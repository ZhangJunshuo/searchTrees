#include "indexsearchtreepage.h"
#include "ui_indexsearchtreepage.h"
#include "indexSearchTree.h"
#include <vector>
#include <random>
#include <algorithm>

searchTree<int,char> ISzjs;
indexSearchTreePage::indexSearchTreePage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::indexSearchTreePage)
{
    ui->setupUi(this);
    setWindowState(Qt::WindowMaximized);
    //QImage* img=new QImage;
    //img->load("D:\\zhangjunshuo_qt\\myFirstWidgetProject\\image\\zjs.png");
    //ui->zjspng->setPixmap(QPixmap::fromImage(*img));
}

indexSearchTreePage::~indexSearchTreePage()
{
    delete ui;
}

void indexSearchTreePage::receiveSignal()
{
    this->show();
}

void indexSearchTreePage::on_ISinsert_clicked()
{
    ISzjs.insert(pair<int,char>( ui->ISinputInsertPair->toPlainText().toInt(), 'z'));
    ISzjs.output();
    int x = 1600;
    int y = 1000;
    ui->ISzjspng->setGeometry(5,5,x,y);
    //QImage* img=new QImage;
    QPixmap *pixmap = new QPixmap("D:\\zhangjunshuo_qt\\myFirstWidgetProject\\image\\zjs.png");
    //ui->zjspng->setScaledContents(false);
    //
    int imgw1 = pixmap->width();
    int imgh1 = pixmap->height();
    if(imgw1>x)
    {
        //ui->justForTest->setText((QString)imgw1);
        //imgw1 = imgw1*( 1 - (imgw1-x)/imgw1 );
        //imgw1 = imgw1 * 0.5;
        imgw1 = x-200;
    }
    if(imgh1>y)
    {
        //ui->justForTest->setText((QString)imgh1);
        //imgh1 = imgh1 * 0.5;
        imgh1 = y-200;
    }
    auto rePixmap = pixmap->scaled(imgw1, imgh1, Qt::KeepAspectRatio);
    //
    ui->ISzjspng->setPixmap(rePixmap);

    //img->load("D:\\zhangjunshuo_qt\\myFirstWidgetProject\\image\\zjs.png");
    //开始缩放图片
//    int width0 = img->width();
//    int height0 = img->height();
//    int width1,height1;
//    int k = 0;  //记录图片与label的高宽比，马上用到
//    if(width0/x>=height0/y)
//        k = width0/x;
//    else {
//        k = height0/y;
//    }
//    width1 = width0 / k;
//    height1 = height0 / k;
//    QImage* scaledimg = new QImage;
//    *scaledimg = img->scaled(width1,height1,Qt::KeepAspectRatio);

//    ui->zjspng->setPixmap(QPixmap::fromImage(*scaledimg));
//    //ui->zjspng->setText("zjsnb!");
}

void indexSearchTreePage::on_ISerase_clicked()
{
    ISzjs.erase(ui->ISinputEraseKey->toPlainText().toInt());
    ISzjs.output();
    int x = 1600;
    int y = 1000;
    ui->ISzjspng->setGeometry(5,5,x,y);
    //QImage* img=new QImage;
    QPixmap *pixmap = new QPixmap("D:\\zhangjunshuo_qt\\myFirstWidgetProject\\image\\zjs.png");
    //ui->zjspng->setScaledContents(false);
    //
    int imgw1 = pixmap->width();
    int imgh1 = pixmap->height();
    if(imgw1>x)
    {
        //ui->justForTest->setText((QString)imgw1);
        //imgw1 = imgw1*( 1 - (imgw1-x)/imgw1 );
        //imgw1 = imgw1 * 0.5;
        imgw1 = x-200;
    }
    if(imgh1>y)
    {
        //ui->justForTest->setText((QString)imgh1);
        //imgh1 = imgh1 * 0.5;
        imgh1 = y-200;
    }
    auto rePixmap = pixmap->scaled(imgw1, imgh1, Qt::KeepAspectRatio);
    //
    ui->ISzjspng->setPixmap(rePixmap);
}

