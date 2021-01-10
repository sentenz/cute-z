#include "SViewHistoryOdometer.h"
#include "../widget/list/SList.h"
#include "../widget/button/SFabButton.h"
#include "../util/dialog/SAppBar.h"
#include "../util/dialog/SInfoBar.h"

#include <QApplication>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QEvent>
#include <QHash>
#include <QDebug>


SViewHistoryOdometer::SViewHistoryOdometer(QWidget * parent)
    : SBaseDialog(parent)
{
    this->setupWidget();
    this->setupLayout();
    this->setConnect();
}

SViewHistoryOdometer::~SViewHistoryOdometer()
{
    if (this->list != nullptr)
    {
        delete this->list;
        this->list = nullptr;
    }
}

void SViewHistoryOdometer::setupWidget()
{
    /* App bar */
    this->appBar = new SAppBar(QtMaterialTheme::icon("navigation", "arrow_back"), this->m_title, this);

    /* Info bar */
    this->infoBar = new SInfoBar(this);
    this->infoBar->addText(this->html(QChar(0x2015), tr("Total time")));
    this->infoBar->addText(this->html(QChar(0x2015), tr("Total length")));
    this->infoBar->addText(this->html(QChar(0x2015), tr("Total orders")));

    /* Swipe list */
    this->list = new SList;
    this->list->enableScrollBar(true);

    /* Fab */
    this->m_fab = new SFabButton(QtMaterialTheme::icon("content", "add"));
}

void SViewHistoryOdometer::setupLayout()
{
    QVBoxLayout * mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(this->appBar, 1);
    mainLayout->addWidget(this->infoBar, 1);
    mainLayout->addWidget(this->list->list(), 8);
    mainLayout->setSpacing(0);
    mainLayout->setContentsMargins(0, 0, 0, 0);

    this->setLayout(mainLayout);

    /* Parent must be set after the layout is placed. */
    this->m_fab->setParent(this);
}

void SViewHistoryOdometer::setConnect()
{
    /* App bar */
    connect(this->appBar, &SAppBar::signalClicked, [this](int n) {
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

        default:
            emit this->signalOption(n);
            break;
        }
    });

    /* Swipe list */
//    connect(this->list, SIGNAL(signalReleased(int)), this, SLOT(slotList(int)));

    /* Fab */
    connect(this->m_fab, SIGNAL(clicked(bool)), this, SLOT(slotList()));
}

void
SViewHistoryOdometer::slotStatistics(QHash<QString, QString> hash)
{
    /* Info bar */
    this->infoBar->setText(0, hash.value("time"));
    this->infoBar->setText(1, hash.value("length"));
    this->infoBar->setText(2, hash.value("counter"));
}

void
SViewHistoryOdometer::slotStream(QHash<QString, QString> hash)
{
    /* Swipe list */
    this->list->addSlot(QIcon(hash.value("icon")),
                           hash.value("text"),
                           hash.value("subtext"),
                           hash.value("info"),
                           QChar(0x276F));
}

void
SViewHistoryOdometer::slotClearHistory()
{
    this->list->clear();
}

void
SViewHistoryOdometer::slotList()
{
    this->slotClearHistory();
    this->signalStream(this->m_quantity);
}

QString
SViewHistoryOdometer::html(const QString topText,
                         const QString bottom,
                         const QString unit)
{
    QString text = tr("<p style=\"line-height: 140%\"><span style=\"font-size: 22pt\">%1</span> <sup><span style=\"font-size: 20pt\">%3</span></sup><br><span style=\"font-size: 16pt\">%2</span></p>").arg(topText, bottom, unit);
    return text;
}

void
SViewHistoryOdometer::title(const QString text)
{
    this->m_title = text;
    this->appBar->setText(this->m_title);
}

QString
SViewHistoryOdometer::title() const
{
    return this->m_title;
}

void
SViewHistoryOdometer::quantity(const int value)
{
    this->m_quantity = value;
}

int
SViewHistoryOdometer::quantity() const
{
    return this->m_quantity;
}

void
SViewHistoryOdometer::showEvent(QShowEvent * event)
{
    SBaseDialog::showEvent(event);

    emit this->signalStatistics();
    emit this->signalStream(this->m_quantity);
}
