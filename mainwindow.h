#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "CustomTitleBarWatcher.h"
#include "Tasks.h"

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

    void on_tasksButton_clicked();

    void on_addTaskButton_clicked();

private:
    cTitlebar *m_title;
    Ui::MainWindow *ui;
    Tasks *c_tasks;

};
#endif // MAINWINDOW_H
