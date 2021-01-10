/**
 * @file ssplashscreen.h
 * @brief Splash screen for UI transitions.
 *
 * @note This contains eventually any constants
 * or global variables you will need.
 *
 * If no image path is provided a pixmap in the
 * global background color will be created.
 *
 * @author Alexej Kloos (AKL)
 * @bug No known bugs.
 * @date 15/11/2018
 */

#ifndef SSPLASHSCREEN_H
#define SSPLASHSCREEN_H

#include "../build/SGlobal.h"

#include <QSplashScreen>
#include <QWidget>
#include <QMovie>
#include <QString>

class SIconButton;


/// @brief SSplashScreen inherits from QSplashScreen.
class SSplashScreen : public QSplashScreen
{
    Q_OBJECT

public:
    /// @brief Constructor description.
    ///
    /// @param parent A Qt parent pointer.
    explicit SSplashScreen(QWidget *parent = nullptr);

    /// @brief Constructor description.
    ///
    /// @param parent A Qt parent pointer.
    /// @param image A reference to pixmap.
    explicit SSplashScreen(QWidget *parent, const QPixmap &pixmap);

    /// @brief Constructor description.
    ///
    /// @param parent A Qt parent pointer.
    /// @param image A reference string to image path.
    explicit SSplashScreen(QWidget *parent, const QString &fileName);

    /// @brief A method to clear pixmap. Default pixmap background will be set.
    void clear();

protected:
    /// @brief Method description.
    ///
    /// @param event A Qt QPaintEvent pionter.
    void paintEvent(QPaintEvent* event);

    /// @brief Method description.
    ///
    /// @param painter A Qt QPainter pionter.
    virtual void drawContents(QPainter *painter);

    /**
     * @brief changeEvent
     * @param event
     */
    void changeEvent(QEvent *event);


private slots:
    /// @brief Sets the current pixmap from the played GIF file in QMovie.
    void slotFrameUpdate();

private:
    /// @brief Config inveroment.
    void setupProperty();

    /// @brief Initializes widgets.
    void setupWidget();

    /// @brief Establishes connection between signals and slots.
    void setConnect();

    /**
     * @brief restyleUI
     */
    void restyleUI();

    /// @brief Data member to store image.
    QPixmap m_pixmap;

    /// @brief Data member to render GIFs.
    QMovie m_movie;

    SIconButton * m_icon = nullptr;
};

#endif // SSPLASHSCREEN_H
