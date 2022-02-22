#ifndef TASK_H
#define TASK_H

#include <QString>
#include <QDate>

class Task
{
public:
    Task();
    Task(QString title, QDate deadline, bool important = false);

    void setTitle(QString title);
    void setDeadline(QDate date);
    void setDescription(QString description);
    void setChecked(bool check);
    void setImportant(bool isImportant);

    QString getTitle();
    QDate getDate();
    QString getDescription();
    bool getChecked();
    bool getImportant();

private:
    QString title;
    QDate date;
    QString description;
    bool checked;
    bool important;
};

#endif // TASK_H
