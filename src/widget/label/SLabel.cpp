#include "SLabel.h"
#include "../widget/button/SPushButton.h"

#include <QEvent>
#include <QVariant>
#include <QButtonGroup>
#include <QHBoxLayout>


SLabel::SLabel(QWidget * parent,
               Qt::WindowFlags f)
    : QLabel(parent)
{
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);

    this->setTheme(Theme::Transparent);
    this->setupWidget();
    this->setConnect();
    this->restyleUI();
}

SLabel::SLabel(const QString & text,
               QWidget * parent,
               Qt::WindowFlags f)
    : QLabel(parent),
      m_text(text)
{
    this->setText(text);
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);

    this->setTheme(Theme::Transparent);
    this->setupWidget();
    this->setConnect();
    this->restyleUI();
}

void
SLabel::setupWidget()
{
    this->slotGroup = new QButtonGroup(this);
}

void
SLabel::setConnect()
{
    connect(this->slotGroup, static_cast<void(QButtonGroup::*)(int)>(&QButtonGroup::buttonPressed), [this] (const int index) {
        emit this->signalPressed(index);
    });
    connect(this->slotGroup, static_cast<void(QButtonGroup::*)(int)>(&QButtonGroup::buttonReleased), [this] (const int index) {
        emit this->signalReleased(index);
    });
    connect(this->slotGroup, static_cast<void(QButtonGroup::*)(int)>(&QButtonGroup::buttonClicked), [this] (const int index) {
        emit this->signalClicked(index);
    });
}

//SLabel::SLabel(const QIcon & icon,
//               const QString & text,
//               QWidget * parent,
//               Qt::WindowFlags f)
//    : QLabel(parent),
//      m_text(text)
//{
//    this->setPixmap(QIcon(icon).pixmap(QSize(this->size())));
//    this->setText(text);
//    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

//    this->setupWidget();
//    this->setConnect();
//    this->setTheme(Theme::None);
//    this->slotReadSettings();
//}

SLabel::~SLabel()
{
}

void
SLabel::header(const QString & text,
               const QChar & left,
               const QChar & right)
{
    int margin = this->width() / 40;

    this->setText(text);
    this->setMinimumHeight(this->height() / 10);
    this->setAlignment(Qt::AlignCenter);
    this->setTheme(Theme::Header);

    SPushButton * buttonLeft = new SPushButton;
    buttonLeft->setObjectName("push");
    buttonLeft->setText(left);
    buttonLeft->setFontSize(24);
    buttonLeft->setMinimumSize(this->minimumHeight(), this->minimumHeight());
    if (left == 0x200A)
    {
        buttonLeft->setDisabled(true);
    }

    SPushButton * buttonRight = new SPushButton;
    buttonRight->setObjectName("push");
    buttonRight->setText(right);
    buttonRight->setFontSize(24);
    buttonRight->setMinimumSize(this->minimumHeight(), this->minimumHeight());
    if (right == 0x200A)
    {
        buttonRight->setDisabled(true);
    }

    auto layout = new QHBoxLayout(this);
    layout->addWidget(buttonLeft, 0, Qt::AlignLeft | Qt::AlignCenter);
    layout->addWidget(buttonRight, 0, Qt::AlignRight | Qt::AlignCenter);
    layout->setContentsMargins(margin, 10, margin, 10);

    int t_iter = 0;
    if (left != 0x200A)
    {
        this->slotGroup->addButton(buttonLeft, t_iter++);
    }
    if (right != 0x200A)
    {
        this->slotGroup->addButton(buttonRight, t_iter++);
    }
}

void
SLabel::header(const int index,
               const QString & text,
               const QChar &left,
               const QChar &right)
{
    this->setText(text);
    if (left != 0x200A)
    {
        this->slotGroup->button(index)->setText(left);
        this->slotGroup->button(index)->setEnabled(true);
    }
    if (right != 0x200A)
    {
        this->slotGroup->button(index)->setText(right);
        this->slotGroup->button(index)->setEnabled(true);
    }
}

void
SLabel::fontSize(const int size)
{
    this->m_fontSize = size;
    this->setStyleSheet(this->formStyleSheet(this->m_style));
}

void
SLabel::setTheme(const Theme &theme)
{
    this->m_style = theme;
    this->setStyleSheet(this->formStyleSheet(theme));
}

