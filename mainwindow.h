#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void on_btnAppTerminate_clicked();

    void on_btnAppMinimize_clicked();

    void on_btnExamine_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
