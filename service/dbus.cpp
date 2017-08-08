//
// Created by linux on 5/22/17.
//

#include "dbus.h"
#include "PolicyKitHelper.h"
#include <QDebug>
#include <QtCore/QFile>

dbus::dbus(QObject *parent) :
    QObject(parent){

}

QString dbus::echo() {
    if(PolicyKitHelper::instance()->checkAuthorization("com.polkit.qt.example.echo", getpid())){
        return tr("Hello DBus");
    }else{
        return tr("无权限");
    }

}

bool dbus::writeEtc(QString text) {
    if(PolicyKitHelper::instance()->checkAuthorization("com.polkit.qt.example.writeEtc", getpid())){
        qDebug() << text;
        QFile file("/etc/test");
        if (file.open(QIODevice::ReadWrite)){
            file.write(text.toLocal8Bit());
            file.close();
        }else{
            QFile log("/tmp/dbus.log");
            log.open(QIODevice::WriteOnly);
            log.write(file.errorString().toLocal8Bit());
            log.close();
            return false;
        }


        return true;
    }else{
        return false;
    }
}

