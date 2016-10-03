#include <QCoreApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    while(true)
    {
        qInfo() << "HELLO WORLD";
    }
    return a.exec();
}

