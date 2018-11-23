//{615d371e-f7f5-41ab-853f-5450c1606d2a}
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QMovie>
#include <QTimer>
#include <QTime>
#include<QMouseEvent>
#include<QDebug>
#include<QPainter>
#include<QSystemTrayIcon>
#include<QFileDialog>
#include"form.h"
#include <QtGlobal>
#include <QDesktopServices>
#include <QUrl>
#include <QMenu>
#include <QProcess>
#include <iostream>
#include "hufftree.h"
#include "decompress.h"
#include <string>
#include <time.h>
#include "comandex.h"
using namespace std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //dialog = new Form(this);
   //dialog->show();

    connect(this,SIGNAL(sig2()),this,SLOT(sig2ed()));
    connect(this,SIGNAL(sig1()),this,SLOT(sig1ed()));
    setWindowOpacity(1);
    setWindowFlags(Qt::FramelessWindowHint);               //设置为无边框窗口

  setAttribute(Qt::WA_TranslucentBackground, true);      //设置透明背景
     setWindowIcon(QIcon(QStringLiteral(":/1.png")));      //设置程序窗体icon
    setContextMenuPolicy(Qt::CustomContextMenu);           //使用菜单

     //QIcon icon = QIcon(":/1.png");
    // myIcon->setIcon(icon);
   // myIcon = new QSystemTrayIcon(this);








         textEdit = new QTextEdit;
        setCentralWidget(textEdit);
        textEdit->setAcceptDrops(false);
        setAcceptDrops(true);






        //setWindowTitle(tr("Text Editor"));

        isLeftPressed=false;
           curPos=0;//标记鼠标左击时的位置
          // this->setMinimumSize(768,432);//设置最小尺寸
           QCursor cursor;
           cursor.setShape(Qt::ArrowCursor);//设置鼠标为箭头形状
          // ui->pushButton->setCursor(cursor);//当放在按钮上时，为箭头
          // cursor.setShape(Qt::OpenHandCursor);
           QMainWindow::setCursor(cursor);//当放在主窗口上时，为手形
           qDebug()<<"h="<<this->height();
           //setWindowFlags(Qt::FramelessWindowHint);//设置主窗口无边框
           qDebug()<<this->minimumHeight();
            this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinimizeButtonHint);







    ui->setupUi(this);
    centralWidget()->setMouseTracking(true);//设置在不按鼠标的情况下也触发鼠标移动事件


    //setWindowIcon(QIcon(QStringLiteral(":/1.png")));



   // this->setWindowIcon(QIcon(":/1.png"));
    //QLabel *label = new QLabel("n");
   // label->setPixmap(QPixmap(":/backg.gif"));

    //QLabel控件显示文字内容
//   QLabel *label1 = new QLabel(this);
//   label1->setText("Hello,world");
//   label1->setGeometry(QRect(50,50,200,25));
    //label1->setScaledContents(true);


   //设置窗体标题，大小，位置，背景颜色；
   this->setWindowTitle("CutDown");
   //this->setMaximumSize(500,500);
   //this->setMinimumSize(500,500);
   this->move(100,100);//setGeometry();
   //this->setStyleSheet("background:rgb(224,227,240)");
    setAttribute(Qt::WA_TranslucentBackground, true);

   //this->setStyleSheet("background:white");


     QLabel *label2 = new QLabel(this);
     label2->setGeometry(QRect(11,10,1049,591));
   //label2->setGeometry(QRect(11,10,767,432));
   //自适应大小
   label2->setScaledContents(true);
   //QTime time;
   //time.start();
   QTime countTime;
   countTime.start();




   QMovie *movie = new QMovie(":/backg.gif");
   QTimer::singleShot(10*1000,label2,SLOT(close()));
   label2->setMovie(movie);
   movie->start();

