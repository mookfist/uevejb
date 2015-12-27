/**
Unofficial EVE Jukebox
Copyright (C) 2015 Mookfist

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include <QQmlApplicationEngine>
#include <QQuickView>
#include <QUrl>
#include <QApplication>
#include <QDebug>
#include <QObject>
#include "controller.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    app.setApplicationName("ueve_jukebox");
    app.setApplicationDisplayName("Unofficial EVE Jukebox");
    app.setApplicationVersion("0.0.1");
    QQmlApplicationEngine engine;
    engine.load(QUrl("qrc:/assets/ui/main.qml"));
    QList<QObject *> roots = engine.rootObjects();

    QObject const *root = roots.at(0);

    Controller ctrl;

    QObject::connect(root, SIGNAL(qmlSignal(QString)),
                     &ctrl, SLOT(discoverChars(QString)));



    return app.exec();
    /*
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
    */
}
