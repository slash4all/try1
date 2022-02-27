#include "descriptiondialog.h"
#include "ui_descriptiondialog.h"

descriptionDialog::descriptionDialog(QWidget *parent) :
    QDialog(parent), ui(new Ui::descriptionDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Bertolazo");

}

descriptionDialog::~descriptionDialog()
{
    delete ui;
}


void descriptionDialog::on_chooseBtn_rejected()
{
    this->rejectClicked = true;
}

bool descriptionDialog::getClicked() const
{
    return rejectClicked;
}


