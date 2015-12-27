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
#include "EveLog.h"
#include <iostream>
#include <fstream>
#include <string>
#include <dirent.h>
#include <vector>
#include <algorithm>
#include <regex>

namespace Eve {

EveEvent::EveEvent() {}
EveEvent::EveEvent(const std::string system) {
  _system = system;
}
EveEvent::EveEvent(const std::string system, const std::string planet, const std::string moon, const std::string station, const int evt) {
  _system  = system;
  _planet  = planet;
  _moon    = moon;
  _station = station;
  _event   = evt;
}

const std::string EveEvent::getSystem() {
  return _system;
}

const std::string EveEvent::getPlanet() {
  return _planet;
}

const std::string EveEvent::getMoon() {
  return _moon;
}

const std::string EveEvent::getStation() {
  return _station;
}

const int EveEvent::getEvent() {
  return _event;
}

bool getCharFromLogFile(std::string logFile, std::string &charName) {

  std::ifstream inLogFile;
  inLogFile.open(logFile.c_str());

  if (!inLogFile.is_open()) {
    throw LogFileError();
  }
    
  std::string STRING;

  int x = 0;

  while(x < 3) {
    std::getline(inLogFile, STRING);
    x++;
  }

  if (x == 3) {
    if (STRING.substr(0, 12) == "  Listener: ") {
      charName = STRING.substr(12, STRING.length());
      return true;
    } else {
      return false;
    }
  } else {
    return false;
  }
}

bool getAvailableCharacters(std::string logDir, std::vector<std::string> &charNames) {

  DIR *pdir = NULL;
  struct dirent *pent = NULL;

  pdir = opendir(logDir.c_str());
  if (pdir == NULL) {
    throw LogFileError();            
  }

  while (pent = readdir(pdir)) {
    std::string dirName = pent->d_name;
    if (dirName != "." && dirName != "..") {
      std::string logFile = logDir + "/" + dirName;
      std::string charName;

      if (getCharFromLogFile(logFile, charName)) {
        if (std::find(charNames.begin(), charNames.end(), charName) == charNames.end()) {
          charNames.push_back(charName);
        }
      }
    }
  }

  closedir(pdir);

  return true;
}

EveEvent getEventFromLogLine(std::string logLine) {
//  logLine = "[ 2015.02.04 05:02:36 ] (None) Undocking from Osmeden III - Federal Administration Information Center to Osmeden solar system.";
  std::string system;
  std::string planet;
  std::string moon;
  std::string station;
  int evt = EveEvent::e_none;

  std::smatch result;
  if (std::regex_search(logLine, result, Eve::rexp_docking) && result.size() > 1) {
    evt = EveEvent::e_docking;
    
    system = result[1].str();
    planet = system + " " + result[2].str();
    moon = result[7].str();
    station = result[8].str();
  } else if (std::regex_search(logLine, result, Eve::rexp_undocking) && result.size() > 1) {
    evt = EveEvent::e_undocking;

    system = result[1].str();
    planet = system + " " + result[2].str();
    moon = result[7].str();
    station = result[8].str();
  } else if (std::regex_search(logLine, result, Eve::rexp_jumping) && result.size() > 1) {
    // seems to match autopilot log as well
    if (result[2].str() != "") {
      evt = EveEvent::e_jump;
      system = result[2].str();
    }
  }

  EveEvent event(system, planet, moon, station, evt);

  return event;
}

}
