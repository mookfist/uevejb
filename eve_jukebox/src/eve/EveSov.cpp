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
#include "EveSov.h"

namespace Eve
{
  Sov::Sov(int solarSystemID, int allianceID, int corporationID) {
    this.solarSystemID = solarSystemID;
    this.allianceID = allianceID;
    this.corporationID = corporationID;
    this.factionID = 0;
  }

  Sov::Sov(int solarSystemID, int factionID) {
    this.solarSystemID = solarSystemID;
    this.factionID = factionID;
  }

  const int Sov::getSolarSystemID() {
    return this.solarSystemID;
  }

  const int Sov::getAllianceID() {
    return this.allianceID;
  }

  const int Sov::getFactionID() {
    return this.factionID;
  }

  const int Sov::getCorporationID() {
    return this.corporationID;
  }

  static Sov FromXML(std::string sovRowXML) {
    
    regex parser("

    Sov sov;
    sov.allianceID = 1;
    sov.factionID  = 1;
    sov.corporationID = 1;
    sov.solarSystemName = "foo";
  }
}
