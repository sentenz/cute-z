#ifndef SODOMETER_H
#define SODOMETER_H

#include <QDialog>
#include <QVector>
#include <vector>

#include <IIR>
#include <Spectrum>

#ifndef M_PI
#define M_PI (3.14159265358979323846)
#endif

class STouchDialogAccept;

class QSettings;
class QFileSystemWatcher;


using namespace Sentenz;

class SOdometer : public QDialog
{
    Q_OBJECT

public:
    explicit SOdometer(QWidget *parent = 0);
    ~SOdometer();

    bool initOdometer();
    void reset();

    double getRawValue();
    double getFilterValue();
    bool getPulseValue(double &pulse);
    bool getHilbertValue(double &dist);
    bool getValue(double &value);

    #ifdef S_LOGGER
    double &getWave();
    double &getPhase();
    double &getUnwrap();
    void setUnwrap(const double &value);
    #endif

signals:
    void start();
    void stop();

public slots:
    bool isStatus();

private slots:
    void slotReadSettings();

private:
    void setupWidget();
    void setConnect();
    bool readFile();
    bool writeFile();
    void initParameter(const double &value);

    bool pos = true;
    bool neg = true;
    double prev = 0.0;
    double value = 0.0;
    double angle = 0.0;
    std::vector<double> data;
    std::vector<double> dataFilt;
    std::vector<double> dataHilb;
    std::vector<double> vphase;

    #ifdef S_UNUSED
    VertX13 *magnet = nullptr;
    #endif
    Butterworth *butterworth = nullptr;
    Hilbert *hilbert = nullptr;
    STouchDialogAccept *touchDialogAccept = nullptr;

    /// settings
    QSettings *settings = nullptr;
    QFileSystemWatcher *fileSystemWatcher = nullptr;

    /// Odometer
    double resolution = 0.0;
    double diameter = 0.0;
    double threshold = 0.0;
    int samplerate = 0;

    /// Butterworth
    int filterOrder = 0;
    double filterCutFreqC = 0.0;
    double filterCutFreq1 = 0.0;
    double filterCutFreq2 = 0.0;
    QString filterType = "";

    /// Procedure
    QString procedure = "";

    #ifdef S_LOGGER
    double unwrap = 0.0;
    #endif
};

#endif /// SODOMETER_H
