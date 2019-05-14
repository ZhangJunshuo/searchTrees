#-------------------------------------------------
#
# Project created by QtCreator 2019-05-13T15:51:54
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = myFirstWidgetProject
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        avltreepage.cpp \
        indexsearchtreepage.cpp \
        main.cpp \
        rbtreepage.cpp \
        secondpage.cpp \
        treaptreepage.cpp \
        widget.cpp

HEADERS += \
        avltreepage.h \
        balancedSearchTree_AVL.h \
        balancedSearchTree_RB.h \
        balancedSearchTree_Treap.h \
        indexSearchTree.h \
        indexsearchtreepage.h \
        rbtreepage.h \
        searchTreeWithoutLeftSize.h \
        secondpage.h \
        treaptreepage.h \
        widget.h

FORMS += \
        avltreepage.ui \
        indexsearchtreepage.ui \
        rbtreepage.ui \
        secondpage.ui \
        treaptreepage.ui \
        widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Treap.jpg
