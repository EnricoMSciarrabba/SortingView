QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    algointerface.cpp \
    barchart.cpp \
    bubblesort.cpp \
    customgroupbox.cpp \
    heapsort.cpp \
    insertionsort.cpp \
    main.cpp \
    mainwindow.cpp \
    mergesort.cpp \
    quicksort.cpp \
    selectionsort.cpp

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    algointerface.h \
    barchart.h \
    bubblesort.h \
    customgroupbox.h \
    heapsort.h \
    insertionsort.h \
    mainwindow.h \
    mergesort.h \
    quicksort.h \
    selectionsort.h
