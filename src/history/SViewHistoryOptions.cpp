#include "SViewHistoryOptions.h"
#include "../keyboard/STouchKeyboard.h"
#include "../keyboard/STouchScreenlock.h"
#include "../widget/list/SList.h"
#include "../widget/label/SLabel.h"
#include "../util/dialog/STextDialog.h"

#include <QApplication>
#include <QDateTime>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDebug>


SViewHistoryOptions::SViewHistoryOptions(QWidget * parent) :
    SBaseDialog(parent)
{
    this->setupWidget();
    this->setupLayout();
    this->setConnect();
}

SViewHistoryOptions::~SViewHistoryOptions()
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

void SViewHistoryOptions::setupWidget()
{
    // Header
    this->header = new SLabel;
    this->header->header(tr("History options"), 0x0276E);
    this->header->setTheme(SLabel::Theme::Contrast);
    this->header->fontSize(22);

    // Swipe list
    this->list = new SList;
    this->list->addTitle(tr("Search"));
    this->list->addSlot(QIcon(),
                     tr("Search ID"),
                     tr(""),
                     tr(""),
                     QChar(0x276F));
    this->list->divider();
    this->list->addTitle(tr("Delete"));
    this->list->addSlot(QIcon(),
                     tr("Delete ID"),
                     tr(""),
                     tr(""),
                     QChar(0x276F));
    this->list->addSlot(QIcon(),
                     tr("Delete all ID`s"),
                     tr(""),
                     tr(""),
                     QChar(0x276F));
}

void SViewHistoryOptions::setupLayout()
{
    QVBoxLayout * mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(this->header, 1);
    mainLayout->addWidget(this->list->list(), 10);
    mainLayout->setSpacing(0);
    mainLayout->setContentsMargins(0, 0, 0, 0);

    this->setLayout(mainLayout);
}

void SViewHistoryOptions::setConnect()
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
    connect(this->list, SIGNAL(signalReleased(QString)), this, SLOT(slotList(QString)));
}

void
SViewHistoryOptions::slotList(const QString & content)
{
    STouchScreenlock touchScreenlock(this);
    touchScreenlock.setRole(STouchScreenlock::Role::Appropriate);
//    if (!content.compare(tr("Delete ID")) || !content.compare(tr("Delete all ID`s")))
//    {
//        touchScreenlock.setRole(STouchScreenlock::Role::Admin);
//    }
    touchScreenlock.enableSymbols(true);
    touchScreenlock.exec();
    if (touchScreenlock.isAccepted())
    {
        if (!content.compare(tr("Search ID")))
        {
            STouchKeyboard touchKeyboard(this);
            touchKeyboard.setTitle(tr("ID"));
            touchKeyboard.exec();
            if (touchKeyboard.isAccepted())
            {
                emit signalId(touchKeyboard.getNumber().toInt());
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
                        STextDialog dialog(this);
                        dialog.setTitle(tr("Database"));
//                        dialog.setDescription(tr("Delete ID %1 from the Database.\nStock size %2.").arg(id.section("\t", 0, 0)).arg(database.statistics().value("counter")));
                        dialog.exec();

                        if (dialog.isAccepted())
                        {
//                            database.deleteMeasurement(id.section("\t", 0, 0).toInt());
                        }
                    }
                    else
                    {
                        STextDialog dialog(this);
                        dialog.setTitle(tr("Database"));
                        dialog.setAcceptButton(tr("Retry"));
                        dialog.setDescription(tr("Unkown ID."));
                        dialog.exec();
                        if (dialog.isAccepted())
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
            STextDialog dialog(this);
            dialog.setTitle(tr("Database"));
            dialog.setAcceptButton(tr("Ok"));
//            dialog.setDescription(tr("Delete all ID`s from the Database.\nStock size %1.").arg(database.statistics().value("counter")));
            dialog.exec();
            if (dialog.isAccepted())
            {
//                database.deleteAllMeasurement();
            }
        }
    }

    this->show();
}

void SViewHistoryOptions::timerEvent(QTimerEvent *event)
{
    if (event->timerId() == this->basicTimer.timerId())
    {
        this->basicTimer.stop();

        emit this->signalReturn();

        if (this->closeable())
        {
            this->close();
        }
    }
}

void SViewHistoryOptions::retranslateUI()
{
    int t_iter = 0;

    // Header
    this->header->header(t_iter, tr("Database"));

    // Swipe list
    this->list->setTitle(t_iter,
                      tr("Search"));
    this->list->setTitle(t_iter++,
                      tr("Delete"));

    t_iter = 0;

    this->list->setSlot(t_iter++,
                     QIcon(),
                     tr("Search ID"),
                     tr(""),
                     tr(""),
                     QChar(0x276F));
    this->list->setSlot(t_iter++,
                     QIcon(),
                     tr("Delete ID"),
                     tr(""),
                     tr(""),
                     QChar(0x276F));
    this->list->setSlot(t_iter++,
                     QIcon(),
                     tr("Delete all ID`s"),
                     tr(""),
                     tr(""),
                     QChar(0x276F));
}

void
SViewHistoryOptions::restyleUI()
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
SViewHistoryOptions::changeEvent(QEvent * event)
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
