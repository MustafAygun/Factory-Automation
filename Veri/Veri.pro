QT -= gui

TEMPLATE = lib
DEFINES += VERI_LIBRARY

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
    VeriSiniflari/calisan.cpp \
    VeriSiniflari/temelverisinifi.cpp \
    VeriSiniflari/uretim.cpp \
    VeriSiniflari/urun.cpp \
    VeriSiniflari/vardiya.cpp \
    VeriYonetim/calisanveriyoneticisi.cpp \
    VeriYonetim/uretimveriyoneticisi.cpp \
    VeriYonetim/urunveriyoneticisi.cpp \
    VeriYonetim/vardiyaveriyoneticisi.cpp \
    veri.cpp \
    veritabani.cpp

HEADERS += \
    VeriSiniflari/calisan.h \
    VeriSiniflari/temelverisinifi.h \
    VeriSiniflari/uretim.h \
    VeriSiniflari/urun.h \
    VeriSiniflari/vardiya.h \
    VeriYonetim/calisanveriyoneticisi.h \
    VeriYonetim/temelveriyonetimsinifi.h \
    VeriYonetim/uretimveriyoneticisi.h \
    VeriYonetim/urunveriyoneticisi.h \
    VeriYonetim/vardiyaveriyoneticisi.h \
    Veri_global.h \
    veri.h \
    veritabani.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
