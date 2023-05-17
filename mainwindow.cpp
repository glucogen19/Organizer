#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QKeyEvent>
#include <QRandomGenerator>

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

     mainButton = new QPushButton("Создать кнопку", this);
     connect(mainButton, &QPushButton::clicked, this, &MainWindow::crButton);

}
MainWindow::~MainWindow()
{
    delete ui;
}

int cnt = 0;

void MainWindow::on_pushButton_clicked()
{

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

}


void MainWindow::crButton()
{
    QPushButton *button = new QPushButton("Новая кнопка",  ui->scrollArea->widget());
    // Дополнительные настройки кнопки
    // ...

    // Размещение кнопки на форме
    int x = QRandomGenerator::global()->bounded(width() - button->width());
    int y = QRandomGenerator::global()->bounded(height() - button->height());
    button->move(x, y);
    button->show();
}

