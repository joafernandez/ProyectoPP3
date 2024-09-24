//
// Created by joana on 24/9/2024.
//

#include "Cliente.h"
#include "Cliente.h"
#include <iostream>

Cliente::Cliente(const string &nombre, const string &empresa, const string &contacto)
        : nombre(nombre), empresa(empresa), contacto(contacto) {}

string Cliente::getNombre() const {
    return nombre;
}

string Cliente::getEmpresa() const {
    return empresa;
}

string Cliente::getContacto() const {
    return contacto;
}

void Cliente::setNombre(const string &nombre) {
    this->nombre = nombre;
}

void Cliente::setEmpresa(const string &empresa) {
    this->empresa = empresa;
}

void Cliente::setContacto(const string &contacto) {
    this->contacto = contacto;
}

void Cliente::solicitarReporte() const {
    cout << "El cliente " << nombre << " de la empresa " << empresa << " ha solicitado un reporte." << endl;
}
