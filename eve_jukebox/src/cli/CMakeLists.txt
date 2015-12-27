add_subdirectory("3rdparty/docopt")

include_directories("3rdparty/docopt")
include_directories("${PROJECT_SOURCE_DIR}/src/eve")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(eveLog eveLog.cpp)
add_executable(eveApi eveApi.cpp)

target_link_libraries(eveLog docopt)
target_link_libraries(eveLog Eve)

target_link_libraries(eveApi docopt)
target_link_libraries(eveApi Eve)
