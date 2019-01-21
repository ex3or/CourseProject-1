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
float det=0;
int rankQM=0, rankIM=0;


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
    float detp1=0, detp2=0, detp3=0, detp4=0;


    rankQM=0;
    rankIM=0;
    det=0;

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

    bool f=false;

    //Full Index Matrix rank

    if (det!=0) {rankIM=4;} else
    {

        for (int i=0; i<4; i++)
        {
            for (int j=0; j<4; j++)
            {
                if (a[i][j]!=0) {rankIM=1;f=true; break;}
            }
            if (f) {break;}
        }
        if (f)
        {
            f=false;

            for (int i1=0; i1<3; i1++)
            {
                for (int i2=0; i2<3; i2++)
                {
                    for (int i3=i1+1; i3<4; i3++)
                    {
                        for (int i4=i2+1; i4<4; i4++)
                        {
                            if ((a[i1][i2]*a[i3][i4]-a[i3][i1]*a[i1][i4])!=0) {rankIM=2; f=true; break;}
                        }
                        if (f) {break;}
                    }
                    if (f) {break;}
                }
            }
        }
        if (f)
        {
            f=false;


            for (int i1=0; i1<4; i1++)
            {
                for (int i2=0; i2<4; i2++)
                {
                    for (int i3=i1+1; i3<4; i3++)
                    {
                        for (int i4=i2+1; i4<4; i4++)
                        {
                            for (int i5=i3+1; i5<4; i5++)
                            {
                                for (int i6=i4+1; i6<4; i6++)
                                {
                                    if ((a[i1][i2]*a[i3][i4]*a[i5][i6]+a[i3][i2]*a[i5][i4]*a[i1][i6]+a[i1][i4]*a[i3][i6]*a[i5][i2]-a[i5][i2]*a[i3][i4]*a[i1][i6]-a[i5][i4]*a[i3][i6]*a[i1][i2]-a[i3][i2]*a[i1][i4]*a[i5][i6])!=0) {rankIM=3; f=true; break;
                                    }
                                }
                                if (f) {break;}
                            }
                            if (f) {break;}
                        }
                        if (f) {break;}
                    }
                    if (f) {break;}
                }
                if (f) {break;}
            }
        }

        //Quadric matrix rank

        if ((a[0][0]*a[1][1]*a[2][2]+a[1][0]*a[2][1]*a[0][2]+a[0][1]*a[1][2]*a[2][0]-a[2][0]*a[1][1]*a[0][2]-a[0][0]*a[2][1]*a[1][2]-a[2][2]*a[1][0]*a[0][1])!=0) {rankQM=3;} else
        {

        for (int i=0; i<3; i++)
        {
            for (int j=0; j<3; j++)
            {
                if (a[i][j]!=0) {rankQM=1;f=true; break;}
            }
            if (f) {break;}
        }
        if (f)
        {
            f=false;

            for (int i1=0; i1<2; i1++)
            {
                for (int i2=0; i2<2; i2++)
                {
                    for (int i3=i1+1; i3<3; i3++)
                    {
                        for (int i4=i2+1; i4<3; i4++)
                        {
                            if ((a[i1][i2]*a[i3][i4]-a[i3][i1]*a[i1][i4])!=0) {rankQM=2; f=true; break;}
                        }
                        if (f) {break;}
                    }
                    if (f) {break;}
                }
            }
        }
        }

    }

    switch ()







    return type;
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

    ExamineSurfaceType();

    QString FullMatrixDet = QString::number(det);
    ui->lblFullMatrixDet->setText("Определитель матрицы коэфф.: "+FullMatrixDet);
    QString FullMatrixRank = QString::number(rankIM);
    ui->lblFullMatrixRank->setText("Ранг матрицы коэффициентов: "+FullMatrixRank);
    QString QuadricFormMatrixRank = QString::number(rankQM);
    ui->lblQuadricFormMatrixRank->setText("Ранг матрицы квадрат. формы: "+QuadricFormMatrixRank);
}
