#include "SList.h"
#include "../widget/button/SPushButton.h"
#include "../widget/button/SIconButton.h"
#include "../widget/slider/SSlider.h"

#include <QTimer>
#include <QButtonGroup>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QVariant>
#include <QFrame>
#include <QDebug>


SList::SList(QWidget * parent)
    : QWidget(parent)
{
    this->setupProperty();
    this->setupWidget();
    this->setConnect();
}

SList::~SList()
{
    this->clear();
}

void
SList::setupProperty()
{
    this->setObjectName("SList");
    this->setWindowState(Qt::WindowFullScreen);
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    this->setWindowFlags(this->windowFlags() | Qt::Window | Qt::FramelessWindowHint);

}

void
SList::setupWidget()
{
    this->m_groupTopic = new QButtonGroup(this);

    this->m_groupSlot = new QButtonGroup(this);
    this->m_groupSlot->setExclusive(true);

    this->m_layoutList = new QVBoxLayout;
    this->m_layoutList->addStretch(1);
}

void
SList::setConnect()
{
    QObject::connect(this->m_groupSlot, static_cast<void(QButtonGroup::*)(int)>(&QButtonGroup::buttonPressed), [this](const int index) {
        QTimer::singleShot(this->m_delay, [this, index] ()
        {
            emit this->signalPressed(index);
            emit this->signalPressed(this->item(index, Item::Text));
        });
    });
    QObject::connect(this->m_groupSlot, static_cast<void(QButtonGroup::*)(int)>(&QButtonGroup::buttonReleased), [this](const int index) {
        QTimer::singleShot(this->m_delay, [this, index] ()
        {
            emit this->signalReleased(index);
            emit this->signalReleased(this->item(index, Item::Text));            
        });
    });
    QObject::connect(this->m_groupSlot, static_cast<void(QButtonGroup::*)(int)>(&QButtonGroup::buttonClicked), [this](const int index) {
        QTimer::singleShot(this->m_delay, [this, index] ()
        {
            emit this->signalClicked(index);
            emit this->signalClicked(this->item(index, Item::Text));
        });
    });
}

SVScrollArea *
SList::list(QWidget * parent)
{
    if (parent == nullptr)
    {
        parent = this;
    }

    /* Add list to widget */
    QWidget * widget = new QWidget;
    widget->setLayout(this->m_layoutList);
    /* Add widget to Scroll Area */
    SVScrollArea * scrollArea = new SVScrollArea(parent);
    scrollArea->enableScrollBar(this->m_scrollBar);
    scrollArea->setWidget(widget);

    return scrollArea;
}

void
SList::title(const QString & text)
{
    int margin = this->width() / 40;

    SPushButton * button = new SPushButton(this);
    button->setObjectName("title");
    button->setMinimumHeight(this->height() / 10);
    button->setAttribute(Qt::WA_TransparentForMouseEvents);

    SLabel * labelText = new SLabel;
    labelText->setObjectName("text");
    labelText->setText(text);
    labelText->setAttribute(Qt::WA_TransparentForMouseEvents);
    labelText->setWordWrap(true);
    labelText->setTheme(SLabel::Theme::Topic);

    auto layout = new QHBoxLayout(button);
    layout->addWidget(labelText);
//    layoutText->setSpacing(0);
//    layoutText->setMargin(0);
    layout->setContentsMargins(margin, 10, margin, 10);

    this->m_list.push_back(button);
    this->m_groupTopic->addButton(button, this->m_iterTopics++);
}

void
SList::addTitle(const QString & text)
{
    /* Add slot to list. */
    this->title(text);
    /* Append slot to layout. */
    this->m_layoutList->insertWidget(this->m_layoutList->count() - 1, this->m_list.last());
}

void
SList::setTitle(const int index,
             const QString & text)
{
    if (index >= this->m_groupTopic->buttons().size())
    {
        return;
    }

    auto labels = this->m_groupTopic->button(index)->findChildren<SLabel *>();

    for (auto label : labels)
    {
        if (!text.isEmpty() && (!label->objectName().compare(QVariant::fromValue(Item::Text).toString(), Qt::CaseInsensitive)))
        {
            label->setText(text);
        }
    }
}

