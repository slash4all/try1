#ifndef DESCRIPTIONDIALOG_H
#define DESCRIPTIONDIALOG_H

#include <QDialog>

namespace Ui {
class descriptionDialog;
}

//interfaccia per selezionare o meno di aggiungere una descrizione ad una task

class descriptionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit descriptionDialog(QWidget *parent = nullptr);
    ~descriptionDialog();

     bool getClicked() const;

private slots:

     void on_chooseBtn_rejected();

private:
    bool rejectClicked {false};
    Ui::descriptionDialog *ui;

};

#endif // DESCRIPTIONDIALOG_H
