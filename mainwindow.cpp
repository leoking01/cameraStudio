#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTextDocument>

int  startTime_playingVideo =0;
int  idCamera_global;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    idCamera = 0;
    idCamera_global = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

//  set  id
void MainWindow::on_pushButton_2_clicked()
{
    QString   cont = ui->textEdit->toPlainText();
    int  id =  cont.toInt();
    idCamera = id;
    idCamera_global = idCamera ;

    ui->label->setStyleSheet("qproperty-alignment: 'AlignBottom | AlignLeft';");

    QLabel *pLabel = new QLabel(this);
    pLabel->setText("Hello World");
    pLabel->setStyleSheet("color: green");

    pLabel->setWordWrap(true);
    //"一去二三里，烟村四五家。亭台六七座，八九十枝花。"
    QString strText = QStringLiteral("1234567890  ");
    QString strHeightText = "<p style=\"line-height:%1%\">%2<p>";
    strText = strHeightText.arg(150).arg(strText);
    pLabel->setText(strText);
    ui->label->setText( QString("idCamera_global   = %1 \n").arg( idCamera_global) );
    //ui->label->getContentsMargins(); ;//"idCamera_global 2 ="   );

    QString  pre =  ui->textBrowser->toPlainText();
    ui->textBrowser->setText( pre+ QString("idCamera_global   = %1 \n").arg( idCamera_global) );
}

void MainWindow::displayMat(Mat image)
{
    Mat rgb;
    QImage img;
    if(image.channels()==3)
    {
        //cvt Mat BGR 2 QImage RGB
        cvtColor(image,rgb,CV_BGR2RGB);
        img =QImage((const unsigned char*)(rgb.data),
                    rgb.cols,rgb.rows,
                    rgb.cols*rgb.channels(),
                    QImage::Format_RGB888);
    }
    else
    {
        img =QImage((const unsigned char*)(image.data),
                    image.cols,image.rows,
                    image.cols*image.channels(),
                    QImage::Format_RGB888);
    }

    ui-> label->setPixmap(QPixmap::fromImage(img));
    ui-> label->resize(ui->label->pixmap()->size());
}



void  MainWindow::openCameraAndShow()
{
    VideoCapture cap( idCamera_global );


    Size sz1 = Size( 640,480  );

    cap.set(CV_CAP_PROP_FRAME_WIDTH,  1920  ) ;
    cap.set(CV_CAP_PROP_FRAME_HEIGHT,  1080 );

    Size size0=Size(cap.get(CV_CAP_PROP_FRAME_WIDTH),cap.get(CV_CAP_PROP_FRAME_HEIGHT));
    //    ui->label->setText( QString(" size0.width , size0.height  = %2, %2  ").arg( size0.width , size0.height  ) );
    QString  pre =  ui->textBrowser->toPlainText();
    ui->textBrowser->setText( pre+ QString(" size0.width , size0.height  = %1, %2  \n").arg( size0.width ).arg( size0.height  ) );


    //    cap.set(CV_CAP_PROP_FRAME_WIDTH,  800  ) ;
    //    cap.set(CV_CAP_PROP_FRAME_HEIGHT,  640 );


    QDateTime dtime = QDateTime::currentDateTime();
    int  currT =  dtime.toTime_t();
    startTime_playingVideo = currT;

    cout<<"size0 = "<< size0 <<  endl;
    char nameF[200];
    sprintf( nameF, "d:/record/%d.avi",  currT  );
    VideoWriter writer = VideoWriter(  nameF, CV_FOURCC('M','J','P','G'),10, sz1   ,true);

    //定义了一个写入视频的对象
//    CV_FOURCC('M','J','P','G')
//            CV_FOURCC('P','I','M','1')
//            VideoWriter writer("D:\\out.avi",CV_FOURCC('P','I','M','1'),15,size0,true);
//    VideoWriter writer("D:\\out.avi", CV_FOURCC('M','J','P','G'),10, sz1   ,true);
//    VideoWriter writer("D:\\out.avi",-1,15,size0,true);
//    cap.open("D:\\1.avi");

    if(!cap.isOpened())
    {
        cout<<"!cap.isOpened()"<<endl;
        return;
    }

    Mat frame;
    Mat imgShow;
    int id = 0;
    while(1){
        cap>>frame;
        if(frame.empty())
            continue;
        imgShow = frame;
        //cv:: resize(  frame,  imgShow, sz1  );


        displayMat(imgShow) ;


        imshow("imgShow",imgShow);
        char key = waitKey(20);
        if(  key==27   )
            break;
        if( key>0 &&  key!=  13  )
            break;
        if( key==13  )
        {
            char car[200];
            sprintf( car, "d:/record01/%d.jpg",  id  );
            imwrite(car,  frame  );
            id++;
        }
    }
    cout<<"Write endl"<<endl;
    cap.release();
    destroyAllWindows();
}


void MainWindow::on_pushButton_clicked()
{
    openCameraAndShow() ;
}
