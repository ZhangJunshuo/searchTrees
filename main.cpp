#include "widget.h"
#include "secondpage.h"
#include "avltreepage.h"
#include "rbtreepage.h"
#include "treaptreepage.h"
#include "indexsearchtreepage.h"
#include <QApplication>
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    secondPage zjs;
    AVLTreePage AVLzjs;
    RBTreePage RBzjs;
    TreapTreePage Treapzjs;
    indexSearchTreePage ISzjs;
    w.show();
    w.move ((QApplication::desktop()->width() - w.width())/2,(QApplication::desktop()->height() - w.height())/2);
    //
    QObject::connect(&w, SIGNAL(sendSignal()), &zjs, SLOT(receiveSignal()) );
    QObject::connect(&zjs, SIGNAL(returnToHomeSignal()), &w, SLOT(receiveSignal()) );
    //
    QObject::connect(&w, SIGNAL(AVLsendSignal()), &AVLzjs, SLOT(receiveSignal()) );
    QObject::connect(&AVLzjs, SIGNAL(returnToHomeSignal()), &w, SLOT(receiveSignal()) );
    //
    QObject::connect(&w, SIGNAL(RBsendSignal()), &RBzjs, SLOT(receiveSignal()) );
    QObject::connect(&RBzjs, SIGNAL(returnToHomeSignal()), &w, SLOT(receiveSignal()) );
    //
    QObject::connect(&w, SIGNAL(TreapsendSignal()), &Treapzjs, SLOT(receiveSignal()) );
    QObject::connect(&Treapzjs, SIGNAL(returnToHomeSignal()), &w, SLOT(receiveSignal()) );
    //
    QObject::connect(&w, SIGNAL(ISsendSignal()), &ISzjs, SLOT(receiveSignal()) );
    QObject::connect(&ISzjs, SIGNAL(returnToHomeSignal()), &w, SLOT(receiveSignal()) );

    return a.exec();
}
