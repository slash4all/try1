#ifndef DESCRIPTIONDIALOG_H
#define DESCRIPTIONDIALOG_H

#include <QDialog>

namespace Ui {
class descriptionDialog;
}

class descriptionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit descriptionDialog(QWidget *parent = nullptr);
    ~descriptionDialog();

     void reject() override;

     bool getAbort() const;

     bool getClicked() const;

private slots:

     void on_chooseBtn_rejected();

private:
    bool clicked {false};
    Ui::descriptionDialog *ui;
    bool abort {false};
};

#endif // DESCRIPTIONDIALOG_H
