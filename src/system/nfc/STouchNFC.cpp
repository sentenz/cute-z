#include "STouchNFC.h"
#include "../settings/systems/stouchsettingssystemnfc.h"
#include "../keyboard/STouchKeyboard.h"
#include "../util/dialog/STextDialog.h"
#include "../widget/wheel/SVTumbler.h"
#include "../widget/layout/SHScrollArea.h"
#include "../widget/button/SToolButton.h"
#include "../widget/button/SPushButton.h"
#include "../widget/label/SLabel.h"

#include <QApplication>
#include <QSettings>
#include <QFileSystemWatcher>
#include <QLabel>
#include <QTimer>
#include <QPushButton>
#include <QButtonGroup>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QException>
#include <QStackedWidget>
#include <QPropertyAnimation>
#include <QGraphicsOpacityEffect>
#include <QMutex>
#include <QMouseEvent>
#include <QPainter>
#ifdef S_DEBUG_SYSTEM
#include <QDebug>
#endif


STouchNFC::STouchNFC(QWidget *parent) : QDialog(parent)
{
    this->setObjectName("STouchNFC");
    // Window size for developing and emulating
    if (!::GlobalWindowSize.isEmpty())
    {
        this->resize(::GlobalWindowSize);
    }
    else
    {
        this->setWindowState(Qt::WindowFullScreen);
        this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    }
    this->setStyleSheet("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 " + this->m_colorContrast.name() + ", stop: 0.8 " + this->m_colorContrast.name() + ", stop: 0.801 " + this->m_colorBase.name() + ", stop: 1 " + this->m_colorBase.name() + ");");
    this->setWindowFlags(this->windowFlags() | Qt::Window | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    this->setWindowModality(Qt::WindowModal);
    this->setModal(true);
    this->activateWindow();
    this->raise();

    this->setupWidget();
    this->setupLayout();
    this->setConnect();
    this->slotReadSettings();
}

STouchNFC::~STouchNFC()
{
    if (this->header != nullptr)
    {
        delete this->header;
        this->header = nullptr;
    }
    if (this->threadNFC != nullptr)
    {
        delete this->threadNFC;
        this->threadNFC = nullptr;
    }
    if (this->buttonDigits != nullptr)
    {
        delete this->buttonDigits;
        this->buttonDigits = nullptr;
    }
    if (this->buttonPlay != nullptr)
    {
        delete this->buttonPlay;
        this->buttonPlay = nullptr;
    }
    if (this->buttonStop != nullptr)
    {
        delete this->buttonStop;
        this->buttonStop = nullptr;
    }
}

void STouchNFC::setupWidget()
{
    // File watcher
    this->fileSystemWatcher = new QFileSystemWatcher(this);
    this->fileSystemWatcher->addPath(::GlobalConfigPathSettings);

    // Header
    this->header = new SLabel;
    this->header->header(tr("Paternoster"), 0x0276E, 0x2699);

    int t_height = ::GlobalWindowSize.height() > ::GlobalWindowSize.width() ? ::GlobalWindowSize.height() : ::GlobalWindowSize.width();
    this->touchTumbler = new SVTumbler(false, this);
    this->touchTumbler->setItemHeight(t_height / 4);
    this->touchTumbler->setFontSize(130);
    this->touchTumbler->enableHighlight(false);
    this->touchTumbler->setItems(QStringList() << "0");

    this->labelTarget = new QLabel(this);
    this->labelTarget->setAlignment(Qt::AlignCenter);
    this->labelTarget->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    this->labelTarget->setStyleSheet("QLabel { font: 18pt " + ::GlobalFont + "; color: " + this->m_colorText.name() + "; background: transparent; }");
    this->labelTarget->setText(this->setHtmlText(QChar(0x2015), tr("Destination")));

    this->labelDirection = new QLabel(this);
    this->labelDirection->setAlignment(Qt::AlignCenter);
    this->labelDirection->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    this->labelDirection->setStyleSheet("QLabel { font: 18pt " + ::GlobalFont + "; color: " + this->m_colorText.name() + "; background: transparent; }");
    this->labelDirection->setText(this->setHtmlText(QChar(0x2015), tr("Direction")));

    // Buttons

    this->buttonStop = new SToolButton;
    this->buttonStop->setCheckable(true);
    this->buttonStop->setIconSize(QSize(100, 100));
    this->buttonStop->setToolButtonStyle(Qt::ToolButtonIconOnly);
    this->buttonStop->setImage(":/images/ic_stop_white_128dp.svg");

    this->buttonPlay = new SToolButton;
    this->buttonPlay->setCheckable(true);
    this->buttonPlay->setIconSize(QSize(175, 175));
    this->buttonPlay->setToolButtonStyle(Qt::ToolButtonIconOnly);
    this->buttonPlay->setImage(":/images/ic_play_arrow_white_128dp.svg");

    this->buttonDigits = new SToolButton;
    this->buttonDigits->setCheckable(true);
    this->buttonDigits->setIconSize(QSize(75, 75));
    this->buttonDigits->setToolButtonStyle(Qt::ToolButtonIconOnly);
    this->buttonDigits->setImage(":/images/ic_dialpad_white_128dp.svg");
}

void STouchNFC::setupLayout()
{
    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(buttonStop, 0, Qt::AlignCenter);
    buttonLayout->addWidget(buttonPlay, 0, Qt::AlignCenter);
    buttonLayout->addWidget(buttonDigits, 0, Qt::AlignCenter);
    buttonLayout->setSpacing(0);
    buttonLayout->setContentsMargins(0, 0, 0, 0);
    // Widget
    QWidget *widget = new QWidget;
    widget->setLayout(buttonLayout);
    // Scroll Area
    SHScrollArea *scrollArea = new SHScrollArea;
    scrollArea->setWidget(widget);

    QVBoxLayout *labelLayout = new QVBoxLayout;
    labelLayout->addWidget(this->touchTumbler);
    labelLayout->setAlignment(Qt::AlignCenter);

    QHBoxLayout *infoLayout = new QHBoxLayout;
    infoLayout->addWidget(this->labelTarget, Qt::AlignBottom | Qt::AlignHCenter);
    infoLayout->addWidget(this->labelDirection, Qt::AlignBottom | Qt::AlignHCenter);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(this->header, 1);
    mainLayout->addLayout(labelLayout, 4);
    mainLayout->addWidget(scrollArea, 3);
    mainLayout->addLayout(infoLayout, 2);
    mainLayout->setSpacing(0);
    mainLayout->setContentsMargins(0, 0, 0, 0);

    this->setLayout(mainLayout);
}

void STouchNFC::setConnect()
{
    // Lists
    connect(this->header, &SLabel::signalReleased, [this] (int n) {
        switch (n) {
        case 0:
            emit this->signalReturn();
            break;

        case 1:
        {
            emit this->signalOptions();

            STouchSettingsSystemNFC touchSettingsSystemNFC(this);
            touchSettingsSystemNFC.setCloseable(true);
            touchSettingsSystemNFC.exec();
        }
            break;

        default:
            break;
        }
    });
    // File watcher
    connect(this->fileSystemWatcher, &QFileSystemWatcher::directoryChanged, this, &STouchNFC::slotReadSettings);
    // Buttons
    connect(this->buttonStop, &SToolButton::pressed, [this] {
        // Workaround: button doesn't set back on its own
        this->buttonPlay->setChecked(false);
        // Workaround: button doesn't set on its own
        this->buttonStop->setChecked(true);
        // Unlack the GPIOs of the e-motor in the SControlEncoder.
        emit this->signalRun(false);
        this->stopThread();
    });
    connect(this->buttonStop, &SToolButton::released, [this] {
        // Workaround: button doesn't set back on its own
        this->buttonStop->setChecked(false);
    });
    connect(this->buttonPlay, &SToolButton::released, [this] {
        switch (this->m_mode)
        {
        case SThreadNFC::NFC::Run:
        case SThreadNFC::NFC::Write:
        {
            if (this->m_target < 0)
            {
                // Workaround: button doesn't set back on its own
                this->buttonPlay->setChecked(false);
                this->buttonDigits->click();
            }
        }
            break;

        default:
            break;
        }

        if (this->buttonPlay->isChecked())
        {
#ifdef S_DEBUG_SYSTEM
            qDebug() << "STouchNFC::setConnect play button";
#endif
            // Start the thread
            this->playThread();
        }
        else // Pause
        {
#ifdef S_DEBUG_SYSTEM
            qDebug() << "STouchNFC::setConnect pause button";
            this->buttonPlay->setChecked(false);
#endif
            switch (this->m_mode)
            {
            case SThreadNFC::NFC::Run:
            {
                // Pause the thread
                // Note: It is better to run the thread throughout the session
                // to measure the delays when you disable the e-motor. Only
                // unlack the GPIOs of the e-motor in the SControlEncoder.
#ifdef S_DEBUG_SYSTEM
                // To avoid crashes in debug mode.
                this->pauseThread();
#endif
                // Unset the GPIOs of the e-motor in the SControlEncoder.
                emit this->signalRun(false);
            }
                break;

            case SThreadNFC::NFC::Read:
            case SThreadNFC::NFC::Write:
            {
                this->pauseThread();
            }
                break;

            default:
                break;
            }
        }
    });
    connect(this->buttonDigits, &SToolButton::pressed, [this] {
        // Workaround: button doesn't set on its own
        this->buttonDigits->setChecked(true);
    });
    connect(this->buttonDigits, &SToolButton::released, [this] {
        if ((this->m_mode == SThreadNFC::NFC::Run) || (this->m_mode == SThreadNFC::NFC::Write))
        {
            // Workaround: doesn't set back from allon
            this->buttonDigits->setChecked(false);
            // Pause the thread for new entry
            this->pause();

            // Set new entry, else continue
            if (this->keyboard())
            {
                // Info board for ID & Target value
                this->initInfo();
                // TODO: Not sure why this function is needed here!
                // Start NFC polling
                this->transferTarget();
            }
        }
    });
}

void
STouchNFC::play()
{
    if (!this->buttonPlay->isChecked())
    {
        this->buttonPlay->click();
    }
}

void
STouchNFC::stop()
{
    // Button stop for reset to return init
    this->buttonStop->click();
}

void
STouchNFC::pause()
{
    if (this->buttonPlay->isChecked())
    {
        this->buttonPlay->click();
    }
}

void
STouchNFC::playThread()
{
    if (this->threadNFC == nullptr)
    {
        // Init
        this->threadNFC = new SThreadNFC;
        this->threadNFC->setMode(this->m_mode);
        if (this->threadNFC != nullptr)
        {
            // Establish connetions
            connect(this->threadNFC, &SThreadNFC::signalRun, this, &STouchNFC::signalRun);
            connect(this->threadNFC, &SThreadNFC::signalData, this, &STouchNFC::slotDataTransfer);
            connect(this->threadNFC, &SThreadNFC::signalError, this, &STouchNFC::slotError);
            // Restart thread
            this->threadNFC->resume();
            // New session begins
            this->m_session = true;
        }
    }
    else
    {
        // Restart thread
        this->threadNFC->resume();
    }
}

void
STouchNFC::pauseThread()
{
    if (this->threadNFC != nullptr)
    {
        // Thread pause
        this->threadNFC->pause();
    }
}

void
STouchNFC::stopThread()
{
    // Reset
    this->resetMembers();

    if (this->threadNFC != nullptr)
    {
        // Thread stop
        this->threadNFC->stop();
        // Delete object for new session
        delete this->threadNFC;
        this->threadNFC = nullptr;
    }

    // Close app if its used to Read/Write TAGs.
    if (this->m_closeable)
    {
        this->close();
    }
}

void STouchNFC::initInfo()
{
    switch (this->m_mode)
    {
    case SThreadNFC::NFC::Run:
    {
        if (this->m_target < 0)
        {
            return;
        }

        this->labelTarget->setText(this->setHtmlText(QString::number(this->m_target), tr("Destination")));
        this->labelDirection->setText(this->setHtmlText(this->up() ? QChar(0x25B2) : QChar(0x25BC), tr("Direction")));
    }
        break;

    case SThreadNFC::NFC::Write:
        this->labelTarget->setText(this->setHtmlText(QString::number(this->m_target), tr("Destination")));
        break;

    default:
        break;
    }
}

void STouchNFC::resetInfo()
{
    this->labelTarget->setText(this->setHtmlText(QChar(0x2015), tr("Destination")));
    this->labelDirection->setText(this->setHtmlText(QChar(0x2015), tr("Direction")));
}

void STouchNFC::resetMembers()
{
    this->m_session = false;
    this->m_target = -1;
    this->resetInfo();
}

bool STouchNFC::keyboard()
{
    bool t_accepted = false;

    STouchKeyboard touchKeyboard(this);
    touchKeyboard.setTitle(tr("Input Value"));
    touchKeyboard.setDescriptionText(tr("The input value must be in the range of %1 to %2.").arg(this->minimumValue()).arg(this->maximumValue()), STouchKeyboard::Dialog::Warning);
    touchKeyboard.setRange(this->minimumValue(), this->maximumValue());
    touchKeyboard.setDatatype(STouchKeyboard::Datatype::Int);
    touchKeyboard.exec();
    if (touchKeyboard.isAccepted())
    {
        // Target value
        this->m_target = touchKeyboard.getNumber().toInt();
        // Return value
        t_accepted = true;
    }
    else
    {
        // Return value
        t_accepted = false;
    }

    return t_accepted;
}

void STouchNFC::slotRun(const bool run)
{
    this->m_running = run;
}

void STouchNFC::slotDataTransfer(const int value)
{
    this->m_value = value;

    // Update current value of tumbler
    this->touchTumbler->scrollToContent(QString::number(this->m_value), 1000);
    // Dialog case
    switch (this->m_mode)
    {
    case SThreadNFC::NFC::Read:
    {
        this->pause();
        this->setMessage(tr("Info"),
                         tr("Value %1 read from TAG.").arg(QString::number(this->m_value)),
                         10000);
    }
        break;

    default:
        break;
    }

    if (this->m_value == this->m_target)
    {
        if (this->m_target >= 0)
        {
            // Dialog cases
            switch (this->m_mode)
            {
            case SThreadNFC::NFC::Run:
            {
                // Button stop for reset to return init
                this->stop();
                this->setMessage(tr("Info"),
                                 tr("Destination %1 has been reached.").arg(QString::number(this->m_value)),
                                 30000);
            }
                break;

            case SThreadNFC::NFC::Write:
            {
                this->pause();
                this->setMessage(tr("Info"),
                                 tr("Value %1 was written on the TAG.").arg(QString::number(this->m_value)),
                                 10000);
            }
                break;

            default:
                break;
            }
            // Reset target for the next target
            this->m_target = -1;
        }
    }
}

void
STouchNFC::slotError()
{
    // Pause button virtuel clicked
    this->pause();

    // Dialog
    this->setMessage(tr("Error"),
                     tr("Communication could not be established"));
}

void
STouchNFC::setMessage(const QString title,
                      const QString text,
                      const int time)
{
    STextDialog *dialog = new STextDialog(this);
    dialog->setTitle(title);
    dialog->setDescription(text);
    dialog->setAcceptButton(tr("Accept"));
    dialog->setAttribute(Qt::WA_DeleteOnClose);
    dialog->show();
}

void
STouchNFC::setMode(const SThreadNFC::NFC mode)
{
    this->m_mode = mode;

    switch (this->m_mode)
    {
    case SThreadNFC::NFC::Read:
    {
        // Change header text
        this->header->header(0, tr("Read NFC TAG"));
        // Disable visability
        this->labelTarget->setVisible(false);
        this->labelDirection->setVisible(false);
    }
        break;

    case SThreadNFC::NFC::Write:
    {
        // Change header text
        this->header->header(0, tr("Write NFC TAG"));
        // Disable visability
        this->labelDirection->setVisible(false);
    }
        break;

    default:
        break;
    }
}

void
STouchNFC::transferTarget()
{
    if (this->threadNFC == nullptr)
    {
        return;
    }

    switch (this->m_mode)
    {
    case SThreadNFC::NFC::Run:
    case SThreadNFC::NFC::Read:
    {
        //this->threadNFC->setMode(this->m_mode);
    }
        break;

    case SThreadNFC::NFC::Write:
    {
        //this->threadNFC->setMode(this->m_mode);
        this->threadNFC->write(this->m_target);
    }
        break;

    default:
        break;
    }
}

void STouchNFC::setValue(const int value)
{
    this->m_value = value;
}

int STouchNFC::getValue() const
{
    return this->m_value;
}

void STouchNFC::setCloseable(const bool closeable)
{
    this->m_closeable = closeable;
}

bool STouchNFC::up()
{
    this->getDirection();

    if (this->m_up < this->m_down)
    {
        return true;
    }

    return false;
}

bool STouchNFC::down()
{
    this->getDirection();

    if (this->m_up > this->m_down)
    {
        return true;
    }

    return false;
}

void STouchNFC::getDirection()
{
    if (this->m_value < this->m_target)
    {
        this->m_up = this->m_target - this->m_value;
        this->m_down = this->m_value - this->minimumValue() + this->maximumValue() - this->m_target;
    }
    else if (this->m_value > this->m_target)
    {
        this->m_up = this->m_target - this->minimumValue() + this->maximumValue() - this->m_value;
        this->m_down = this->m_value - this->m_target;
    }
}

bool STouchNFC::unidirectional() const
{
    return (this->direction() == 0);
}

bool STouchNFC::bidirectional() const
{
    return (this->direction() == 1);
}

int STouchNFC::minimumValue() const
{
    return this->m_minValue;
}

int STouchNFC::maximumValue() const
{
    return this->m_maxValue;
}

int STouchNFC::direction() const
{
    return this->m_direction;
}

QString
STouchNFC::setElidedText(const QLabel *label,
                         const QString &text,
                         const Qt::TextElideMode elide)
{
    QFontMetrics t_metrics(label->font());
    return t_metrics.elidedText(text, elide, label->width() - 2);
}

QString
STouchNFC::setHtmlText(const QString topText,
                       const QString bottomText,
                       const QString unit)
{
    QString text = tr("<p style=\"line-height: 140%\"><span style=\"font-size: 22pt\">%1</span> <sup><span style=\"font-size: 20pt\">%3</span></sup><br><span style=\"font-size: 16pt\">%2</span></p>").arg(topText, bottomText, unit);
//    QString text = tr("<p style=\"line-height: 140%; font-size: 20pt\"><font size='+2'>%1</font> <font size='+0'><sup>%3</sup></font><br><font size='-2'>%2</font></p>").arg(topText, bottomText, unit);
    return text;
}

void STouchNFC::slotReadSettings()
{
    QSettings settings(::GlobalConfigFileSettings, QSettings::IniFormat);

    if (!QStringList(settings.allKeys().filter("custom/system/nfc", Qt::CaseInsensitive)).isEmpty())
    {
        settings.beginGroup("custom/system/nfc");
    }
    else if (!QStringList(settings.allKeys().filter("default/system/nfc", Qt::CaseInsensitive)).isEmpty())
    {
        settings.beginGroup("default/system/nfc");
    }

    this->m_minValue = settings.value("minValue", 0).toInt();
    this->m_maxValue = settings.value("maxValue", 255).toInt();
    this->m_direction = settings.value("direction", 0).toInt();

    settings.sync();
    settings.endGroup();

    // Update Widgets with the loaded settings
    this->updateWidget();
}

void
STouchNFC::updateWidget()
{
}

void STouchNFC::showEvent(QShowEvent *event)
{
    Q_UNUSED(event);
}

void STouchNFC::mousePressEvent(QMouseEvent *event)
{
    QWidget::mousePressEvent(event);
}

void STouchNFC::mouseReleaseEvent(QMouseEvent *event)
{
    QWidget::mouseReleaseEvent(event);
}

void STouchNFC::retranslateUI()
{
    this->initInfo();

    switch (this->m_mode)
    {
    case SThreadNFC::NFC::Run:
    {
        this->header->header(0, tr("Paternoster"));
    }
        break;

    case SThreadNFC::NFC::Read:
    {
        this->header->header(0, tr("Read NFC TAG"));
    }
        break;

    case SThreadNFC::NFC::Write:
    {
        this->header->header(0, tr("Write NFC TAG"));
    }
        break;

    default:
        break;
    }
}

void
STouchNFC::restyleUI()
{
    if (this->m_colorBase != ::GlobalColorCustomBase)
    {
        this->m_colorBase = ::GlobalColorCustomBase;
        this->setStyleSheet("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 " + this->m_colorContrast.name() + ", stop: 0.8 " + this->m_colorContrast.name() + ", stop: 0.801 " + this->m_colorBase.name() + ", stop: 1 " + this->m_colorBase.name() + ");");
    }
    if (this->m_colorContrast != ::GlobalColorCustomContrast)
    {
        this->m_colorContrast = ::GlobalColorCustomContrast;
        this->setStyleSheet("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 " + this->m_colorContrast.name() + ", stop: 0.8 " + this->m_colorContrast.name() + ", stop: 0.801 " + this->m_colorBase.name() + ", stop: 1 " + this->m_colorBase.name() + ");");
    }
    if (this->m_colorText != ::GlobalColorCustomText)
    {
        this->m_colorText = ::GlobalColorCustomText;
        this->labelTarget->setStyleSheet("QLabel { font: 18pt " + ::GlobalFont + "; color: " + this->m_colorText.name() + "; background: transparent; }");
        this->labelDirection->setStyleSheet("QLabel { font: 18pt " + ::GlobalFont + "; color: " + this->m_colorText.name() + "; background: transparent; }");
    }
    if (this->m_colorHighlight != ::GlobalColorCustomHighlight)
    {
        this->m_colorHighlight = ::GlobalColorCustomHighlight;
    }
}

void
STouchNFC::changeEvent(QEvent * event)
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
