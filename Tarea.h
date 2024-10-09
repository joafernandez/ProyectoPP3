//
// Created by joana on 24/9/2024.
//

#ifndef GESTORPROYECTOS_TAREA_H
#define GESTORPROYECTOS_TAREA_H


#include <string>
#include "Empleado.h"

using namespace std;
// representa las acttividades dentro del proyecto
class Tarea {
private:
    string nombre;// de la tarea
    string estado;  // pendiente, en progreso, finalizada
    string fechaLimite;
    Empleado* empleadoAsignado;

public:
    Tarea(const string &nombre, const string &estado, const string &fechaLimite, Empleado *empleadoAsignado);

    // Getters y Setters
    string getNombre() const;
    string getEstado() const;
    string getFechaLimite() const;
    Empleado* getEmpleadoAsignado() const;


    void setEstado(const string &estado);
    void setEmpleadoAsignado(Empleado *empleado);

    // Métodos para actualizar estado de la tarea

    void actualizarEstado(const string &nuevoEstado);// no la usamos x momento


    //ordenamos por fecha las tareas
    bool operator<(const Tarea &otra) const;
    bool operator>(const Tarea &otra) const;
    bool operator<=(const Tarea &otra) const;
    bool operator>=(const Tarea &otra) const;


    // gerente puede actualizar tarea:
    friend class GerenteProyecto;// para q pueda acceder a las listas


};

#endif // GESTORPROYECTOS_TAREA_H
