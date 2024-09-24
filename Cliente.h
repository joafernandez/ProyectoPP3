//
// Created by joana on 24/9/2024.
//

#ifndef GESTORPROYECTOS_CLIENTE_H
#define GESTORPROYECTOS_CLIENTE_H



#include <string>
using namespace std;

class Cliente {
private:
    string nombre;
    string empresa;
    string contacto;

public:
    Cliente(const string &nombre, const string &empresa, const string &contacto);

    // Getters y Setters
    string getNombre() const;
    string getEmpresa() const;
    string getContacto() const;

    void setNombre(const string &nombre);
    void setEmpresa(const string &empresa);
    void setContacto(const string &contacto);

    // Método para solicitar reporte
    void solicitarReporte() const;
};

#endif // GESTORPROYECTOS_CLIENTE_H