void
SList::slot(const QIcon &icon,
            const QString & text,
            const QString & subtext,
            const QString & info,
            const QString & symbol,
            Qt::BGMode mode)
{
    int margin = this->width() / 40;

    /* Button - Parent widget */
    SPushButton * button = new SPushButton(this);
    button->setObjectName("slot");
    if (this->m_box || this->m_banner)
    {
        button->setBackgroundMode(mode);
        button->setDisabledMode(false);
        button->setMinimumHeight(this->height() / 1.5);
        if (this->m_banner)
        {
            button->setAttribute(Qt::WA_TransparentForMouseEvents);
        }
    }
    else if (this->m_line)
    {
        button->setMinimumHeight(this->height() / 8);
    }
    else
    {
        button->setBackgroundMode(mode);
        button->setMinimumHeight(this->height() / 5);
    }

    /* Icon */
    SIconButton * t_icon = new SIconButton(QIcon());
    t_icon->setObjectName("icon");
    t_icon->setAttribute(Qt::WA_TransparentForMouseEvents);
    if (!icon.isNull())
    {
        t_icon->setIcon(QIcon(icon));
        if (this->m_box || this->m_banner)
        {
            t_icon->setIconSize(QSize(button->width() * 4, button->height() * 0.5));
        }
        else
        {
            t_icon->setIconSize(QSize(button->size() / 1.5));
        }
    }
    else
    {
        t_icon->setVisible(false);
    }

    /* Text */
    SLabel * labelText = new SLabel;
    labelText->setObjectName("text");
    labelText->setText(text);
    labelText->setAttribute(Qt::WA_TransparentForMouseEvents);
    labelText->setWordWrap(true);
    labelText->setTheme(SLabel::Theme::Text);
    if (text.isEmpty())
    {
        labelText->setVisible(false);
    }

    /* Subtext */
    SLabel * labelSubtext = new SLabel;
    labelSubtext->setObjectName("subtext");
    labelSubtext->setText(subtext);
    labelSubtext->setAttribute(Qt::WA_TransparentForMouseEvents);
    labelSubtext->setWordWrap(true);
    labelSubtext->setTheme(SLabel::Theme::Subtext);
    if (subtext.isEmpty())
    {
        labelSubtext->setVisible(false);
    }

    /* Info */
    SLabel * labelInfo = new SLabel;
    labelInfo->setObjectName("info");
    labelInfo->setText(info);
    labelInfo->setAttribute(Qt::WA_TransparentForMouseEvents);
    labelInfo->setTheme(SLabel::Theme::Subtext);
    if (info.isEmpty())
    {
        if (this->m_box || this->m_banner)
        {
            labelInfo->setVisible(false);
        }
    }

    /* Symbol */
    SLabel * labelSymbol = new SLabel;
    labelSymbol->setObjectName("symbol");
    labelSymbol->setText(symbol);
    labelSymbol->setAttribute(Qt::WA_TransparentForMouseEvents);
    labelSymbol->setTheme(SLabel::Theme::Subtext);
    if (symbol.isEmpty())
    {
        if (this->m_box || this->m_banner)
        {
            labelSymbol->setVisible(false);
        }
    }

    // TODO: Make a signal connection with index and valueChanged to outside!
    /* Slider */
    SSlider * slider = nullptr;
    if (this->m_slider)
    {
        slider = new SSlider;
        slider->setObjectName("slider");
        slider->setRange(this->m_min, this->m_max);
    }

    /* Layout */
    if (this->m_box || this->m_banner)
    {
        auto layoutBottom = new QHBoxLayout;
        layoutBottom->addWidget(labelSubtext, 8, Qt::AlignCenter | Qt::AlignLeft);
        layoutBottom->addWidget(labelInfo, 1, Qt::AlignCenter | Qt::AlignRight);
        layoutBottom->addWidget(labelSymbol, 1, Qt::AlignCenter | Qt::AlignRight);
        auto layoutText = new QVBoxLayout;
        layoutText->addWidget(labelText, 0, Qt::AlignCenter | Qt::AlignLeft);
        layoutText->addLayout(layoutBottom);
        layoutText->addStretch();
        layoutText->setContentsMargins(15, 15, 15, 15);

        auto layout = new QVBoxLayout(button);
        layout->addWidget(t_icon, 3, Qt::AlignCenter);
        layout->addLayout(layoutText, 2);
        layout->setContentsMargins(margin, 10, margin, margin);
    }
    else if (this->m_slider)
    {
        auto layoutTop = new QHBoxLayout;
        layoutTop->addWidget(labelText, 2, Qt::AlignCenter | Qt::AlignLeft);
        layoutTop->addWidget(labelInfo, 1, Qt::AlignCenter | Qt::AlignRight);
        auto layoutBottom = new QHBoxLayout;
        layoutBottom->addWidget(slider, Qt::AlignCenter);

        auto layout = new QVBoxLayout(button);
        layout->addLayout(layoutTop, 7);
        layout->addLayout(layoutBottom, 1);
    }
    else
    {
        auto layoutText = new QVBoxLayout;
        layoutText->addStretch();
        layoutText->addWidget(labelText, 0, Qt::AlignLeft);
        layoutText->addWidget(labelSubtext, 0, Qt::AlignLeft);
        layoutText->addStretch();

        auto layout = new QHBoxLayout(button);
        layout->addWidget(t_icon, 3, Qt::AlignCenter);
        layout->addLayout(layoutText,  8);
//        layout->addLayout(layoutText, icon.isEmpty() ? 10 : 8);
        layout->addWidget(labelInfo, 1, Qt::AlignCenter | Qt::AlignRight);
        layout->addWidget(labelSymbol, 1, Qt::AlignCenter | Qt::AlignRight);
 //       layoutText->setSpacing(0);
        layout->setContentsMargins(icon.isNull() ? margin : 0, 10, margin, 10);
    }

    this->m_list.push_back(button);
    this->m_groupSlot->addButton(button, this->m_iterSlots++);
}

