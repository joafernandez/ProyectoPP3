//
// Created by joana on 24/9/2024.
//

#ifndef GESTORPROYECTOS_REUNIONSEGUIMIENTO_H
#define GESTORPROYECTOS_REUNIONSEGUIMIENTO_H


#include <string>
#include <vector>

using namespace std;

class ReunionSeguimiento {
private:
    string fecha;
    string hora;
    vector<string> listaAsistentes;
    vector<string> temasDiscutidos;
    vector<string> decisiones;
    vector<string> acciones;

public:
    ReunionSeguimiento(const string &fecha, const string &hora);

    // Métodos para gestionar la reunión
    void agendarReunion(const vector<string> &asistentes, const vector<string> &temas);
    void generarResumen() const;

    // Getters y Setters
    string getFecha() const;
    string getHora() const;
    vector<string> getListaAsistentes() const;
    vector<string> getTemasDiscutidos() const;
    vector<string> getDecisiones() const;
    vector<string> getAcciones() const;
};

#endif // GESTORPROYECTOS_REUNIONSEGUIMIENTO_H
