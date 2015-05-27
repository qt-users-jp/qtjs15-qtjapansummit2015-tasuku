#include <QtCore/QCoreApplication>
#include <QtCore/QDebug>
#include <QtCore/QRect>
#include <QtCore/QTime>
#include <QtCore/QLoggingCategory>

struct Color { uchar r, g, b; };

QDebug operator <<(QDebug dbg, const Color &color) {
    QDebugStateSaver saver(dbg);
    dbg.resetFormat();
    dbg.nospace();
    dbg << "Color(#";
    dbg << hex << uppercasedigits;
    dbg << qSetFieldWidth(2) << qSetPadChar('0');
    dbg << color.r << color.g << color.b;
    dbg << qSetFieldWidth(0) << ')';
    return dbg;
}

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    QLoggingCategory categoryA("category.a");
    qCDebug(categoryA, "Hello World");
    qCDebug(categoryA, "Hello Qt 5 World");

    QLoggingCategory categoryB("category.b");
    qCDebug(categoryB) << "Hello World";
    qCDebug(categoryB) << "Hello" << "Qt" << 5 << "World";
    qCDebug(categoryB) << QRect(0, 0, 100, 100) << QTime::currentTime();

    QString world = QStringLiteral("World");
    qDebug() << "Hello" << world;
    qDebug().nospace() << "Hello" << world;
    qDebug().noquote() << "Hello" << world;

    QStringList list = {"Hello", "World"};
    {
        QDebug dbg = qDebug();
        dbg.nospace().noquote();
        dbg << "List:";
        for (int i = 0; i < list.size(); i++) {
            dbg << ' ' << i << '/' << list.at(i);
        }
    }

#ifndef MY_NO_COLOR_DEBUG
    qDebug().nospace() << "RGB: #" << hex << uppercasedigits
                       << 0x7e << 0xc2 << 0x42;
#endif

    if (qEnvironmentVariableIsEmpty("MY_NO_COLOR_DEBUG")) {
        qDebug() << Color({126, 194, 6}) << QTime::currentTime();
    }

//    return app.exec();
    return 0;
}
