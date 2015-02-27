#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTcpSocket>
#include <QTimer>
#include <QDebug>

int right_val = 0;
int left_val = 0;

QTcpSocket socket;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->stop,SIGNAL(clicked()),this,SLOT(stop()));
    connect(ui->tele_op,SIGNAL(clicked()),this,SLOT(tele_op()));
    connect(ui->semi_auto,SIGNAL(clicked()),this,SLOT(semi_auto()));
    connect(ui->full_auto,SIGNAL(clicked()),this,SLOT(full_auto()));

    socket.connectToHost("35.2.95.129",3141);

    if (!socket.waitForConnected()){
        qDebug()<< "Unable to Connect";
    }

    QTimer*timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(update()));
    timer->start(1000);


}

void MainWindow::keyPressEvent(QKeyEvent *e){
    //Turn Right
    if (e->key()==Qt::Key_Right){
        left_val = 100;
        right_val = -100;
    }
    //Turn Left
    if (e->key()==Qt::Key_Left) {
        left_val = -100;
        right_val = 100;
    }
    //Forward
    if (e->key()==Qt::Key_Up){
        left_val = 100;
        right_val = 100;
    }
    //Backward
    if (e->key()==Qt::Key_Down){
        left_val = -100;
        right_val = -100;
    }
}

void MainWindow::keyReleaseEvent(QKeyEvent *e){
    left_val = 0;
    right_val = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::update(){

   dataTest.SetLeftJoystick(left_val);
   dataTest.SetRightJoystick(right_val);

   showNormal();
   raise();
   activateWindow();
   setFocus();

   socket.write(dataTest.ToByteArray());
   socket.flush();
}

void MainWindow::stop(){
    dataTest.SetRunMode(STOP);
}

void MainWindow::tele_op(){
    dataTest.SetRunMode(TELE_OP);

}

void MainWindow::semi_auto(){
    dataTest.SetRunMode(SEMI_AUTO);
}

void MainWindow::full_auto(){
    dataTest.SetRunMode(FULL_AUTO);
}