QString
SLabel::formStyleSheet(const Theme &style)
{
    QString sheet = "";
    int fontSize = 0;

    switch (style)
    {
    case Theme::Header:
    {
        fontSize = this->m_fontSize == 0 ? 22 : this->m_fontSize;
        sheet = " \
                QLabel { text-align: center; font: " + QString::number(fontSize) + "pt " + ::GlobalFont + "; color: " + this->m_colorText.name() + "; background-color: transparent; border: none; } \
                ";
    }
        break;

    case Theme::Topic:
    {
        fontSize = this->m_fontSize == 0 ? 18 : this->m_fontSize;
        sheet = " \
                QLabel { text-align: center; font: " + QString::number(fontSize) + "pt " + ::GlobalFont + "; color: " + this->m_colorText.darker().name() + "; background-color: transparent; border: none; } \
                ";
    }
        break;

    case Theme::Base:
    {
        fontSize = this->m_fontSize == 0 ? 18 : this->m_fontSize;
        sheet = " \
                QLabel { text-align: center; font: " + QString::number(fontSize) + "pt " + ::GlobalFont + "; color: " + this->m_colorText.name() + "; background-color: " + this->m_colorBase.name() + "; border: none; } \
                ";
    }
        break;

    case Theme::Contrast:
    {
        fontSize = this->m_fontSize == 0 ? 18 : this->m_fontSize;
        sheet = " \
                QLabel { text-align: center; font: " + QString::number(fontSize) + "pt " + ::GlobalFont + "; color: " + this->m_colorText.name() + "; background-color: " + this->m_colorContrast.name() + "; border: none; } \
                ";
    }
        break;

    case Theme::Text:
    {
        fontSize = this->m_fontSize == 0 ? 18 : this->m_fontSize;
        sheet = " \
                QLabel { text-align: center; font: " + QString::number(fontSize) + "pt " + ::GlobalFont + "; color: " + this->m_colorText.name() + "; background-color: transparent; border: none; } \
                ";
    }
        break;

    case Theme::Subtext:
    {
        fontSize = this->m_fontSize == 0 ? 14 : this->m_fontSize;
        sheet = " \
                QLabel { text-align: center; font: " + QString::number(fontSize) + "pt " + ::GlobalFont + "; color: " + this->m_colorText.darker().name() + "; background-color: transparent; border: none; } \
                ";
    }
        break;

    case Theme::Transparent:
    {
        fontSize = this->m_fontSize == 0 ? 26 : this->m_fontSize;
        sheet = " \
                QLabel { text-align: center; font: " + QString::number(fontSize) + "pt " + ::GlobalFont + "; color: " + this->m_colorText.name() + "; background-color: transparent; border: none; } \
                ";
    }
        break;

    case Theme::FilledRoundRect:
    {
        fontSize = this->m_fontSize == 0 ? 20 : this->m_fontSize;
        sheet = " \
                QLabel { margin: " + QString::number(this->height() * 0.2) + "px; text-align: center; font: " + QString::number(fontSize) + "pt " + ::GlobalFont + "; color: " + this->m_colorText.name() + "; background: " + this->m_colorContrast.name() + "; background-color: " + this->m_colorContrast.name() + "; border: none; border-radius: " + QString::number(this->height() * 0.8) + "px; } \
                ";
    }
        break;

    case Theme::None:
        sheet = " \
                QLabel { color: transparent; background-color: transparent; background: transparent; border: none; } \
                ";
        break;
    }

    return sheet;
}

void
SLabel::restyleUI()
{
    if (this->m_colorBase != ::GlobalColorCustomBase)
    {
        this->m_colorBase = ::GlobalColorCustomBase;
        this->setStyleSheet(this->formStyleSheet(this->m_style));
    }
    if (this->m_colorContrast != ::GlobalColorCustomContrast)
    {
        this->m_colorContrast = ::GlobalColorCustomContrast;
        this->setStyleSheet(this->formStyleSheet(this->m_style));
    }
    if (this->m_colorHighlight != ::GlobalColorCustomHighlight)
    {
        this->m_colorHighlight = ::GlobalColorCustomHighlight;
        this->setStyleSheet(this->formStyleSheet(this->m_style));
    }
    if (this->m_colorText != ::GlobalColorCustomText)
    {
        this->m_colorText = ::GlobalColorCustomText;
        this->setStyleSheet(this->formStyleSheet(this->m_style));
    }
}

void
SLabel::changeEvent(QEvent * event)
{
    switch (event->type())
    {
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
