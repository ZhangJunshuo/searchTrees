#ifndef AVLTREEPAGE_H
#define AVLTREEPAGE_H

#include <QWidget>

namespace Ui {
class AVLTreePage;
}

class AVLTreePage : public QWidget
{
    Q_OBJECT

public:
    explicit AVLTreePage(QWidget *parent = nullptr);
    ~AVLTreePage();

private slots:
    void receiveSignal();

    void on_AVLinsert_clicked();

    void on_AVLerase_clicked();

    void on_AVLshunxucharu_clicked();

    void on_AVLsuijicharu_clicked();

    void on_AVLzidongsuijicharu_clicked();

    void on_AVLfanhuizhuye_clicked();

private:
    Ui::AVLTreePage *ui;

signals:
    void returnToHomeSignal();
};

#endif // AVLTREEPAGE_H
