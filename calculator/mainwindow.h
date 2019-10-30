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

private:
    Ui::MainWindow *ui;
private slots:
    void numbers();
    void on_pushButton_dot_clicked();
    void pm();
    void on_pushButton_ac_clicked();
    void on_pushButton_ravno_clicked();
    void operations();
};

#endif // MAINWINDOW_H
