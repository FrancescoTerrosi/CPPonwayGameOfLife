cmake_minimum_required(VERSION 3.22)

project(Conway)

find_package(OpenGL REQUIRED)

find_package(GLUT REQUIRED)

include_directories( ${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS} )

add_executable(Conway src/main.cpp
    src/gui/boardgui.cpp
    src/game/game.cpp
)

target_link_libraries(Conway ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES} )


