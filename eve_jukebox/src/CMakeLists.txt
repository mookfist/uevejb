find_package(Qt5Core REQUIRED)

add_subdirectory(cli)
add_subdirectory(ui)
add_subdirectory(eve)

add_library(properties properties)

qt5_use_modules(properties Core)
