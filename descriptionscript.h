#ifndef DESCRIPTIONSCRIPT_H
#define DESCRIPTIONSCRIPT_H

#include <QDialog>
#include "todolist.h"

namespace Ui {
class DescriptionScript;
}

class DescriptionScript : public QDialog
{
    Q_OBJECT

public:
    explicit DescriptionScript(Task* task, QWidget *parent = nullptr);
    ~DescriptionScript();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::DescriptionScript *ui;
    Task* task;
};

#endif // DESCRIPTIONSCRIPT_H
