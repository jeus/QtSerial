#ifndef THREADSTARTER_H
#define THREADSTARTER_H
#include "slavethread.h"
#include <QObject>

class threadstarter : public QObject
{
    Q_OBJECT
public:
    explicit threadstarter(QObject *parent = 0);

signals:

private slots:
    void startSlave();
    void showRequest(const QString &s);
    void processError(const QString &s);
    void processTimeout(const QString &s);
    void insertDatabase(const QString &json);

private:
      SlaveThread thread;

};

#endif // THREADSTARTER_H
