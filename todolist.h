#ifndef TODOLIST_H
#define TODOLIST_H

#include <vector>
#include "task.h"

//Classe che raccoglie l'elenco delle varie task

class ToDoList
{
public:
    ToDoList();
    ToDoList(QString owner);
    ~ToDoList(){
        schedule.clear();
    }

    Task createTask(QString title, QDate deadline, bool important=false);  //forse da sostituire con il costruttore
    void checkTask(int taskNumber);
    void editTask(int taskNumber);
    void cancelTask(int taskNumber);
    void removeTask(); //magari potremmo fare 2 metodi diversi per eliminare il task...
                                        //uno che gli passa l'indice e uno toglie l'ultima task!
    void addTask(const Task& task);

    //metodi setter/getter
    void setOwner(QString owner);
    QString& getOwner();
    std::vector<Task>& getSchedule();

private:
    std::vector<Task> schedule;
    QString owner;
};

#endif // TODOLIST_H
