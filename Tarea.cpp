//
// Created by joana on 24/9/2024.
//

#include "Tarea.h"
#include <iostream>

Tarea::Tarea(const string &nombre, const string &estado, const string &fechaLimite, Empleado *empleadoAsignado)
        : nombre(nombre), estado(estado), fechaLimite(fechaLimite), empleadoAsignado(empleadoAsignado) {}

string Tarea::getNombre() const {
    return nombre;
}

string Tarea::getEstado() const {
    return estado;
}

string Tarea::getFechaLimite() const {
    return fechaLimite;
}

Empleado* Tarea::getEmpleadoAsignado() const {
    return empleadoAsignado;
}

void Tarea::setNombre(const string &nombre) {
    this->nombre = nombre;
}

void Tarea::setEstado(const string &estado) {
    this->estado = estado;
}

void Tarea::setFechaLimite(const string &fechaLimite) {
    this->fechaLimite = fechaLimite;
}

void Tarea::setEmpleadoAsignado(Empleado *empleado) {
    this->empleadoAsignado = empleado;
}

void Tarea::actualizarEstado(const string &nuevoEstado) {
    this->estado = nuevoEstado;
    cout << "El estado de la tarea '" << nombre << "' ha sido actualizado a " << estado << "." << endl;
}
