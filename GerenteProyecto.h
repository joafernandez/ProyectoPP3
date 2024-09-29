//
// Created by joana on 23/9/2024.
//

#ifndef GESTORPROYECTOS_GERENTEPROYECTO_H
#define GESTORPROYECTOS_GERENTEPROYECTO_H

#endif //GESTORPROYECTOS_GERENTEPROYECTO_H
#include "Empleado.h"
#include "string"
//agregue utlimo
#include "Proyecto.h"
#include "Tarea.h"
using namespace std;



class GerenteProyecto:public Empleado {
private:
    string equipoGestionado;// el equipo q hace el proyecto
public:
   //CONSTR
    GerenteProyecto(const string &nom, const string &puesto, const string &equipoGest);

    // getters y setters

    string getEquipoGestionado()const;
    void setEquipoGestionado(const string & equipoGest);

    //metodos:
    // antes void gestionarProyecto();

    void gestionarProyecto(Proyecto &proyecto);//imprime nombre proyecto,lista empleado y estado tarea
    void asignarTareas();

    //agregue esto ultimo

    void actualizarEstadoTarea(Tarea &tarea, const string &nuevoEstado);  // Declaración de actualizarEstadoTarea

    //HAGO USO DE FRIEND EN PROYECTO:

    void listarTareasProyecto(Proyecto &proyecto);  // Método que accede a los atributos privados de `Proyecto`

};

