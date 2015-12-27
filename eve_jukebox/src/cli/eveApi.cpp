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
#include <string>
#include <vector>
#include <EveApi.h>

static const char USAGE[] =
R"(EVE Api Tools.

  Usage:
    eveApi sovlist [--cache=<dir>]
    eveApi charImage <name> [--cache=<dir>]

  Options:
    -h --help      Display this help
    --version      Show the version
    --cache=<dir>  Set the cache directory
)";

int sovlist() {
  std::string xml;
  std::vector< std::vector<string> > sovlist = Eve::get_sov_list();

  for (std::vector< std::vector<string> >::size_type i = 0; i != sovlist.size(); i++) {
    std::cout << sovlist[i][3] << std::endl;
  }

  return 0;
}

int main(int argc, const char** argv) {
  int retval = 0;

  std::map<std::string, docopt::value> args
    = docopt::docopt(USAGE, { argv + 1, argv + argc }, true, "1.0");

  if (args["sovlist"].asBool() == true) {
    retval = sovlist();   
  }

  return retval;
}
