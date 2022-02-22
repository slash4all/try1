#include "todolist.h"

ToDoList::ToDoList()
{

}

Task ToDoList::createTask(QString title, QDate deadline, bool important)
{
    Task newTask = Task(title, deadline, important);
    return newTask;
}

void ToDoList::addTask(Task task)
{

}

std::vector<Task> &ToDoList::getSchedule()
{
    return schedule;
}
