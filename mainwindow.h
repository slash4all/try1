#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QListWidgetItem>
#include <QMainWindow>
#include <QDir>
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
    void createDescription();
    void on_listWidget_itemClicked(QListWidgetItem *item);

private:
    QDir path;               // contains the path of the builded app
    Ui::MainWindow *ui;
    ToDoList todo;
    int lastRow {0};
    Task currentTask;
};
#endif // MAINWINDOW_H
