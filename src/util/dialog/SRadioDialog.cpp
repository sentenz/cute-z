#include "SRadioDialog.h"
#include "../components/qtmaterialdialog.h"
#include "../widget/label/SLabel.h"
#include "../widget/button/SRadioButton.h"
#include "../widget/button/SPushButton.h"
#include "../widget/layout/SVScrollArea.h"

#include <QVBoxLayout>
#include <QButtonGroup>
#include <QLabel>
#include <QEvent>
#include <QTimer>
#include <QColorDialog>


SRadioDialog::SRadioDialog(QWidget *parent)
    : QDialog(parent),
      m_titleLabel(new SLabel),
      m_radioLayout(new QVBoxLayout),
      m_buttonGroup(new QButtonGroup),
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

SRadioDialog::~SRadioDialog()
{
    /* Button group */
    foreach(QAbstractButton * button, this->m_buttonGroup->buttons())
    {
        this->m_buttonGroup->removeButton(button);
        delete button;
    }
}

void
SRadioDialog::setupProperty()
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
SRadioDialog::setupWidget()
{
    this->m_titleLabel->setTheme(SLabel::Theme::Header);
    this->m_titleLabel->setFont(QFont("Roboto", 15, QFont::Bold));

    this->m_dialog->setParent(this);
}

void
SRadioDialog::setupLayout()
{
    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addStretch(10);
    buttonLayout->addWidget(this->m_rejectButton, 9, Qt::AlignBottom | Qt::AlignRight);
    buttonLayout->addWidget(this->m_acceptButton, 9, Qt::AlignBottom | Qt::AlignRight);

    /* Add list to widget */
    QWidget * widget = new QWidget;
    widget->setLayout(this->m_radioLayout);
    /* Add text label to Scroll Area */
    SVScrollArea * scrollArea = new SVScrollArea(this);
    scrollArea->enableScrollBar(true);
    scrollArea->setWidget(widget);
    scrollArea->setMaximumHeight(this->height() * 0.4);
    scrollArea->setFixedWidth(this->width() * 0.9);

    QVBoxLayout *dialogLayout = new QVBoxLayout(this);
    dialogLayout->addWidget(this->m_titleLabel);
    dialogLayout->addWidget(scrollArea);
    dialogLayout->addLayout(buttonLayout);
    dialogLayout->setContentsMargins(20, 20, 20, 20);

    this->m_dialog->setWindowLayout(dialogLayout);
}

void
SRadioDialog::setConnect()
{
    QObject::connect(this->m_buttonGroup, static_cast<void(QButtonGroup::*)(int, bool)>(&QButtonGroup::buttonToggled), [this](const int id, const bool toggled) {
        this->m_index = id;
    });
    QObject::connect(this->m_rejectButton, &SPushButton::released, [this]() {
        this->m_accepted = false;
        this->m_dialog->hideDialog();
        QTimer::singleShot(300, this, &SRadioDialog::close);
    });
    QObject::connect(this->m_acceptButton, &SPushButton::released, [this]() {
        this->m_accepted = true;
        this->m_dialog->hideDialog();
        QTimer::singleShot(300, this, &SRadioDialog::close);
    });
}

void
SRadioDialog::setTitle(const QString &text)
{
    this->m_title = text;
    this->m_titleLabel->setText(text);
    this->update();
}

QString
SRadioDialog::title() const
{
    return this->m_title;
}

void
SRadioDialog::addText(const QString &text)
{
    SRadioButton * button = new SRadioButton;
    button->setText(text);

    this->m_radioLayout->addWidget(button);
    if (this->m_buttonGroup->buttons().isEmpty())
    {
        this->m_buttonGroup->addButton(button, 0);
    }
    else
    {
        this->m_buttonGroup->addButton(button, this->m_buttonGroup->buttons().size());
    }
}

void
SRadioDialog::setIndex(const int index)
{
    this->m_index = index;
    if ((index < this->m_buttonGroup->buttons().size()))
    {
        this->m_buttonGroup->button(index)->setChecked(true);
    }
}

int
SRadioDialog::index()
{
    return this->m_index;
}

void
SRadioDialog::setAcceptButton(const QString &text)
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
SRadioDialog::setRejectButton(const QString &text)
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
SRadioDialog::isAccepted()
{
    return m_accepted;
}

bool
SRadioDialog::isRejected()
{
    return !m_accepted;
}

void
SRadioDialog::setBackgroundColor(const QColor &color)
{
    this->m_colorBase = color;
    this->m_dialog->setBackgroundColor(color);
}

void
SRadioDialog::setForegroundColor(const QColor &color)
{
    this->m_colorContrast = color;
    this->m_dialog->setForegroundColor(color);
}

void
SRadioDialog::restyleUI()
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
SRadioDialog::changeEvent(QEvent * event)
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
SRadioDialog::showEvent(QShowEvent *event)
{
    Q_UNUSED(event);

    this->m_dialog->showDialog();
}
