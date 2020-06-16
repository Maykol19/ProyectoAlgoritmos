#include "Destinos.h"

Destinos::Destinos(string nombreAerolinea, string paisSalida, string paisLlegada) {
    this->nombreAerolinea = nombreAerolinea;
    this->paisLlegada=paisLlegada;
    this->paisSalida= paisSalida;
    
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

string Destinos::toString(){
    return paisSalida+"--"+ paisLlegada;
}//toString
