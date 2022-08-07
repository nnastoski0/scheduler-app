#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRect>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //creates the custom title bar and adds it to a layout along the top of the screen
    m_title = new cTitlebar(this);
    ui->titlebar_layout->addWidget(m_title);

    //adds icons to buttons
    ui->homeButton->setIcon(QIcon(":/Resources/Icons/home.png"));

    // instantiate tasks controller & pass tasks page in
    c_tasks = new Tasks(ui->stackedWidget->widget(1));

    //Adds icon to resize button
    ui->maximizeButton->setCheckable(true);
    ui->maximizeButton->setIcon(QIcon(":/Resources/Icons/resize.png"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

//exit button clicked handler
void MainWindow::on_exitButton_clicked()
{
    this->close();
}

//maximize button clicked handler
void MainWindow::on_maximizeButton_clicked()
{
    if(this->isFullScreen()){
        this->showNormal();
        ui->maximizeButton->setIcon(QIcon(":/Resources/Icons/resize.png"));
    }
    else{
        this->showFullScreen();
        ui->maximizeButton->setIcon(QIcon(":/Resources/Icons/compress.png"));
    }

}

//minimize button clicked handler
void MainWindow::on_minimizeButton_clicked()
{
    this->showMinimized();
}

// stacked widget page switch handler
void MainWindow::on_homeButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_tasksButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}
//


// tasks button handler
void MainWindow::on_addTaskButton_clicked()
{
    c_tasks->addTask();
    c_tasks->displayTasks();
}

