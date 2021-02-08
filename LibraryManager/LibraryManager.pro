QT       += core gui
QT       += sql

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
    base64.cpp \
    filemanager.cpp \
    login.cpp \
    main.cpp \
    manager.cpp \
    md5.cpp \
    menubar.cpp \
    personalcenter.cpp \
    reader.cpp \
    registered.cpp \
    resetpassword.cpp \
    sqltablemodel.cpp \
    stackroom.cpp \
    timemanager.cpp \
    widget.cpp

HEADERS += \
    base64.h \
    filemanager.h \
    librarydefine.h \
    login.h \
    manager.h \
    md5.h \
    menubar.h \
    personalcenter.h \
    reader.h \
    registered.h \
    resetpassword.h \
    sqltablemodel.h \
    stackroom.h \
    timemanager.h \
    widget.h

FORMS += \
    login.ui \
    manager.ui \
    menubar.ui \
    personalcenter.ui \
    reader.ui \
    registered.ui \
    resetpassword.ui \
    stackroom.ui \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
