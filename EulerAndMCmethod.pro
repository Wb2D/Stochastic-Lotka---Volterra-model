QT += gui

CONFIG += c++11 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

HEADERS += \
    DataWorker/dataworker.h \
    Equation/LotkaVolterraEquation.h \
    Equation/equation.h \
    Methods/method.h \
    Methods/methodemc.h \
    Methods/methodmilstein.h \
    Methods/methodrk4.h

SOURCES += \
        DataWorker/dataworker.cpp \
        Methods/methodemc.cpp \
        Methods/methodmilstein.cpp \
        Methods/methodrk4.cpp \
        main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
