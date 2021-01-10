#include "STextDialog.h"
#include "../components/qtmaterialdialog.h"
#include "../widget/label/SLabel.h"
#include "../widget/button/SPushButton.h"
#include "../widget/layout/SVScrollArea.h"

#include <QVBoxLayout>
#include <QLabel>
#include <QEvent>
#include <QTimer>
#include <QColorDialog>


STextDialog::STextDialog(QWidget *parent)
    : QDialog(parent),
      m_titleLabel(new SLabel),
      m_textLabel(new SLabel),
      m_dialog(new QtMaterialDialog),
      m_rejectButton(new SPushButton),
      m_acceptButton(new SPushButton)
{
    this->setupProperty();
    this->setupWidget();
    this->setupLayout();
    this->setConnect();
    this->restyleUI();
}

STextDialog::~STextDialog()
{
}

void
STextDialog::setupProperty()
{
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

    this->setBackgroundColor(this->m_colorBase);
    this->setForegroundColor(this->m_colorContrast);
}

void
STextDialog::setupWidget()
{
    this->m_titleLabel->setTheme(SLabel::Theme::Header);
    this->m_titleLabel->setFont(QFont("Roboto", 15, QFont::Bold));

    this->m_textLabel->setTheme(SLabel::Theme::Text);
    this->m_textLabel->setFont(QFont("Roboto", 14, QFont::Normal));
    this->m_textLabel->setWordWrap(true);

    /* Dialog */
    this->m_dialog->setParent(this);
}

void
STextDialog::setupLayout()
{
    /* Button layout */
    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addStretch(10);
    buttonLayout->addWidget(this->m_rejectButton, 9, Qt::AlignBottom | Qt::AlignRight);
    buttonLayout->addWidget(this->m_acceptButton, 9, Qt::AlignBottom | Qt::AlignRight);

    /* Text layout */
    QVBoxLayout *textLayout = new QVBoxLayout;
    textLayout->addWidget(this->m_textLabel);
    textLayout->addStretch(1);
    /* Add list to widget */
    QWidget * widget = new QWidget;
    widget->setLayout(textLayout);
    /* Add text label to Scroll Area */
    SVScrollArea * scrollArea = new SVScrollArea(this);
    scrollArea->enableScrollBar(true);
    scrollArea->setWidget(widget);
    scrollArea->setMaximumHeight(this->height() * 0.4);
    scrollArea->setFixedWidth(this->width() * 0.9);

    /* Main layout */
    QVBoxLayout *dialogLayout = new QVBoxLayout(this);
    dialogLayout->addWidget(this->m_titleLabel);
    dialogLayout->addWidget(scrollArea);
    dialogLayout->addLayout(buttonLayout);
    dialogLayout->setContentsMargins(20, 20, 20, 20);

    /* Set layout to dialog */
    this->m_dialog->setWindowLayout(dialogLayout);
}

void
STextDialog::setConnect()
{
    connect(this->m_rejectButton, &SPushButton::released, [this]() {
        this->m_accepted = false;
        this->m_dialog->hideDialog();
        QTimer::singleShot(300, this, &STextDialog::close);
    });
    connect(this->m_acceptButton, &SPushButton::released, [this]() {
        this->m_accepted = true;
        this->m_dialog->hideDialog();
        QTimer::singleShot(300, this, &STextDialog::close);
    });
}

void
STextDialog::setTitle(const QString &text)
{
    this->m_title = text;
    this->m_titleLabel->setText(text);
    this->update();
}

QString
STextDialog::title() const
{
    return this->m_title;
}

void
STextDialog::setDescription(const QString &text)
{
    this->m_text = text;
    this->m_textLabel->setText(text);
    this->update();
}

QString
STextDialog::description() const
{
    return this->m_text;
}

void
STextDialog::setAcceptButton(const QString &text)
{
    this->m_acceptButton->setText(text);
    this->m_acceptButton->setVisible(true);

    if (this->m_rejectButton->text().isEmpty())
    {
        this->m_rejectButton->setVisible(false);
    }
    this->update();
}

void
STextDialog::setRejectButton(const QString &text)
{
    this->m_rejectButton->setText(text);
    this->m_rejectButton->setVisible(true);

    if (this->m_acceptButton->text().isEmpty())
    {
        this->m_acceptButton->setVisible(false);
    }
    this->update();
}

bool
STextDialog::isAccepted()
{
    return m_accepted;
}

bool
STextDialog::isRejected()
{
    return !m_accepted;
}

void
STextDialog::setBackgroundColor(const QColor &color)
{
    this->m_colorBase = color;
    this->m_dialog->setBackgroundColor(color);
}

void
STextDialog::setForegroundColor(const QColor &color)
{
    this->m_colorContrast = color;
    this->m_dialog->setForegroundColor(color);
}

void
STextDialog::restyleUI()
{
    if (this->m_colorBase != ::GlobalColorCustomBase)
    {
        this->m_colorBase = ::GlobalColorCustomBase;
        this->setBackgroundColor(this->m_colorBase);
    }
    if (this->m_colorContrast != ::GlobalColorCustomContrast)
    {
        this->m_colorContrast = ::GlobalColorCustomContrast;
        this->setForegroundColor(this->m_colorContrast);
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
STextDialog::changeEvent(QEvent * event)
{
    switch (event->type())
    {
    case QEvent::StyleChange:
        this->restyleUI();
        break;

    default:
        break;
    }

    QWidget::changeEvent(event);
}

void
STextDialog::showEvent(QShowEvent *event)
{
    Q_UNUSED(event);

    this->m_dialog->showDialog();
}
