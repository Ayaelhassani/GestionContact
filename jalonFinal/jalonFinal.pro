QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    aff.cpp \
    ajouinteraction.cpp \
    ajoutcontact.cpp \
    ajouttache.cpp \
    basedonne1.cpp \
    contact.cpp \
    formulaire.cpp \
    gestioncontact.cpp \
    gestioninteraction.cpp \
    gestiontache.cpp \
    interaction.cpp \
    main.cpp \
    mainwindow.cpp \
    modif.cpp \
    rechercher.cpp \
    tache.cpp

HEADERS += \
    aff.h \
    ajouinteraction.h \
    ajoutcontact.h \
    ajouttache.h \
    basedonne1.h \
    contact.h \
    formulaire.h \
    gestioncontact.h \
    gestioninteraction.h \
    gestiontache.h \
    interaction.h \
    mainwindow.h \
    modif.h \
    rechercher.h \
    tache.h

FORMS += \
    aff.ui \
    ajouinteraction.ui \
    ajoutcontact.ui \
    ajouttache.ui \
    formulaire.ui \
    mainwindow.ui \
    modif.ui \
    rechercher.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
