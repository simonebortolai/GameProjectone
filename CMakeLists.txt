cmake_minimum_required(VERSION 3.16.3)

project(game_unibo)




set(SOURCE_FILES main.cpp)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

include_directories( classes )
link_directories(classes)
add_subdirectory(classes)


add_executable(main ${SOURCE_FILES})

target_link_libraries(main ${CURSES_LIBRARIES} classes)