#include "SViewHistoryDetail.h"
#include "../widget/list/SList.h"
#include "../widget/label/SLabel.h"

#include <QApplication>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFocusEvent>
#include <QDate>
#include <QTime>
#include <QEvent>
#include <QHash>
#include <QFuture>
#include <QtConcurrent/QtConcurrent>
#include <QDebug>


SViewHistoryDetail::SViewHistoryDetail(QWidget * parent)
    : SBaseDialog(parent)
{
    this->setupWidget();
    this->setupLayout();
    this->setConnect();
}

SViewHistoryDetail::~SViewHistoryDetail()
{
    if (this->header != nullptr)
    {
        delete this->header;
        this->header = nullptr;
    }
    if (this->list != nullptr)
    {
        delete this->list;
        this->list = nullptr;
    }
}

void SViewHistoryDetail::setupWidget()
{
    /* Header */
    this->header = new SLabel;
    this->header->header(this->m_title, 0x0276E);
    this->header->setAlignment(Qt::AlignCenter);
    this->header->setCustomStyleSheet(SLabel::Style::Contrast);
    this->header->fontSize(22);

    /* Info board */
    this->labelStatisticsTime = new SLabel(this);
    this->labelStatisticsTime->setText(this->html(QChar(0x2015), tr("Total time")));
    this->labelStatisticsTime->setAlignment(Qt::AlignCenter);
    this->labelStatisticsTime->setCustomStyleSheet(SLabel::Style::Contrast);
    this->labelStatisticsTime->fontSize(24);

    this->labelStatisticsLength = new SLabel(this);
    this->labelStatisticsLength->setText(this->html(QChar(0x2015), tr("Total length")));
    this->labelStatisticsLength->setAlignment(Qt::AlignCenter);
    this->labelStatisticsLength->setCustomStyleSheet(SLabel::Style::Contrast);
    this->labelStatisticsLength->fontSize(24);

    this->labelStatisticsOrders = new SLabel(this);
    this->labelStatisticsOrders->setText(this->html(QChar(0x2015), tr("Total orders")));
    this->labelStatisticsOrders->setAlignment(Qt::AlignCenter);
    this->labelStatisticsOrders->setCustomStyleSheet(SLabel::Style::Contrast);
    this->labelStatisticsOrders->fontSize(24);

    /* Swipe list */
    this->list = new SList;
    this->list->enableScrollBar(true);
}

void SViewHistoryDetail::setupLayout()
{
    QHBoxLayout * totalLayout = new QHBoxLayout;
    totalLayout->addWidget(this->labelStatisticsTime, Qt::AlignCenter);
    totalLayout->addWidget(this->labelStatisticsLength, Qt::AlignCenter);
    totalLayout->addWidget(this->labelStatisticsOrders, Qt::AlignCenter);

    QVBoxLayout * mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(this->header, 1);
    mainLayout->addLayout(totalLayout, 2);
    mainLayout->addWidget(this->list->listItems(), 10);
    mainLayout->setSpacing(0);
    mainLayout->setContentsMargins(0, 0, 0, 0);

    this->setLayout(mainLayout);
}

void SViewHistoryDetail::setConnect()
{
    /* Header */
    QObject::connect(this->header, &SLabel::signalReleased, [this](int n) {
        switch (n) {
        case 0:
        {
            emit this->signalReturn();

            if (this->closeable())
            {
                this->close();
            }
        }
            break;

        case 1:
            emit this->signalOption();
            break;

        default:
            break;
        }
    });
    /* Swipe list */
    connect(this->list, SIGNAL(signalReleased(int)), this, SLOT(slotList(int)));
}

void
SViewHistoryDetail::slotStatistics(QHash<QString, QString> hash)
{
    /* Info board */
    this->labelStatisticsTime->setText(this->html(QTime::fromMSecsSinceStartOfDay(hash.value("time").toLongLong()).toString("hh:mm"), tr("Total time"), "h"));
    this->labelStatisticsLength->setText(this->html(hash.value("length"), tr("Total length"), "m"));
    this->labelStatisticsOrders->setText(this->html(hash.value("counter"), tr("Total orders")));
}

void
SViewHistoryDetail::slotStream(QHash<QString, QString> hash)
{
    /* Swipe list */
    this->list->appendSlot(hash.value("complete").toInt() ? ":/images/ic_check_circle_blue_128dp.svg" : ":/images/ic_warning_red_128dp.svg",
                           tr("%1 %2").arg(hash.value("date")).arg(hash.value("time")),
                           tr("<p style=\"font-size: 14pt\">Ordered %1 <sup>%3</sup><br>Measuered %2 <sup>%3</sup></p>").arg(hash.value("length")).arg(hash.value("measured")).arg("m"),
                           tr("<p style=\"font-size: 14pt\">ID %1</p>").arg(hash.value("id")),
                           QChar(0x276F),
                           SList::Shape::Contrast);

    if (this->list->size() >= this->m_quantity)
    {
        this->list->appendLine(":/images/ic_arrow_forward_gray_128dp.svg",
                               tr("More histories"),
                               SList::Shape::Contrast);
    }
}

void
SViewHistoryDetail::slotClearHistory()
{
    this->list->clear();
}

void
SViewHistoryDetail::slotList(const int index)
{
    if (index == this->m_quantity)
    {
        this->slotClearHistory();
        this->signalStream(this->m_quantity);
    }
}

QString
SViewHistoryDetail::html(const QString topText,
                         const QString bottom,
                         const QString unit)
{
    QString text = tr("<p style=\"line-height: 140%\"><span style=\"font-size: 22pt\">%1</span> <sup><span style=\"font-size: 20pt\">%3</span></sup><br><span style=\"font-size: 16pt\">%2</span></p>").arg(topText, bottom, unit);
//    QString text = tr("<p style=\"line-height: 140%; font-size: 20pt\"><font size='+2'>%1</font> <font size='+0'><sup>%3</sup></font><br><font size='-2'>%2</font></p>").arg(topText, bottomText, unit);
    return text;
}

void
SViewHistoryDetail::title(const QString text)
{
    this->m_title = text;
    this->header->header(0, this->m_title);
}

QString
SViewHistoryDetail::title() const
{
    return this->m_title;
}

void
SViewHistoryDetail::quantity(const int value)
{
    this->m_quantity = value;
}

int
SViewHistoryDetail::quantity() const
{
    return this->m_quantity;
}

void
SViewHistoryDetail::showEvent(QShowEvent * event)
{
    SBaseDialog::showEvent(event);

    emit this->signalStatistics();
    emit this->signalStream(this->m_quantity);
}
