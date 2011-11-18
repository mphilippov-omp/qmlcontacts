/*
 * Copyright 2011 Intel Corporation.
 *
 * This program is licensed under the terms and conditions of the
 * Apache License, version 2.0.  The full text of the Apache License is at 	
 * http://www.apache.org/licenses/LICENSE-2.0
 */

#include <QtDeclarative/qdeclarative.h>
#include <QDeclarativeEngine>
#include <QApplication>
#include <QDeclarativeContext>
#include <QDeclarativeView>
#include <seasidepeoplemodel.h>
#include <seasideproxymodel.h>

int main(int argc, char **argv)
{
    QApplication a(argc, argv);

    // TODO: this should probably be done in libseaside somehow
    qmlRegisterType<SeasidePeopleModel>("MeeGo.App.Contacts", 0, 1, "PeopleModel");
    qmlRegisterType<SeasideProxyModel>("MeeGo.App.Contacts", 0, 1, "ProxyModel");

    QDeclarativeView view;

    QDeclarativeContext *rootContext = view.engine()->rootContext();
    Q_ASSERT(rootContext);

    view.setSource(QUrl::fromLocalFile("main.qml"));

    view.show();

    return a.exec();
}
