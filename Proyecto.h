//
// Created by joana on 24/9/2024.
//

#ifndef GESTORPROYECTOS_PROYECTO_H
#define GESTORPROYECTOS_PROYECTO_H


#include <string>
#include <vector>
#include "Empleado.h"
#include "Tarea.h"
using namespace std;


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

                                                // metodos a implementar a futuro
    void agregarEmpleado(Empleado *empleado);
    void eliminarEmpleado(Empleado *empleado);
    void agregarTarea(Tarea *tarea);
    void eliminarTarea(Tarea *tarea);


    // Métodos para iteradores personalizados
    // para recorrer y mostrar

    vector<Empleado*>::const_iterator beginEmpleados() const;
    vector<Empleado*>::const_iterator endEmpleados() const;
    vector<Tarea*>::const_iterator beginTareas() const;
    vector<Tarea*>::const_iterator endTareas() const;



    void generarReporte() const;//MUESTRA INFO DE LA CLASE

 // podemos controlar los proyectos por fecha de inicio y finalizacion
    bool operator<(const Proyecto &otro) const;
    bool operator>(const Proyecto &otro) const;
    bool operator<=(const Proyecto &otro) const;
    bool operator>=(const Proyecto &otro) const;


    // Declaramos un amigo
    friend class GerenteProyecto;// podra acceder a la lista de tareas y empleados si es necesario



};


#endif //GESTORPROYECTOS_PROYECTO_H


