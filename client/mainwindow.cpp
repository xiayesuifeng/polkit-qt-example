//
// Created by linux on 5/22/17.
//

#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include "mainwindow.h"
#include "dbus_interface.h"


mainwindow::mainwindow(QWidget *parent) :
        QMainWindow(parent) {

    this->resize(300, 200);

    QLabel *label = new QLabel(this);
    label->setGeometry(10, 60, 300, 20);

    qDebug() << QCoreApplication::applicationPid();
    com::polkit::qt::example::dbus *dbus = new com::polkit::qt::example::dbus(
            "com.polkit.qt.example.dbus", "/", QDBusConnection::systemBus(), this);

    QPushButton *button = new QPushButton("写etc",this);
    button->move(30, 80);
    connect(button, &QPushButton::clicked, this, [ = ] {
        if(dbus->writeEtc("test")){
            qDebug() << true;
        }else{
            qDebug() << false;
        }
    });

    label->setText(dbus->echo());
}