#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "descriptiondialog.h"
#include "descriptionscript.h"
#include <QFont>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
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

    currentTask = todo.createTask(ui->lineEdit->text(), ui->dateEdit->date(), ui->checkBox->isChecked());
    descriptionDialog* dd = new descriptionDialog(this);
    if(dd->exec() != 0){
        createDescription();
    }
    todo.addTask(currentTask);
    updateToDo();
}

void MainWindow::createDescription()
{
    DescriptionScript* ds = new DescriptionScript(&currentTask, this);
    ds->exec();
}

void MainWindow::updateToDo()
{
    ui->listWidget->clear();
    for (int i = 0; i < todo.getSchedule().size(); i++ ) {      // for ( int i = todo.getSchedule().size() - 1; i >= 0 ; i --) ???
        currentTask = todo.getSchedule()[i];
        QListWidgetItem *item = new QListWidgetItem;
        item->setCheckState(Qt::Unchecked);
        item->setText(QString( currentTask.getTitle() + "\t" + currentTask.getDate().toString("dd.MM.yyyy") +" \t "));
        ui->listWidget->addItem(item);
    }
    return;
}

void MainWindow::on_listWidget_itemClicked(QListWidgetItem *item)
{
    QFont font = QFont();
    if (item->checkState() == Qt::Checked)
        font.setStrikeOut(true);
    else
        font.setStrikeOut(false);

    item->setFont(font);
}

