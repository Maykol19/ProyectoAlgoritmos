#ifndef COLAENLAZADA_H
#define COLAENLAZADA_H

#include <cstdlib>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include "ColaNode.h"

using namespace std;

template<typename Horarios>

class ColaEnlazada {
public:

    ColaEnlazada() {
        this->head = NULL;
        this->tail = NULL;
    }//constructor

    void enQueue(Horarios value) {
        
        ColaNode<Horarios> *aux = new ColaNode<Horarios>();

        aux->horarios = value;
        aux->sgte = NULL;

        if (this->tail == NULL)
            this->tail = aux;
        else
            this->head->sgte = aux;
        this->head = aux;
        
    }//enQueue

    int getSize() {
        
        ColaNode<Horarios> *aux = tail;
        int cont = 0;
        
        while (aux != NULL) {
            cont++;
            aux = aux->sgte;
        }
        return cont;
        
    }//getSize

    Horarios getNodo(int posicion) {
        
        if (posicion == 0) {
            return tail->horarios;
        } else {
            ColaNode<Horarios> *aux = tail;
            for (int i = 0; i < posicion; i++) {
                aux = aux->sgte;
            }
            return aux->horarios;

        }
        
    }//getNodo

private:
    //variables
    ColaNode<Horarios>* head;
    ColaNode<Horarios>* tail;
    
};

#endif /* COLAENLAZADA2_H */

