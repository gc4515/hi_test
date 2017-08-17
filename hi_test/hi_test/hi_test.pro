QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = hi_test

TEMPLATE = app

SOURCES += \
    main.cpp \
    logiclayer.cpp

HEADERS += \
    logiclayer.h



INCLUDEPATH += PWD/include
include(../SystemInit/SystemInit.pri) \
include(../ShowForm/ShowForm.pri) \
include(../CSourceCode/CSourceCode.pri) \
include(../Venc2H264/Venc2H264.pri) \
include(../vdec2Vo/vdec2Vo.pri)

INCLUDEPATH += /myhome/Hisiqt/Qt/build_qt/hinclude
LIBS += -L/myhome/Hisiqt/Qt/build_qt/hilib -lmpi -lhdmi -ltde -lanr -laec -ljpeg -lresampler -lVoiceEngine

RESOURCES += \
    Resource/image.qrc



