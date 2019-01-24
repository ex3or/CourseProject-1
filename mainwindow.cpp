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
#include "cctype"

const double pi=3.14159265359;

float IndexMatrix[4][4];

double det=0;
int rankQM=-1, rankIM=-1;
double ceroot1=-1,ceroot2=-1,ceroot3=-1;
bool rootsopositsigns=false;
bool imaginary=false;


QString root1=" ",root2=" ",root3=" ",ftype="";

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lblStatus->setText("Статус: Инициализация..");
    ui->lblStatus->setText("Статус: Ожидание ввода данных..");
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

int sgn(double value)
{
    if (value<0) {return -1;}
    else if (value==0) {return 0;}
    else if (value>0) {return 1;}
}



void CharacteristicEquasion()
{

    float* A=&IndexMatrix[0][0];
    float* B=&IndexMatrix[1][1];
    float* C=&IndexMatrix[2][2];
    float* D=&IndexMatrix[0][1];
    float* E=&IndexMatrix[0][2];
    float* F=&IndexMatrix[1][2];

    imaginary=false;

    if (rankQM==3) // Cubic equasion solving
    {

        double a=0,b=0,c=0,d=0,f=0,q=0,r=0,s=0;

        d=1;
        a=-((*A)+(*B)+(*C));
        b=((*A)*(*C)+(*B)*(*A)+(*B)*(*C)-pow((*E),2)-pow((*F),2)-pow((*D),2));
        c=-((*A)*(*B)*(*C)+2*(*D)*(*F)*(*E)-(*B)*pow((*E),2)-(*A)*pow((*F),2)-(*C)*pow((*D),2));

        q=(pow(a,2)-3*b)/9;
        r=(2*pow(a,3)-9*a*b+27*c)/54;
        s=pow(q,3)-pow(r,2);

        root1=" ";
        root2=" ";
        root3 =" ";
        ceroot1=-1;
        ceroot2=-1;
        ceroot3=-1;

        if (s>0)
        {

            f=acos(r/pow(q,1.5))/3;
            ceroot1=-2*sqrt(q)*cos(f)-a/3;
            ceroot2=-2*sqrt(q)*cos(f+(2*pi/3))-a/3;
            ceroot3=-2*sqrt(q)*cos(f-(2*pi/3))-a/3;


            root1=QString::number((float)ceroot1);
            root2=QString::number((float)ceroot2);
            root3=QString::number((float)ceroot3);

        } else
        if (s<0)
        {
            double complexpart1,complexpart2;

            if (q>0)
                        {
                            f=acosh(abs(r)/pow(abs(q),1.5))/3;
                            ceroot1=-2*sgn(r)*sqrt(q)*cosh(f)-a/3;
                            ceroot2=sgn(r)*sqrt(q)*cosh(f)-a/3;
                            ceroot3=ceroot2;


                            complexpart1=sqrt(3)*sqrt(abs(q))*sinh(f);
                            complexpart2=-complexpart1;

                            root1=QString::number(ceroot1);
                            root2=QString::number(ceroot2)+"+"+QString::number(complexpart1)+"i";
                            root3=QString::number(ceroot3)+"-"+QString::number(-complexpart2)+"i";
                            imaginary=true;
                        } else
                        if (q<0)
                        {
                            f=asinh(abs(r)/pow(abs(q),1.5))/3;
                            ceroot1=-2*sgn(r)*sqrt(abs(q))*sinh(f)-a/3;
                            ceroot2=sgn(r)*sqrt(abs(q))*sinh(f)-a/3;
                            ceroot3=ceroot2;

                            complexpart1=sqrt(3)*sqrt(abs(q))*cosh(f);
                            complexpart2=-complexpart1;

                            root1=QString::number(ceroot1);
                            root2=QString::number(ceroot2)+"+"+QString::number(complexpart1)+"i";
                            root3=QString::number(ceroot3)+"-"+QString::number(-complexpart2)+"i";
                            imaginary=true;
                        } else
                        if (q==0)
                        {
                            ceroot1=-pow((c-pow(a,3)/27),(1/3))-a/3;
                            ceroot2=-(a+ceroot1)/2;
                            ceroot3=ceroot2;

                            complexpart1=sqrt(abs((a-3*ceroot1)*(a+ceroot1)-4/b))/2;
                            complexpart2=-complexpart1;

                            root1=QString::number(ceroot1);
                            root2=QString::number(ceroot2)+"+"+QString::number(complexpart1)+"i";
                            root3=QString::number(ceroot3)+"-"+QString::number(-complexpart2)+"i";
                            imaginary=true;

                        }
        } else
        if (s==0)
        {
            ceroot1=-2*sgn(r)*sqrt(q)-a/3;
            ceroot2=sgn(r)*sqrt(q)-a/3;
            ceroot3=ceroot2;
            root1=QString::number(ceroot1);
            root2=QString::number(ceroot2);
            root3=QString::number(ceroot3);
        }




    } else
    if (rankQM==2) //Quadric equasion solving
    {
        float d=0,b=0,c=0;

        ceroot1=0;
        root1=QString::number((float)ceroot1);
        if ((*A)!=0 && (*B)!=0 && (*C)!=0){

            //
            //
            //

            double a=0,b=0,c=0,d=0,f=0,q=0,r=0,s=0;

            d=1;
            a=-((*A)+(*B)+(*C));
            b=((*A)*(*C)+(*B)*(*A)+(*B)*(*C)-pow((*E),2)-pow((*F),2)-pow((*D),2));
            c=-((*A)*(*B)*(*C)+2*(*D)*(*F)*(*E)-(*B)*pow((*E),2)-(*A)*pow((*F),2)-(*C)*pow((*D),2));

            q=(pow(a,2)-3*b)/9;
            r=(2*pow(a,3)-9*a*b+27*c)/54;
            s=pow(q,3)-pow(r,2);

            root1=" ";
            root2=" ";
            root3 =" ";
            ceroot1=-1;
            ceroot2=-1;
            ceroot3=-1;

            if (s>0)
            {

                f=acos(r/pow(q,1.5))/3;
                ceroot1=-2*sqrt(q)*cos(f)-a/3;
                ceroot2=-2*sqrt(q)*cos(f+(2*pi/3))-a/3;
                ceroot3=-2*sqrt(q)*cos(f-(2*pi/3))-a/3;


                root1=QString::number((float)ceroot1);
                root2=QString::number((float)ceroot2);
                root3=QString::number((float)ceroot3);

            } else
            if (s<0)
            {
                double complexpart1,complexpart2;

                if (q>0)
                            {
                                f=acosh(abs(r)/pow(abs(q),1.5))/3;
                                ceroot1=-2*sgn(r)*sqrt(q)*cosh(f)-a/3;
                                ceroot2=sgn(r)*sqrt(q)*cosh(f)-a/3;
                                ceroot3=ceroot2;


                                complexpart1=sqrt(3)*sqrt(abs(q))*sinh(f);
                                complexpart2=-complexpart1;

                                root1=QString::number(ceroot1);
                                root2=QString::number(ceroot2)+"+"+QString::number(complexpart1)+"i";
                                root3=QString::number(ceroot3)+"-"+QString::number(-complexpart2)+"i";
                                imaginary=true;
                            } else
                            if (q<0)
                            {
                                f=asinh(abs(r)/pow(abs(q),1.5))/3;
                                ceroot1=-2*sgn(r)*sqrt(abs(q))*sinh(f)-a/3;
                                ceroot2=sgn(r)*sqrt(abs(q))*sinh(f)-a/3;
                                ceroot3=ceroot2;

                                complexpart1=sqrt(3)*sqrt(abs(q))*cosh(f);
                                complexpart2=-complexpart1;

                                root1=QString::number(ceroot1);
                                root2=QString::number(ceroot2)+"+"+QString::number(complexpart1)+"i";
                                root3=QString::number(ceroot3)+"-"+QString::number(-complexpart2)+"i";
                                imaginary=true;
                            } else
                            if (q==0)
                            {
                                ceroot1=-pow((c-pow(a,3)/27),(1/3))-a/3;
                                ceroot2=-(a+ceroot1)/2;
                                ceroot3=ceroot2;

                                complexpart1=sqrt(abs((a-3*ceroot1)*(a+ceroot1)-4/b))/2;
                                complexpart2=-complexpart1;

                                root1=QString::number(ceroot1);
                                root2=QString::number(ceroot2)+"+"+QString::number(complexpart1)+"i";
                                root3=QString::number(ceroot3)+"-"+QString::number(-complexpart2)+"i";
                                imaginary=true;

                            }
            } else
            if (s==0)
            {
                ceroot1=-2*sgn(r)*sqrt(q)-a/3;
                ceroot2=sgn(r)*sqrt(q)-a/3;
                ceroot3=ceroot2;
                root1=QString::number(ceroot1);
                root2=QString::number(ceroot2);
                root3=QString::number(ceroot3);
            }


            //
            //
            //

        } else
        {
        if ((*A)==0)
        {
            b=-((*B)+(*C));
            c=-(pow((*F),2)-(*B)*(*C));
        } else
        if ((*B)==0)
        {
            b=-((*A)+(*C));
            c=-(pow((*E),2)-(*A)*(*C));
        } if ((*C)==0)
        {
            b=-((*B)+(*A));
            c=-(pow((*D),2)-(*B)*(*A));
        }

        d=pow(b,2)-4*c;
        if (d>=0)
        {
            ceroot2=(-b+sqrt(d))/2;
            ceroot3=(-b-sqrt(d))/2;

            root2=QString::number((float)ceroot2);
            root3=QString::number((float)ceroot3);

        } else
        if (d<0)
        {
            ceroot2=-b/2;
            ceroot3=-b/2;
            root2=QString::number((float)ceroot2)+"+"+(sqrt(-d)/2);
            root2=QString::number((float)ceroot2)+"-"+(sqrt(-d)/2);
            imaginary=true;
        }
        }
    } else
    if (rankQM==1) // In case if
    {
        ceroot1=0;
        ceroot2=0;
        if ((*A)!=0)
        {
            ceroot3=(*A);
        } else
        if ((*B)!=0)
        {
            ceroot3=(*B);
        } else
        if ((*C!=0))
        {
            ceroot3=(*C);
        }
    }


}

