//
// Created by joana on 23/9/2024.
//

#include "GerenteProyecto.h"
#include "Proyecto.h"
#include "Tarea.h"
#include <iostream>

// implemento constructor
GerenteProyecto::GerenteProyecto(const string &nombre, const string &puesto, const string &equipo)
        : Empleado(nombre, puesto), equipoGestionado(equipo) {}

// Getter y Setter
string GerenteProyecto::getEquipoGestionado() const {
    return equipoGestionado;
}

void GerenteProyecto::setEquipoGestionado(const string &equipo) {
    equipoGestionado = equipo;
}

// Métodos
void GerenteProyecto::gestionarProyecto() {
  cout << "El gerente " << getNombre()<< " esta gestionando el proyecto con su equipo: " << equipoGestionado << endl;
}

void GerenteProyecto::asignarTareas() {
    cout << "El gerente " << getNombre() << " esta asignando tareas a su equipo." << endl;
}

