#ifndef SECONDPAGE_H
#define SECONDPAGE_H

#include <QWidget>

namespace Ui {
class secondPage;
}

class secondPage : public QWidget
{
    Q_OBJECT

public:
    explicit secondPage(QWidget *parent = nullptr);
    ~secondPage();

private slots:
    void receiveSignal();

    void on_insert_clicked();

    void on_erase_clicked();

    void on_shunxucharu_clicked();

    void on_suijicharu_clicked();

    void on_zidongsuijicharu_clicked();

    void on_fanhuizhuye_clicked();

private:
    Ui::secondPage *ui;

signals:
    void returnToHomeSignal();
};

#endif // SECONDPAGE_H
