#include "Horarios.h"

Horarios::Horarios(string salida, string llegada) {
    this->llegada = llegada;
    this->salida = salida;
}//constructor

Horarios::Horarios() {
}//constructor

//getters and setters
void Horarios::SetSalida(string salida) {
    this->salida = salida;
}

string Horarios::GetSalida() const {
    return salida;
}

void Horarios::SetLlegada(string llegada) {
    this->llegada = llegada;
}

string Horarios::GetLlegada() const {
    return llegada;
}

string Horarios::GetNombreSalida() const {
    return nombreSalida;
}

string Horarios::GetNombreAerolinea() const {
    return nombreAerolinea;
}

string Horarios::GetNombreLlegada() const {
    return nombreLlegada;
}

string Horarios::toString() {
    return salida + "-" + llegada;
}//toString
