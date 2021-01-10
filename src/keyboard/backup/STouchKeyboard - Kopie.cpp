#include "STouchKeyboard.h"
#include "../effect/SGraphicsGlowEffect.h"

#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QString>
#include <QChar>
#include <QTimer>
#include <QDebug>

STouchKeyboard::STouchKeyboard(QWidget *parent) : QDialog(parent)
{
    this->setUpGUI();
    this->setConnect();


#ifndef QT_NO_EMBEDDED
    QApplication::setOverrideCursor(Qt::BlankCursor);
    this->setWindowState(Qt::WindowFullScreen);
#else
    this->resize(QSize(800,480));
#endif
    this->setStyleSheet("background-color: rgb(42,40,38);");
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
}

void STouchKeyboard::setUpGUI()
{
    /// Labels
    labelTitle = new QLabel(this);
    labelTitle->setAlignment(Qt::AlignCenter);
    labelTitle->setStyleSheet("QLabel { font: 20pt; font-weight: bold; color: gainsboro; background: transparent; }");

    labelNumbers = new QLabel(this);
    labelNumbers->setAlignment(Qt::AlignCenter);
    labelNumbers->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    labelNumbers->setStyleSheet("QLabel { font: 30pt; color: lightgray; background: transparent; }");


    /// Style
    double diameter = 80.;
    int space = 5;
    double f = 1.5;

    QString styleButtonRect
    (" \
        QPushButton:!pressed { font: 18pt; color: gainsboro; background-color: transparent; border: none; } \
        QPushButton:pressed  { font: 18pt; color: gainsboro; background-color: transparent; border: none; } \
        QPushButton:disabled { font: 18pt; color: gray; background-color: transparent; border: none; } \
    ");

    styleButton = formStyleSheetString();

    /// Buttons
    buttonZero = new QPushButton(tr("0"), this);
    buttonZero->setFixedSize(QSize(f*diameter,diameter));
    buttonZero->setCheckable(true);
    buttonZero->setStyleSheet(styleButton);
    SGraphicsGlowEffect *glow_0 = new SGraphicsGlowEffect;
    glow_0->setBlurRadius(0);
    glow_0->setStrength(1);
    buttonZero->setGraphicsEffect(glow_0);

    buttonOne = new QPushButton(tr("1"), this);
    buttonOne->setFixedSize(QSize(f*diameter,diameter));
    buttonOne->setCheckable(true);
    buttonOne->setStyleSheet(styleButton);
    SGraphicsGlowEffect *glow_1 = new SGraphicsGlowEffect;
    glow_1->setBlurRadius(0);
    glow_1->setStrength(1);
    buttonOne->setGraphicsEffect(glow_1);

    buttonTwo = new QPushButton(tr("2"), this);
    buttonTwo->setFixedSize(QSize(f*diameter,diameter));
    buttonTwo->setCheckable(true);
    buttonTwo->setStyleSheet(styleButton);
    SGraphicsGlowEffect *glow_2 = new SGraphicsGlowEffect;
    glow_2->setBlurRadius(0);
    glow_2->setStrength(1);
    buttonTwo->setGraphicsEffect(glow_2);

    buttonThree = new QPushButton(tr("3"), this);
    buttonThree->setFixedSize(QSize(f*diameter,diameter));
    buttonThree->setCheckable(true);
    buttonThree->setStyleSheet(styleButton);
    SGraphicsGlowEffect *glow_3 = new SGraphicsGlowEffect;
    glow_3->setBlurRadius(0);
    glow_3->setStrength(1);
    buttonThree->setGraphicsEffect(glow_3);

    buttonFour = new QPushButton(tr("4"), this);
    buttonFour->setFixedSize(QSize(f*diameter,diameter));
    buttonFour->setCheckable(true);
    buttonFour->setStyleSheet(styleButton);
    SGraphicsGlowEffect *glow_4 = new SGraphicsGlowEffect;
    glow_4->setBlurRadius(0);
    glow_4->setStrength(1);
    buttonFour->setGraphicsEffect(glow_4);

    buttonFive = new QPushButton(tr("5"), this);
    buttonFive->setFixedSize(QSize(f*diameter,diameter));
    buttonFive->setCheckable(true);
    buttonFive->setStyleSheet(styleButton);
    SGraphicsGlowEffect *glow_5 = new SGraphicsGlowEffect;
    glow_5->setBlurRadius(0);
    glow_5->setStrength(1);
    buttonFive->setGraphicsEffect(glow_5);

    buttonSix = new QPushButton(tr("6"), this);
    buttonSix->setFixedSize(QSize(f*diameter,diameter));
    buttonSix->setCheckable(true);
    buttonSix->setStyleSheet(styleButton);
    SGraphicsGlowEffect *glow_6 = new SGraphicsGlowEffect;
    glow_6->setBlurRadius(0);
    glow_6->setStrength(1);
    buttonSix->setGraphicsEffect(glow_6);

    buttonSeven = new QPushButton(tr("7"), this);
    buttonSeven->setFixedSize(QSize(f*diameter,diameter));
    buttonSeven->setCheckable(true);
    buttonSeven->setStyleSheet(styleButton);
    SGraphicsGlowEffect *glow_7 = new SGraphicsGlowEffect;
    glow_7->setBlurRadius(0);
    glow_7->setStrength(1);
    buttonSeven->setGraphicsEffect(glow_7);

    buttonEight = new QPushButton(tr("8"), this);
    buttonEight->setFixedSize(QSize(f*diameter,diameter));
    buttonEight->setCheckable(true);
    buttonEight->setStyleSheet(styleButton);
    SGraphicsGlowEffect *glow_8 = new SGraphicsGlowEffect;
    glow_8->setBlurRadius(0);
    glow_8->setStrength(1);
    buttonEight->setGraphicsEffect(glow_8);

    buttonNine = new QPushButton(tr("9"), this);
    buttonNine->setFixedSize(QSize(f*diameter,diameter));
    buttonNine->setCheckable(true);
    buttonNine->setStyleSheet(styleButton);
    SGraphicsGlowEffect *glow_9 = new SGraphicsGlowEffect;
    glow_9->setBlurRadius(0);
    glow_9->setStrength(1);
    buttonNine->setGraphicsEffect(glow_9);

    buttonDelete = new QPushButton(tr("Cancel"), this);
    buttonDelete->setCheckable(true);
    buttonDelete->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    buttonDelete->setStyleSheet(styleButtonRect);

    buttonAccept = new QPushButton(tr("Accept"), this);
    buttonAccept->setCheckable(true);
    buttonAccept->setDisabled(true);
    buttonAccept->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    buttonAccept->setStyleSheet(styleButtonRect);

    buttonMinus = new QPushButton(tr("-"), this);
    buttonMinus->setCheckable(true);
    buttonMinus->setHidden(true);
    buttonMinus->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    buttonMinus->setStyleSheet(formStyleSheetString("transparent"));

    buttonDot = new QPushButton(tr("."), this);
    buttonDot->setCheckable(true);
    buttonDot->setHidden(true);
    buttonDot->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    buttonDot->setStyleSheet(formStyleSheetString("transparent"));


    /// Layout
    QVBoxLayout *layout_0 = new QVBoxLayout;
    layout_0->addWidget(labelTitle);
    layout_0->addSpacing(height()/20);
    layout_0->addWidget(labelNumbers);
    layout_0->setContentsMargins(0,0,0,height()/20);

    QHBoxLayout *layout_1 = new QHBoxLayout;
    layout_1->addStretch();
    layout_1->addWidget(buttonOne);
    layout_1->addSpacing(space);
    layout_1->addWidget(buttonTwo);
    layout_1->addSpacing(space);
    layout_1->addWidget(buttonThree);
    layout_1->addSpacing(space);
    layout_1->addWidget(buttonFour);
    layout_1->addStretch();

    QHBoxLayout *layout_2 = new QHBoxLayout;
    layout_2->addStretch();
    layout_2->addWidget(buttonFive);
    layout_2->addSpacing(space);
    layout_2->addWidget(buttonSix);
    layout_2->addSpacing(space);
    layout_2->addWidget(buttonSeven);
    layout_2->addSpacing(space);
    layout_2->addWidget(buttonEight);
    layout_2->addStretch();

    QHBoxLayout *layout_3 = new QHBoxLayout;
    layout_3->addWidget(buttonDelete);
    //layout_3->addStretch();
    layout_3->addSpacing(space);
    layout_3->addWidget(buttonMinus);
    layout_3->addSpacing(space);
    layout_3->addWidget(buttonZero);
    layout_3->addSpacing(space);
    layout_3->addWidget(buttonNine);
    layout_3->addSpacing(space);
    layout_3->addWidget(buttonDot);
    layout_3->addSpacing(space);
    //layout_3->addStretch();
    layout_3->addWidget(buttonAccept);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addStretch();
    mainLayout->addLayout(layout_0);
    mainLayout->addStretch();
    mainLayout->addLayout(layout_1);
    mainLayout->addSpacing(space);
    mainLayout->addLayout(layout_2);
    mainLayout->addSpacing(space);
    mainLayout->addLayout(layout_3);
    mainLayout->addSpacing(space);


    setLayout(mainLayout);
}

