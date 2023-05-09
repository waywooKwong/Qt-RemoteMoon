QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    dialog.cpp \
    dialog2.cpp \
    finalplot.cpp \
    help.cpp \
    lightray.cpp \
    main.cpp \
    interface.cpp \
    moon.cpp \
    music.cpp \
    ocean.cpp \
    play.cpp

HEADERS += \
    dialog.h \
    dialog2.h \
    finalplot.h \
    help.h \
    interface.h \
    lightray.h \
    moon.h \
    music.h \
    ocean.h \
    play.h

FORMS += \
    dialog.ui \
    dialog2.ui \
    finalplot.ui \
    help.ui \
    interface.ui \
    lightray.ui \
    moon.ui \
    music.ui \
    ocean.ui \
    play.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    cloud.qrc \
    icon0.qrc \
    moon.qrc \
    music.qrc

DISTFILES += \
    Music/ReflectionEternal.mp3 \
    Music/WishYouWereHere.mp3 \
    Music/thatMoon.mp3