float ExamineSurfaceType()
{
    float a[4][4];
    int type=0;
    double detp1=0, detp2=0, detp3=0, detp4=0;

    rootsopositsigns=false;
    rankQM=-1;
    rankIM=-1;
    det=0;

    for (int i=0; i<4; i++)
    {
        for (int j=0; j<4; j++)
        {
            a[i][j]=IndexMatrix[i][j];
        }
    }
    // Determinant
    detp1=a[1][1]*a[2][2]*a[3][3]+a[2][1]*a[1][3]*a[3][2]+a[1][2]*a[2][3]*a[3][1]-a[3][1]*a[2][2]*a[1][3]-a[3][2]*a[2][3]*a[1][1]-a[2][1]*a[1][2]*a[3][3];
    detp2=a[1][0]*a[2][2]*a[3][3]+a[2][0]*a[3][2]*a[1][3]+a[1][2]*a[2][3]*a[3][0]-a[3][0]*a[2][2]*a[1][3]-a[2][0]*a[1][2]*a[3][3]-a[1][0]*a[3][2]*a[2][3];
    detp3=a[1][0]*a[2][1]*a[3][3]+a[2][0]*a[3][1]*a[1][3]+a[1][1]*a[2][3]*a[3][0]-a[3][0]*a[2][1]*a[1][3]-a[2][0]*a[1][1]*a[3][3]-a[3][1]*a[2][3]*a[1][0];
    detp4=a[1][0]*a[2][1]*a[3][3]+a[2][0]*a[3][1]*a[1][2]+a[1][1]*a[2][2]*a[3][0]-a[3][0]*a[2][1]*a[1][2]-a[3][1]*a[2][2]*a[1][0]-a[2][0]*a[1][1]*a[3][2];

    det=a[0][0]*detp1-a[0][1]*detp2+a[0][2]*detp3-a[0][3]*detp4;


    bool f=false;

    // Index Matrix rank

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
    }
        //Quadric matrix rank
        float mindet=0;
        mindet=(a[0][0]*a[1][1]*a[2][2]+a[1][0]*a[2][1]*a[0][2]+a[0][1]*a[1][2]*a[2][0]-a[2][0]*a[1][1]*a[0][2]-a[0][0]*a[2][1]*a[1][2]-a[2][2]*a[1][0]*a[0][1]);
        if (mindet!=0) {rankQM=3;} else
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
        }



    CharacteristicEquasion();
    if (ceroot1*ceroot2<0 || ceroot2*ceroot3<0 || ceroot1*ceroot3<0) {rootsopositsigns=true;} else {rootsopositsigns=false;}


    switch (rankQM)
    {
        case 3:
        {
            if (rankIM==4)
            {
                if (ceroot1==ceroot2 && ceroot1==ceroot3){type=0; ftype="Сфера";} else
                if (rootsopositsigns==false)
                {
                    if (det<0) {type=1; ftype="Эллипсоид";} else
                    if (det>0) {type=2; ftype="Мнимый эллипсоид";}
                } else
                if (rootsopositsigns==true){
                    if (det>0) {type=3; ftype="Однополостный гиперболоид";} else
                    if (det<0) {type=4; ftype="Двухполостный гиперболоид";}
                }

            } else
            if (rankIM==3)
            {
                if (rootsopositsigns==true) {type=5; ftype="Коническая поверхность";} else
                if (rootsopositsigns==false) {type=6; ftype="Мнимая коническая поверхность";}
            }
            break;
        }
        case 2:
        {
            if (rankIM==4)
            {
                if (rootsopositsigns==false && det<0) {type=7; ftype="Эллиптический параболоид";} else
                if (rootsopositsigns==true && det>0) {type=8; ftype="Гиперболический параболоид";}
            } else
            if (rankIM==3)
            {
                if (rootsopositsigns==false) {if (imaginary==false) {type=9; ftype="Эллиптический цилиндр";} else {type=10; ftype="Мнимый эллиптический цилиндр";}} else
                if (rootsopositsigns==true) {type=11; ftype="Гиперболический цилиндр";}
            } else
            if (rankIM==2)
            {
                if (rootsopositsigns==true) {type=12; ftype="Пересикающиеся плоскости";} else
                if (rootsopositsigns==false) {type=13; ftype="Мнимые пересекающиеся плоскости";}
            }
            break;
        }
        case 1:
        {
            if (rankIM==3)
            {
                type=14;
                ftype="Параболический цилиндр";
            } else
            if (rankIM==2)
            {
                if (imaginary=false){type=15;ftype="Параллельные плоскости";} else {type=16; ftype="Мнимые параллельные плоскости";}
            } else
            if (rankIM==1)
            {
                type=17;
                ftype="Совпадаюшие плоскости";
            }
            break;
        }
    default:{break;}
    }



    return type;
}

