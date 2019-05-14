#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButton_2_clicked();

    void receiveSignal();

    void on_AVL_clicked();

    void on_RB_clicked();

    void on_Treap_clicked();

    void on_IS_clicked();

signals:
    void sendSignal();
    void AVLsendSignal();
    void RBsendSignal();
    void TreapsendSignal();
    void ISsendSignal();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