void
SList::addSlot(const QIcon &icon,
               const QString & text,
               const QString & subtext,
               const QString & info,
               const QString & symbol,
               Qt::BGMode mode)
{
    /* Add slot to list. */
    this->slot(icon, text, subtext, info, symbol, mode);
    /* Append slot to layout. */
    this->m_layoutList->insertWidget(this->m_layoutList->count() - 1, this->m_list.last());
}

void
SList::setSlot(const int index,
               const QIcon &icon,
               const QString & text,
               const QString & subtext,
               const QString & info,
               const QString & symbol,
               Qt::BGMode mode)
{
    // TODO: add error message!
    if (index >= this->m_groupSlot->buttons().size())
    {
        return;
    }

    /* Icon */
    auto t_icons = this->m_groupSlot->button(index)->findChildren<SIconButton *>();

    for (auto t_icon : t_icons)
    {
        if (!icon.isNull() && (!t_icon->objectName().compare(QVariant::fromValue(Item::Icon).toString(), Qt::CaseInsensitive)))
        {
            t_icon->setIcon(QIcon(icon));
            // FIXME
            if (this->m_box || this->m_banner)
            {
//                t_icon->setIconSize(QSize(button->width() * 4, button->height() * 0.5));
            }
            else
            {
//                t_icon->setIconSize(QSize(button->size() / 1.5));
            }
        }
    }


    /* Text */
    auto labels = this->m_groupSlot->button(index)->findChildren<SLabel *>();

    for (auto label : labels)
    {
        if (!text.isEmpty() && (!label->objectName().compare(QVariant::fromValue(Item::Text).toString(), Qt::CaseInsensitive)))
        {
            label->setText(text);
        }
        else if (!subtext.isEmpty() && (!label->objectName().compare(QVariant::fromValue(Item::Subtext).toString(), Qt::CaseInsensitive)))
        {
            label->setText(subtext);
        }
        else if (!info.isEmpty() && (!label->objectName().compare(QVariant::fromValue(Item::Info).toString(), Qt::CaseInsensitive)))
        {
            label->setText(info);
        }
        else if (!symbol.isEmpty() && (!label->objectName().compare(QVariant::fromValue(Item::Symbol).toString(), Qt::CaseInsensitive)))
        {
            label->setText(symbol);
        }
    }
}

