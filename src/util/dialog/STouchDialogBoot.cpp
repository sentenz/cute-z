#include "STouchDialogBoot.h"
#include "../build/SGlobal.h"
#include "../widget/effect/SGraphicsGlowEffect.h"

#include <QApplication>
#include <QTimer>
#include <QLabel>
#include <QToolButton>
#include <QButtonGroup>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QProcess>
#include <QString>
#include <QPainter>
#include <QPaintEvent>
#include <QPropertyAnimation>


STouchDialogBoot::STouchDialogBoot(QWidget *parent) : QDialog(parent)
{
    /// Window size for developing and emulating
    if (!::GlobalWindowSize.isEmpty())
    {
        this->resize(::GlobalWindowSize);
    }
    else
    {
        this->setWindowState(Qt::WindowFullScreen);
        this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    }
    this->setWindowFlags(this->windowFlags() | Qt::Window | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    this->setAttribute(Qt::WA_TranslucentBackground);
    this->setAttribute(Qt::WA_NoSystemBackground);
    this->setAttribute(Qt::WA_OpaquePaintEvent);
    this->setAttribute(Qt::WA_AcceptTouchEvents);
    this->setWindowModality(Qt::WindowModal);
    this->setModal(true);
    this->activateWindow();
    this->raise();

    this->setupWidget();
    this->setConnect();
}

void STouchDialogBoot::setupWidget()
{
    int t_size = this->height() < this->width() ? this->height() : this->width();

    ///
    /// \brief Shutdown
    ///
    this->labelShutdown = new QLabel(tr("Shutdown"), this);
    this->labelShutdown->setAlignment(Qt::AlignCenter);
    this->labelShutdown->setStyleSheet(this->formStyleSheetString("label"));
    this->labelShutdown->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QToolButton *buttonLevel_0 = new QToolButton(this);
    buttonLevel_0->setIcon(QIcon(QPixmap(":/images/shutdown.svg").scaledToWidth(t_size, Qt::SmoothTransformation)));
    buttonLevel_0->setCheckable(true);
    buttonLevel_0->setAutoExclusive(true);
    buttonLevel_0->setStyleSheet(this->formStyleSheetString("icon"));
    buttonLevel_0->setToolButtonStyle(Qt::ToolButtonIconOnly);
    buttonLevel_0->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    ///
    /// \brief Restart
    ///
    this->labelRestart = new QLabel(tr("Restart"), this);
    this->labelRestart->setAlignment(Qt::AlignCenter);
    this->labelRestart->setStyleSheet(this->formStyleSheetString("label"));
    this->labelRestart->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QToolButton *buttonLevel_1 = new QToolButton(this);
    buttonLevel_1->setIcon(QIcon(QPixmap(":/images/restart.svg").scaledToWidth(t_size, Qt::SmoothTransformation)));
    buttonLevel_1->setCheckable(true);
    buttonLevel_1->setAutoExclusive(true);
    buttonLevel_1->setStyleSheet(this->formStyleSheetString("icon"));
    buttonLevel_1->setToolButtonStyle(Qt::ToolButtonIconOnly);
    buttonLevel_1->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    ///
    /// \brief Cancel
    ///
    this->labelCancel = new QLabel(tr("Cancel"), this);
    this->labelCancel->setAlignment(Qt::AlignCenter);
    this->labelCancel->setStyleSheet(this->formStyleSheetString("label"));
    this->labelCancel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QToolButton *buttonLevel_2 = new QToolButton(this);
    buttonLevel_2->setIcon(QIcon(QPixmap(":/images/cancel.svg").scaledToWidth(t_size, Qt::SmoothTransformation)));
    buttonLevel_2->setCheckable(true);
    buttonLevel_2->setAutoExclusive(true);
    buttonLevel_2->setStyleSheet(this->formStyleSheetString("icon"));
    buttonLevel_2->setToolButtonStyle(Qt::ToolButtonIconOnly);
    buttonLevel_2->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    /// BUTTON GROUP
    int iter = 0;
    this->buttonGroup = new QButtonGroup(this);
    this->buttonGroup->addButton(buttonLevel_0, iter++);
    this->buttonGroup->addButton(buttonLevel_1, iter++);
    this->buttonGroup->addButton(buttonLevel_2, iter++);
    this->buttonGroup->setExclusive(true);

    ///
    /// \brief Layout
    ///
    QVBoxLayout *buttonLayout_0 = new QVBoxLayout;
    buttonLayout_0->addStretch();
    buttonLayout_0->addWidget(buttonLevel_0);
    buttonLayout_0->addWidget(this->labelShutdown);
    buttonLayout_0->addStretch();

    QVBoxLayout *buttonLayout_1 = new QVBoxLayout;
    buttonLayout_1->addStretch();
    buttonLayout_1->addWidget(buttonLevel_1);
    buttonLayout_1->addWidget(this->labelRestart);
    buttonLayout_1->addStretch();

    QVBoxLayout *buttonLayout_2 = new QVBoxLayout;
    buttonLayout_2->addStretch();
    buttonLayout_2->addWidget(buttonLevel_2);
    buttonLayout_2->addWidget(this->labelCancel);
    buttonLayout_2->addStretch();

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(buttonLayout_0);
    mainLayout->addLayout(buttonLayout_1);
    mainLayout->addLayout(buttonLayout_2);
    mainLayout->setSpacing(0);
    mainLayout->setMargin(0);
    mainLayout->setContentsMargins(0, 0, 0, 0);

    setLayout(mainLayout);
}

void STouchDialogBoot::setConnect()
{
    connect(this->buttonGroup, SIGNAL(buttonPressed(int)), this, SLOT(slotButtonPressed(int)));
    connect(this->buttonGroup, SIGNAL(buttonReleased(int)), this, SLOT(slotButtonReleased(int)));
}

void STouchDialogBoot::slotButtonPressed(int index)
{
    SGraphicsGlowEffect *glow = new SGraphicsGlowEffect;
    glow->setBlurRadius(15);
    glow->setStrength(2);
    this->buttonGroup->button(index)->setGraphicsEffect(glow);
}

void STouchDialogBoot::slotButtonReleased(int index)
{
    this->buttonGroup->button(index)->setGraphicsEffect(nullptr);

    switch (index) {
    case 0: // Shutdown
        if (::GlobalDefinesEmbedded)
        {
            qApp->exit();
            /*
            QProcess shellCommand;
            shellCommand.start("sudo shutdown -h now");
            shellCommand.waitForFinished();
            */
        }
        else
        {
            qApp->exit();
        }
        break;

    case 1: // Restart
        if (::GlobalDefinesEmbedded)
        {
            QProcess shellCommand;
            shellCommand.start("sudo reboot");
            shellCommand.waitForFinished();
        }
        else
        {
            qApp->exit();
        }
        break;

    case 2: // Cancel
        this->slotClose();
        break;

    default:
        break;
    }
}

void STouchDialogBoot::setOpacity(const double opacity)
{
    this->m_opacitiy = opacity;
    update();
}

void STouchDialogBoot::setBaseColor(const QColor &color)
{
    this->m_colorBase = color;
    update();
}

void
STouchDialogBoot::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::HighQualityAntialiasing | QPainter::TextAntialiasing);
    QColor color = ::GlobalColorBase;
    color.setAlphaF(this->m_opacitiy);
    painter.fillRect(event->rect(), QBrush(color));
    painter.end();
}

