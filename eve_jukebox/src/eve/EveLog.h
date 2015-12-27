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
#ifndef EVE_LOG_H
#define EVE_LOG_H

#include <string>
#include <vector>
#include <exception>
#include <stdexcept>
#include <regex>

namespace Eve
{

const std::regex rexp_docking("Requested to dock at ([a-zA-Z0-9\\-\\s]+) (M{0,4}(CM|CD|D?C{0,3})(XC|XL|L?X{0,3})(IX|IV|V?I{0,3})) - (([a-zA-Z0-9\\s]+) - )?([a-zA-Z0-9\\s]+) station", std::regex_constants::ECMAScript);

const std::regex rexp_undocking("Undocking from ([a-zA-Z0-9\\-\\s]+) (M{0,4}(CM|CD|D?C{0,3})(XC|XL|L?X{0,3})(IX|IV|V?I{0,3})) - ((Moon [0-9]+) - )?([a-zA-Z0-9\\-\\s]+) to ([a-zA-Z0-9\\-\\s]+) solar system", std::regex::ECMAScript);
const std::regex rexp_planets("([a-zA-Z0-9\\-\\s]+) (M{0,4}(CM|CD|D?C{0,3})(XC|XL|L?X{0,3})(IX|IV|V?I{0,3}))", std::regex_constants::ECMAScript);

const std::regex rexp_jumping("Jumping from ([a-zA-Z0-9\\s\\-]+) to ([a-zA-Z0-9\\s\\-]+)", std::regex_constants::ECMAScript);

class LogFileError: public std::runtime_error {

  public:
    LogFileError() : runtime_error("Log file error") {}

    const char * what () const throw ()
    {
      return "Error trying to access the log file";
    }
};

class EveEvent {
public:

  static const int e_none      = 0;
  static const int e_docking   = 1;
  static const int e_docked    = 2;
  static const int e_undocking = 3;
  static const int e_jump      = 4;

  EveEvent();
  EveEvent(const std::string system);
  EveEvent(const std::string system, const std::string planet, const std::string moon, const std::string station, const int evt);
  const std::string getSystem();
  const std::string getPlanet();
  const std::string getMoon();
  const std::string getStation();
  const int getEvent();

private:
 std::string _system;
 std::string _planet;
 std::string _moon;
 std::string _station;
 int _event;
};

bool getCharFromLogFile(std::string logFile, std::string & charName);

/**	
 * Get a list of available characters, based on their appearance in EVE log files
 * @return QStringList List of character names
 */
bool getAvailableCharacters(std::string logFile, std::vector<std::string> & charNames);

EveEvent getEventFromLogLine(std::string logLine);

};
#endif
