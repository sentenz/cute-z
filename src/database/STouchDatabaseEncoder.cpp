#include "STouchDatabaseEncoder.h"
#include "STouchHistoryEncoder.h"
#include "../database/SDatabase.h"
#include "../keyboard/STouchKeyboard.h"
#include "../keyboard/STouchScreenlock.h"
#include "../widget/list/SList.h"
#include "../widget/label/SLabel.h"
#include "../widget/stacked/SAnimatedStackedWidget.h"
#include "../util/dialog/STouchDialog.h"

#include <QApplication>
#include <QDateTime>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDebug>


STouchDatabaseEncoder::STouchDatabaseEncoder(QWidget *parent) : QDialog(parent)
{
    this->setWindowState(Qt::WindowFullScreen);
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    this->setStyleSheet("background-color: " + this->m_colorBase.name() + ";");
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

    this->setupWidget();
    this->setupGUI();
    this->setConnect();
}

STouchDatabaseEncoder::~STouchDatabaseEncoder()
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
//    if (this->touchDatabaseEncoderID != nullptr)
//    {
//        delete this->touchDatabaseEncoderID;
//        this->touchDatabaseEncoderID = nullptr;
//    }
}

void STouchDatabaseEncoder::setupWidget()
{
    // Header
    this->header = new SLabel;
    this->header->header(tr("Database"), 0x0276E);

    // Swipe list
    this->list = new SList;
    this->list->topic(tr("Odometer"));
    this->list->slot("",
                     tr("Search ID"),
                     tr(""),
                     tr(""),
                     QChar(0x276F));
    this->list->slot("",
                     tr("Delete ID"),
                     tr(""),
                     tr(""),
                     QChar(0x276F));
    this->list->slot("",
                     tr("Delete all ID`s"),
                     tr(""),
                     tr(""),
                     QChar(0x276F));

    // Database ID
//    this->touchDatabaseEncoderID = new STouchDatabaseEncoderID;
}

void STouchDatabaseEncoder::setupGUI()
{
    QVBoxLayout * subLayout = new QVBoxLayout(this);
    subLayout->addWidget(this->header, 1);
    subLayout->addWidget(this->list->listItems(), 10);
    subLayout->setSpacing(0);
    subLayout->setMargin(0);
    subLayout->setContentsMargins(0, 0, 0, 0);
    QWidget * widget = new QWidget(this);
    widget->setLayout(subLayout);

    this->stackedWidget = new SAnimatedStackedWidget(this);
    this->stackedWidget->addWidget(widget);
//    this->stackedWidget->addWidget(this->touchDatabaseEncoderID);

    QVBoxLayout * mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(this->stackedWidget);
    mainLayout->setSpacing(0);
    mainLayout->setContentsMargins(0, 0, 0, 0);

    this->setLayout(mainLayout);
}

void STouchDatabaseEncoder::setConnect()
{
    // Lists
    connect(this->header, SIGNAL(signalReleased(int)), this, SIGNAL(signalReturn(void)));
    connect(this->list, SIGNAL(signalReleased(QString)), this, SLOT(slotList(QString)));
    // Subwidgets
//    connect(this->touchDatabaseEncoderID, &STouchDatabaseEncoderID::signalReturn, this, &STouchDatabaseEncoder::slotReturn);
}