//压缩
//   QMovie *movie2 = new QMovie(":/load.gif");
//   QTimer::singleShot(20*1000,label2,SLOT(close()));
//   ui->label_9->setMovie(movie2);
//   movie2->start();
//解压
//   QMovie *movie3 = new QMovie(":/jie_ya.gif");
//   QTimer::singleShot(20*1000,label2,SLOT(close()));
//   ui->label_9->setMovie(movie3);
//   movie3->start();




//   QMovie *movie2 = new QMovie(":/loaddown.gif");
//   QTimer::singleShot(10*1000,label2,SLOT(close()));
//   ui->label_9->setMovie(movie2);
//   movie2->start();

//   QTimer *timer = new QTimer(this);
//   timer->setSingleShot(true);
//   connect(timer, SIGNAL(timeout()), this, SLOT(gif1()));
//   //timer->start(11000);
   //QTimer::singleShot(10*1000,this,SLOT(gif1(label2)));
   //QTimer* timer;
   //QObject::connect(timer,SIGNAL(timeout()),this,SLOT(systimer()));
   //timer->start(10000);



  //gif(label2);

//    QTime countTimer;
//    countTimer.start();
   qDebug()<<countTime.elapsed()/1000.0;
    if(countTime.elapsed()==11)
    {
        qDebug()<<i;
        //label2->hide();
    }
   // QTimer::singleShot(10*1000,label2,SLOT(hide()));
  // label2->hide();
   //QTimer::singleShot(10*1000,label2,SLOT(gifhide()));
//   label2->setGeometry(QRect(0,0,1,1));
//   label2->setStyleSheet("");


connect(this, SIGNAL(value(QLabel *q1)), this, SLOT(gif(QLabel *q1)));
connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(open()));



   //
//   this->setWindowFlags(Qt::FramelessWindowHint);
//   btClose = new QPushButton(this);
//   btClose->setText("关闭");;fefpewfsqlitemanager
//   connect(btClose,SIGNAL(clicked()),this,SLOT(close()));

   //


   //
  // this->setWindowFlags(Qt::WindowMinMaxButtonsHint);
   //this->setWindowFlags(Qt::WindowCloseButtonHint);

       connect( ui->pushButton_12, SIGNAL(clicked(bool)), this, SLOT(onMin(bool)) );
       connect( ui->pushButton_13, SIGNAL(clicked(bool)), this, SLOT( onMaxOrNormal(bool)) );
       connect( ui->pushButton_11, SIGNAL(clicked(bool)), this, SLOT( onClose(bool)) );
       connect( ui->pushButton_7, SIGNAL(clicked()), this, SLOT( save()) );
       connect( ui->pushButton_2, SIGNAL(clicked()), this, SLOT( open()) );
       connect(ui->pushButton_6,SIGNAL(clicked()),this,SLOT(freeopen()));
       //connect( ui->pushButton_6, SIGNAL(clicked()), this, SLOT( cutdown()) );
       connect(ui->pushButton_15,SIGNAL(clicked()),this,SLOT(ff()));
       connect(ui->pushButton_5,SIGNAL(clicked()),this,SLOT(share()));
       //connect( this, SIGNAL(clicked()), this, SLOT( open()) );
       //const QUrl regUrl(QLatin1String("https://github.com/wfppfw/wfppfw.github.io"));
       //QDesktopServices::openUrl(regUrl);

ui->pushButton_7->setEnabled(false);
ui->pushButton_7->setStyleSheet("QPushButton{border:2px solid red;border-radius:20px; border-image: url(:/ya1.png) 0 0 0 0; };");
ui->pushButton_5->setEnabled(false);
ui->pushButton_5->setStyleSheet("QPushButton{border:2px solid red;border-radius:20px; border-image: url(:/jie1.png) 0 0 0 0; };");
ui->pushButton_6->setEnabled(false);
ui->pushButton_6->setStyleSheet("QPushButton{border:2px solid red;border-radius:20px; border-image: url(:/fx1.png) 0 0 0 0; };");



