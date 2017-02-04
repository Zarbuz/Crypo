SOURCES += \
    src/main.cpp \
    src/FenPrincipale.cpp \
    src/Conversions.cpp \
    src/Encryptions.cpp \
    src/Hashes.cpp \
    src/FenHistorique.cpp
CONFIG += crypto

HEADERS += \
    src/FenPrincipale.h \
    src/FenHistorique.h \
    src/Conversions.h \
    src/Encryptions.h \
    src/Hashes.h

FORMS +=


LIBS += -L$$QCAPATH/lib -lqca2
LIBS += -L C:\Qt\2009.02\qt\lib\ -lcryptopp
INCLUDEPATH += QTDIR\include\cryptopp



