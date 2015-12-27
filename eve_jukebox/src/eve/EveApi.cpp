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
#include "EveApi.h"
#include <string>
#include <vector>
#include <cstring>
#include <sstream>
#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
#include <rapidxml_utils.hpp>

using namespace rapidxml;
using namespace std;

namespace Eve {

  const std::string sov_url = "https://api.eveonline.com/map/Sovereignty.xml.aspx";

  vector< vector<string> > get_sov_list() {
    string xml = get_eve_xml(sov_url);

    char* cstr = new char[xml.size() + 1];
    strcpy(cstr, xml.c_str());

    xml_document<> doc;
    xml_node<> * root_node;
    xml_node<> * rowset_node;

    doc.parse<0>(cstr);

    root_node = doc.first_node("eveapi");
    rowset_node = root_node->first_node("result")->first_node("rowset");

    vector< vector<string> > retval;    
    
    for (xml_node<> * row_node = rowset_node->first_node("row"); row_node; row_node = row_node->next_sibling()) {
      vector<string> row;

      row.push_back(row_node->first_attribute("solarSystemID")->value());
      row.push_back(row_node->first_attribute("allianceID")->value());
      row.push_back(row_node->first_attribute("factionID")->value());
      row.push_back(row_node->first_attribute("solarSystemName")->value());
      row.push_back(row_node->first_attribute("corporationID")->value());

      retval.push_back(row);
    }

    delete [] cstr;

    return retval;
  }

  std::string get_eve_xml(std::string url) {

    std::ostringstream os;
  
    curlpp::Cleanup mycleanup;

    curlpp::Easy request;

    curlpp::options::Url targetUrl(url);
    curlpp::options::WriteStream ws(&os);

    request.setOpt(targetUrl);
    request.setOpt(ws);
    
    request.perform();

    return os.str();
  }

  std::string get_char_img(std::string charName, std::string cachePath) {
    return charName;
  }
}

