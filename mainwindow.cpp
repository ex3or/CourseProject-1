#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tchar.h"
#include "Windows.h"
#include "WinUser.h"
#include "math.h"
#include "tgmath.h"
#include "vector"
#include "iostream"

float IndexMatrix[4][4];
bool Imaginary;



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnAppTerminate_clicked()
{
    exit(0);
}

void MainWindow::on_btnAppMinimize_clicked()
{
    // to add minimization functionality
}

float ExamineSurfaceType()
{
    float a[4][4];
    int type=0;
    float det=0, detp1=0, detp2=0, detp3=0, detp4=0;
    int rankIM=0,rankQM=0;

    for (int i=0; i<4; i++)
    {
        for (int j=0; j<4; j++)
        {
            a[i][j]=IndexMatrix[i][j];
        }
    }

    detp1=a[1][1]*a[2][2]*a[3][3]+a[2][1]*a[1][3]*a[3][2]+a[1][2]*a[2][3]*a[3][1]-a[3][1]*a[2][2]*a[1][3]-a[3][2]*a[2][3]*a[1][1]-a[2][1]*a[1][2]*a[3][3];
    detp2=a[1][0]*a[2][2]*a[3][3]+a[2][0]*a[3][2]*a[1][3]+a[1][2]*a[2][3]*a[3][0]-a[3][0]*a[2][2]*a[1][3]-a[2][0]*a[1][2]*a[3][3]-a[1][0]*a[3][2]*a[2][3];
    detp3=a[1][0]*a[2][1]*a[3][3]+a[2][0]*a[3][1]*a[1][3]+a[1][1]*a[2][3]*a[3][0]-a[3][0]*a[2][1]*a[1][3]-a[2][0]*a[1][1]*a[3][3]-a[3][1]*a[2][3]*a[1][0];
    detp4=a[1][0]*a[2][1]*a[3][3]+a[2][0]*a[3][1]*a[1][2]+a[1][1]*a[2][2]*a[3][0]-a[3][0]*a[2][1]*a[1][2]-a[3][1]*a[2][2]*a[1][0]-a[2][0]*a[1][1]*a[3][2];

    det=a[0][0]*detp1-a[0][1]*detp2+a[0][2]*detp3-a[0][3]*detp4;
    //det!=0 => ранг определителя IM 4

    return det;
}

void MainWindow::on_btnExamine_clicked()
{
    IndexMatrix[0][0]=ui->editX2->text().toFloat();
    IndexMatrix[1][1]=ui->editY2->text().toFloat();
    IndexMatrix[2][2]=ui->editZ2->text().toFloat();
    IndexMatrix[3][3]=ui->editD->text().toFloat();
    IndexMatrix[0][1]=ui->editXY->text().toFloat();
    IndexMatrix[1][0]=ui->editXY->text().toFloat();
    IndexMatrix[2][0]=ui->editXZ->text().toFloat();
    IndexMatrix[0][2]=ui->editXZ->text().toFloat();
    IndexMatrix[1][2]=ui->editYZ->text().toFloat();
    IndexMatrix[2][1]=ui->editYZ->text().toFloat();
    IndexMatrix[0][3]=ui->editX->text().toFloat();
    IndexMatrix[3][0]=ui->editX->text().toFloat();
    IndexMatrix[1][3]=ui->editY->text().toFloat();
    IndexMatrix[3][1]=ui->editY->text().toFloat();
    IndexMatrix[2][3]=ui->editZ->text().toFloat();
    IndexMatrix[3][2]=ui->editZ->text().toFloat();
    IndexMatrix[0][1]/=2.0;
    IndexMatrix[1][0]/=2.0;
    IndexMatrix[2][0]/=2.0;
    IndexMatrix[0][2]/=2.0;
    IndexMatrix[1][2]/=2.0;
    IndexMatrix[2][1]/=2.0;
    IndexMatrix[0][3]/=2.0;
    IndexMatrix[3][0]/=2.0;
    IndexMatrix[1][3]/=2.0;
    IndexMatrix[3][1]/=2.0;
    IndexMatrix[2][3]/=2.0;
    IndexMatrix[3][2]/=2.0;

    QString FullDet = QString::number(ExamineSurfaceType());
    ui->lblFullDeterminant->setText(FullDet);
}
