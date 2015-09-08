#include <QApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include "model.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Model mc;
    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("modcpp", &mc);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    return app.exec();
}
