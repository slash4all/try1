#include "descriptionscript.h"
#include "ui_descriptionscript.h"

DescriptionScript::DescriptionScript(Task* task, QWidget *parent) :
    QDialog(parent), ui(new Ui::DescriptionScript)
{
    ui->setupUi(this);
    this->setWindowTitle("Task's Description");
    this->task = task;
    ui->taskEdit->setText(task->getTitle());
    ui->deadlineEdit->setText(task->getDate().toString("dd-MM-yyyy"));
}

DescriptionScript::~DescriptionScript()
{
    delete ui;
}

void DescriptionScript::on_buttonBox_accepted()
{
    task->setDescription(ui->descriptionEdit->toPlainText());
}

