//
// Created by joana on 24/9/2024.
//

#include "ReunionSeguimiento.h"
#include <iostream>

ReunionSeguimiento::ReunionSeguimiento(const string &fecha, const string &hora)
        : fecha(fecha), hora(hora) {}

void ReunionSeguimiento::agendarReunion(const vector<string> &asistentes, const vector<string> &temas) {
    listaAsistentes = asistentes;
    temasDiscutidos = temas;
}

void ReunionSeguimiento::generarResumen() const {
    cout << "Resumen de la reunión del día " << fecha << " a las " << hora << ":" << endl;
    cout << "Asistentes: " << endl;
    for (const auto &asistente : listaAsistentes) {
        cout << "- " << asistente << endl;
    }
    cout << "Temas discutidos: " << endl;
    for (const auto &tema : temasDiscutidos) {
        cout << "- " << tema << endl;
    }
    cout << "Decisiones: " << endl;
    for (const auto &decision : decisiones) {
        cout << "- " << decision << endl;
    }
    cout << "Acciones a seguir: " << endl;
    for (const auto &accion : acciones) {
        cout << "- " << accion << endl;
    }
}

// Getters
string ReunionSeguimiento::getFecha() const {
    return fecha;
}

string ReunionSeguimiento::getHora() const {
    return hora;
}

vector<string> ReunionSeguimiento::getListaAsistentes() const {
    return listaAsistentes;
}

vector<string> ReunionSeguimiento::getTemasDiscutidos() const {
    return temasDiscutidos;
}

vector<string> ReunionSeguimiento::getDecisiones() const {
    return decisiones;
}

vector<string> ReunionSeguimiento::getAcciones() const {
    return acciones;
}
