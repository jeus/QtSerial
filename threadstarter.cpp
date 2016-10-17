#include "threadstarter.h"
#include <QtSerialPort/QSerialPortInfo>

threadstarter::threadstarter(QObject *parent) : QObject(parent)
{


//  connect(runButton, SIGNAL(clicked()),this, SLOT(startSlave()));
    connect(&thread, SIGNAL(request(QString)),this, SLOT(showRequest(QString)));
    connect(&thread, SIGNAL(error(QString)),this, SLOT(processError(QString)));
    connect(&thread, SIGNAL(timeout(QString)),this, SLOT(processTimeout(QString)));
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
      startSlave(info.portName());
}


void threadstarter::startSlave(const QString &serialPort)
{
   thread.startSlave(serialPort,5000,"ISOK");

}

void threadstarter::showRequest(const QString &s)
{
 qInfo() << "This Method Call"+s;
 insertDatabase(s);
}

void threadstarter::processError(const QString &s)
{
 qInfo() << "process Error Call"+s;
}

void threadstarter::insertDatabase(const QString &json)
{
    /**
     * Sample Format
     * "{\"Radon\":[{\"radon\": 15445,\"temp\": 73,\"hum\": 47,\"pres\": 99}]}";
     */

    QJsonDocument jsonResponse = QJsonDocument::fromJson(json.toUtf8());
    QJsonObject jsonObject = jsonResponse.object();
    QJsonArray jsonArray = jsonObject["Radon"].toArray();
    QString sql = "INSERT INTO `radon`.`logs` (`radon`,`toler`,`hum`,`temp`,`pres`) VALUES (%1,%2,%3,%4,%5);";
    foreach (const QJsonValue & value, jsonArray) {
        QJsonObject obj = value.toObject();
        sql = QString(sql).arg(obj["radon"].toInt()).arg(obj["toler"].toInt()).arg(obj["hum"].toDouble()).arg(obj["temp"].toDouble()).arg(obj["pres"].toInt());

    }
         QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
         db.setHostName("127.0.0.1");
         db.setDatabaseName("radon");
         db.setUserName("root");
         db.setPassword("6111191111");

         db.open();
         QSqlQuery query;
         query.exec(sql);
         db.close();
}

void threadstarter::processTimeout(const QString &s)
{
   qInfo() << "ProcessTimeOut Call --- " + s;
}

