#ifndef SLOADKEYBOARD_H
#define SLOADKEYBOARD_H

#include <QQmlApplicationEngine>


class SLoadKeyboard
{
public:
     SLoadKeyboard();

     void load();

private:
     QQmlApplicationEngine engine;
};

#endif // SLOADKEYBOARD_H
