#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QTextCodec>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    p = (dic*)malloc(sizeof(dic) * WORDMAX);
    FILE* fp = fopen("C:\\Users\\Ming\\Documents\\dict\\dict.txt", "r");
    if (!fp) {
        return;
    }
    int i = 0;
    char buf[1024];
    while (!feof(fp)) {
        memset(buf, 0, 1024);
        fgets(buf, 1024, fp);
        buf[strlen(buf)-1]='\0';

        p[i].word= (char*)malloc(strlen(buf) + 1);

        memset(p[i].word, 0, strlen(buf) + 1);
        strcpy(p[i].word, &buf[1]);

        memset(buf, 0, 1024);
        fgets(buf, 1024, fp);
        p[i].trans = (char*)malloc(strlen(buf) + 1);
        memset(p[i].trans, 0, strlen(buf) + 1);
        strcpy(p[i].trans, buf);


        i++;
    }

    fclose(fp);
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    for (int i = 0;i < WORDMAX;i++) {
            free(p[i].word);
            free(p[i].trans);

        }
    free(p);
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString txt=ui->textEdit->toPlainText();
    QTextCodec * codec=QTextCodec::codecForName("GBK");
    if(txt.isEmpty()){
        ui->label->setText("Enter word");
        return;
    }
    char *buf=codec->fromUnicode(txt).data();
    for(int i=0;i<WORDMAX;i++){
        if(!strcmp(buf,p[i].word)){
            ui->label->setText(codec->toUnicode(p[i].trans));
            return;
        }
    }
    ui->label->setText(codec->toUnicode("No Translation Found!"));
}
