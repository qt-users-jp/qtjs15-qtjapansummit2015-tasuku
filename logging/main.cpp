//#include <QtCore/QCoreApplication>
#include <QtCore/QDebug>
#include <QtCore/QRect>
#include <QtCore/QTime>
#include <QtCore/QLoggingCategory>

#include <QtWidgets/QApplication>
#include <QtWidgets/QTextBrowser>

#include "mydebug.h"

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

QTextBrowser *logViewer;

int main(int argc, char *argv[])
{
//    QCoreApplication app(argc, argv);
    QApplication app(argc, argv);

    logViewer = new QTextBrowser;
    logViewer->show();

    qInstallMessageHandler(
                [](QtMsgType type, const QMessageLogContext &context, const QString &message) {
        // スレッドセーフにしてね
        // 再帰にも対応してね
        // theread_local or QThreadStorage
        logViewer->append(
                    qFormatLogMessage(type, context, message)
                    );
    });

    QLoggingCategory::setFilterRules(
                "*=false\n"
                "category.*=true\n"
                );
    qSetMessagePattern("%{category} %{function}:%{line}: %{message}");


    QLoggingCategory categoryA("category.a");
    qCDebug(categoryA, "Hello World");
    qCDebug(categoryA, "Hello Qt 5 World");

    QLoggingCategory categoryB("category.b");
    qCDebug(categoryB) << "Hello World";
    qCWarning(categoryB) << "Hello" << "Qt" << 5 << "World";
    qCCritical(categoryB) << QRect(0, 0, 100, 100) << QTime::currentTime();

    QString world = QStringLiteral("World");
    qCDebug(categoryC) << "Hello" << world;
    qCDebug(categoryC).nospace() << "Hello" << world;
    qCDebug(categoryC).noquote() << "Hello" << world;

//    QStringList list = {"Hello", "World"};
//    {
//        QDebug dbg = qDebug();
//        dbg.nospace().noquote();
//        dbg << "List:";
//        for (int i = 0; i < list.size(); i++) {
//            dbg << ' ' << i << '/' << list.at(i);
//        }
//    }

    qCDebug(categoryD).nospace() << "RGB: #" << hex << uppercasedigits
                       << 0x7e << 0xc2 << 0x42;

    qCDebug(categoryD) << Color({126, 194, 6}) << QTime::currentTime();

//    return 0;
    return app.exec();
}
