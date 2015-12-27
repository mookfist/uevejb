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

#include <docopt.h>
#include <iostream>
#include <fstream>
#include <string>
#include <EveLog.h>

static const char USAGE[] =
R"(EVE Log Tools.

  Usage:
    eveLog charlist <logDir>
    eveLog charname <logFile>
    eveLog listevents <logFile>

  Options:
    -h --help   Display this help
    --version   Show the version
)";

int charname(std::string logFile) {
  std::string charName = "";
  
  if (Eve::getCharFromLogFile(logFile, charName)) {
    std::cout << charName << std::endl;
    return 0;
  } else {
    std::cout << "Unable to determine character" << std::endl;
    return 1;
  }
}

int charlist (std::string logDir) {

  std::vector<std::string> charlist;

  if (Eve::getAvailableCharacters(logDir, charlist)) {
    for (std::string charName : charlist) {
      std::cout << charName << std::endl;
    }
    return 0;
  } else {
    return 1;
  }
}

int listEvents(std::string logFile) {
  std::ifstream in;
  in.open(logFile);

  if (!in.is_open()) {
    throw "could not open log file: ";
  }

  int x = 0;
  while (!in.eof()) {
    std::string lineBuffer;
    std::string line;
    std::getline(in, lineBuffer);

    Eve::EveEvent location = Eve::getEventFromLogLine(lineBuffer);

    if (location.getEvent() != Eve::EveEvent::e_none) {
      std::cout << "------------------" << std::endl;
    }

    switch (location.getEvent()) {
      case Eve::EveEvent::e_docking:
        std::cout << "Event: Docking" << std::endl;
        break;
      case Eve::EveEvent::e_undocking:
        std::cout << "Event: Undocking" << std::endl;
        break;
      case Eve::EveEvent::e_jump:
        std::cout << "Event: Jump" << std::endl;
        break;
    }

    if (location.getEvent() != Eve::EveEvent::e_none) {
      std::cout << "System:  " << location.getSystem() << std::endl;
      std::cout << "Planet:  " << location.getPlanet() << std::endl;
      std::cout << "Moon:    " << location.getMoon() << std::endl;
      std::cout << "Station: " << location.getStation() << std::endl;
      std::cout << "------------------" << std::endl;
      std::cout << std::endl;
    }

  }

  return 0;
}

 

int main(int argc, const char** argv)
{
  int retval = 1;

  std::map<std::string, docopt::value> args
    = docopt::docopt(USAGE, { argv + 1, argv + argc }, true, "1.0");

  
  if (args["charname"].asBool() == true) {
    retval = charname(args["<logFile>"].asString());
  } else if (args["charlist"].asBool() == true) {
    retval = charlist(args["<logDir>"].asString());
  } else if (args["listevents"].asBool() == true) {
    retval = listEvents(args["<logFile>"].asString());
  }

  return retval;
}
