//
// Created by joana on 18/9/2024.
//

#include "Empleado.h"

// Implemento el constructor
Empleado::Empleado(const string &nom, const string &pues) :
        nombre(nom), puesto(pues), numProyectos(0) {}

                                          //  getters
string Empleado::getNombre() const {
    return nombre;
}

string Empleado::getPuesto() const {
    return puesto;
}

int Empleado::getNumProyectos() const {
    return numProyectos;
}

                                                  //  setters
void Empleado::setNombre(const string &nombre) {
    this->nombre = nombre;
}

void Empleado::setPuesto(const string &puesto) {
    this->puesto = puesto;
}

void Empleado::setNumProyectos(int numProyectos) {
    this->numProyectos = numProyectos;
}

                                                      // metodos:
void Empleado::asignarProyecto() {
    numProyectos++;  // incremento
}


void Empleado::finalizarTarea() {                                 //falta
    if (numProyectos > 0) {
        cout << "El empleado " << getNombre() << " ha finalizado una tarea." << endl;
        numProyectos--;  // disminuye num proyect
    } else {
        cout << "No hay tareas pendientes para el empleado " << getNombre() << "." << endl;
    }
}

bool Empleado::operator<(const Empleado &otroEmpleado) const {
    return this->numProyectos < otroEmpleado.numProyectos;
}

bool Empleado::operator>(const Empleado &otroEmpleado) const {
    return this->numProyectos > otroEmpleado.numProyectos;
}