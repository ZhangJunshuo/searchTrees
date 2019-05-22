#include "secondpage.h"
#include "ui_secondpage.h"
#include "searchTreeWithoutLeftSize.h"
#include <vector>
#include <random>
#include <algorithm>

searchTree<int,char> zjs;
secondPage::secondPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::secondPage)
{
    ui->setupUi(this);
    setWindowState(Qt::WindowMaximized);
    //QImage* img=new QImage;
    //img->load("D:\\zhangjunshuo_qt\\myFirstWidgetProject\\image\\zjs.png");
    //ui->zjspng->setPixmap(QPixmap::fromImage(*img));
}

secondPage::~secondPage()
{
    delete ui;
}

void secondPage::receiveSignal()
{
    this->show();
}

void secondPage::on_insert_clicked()
{
    zjs.insert(pair<int,char>( ui->inputInsertPair->toPlainText().toInt(), 'z'));
    zjs.output();
    Sleep(100);
    int x = 1600;
    int y = 1000;
    ui->zjspng->setGeometry(5,5,x,y);
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
    ui->zjspng->setPixmap(rePixmap);
}

void secondPage::on_erase_clicked()
{
    zjs.erase(ui->inputEraseKey->toPlainText().toInt());
    zjs.output();
    Sleep(100);
    int x = 1600;
    int y = 1000;
    ui->zjspng->setGeometry(5,5,x,y);
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
    ui->zjspng->setPixmap(rePixmap);
}

void secondPage::on_shunxucharu_clicked()
{
    searchTree<int,char> temp_zjs;
    int num = ui->input_shunxucharu->toPlainText().toInt();
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
        Sleep(100);
        int x = 1600;
        int y = 1000;
        ui->zjspng->setGeometry(5,5,x,y);
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
        ui->zjspng->setPixmap(rePixmap);
}

void secondPage::on_suijicharu_clicked()
{
    searchTree<int,char> temp_zjs;
    int num = ui->input_suijicharu->toPlainText().toInt();
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
        Sleep(100);
        int x = 1600;
        int y = 1000;
        ui->zjspng->setGeometry(5,5,x,y);
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
        ui->zjspng->setPixmap(rePixmap);
}

//这一串都是为了自动随机插入而设置的全局变量
int ISnumForZiDongSuiJiChaRu = 0;
vector<int> IStempForZiDongSuiJiChaRu;
pair<int,char>* ISdataForZiDongSuiJiChaRu;
bool ISfirstInThisFunction = true;    //也是为了自动随机插入设置的
//第一次进入自动随机插入函数时，初始化vector和pair数组
//以后就不必了
searchTree<int,char> IStemp_zjsForZiDongSuiJiChaRu;
int ISiForZiDongSuiJiChaRu = 0;
void secondPage::on_zidongsuijicharu_clicked()
{
    //
    if(ISfirstInThisFunction)
    {
        ISnumForZiDongSuiJiChaRu = ui->input_zidongsuijicharu->toPlainText().toInt();
        for (int i = 1; i <= ISnumForZiDongSuiJiChaRu; i++)
        {
            IStempForZiDongSuiJiChaRu.push_back(i);
        }
        random_shuffle(IStempForZiDongSuiJiChaRu.begin(), IStempForZiDongSuiJiChaRu.end());
        ISdataForZiDongSuiJiChaRu = new pair<int,char>[ISnumForZiDongSuiJiChaRu];
        for (int i = 0; i < ISnumForZiDongSuiJiChaRu; i++)
        {
            ISdataForZiDongSuiJiChaRu[i].first = IStempForZiDongSuiJiChaRu[i];
            ISdataForZiDongSuiJiChaRu[i].second = 'z';
        }
        IStemp_zjsForZiDongSuiJiChaRu.insert(ISdataForZiDongSuiJiChaRu[ISiForZiDongSuiJiChaRu]);
        ISiForZiDongSuiJiChaRu++;
        ISfirstInThisFunction = false;
    }
    else
    {
        if(ISiForZiDongSuiJiChaRu<ISnumForZiDongSuiJiChaRu)
        {
            IStemp_zjsForZiDongSuiJiChaRu.insert(ISdataForZiDongSuiJiChaRu[ISiForZiDongSuiJiChaRu]);
            ISiForZiDongSuiJiChaRu++;
            //
            IStemp_zjsForZiDongSuiJiChaRu.output();
            Sleep(100);
            int x = 1600;
            int y = 1000;
            ui->zjspng->setGeometry(5,5,x,y);
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
            ui->zjspng->setPixmap(rePixmap);
        }
        else
        {
            ;//什么都不做
        }
    }
}

void secondPage::on_fanhuizhuye_clicked()
{
    this->hide();
    emit returnToHomeSignal();
}
