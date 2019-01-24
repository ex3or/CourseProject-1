#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QOpenGLWidget>
#include <gl/freeglut.h>

class GLWidget : public QOpenGLWidget
{
    Q_OBJECT
public:
    explicit GLWidget(QWidget *parent = 0);

private:





protected:

    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);



};

#endif // GLWIDGET_H
