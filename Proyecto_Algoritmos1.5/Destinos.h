#ifndef DESTINOS_H
#define DESTINOS_H

#include "Horarios.h"
#include "ColaEnlazada.h"
#include <string>

using namespace std;

class Destinos {
    
    //atributos
    string paisLlegada;
    string paisSalida;
    string nombreAerolinea;
    ColaEnlazada<Horarios*>* horarios;
    string restriccion;
    string avion;
    
public:
    Destinos(string nombreAerolinea, string paisSalida, string paisLlegada, string restriccion, string avion);
    void SetHorarios(ColaEnlazada<Horarios*>* horarios);
    ColaEnlazada<Horarios*>* GetHorarios() const;
    void SetPaisSalida(string paisSalida);
    void SetAvion(string avion);
    string GetAvion() const;
    string GetPaisSalida() const;
    void SetRestriccion(string restriccion);
    string GetRestriccion() const;
    void SetPaisLlegada(string paisLlegada);
    string GetPaisLlegada() const;
    string GetNombreAerolinea() const;
    string toString();

};

#endif /* DESTINOS_H */