#include "mainwindow.h"
#include "screenmovewatcher.h"
#include "ui_mainwindow.h"
#include <QRect>
#include "screenmovewatcher.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //creates the custom title bar move handler and adds it to a layout along the top of the screen
    m_title = new cTitlebar(this);
    ui->titlebar_layout->addWidget(m_title);

    //adds icons to buttons
    ui->homeButton->setIcon(QIcon(":/Resources/Icons/home.png"));
    ui->exitButton->setIcon(QIcon(":/Resources/Icons/multiply.svg"));
    ui->minimizeButton->setIcon(QIcon(":/Resources/Icons/minus.svg"));

    // ensure calendar page is default on app startup
    ui->stackedWidget->setCurrentIndex(0); // 0 is first index, calendar page

    // instantiate tasks controller & pass tasks page in
    c_tasks = new Tasks(ui->stackedWidget->widget(1));
    //connects the return key pressed signal to the add task button clicked signal to add a task when you press the enter key
    connect(ui->inputText,SIGNAL(returnPressed()),ui->addTaskButton,SIGNAL(clicked()));

    //Adds icon to resize button
    ScreenMoveWatcher *maxButWatcher = new ScreenMoveWatcher(this);
    ui->maximizeButton->setCheckable(true);
    ui->maximizeButton->setIcon(QIcon(":/Resources/Icons/expand-arrows.svg"));
    ui->maximizeButton->installEventFilter(maxButWatcher);

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
        ui->maximizeButton->setIcon(QIcon(":/Resources/Icons/expand-arrows.svg"));
    }
    else{
        this->showFullScreen();
        ui->maximizeButton->setIcon(QIcon(":/Resources/Icons/compress-arrows.svg"));
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

