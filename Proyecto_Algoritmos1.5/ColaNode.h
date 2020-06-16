#ifndef COLANODE_H
#define COLANODE_H

#include <cstdlib>
#include <iostream>

#include "Horarios.h"

using namespace std;

template <typename Horarios>

class ColaNode {
    
public:
    //atributos
    Horarios horarios;
    ColaNode<Horarios> *sgte;
    ColaNode<Horarios> *ant;

    ColaNode() {
    }//constructor

    ColaNode(Horarios value) {
        this->horarios = value;
    }//constructor

};

#endif /* NODE_H */

