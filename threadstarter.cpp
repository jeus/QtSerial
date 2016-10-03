#include "threadstarter.h"

threadstarter::threadstarter(QObject *parent) : QObject(parent)
{
//    connect(runButton, SIGNAL(clicked()),this, SLOT(startSlave()));
    connect(&thread, SIGNAL(request(QString)),this, SLOT(showRequest(QString)));
    connect(&thread, SIGNAL(error(QString)),this, SLOT(processError(QString)));
    connect(&thread, SIGNAL(timeout(QString)),this, SLOT(processTimeout(QString)));

}


void threadstarter::startSlave()
{
   qInfo() << "THIS METHOD CALL";
}

void threadstarter::showRequest(const QString &s)
{
 qInfo() << "This Method Call"+s;
}

void threadstarter::processError(const QString &s)
{
 qInfo() << "process Error Call"+s;
}

void threadstarter::insertDatabase(const QString &json)
{
   qInfo() << "Insert Into Database Call"+json;
}

void threadstarter::processTimeout(const QString &s)
{
   qInfo() << "ProcessTimeOut Call --- " + s;
}

