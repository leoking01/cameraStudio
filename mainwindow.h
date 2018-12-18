#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDateTime>


#include<iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;






namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

public:
    int  idCamera ;
    void  openCameraAndShow();


public:
//    Ui::Widget *ui;
//    cv::Mat image;
    void MainWindow::displayMat(Mat image) ;
};

#endif // MAINWINDOW_H
