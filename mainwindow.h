#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "CustomTitleBar.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_exitButton_clicked();
    void on_maximizeButton_clicked();

    void on_minimizeButton_clicked();

    void on_homeButton_clicked();

    void on_pushButton_5_clicked();

private:
    cTitlebar *m_title;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
