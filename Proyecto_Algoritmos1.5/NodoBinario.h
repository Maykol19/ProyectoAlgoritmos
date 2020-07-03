#ifndef NODOBINARIO_H
#define NODOBINARIO_H

#include <cstdlib>
#include <iostream>
#include "Avion.h"

using namespace std;

template <typename Avion>

class NodoBinario {
public:
    //variables
    Avion elemento;
    NodoBinario* izq;
    NodoBinario* der;

    NodoBinario() {
        this->elemento = 0;
        this->izq = this->der = NULL;
    }//constructor

    NodoBinario(Avion elemento) {
        this->elemento = elemento;
        this->izq = this->der = NULL;
    }//constructor

};

#endif /* NODOBINARIO_H */

