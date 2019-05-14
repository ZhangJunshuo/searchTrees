#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_2_clicked()
{
    this->hide();
    emit sendSignal();
}

void Widget::receiveSignal()
{
    this->show();
}

void Widget::on_AVL_clicked()
{
    this->hide();
    emit AVLsendSignal();
}

void Widget::on_RB_clicked()
{
    this->hide();
    emit RBsendSignal();
}

void Widget::on_Treap_clicked()
{
    this->hide();
    emit TreapsendSignal();
}

void Widget::on_IS_clicked()
{
    this->hide();
    emit ISsendSignal();
}