void STouchKeyboard::setConnect()
{
    QList<QPushButton *> buttons = this->findChildren<QPushButton *>();
    for (int i = 0; i < buttons.size(); ++i)
    {
        connect(buttons.at(i), &QPushButton::pressed, this, &STouchKeyboard::slotGetNumber);
    }
}

void STouchKeyboard::slotGetNumber()
{
    ///
    /// \brief pb: casting which butten is pressed
    ///
    QPushButton *pb = qobject_cast<QPushButton *>(sender());
    if(pb)
    {
        /// cancel characters
        if (!pb->text().compare(tr("Cancel")))
        {
            accepted = false;
            this->close();
        }
        /// delete characters
        else if (!pb->text().compare(tr("Delete")))
        {
             currentNumbers.remove(currentNumbers.length()-1, 1);
        }

        /// accept characters
        else if (!pb->text().compare(tr("Accept")))
        {
            if(!currentNumbers.isEmpty())
            {
                emit signalNumbersChanged(convertToMetric(currentNumbers));
                lastNumbers = convertToMetric(currentNumbers);
                currentNumbers.clear();
                accepted = true;
                this->close();
            }
        }
        /// add characters
        else
        {
            if (currentNumbers.length() < digits)
            {
                currentNumbers.push_back(pb->text());
            }
        }

        /// swap delete/cancel
        if(!currentNumbers.isEmpty() && !buttonDelete->text().compare(tr("Cancel")))
        {
            buttonDelete->setText(tr("Delete"));
            buttonAccept->setDisabled(false);
        }
        else if(currentNumbers.isEmpty() && !buttonDelete->text().compare(tr("Delete")))
        {
            buttonDelete->setText(tr("Cancel"));
            buttonAccept->setDisabled(true);
        }

        if (password && currentNumbers.size() == digits)
        {
            buttonAccept->setDisabled(false);
        }
        else if (password && currentNumbers.size() < digits)
        {
            buttonAccept->setDisabled(true);
        }
    }

    ///
    /// \brief labelNumbers: visual Numbers
    ///
    //labelNumbers->setStyleSheet("QLabel { font: 30pt; color: lightgray; background: transparent; }");
    if (password)
    {
        labelNumbers->setText(QString(currentNumbers.length(), QChar(0x26AB)).append(QString(digits - currentNumbers.length(), QChar(0x26AA))));
    }
    else
    {
        labelNumbers->setText(convertToMetric(currentNumbers));
    }
}

