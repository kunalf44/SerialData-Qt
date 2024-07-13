#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <serial.h>

int main(int argc, char *argv[])
{
    qputenv("QT_IM_MODULE", QByteArray("qtvirtualkeyboard"));

    QGuiApplication app(argc, argv);
    qmlRegisterType<SerialManager>("Serial",1,0,"Serial");
    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/SerialCommunication/Main.qml"));
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