void OpenGLInit()
{

}

void BuildSurface()
{



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

    ui->lblStatus->setText("Статус: Обработка данных..");

    ExamineSurfaceType();
    OpenGLInit();

    ui->lblStatus->setText("Статус: Ожидание действия..");

    QString FullMatrixDet = QString::number((float)det);
    ui->lblFullMatrixDet->setText("Определитель матрицы коэфф.: "+FullMatrixDet);
    QString FullMatrixRank = QString::number(rankIM);
    ui->lblFullMatrixRank->setText("Ранг матрицы коэффициентов: "+FullMatrixRank);
    QString QuadricFormMatrixRank = QString::number(rankQM);
    ui->lblQuadricFormMatrixRank->setText("Ранг матрицы квадрат. формы: "+QuadricFormMatrixRank);

    ui->lblSurfaceName->setText("Поверхность: "+ftype);

    ui->lblCEroot1->setText(root1);
    ui->lblCEroot2->setText(root2);
    ui->lblCEroot3->setText(root3);
    BuildSurface();

}

void MainWindow::on_editX2_textChanged(const QString &arg1)
{
    //editinput limitation
}

void MainWindow::on_btnPreset1_clicked()
{
    ui->editX2->setText("1");
    ui->editY2->setText("2");
    ui->editZ2->setText("3");
    ui->editXY->setText("-4");
    ui->editXZ->setText("0");
    ui->editYZ->setText("-4");
    ui->editX->setText("0");
    ui->editY->setText("0");
    ui->editZ->setText("0");
    ui->editD->setText("100");
}

