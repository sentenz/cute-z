#include "SLoadKeyboard.h"
#include <SBackendKeyboard.h>

SLoadKeyboard::SLoadKeyboard()
{
    Q_INIT_RESOURCE(qml);

    qmlRegisterType<SBackendKeyboard>("s.keyboard.backend", 1, 0, "SBackendKeyboard");
}

void SLoadKeyboard::load()
{
    //engine.load(QUrl::fromLocalFile("STouchCanvas.qml"));
    engine.load(QUrl(QStringLiteral("qrc:/STouchCanvas.qml")));
//    QObject *object = engine.rootObjects().first();
//    object->setProperty("labelTitle.text", "Keyboard");
}
