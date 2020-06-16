#include <cstdlib>
#include <list>
#include <ostream>
#include <iostream>
#include <string>

#include "Aerolineas.h"

using namespace std;

Aerolineas::Aerolineas(string nombre) {
    this->destinos= new DoublyLinkedCircular<Destinos*>();
    this->nombre = nombre;
}//constructor

Aerolineas::Aerolineas() {
    this->nombre = "";
}//constructor

//getters and setters
void Aerolineas::SetNombre(string nombre) {
    this->nombre = nombre;
}

string Aerolineas::GetNombre()  {
    return nombre;
}

void Aerolineas::SetDestinos(DoublyLinkedCircular<Destinos*>* destinos) {
    this->destinos = destinos;
}

DoublyLinkedCircular<Destinos*>* Aerolineas::GetDestinos()  {
    return destinos;
}


string Aerolineas::toString() {
    return nombre + " ";
}//toString

