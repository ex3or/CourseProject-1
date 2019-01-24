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

    void on_editX2_textChanged(const QString &arg1);

    void on_btnPreset1_clicked();

    void on_btnPreset2_clicked();

    void on_btnPreset3_clicked();

    void on_btnClear_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
