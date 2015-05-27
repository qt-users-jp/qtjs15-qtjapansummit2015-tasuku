#include <QtCore/QCoreApplication>

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    qDebug("Hello World");
    qDebug("Hello Qt 5 World");

//    return app.exec();
    return 0;
}