void
SList::line(const QIcon &icon,
            const QString & text,
            Qt::BGMode mode)
{
    this->m_line = true;
    this->slot(icon, text, "", "", "", mode);
    this->m_line = false;
}

void
SList::addLine(const QIcon &icon,
               const QString & text,
               Qt::BGMode mode)
{
    /* Add line to list. */
    this->line(icon, text, mode);
    /* Append line to layout. */
    this->m_layoutList->insertWidget(this->m_layoutList->count() - 1, this->m_list.last());
}

void
SList::setLine(const int index,
               const QIcon &icon,
               const QString & text,
               Qt::BGMode mode)
{
    this->m_line = true;
    this->setSlot(index, icon, text, "", "", "", mode);
    this->m_line = false;
}

void
SList::box(const QIcon &icon,
           const QString & text,
           const QString & subtext,
           const QString & info,
           const QString & symbol,
           Qt::BGMode mode)
{
    this->m_box = true;
    this->slot(icon, text, subtext, info, symbol, mode);
    this->m_box = false;
}

void
SList::addBox(const QIcon &icon,
              const QString & text,
              const QString & subtext,
              const QString & info,
              const QString & symbol,
              Qt::BGMode mode)
{
    /* Add box to list. */
    this->box(icon, text, subtext, info, symbol, mode);
    /* Append box to layout. */
    this->m_layoutList->insertWidget(this->m_layoutList->count() - 1, this->m_list.last());
}

void
SList::setBox(const int index,
              const QIcon &icon,
              const QString & text,
              const QString & subtext,
              const QString & info,
              const QString & symbol,
              Qt::BGMode mode)
{
    this->m_box = true;
    this->setSlot(index, icon, text, subtext, info, symbol, mode);
    this->m_box = false;
}

void
SList::banner(const QIcon &icon,
              const QString & text,
              const QString & subtext,
              Qt::BGMode mode)
{
    this->m_banner = true;
    this->box(icon, text, subtext, "", "", mode);
    this->m_banner = false;
}

void
SList::addBanner(const QIcon &icon,
                 const QString & text,
                 const QString & subtext,
                 Qt::BGMode mode)
{
    /* Add banner to list. */
    this->banner(icon, text, subtext, mode);
    /* Append banner to layout. */
    this->m_layoutList->insertWidget(this->m_layoutList->count() - 1, this->m_list.last());
}

void
SList::setBanner(const int index,
                 const QIcon &icon,
                 const QString & text,
                 const QString & subtext,
                 Qt::BGMode mode)
{
    this->m_banner = true;
    this->setBox(index, icon, text, subtext, "", "", mode);
    this->m_banner = false;
}

void
SList::slider(const QString & text,
              const QString & info,
              const int min,
              const int max,
              Qt::BGMode mode)
{
    this->m_min = min;
    this->m_max = max;
    this->m_slider = true;
    this->slot(QIcon(), text, "", info, "", mode);
    this->m_slider = false;
}

void
SList::addSlider(const QString & text,
                 const QString & info,
                 const int min,
                 const int max,
                 Qt::BGMode mode)
{
    /* Add slider to list. */
    this->slider(text, info, min, max, mode);
    /* Add slider to list. */
    this->m_layoutList->insertWidget(this->m_layoutList->count() - 1, this->m_list.last());
}

void
SList::setSlider(const int index,
                 const QString & text,
                 const QString & info,
                 const int min,
                 const int max,
                 Qt::BGMode mode)
{
    this->m_min = min;
    this->m_max = max;
    this->m_slider = true;
    this->setSlot(index, QIcon(), text, "", info, "", mode);
    this->m_slider = false;
}

void
SList::divider(const SLabel::Theme style)
{
    SLabel * divider = new SLabel;
    divider->setObjectName("accessoire");
    divider->setMaximumHeight(this->m_space);
    divider->setAttribute(Qt::WA_TransparentForMouseEvents);
    divider->setTheme(style);
 //    divider->setContentsMargins(0, 0, 0, 0);

    /* Add to list. */
    this->m_list.push_back(divider);
    /* Add slider to list. */
    this->m_layoutList->insertWidget(this->m_layoutList->count() - 1, this->m_list.last());
}