void indexSearchTreePage::on_ISshunxucharu_clicked()
{
    searchTree<int,char> temp_zjs;
    int num = ui->ISinput_shunxucharu->toPlainText().toInt();
    //
        vector<int> temp;
        for (int i = 1; i <= num; i++)
        {
            temp.push_back(i);
        }
        //random_shuffle(temp.begin(), temp.end());
        pair<int,char>* data = new pair<int,char>[num];
        for (int i = 0; i < num; i++)
        {
            data[i].first = temp[i];
            data[i].second = 'z';
        }
        for(int i = 0; i < num; i++)
        {
            temp_zjs.insert(data[i]);
        }
    //
        temp_zjs.output();
        int x = 1600;
        int y = 1000;
        ui->ISzjspng->setGeometry(5,5,x,y);
        //QImage* img=new QImage;
        QPixmap *pixmap = new QPixmap("D:\\zhangjunshuo_qt\\myFirstWidgetProject\\image\\zjs.png");
        //ui->zjspng->setScaledContents(false);
        //
        int imgw1 = pixmap->width();
        int imgh1 = pixmap->height();
        if(imgw1>x)
        {
            //ui->justForTest->setText((QString)imgw1);
            //imgw1 = imgw1*( 1 - (imgw1-x)/imgw1 );
            //imgw1 = imgw1 * 0.5;
            imgw1 = x-200;
        }
        if(imgh1>y)
        {
            //ui->justForTest->setText((QString)imgh1);
            //imgh1 = imgh1 * 0.5;
            imgh1 = y-200;
        }
        auto rePixmap = pixmap->scaled(imgw1, imgh1, Qt::KeepAspectRatio);
        //
        ui->ISzjspng->setPixmap(rePixmap);
}

void indexSearchTreePage::on_ISsuijicharu_clicked()
{
    searchTree<int,char> temp_zjs;
    int num = ui->ISinput_suijicharu->toPlainText().toInt();
    //
        vector<int> temp;
        for (int i = 1; i <= num; i++)
        {
            temp.push_back(i);
        }
        random_shuffle(temp.begin(), temp.end());
        pair<int,char>* data = new pair<int,char>[num];
        for (int i = 0; i < num; i++)
        {
            data[i].first = temp[i];
            data[i].second = 'z';
        }
        for(int i = 0; i < num; i++)
        {
            temp_zjs.insert(data[i]);
        }
    //
        temp_zjs.output();
        int x = 1600;
        int y = 1000;
        ui->ISzjspng->setGeometry(5,5,x,y);
        //QImage* img=new QImage;
        QPixmap *pixmap = new QPixmap("D:\\zhangjunshuo_qt\\myFirstWidgetProject\\image\\zjs.png");
        //ui->zjspng->setScaledContents(false);
        //
        int imgw1 = pixmap->width();
        int imgh1 = pixmap->height();
        if(imgw1>x)
        {
            //ui->justForTest->setText((QString)imgw1);
            //imgw1 = imgw1*( 1 - (imgw1-x)/imgw1 );
            //imgw1 = imgw1 * 0.5;
            imgw1 = x-200;
        }
        if(imgh1>y)
        {
            //ui->justForTest->setText((QString)imgh1);
            //imgh1 = imgh1 * 0.5;
            imgh1 = y-200;
        }
        auto rePixmap = pixmap->scaled(imgw1, imgh1, Qt::KeepAspectRatio);
        //
        ui->ISzjspng->setPixmap(rePixmap);
}

