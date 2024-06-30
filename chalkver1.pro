QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    alterstudialog.cpp \
    course.cpp \
    deletecourdialog.cpp \
    deletstudialog.cpp \
    deselect.cpp \
    inputcourdialog.cpp \
    inputstudialog.cpp \
    lookupcourdialog.cpp \
    lookupstudialog.cpp \
    main.cpp \
    mainwindow.cpp \
    menu.cpp \
    modifycourdialog.cpp \
    select.cpp \
    stu.cpp \
    student.cpp \
    studialog.cpp \
    stufuncdialog.cpp \
    teadialog.cpp \
    teafuncdialog.cpp

HEADERS += \
    alterstudialog.h \
    course.h \
    deletecourdialog.h \
    deletstudialog.h \
    deselect.h \
    inputcourdialog.h \
    inputstudialog.h \
    lookupcourdialog.h \
    lookupstudialog.h \
    mainwindow.h \
    menu.h \
    modifycourdialog.h \
    select.h \
    stu.h \
    student.h \
    studialog.h \
    stufuncdialog.h \
    teadialog.h \
    teafuncdialog.h

FORMS += \
    alterstudialog.ui \
    deletecourdialog.ui \
    deletstudialog.ui \
    inputcourdialog.ui \
    inputstudialog.ui \
    lookupcourdialog.ui \
    lookupstudialog.ui \
    mainwindow.ui \
    modifycourdialog.ui \
    studialog.ui \
    stufuncdialog.ui \
    teadialog.ui \
    teafuncdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
