#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QKeyEvent>
#include <QRandomGenerator>

bool REview = false;

//Объявление глобальных массивов
QLineEdit *lineEd[50];
QPushButton *checkB[50];
QPushButton *editB[50];
QPushButton *delB[50];

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
     ui->setupUi(this);
     setFixedSize(530, 580);
     setFocusPolicy(Qt::StrongFocus);
     ///

}
MainWindow::~MainWindow()
{
    delete ui;
}

int cnt = 0; // Указатель для работы с массивом

void MainWindow::on_pushButton_clicked()
{
    if(cnt < 50){   // Условный цикл, чтобы не выйти за пределы массивов
    //    if(ui->lineEdit->text() != "\0"){ // Условный цикл, чтобы не создавалсь пустая строка
            ui->scrollAreaWidgetContents->show(); // Показ содержимого объекта ScrollArea

            lineEd[cnt] = new QLineEdit; // Выделение памяти для объекта класса QLineEdit в элементе массива lineEd
            lineEd[cnt]->setText(ui->lineEdit->text()); // Запись текста из lineEdir в элемент массива
            lineEd[cnt]->setReadOnly(true); // Запрет на редактирование
            lineEd[cnt]->setFixedHeight(25); // Установка фиксированного размера
            ui->lineEdLay->setSpacing(5); // Установка пустого места на 5пикселей
            ui->lineEdLay->addWidget(lineEd[cnt]); // Добавление элемента lineEd в layout "lineEdLay"
            ui->lineEdLay->setAlignment(Qt::AlignTop); // Прикрепление объекта к верху

            checkB[cnt] = new QPushButton;
            checkB[cnt]->setCheckable(1); // Разрешение на отметку кнопки
            checkB[cnt]->setFixedHeight(25);
            ui->checkLay->setSpacing(5);
            ui->checkLay->setAlignment(Qt::AlignTop);
            ui->checkLay->addWidget(checkB[cnt]);

            editB[cnt] = new QPushButton;
            editB[cnt]->setFixedHeight(25);
            ui->editLay->setSpacing(5);
            ui->editLay->setAlignment(Qt::AlignTop);
            ui->editLay->addWidget(editB[cnt]);

            delB[cnt] = new QPushButton;
            delB[cnt]->setFixedHeight(25);
            ui->delLay->setSpacing(5);
            ui->delLay->setAlignment(Qt::AlignTop);
            ui->delLay->addWidget(delB[cnt]);

            cnt++; // Инкрементируем указатель
            ui->lineEdit->clear(); // Очистка текста
     //   }
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

void MainWindow::on_pushButton_del_clicked() // Очистка Таблицы
{
    for(int i=0;i<cnt;i++){  // Цикл для очистки массивов. Продолжается до элемента cnt, чтобы не выйти за пределы массивов
        delete checkB[i]; // Освобождение памяти элемента
        delete editB[i];
        delete lineEd[i];
        delete delB[i];
    }
    cnt = 0;
}
