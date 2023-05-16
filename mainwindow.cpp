#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QKeyEvent>

bool REview = false;

QLineEdit *lineEd[12];
QPushButton *checkB[12];
QPushButton *editB[12];
QPushButton *delB[12];

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
     ui->setupUi(this);
     setFixedSize(530, 580);
     setFocusPolicy(Qt::StrongFocus);
     ///////////
     lineEd[0]=ui->lineEdit_1; lineEd[1]=ui->lineEdit_2;
     lineEd[2]=ui->lineEdit_3; lineEd[3]=ui->lineEdit_4;
     lineEd[4]=ui->lineEdit_5; lineEd[5]=ui->lineEdit_6;
     lineEd[6]=ui->lineEdit_7; lineEd[7]=ui->lineEdit_8;
     lineEd[8]=ui->lineEdit_9; lineEd[9]=ui->lineEdit_10;
     lineEd[10]=ui->lineEdit_11; lineEd[11]=ui->lineEdit_12;

    checkB[0]=ui->pushButton_1; checkB[1]=ui->pushButton_2;
    checkB[2]=ui->pushButton_3; checkB[3]=ui->pushButton_4;
    checkB[4]=ui->pushButton_5; checkB[5]=ui->pushButton_6;
    checkB[6]=ui->pushButton_7; checkB[7]=ui->pushButton_8;
    checkB[8]=ui->pushButton_9; checkB[9]=ui->pushButton_10;
    checkB[10]=ui->pushButton_11; checkB[11]=ui->pushButton_12;

    editB[0]=ui->pushButton_13; editB[1]=ui->pushButton_14;
    editB[2]=ui->pushButton_15; editB[3]=ui->pushButton_16;
    editB[4]=ui->pushButton_17; editB[5]=ui->pushButton_18;
    editB[6]=ui->pushButton_19; editB[7]=ui->pushButton_20;
    editB[8]=ui->pushButton_21; editB[9]=ui->pushButton_22;
    editB[10]=ui->pushButton_23; editB[11]=ui->pushButton_24;

    delB[0]=ui->pushButton_25; delB[1]=ui->pushButton_26;
    delB[2]=ui->pushButton_27; delB[3]=ui->pushButton_28;
    delB[4]=ui->pushButton_29; delB[5]=ui->pushButton_30;
    delB[6]=ui->pushButton_31; delB[7]=ui->pushButton_32;
    delB[8]=ui->pushButton_33; delB[9]=ui->pushButton_34;
    delB[10]=ui->pushButton_35; delB[11]=ui->pushButton_36;

    for (int i = 0; i < 12; i++){
        lineEd[i]->hide();
        checkB[i]->hide();
        editB[i]->hide();
        delB[i]->hide();
    }

}
MainWindow::~MainWindow()
{
    delete ui;
}

int cnt = 0;

void MainWindow::on_pushButton_clicked()
{

    if (cnt < 12) {
         QString task = ui->lineEdit->text();
         lineEd[cnt]->show();
         checkB[cnt]->show();
         editB[cnt]->show();
         delB[cnt]->show();
         lineEd[cnt]->setText(task);
         ui->lineEdit->clear();
         cnt++;

    }

}

void MainWindow::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return) {
        // Нажата клавиша Enter или Return
        ui->pushButton->click(); // Симулируем нажатие кнопки pushButton
    } else {
        // Обработка других событий клавиатуры
        QMainWindow::keyPressEvent(event);
    }
}

void MainWindow::on_pushButton_del_clicked()
{
    for (int i = 0; i < 12; i++){
        lineEd[i]->hide();
        checkB[i]->hide();
        editB[i]->hide();
        delB[i]->hide();
        cnt = 0;
    }
}



