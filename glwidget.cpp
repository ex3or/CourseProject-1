#include "glwidget.h"

GLWidget::GLWidget(QWidget *parent) : QOpenGLWidget (parent)
{

}

void GLWidget::initializeGL()
{
    //glClearColor(0.8,0.8,0.8,1);
    //glEnable(GL_DEPTH_TEST);
    //glEnable(GL_LIGHT0);
    //glEnable(GL_LIGHTING);
    //glEnable(GL_COLOR_MATERIAL);
    //glOrtho(0,600,600,0,1,0);

}

void GLWidget::paintGL()
{
    //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //glMatrixMode(GL_MODELVIEW);
    //glLoadIdentity();

    //glColor3f(1,0,0);

    //glutSolidSphere(1,20,20);
    //glBegin(GL_POLYGON);
    //    glVertex2f(200,300);
    //    glVertex2f(400,100);
    //    glVertex2f(400,200);
    //glEnd;

}

void GLWidget::resizeGL(int w, int h)
{
    //float aspect=w/(float)h;

    //glViewport(0,0,w,h);
    //glMatrixMode(GL_PROJECTION);
    //glLoadIdentity();
    //gluPerspective(45.0,aspect,0.01,100);
}
