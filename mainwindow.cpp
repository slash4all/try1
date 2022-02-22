#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "descriptiondialog.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("ToDo List");
    ui->dateEdit->setDate(QDate::currentDate());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_addBtn_clicked()
{
    // quando pigio il pulsante ADD creo subito una nuova task con i dati inseriti e poi vedo se viene scelto di aggiungere
    // una descrizione, nel qual caso verranno aggiunte informazioni alla task nel corpo dell'if

    Task newTask = todo.createTask(ui->lineEdit->text(), ui->dateEdit->date(), ui->checkBox->isChecked());
    descriptionDialog* dd = new descriptionDialog();
    dd->show();
    connect(dd, SIGNAL(accepted()), this, SLOT(addDescription()));
    if(dd->exec() != 0){
        // TODO creare metodo addDescription()
    }

    todo.addTask(newTask);
    updateToDo();
}

void MainWindow::updateToDo()
{
    ui->listWidget->clear();
    for (int i = 0; i < todo.getSchedule().size(); i++ ) {
        // TODO aggiungere ogni task alla lista
    }
    return;
}
