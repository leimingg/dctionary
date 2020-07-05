#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#define WORDMAX 111104

struct dicts {
    char* word;
    char* trans;

};

typedef struct dicts dic;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    dic *p;
};
#endif // MAINWINDOW_H
