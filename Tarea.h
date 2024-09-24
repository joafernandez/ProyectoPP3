//
// Created by joana on 24/9/2024.
//

#ifndef GESTORPROYECTOS_TAREA_H
#define GESTORPROYECTOS_TAREA_H


#include <string>
#include "Empleado.h"

using namespace std;

class Tarea {
private:
    string nombre;
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

    void setNombre(const string &nombre);
    void setEstado(const string &estado);
    void setFechaLimite(const string &fechaLimite);
    void setEmpleadoAsignado(Empleado *empleado);

    // Métodos para actualizar estado de la tarea
    void actualizarEstado(const string &nuevoEstado);

    // Declarar a GerenteProyecto como friend!!!!!!!!
    friend class GerenteProyecto;


};

#endif // GESTORPROYECTOS_TAREA_H
