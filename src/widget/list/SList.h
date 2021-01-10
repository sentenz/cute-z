#ifndef SLIST_H
#define SLIST_H

#include <QWidget>
#include <QList>

#include "../widget/layout/SVScrollArea.h"
#include "../widget/label/SLabel.h"

class QButtonGroup;
class QVBoxLayout;

class SLabel;
class SPushButton;


class SList : public QWidget
{
    Q_OBJECT
public:
    enum class Item {
        Icon,
        Text,
        Subtext,
        Info,
        Symbol,
        Slider
    };
    Q_ENUM(Item)

    explicit SList(QWidget * parent = nullptr);
    ~SList();

    /**
     * @brief title Header or Group name in a List view.
     * @param text Name of title.
     */
    void addTitle(const QString & text);
    void setTitle(const int index, const QString & text);

    /**
     * @brief sLot Active slot view in a List.
     * @param icon Icon of a slot. Can remain empty.
     * @param text Header text of a slot. Can remain empty.
     * @param subtext Description of a slot with activated word wrap. Can remain empty.
     * @param info Info of the actuell value. Can remain empty.
     * @param symbol Any symbol e.g. arrow. Can remain empty.
     */
    void addSlot(const QIcon & icon, const QString & text, const QString & subtext, const QString & info, const QString & symbol, Qt::BGMode mode = Qt::TransparentMode);
    void setSlot(const int index, const QIcon & icon, const QString & text, const QString & subtext, const QString & info, const QString & symbol, Qt::BGMode mode = Qt::TransparentMode);

    /**
     * @brief line Active line view in a List.
     * @param icon Icon of a line.
     * @param text Header text of a line.
     */
    void addLine(const QIcon & icon, const QString & text, Qt::BGMode mode = Qt::TransparentMode);
    void setLine(const int index, const QIcon & icon, const QString & text, Qt::BGMode mode = Qt::TransparentMode);

    /**
     * @brief box Active box view in a list. Box uses slots underniev.
     * @param icon Icon of a slot. Can remain empty.
     * @param text Header text of a slot. Can remain empty.
     * @param subtext Description of a slot with activated word wrap. Can remain empty.
     * @param info Info of the actuell value. Can remain empty.
     * @param symbol Any symbol e.g. arrow. Can remain empty.
     */
    void addBox(const QIcon & icon, const QString & text, const QString & subtext, const QString & info, const QString & symbol, Qt::BGMode mode = Qt::OpaqueMode);
    void setBox(const int index, const QIcon & icon, const QString & text, const QString & subtext, const QString & info, const QString & symbol, Qt::BGMode mode = Qt::OpaqueMode);

    /**
     * @brief banner Inactive box view in a list. Banner uses box underniev.
     * @param icon Icon of a slot. Can remain empty.
     * @param text Header of a slot. Can remain empty.
     * @param subtext Description of a slot with activated word wrap. Can remain empty.
     */
    void addBanner(const QIcon & icon, const QString & text, const QString & subtext, Qt::BGMode mode = Qt::TransparentMode);
    void setBanner(const int index, const QIcon & icon, const QString & text, const QString & subtext, Qt::BGMode mode = Qt::TransparentMode);

    /**
     * @brief slider
     * @param text
     * @param info
     * @param min
     * @param max
     */
    void addSlider(const QString & text, const QString & info, const int min, const int max, Qt::BGMode mode = Qt::TransparentMode);
    void setSlider(const int index, const QString & text, const QString & info, const int min, const int max, Qt::BGMode mode = Qt::TransparentMode);

    /**
     * @brief divider Sets a line to divide groups.
     * @param style
     */
    void divider(const SLabel::Theme style = SLabel::Theme::Contrast);

    /**
     * @brief spacer Sets a space between two slots.
     * @param space Size of the spacer.
     * @param style
     */
    void spacer(const int space = 15, const SLabel::Theme style = SLabel::Theme::Base);

    /**
     * @brief widget Container and Scroll Area for slots, boxes and titles etc.
     * @param parent
     * @return Returns vertical Scroll Area with slots.
     */
    SVScrollArea * list(QWidget * parent = nullptr);

