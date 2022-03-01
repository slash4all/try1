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
    for (auto task: todo.getSchedule()) {      // for ( int i = todo.getSchedule().size() - 1; i >= 0 ; i --) ???
        QListWidgetItem *item = new QListWidgetItem;
        if(task.getChecked()){
            QFont font = QFont();
//            font.setWeight(QFont::Bold);
            font.setStrikeOut(true);
//            ui->descriptionEdit->setFont(font);
            item->setFont(font);
            item->setCheckState(Qt::Checked);
        }
        else
            item->setCheckState(Qt::Unchecked);
        item->setText(QString(task.getDate().toString("dd.MM.yyyy") +"\t" + task.getTitle() + "\t"));
        if (task.getImportant()){
            item->setIcon(QIcon(path.absolutePath() + "/debug/img/imp_logo.png"));                // the absolute path is the one of build-try1-Desktop_Qt_6_2_3_MinGW_64_bit-Debug
        }                                                                                         // needed to add the img dir to the debug dir in that path
        ui->listWidget->addItem(item);
    }
    return;
}


void MainWindow::on_listWidget_itemClicked(QListWidgetItem *item)
{
    int index = ui->listWidget->indexFromItem(item).row();   // così prendo l'informazione dell'indice dall'oggetto che è cambiato
    Task &task = todo.getSchedule()[index];                  // e non dalla riga selezionata
    QFont font = QFont();
    if (item->checkState() == Qt::Checked){
        task.setChecked(true);                         // ma non è già settato a true??
        font.setStrikeOut(true);
    }
    else{
        task.setChecked(false);
        font.setStrikeOut(false);
    }
    ui->descriptionEdit->setFont(font);
    item->setFont(font);
    ui->descriptionEdit->setText(task.getDescription());
}

