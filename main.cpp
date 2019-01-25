#include "mainwindow.h"
#include <QApplication>
#include <gl/freeglut.h>
#include <QOpenGLWidget>
#include <QtOpenGL>

extern int mainwindowpos_x,mainwindowpos_y;
extern int mainwindow_w,mainwindow_h;

extern int type;
extern float IndexMatrix[4][4];
double pi=3.14159265359;

float angle_x=0,angle_y=0,angle_z=0;
float scalemultiplier=1;

void initl()
{
    float light0_diffuse[] = {0.4, 0.7, 0.2};
    float light0_direction[] = {0.0, 0.0, 1.0, 0.0};
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_diffuse);
    glLightfv(GL_LIGHT0, GL_POSITION, light0_direction);
}

void reshape(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-120, 120, -120, 120, -100, 100);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


void draw()
{
    glColor3f(0,0,0);
    glLineWidth(5);
    glBegin(GL_LINES);
        glVertex3f(0,-100,5);
        glVertex3f(0,100,5);
        glVertex3f(100,0,5);
        glVertex3f(-100,0,5);
    glEnd();

}

void drawaxes()
{
    glLineWidth(1.5);
    glColor3f(1,0,0);
    glBegin(GL_LINES);
        glVertex3f(0,-1000*scalemultiplier,0);
        glVertex3f(0,1000*scalemultiplier,0);
    glEnd();
    glColor3f(0,0,1);
    glBegin(GL_LINES);
        glVertex3f(-1000*scalemultiplier,0,0);
        glVertex3f(1000*scalemultiplier,0,0);
    glEnd();
    glColor3f(0,1,0);
    glBegin(GL_LINES);
        glVertex3f(0,0,-1000*scalemultiplier);
        glVertex3f(0,0,1000*scalemultiplier);
    glEnd();
}

void drawsphere()
{
    glColor3f(0,0,0);
    glLineWidth(1);
    glBegin(GL_LINES);
        glVertex3f(0,0,50);
        glVertex3f(50,0,0);
        glVertex3f(50,5,0);
        glVertex3f(-50,5,0);
    glEnd();
}

void hyperboloid2()
{
    if (IndexMatrix[0][0]==1 && IndexMatrix[1][1]==2 && IndexMatrix[2][2]==3 && IndexMatrix[3][3]==100 && IndexMatrix[0][1]==-2 && IndexMatrix[0][2]==0 && IndexMatrix[1][2]==-2 && IndexMatrix[0][3]==0 && IndexMatrix[1][3]==0 && IndexMatrix[2][3]==0 && type==4)
    {
        glColor3f(0,0,0);
        glLineWidth(3);
        glBegin(GL_LINES);
            glVertex3f(-1000*2/3,-1000*2/3,-1000*1/3);
            glVertex3f(1000*2/3,1000*2/3,1000*1/3);

            glVertex3f(-1000*1/3,1000*2/3,-1000*2/3);
            glVertex3f(1000*1/3,-1000*2/3,1000*2/3);
        glEnd();
        glBegin(GL_LINES);
            glVertex3f(1000*2/3,-1000*1/3,-1000*2/3);
            glVertex3f(-1000*2/3,1000*1/3,1000*2/3);
        glEnd();
        glColor3f(0.4,0.4,0.4);
        glLineWidth(3.5);
        float x=0,y=0;
        float theta;
        float radius;
        float newx=0,newy=0,newz=0;
        for (float z=-5; z--; z>-20)
        {
            radius=sqrt(-100-3*z*z);
            glBegin(GL_LINE_LOOP);
            for(GLfloat a = 0.0f; a < 360.0f; a += 180) {
                theta = 2.0f * pi * a / 180.0f;
                x=radius*cos(theta);
                y=radius*sin(theta);
                glVertex3f((x*2/3+y*2/3+z*1/3),(x*1/3-y*2/3+z*2/3),(-x*2/3+y*1/3+z*2/3));
            }
            glEnd();
        }
        for (float z=5; z++; z<20)
        {
            radius=sqrt(-100+3*z*z);
            glBegin(GL_LINE_LOOP);
            for(GLfloat a = 0.0f; a < 360.0f; a += 180) {
                theta = 2.0f * pi * a / 180.0f;
                x=radius*cos(theta);
                y=radius*sin(theta);
                glVertex3f((x*2/3+y*2/3+z*1/3),(x*1/3-y*2/3+z*2/3),(-x*2/3+y*1/3+z*2/3));
            }
            glEnd();
        }




    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    initl();

        drawaxes();

    glFlush();

}

void updatedisplay()
{
    glRotatef(angle_x,1,0,0);
    glRotatef(angle_y,0,1,0);
    glRotatef(angle_z,0,0,1);
    display();

}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    w.setFocusPolicy(Qt::ClickFocus);


    mainwindowpos_x=w.geometry().topRight().x();
    mainwindowpos_y=w.geometry().topRight().y();
    mainwindow_w=w.geometry().size().width();
    mainwindow_h=w.geometry().size().height();


    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(650,720);
    glutInitWindowPosition(mainwindowpos_x+5,mainwindowpos_y-35);
    glutCreateWindow("Graph");
    glClearColor(.9,.9,.9,1.0);
    glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
    glEnable(GL_NORMALIZE);

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glRotatef(0,1,0,0);
    glRotatef(0,0,1,0);
    glRotatef(0,0,0,1);




    glutMainLoop();
    return a.exec();
}
