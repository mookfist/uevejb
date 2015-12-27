find_package(Qt5 COMPONENTS Widgets Quick Core Network)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories("${PROJECT_SOURCE_DIR}/src/eve")

qt5_add_resources(RESOURCES assets.qrc)

add_executable(ui main.cpp controller.cpp assets.qrc)

qt5_use_modules(ui Quick Core Network Widgets)
target_link_libraries(ui Eve)
