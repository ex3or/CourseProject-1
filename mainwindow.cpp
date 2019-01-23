#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tchar.h"
#include "Windows.h"
#include "WinUser.h"
#include "math.h"
#include "tgmath.h"
#include "vector"
#include "iostream"
#include "complex"

const double pi=3.14159;

float IndexMatrix[4][4];
bool Imaginary;
long double det=0;
int rankQM=-1, rankIM=-1;
long double ceroot1=-1,ceroot2=-1,ceroot3=-1;
bool rootsoposits=false;

QString root1=" ",root2=" ",root3=" ";

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

int sgn(long double value)
{
    if (value<0) {return -1;}
    else if (value==0) {return 0;}
    else if (value>0) {return 1;}
}

void CharacteristicEquasion()
{

    if (rankQM==3)
    {

        long double a=0,b=0,c=0,d=0,f=0,q=0,r=0,s=0;
        float* A=&IndexMatrix[0][0];
        float* B=&IndexMatrix[1][1];
        float* C=&IndexMatrix[2][2];
        float* D=&IndexMatrix[0][1];
        float* E=&IndexMatrix[0][2];
        float* F=&IndexMatrix[1][2];

        root1=" ";
        root2=" ";
        root3 =" ";
        ceroot1=-1;
        ceroot2=-1;
        ceroot3=-1;


        d=1;
        a=-((*B)+(*C));
        b=((*C)+(*B)+(*B)*(*C)-pow((*E),2)-pow((*F),2)-pow((*D),2));
        c=-((*B)*(*C)+2*(*D)*(*F)*(*E)-(*B)*pow((*E),2)-pow((*F),2)-(*C)*pow((*D),2));

        q=(pow(a,2)-3*b)/9;
        r=(2*pow(a,3)-9*a*b+27*c)/54;
        s=pow(q,3)-pow(r,2);

        if (s>0)
        {
            f=acos(r/pow(q,1.5))/3;
            ceroot1=-2*sqrt(q)*cos(f)-a/3;
            ceroot2=-2*sqrt(q)*cos(f+2/3*pi)-a/3;
            ceroot3=-2*sqrt(q)*cos(f-2/3*pi)-a/3;

            root1=QString::number((float)ceroot1);
            root2=QString::number((float)ceroot2);
            root3=QString::number((float)ceroot3);

        } else
        if (s<0)
        {
            float complexpart1,complexpart2;

            if (q>0)
                        {
                            f=acosh(abs(r)/pow(abs(q),1.5))/3;
                            ceroot1=-2*sgn(r)*sqrt(q)*cosh(f)-a/3;
                            ceroot2=sgn(r)*sqrt(q)*cosh(f)-a/3;
                            ceroot3=ceroot2;
                            complexpart1=sqrt(3)*sqrt(abs(q))*sinh(f);
                            complexpart2=-complexpart1;

                            root1=QString::number((float)ceroot1);
                            root2=QString::number((float)ceroot2)+"+"+QString::number(complexpart1)+"i";
                            root3=QString::number((float)ceroot3)+"-"+QString::number(-complexpart2)+"i";
                        } else
                        if (q<0)
                        {
                            f=asinh(abs(r)/pow(abs(q),1.5))/3;
                            ceroot1=-2*sgn(r)*sqrt(abs(q))*sinh(f)-a/3;
                            ceroot2=sgn(r)*sqrt(abs(q))*sinh(f)-a/3;
                            ceroot3=ceroot2;

                            complexpart1=sqrt(3)*sqrt(abs(q))*cosh(f);
                            complexpart2=-complexpart1;

                            root1=QString::number((float)ceroot1);
                            root2=QString::number((float)ceroot2)+"+"+QString::number(complexpart1)+"i";
                            root3=QString::number((float)ceroot3)+"-"+QString::number(-complexpart2)+"i";
                        } else
                        if (q==0)
                        {
                            ceroot1=-pow((c-pow(a,3)/27),(1/3))-a/3;
                            ceroot2=-(a+ceroot1)/2;
                            ceroot3=ceroot2;

                            complexpart1=sqrt(abs((a-3*ceroot1)*(a+ceroot1)-4/b))/2;
                            complexpart2=-complexpart1;

                            root1=QString::number((float)ceroot1);
                            root2=QString::number((float)ceroot2)+"+"+QString::number(complexpart1)+"i";
                            root3=QString::number((float)ceroot3)+"-"+QString::number(-complexpart2)+"i";

                        }
        } else
        if (s==0)
        {
            ceroot1=-2*sgn(r)*sqrt(q)-a/3;
            ceroot2=sgn(r)*sqrt(q)-a/3;

            root1=QString::number((float)ceroot1);
            root2=QString::number((float)ceroot2);
        }






    }

}

float ExamineSurfaceType()
{
    float a[4][4];
    int type=0;
    double detp1=0, detp2=0, detp3=0, detp4=0;


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


    bool f=false;

    //Full Index Matrix rank

    if (det!=0) {rankIM=4;rankQM=3;} else
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
        if (rankIM!=4) {
        if ((a[0][0]*a[1][1]*a[2][2]+a[1][0]*a[2][1]*a[0][2]+a[0][1]*a[1][2]*a[2][0]-a[2][0]*a[1][1]*a[0][2]-a[0][0]*a[2][1]*a[1][2]-a[2][2]*a[1][0]*a[0][1])!=0) {rankQM=3;} else
        {
        f=false;
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
        }}

    }

    CharacteristicEquasion();





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

    QString FullMatrixDet = QString::number((float)det);
    ui->lblFullMatrixDet->setText("Определитель матрицы коэфф.: "+FullMatrixDet);
    QString FullMatrixRank = QString::number(rankIM);
    ui->lblFullMatrixRank->setText("Ранг матрицы коэффициентов: "+FullMatrixRank);
    QString QuadricFormMatrixRank = QString::number(rankQM);
    ui->lblQuadricFormMatrixRank->setText("Ранг матрицы квадрат. формы: "+QuadricFormMatrixRank);

    ui->lblCEroot1->setText(root1);
    ui->lblCEroot2->setText(root2);
    ui->lblCEroot3->setText(root3);

}
