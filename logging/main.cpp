#include <QtCore/QCoreApplication>
#include <QtCore/QDebug>
#include <QtCore/QRect>
#include <QtCore/QTime>

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    qDebug("Hello World");
    qDebug("Hello Qt 5 World");

    qDebug() << "Hello World";
    qDebug() << "Hello" << "Qt" << 5 << "World";
    qDebug() << QRect(0, 0, 100, 100) << QTime::currentTime();

    QString world = QStringLiteral("World");
    qDebug() << "Hello" << world;
    qDebug().nospace() << "Hello" << world;
    qDebug().noquote() << "Hello" << world;

//    return app.exec();
    return 0;
}
