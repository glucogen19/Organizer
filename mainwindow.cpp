#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QKeyEvent>

QCheckBox *checkB[11];
QPushButton *pushB[11];

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
     ui->setupUi(this);
     setFixedSize(530, 560);
     setFocusPolicy(Qt::StrongFocus);
     ///////////
     checkB[0]=ui->checkBox_1; checkB[1]=ui->checkBox_2;
     checkB[2]=ui->checkBox_3; checkB[3]=ui->checkBox_4;
     checkB[4]=ui->checkBox_5; checkB[5]=ui->checkBox_6;
     checkB[6]=ui->checkBox_7; checkB[7]=ui->checkBox_8;
     checkB[8]=ui->checkBox_9; checkB[9]=ui->checkBox_10;
     checkB[10]=ui->checkBox_11;

    for (int i = 0; i < 11; i++){
       checkB[i]->hide();
    }
    ///////////
    pushB[0]=ui->pushButton_1; pushB[1]=ui->pushButton_2;
    pushB[2]=ui->pushButton_3; pushB[3]=ui->pushButton_4;
    pushB[4]=ui->pushButton_5; pushB[5]=ui->pushButton_6;
    pushB[6]=ui->pushButton_7; pushB[7]=ui->pushButton_8;
    pushB[8]=ui->pushButton_9; pushB[9]=ui->pushButton_10;
    pushB[10]=ui->pushButton_11;

    for (int i = 0; i < 11; i++){
       pushB[i]->hide();
    }
    ///////////
    //int i = 0;
    //if (pushB[i]->isChecked( )
}
MainWindow::~MainWindow()
{
    delete ui;
}

int cnt = 0;

void MainWindow::on_pushButton_clicked()
{
    if (cnt < 11) {
         QString task = ui->lineEdit->text();
         checkB[cnt]->show();
         checkB[cnt]->setText(task);
         ui->lineEdit->clear();
         cnt++;
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return) {
        // Нажата клавиша Enter или Return
        ui->pushButton->click(); // Симулируем нажатие кнопки PushButton
    } else {
        // Обработка других событий клавиатуры
        QMainWindow::keyPressEvent(event);
    }
}
