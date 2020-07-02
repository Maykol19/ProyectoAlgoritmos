#include "Avion.h"
#include <ostream>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

Avion::Avion(string nombre, int x, int y) {
    this->nombre = nombre;
}//constructor

Avion::Avion(string nombre, int horas) {
    this->nombre = nombre;
    this->horas = horas;
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

int Avion::GetHoras() const {
    return horas;
}

string Avion::toString() {
    return nombre;
}//toString

string Avion::toStringH() {


    stringstream s;
    s << nombre << ": " << horas;
    return s.str();

}//toString