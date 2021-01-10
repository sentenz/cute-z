#ifndef SGLOBAL_H
#define SGLOBAL_H

class QColor;
class QString;
class QSize;

///
/// \brief Device Variables
///

extern const QString GlobalModule;
extern const QString GlobalVersionSW;
extern const QString GlobalVersionHW;

///
/// \brief System Defines
///

/// Conf
extern const bool GlobalDefinesEmbedded;
extern const bool GlobalDefinesCursor;

/// Apps
extern const bool GlobalDefinesNfc;
extern const bool GlobalDefinesEncoder;
extern const bool GlobalDefinesPanel;
extern const bool GlobalDefinesAnalytics;
extern const bool GlobalDefinesAnalyticsDevices;
extern const bool GlobalDefinesAnalyticsInputs;
extern const bool GlobalDefinesSettingsDesign;

///
/// \brief GUI Variables
///

extern QString GlobalLabelTextFont;
extern QString GlobalFont;
extern QColor GlobalColorText;
extern QColor GlobalColorContrast;
extern QColor GlobalColorHighlight;
extern QColor GlobalColorBase;
extern QColor GlobalColorCustomText;
extern QColor GlobalColorCustomContrast;
extern QColor GlobalColorCustomHighlight;
extern QColor GlobalColorCustomBase;
extern const int GlobalTouchDelay;
extern const int GlobalAnimationTimeIn;
extern const int GlobalAnimationTimeOut;
extern const int GlobalAnimationSlowTimeIn;
extern const int GlobalAnimationSlowTimeOut;
extern const int GlobalAnimationFastTimeIn;
extern const int GlobalAnimationFastTimeOut;

///
/// \brief System Configurations
///

extern const QSize GlobalWindowSize;
extern QString GlobalAppPath;
extern const QString GlobalConfigPathSettings;
extern const QString GlobalConfigFileSettings;
extern const QString GlobalConfigPathLanguage;
extern const QString GlobalConfigFileLanguage;
extern const QString GlobalConfigPathDatabase;
extern const QString GlobalConfigPathNeuron;

///
/// \brief System BUS
///

extern QString GlobalBus1Wire;
extern QString GlobalBusI2C;
extern QString GlobalBusSPI;
extern QString GlobalBusUART;

#endif /// SGLOBAL_H
