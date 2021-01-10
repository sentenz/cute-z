#include <QApplication>
#include <QTranslator>
#include <QLocale>
#include <QFontDatabase>

#include "SMain.h"


int main(int argc, char *argv[])
{
    Q_INIT_RESOURCE(resources);
    Q_INIT_RESOURCE(images);

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QApplication app(argc, argv);

    QFontDatabase::addApplicationFont(":/fonts/roboto_regular");
    QFontDatabase::addApplicationFont(":/fonts/roboto_medium");
    QFontDatabase::addApplicationFont(":/fonts/roboto_bold");

//    QFontDatabase::addApplicationFont(":/fonts/san-francisco/System San Francisco Display Bold.ttf");
//    QFontDatabase::addApplicationFont(":/fonts/san-francisco/System San Francisco Display Regular.ttf");
//    QFontDatabase::addApplicationFont(":/fonts/san-francisco/System San Francisco Display Thin.ttf");
//    QFontDatabase::addApplicationFont(":/fonts/san-francisco/System San Francisco Display Ultralight.ttf");
//    app.setFont(QFont("SFNS Display"));

    SMain smain;

    return app.exec();
}
