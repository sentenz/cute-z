#ifndef SMAIN_H
#define SMAIN_H

#include <QWidget>

class SSplashScreen;
class SCentral;

class SMain : public QWidget
{
    Q_OBJECT

public:
    explicit SMain(QWidget *parent = nullptr);
    ~SMain();

private:
    void setGlobalVariables();
    void setupWidget();
    void setConnect();
    void setProcess();

    SSplashScreen *splash = nullptr;
    SCentral *central = nullptr;
};

#endif // SMAIN_H
