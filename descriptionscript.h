#ifndef DESCRIPTIONSCRIPT_H
#define DESCRIPTIONSCRIPT_H

#include <QDialog>
#include "todolist.h"

namespace Ui {
class DescriptionScript;
}

//Interfaccia per aggiungere una descrizione della task,
//inoltre deve essere possibile modifica data e nome della task! (TODO)

class DescriptionScript : public QDialog
{
    Q_OBJECT

public:
    explicit DescriptionScript(Task* task, QWidget *parent = nullptr); //excplit??
    ~DescriptionScript();


private slots:
    void on_buttonBox_accepted();

private:
    Ui::DescriptionScript *ui;
    Task* task; //puntatore o non puntatore?
};

#endif // DESCRIPTIONSCRIPT_H
