#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("English-Chinese Dictionary");
    w.setWindowIcon(QIcon("C:\\Users\\Ming\\Documents\\dict\\app1.ico"));
    w.show();
    return a.exec();
}
