# Check if the config file exists
! include( ../../common.pri ) {
    error( "Couldn't find the common.pri file!" )
}

TEMPLATE = lib
CONFIG += staticlib

SOURCES += \
    label/SLabel.cpp \
    list/SList.cpp \
    button/SPushButton.cpp \
    button/SToolButton.cpp \
    button/SFabButton.cpp \
    button/SRadioButton.cpp \
    layout/SFlowLayout.cpp \
    layout/SHScrollArea.cpp \
    layout/SVScrollArea.cpp \
    stacked/SAnimatedStackedWidget.cpp \
    effect/SGraphicsGlowEffect.cpp \
    plot/SPlotQwt.cpp \
    slider/SSlider.cpp \
    wheel/SVTumbler.cpp \
    base/SBaseThread.cpp \
    base/SBasePresenter.cpp \
    base/SBaseModel.cpp \
    base/SBaseDialog.cpp \
    switch/SSwitch.cpp \
    tab/STabs.cpp \
    util/SSnackbar.cpp \
    util/SCircularProgress.cpp \
    util/SLinearProgress.cpp \
    button/SCheckBox.cpp \
    button/SRaisedButton.cpp \
    button/SIconButton.cpp

HEADERS += \
    label/SLabel.h \
    button/SPushButton.h \
    button/SToolButton.h \
    button/SFabButton.h \
    button/SRadioButton.h \
    list/SList.h \
    layout/SFlowLayout.h \
    layout/SHScrollArea.h \
    layout/SVScrollArea.h \
    stacked/SAnimatedStackedWidget.h \
    effect/SGraphicsGlowEffect.h \
    plot/SPlotQwt.h \
    button/SRadioButton.h \
    slider/SSlider.h \
    wheel/SVTumbler.h \
    base/SBaseThread.h \
    base/SBasePresenter.h \
    base/SBaseModel.h \
    base/SBaseDialog.h \
    switch/SSwitch.h \
    tab/STabs.h \
    util/SSnackbar.h \
    util/SCircularProgress.h \
    util/SLinearProgress.h \
    button/SCheckBox.h \
    button/SRaisedButton.h \
    button/SIconButton.h

