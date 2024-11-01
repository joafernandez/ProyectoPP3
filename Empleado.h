//
// Created by joana on 18/9/2024.
//

#ifndef GESTORPROYECTOS_EMPLEADO_H
#define GESTORPROYECTOS_EMPLEADO_H


#include "string"
#include "iostream"
using namespace std;

class Empleado {
private:
    string nombre;
    string puesto;
    int numProyectos;//cantidad de proyectos.contador
public:                                             //declaro el contructor
    Empleado(const string &nom, const string &pues);

    string getNombre() const;
    string getPuesto() const;
    int getNumProyectos() const;




    void asignarProyecto();
    void finalizarTarea();

    // para comparar empleados
    bool operator<(const Empleado &otroEmpleado) const;
    bool operator>(const Empleado &otroEmpleado) const;// se repite podria quitar
};
#endif //GESTORPROYECTOS_EMPLEADO_H