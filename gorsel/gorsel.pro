QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Formlar/VeriGiris/calisanekle.cpp \
    Formlar/VeriGiris/uretimekle.cpp \
    Formlar/VeriGiris/urunekle.cpp \
    Formlar/VeriGiris/vardiyaekle.cpp \
    main.cpp \
    mainwindow.cpp \
    uretimbilgileri.cpp

HEADERS += \
    Formlar/VeriGiris/calisanekle.h \
    Formlar/VeriGiris/uretimekle.h \
    Formlar/VeriGiris/urunekle.h \
    Formlar/VeriGiris/vardiyaekle.h \
    mainwindow.h \
    uretimbilgileri.h

FORMS += \
    Formlar/VeriGiris/calisanekle.ui \
    Formlar/VeriGiris/uretimekle.ui \
    Formlar/VeriGiris/urunekle.ui \
    Formlar/VeriGiris/vardiyaekle.ui \
    mainwindow.ui \
    uretimbilgileri.ui

TRANSLATIONS += \
    gorsel_en_US.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Kaynaklar.qrc

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Veri/release/ -lVeri
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Veri/debug/ -lVeri
else:unix: LIBS += -L$$OUT_PWD/../Veri/ -lVeri

INCLUDEPATH += $$PWD/../Veri
DEPENDPATH += $$PWD/../Veri