menu = new QMenu(this);
action1 = new QAction(this);
action2 = new QAction(this);
action3 = new QAction(this);
action4 = new QAction(this);

action1->setText("微信");
action2->setText("邮箱");
action3->setText("U盘");
action4->setText("QQ");
menu->addAction(action1);
menu->addAction(action2);
menu->addAction(action3);
menu->addAction(action4);

connect(action1,SIGNAL(triggered()),this,SLOT(action1Slot()));
connect(action2,SIGNAL(triggered()),this,SLOT(action2Slot()));
connect(action3,SIGNAL(triggered()),this,SLOT(action3Slot()));
connect(action4,SIGNAL(triggered()),this,SLOT(action4Slot()));
//triggered()
//connect(this, SIGNAL(customContextMenuRequested(const QPoint&)), this, SLOT(share(const QPoint&)));

       //connect( ui->pushButton_9, SIGNAL(clicked()), this, SLOT(ff()) );




//       while(1)
//       {
//           if(countTime.elapsed()==1000*12)
//           {
//               label2->hide();
//               break;
//           }
//       }

//emit value(label2);

}
void MainWindow::cutdown()
{


//QString URL = "www.baidu.com";
//QDesktopServices::openUrl(QUrl(URL.toLatin1()));

     //file_save = QFileDialog::getSaveFileName(this,"解压在这里","All","*");
}
void MainWindow::gif(QLabel *q1)
{
    QTime countTime;

    countTime.start();
           while(1)
           {
               if(countTime.elapsed()==1000*12)
               {
                   q1->hide();
                   break;
               }
           }
     //emit value(q1);
     qDebug()<<i;

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::share()
{
            QPoint pos;
            int x = pos.x();
            pos.setX(x+250);
            int y = pos.y();
            pos.setY(y+130);

            menu->exec(this->mapToGlobal(pos));
            qDebug()<<"d";
}
void MainWindow::action1Slot()
{
    qDebug()<<1;
    //打开微信；
    //const QUrl regUrl(QLatin1String("https://wx.qq.com/"));
    //QDesktopServices::openUrl(regUrl);
   //     /Applications/Mail.app/Contents/MacOS/Mail
    //QDesktopServices::openUrl(QUrl(QLatin1String("mailto:wfppfw12138@163.com")));
//    QString program = "微信";
//    QProcess process;
//    process.start("微信 ping 127.0.0.1");

   // qDebug()<<s;
     QString appName=appadress1+"WeChat.app"+appadress2+ "weChat";
    QProcess *toolProcess = new QProcess;
    toolProcess->start(appName);


}
void MainWindow::action2Slot()
{
    QDesktopServices::openUrl(QUrl(QLatin1String("mailto:wfppfw12138@163.com")));
    qDebug()<<2;
}
void MainWindow::action3Slot()
{
    qDebug()<<3;
}
void MainWindow::action4Slot()
{
    qDebug()<<4;
    QString appName=appadress1+"QQ.app"+appadress2+ "QQ";
   QProcess *toolProcess = new QProcess;
   toolProcess->start(appName);
}
void MainWindow::freeopen()
{

    file_save = QFileDialog::getSaveFileName(this,"解压在这里",file_open[0]+".txt","*");

    //decompress d1(file_open[0].toStdString(),file_save.toStdString());
     ui->label_9->show();
     QMovie *movie3 = new QMovie(":/jie_ya.gif");
     QTimer::singleShot(4*1000,ui->label_9,SLOT(hide()));
     ui->label_9->setMovie(movie3);
     movie3->start();
     emit sig1();
}
void MainWindow::sig1ed()
{
    ComAndEx d;
    d.Extract(file_open[0].toStdString(),file_save.toStdString());

}
void MainWindow::openfile()
{

}
void MainWindow::widget0()
{

}
void MainWindow::ff()
{

    //刷新
    ui->pushButton->setEnabled(true);
    ui->pushButton_7->setEnabled(false);
    ui->pushButton_7->setStyleSheet("QPushButton{border:2px solid red;border-radius:20px; border-image: url(:/ya1.png) 0 0 0 0; };");
    ui->pushButton_5->setEnabled(false);
    ui->pushButton_5->setStyleSheet("QPushButton{border:2px solid red;border-radius:20px; border-image: url(:/jie1.png) 0 0 0 0; };");
    ui->pushButton_6->setEnabled(false);
    ui->pushButton_6->setStyleSheet("QPushButton{border:2px solid red;border-radius:20px; border-image: url(:/fx1.png) 0 0 0 0; };");
    ui->widget_7->setStyleSheet("QWidget{border-image:url(:/jiahao.png) 0 0 0 0;}");
    ui->label_7->setText("0M将要被压缩");
    ui->label_8->setText("<html><head/><body><p align=\"center\"><span style=\" font-size:35pt; color:#8a8a8a;\">拖拽文件到这里</span></p></body></html>");
    ui->label_9->hide();



}
void MainWindow::open()
{

     file_open = QFileDialog::getOpenFileNames(NULL,"选择文件压缩","/","*");
     //QStringList A = ();
     qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
     int test;
     for(int i=0; i<10; i++)
     {
          test =qrand()%21;
         qDebug()<<test;
     }
     if(!file_open.empty())
     {
        ui->pushButton->setEnabled(false);
         emit value(2);
         //ui l1;
         QString Aurl = "border-image:url(:/";
         QString str = QString::number(test);
         Aurl = Aurl + str;
         Aurl = Aurl + ".png) 0 0 0 0;";
        ui->widget_7->setStyleSheet(Aurl);
         qDebug()<<"s";
         ui->pushButton_7->setEnabled(true);
         ui->pushButton_7->setStyleSheet("QPushButton{border:2px solid red;border-radius:20px; border-image: url(:/ya3.png) 0 0 0 0; } QPushButton:pressed{border-image: url(:/ya2.png) 0 0 0 0;}");
         //ui->pushButton_7->setStyleSheet("QPushButton:pressed{border-image: url(:/ya2.png) 0 0 0 0;}");
         ui->pushButton_5->setEnabled(true);
           ui->pushButton_5->setStyleSheet("QPushButton{border:2px solid red;border-radius:20px; border-image: url(:/fx2.png) 0 0 0 0; } QPushButton:pressed{border-image: url(:/fx3.png) 0 0 0 0;}");
         ui->pushButton_6->setEnabled(true);
           ui->pushButton_6->setStyleSheet("QPushButton{border:2px solid red;border-radius:20px; border-image: url(:/jie2.png) 0 0 0 0; } QPushButton:pressed{border-image: url(:/jie3.png) 0 0 0 0;}");
         // ui->label_8->setText("");


           QStringList s1;
           QString S2="";
            QString snumber;
            long long SumOfFile=0;
          for(int i=0;i<file_open.length();i++)
          {
             s1 =  file_open[i].split("/");
             qDebug()<<s1[s1.length()-1];
             S2 = S2+s1[s1.length()-1];
                //QString snumber;
             QFileInfo info(file_open[i]);
             long long u = info.size();
             SumOfFile += u;
             qDebug()<<"hhh";
             qDebug()<<u;
             qDebug()<<"hhh";
             S2 = S2+"<br>";

             //ui->label_8->setText(""+s1[s1.length()-1]);
          }
          S2 = S2+"<br>";
          double number = 0;
          if(SumOfFile<1024)
          {
              number = SumOfFile;
              snumber = QString::number(number);
              snumber += "Bytes";
          }else{
          if(((SumOfFile/1024)/1024)<1)
          {
              number =SumOfFile/1024.00;
              snumber = QString::number(number);
              snumber += "KB";
          }else{
              double x = (SumOfFile/1024.00);
                      number = x/1024.00;
                      snumber = QString::number(number);
                      snumber += "M";
          }
          }

          ui->label_7->setText(snumber+"将要被压缩");
          ui->label_8->setText(S2);



         //<html><head/><body><p align="center"><span style=" font-size:35pt; color:#8a8a8a;">拖拽文件到这里</span></p></body></html>
     }
    qDebug() << file_open;
}
void MainWindow::save()
{
     file_save = QFileDialog::getSaveFileName(this,"压缩在这里",file_open[0]+".zip","*");
    // hufftree h1(file_open[0].toStdString(),file_save.toStdString());
    qDebug() << file_save;

        ui->label_9->show();
       QMovie *movie2 = new QMovie(":/load.gif");
       QTimer::singleShot(110*100,ui->label_9,SLOT(close()));
       ui->label_9->setMovie(movie2);
       movie2->start();
       //ui->label_9->hide();
       emit sig2();
      // ComAndEx c;
      // c.Compress(file_open[0].toStdString(),file_save.toStdString());
        //hufftree h1(file_open[0].toStdString(),file_save.toStdString());
}
void MainWindow::sig2ed()
{
    ComAndEx c;
    c.Compress(file_open[0].toStdString(),file_save.toStdString());
    ui->label_9->hide();
}
void MainWindow::on_showMainAction()
{
    this->show();
}

void MainWindow::on_exitAppAction()
{
    close();
}
void MainWindow::on_activatedSysTrayIcon(QSystemTrayIcon::ActivationReason reason)
{
    switch(reason){
    case QSystemTrayIcon::Trigger:
        myIcon->showMessage(("Message Title"),
                                  ("欢迎使用此程序"),
                                  QSystemTrayIcon::Information,
                                  1000);
        break;
    case QSystemTrayIcon::DoubleClick:
        this->show();
        break;
    default:
        break;
    }
}

void MainWindow::onMin(bool)
{

    hide();

}

void MainWindow::onMaxOrNormal(bool)
{

        if(windowState()!=Qt::WindowFullScreen)
            setWindowState(Qt::WindowFullScreen);
        else setWindowState(Qt::WindowNoState);//恢复正常模式



}

void MainWindow::onClose(bool)
{

    close();
}


void MainWindow::dragEnterEvent(QDragEnterEvent *event)
{
    if (event->mimeData()->hasFormat("text/uri-list")){
        event->acceptProposedAction();
    }
}

void MainWindow::dropEvent(QDropEvent *event)
{
    file_open.clear();
    QList<QUrl> list;
    if( event->mimeData()->hasUrls() )
        {
            list = event->mimeData()->urls();       //获取资源定位符

           for(int i=0; i<list.count(); i++)
           {
               qDebug() << list[i].toLocalFile();       //将资源定位符转化为本地文件路径
           }
        }
       else
        {
           event->ignore();
        }


    if(!list.empty())
    {
        //file_open = QFileDialog::getOpenFileNames(NULL,"选择文件压缩","/","*");
        //QStringList A = ();
        //file_open == list;
        for(int i=0; i<list.count(); i++)
        {
            file_open.append(list[i].toLocalFile());       //将资源定位符转化为本地文件路径
        }

        qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
        int test;
        for(int i=0; i<10; i++)
        {
             test =qrand()%21;
            qDebug()<<test;
        }
        if(!file_open.empty())
        {
            ui->pushButton->setEnabled(false);
           // emit value(2);
            //ui l1;
            QString Aurl = "border-image:url(:/";
            QString str = QString::number(test);
            Aurl = Aurl + str;
            Aurl = Aurl + ".png) 0 0 0 0;";
           ui->widget_7->setStyleSheet(Aurl);
            qDebug()<<"s";
            ui->pushButton_7->setEnabled(true);
            ui->pushButton_7->setStyleSheet("QPushButton{border:2px solid red;border-radius:20px; border-image: url(:/ya3.png) 0 0 0 0; } QPushButton:pressed{border-image: url(:/ya2.png) 0 0 0 0;}");
            //ui->pushButton_7->setStyleSheet("QPushButton:pressed{border-image: url(:/ya2.png) 0 0 0 0;}");
            ui->pushButton_5->setEnabled(true);
              ui->pushButton_5->setStyleSheet("QPushButton{border:2px solid red;border-radius:20px; border-image: url(:/fx2.png) 0 0 0 0; } QPushButton:pressed{border-image: url(:/fx3.png) 0 0 0 0;}");
            ui->pushButton_6->setEnabled(true);
              ui->pushButton_6->setStyleSheet("QPushButton{border:2px solid red;border-radius:20px; border-image: url(:/jie2.png) 0 0 0 0; } QPushButton:pressed{border-image: url(:/jie3.png) 0 0 0 0;}");
            // ui->label_8->setText("");


              QStringList s1;
              QString S2="";
               QString snumber;
               long long SumOfFile=0;
               int yy=0;
               int i;
             for( i=0;i<file_open.length();i++)
             {
                s1 =  file_open[i].split("/");
                if(s1[s1.length()-1]=="")
                {
                    s1.pop_back();
                    yy=1;
                }
                qDebug()<<s1[s1.length()-1];
               // S2 = S2+s1[s1.length()-1];
                   //QString snumber;
                QFileInfo info(file_open[i]);
                long long u=0;
                if(yy==1)
                {
                    u = GetDirFileSize(file_open[i]);
                }else{
                 u = info.size();
                }
                SumOfFile += u;
                qDebug()<<u;
                //S2 = S2+"<br>";
                if(i<=4)
                {
                    S2 = S2+s1[s1.length()-1];
                    S2 = S2+"<br>";
                    yy=1;
                }
                //ui->label_8->setText(""+s1[s1.length()-1]);
             }
             if(i<=4){
                  S2 = S2+"<br>";
             }else{
             S2 = S2+"...<br>";
             }
             double number = 0;
             if(SumOfFile<1024)
             {
                 number = SumOfFile;
                 snumber = QString::number(number);
                 snumber += "Bytes";
             }else{
             if(((SumOfFile/1024.00)/1024.00)<1)
             {
                 number =SumOfFile/1024.00;
                 snumber = QString::number(number);
                 snumber += "KB";
             }else{
                 if((((SumOfFile/1024.00)/1024.00)/1024.00)<1){
                 double x = (SumOfFile/1024.00);
                         number = x/1024.00;
                         snumber = QString::number(number);
                         snumber += "M";
                 }
                 else{
                     double x = (SumOfFile/1024.00);
                             x = x/1024.00;
                             number = x/1024.00;
                             snumber = QString::number(number);
                             snumber += "G";
                 }
             }
             }

             ui->label_7->setText(snumber+"将要被压缩");
             ui->label_8->setText(S2);
             qDebug()<<GetDirFileSize("/Users/wfppfw/Desktop/KMP/");

        }
    }



}
long long MainWindow::GetDirFileSize(const QString &dirPath)
{
    QDir dir(dirPath);
    long long size = 0;
    foreach(QFileInfo fileInfo, dir.entryInfoList(QDir::Files))
    {
        //计算文件大小
        size += fileInfo.size();
    }

    foreach(QString subDir, dir.entryList(QDir::Dirs | QDir::NoDotAndDotDot))
    {
        //若存在子目录，则递归调用dirFileSize()函数
        size += GetDirFileSize(dirPath + QDir::separator() + subDir);
    }

    return size;
}

bool MainWindow::readFile(const QString &fileName)
{
//    bool r = false;
//    QFile file(fileName);
//    QTextStream in(&file);
//    QString content;
//    if(file.open(QIODevice::ReadOnly)) {
//        in >> content;
//        r = true;
//    }
//    textEdit->setText(content);
//    return r;
    QFile file(fileName);
        if(!file.open(QFile::ReadOnly | QFile::Text))
              return false;

        QByteArray data;
        data = file.readAll();
        textEdit->setText(QString::fromLocal8Bit(data));
        return true;
}


void    MainWindow::mouseDoubleClickEvent(QMouseEvent *event)//鼠标双击 全屏
{
    if(event->button()==Qt::LeftButton)
    {
        if(event->y()<50&&event->x()>(0.5*(this->frameGeometry().width()-28))&&event->x()<(0.5*(this->frameGeometry().width()+28)))
        {
            const QUrl regUrl(QLatin1String("https://github.com/wfppfw/wfppfw.github.io"));
            QDesktopServices::openUrl(regUrl);
        }else
        {
        if(windowState()!=Qt::WindowFullScreen)
            setWindowState(Qt::WindowFullScreen);
        else setWindowState(Qt::WindowNoState);//恢复正常模式
        }
    }
    event->ignore();
}

void MainWindow::mousePressEvent(QMouseEvent *event)//鼠标按下事件
{
    if(event->button()==Qt::LeftButton)
    {
        this->isLeftPressed=true;
        QPoint temp=event->globalPos();
        pLast=temp;
        curPos=countFlag(event->pos(),countRow(event->pos()));
        event->ignore();
    }
}


void MainWindow::mouseReleaseEvent(QMouseEvent *event)//鼠标释放事件
{
    if(isLeftPressed)
        isLeftPressed=false;
    QApplication::restoreOverrideCursor();//恢复鼠标指针性状
    event->ignore();
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)//鼠标移动事件
{

    int poss=countFlag(event->pos(),countRow(event->pos()));
    setCursorType(poss);
    if(isLeftPressed)//是否左击
    {
        QPoint ptemp=event->globalPos();
        ptemp=ptemp-pLast;
        if(curPos==22)//移动窗口
        {
            ptemp=ptemp+pos();
            move(ptemp);
        }
        else
        {
            QRect wid=geometry();

            switch(curPos)//改变窗口的大小
            {

            case 11:wid.setTopLeft(wid.topLeft()+ptemp);break;//左上角
            case 13:wid.setTopRight(wid.topRight()+ptemp);break;//右上角
            case 31:wid.setBottomLeft(wid.bottomLeft()+ptemp);break;//左下角
            case 33:wid.setBottomRight(wid.bottomRight()+ptemp);break;//右下角
            case 12:wid.setTop(wid.top()+ptemp.y());break;//中上角
            case 21:wid.setLeft(wid.left()+ptemp.x());break;//中左角
            case 23:wid.setRight(wid.right()+ptemp.x());break;//中右角
            case 32:wid.setBottom(wid.bottom()+ptemp.y());break;//中下角
            }
            setGeometry(wid);
        }


        pLast=event->globalPos();//更新位置
    }
    event->ignore();
}

int MainWindow::countFlag(QPoint p,int row)//计算鼠标在哪一列和哪一行
{
    if(p.y()<MARGIN)
        return 10+row;
    else if(p.y()>this->height()-MARGIN)
        return 30+row;
    else
        return 20+row;
}

void MainWindow::setCursorType(int flag)//根据鼠标所在位置改变鼠标指针形状
{
    Qt::CursorShape cursor;
    switch(flag)
    {
    case 11:
    case 33:
        cursor=Qt::SizeFDiagCursor;break;
    case 13:
    case 31:
        cursor=Qt::SizeBDiagCursor;break;
    case 21:
    case 23:
        cursor=Qt::SizeHorCursor;break;
    case 12:
    case 32:
        cursor=Qt::SizeVerCursor;break;
    case 22:
        cursor=Qt::OpenHandCursor;break;
    default:
       //  QApplication::restoreOverrideCursor();//恢复鼠标指针性状
         break;

    }
    setCursor(cursor);
}
int MainWindow::countRow(QPoint p)//计算在哪一列
{
    return (p.x()<MARGIN)?1:(p.x()>(this->width()-MARGIN)?3:2);
}













