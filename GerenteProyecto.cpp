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
void GerenteProyecto::gestionarProyecto(Proyecto &proyecto) {
    cout << "Gestionando el proyecto: " << proyecto.getNombre() << endl;

    // Acceder a los empleados del proyecto
    for (Empleado* empleado : proyecto.empleadosAsignados) {
        cout << "Empleado: " << empleado->getNombre() << " - Puesto: " << empleado->getPuesto() << endl;
    }

    // Acceder a las tareas del proyecto
    for (Tarea* tarea : proyecto.tareas) {
        cout << "Tarea: " << tarea->getNombre() << " - Estado: " << tarea->getEstado() << endl;
    }
}

void GerenteProyecto::actualizarEstadoTarea(Tarea &tarea, const string &nuevoEstado) {
    tarea.setEstado(nuevoEstado);  // Accede directamente al atributo privado estado
    cout << "El estado de la tarea '" << tarea.getNombre() << "' ha sido actualizado a " << nuevoEstado << endl;
}

void GerenteProyecto::asignarTareas() {
  cout << "El gerente " << getNombre() << " está asignando tareas a su equipo." << endl;
}


// FRIENS:

void GerenteProyecto::listarTareasProyecto(Proyecto &proyecto) {
    // Acceder directamente al atributo privado `tareas` de `Proyecto` gracias a `friend`
    cout << "Tareas del proyecto " << proyecto.nombre << ":" << endl;
    for (Tarea *tarea: proyecto.tareas) {  // Accediendo directamente a 'tareas' (privado)
        cout << "- " << tarea->getNombre() << " - Estado: " << tarea->getEstado() << endl;
    }
}






















/*Métodos origianles
void GerenteProyecto::gestionarProyecto() {
  cout << "El gerente " << getNombre()<< " esta gestionando el proyecto con su equipo: " << equipoGestionado << endl;
}

void GerenteProyecto::asignarTareas() {
    cout << "El gerente " << getNombre() << " esta asignando tareas a su equipo." << endl;
}
*/
