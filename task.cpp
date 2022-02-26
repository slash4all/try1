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

QString Task::getTitle()
{
    return title;
}

QDate Task::getDate()
{
    return date;
}

bool Task::getImportant()
{
    return important;
}
