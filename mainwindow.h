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
    void keyPressEvent(QKeyEvent *event);
    void slotDel();
    void slotEdit();
    void slotCheck();
    void on_pushButton_clicked();
    void on_pushButton_del_clicked();
    void on_SaveFile_triggered();

    void on_OpenFile_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
