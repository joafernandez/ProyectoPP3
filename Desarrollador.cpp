//
// Created by joana on 23/9/2024.
//

#include "Desarrollador.h"
#include <iostream>

Desarrollador::Desarrollador(const string &nombre, const string &puesto, const string &lenguajeDominado)
        : Empleado(nombre, puesto), lenguajeDominado(lenguajeDominado) {}

// Getter y Setter
string Desarrollador::getLenguajeDominado() const {
    return lenguajeDominado;
}

void Desarrollador::setLenguajeDominado(const string &lenguajeDominado) {
    this->lenguajeDominado = lenguajeDominado;
}

// Métodos específicos del desarrollador
void Desarrollador::desarrollarCodigo() {
    cout << "El desarrollador " << getNombre() << " está desarrollando código en " << lenguajeDominado << "." << endl;
}

void Desarrollador::depurarCodigo() {
    cout << "El desarrollador " << getNombre() << " está depurando código en " << lenguajeDominado << "." << endl;
}
