#include "Tasks.h"

std::vector<Task> tasks;

Tasks::Tasks()
{

}

// add a task to vector
void Tasks::addTask(QString task_title) {
    Task task = Task(task_title, QString());
    tasks.push_back(task);
}

void Tasks::addTask(QString task_title, QString task_desc) {
    Task task = Task(task_title, task_desc);
    tasks.push_back(task);
}

// return list of tasks
QString Tasks::getTasks() {
    QString text;

    for (int i = 0; i < tasks.size(); i++) {
        QString index = QString::fromStdString(std::to_string(i + 1)); // :)
        text += index + ". " + tasks[i].title + "\n";
    }

    return text;
}
