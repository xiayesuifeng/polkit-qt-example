//
// Created by linux on 5/22/17.
//

#ifndef POLKIT_QT_EXAMPLE_DBUS_H
#define POLKIT_QT_EXAMPLE_DBUS_H


#include <QtCore/QObject>

class dbus : public QObject{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface","com.polkit.qt.example.dbus")

public:
    dbus(QObject* parent=0);


public Q_SLOTS:
    QString echo();

    bool writeEtc(QString text);
};


#endif //POLKIT_QT_EXAMPLE_DBUS_H
