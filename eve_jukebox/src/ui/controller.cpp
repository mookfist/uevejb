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
#include "controller.h"
#include <QObject>
#include <QDebug>
#include <EveLog.h>
#include <string>

Controller::Controller()
{
  qDebug() << "construction baby";
}

void Controller::discoverChars(QString logDir) {

    qDebug() << "Discovering Chars: " << logDir;

    std::vector<std::string> chars;

    logDir.replace(QString("file:///"), QString("/"));

    if (EveLog::getAvailableCharacters(logDir.toStdString(), chars)) {
        qDebug() << "Loaded characters";
        for (std::string &i : chars) {
            QString charName = QString::fromStdString(i);
            qDebug() << charName;
        }

    } else {
        qDebug() << "Failed to load characters";
    }


}

