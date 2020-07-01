#include "Avion.h"

Avion::Avion(string nombre, int x, int y) {
    this->nombre = nombre;
}//constructor

Avion::Avion(string nombre) {
    this->nombre = nombre;
}//constructor

//getters and setters
void Avion::SetNombre(string nombre) {
    this->nombre = nombre;
}

string Avion::GetNombre() const {
    return nombre;
}

void Avion::SetX(int x) {
    this->x = x;
}

int Avion::GetX() const {
    return x;
}

void Avion::SetY(int y) {
    this->y = y;
}

int Avion::GetY() const {
    return y;
}

string Avion::toString() {
    return nombre;
}//toString