//这一串都是为了自动随机插入而设置的全局变量
int numForZiDongSuiJiChaRu = 0;
vector<int> tempForZiDongSuiJiChaRu;
pair<int,char>* dataForZiDongSuiJiChaRu;
bool firstInThisFunction = true;    //也是为了自动随机插入设置的
//第一次进入自动随机插入函数时，初始化vector和pair数组
//以后就不必了
searchTree<int,char> temp_zjsForZiDongSuiJiChaRu;
int iForZiDongSuiJiChaRu = 0;
void indexSearchTreePage::on_ISzidongsuijicharu_clicked()
{
    //
    if(firstInThisFunction)
    {
        numForZiDongSuiJiChaRu = ui->ISinput_zidongsuijicharu->toPlainText().toInt();
        for (int i = 1; i <= numForZiDongSuiJiChaRu; i++)
        {
            tempForZiDongSuiJiChaRu.push_back(i);
        }
        random_shuffle(tempForZiDongSuiJiChaRu.begin(), tempForZiDongSuiJiChaRu.end());
        dataForZiDongSuiJiChaRu = new pair<int,char>[numForZiDongSuiJiChaRu];
        for (int i = 0; i < numForZiDongSuiJiChaRu; i++)
        {
            dataForZiDongSuiJiChaRu[i].first = tempForZiDongSuiJiChaRu[i];
            dataForZiDongSuiJiChaRu[i].second = 'z';
        }
        temp_zjsForZiDongSuiJiChaRu.insert(dataForZiDongSuiJiChaRu[iForZiDongSuiJiChaRu]);
        iForZiDongSuiJiChaRu++;
        firstInThisFunction = false;
    }
    else
    {
        if(iForZiDongSuiJiChaRu<numForZiDongSuiJiChaRu)
        {
            temp_zjsForZiDongSuiJiChaRu.insert(dataForZiDongSuiJiChaRu[iForZiDongSuiJiChaRu]);
            iForZiDongSuiJiChaRu++;
            //
            temp_zjsForZiDongSuiJiChaRu.output();
            int x = 1600;
            int y = 1000;
            ui->ISzjspng->setGeometry(5,5,x,y);
            //QImage* img=new QImage;
            QPixmap *pixmap = new QPixmap("D:\\zhangjunshuo_qt\\myFirstWidgetProject\\image\\zjs.png");
            //ui->AVLzjspng->setScaledContents(false);
            //
            int imgw1 = pixmap->width();
            int imgh1 = pixmap->height();
            if(imgw1>x)
            {
                //ui->justForTest->setText((QString)imgw1);
                //imgw1 = imgw1*( 1 - (imgw1-x)/imgw1 );
                //imgw1 = imgw1 * 0.5;
                imgw1 = x-200;
            }
            if(imgh1>y)
            {
                //ui->justForTest->setText((QString)imgh1);
                //imgh1 = imgh1 * 0.5;
                imgh1 = y-200;
            }
            auto rePixmap = pixmap->scaled(imgw1, imgh1, Qt::KeepAspectRatio);
            //
            ui->ISzjspng->setPixmap(rePixmap);
        }
        else
        {
            ;//什么都不做
        }
    }
}

void indexSearchTreePage::on_ISfanhuizhuye_clicked()
{
    this->hide();
    emit returnToHomeSignal();
}

void indexSearchTreePage::on_ISelementOfRank_clicked()
{
    pair<int,char> _element = temp_zjsForZiDongSuiJiChaRu.elementOfRank(ui->ISinput_elementOfRank->toPlainText().toInt());
    temp_zjsForZiDongSuiJiChaRu.outputForFind(_element);
    //
    int x = 1600;
    int y = 1000;
    ui->ISzjspng->setGeometry(5,5,x,y);
    //QImage* img=new QImage;
    QPixmap *pixmap = new QPixmap("D:\\zhangjunshuo_qt\\myFirstWidgetProject\\image\\zjs.png");
    //ui->zjspng->setScaledContents(false);
    //
    int imgw1 = pixmap->width();
    int imgh1 = pixmap->height();
    if(imgw1>x)
    {
        //ui->justForTest->setText((QString)imgw1);
        //imgw1 = imgw1*( 1 - (imgw1-x)/imgw1 );
        //imgw1 = imgw1 * 0.5;
        imgw1 = x-200;
    }
    if(imgh1>y)
    {
        //ui->justForTest->setText((QString)imgh1);
        //imgh1 = imgh1 * 0.5;
        imgh1 = y-200;
    }
    auto rePixmap = pixmap->scaled(imgw1, imgh1, Qt::KeepAspectRatio);
    //
    ui->ISzjspng->setPixmap(rePixmap);
}
