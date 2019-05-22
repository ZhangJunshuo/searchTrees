#include "avltreepage.h"
#include "ui_avltreepage.h"
#include "balancedSearchTree_AVL.h"
#include <vector>
#include <random>
#include <algorithm>

searchTree<int> AVLzjs;
AVLTreePage::AVLTreePage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AVLTreePage)
{
    ui->setupUi(this);
    setWindowState(Qt::WindowMaximized);
    //QImage* img=new QImage;
    //img->load("D:\\zhangjunshuo_qt\\myFirstWidgetProject\\image\\avlzjs.png");
    //ui->AVLzjspng->setPixmap(QPixmap::fromImage(*img));
}

AVLTreePage::~AVLTreePage()
{
    delete ui;
}

void AVLTreePage::receiveSignal()
{
    this->show();
}

void AVLTreePage::on_AVLinsert_clicked()
{
    AVLzjs.insert( ui->AVLinputInsertPair->toPlainText().toInt() );
    AVLzjs.output();
    Sleep(100);
    int x = 1600;
    int y = 1000;
    ui->AVLzjspng->setGeometry(5,5,x,y);
    //QImage* img=new QImage;
    QPixmap *pixmap = new QPixmap("D:\\zhangjunshuo_qt\\myFirstWidgetProject\\image\\avlzjs.png");
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
    ui->AVLzjspng->setPixmap(rePixmap);

    //img->load("D:\\zhangjunshuo_qt\\myFirstWidgetProject\\image\\avlzjs.png");
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

//    ui->AVLzjspng->setPixmap(QPixmap::fromImage(*scaledimg));
//    //ui->AVLzjspng->setText("zjsnb!");
}

void AVLTreePage::on_AVLerase_clicked()
{
    AVLzjs.erase(ui->AVLinputEraseKey->toPlainText().toInt());
    AVLzjs.output();
    Sleep(100);
    int x = 1600;
    int y = 1000;
    ui->AVLzjspng->setGeometry(5,5,x,y);
    //QImage* img=new QImage;
    QPixmap *pixmap = new QPixmap("D:\\zhangjunshuo_qt\\myFirstWidgetProject\\image\\avlzjs.png");
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
    ui->AVLzjspng->setPixmap(rePixmap);
}

void AVLTreePage::on_AVLshunxucharu_clicked()
{
    searchTree<int> temp_zjs;
    int num = ui->AVLinput_shunxucharu->toPlainText().toInt();
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
        temp_zjs.output();
        Sleep(100);
        int x = 1600;
        int y = 1000;
        ui->AVLzjspng->setGeometry(5,5,x,y);
        //QImage* img=new QImage;
        QPixmap *pixmap = new QPixmap("D:\\zhangjunshuo_qt\\myFirstWidgetProject\\image\\avlzjs.png");
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
        ui->AVLzjspng->setPixmap(rePixmap);
}

void AVLTreePage::on_AVLsuijicharu_clicked()
{
    searchTree<int> temp_zjs;
    int num = ui->AVLinput_suijicharu->toPlainText().toInt();
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
        temp_zjs.output();
        Sleep(100);
        int x = 1600;
        int y = 1000;
        ui->AVLzjspng->setGeometry(5,5,x,y);
        //QImage* img=new QImage;
        QPixmap *pixmap = new QPixmap("D:\\zhangjunshuo_qt\\myFirstWidgetProject\\image\\avlzjs.png");
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
        ui->AVLzjspng->setPixmap(rePixmap);
}

//这一串都是为了自动随机插入而设置的全局变量
int AVLnumForZiDongSuiJiChaRu = 0;
vector<int> AVLtempForZiDongSuiJiChaRu;
int* AVLdataForZiDongSuiJiChaRu;
bool AVLfirstInThisFunction = true;    //也是为了自动随机插入设置的
//第一次进入自动随机插入函数时，初始化vector和pair数组
//以后就不必了
searchTree<int> AVLtemp_zjsForZiDongSuiJiChaRu;
int AVLiForZiDongSuiJiChaRu = 0;
void AVLTreePage::on_AVLzidongsuijicharu_clicked()
{
    //
    if(AVLfirstInThisFunction)
    {
        AVLnumForZiDongSuiJiChaRu = ui->AVLinput_zidongsuijicharu->toPlainText().toInt();
        for (int i = 1; i <= AVLnumForZiDongSuiJiChaRu; i++)
        {
            AVLtempForZiDongSuiJiChaRu.push_back(i);
        }
        random_shuffle(AVLtempForZiDongSuiJiChaRu.begin(), AVLtempForZiDongSuiJiChaRu.end());
        AVLdataForZiDongSuiJiChaRu = new int[AVLnumForZiDongSuiJiChaRu];
        for (int i = 0; i < AVLnumForZiDongSuiJiChaRu; i++)
        {
            AVLdataForZiDongSuiJiChaRu[i] = AVLtempForZiDongSuiJiChaRu[i];
        }
        AVLtemp_zjsForZiDongSuiJiChaRu.insert(AVLdataForZiDongSuiJiChaRu[AVLiForZiDongSuiJiChaRu]);
        AVLiForZiDongSuiJiChaRu++;
        AVLfirstInThisFunction = false;
    }
    else
    {
        if(AVLiForZiDongSuiJiChaRu<AVLnumForZiDongSuiJiChaRu)
        {
            AVLtemp_zjsForZiDongSuiJiChaRu.insert(AVLdataForZiDongSuiJiChaRu[AVLiForZiDongSuiJiChaRu]);
            AVLiForZiDongSuiJiChaRu++;
            //
            AVLtemp_zjsForZiDongSuiJiChaRu.output();
            Sleep(100);
            int x = 1600;
            int y = 1000;
            ui->AVLzjspng->setGeometry(5,5,x,y);
            //QImage* img=new QImage;
            QPixmap *pixmap = new QPixmap("D:\\zhangjunshuo_qt\\myFirstWidgetProject\\image\\avlzjs.png");
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
            ui->AVLzjspng->setPixmap(rePixmap);
        }
        else
        {
            ;//什么都不做
        }
    }
}

void AVLTreePage::on_AVLfanhuizhuye_clicked()
{
    this->hide();
    emit returnToHomeSignal();
}