void STouchDatabaseEncoder::slotList(const QString &content)
{
    this->hide();

    this->basicTimer.start(20 * 60 * 1000, this);

    STouchScreenlock touchScreenlock(this);
    touchScreenlock.setRole(STouchScreenlock::Role::Appropriate);
    if (!content.compare(tr("Delete ID")) || !content.compare(tr("Delete all ID`s")))
    {
        touchScreenlock.setRole(STouchScreenlock::Role::Admin);
    }
    touchScreenlock.enableSymbols(true);
    touchScreenlock.exec();
    if (touchScreenlock.isAccepted())
    {
        // Database
        SDatabase database(::GlobalConfigPathDatabase);

        if (!content.compare(tr("Search ID")))
        {
            retry0:
            {
                QString id;

                STouchKeyboard touchKeyboard(this);
                touchKeyboard.setTitle(tr("ID"));
                touchKeyboard.exec();
                if (touchKeyboard.isAccepted())
                {
//                    id = database.getMeasurement(touchKeyboard.getNumber().toInt());

                    if (!id.isEmpty())
                    {
//                        this->touchDatabaseEncoderID->slotUpdateWidgeds(id);
//                        this->stackedWidget->slideIn(this->touchDatabaseEncoderID);
                    }
                    else
                    {
                        STouchDialog touchDialog(this);
                        touchDialog.setTitelText(tr("Database"));
                        touchDialog.setAcceptText(tr("Retry"));
                        touchDialog.setDescriptionText(tr("Unkown ID."));
                        touchDialog.exec();
                        if (touchDialog.isAccepted())
                        {
                            id.clear();
                            goto retry0;
                        }
                    }
                }
            }
        }
        else if (!content.compare(tr("Delete ID"))) // Delete ID
        {
            retry1:
            {
                QString id;

                STouchKeyboard touchKeyboard(this);
                touchKeyboard.setTitle(tr("ID"));
                touchKeyboard.exec();
                if (touchKeyboard.isAccepted())
                {
//                    id = database.getMeasurement(touchKeyboard.getNumber().toInt());

                    if (!id.isEmpty())
                    {
                        STouchDialog touchDialog(this);
                        touchDialog.setTitelText(tr("Database"));
                        touchDialog.setAcceptText(tr("Ok"));
                        touchDialog.setDescriptionText(tr("Delete ID %1 from the Database.\nStock size %2.").arg(id.section("\t", 0, 0)).arg(database.getTotalOrders()));
                        touchDialog.exec();

                        if (touchDialog.isAccepted())
                        {
                            database.deleteMeasurement(id.section("\t", 0, 0).toInt());
                        }
                    }
                    else
                    {
                        STouchDialog touchDialog(this);
                        touchDialog.setTitelText(tr("Database"));
                        touchDialog.setAcceptText(tr("Retry"));
                        touchDialog.setDescriptionText(tr("Unkown ID."));
                        touchDialog.exec();
                        if (touchDialog.isAccepted())
                        {
                            id.clear();
                            goto retry1;
                        }
                    }
                }
            }
        }
        else if (!content.compare(tr("Delete all ID`s"))) // Delete all ID`s
        {
            STouchDialog touchDialog(this);
            touchDialog.setTitelText(tr("Database"));
            touchDialog.setAcceptText(tr("Ok"));
            touchDialog.setDescriptionText(tr("Delete all ID`s from the Database.\nStock size %1.").arg(database.getTotalOrders()));
            touchDialog.exec();
            if (touchDialog.isAccepted())
            {
                database.deleteAllMeasurement();
            }
        }
    }

    this->show();
}

void STouchDatabaseEncoder::slotReturn()
{
    this->basicTimer.stop();
    this->stackedWidget->slideIn(0);
}

void STouchDatabaseEncoder::timerEvent(QTimerEvent *event)
{
    if (event->timerId() == this->basicTimer.timerId())
    {
        emit slotReturn();
    }
}

void STouchDatabaseEncoder::retranslateUI()
{
    int t_iter = 0;

    // Header
    this->header->header(t_iter, tr("Database"));

    // Swipe list
    this->list->topic(t_iter, tr("Odometer"));

    this->list->slot(t_iter++,
                     "",
                     tr("Search ID"),
                     tr(""),
                     tr(""),
                     QChar(0x276F));
    this->list->slot(t_iter++,
                     "",
                     tr("Delete ID"),
                     tr(""),
                     tr(""),
                     QChar(0x276F));
    this->list->slot(t_iter++,
                     "",
                     tr("Delete all ID`s"),
                     tr(""),
                     tr(""),
                     QChar(0x276F));
}

void
STouchDatabaseEncoder::restyleUI()
{
    if (this->m_colorBase != ::GlobalColorCustomBase)
    {
        this->m_colorBase = ::GlobalColorCustomBase;
        this->setStyleSheet("background-color: " + this->m_colorBase.name() + ";");
    }
    if (this->m_colorContrast != ::GlobalColorCustomContrast)
    {
        this->m_colorContrast = ::GlobalColorCustomContrast;
    }
    if (this->m_colorText != ::GlobalColorCustomText)
    {
        this->m_colorText = ::GlobalColorCustomText;
    }
    if (this->m_colorHighlight != ::GlobalColorCustomHighlight)
    {
        this->m_colorHighlight = ::GlobalColorCustomHighlight;
    }
}

void
STouchDatabaseEncoder::changeEvent(QEvent * event)
{
    switch (event->type())
    {
    case QEvent::LanguageChange:
        this->retranslateUI();
        break;

    case QEvent::StyleChange:
        this->restyleUI();
        break;

    case QEvent::LocaleChange:
        break;

    default:
        break;
    }

    QWidget::changeEvent(event);
}
