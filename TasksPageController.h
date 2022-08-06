#ifndef TASKSPAGECONTROLLER_H
#define TASKSPAGECONTROLLER_H

#include <QWidget>

class TasksPageController : public QWidget
{
    Q_OBJECT
public:
    TasksPageController(QWidget *parent = nullptr);
    void addTask(QString task_text);
};

#endif // TASKSPAGECONTROLLER_H