void MainWindow::on_btnPreset2_clicked()
{
    ui->editX2->setText("5");
    ui->editY2->setText("5");
    ui->editZ2->setText("5");
    ui->editXY->setText("0");
    ui->editXZ->setText("0");
    ui->editYZ->setText("0");
    ui->editX->setText("1");
    ui->editY->setText("2");
    ui->editZ->setText("3");
    ui->editD->setText("100");
}

void MainWindow::on_btnPreset3_clicked()
{
    ui->editX2->setText("2");
    ui->editY2->setText("2");
    ui->editZ2->setText("3");
    ui->editXY->setText("4");
    ui->editXZ->setText("2");
    ui->editYZ->setText("2");
    ui->editX->setText("-4");
    ui->editY->setText("6");
    ui->editZ->setText("-2");
    ui->editD->setText("3");
}

void MainWindow::on_btnClear_clicked()
{
    ui->editX2->setText("");
    ui->editY2->setText("");
    ui->editZ2->setText("");
    ui->editXY->setText("");
    ui->editXZ->setText("");
    ui->editYZ->setText("");
    ui->editX->setText("");
    ui->editY->setText("");
    ui->editZ->setText("");
    ui->editD->setText("");
    ui->lblCEroot1->setText("");
    ui->lblCEroot2->setText("");
    ui->lblCEroot3->setText("");
    ui->lblFullMatrixDet->setText("Определитель матрицы коэфф.: ");
    ui->lblQuadricFormMatrixRank->setText("Ранг матрицы квадрат. формы: ");
    ui->lblFullMatrixRank->setText("Ранг матрицы коэффициентов: ");
    ui->lblSurfaceName->setText("Поверхность: ");
    ui->lblStatus->setText("Статус: Ожидание ввода данных..");

}
