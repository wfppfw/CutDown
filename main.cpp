#include "mainwindow.h"
#include <QApplication>
#include <QLabel>
#include <QTime>
#include <QDebug>

#include <QMovie>
#include <iostream>
#include <iostream>
#include "hufftree.h"
#include "decompress.h"
#include <string>
#include <time.h>
#include "comandex.h"


using namespace std;
int main(int argc, char *argv[])
{
    cout<<"jj";
    QApplication a(argc, argv);
   MainWindow w;
   //qDebug() << w.file_save;

   w.show();
    //string name1 = "/Users/wfppfw/Desktop/11.txt";
    // string name2 = "/Users/wfppfw/Desktop/1.zip";
    //ComAndEx c;
    //c.Compress(name1,name2);
   // c.Extract(name2,name1);
       //hufftree h1(name1,name2);

       //decompress d1(name2,"/Users/wfppfw/Desktop/111.txt");

    return a.exec();
}
