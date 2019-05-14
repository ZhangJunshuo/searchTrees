#ifndef TreapTREEPAGE_H
#define TreapTREEPAGE_H

#include <QWidget>

namespace Ui {
class TreapTreePage;
}

class TreapTreePage : public QWidget
{
    Q_OBJECT

public:
    explicit TreapTreePage(QWidget *parent = nullptr);
    ~TreapTreePage();

private slots:
    void receiveSignal();

    void on_Treapinsert_clicked();

    void on_Treaperase_clicked();

    void on_Treapshunxucharu_clicked();

    void on_Treapsuijicharu_clicked();

    void on_Treapzidongsuijicharu_clicked();

    void on_Treapfanhuizhuye_clicked();

private:
    Ui::TreapTreePage *ui;

signals:
    void returnToHomeSignal();
};

#endif // TreapTREEPAGE_H
