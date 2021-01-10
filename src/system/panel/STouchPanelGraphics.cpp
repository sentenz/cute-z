#include "STouchPanelGraphics.h"
#include "../build/SGlobal.h"
#include "../device/SEngine.h"
#include "../widget/effect/SGraphicsGlowEffect.h"
#include "../widget/button/SToolButton.h"

#include <QApplication>
#include <QPropertyAnimation>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QDebug>


STouchPanelGraphics::STouchPanelGraphics(QWidget *parent) : QDialog(parent)
{
    this->resize(::GlobalWindowSize);
    this->setStyleSheet("background-color: " + ::GlobalColorBase.name() + ";");
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    this->setFocusPolicy(Qt::StrongFocus);
    this->setMouseTracking(true);

    this->setupWidget();
    this->setupGUI();
}

STouchPanelGraphics::~STouchPanelGraphics()
{
    /*
    if (this->layout != nullptr)
    {
        delete this->layout;
        this->layout = nullptr;
    }
    */
    if (this->engine != nullptr)
    {
        delete this->engine;
        this->engine = nullptr;
    }
    this->slotRemoveAllButtons();
}

void STouchPanelGraphics::setupWidget()
{
    /// SEngine
    this->engine = new SEngine(BUS::GPIO);
}

void STouchPanelGraphics::setupGUI()
{
    this->layout = new QGridLayout(this);

    setLayout(this->layout);
}

void STouchPanelGraphics::setConnect(SToolButton * button)
{
    connect(button, &SToolButton::pressed, this, &STouchPanelGraphics::slotButtonPressed);
    connect(button, &SToolButton::released, this, &STouchPanelGraphics::slotButtonReleased);
    connect(button, &SToolButton::toggled, this, &STouchPanelGraphics::slotButtonToggled);
}

void STouchPanelGraphics::disConnect(SToolButton * button)
{
    disconnect(button, &SToolButton::pressed, this, &STouchPanelGraphics::slotButtonPressed);
    disconnect(button, &SToolButton::released, this, &STouchPanelGraphics::slotButtonReleased);
    disconnect(button, &SToolButton::toggled, this, &STouchPanelGraphics::slotButtonToggled);
}

void STouchPanelGraphics::slotAddButton()
{
    /// Button
    ///
    SToolButton *button = new SToolButton(this);
    button->setText(QString::number(this->list.size()));
    //button->setIcon(QIcon(QPixmap(":/images/arrow_up_1.svg")));
    //button->setIconSize(QSize(40,40));
    //button->setFixedSize(310,70);
    button->setCheckable(false);
    button->setAutoExclusive(true);
    button->setPopupMode(SToolButton::InstantPopup);
    button->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    SGraphicsGlowEffect *glow = new SGraphicsGlowEffect;
    glow->setColor(::GlobalColorText);
    glow->setBlurRadius(1);
    glow->setStrength(1);
    button->setGraphicsEffect(glow);
    /// List
    this->list.append(button);
    /// Layout
    this->layout->addWidget(button);
    this->slotArrangeButton();

    this->setConnect(button);
}

void STouchPanelGraphics::slotRemoveButton()
{
    if (!this->list.isEmpty())
    {
        SToolButton *button = this->list.last();
        this->disConnect(button);
        this->list.removeOne(button);
        delete button;
        button = nullptr;

        this->slotArrangeButton();
    }
}

void STouchPanelGraphics::slotRemoveAllButtons()
{
    foreach (SToolButton *button, this->list)
    {
        this->disConnect(button);
        this->list.removeOne(button);
        delete button;
        button = nullptr;
    }
}

void STouchPanelGraphics::slotArrangeButton()
{
    /// Animation
    ///
    /*
    QPropertyAnimation *animation = new QPropertyAnimation(this, "alpha", this);
    animation->setDuration(1000);
    animation->setKeyValueAt(0, 255);
    animation->setKeyValueAt(0.5, 100);
    animation->setKeyValueAt(1, 255);
    animation->start(QPropertyAnimation::DeleteWhenStopped);
    */

    if (!this->list.isEmpty())
    {
        /// Arrange Margins
        ///
        this->layout->setContentsMargins(20, 110/4, 20, 110/4);
        this->layout->setSpacing(70/2);

        if (this->layout->count() < 4)
        {
            this->layout->setContentsMargins(20, 110/1, 20, 110/1);
            this->layout->setSpacing(70/2);
        }
        else if (this->layout->count() > 8)
        {
            this->layout->setContentsMargins(20, 110/8, 20, 110/8);
            this->layout->setSpacing(70/6);
        }

        /// Arrange Widgets
        ///
        int row = 0;
        int col = 0;

        if (this->layout->count() < 4)
        {
            for (int i = 0; i < this->layout->count(); ++i)
            {
                if (this->layout->count() == 2)
                {
                    this->layout->removeWidget(this->list.at(i));
                    this->layout->addWidget(this->list.at(i), ++row, col);
                    this->layout->setContentsMargins(20, 110/2, 20, 110/2);
                }
                else
                {
                    this->layout->removeWidget(this->list.at(i));
                    this->layout->addWidget(this->list.at(i), row, ++col);
                }
            }
        }
        else if (this->layout->count() < 9)
        {
            for (int i = 0; i < this->layout->count(); ++i)
            {
                this->layout->removeWidget(this->list.at(i));
                if (i%2 == 0)
                {
                    this->layout->addWidget(this->list.at(i), row, col);
                }
                else
                {
                    this->layout->addWidget(this->list.at(i), ++row, col++);
                    row = 0;
                }
            }
        }
        else
        {
            for (int i = 0; i < this->layout->count(); ++i)
            {
                this->layout->removeWidget(this->list.at(i));
                if (i%2 == 0)
                {
                    this->layout->addWidget(this->list.at(i), row, col++);
                }
                else if (col == 1)
                {
                    this->layout->addWidget(this->list.at(i), row, col++);
                }
                else
                {
                    this->layout->addWidget(this->list.at(i), row++, col);
                    col = 0;
                }
            }
        }
    }
}

void STouchPanelGraphics::slotButtonPressed()
{
    qDebug() << "Pressed" << this->getButton();

    this->engine->forward(Engine::EMotor);
}

void STouchPanelGraphics::slotButtonReleased()
{
    qDebug() << "Released" << this->getButton();

    this->engine->neutral(Engine::EMotor);
}

void STouchPanelGraphics::slotButtonToggled()
{
    this->engine->neutral(Engine::EMotor);
}

int STouchPanelGraphics::getButton()
{
    SToolButton *button = qobject_cast<SToolButton *>(sender());
    return button->text().toInt();
}

/*
bool STouchPanelGraphics::event(QEvent *event)
{
    //qDebug() << "Event" << event->type();

    switch (event->type())
    {
    case QEvent::Leave:
        {
            foreach (SToolButton *button, this->list)
            {
                if (!button->isCheckable() && button->isDown())
                {
                    //qDebug() << "Released Event" << button->text();

                    button->released();
                    //button->animateClick(1000);
                }
            }
        }
            break;
        default:
            break;
    }

    return true;
}
*/

void STouchPanelGraphics::retranslateUI()
{
}

void STouchPanelGraphics::changeEvent(QEvent* event)
{
    switch(event->type())
    {
        case QEvent::LanguageChange:
            retranslateUI();
            break;
        case QEvent::LocaleChange:
            break;
        default:
            break;
    }

    QWidget::changeEvent(event);
}
