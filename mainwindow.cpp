#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "studialog.h"
#include "teadialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(1000,640);
    ui->stuButton->setGeometry(200,300,100,50);
    ui->teaButton->setGeometry(700,300,100,50);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_stuButton_clicked()
{
    StuDialog* studialog=new StuDialog(this);
    studialog->show();
}


void MainWindow::on_teaButton_clicked()
{
    TeaDialog* teadialog=new TeaDialog(this);
    teadialog->show();
}

