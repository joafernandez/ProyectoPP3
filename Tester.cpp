//
// Created by joana on 23/9/2024.
//

#include "Tester.h"
#include <iostream>

Tester::Tester(const string &nombre, const string &puesto, const string &especialidadPruebas)
        : Empleado(nombre, puesto), especialidadPruebas(especialidadPruebas) {}

// Getter y Setter
string Tester::getEspecialidadPruebas() const {
    return especialidadPruebas;
}

void Tester::setEspecialidadPruebas(const string &especialidadPruebas) {
    this->especialidadPruebas = especialidadPruebas;
}

//metodos

void Tester::realizarPruebas() {
    cout << "El tester " << getNombre() << " está realizando pruebas de " << especialidadPruebas << "." << endl;
}

void Tester::reportarErrores() {
    cout << "El tester " << getNombre() << " ha encontrado y reportado errores durante las pruebas." << endl;
}