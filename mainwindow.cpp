#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "descriptiondialog.h"
#include "descriptionscript.h"
#include <QFont>
#include <QIcon>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("ToDo List");
    ui->dateEdit->setDate(QDate::currentDate());
    path = QDir::currentPath();
    //qDebug() << path;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_addBtn_clicked()
{
    // quando pigio il pulsante ADD creo subito una nuova task con i dati inseriti e poi vedo se viene scelto di aggiungere
    // una descrizione, nel qual caso verranno aggiunte informazioni alla task nel corpo dell'if

    currentTask = todo.createTask(ui->lineEdit->text(), ui->dateEdit->date(), ui->checkBox->isChecked()); //metodo che mi crea la task
    descriptionDialog* dd = new descriptionDialog(this);
    if(dd->exec() != 0){
        if(dd->getClicked() != true) //entrerò SOLO SE è stato premuto l'OK button
            createDescription();    //in quel caso potrò chiamare la funzione di createDescription
        todo.addTask(currentTask);
        updateToDo();
    }

}

void MainWindow::createDescription()
{
    DescriptionScript* ds = new DescriptionScript(&currentTask, this);
    ds->exec();
}

void MainWindow::updateToDo()
{
    ui->lineEdit->clear();
    ui->dateEdit->setDate(QDate::currentDate());
    ui->checkBox->setCheckState(Qt::Unchecked);
    ui->descriptionEdit->clear();
    ui->listWidget->clear(); //importante altrimenti ogni volta stamperei anche le task inserite precedentemente
    for (int i = 0; i < todo.getSchedule().size(); i++ ) {      // for ( int i = todo.getSchedule().size() - 1; i >= 0 ; i --) ???
        currentTask = todo.getSchedule()[i];
        QListWidgetItem *item = new QListWidgetItem;
        if(currentTask.getChecked())
            item->setCheckState(Qt::Checked);
        else
            item->setCheckState(Qt::Unchecked);
        item->setText(QString(currentTask.getDate().toString("dd.MM.yyyy") +"\t" + currentTask.getTitle() + "\t"));
        if (currentTask.getImportant()){
            item->setIcon(QIcon(path.absolutePath() + "/debug/img/imp_logo.png"));                // the absolute path is the one of build-try1-Desktop_Qt_6_2_3_MinGW_64_bit-Debug
        }                                                                                         // needed to add the img dir to the debug dir in that path
        ui->listWidget->addItem(item);
    }
    return;
}

void MainWindow::on_listWidget_itemClicked(QListWidgetItem *item)
{
    int index = ui->listWidget->currentRow(); //come mai parte da -1??
    if (index < 0)
        index = lastRow;
    currentTask = todo.getSchedule()[index];
    QFont font = QFont();
    if (item->checkState() == Qt::Checked){
        currentTask.setChecked(true); //ma non è già settato a true??
        font.setStrikeOut(true);
    }
    else{
        currentTask.setChecked(false);
        font.setStrikeOut(false);
    }
    ui->descriptionEdit->setFont(font);
    item->setFont(font);
    ui->descriptionEdit->setText(currentTask.getDescription());
}

