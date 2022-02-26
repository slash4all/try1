#include "descriptiondialog.h"
#include "ui_descriptiondialog.h"

descriptionDialog::descriptionDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::descriptionDialog)
{
    ui->setupUi(this);

}

descriptionDialog::~descriptionDialog()
{
    delete ui;
}


void descriptionDialog::reject()
{
    this->abort = true;
    QDialog::reject();
}

void descriptionDialog::on_chooseBtn_rejected()
{
    this->clicked = true;
}

bool descriptionDialog::getClicked() const
{
    return clicked;
}

bool descriptionDialog::getAbort() const
{
    return abort;
}

