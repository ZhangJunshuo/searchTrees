#include "treaptreepage.h"
#include "ui_treaptreepage.h"
#include "balancedSearchTree_Treap.h"
#include <vector>
#include <random>
#include <algorithm>

searchTree<int,char> Treapzjs;
TreapTreePage::TreapTreePage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TreapTreePage)
{
    ui->setupUi(this);
    setWindowState(Qt::WindowMaximized);
    //QImage* img=new QImage;
    //img->load("D:\\zhangjunshuo_qt\\myFirstWidgetProject\\image\\zjs.png");
    //ui->Treapzjspng->setPixmap(QPixmap::fromImage(*img));
}

TreapTreePage::~TreapTreePage()
{
    delete ui;
}

void TreapTreePage::receiveSignal()
{
    this->show();
}

void TreapTreePage::on_Treapinsert_clicked()
{
    Treapzjs.insert(Treapzjs.indexOfRoot,pair<int,char>( ui->TreapinputInsertPair->toPlainText().toInt(), 'z'));
    Treapzjs.output();
    int x = 1600;
    int y = 1000;
    ui->Treapzjspng->setGeometry(5,5,x,y);
    //QImage* img=new QImage;
    QPixmap *pixmap = new QPixmap("D:\\zhangjunshuo_qt\\myFirstWidgetProject\\image\\zjs.png");
    //ui->Treapzjspng->setScaledContents(false);
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
    ui->Treapzjspng->setPixmap(rePixmap);

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

//    ui->Treapzjspng->setPixmap(QPixmap::fromImage(*scaledimg));
//    //ui->Treapzjspng->setText("zjsnb!");
}

void TreapTreePage::on_Treaperase_clicked()
{
    Treapzjs.erase(Treapzjs.indexOfRoot,ui->TreapinputEraseKey->toPlainText().toInt());
    Treapzjs.output();
    int x = 1600;
    int y = 1000;
    ui->Treapzjspng->setGeometry(5,5,x,y);
    //QImage* img=new QImage;
    QPixmap *pixmap = new QPixmap("D:\\zhangjunshuo_qt\\myFirstWidgetProject\\image\\zjs.png");
    //ui->Treapzjspng->setScaledContents(false);
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
    ui->Treapzjspng->setPixmap(rePixmap);
}

void TreapTreePage::on_Treapshunxucharu_clicked()
{
    searchTree<int,char> temp_zjs;
    int num = ui->Treapinput_shunxucharu->toPlainText().toInt();
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
            temp_zjs.insert(temp_zjs.indexOfRoot, data[i]);
        }
    //
        temp_zjs.output();
        int x = 1600;
        int y = 1000;
        ui->Treapzjspng->setGeometry(5,5,x,y);
        //QImage* img=new QImage;
        QPixmap *pixmap = new QPixmap("D:\\zhangjunshuo_qt\\myFirstWidgetProject\\image\\zjs.png");
        //ui->Treapzjspng->setScaledContents(false);
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
        ui->Treapzjspng->setPixmap(rePixmap);
}

void TreapTreePage::on_Treapsuijicharu_clicked()
{
    searchTree<int,char> temp_zjs;
    int num = ui->Treapinput_suijicharu->toPlainText().toInt();
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
            temp_zjs.insert(temp_zjs.indexOfRoot, data[i]);
        }
    //
        temp_zjs.output();
        int x = 1600;
        int y = 1000;
        ui->Treapzjspng->setGeometry(5,5,x,y);
        //QImage* img=new QImage;
        QPixmap *pixmap = new QPixmap("D:\\zhangjunshuo_qt\\myFirstWidgetProject\\image\\zjs.png");
        //ui->Treapzjspng->setScaledContents(false);
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
        ui->Treapzjspng->setPixmap(rePixmap);
}

//这一串都是为了自动随机插入而设置的全局变量
int TreapnumForZiDongSuiJiChaRu = 0;
vector<int> TreaptempForZiDongSuiJiChaRu;
pair<int,char>* TreapdataForZiDongSuiJiChaRu;
bool TreapfirstInThisFunction = true;    //也是为了自动随机插入设置的
//第一次进入自动随机插入函数时，初始化vector和pair数组
//以后就不必了
searchTree<int,char> Treaptemp_zjsForZiDongSuiJiChaRu;
int TreapiForZiDongSuiJiChaRu = 0;
void TreapTreePage::on_Treapzidongsuijicharu_clicked()
{
    //
    if(TreapfirstInThisFunction)
    {
        TreapnumForZiDongSuiJiChaRu = ui->Treapinput_zidongsuijicharu->toPlainText().toInt();
        for (int i = 1; i <= TreapnumForZiDongSuiJiChaRu; i++)
        {
            TreaptempForZiDongSuiJiChaRu.push_back(i);
        }
        random_shuffle(TreaptempForZiDongSuiJiChaRu.begin(), TreaptempForZiDongSuiJiChaRu.end());
        TreapdataForZiDongSuiJiChaRu = new pair<int,char>[TreapnumForZiDongSuiJiChaRu];
        for (int i = 0; i < TreapnumForZiDongSuiJiChaRu; i++)
        {
            TreapdataForZiDongSuiJiChaRu[i].first = TreaptempForZiDongSuiJiChaRu[i];
            TreapdataForZiDongSuiJiChaRu[i].second = 'z';
        }
        Treaptemp_zjsForZiDongSuiJiChaRu.insert(Treaptemp_zjsForZiDongSuiJiChaRu.indexOfRoot, TreapdataForZiDongSuiJiChaRu[TreapiForZiDongSuiJiChaRu]);
        TreapiForZiDongSuiJiChaRu++;
        TreapfirstInThisFunction = false;
    }
    else
    {
        if(TreapiForZiDongSuiJiChaRu<TreapnumForZiDongSuiJiChaRu)
        {
            Treaptemp_zjsForZiDongSuiJiChaRu.insert(Treaptemp_zjsForZiDongSuiJiChaRu.indexOfRoot, TreapdataForZiDongSuiJiChaRu[TreapiForZiDongSuiJiChaRu]);
            TreapiForZiDongSuiJiChaRu++;
            //
            Treaptemp_zjsForZiDongSuiJiChaRu.output();
            int x = 1600;
            int y = 1000;
            ui->Treapzjspng->setGeometry(5,5,x,y);
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
            ui->Treapzjspng->setPixmap(rePixmap);
        }
        else
        {
            ;//什么都不做
        }
    }
}

void TreapTreePage::on_Treapfanhuizhuye_clicked()
{
    this->hide();
    emit returnToHomeSignal();
}
