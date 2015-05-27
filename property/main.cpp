#include <QtCore/QCoreApplication>
#include <QtCore/QDebug>

class Object : public QObject
{
    Q_OBJECT
public:
    Object(QObject *parent = Q_NULLPTR)
        : QObject(parent), m_value(0) {}

    int value() const { return m_value; }

public slots:
    void setValue(int value) {
        if (m_value == value) return;
        m_value = value;
        emit valueChanged(value);
    }

signals:
    void valueChanged(int value);

private:
    int m_value;
};

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    Object object;
    QObject::connect(&object, &Object::valueChanged, [](int value) {
        qDebug() << value;
    });

    qDebug() << object.value();
    object.setValue(100);
    qDebug() << object.value();
    return 0;
}

#include "main.moc"
