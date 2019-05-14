#include "rbtreepage.h"
#include "ui_rbtreepage.h"
#include "balancedSearchTree_RB.h"
#include <vector>
#include <random>
#include <algorithm>

searchTree<int> RBzjs;
RBTreePage::RBTreePage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RBTreePage)
{
    ui->setupUi(this);
    setWindowState(Qt::WindowMaximized);
    //QImage* img=new QImage;
    //img->load("D:\\zhangjunshuo_qt\\myFirstWidgetProject\\image\\zjs.png");
    //ui->RBzjspng->setPixmap(QPixmap::fromImage(*img));
}

RBTreePage::~RBTreePage()
{
    delete ui;
}

void RBTreePage::receiveSignal()
{
    this->show();
}

void RBTreePage::on_RBinsert_clicked()
{
    RBzjs.insert(ui->RBinputInsertPair->toPlainText().toInt());
    RBzjs.RBoutput();
    int x = 1600;
    int y = 1000;
    ui->RBzjspng->setGeometry(5,5,x,y);
    //QImage* img=new QImage;
    QPixmap *pixmap = new QPixmap("D:\\zhangjunshuo_qt\\myFirstWidgetProject\\image\\zjs.png");
    //ui->RBzjspng->setScaledContents(false);
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
    ui->RBzjspng->setPixmap(rePixmap);

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

//    ui->RBzjspng->setPixmap(QPixmap::fromImage(*scaledimg));
//    //ui->RBzjspng->setText("zjsnb!");
}

void RBTreePage::on_RBerase_clicked()
{
    RBzjs.erase(ui->RBinputEraseKey->toPlainText().toInt());
    RBzjs.RBoutput();
    int x = 1600;
    int y = 1000;
    ui->RBzjspng->setGeometry(5,5,x,y);
    //QImage* img=new QImage;
    QPixmap *pixmap = new QPixmap("D:\\zhangjunshuo_qt\\myFirstWidgetProject\\image\\zjs.png");
    //ui->RBzjspng->setScaledContents(false);
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
    ui->RBzjspng->setPixmap(rePixmap);
}

void RBTreePage::on_RBshunxucharu_clicked()
{
    searchTree<int> temp_zjs;
    int num = ui->RBinput_shunxucharu->toPlainText().toInt();
    //
        vector<int> temp;
        for (int i = 1; i <= num; i++)
        {
            temp.push_back(i);
        }
        //random_shuffle(temp.begin(), temp.end());
        int* data = new int[num];
        for (int i = 0; i < num; i++)
        {
            data[i] = temp[i];
        }
        for(int i = 0; i < num; i++)
        {
            temp_zjs.insert(data[i]);
        }
    //
        temp_zjs.RBoutput();
        int x = 1600;
        int y = 1000;
        ui->RBzjspng->setGeometry(5,5,x,y);
        //QImage* img=new QImage;
        QPixmap *pixmap = new QPixmap("D:\\zhangjunshuo_qt\\myFirstWidgetProject\\image\\zjs.png");
        //ui->RBzjspng->setScaledContents(false);
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
        ui->RBzjspng->setPixmap(rePixmap);
}

void RBTreePage::on_RBsuijicharu_clicked()
{
    searchTree<int> temp_zjs;
    int num = ui->RBinput_suijicharu->toPlainText().toInt();
    //
        vector<int> temp;
        for (int i = 1; i <= num; i++)
        {
            temp.push_back(i);
        }
        random_shuffle(temp.begin(), temp.end());
        int* data = new int[num];
        for (int i = 0; i < num; i++)
        {
            data[i] = temp[i];
        }
        for(int i = 0; i < num; i++)
        {
            temp_zjs.insert(data[i]);
        }
    //
        temp_zjs.RBoutput();
        int x = 1600;
        int y = 1000;
        ui->RBzjspng->setGeometry(5,5,x,y);
        //QImage* img=new QImage;
        QPixmap *pixmap = new QPixmap("D:\\zhangjunshuo_qt\\myFirstWidgetProject\\image\\zjs.png");
        //ui->RBzjspng->setScaledContents(false);
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
        ui->RBzjspng->setPixmap(rePixmap);
}

//这一串都是为了自动随机插入而设置的全局变量
int RBnumForZiDongSuiJiChaRu = 0;
vector<int> RBtempForZiDongSuiJiChaRu;
int* RBdataForZiDongSuiJiChaRu;
bool RBfirstInThisFunction = true;    //也是为了自动随机插入设置的
//第一次进入自动随机插入函数时，初始化vector和pair数组
//以后就不必了
searchTree<int> RBtemp_zjsForZiDongSuiJiChaRu;
int RBiForZiDongSuiJiChaRu = 0;
void RBTreePage::on_RBzidongsuijicharu_clicked()
{
    //
    if(RBfirstInThisFunction)
    {
        RBnumForZiDongSuiJiChaRu = ui->RBinput_zidongsuijicharu->toPlainText().toInt();
        for (int i = 1; i <= RBnumForZiDongSuiJiChaRu; i++)
        {
            RBtempForZiDongSuiJiChaRu.push_back(i);
        }
        random_shuffle(RBtempForZiDongSuiJiChaRu.begin(), RBtempForZiDongSuiJiChaRu.end());
        RBdataForZiDongSuiJiChaRu = new int[RBnumForZiDongSuiJiChaRu];
        for (int i = 0; i < RBnumForZiDongSuiJiChaRu; i++)
        {
            RBdataForZiDongSuiJiChaRu[i] = RBtempForZiDongSuiJiChaRu[i];
        }
        RBtemp_zjsForZiDongSuiJiChaRu.insert(RBdataForZiDongSuiJiChaRu[RBiForZiDongSuiJiChaRu]);
        RBiForZiDongSuiJiChaRu++;
        RBfirstInThisFunction = false;
    }
    else
    {
        if(RBiForZiDongSuiJiChaRu<RBnumForZiDongSuiJiChaRu)
        {
            RBtemp_zjsForZiDongSuiJiChaRu.insert(RBdataForZiDongSuiJiChaRu[RBiForZiDongSuiJiChaRu]);
            RBiForZiDongSuiJiChaRu++;
            //
            RBtemp_zjsForZiDongSuiJiChaRu.RBoutput();
            int x = 1600;
            int y = 1000;
            ui->RBzjspng->setGeometry(5,5,x,y);
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
            ui->RBzjspng->setPixmap(rePixmap);
        }
        else
        {
            ;//什么都不做
        }
    }
}

void RBTreePage::on_RBfanhuizhuye_clicked()
{
    this->hide();
    emit returnToHomeSignal();
}