void
SList::spacer(const int space, const SLabel::Theme style)
{
    this->m_spacer = true;
    this->m_space = space;
    this->divider(style);
    this->m_spacer = false;
}

void
SList::setItems(QString text,
                Item item)
{
    for (auto button : this->m_groupSlot->buttons())
    {
        auto labels = button->findChildren<SLabel *>();

        for (auto label : labels)
        {
            if (!label->objectName().compare(QVariant::fromValue(item).toString(), Qt::CaseInsensitive))
            {
                label->setText(text);
            }
        }
    }
}

void
SList::setItem(const int index,
               QString text,
               Item item)
{
    auto labels = this->m_groupSlot->button(index)->findChildren<SLabel *>();

    for (auto label : labels)
    {
        if (!label->objectName().compare(QVariant::fromValue(item).toString(), Qt::CaseInsensitive))
        {
            label->setText(text);
//            if (!label->wordWrap())
//            {
//                label->setText(this->elidedText(label, text));
//            }
//            else
//            {
//                label->setText(text);
//            }
        }
    }

//    qDebug() << QMetaEnum::fromType<SList::Item>().valueToKey(item);
}

SPushButton *
SList::item(const int index)
{
    // TODO: add error message!
    if (index >= this->m_groupSlot->buttons().size())
    {
        return static_cast<SPushButton *>(this->m_groupSlot->button(index));
    }
}

//QList<QAbstractButton *>
//SList::items()
//{
//    return this->m_groupSlot->buttons();
//}

QString
SList::item(const int index,
            Item item)
{
    QString string = "";

    // TODO: add error message!
    if (index >= this->m_groupSlot->buttons().size())
    {
        return QString("");
    }

    auto labels = this->m_groupSlot->button(index)->findChildren<SLabel *>();

    for (auto label : labels)
    {
        if (!label->objectName().compare(QVariant::fromValue(item).toString(), Qt::CaseInsensitive))
        {
            string = label->text();
        }
    }

//    qDebug() << string;

    return string;
}

void
SList::index(const int index)
{
    if ((index < this->m_groupSlot->buttons().size()) && this->m_groupSlot->button(index)->isCheckable())
    {
        this->m_groupSlot->button(index)->setChecked(true);
    }
}

int
SList::index() const
{
    return this->m_groupSlot->checkedId();
}

void
SList::enableScrollBar(const bool enable)
{
    this->m_scrollBar = enable;
}

QString
SList::elidedText(const SLabel * label,
                  const QString & text,
                  const Qt::TextElideMode elide)
{
    QFontMetrics t_metrics(label->font());
    return t_metrics.elidedText(text, elide, label->width());
}

int
SList::size()
{
    return this->m_groupSlot->buttons().size();
}

void
SList::clear()
{
    /* Delete */
    this->clearButtonGroup(this->m_groupSlot);
    this->clearButtonGroup(this->m_groupTopic);
    this->clearLayout(this->m_layoutList, true);
    this->clearList(this->m_list);

    /* Init */
    this->m_iterSlots = 0;
    this->m_iterTopics = 0;
    this->m_layoutList->addStretch(1);
}

void
SList::clearList(QList<QWidget *> list)
{
    if (!list.isEmpty())
    {
        list.erase(list.begin(), list.end());
    }
}

void
SList::clearButtonGroup(QButtonGroup * buttonGroup,
                        bool deleteButton)
{
    foreach(QAbstractButton * button, buttonGroup->buttons())
    {
        buttonGroup->removeButton(button);
        if (deleteButton)
        {
            delete button;
        }
    }
}

void
SList::clearLayout(QLayout * layout,
                   bool deleteWidgets)
{
    while (QLayoutItem * item = layout->takeAt(0))
    {
        QWidget * widget;
        if (deleteWidgets && (widget = item->widget()))
        {
            delete widget;
        }
        if (QLayout * childLayout = item->layout())
        {
            this->clearLayout(childLayout, deleteWidgets);
        }
        delete item;
    }
}
