//
// Created by joana on 23/9/2024.
//

#ifndef GESTORPROYECTOS_DESARROLLADOR_H
#define GESTORPROYECTOS_DESARROLLADOR_H

#endif //GESTORPROYECTOS_DESARROLLADOR_H

#include "Empleado.h"
#include <string>




class Desarrollador : public Empleado {
private:
    string lenguajeDominado;                    // Lenguaje de programación en el que se especializa el desarrollador

public:
    // Constructor
    Desarrollador(const string &nombre, const string &puesto, const string &lenguajeDominado);

    // Getter y Setter
    string getLenguajeDominado() const;
    void setLenguajeDominado(const string &lenguajeDominado);

    // Métodos específicos del desarrollador
    void desarrollarCodigo();
    void depurarCodigo();
};
