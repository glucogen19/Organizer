#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

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
    void keyPressEvent(QKeyEvent *event);

    void on_pushButton_del_clicked();
    void crButton();

private:
    Ui::MainWindow *ui;
    QPushButton *mainButton;
};
#endif // MAINWINDOW_H