    /**
     * @brief item Get / Set item text at a given index.
     * @param index Index of a item in a slot.
     * @param text Text to set to a item in a slot.
     * @return Returns QString of a slot, else void.
     */
    void setItems(QString text, Item item);
    void setItem(const int index, QString text, Item item);
    QString item(const int index, Item item);
    SPushButton * item(const int index);
//    QList<QAbstractButton *> items();

    /**
     * @brief index Set current index.
     * @param index Index passt.
     */
    void index(const int index);
    int index() const;

    /**
     * @brief enableScrollBar Enable vertical scroll bar.
     * @param enable Visiable if true.
     */
    void enableScrollBar(const bool enable);

    int size();

    void clear();

signals:
    void signalPressed(const int index);
    void signalPressed(const QString &content);

    void signalReleased(const int index);
    void signalReleased(const QString &content);

    void signalClicked(const int index);
    void signalClicked(const QString &content);

public slots:

private:
    void title(const QString & text);
    void slot(const QIcon & icon, const QString & text, const QString & subtext, const QString & info, const QString & symbol, Qt::BGMode mode = Qt::TransparentMode);
    void line(const QIcon & icon, const QString & text, Qt::BGMode mode = Qt::TransparentMode);
    void box(const QIcon & icon, const QString & text, const QString & subtext, const QString & info, const QString & symbol, Qt::BGMode mode = Qt::OpaqueMode);
    void banner(const QIcon & icon, const QString & text, const QString & subtext, Qt::BGMode mode = Qt::TransparentMode);
    void slider(const QString & text, const QString & info, const int min, const int max, Qt::BGMode mode = Qt::TransparentMode);

    /**
     * @brief setupProperty Member function to initialize properties.
     */
    void setupProperty();

    /**
     * @brief setupWidget Member function to initialize widgets.
     */
    void setupWidget();

    /**
     * @brief setConnect Connect signal of all slots.
     */
    void setConnect();

    /**
     * @brief elidedText Specifies where the ellipsis should appear when displaying texts that don't fit.
     * @param label Widget
     * @param text Text to elide.
     * @param elide Where the ellipsis should appear at the text.
     * @return Elide text.
     */
    QString elidedText(const SLabel *label, const QString & text, const Qt::TextElideMode elide = Qt::ElideRight);

    void clearList(QList<QWidget *> list);
    void clearButtonGroup(QButtonGroup * buttonGroup, bool deleteButton = false);
    void clearLayout(QLayout * layout, bool deleteWidgets = false);

    /**
     * @brief m_line Enables line view by re-structuring slot.
     */
    bool m_line = false;

    /**
     * @brief m_box Enables box view by re-structuring slot.
     */
    bool m_box = false;

    /**
     * @brief m_banner Enables banner view by re-structuring slot.
     */
    bool m_banner = false;

    /**
     * @brief m_slider Enabléd slider view by re-structuring slot.
     */
    bool m_slider = false;

    /**
     * @brief m_spacer Enables spacer view by re-structuring divider.
     */
    bool m_spacer = false;

    /**
     * @brief m_iter# Counts index for button group.
     */
    int m_iterTopics = 0;
    int m_iterSlots = 0;
    int m_delay = 70;
    int m_space = 2;
    int m_min = 0;
    int m_max = 0;

    bool m_scrollBar = false;

    /**
     * @brief m_list Container for all defined member functions e.g. title or slot.
     */
    QList<QWidget *> m_list;

    /**
     * @brief m_groupTopic Collection of all titles, headers and  banners
     *  for the easy separation.
     */
    QButtonGroup * m_groupTopic = nullptr;

    /**
     * @brief m_groupSlot Collection of all slots and boxes for the easy separation and use of signals.
     */
    QButtonGroup * m_groupSlot = nullptr;

    /**
     * @brief m_layoutList View layout for the item list. Can by updated on the fly.
     */
    QVBoxLayout * m_layoutList = nullptr;
};

#endif // SLIST_H
