//
// Created by joana on 24/9/2024.
//

#ifndef GESTORPROYECTOS_PROYECTO_H
#define GESTORPROYECTOS_PROYECTO_H

#endif //GESTORPROYECTOS_PROYECTO_H

#include <string>
#include <vector>
#include "Empleado.h"
#include "Tarea.h"   // falta hacer esta clase

class Proyecto{
private:
    string nombre;
    string descripcion;
    string fechaInicio;
    string fechaFin;
    vector<Empleado*>empleadosAsignados;// lista de empleados
    vector<Tarea*>tareas;// lista de tareas

public:
    Proyecto(const string &nombre, const string &descripcion, const string &fechaInicio, const string &fechaFin);

                                         // getters y setters
    string getNombre() const;
    string getDescripcion() const;
    string getFechaInicio() const;
    string getFechaFin() const;

                                                // metodos
    void agregarEmpleado(Empleado *empleado);
    void eliminarEmpleado(Empleado *empleado);
    void agregarTarea(Tarea *tarea);
    void eliminarTarea(Tarea *tarea);


    void generarReporte() const;




};




