#ifndef TASKS_H
#define TASKS_H

#include <vector>
#include <QString>

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
    Tasks();
    void addTask(QString task_title);
    void addTask(QString task_title, QString task_desc);
    QString getTasks();

private:
    std::vector<Task> tasks;
};

#endif // TASKS_H
