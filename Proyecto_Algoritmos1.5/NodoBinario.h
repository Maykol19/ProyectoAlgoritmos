/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NodoBinario.h
 * Author: curso
 *
 * Created on June 18, 2019, 1:10 PM
 */

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
    }//constructor default

    NodoBinario(Avion elemento) {
        this->elemento = elemento;
        this->izq = this->der = NULL;
    }//constructor sobrecargado


private:


};

#endif /* NODOBINARIO_H */

