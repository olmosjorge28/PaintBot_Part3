#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>

#include <QtWidgets>
#include "coloritem.h"
#include "myserver.h"
#include "client.h"
#include "robot.h"
#include <math.h>
#include <QGraphicsView>
#include <QGraphicsScene>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    MyServer* server;
    SocketClient* client;
public:
    explicit MainWindow(QWidget *parent = 0, MyServer* server = 0, SocketClient* client = 0);
    volatile int link1_rotate_left();
    void link1_rotate_right();
    void link2_rotate_left();
    void link2_rotate_right();
    void link3_rotate_left();
    void link3_rotate_right();
    void plus_x();
    void minus_x();
    void plus_y();
    void minus_y();
    void drop_circle();
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void on_checkBox_toggled(bool checked);

    void on_checkBox_3_toggled(bool checked);

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    Robot *robot;
    //const QPen *pen;

protected:
    void paintEvent(QPaintEvent *);
};

#endif // MAINWINDOW_H