void STouchDialogBoot::showEvent(QShowEvent *event)
{
    Q_UNUSED(event);

    QPropertyAnimation *animation = new QPropertyAnimation(this, "windowOpacity", this);
    animation->setDuration(::GlobalAnimationFastTimeIn);
    animation->setStartValue(0);
    animation->setEndValue(1);
    animation->setEasingCurve(QEasingCurve::InQuad);
    animation->start(QPropertyAnimation::DeleteWhenStopped);
}

void STouchDialogBoot::slotClose()
{
    QPropertyAnimation *animation = new QPropertyAnimation(this, "windowOpacity", this);
    animation->setDuration(::GlobalAnimationFastTimeOut);
    animation->setStartValue(1);
    animation->setEndValue(0);
    animation->setEasingCurve(QEasingCurve::OutQuad);
    animation->start(QPropertyAnimation::DeleteWhenStopped);

    QTimer::singleShot(::GlobalAnimationTimeOut, this, SLOT(close()));
}

void STouchDialogBoot::retranslateUI()
{
    this->labelShutdown->setText(tr("Shutdown"));
    this->labelRestart->setText(tr("Restart"));
    this->labelCancel->setText(tr("Cancel"));
}

void
STouchDialogBoot::restyleUI()
{
    if (this->m_colorBase != ::GlobalColorCustomBase)
    {
        this->m_colorBase = ::GlobalColorCustomBase;
    }
}

void STouchDialogBoot::changeEvent(QEvent* event)
{
    switch (event->type())
    {
    case QEvent::LanguageChange:
        retranslateUI();
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

QString STouchDialogBoot::formStyleSheetString(const QString &style)
{
    QString styleButton;

    if (!style.compare("icon"))
    {
        styleButton =
        "\
            QToolButton { icon-size: 120px 120px; padding-top: 0px; font: 16pt " + ::GlobalFont + "; color: " + ::GlobalColorText.name() + "; border-image: none; background-color: transparent; border: none; } \
            QToolButton:pressed { icon-size: 120px 120px; padding-top: 0px; font: 16pt " + ::GlobalFont + "; color: " + ::GlobalColorText.name() + "; border-image: none; background-color: transparent; border: none; } \
        ";
    }
    else if (!style.compare("transparent"))
    {
        styleButton =
        "\
            QPushButton:!pressed  { font: 20pt " + ::GlobalFont + "; color: " + ::GlobalColorText.name() + "; background-color: transparent; border: none; } \
            QPushButton:pressed   { font: 20pt " + ::GlobalFont + "; color: " + ::GlobalColorText.name() + "; background-color: transparent; border: none; } \
            QPushButton:disabled  { font: 20pt " + ::GlobalFont + "; color: #404040; background: transparent; border: none; } \
        ";
    }
    else if (!style.compare("label"))
    {
        styleButton =
        "\
            QLabel { font: 16pt " + ::GlobalFont + "; color: " + ::GlobalColorText.name() + "; background: transparent; } \
        ";
    }

    return styleButton;
}
