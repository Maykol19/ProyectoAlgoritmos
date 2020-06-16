#ifndef LISTACIRCULARENLAZADA_H
#define LISTACIRCULARENLAZADA_H

#include "Aerolineas.h"


class ListaCircularDobleEnlazada {
    
    struct nodo {
        Aerolineas elemento;
        struct nodo *sgte, *ant;
    };
    
    nodo *inicio;
    nodo *fin;
    
    typedef nodo *ptrLista;
    
public:
    ListaCircularDobleEnlazada();
    ~ListaCircularDobleEnlazada();
    int getSize();
    void anular();
    bool isEmpty();
    void insertar(Aerolineas valor);
    int getPosicion(Aerolineas valor);
    void borrar(Aerolineas valor);
    bool exist(Aerolineas valor);
    void insertarOrdenado(Aerolineas valor);
    int firstInList();
    int lastInList();
    void mostrarLista();
    ptrLista l;
    
};

#endif /* LISTACIRCULARENLAZADA_H */

