#ifndef AEROLINEAS_H
#define AEROLINEAS_H

#include <string>
#include <list>
#include "Destinos.h"
#include "DoublyLinkedCircular.h"

using namespace std;

class Aerolineas {
    
    //atributos
    string nombre;
    DoublyLinkedCircular<Destinos*>* destinos;
    
public:
    //Métodos
    Aerolineas(string nombre);
    Aerolineas();
    void SetNombre(string nombre);
    string GetNombre() ;
    void SetDestinos(DoublyLinkedCircular<Destinos*>* destinos);
    DoublyLinkedCircular<Destinos*>* GetDestinos() ;
    string toString();

};

#endif /* AEROLINEAS_H */

