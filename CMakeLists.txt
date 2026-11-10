cmake_minimum_required(VERSION 3.12)
project(MiProyecto)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

# Incluimos recursivamente los fuentes de src/ y sus subcarpetas.
file(GLOB_RECURSE APP_SOURCES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)

add_executable(app ${APP_SOURCES})

# Directorio donde CMake buscará las cabeceras (.h)
target_include_directories(app PRIVATE include)

# Enlazado de librerías
target_link_libraries(app OpenGL::GL glfw ${CMAKE_DL_LIBS})