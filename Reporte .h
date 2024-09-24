//
// Created by joana on 24/9/2024.
//

#ifndef GESTORPROYECTOS_REPORTE_H
#define GESTORPROYECTOS_REPORTE_H


#include <string>
#include <vector>
#include "ReunionSeguimiento.h"

using namespace std;

class Reporte {
private:
    string progresoGeneral;
    vector<string> tareasCompletadas;
    vector<ReunionSeguimiento> resumenReuniones;

public:
    Reporte(const string &progresoGeneral);

    // Métodos para generar el reporte
    void agregarTareaCompletada(const string &tarea);
    void agregarResumenReunion(const ReunionSeguimiento &reunion);
    void generarReporteProgreso() const;

    // Getters y Setters
    string getProgresoGeneral() const;
    vector<string> getTareasCompletadas() const;
    vector<ReunionSeguimiento> getResumenReuniones() const;
};

#endif // GESTORPROYECTOS_REPORTE_H

