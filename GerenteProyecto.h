//
// Created by joana on 23/9/2024.
//

#ifndef GESTORPROYECTOS_GERENTEPROYECTO_H
#define GESTORPROYECTOS_GERENTEPROYECTO_H

#endif //GESTORPROYECTOS_GERENTEPROYECTO_H
#include "Empleado.h"
#include "string"
using namespace std;

class GerenteProyecto:public Empleado {
private:
    string equipoGestionado;
public:
   //CONSTR
    GerenteProyecto(const string &nom, const string &puesto, const string &equipoGest);

    // getters y setters

    string getEquipoGestionado()const;
    void setEquipoGestionado(const string & equipoGest);

    //metodos:
    void gestionarProyecto();
    void asignarTareas();


};

