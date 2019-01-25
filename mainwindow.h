#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QOpenGLWidget>
#include <QtOpenGL>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:

    void on_btnExamine_clicked();

    void on_editX2_textChanged(const QString &arg1);

    void on_btnPreset1_clicked();

    void on_btnPreset2_clicked();

    void on_btnPreset3_clicked();

    void on_btnClear_clicked();

    void closeEvent(QCloseEvent *event);

    void MainWindow::mousePressEvent(QMouseEvent *event);

    void MainWindow::mouseReleaseEvent(QMouseEvent *event);

    void on_btnZoomIn_clicked();

    void on_btnZoomOut_clicked();

    void on_sliderOX_sliderMoved(int position);

    void on_sliderOY_sliderMoved(int position);

    void on_sliderOZ_sliderMoved(int position);

    void on_btnBuild_clicked();

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
