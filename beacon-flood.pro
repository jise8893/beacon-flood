QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
LIBS +=-lpcap
SOURCES += \
        beacon.cpp \
        mac.cpp \
        main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    beacon.h \
    dot11_frame.h \
    dstag.h \
    frame_control.h \
    information.h \
    mac.h \
    radiotap_header.h \
    rsn.h \
    supported.h \
    tagged_param.h \
    wireless.h
