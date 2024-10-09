//
// Created by joana on 24/9/2024.
//

#include "Proyecto.h"
#include <iostream>
#include "algorithm"

Proyecto::Proyecto(const string &nombre, const string &descripcion, const string &fechaInicio, const string &fechaFin)
        : nombre(nombre), descripcion(descripcion), fechaInicio(fechaInicio), fechaFin(fechaFin) {}

string Proyecto::getNombre() const {
    return nombre;
}

string Proyecto::getDescripcion() const {
    return descripcion;
}

string Proyecto::getFechaInicio() const {
    return fechaInicio;
}

string Proyecto::getFechaFin() const {
    return fechaFin;
}

void Proyecto::agregarEmpleado(Empleado *empleado) {
    empleadosAsignados.push_back(empleado);
}

void Proyecto::eliminarEmpleado(Empleado *empleado) {
    empleadosAsignados.erase(remove(empleadosAsignados.begin(), empleadosAsignados.end(), empleado), empleadosAsignados.end());
}

void Proyecto::agregarTarea(Tarea *tarea) {
    tareas.push_back(tarea);
}

void Proyecto::eliminarTarea(Tarea *tarea) {
    tareas.erase(remove(tareas.begin(), tareas.end(), tarea), tareas.end());
}

void Proyecto::generarReporte() const {
    cout << "Proyecto: " << nombre << endl;
    cout << "Descripcion: " << descripcion << endl;
    cout << "Fecha de Inicio: " << fechaInicio << endl;
    cout << "Fecha de Fin: " << fechaFin << endl;
    cout << "Numero de empleados asignados: " << empleadosAsignados.size() << endl;
    cout << "Numero de tareas: " << tareas.size() << endl;
}
// Métodos para iteradores personalizados
vector<Empleado*>::const_iterator Proyecto::beginEmpleados() const {
    return empleadosAsignados.begin();
}

vector<Empleado*>::const_iterator Proyecto::endEmpleados() const {
    return empleadosAsignados.end();
}

vector<Tarea*>::const_iterator Proyecto::beginTareas() const {
    return tareas.begin();
}

vector<Tarea*>::const_iterator Proyecto::endTareas() const {
    return tareas.end();
}


// Sobrecarga de operadores para comparar fechas de finalización de proyectos

bool Proyecto::operator<(const Proyecto &otro) const {
    return this->fechaFin < otro.fechaFin;
}

bool Proyecto::operator>(const Proyecto &otro) const {
    return this->fechaFin > otro.fechaFin;
}

bool Proyecto::operator<=(const Proyecto &otro) const {
    return this->fechaFin <= otro.fechaFin;
}

bool Proyecto::operator>=(const Proyecto &otro) const {
    return this->fechaFin >= otro.fechaFin;
}
