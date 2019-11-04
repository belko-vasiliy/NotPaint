#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <QApplication>

#include <QQmlContext>
#include <painter.h>
#include <ifile.h>


int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    //QGuiApplication app(argc, argv);
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    qmlRegisterType<Painter>("Painter",1,0,"Painter");
    qRegisterMetaType<EButtonType::ButtonType >("EButtonType::ButtonType");
    qmlRegisterUncreatableType<EButtonType>("EButtonType", 1, 0, "EButtonType", "You cannot create an instance of the Enums.");

    IFile iFile;
    QQmlContext *context = engine.rootContext();
    context->setContextProperty("iFile", &iFile);

    engine.load(url);

    //engine.rootContext()->setContextProperty("Painter", &painter);

    return app.exec();
}
