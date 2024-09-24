cmake_minimum_required(VERSION 3.24)
project(GestorProyectos)

set(CMAKE_CXX_STANDARD 17)

add_executable(GestorProyectos main.cpp Empleado.cpp Empleado.h GerenteProyecto.cpp GerenteProyecto.h Tester.cpp Tester.h Desarrollador.cpp Desarrollador.h Proyecto.cpp Proyecto.h)
