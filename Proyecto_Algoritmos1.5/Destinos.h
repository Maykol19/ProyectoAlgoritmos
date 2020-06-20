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
    
public:
    Destinos(string nombreAerolinea, string paisSalida, string paisLlegada, string restriccion);
    void SetHorarios(ColaEnlazada<Horarios*>* horarios);
    ColaEnlazada<Horarios*>* GetHorarios() const;
    void SetPaisSalida(string paisSalida);
    string GetPaisSalida() const;
    void SetRestriccion(string restriccion);
    string GetRestriccion() const;
    void SetPaisLlegada(string paisLlegada);
    string GetPaisLlegada() const;
    string GetNombreAerolinea() const;
    string toString();

};

#endif /* DESTINOS_H */
