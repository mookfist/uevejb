find_package(Qt5Core REQUIRED)
find_package(Qt5Network REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Sql REQUIRED)

add_subdirectory("3rdparty/rapidxml")
include_directories("3rdparty/rapidxml")


add_library(Eve SHARED EveApi.cpp EveLog.cpp EveSov.cpp)

target_link_libraries(Eve curlpp)
target_link_libraries(Eve rapidxml)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

qt5_use_modules(Eve Core Network Widgets Sql)

# target_link_libraries(Eve ${Qt5Core_LIBRARIES} ${Qt5Network_LIBRARIES})
