//
// Created by linux on 5/22/17.
//

#include <QApplication>
#include "mainwindow.h"

int main(int argv,char **argc){

    QApplication app(argv, argc);
    mainwindow *mainwindow1 = new mainwindow;
    mainwindow1->show();
    return app.exec();
}