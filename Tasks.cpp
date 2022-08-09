#include "Tasks.h"

std::vector<Task> tasks;

Tasks::Tasks(QWidget * tasks_page_)
{
    tasks_page = tasks_page_;
    textInputWidget = tasks_page->findChild<QLineEdit *>("inputText");
    textLabelWidget = tasks_page->findChild<QLabel *>("tasksText");
}

// add a task to the vector
void Tasks::addTask() {
    Task task = Task(textInputWidget->text(), QString()); // add description handling soon!
    tasks.push_back(task);
    textInputWidget->clear();
}

// return list of tasks
void Tasks::displayTasks() {
    QString text;

       // consider fixing this compiler warning, though harmless for now
    for (int i = 0; i < tasks.size(); i++) {
        QString index = QString::fromStdString(std::to_string(i + 1)); // :)
        text += index + ". " + tasks[i].title + "\n";
    }

    textLabelWidget->setText(text);
}
