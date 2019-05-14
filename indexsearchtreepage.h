#ifndef INDEXSEARCHTREEPAGE_H
#define INDEXSEARCHTREEPAGE_H

#include <QWidget>

namespace Ui {
class indexSearchTreePage;
}

class indexSearchTreePage : public QWidget
{
    Q_OBJECT

public:
    explicit indexSearchTreePage(QWidget *parent = nullptr);
    ~indexSearchTreePage();

private slots:
    void receiveSignal();

    void on_ISinsert_clicked();

    void on_ISerase_clicked();

    void on_ISshunxucharu_clicked();

    void on_ISsuijicharu_clicked();

    void on_ISzidongsuijicharu_clicked();

    void on_ISfanhuizhuye_clicked();

    void on_ISelementOfRank_clicked();

private:
    Ui::indexSearchTreePage *ui;

signals:
    void returnToHomeSignal();
};

#endif // INDEXSEARCHTREEPAGE_H
