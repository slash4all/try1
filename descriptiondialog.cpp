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

bool descriptionDialog::getClicked() const
{
    return clicked;
}

void descriptionDialog::on_chooseBtn_rejected()
{
    clicked = true;
}

