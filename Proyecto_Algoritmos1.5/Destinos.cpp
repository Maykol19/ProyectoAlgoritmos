#include "Destinos.h"

Destinos::Destinos(string nombreAerolinea, string paisSalida, string paisLlegada, string restriccion, string avion) {
    this->nombreAerolinea = nombreAerolinea;
    this->paisLlegada=paisLlegada;
    this->paisSalida= paisSalida;
    this->restriccion = restriccion;
    this->avion = avion;
}//constructor

//getters and setters
void Destinos::SetHorarios(ColaEnlazada<Horarios*>* horarios) {
    this->horarios = horarios;
}

void Destinos::SetPaisSalida(string paisSalida) {
    this->paisSalida = paisSalida;
}

string Destinos::GetPaisSalida() const {
    return paisSalida;
}

void Destinos::SetPaisLlegada(string paisLlegada) {
    this->paisLlegada = paisLlegada;
}

string Destinos::GetPaisLlegada() const {
    return paisLlegada;
}

string Destinos::GetNombreAerolinea() const {
    return nombreAerolinea;
}

ColaEnlazada<Horarios*>* Destinos::GetHorarios() const {
    return horarios;
}

void Destinos::SetRestriccion(string restriccion) {
    this->restriccion = restriccion;
}

string Destinos::GetRestriccion() const {
    return restriccion;
}

void Destinos::SetAvion(string avion) {
    this->avion = avion;
}

string Destinos::GetAvion() const {
    return avion;
}

string Destinos::toString(){
    return paisSalida+"--"+ paisLlegada;
}//toString
