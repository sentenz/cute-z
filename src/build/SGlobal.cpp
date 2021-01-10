#include "SGlobal.h"

#include <QApplication>
#include <QString>
#include <QColor>
#include <QSize>
#include <QFont>

///
/// \brief System Variables
///

const QString GlobalModule = "Sentenz Controls";
const QString GlobalVersionSW = "0.10";
const QString GlobalVersionHW = "3.00";

///
/// \brief System Defines
///

/// Conf
#ifdef S_EMBEDDED
const bool GlobalDefinesEmbedded = true;
#else
const bool GlobalDefinesEmbedded = false;
#endif
const bool GlobalDefinesCursor = true;

/// Apps
///
/// System
const bool GlobalDefinesEncoder = true;
const bool GlobalDefinesNfc = true;
const bool GlobalDefinesPanel = true;
/// Diagnosis
const bool GlobalDefinesAnalytics = true;
const bool GlobalDefinesAnalyticsDevices = false;
const bool GlobalDefinesAnalyticsInputs = true;
/// Settings
const bool GlobalDefinesSettingsDesign = true;

///
/// \brief GUI Variables
///

//QString GlobalLabelTextFont = "22pt SFNS Display";
QString GlobalLabelTextFont = QFont("Roboto", 20, QFont::Bold).toString();
//QString GlobalFont = "SFNS Display";
QString GlobalFont = "Roboto";
QColor GlobalColorText = QColor(255, 255, 255);
QColor GlobalColorContrast = QColor(38, 40, 38);    //28, 30, 34
//QColor GlobalColorHighlight = QColor(0, 65, 255); 5a57fe
QColor GlobalColorHighlight = QColor("#5a57fe");
QColor GlobalColorBase = QColor(0, 0, 0);
QColor GlobalColorCustomText = QColor(255, 255, 255);
QColor GlobalColorCustomContrast = QColor(38, 40, 38);
QColor GlobalColorCustomHighlight = QColor(0, 65, 255);
QColor GlobalColorCustomBase = QColor(0, 0, 0);

const int GlobalTouchDelay = 100;
const int GlobalAnimationTimeIn = 400;
const int GlobalAnimationTimeOut = 300;
const int GlobalAnimationSlowTimeIn = 600;
const int GlobalAnimationSlowTimeOut = 500;
const int GlobalAnimationFastTimeIn = 300;
const int GlobalAnimationFastTimeOut = 200;

///
/// \brief System Configurations
///
///

//const QSize GlobalWindowSize = QSize(0, 0);
const QSize GlobalWindowSize = QSize(480, 800);
//const QSize GlobalWindowSize = QSize(600, 900);
//const QSize GlobalWindowSize = QSize(1024, 600);
#ifdef __linux__
QString GlobalAppPath = "/etc/sentenz";
#else
// Note: Qt Global starts befor qApp->applicationDirPath() is initia, therefor qApp is empty... Initialize in SMain.cpp
QString GlobalAppPath;
#endif
const QString GlobalConfigPathSettings = "/etc/sentenz/config/settings";
const QString GlobalConfigFileSettings = "/etc/sentenz/config/settings/settings.ini";
const QString GlobalConfigPathLanguage = "/etc/sentenz/config/language";
const QString GlobalConfigFileLanguage = "/etc/sentenz/config/language/language.ini";
const QString GlobalConfigPathDatabase = "/etc/sentenz/config/database";
const QString GlobalConfigPathNeuron = "/etc/sentenz/config/neuron";

///
/// \brief System BUS
///

#ifdef __linux__
QString GlobalBus1Wire = "/sys/bus/w1/devices";
#else
// Note: Qt Global starts befor qApp->applicationDirPath() + "/devices", therefor qApp is empty... Initialize in SMain.cpp
QString GlobalBus1Wire;
#endif
QString GlobalBusI2C;
QString GlobalBusSPI;
QString GlobalBusUART;
