#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include<QQmlContext>
#include"./myqmlclass.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;



    //方式二
    qmlRegisterType<MyQmlClass>("com.company.myqmlclass",1,0,"MyQmlClass");







    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("untitled5", "Main");

    return app.exec();
}
