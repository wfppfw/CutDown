#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#define MARGIN 20//四个角的长度
#include <QMainWindow>
#include <QMouseEvent>
#include <QPushButton>
#include <QtGui>
#include <QTextEdit>
#include<QSystemTrayIcon>
#include<QLabel>
#include"form.h"
#include <iostream>
#include <string>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:


   //QString StoQ(const string &s);
    long long GetDirFileSize(const QString &dirPath);
    void  widget0();
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
   // void gif(QLabel *q1);
       QStringList file_open;
       QString file_save="0";
    int countFlag(QPoint p, int row);
        void setCursorType(int flag);
        int countRow(QPoint p);
        QSystemTrayIcon *myIcon;
            QMenu *mMenu;
            QAction *mShowMainAction;
            QAction *mExitAppAction;
signals:
        void value(int a);
        void sig1();
        void sig2();
protected:

    //鼠标双击
    void mouseDoubleClickEvent(QMouseEvent *event);


    void dragEnterEvent(QDragEnterEvent *event);//拖动

    void dropEvent(QDropEvent *event);//放下


//    //鼠标按下
   void mousePressEvent(QMouseEvent *event);
//    //鼠标移动
    void mouseMoveEvent(QMouseEvent *event);
//    //鼠标释放
    void mouseReleaseEvent(QMouseEvent *event);

    void openfile();
private slots:

    /* custom system btn */
    void sig1ed();
    void sig2ed();
    void action1Slot();
    void action2Slot();
    void action3Slot();
    void action4Slot();
    void share();
    void gif(QLabel *q1);
    void freeopen();
    void cutdown();
    void open();
    void save();
    void onMin( bool );
    void onMaxOrNormal( bool );
    void onClose( bool );
    void ff();
    void on_activatedSysTrayIcon(QSystemTrayIcon::ActivationReason reason);
        void on_showMainAction();
        void on_exitAppAction();
private:
     QString appadress1 = "/Applications/";
     QString appadress2 = "/Contents/MacOS/";
    int i =0;
    QMenu *menu;
    QAction *action1;
    QAction *action2;
    QAction *action3;
    QAction *action4;
    bool maxOrNormal;//true表示当前窗口状态为normal，图标应显示为max
   // QLabel *label2;
    bool readFile(const QString &fileName);
    QTextEdit *textEdit;
    Ui::MainWindow *ui;
    Form *dialog;


    bool isLeftPressed;
        int curPos;
        QPoint pLast;
    QPushButton *btClose;
    QPoint last;
   // QSystemTrayIcon  mySysTraIcon;
};


#endif // MAINWINDOW_H
