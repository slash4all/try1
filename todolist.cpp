#include "todolist.h"

ToDoList::ToDoList()
{

}

Task ToDoList::createTask(QString title, QDate deadline, bool important)
{
    Task newTask = Task(title, deadline, important);
    return newTask; //ritorna l'indice del task... ma non andrebbe aggiunto al vettore?? (ah deleghi a dopo il tutto... ok!)
}

void ToDoList::addTask(const Task& task)
{
    schedule.push_back(task); //la task sarà inserita in ultima posizione??
}
void ToDoList::removeTask(){
    //metodo in cui elimino l'ultima task inserita
    schedule.pop_back();
}

std::vector<Task> &ToDoList::getSchedule()
{
    return schedule;
}

void checkTask(int taskNumber){ //TODO: Capire come ottenere il numero del task su cui fare il check
    //more code here...

}

void editTask(int taskNumber){ //TODO: Stesso discorso del metodo check
    //more code here...
}

void cancelTask(int taskNumber){ //TODO: Uguale ai 2 sopra
    //more code here...
}
