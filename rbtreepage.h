#ifndef RBTREEPAGE_H
#define RBTREEPAGE_H

#include <QWidget>

namespace Ui {
class RBTreePage;
}

class RBTreePage : public QWidget
{
    Q_OBJECT

public:
    explicit RBTreePage(QWidget *parent = nullptr);
    ~RBTreePage();

private slots:
    void receiveSignal();

    void on_RBinsert_clicked();

    void on_RBerase_clicked();

    void on_RBshunxucharu_clicked();

    void on_RBsuijicharu_clicked();

    void on_RBzidongsuijicharu_clicked();

    void on_RBfanhuizhuye_clicked();

private:
    Ui::RBTreePage *ui;

signals:
    void returnToHomeSignal();
};

#endif // RBTREEPAGE_H