QString STouchKeyboard::convertToMetric(QString text)
{

    switch(metric)
    {
    case 'm':
    {
        if (text.length() < 3 && !text.isEmpty())
        {
            text.insert(1-text.length(),"0").prepend("0.");
        }
        else if (text.length() > 2 && !text.isEmpty())
        {
            text.insert(text.length()-2,".");
        }

        return text;
    }
        break;
    case 'f':
    {
        return QString("%1").arg(text, 3, QChar('0')).prepend("0.");
    }
        break;
    default:
    {
        return text;
    }
        break;
    }
}

void STouchKeyboard::setTitle(const QString text)
{
    labelTitle->setText(text);
}

void STouchKeyboard::setPassword(const bool on = false)
{
    this->password = on;
    labelNumbers->setStyleSheet("QLabel { font: bold 30pt; color: lightgray; background: transparent; }");
    labelNumbers->setText(QString(digits, QChar(0x26AA)));
    update();
}

void STouchKeyboard::setMaximumDigit(const int digits)
{
    if (digits > maxDigits)
    {
        this->digits = maxDigits;
    }
    else
    {
        this->digits = digits;
    }
    update();
}

void STouchKeyboard::setMetric(const char *metric)
{
    this->metric = *metric;
    update();
}

bool STouchKeyboard::isAccepted()
{
    return accepted;
}

QString STouchKeyboard::getNumber()
{
    return lastNumbers;
}

void STouchKeyboard::setButtonStyle(const QString style)
{
    this->styleButton = formStyleSheetString(style);

    QList<QPushButton *> buttons = this->findChildren<QPushButton *>();
    for (int i = 0; i < buttons.size(); ++i)
    {
        if (buttons.at(i)->text().size() == 1 )
        {
            buttons.at(i)->setStyleSheet(styleButton);
        }
    }

    update();
}

void STouchKeyboard::enableButtons(const bool on)
{
    buttonMinus->setHidden(!on);
    buttonDot->setHidden(!on);
}

QString STouchKeyboard::formStyleSheetString(const QString style)
{
    QString styleButton;

    if (!style.compare("transparent"))
    {
        styleButton =
        " \
            QPushButton:!pressed { font: 25pt; font-family: Arial; color: gainsboro; background: transparent; border: 2px solid gray; } \
            QPushButton:pressed  { font: 25pt; font-family: Arial; color: gainsboro; background-color: gray; border: none; } \
        ";
    }
    else if (!style.compare("rect"))
    {
        styleButton =
        " \
            QPushButton:!pressed { font: 25pt; font-family: Arial; color: gainsboro; background-color: rgba(255,255,255,40); border: none; } \
            QPushButton:pressed { font: 25pt; font-family: Arial; color: gainsboro; background-color: rgba(255,255,255,100); border: none; } \
        ";
    }

    return styleButton;
}

void STouchKeyboard::retranslateUI()
{
    buttonDelete->setText(tr("Cancel"));
    buttonAccept->setText(tr("Accept"));
}

void STouchKeyboard::changeEvent(QEvent* event)
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
