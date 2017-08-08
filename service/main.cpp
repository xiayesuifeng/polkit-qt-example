//
// Created by linux on 5/21/17.
//

#include <QtDBus/QDBusConnection>
#include <QCoreApplication>
#include "dbus_adaptor.h"
#include "dbus.h"

int main(int argc, char **argv)
{
    QCoreApplication app(argc, argv);

    dbus *dbus1 = new dbus;
    new DbusAdaptor(dbus1);

//    注册服务名
    QDBusConnection connection = QDBusConnection::systemBus();
    qDebug() << connection.isConnected();
    if(!connection.registerService("com.polkit.qt.example.dbus") || !connection.registerObject("/", dbus1)){
        qDebug() << connection.lastError();
        app.exit(1);
        return 1;
    }


    return app.exec();
}