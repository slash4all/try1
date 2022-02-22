#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "todolist.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void updateToDo();

private slots:
    void on_addBtn_clicked();

private:
    Ui::MainWindow *ui;
    ToDoList todo;
    int lastRow {0};
};
#endif // MAINWINDOW_H
