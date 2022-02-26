#include "task.h"

Task::Task()
{

}

Task::Task(QString title, QDate deadline, bool important)
{
    this->title = title;
    this->date = deadline;
    this->important = important;
}

void Task::setDescription(QString description)
{
    this->description = description;
}

void Task::setChecked(bool check)
{
    checked = check;
}

QString Task::getTitle()
{
    return title;
}

QDate Task::getDate()
{
    return date;
}

QString Task::getDescription()
{
    return description;
}

bool Task::getChecked()
{
    return checked;
}

bool Task::getImportant()
{
    return important;
}
