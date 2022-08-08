#ifndef TASKS_H
#define TASKS_H

#include <QLineEdit>
#include <QString>
#include <QWidget>
#include <QLabel>
#include <vector>


struct Task {
    QString title;
    QString desc;

    // add maybe dates, time limits, prio, etc.

    Task(QString title_, QString desc_) {
        title = title_;
        desc = desc_;
    }
};

class Tasks
{
public:
    Tasks(QWidget * tasks_page_);
    void addTask();
    void displayTasks();

private:
    std::vector<Task> tasks;
    QWidget * tasks_page;
    QLineEdit * textInputWidget;
    QLabel * textLabelWidget;
};

#endif // TASKS_H
