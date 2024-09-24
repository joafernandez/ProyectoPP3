//
// Created by joana on 23/9/2024.
//

#ifndef GESTORPROYECTOS_TESTER_H
#define GESTORPROYECTOS_TESTER_H

#endif //GESTORPROYECTOS_TESTER_H


#include "Empleado.h"
#include <string>

using namespace std;

class Tester : public Empleado {
private:
    string especialidadPruebas;  // Especialidad en pruebas (funcionales, de rendimiento, etc.)

public:
    // Constructor
    Tester(const string &nombre, const string &puesto, const string &especialidadPruebas);

    // Getter y Setter
    string getEspecialidadPruebas() const;
    void setEspecialidadPruebas(const string &especialidadPruebas);

    // Métodos específicos del tester
    void asignarTarea() override;  // Sobrescribo el método de Empleado
    void realizarPruebas();
    void reportarErrores();
};