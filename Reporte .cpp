//
// Created by joana on 24/9/2024.
//

#include "Reporte .h"
#include <iostream>

Reporte::Reporte(const string &progresoGeneral) : progresoGeneral(progresoGeneral) {}

void Reporte::agregarTareaCompletada(const string &tarea) {
    tareasCompletadas.push_back(tarea);
}

void Reporte::agregarResumenReunion(const ReunionSeguimiento &reunion) {
    resumenReuniones.push_back(reunion);
}

void Reporte::generarReporteProgreso() const {
    cout << "Progreso General: " << progresoGeneral << endl;
    cout << "Tareas Completadas: " << endl;
    for (const auto &tarea : tareasCompletadas) {
        cout << "- " << tarea << endl;
    }
    cout << "Resumen de Reuniones: " << endl;
    for (const auto &reunion : resumenReuniones) {
        reunion.generarResumen();
    }
}

// Getters
string Reporte::getProgresoGeneral() const {
    return progresoGeneral;
}

vector<string> Reporte::getTareasCompletadas() const {
    return tareasCompletadas;
}

vector<ReunionSeguimiento> Reporte::getResumenReuniones() const {
    return resumenReuniones;
}
