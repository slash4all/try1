#ifndef TODOLIST_H
#define TODOLIST_H

#include <vector>
#include "task.h"

class ToDoList
{
public:
    ToDoList();
    ToDoList(QString owner);
    ~ToDoList(){
        schedule.clear();
    }

    Task createTask(QString title, QDate deadline, bool important=false);   // implementare le funzioni //forse da sostituire con il costruttore
    void checkTask(int taskNumber);
    void editTask(int taskNumber);
    void removeTask(int taskNumber);
    void addTask(Task task);

    void setOwner(QString owner);

    QString& getOwner();
    std::vector<Task>& getSchedule();

private:
    std::vector<Task> schedule;
    QString owner;
};

#endif // TODOLIST_H
