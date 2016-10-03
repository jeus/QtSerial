#include <QCoreApplication>
#include <QDebug>
#include "threadstarter.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    threadstarter threadstarter;
    return a.exec();
}

