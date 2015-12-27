cmake_minimum_required (VERSION 2.8.11)
project(rapidxml C CXX)

add_library(rapidxml SHARED rapidxml.hpp rapidxml_iterators.hpp rapidxml_print.hpp rapidxml_utils.hpp)
set_target_properties(rapidxml PROPERTIES LINKER_LANGUAGE CXX)
set (rapidxml_VERSION_MAJOR, 1)
set (rapidxml_VERSION_MINOR, 13)
