/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cola.h
 * Author: sojo
 *
 * Created on 9 de mayo de 2020, 05:29 PM
 */

#ifndef COLA_H
#define COLA_H

class Cola {

    struct nodo {
        int numero;
        struct nodo *sgte;
    };

    nodo *anterior;
    nodo *posterior;

    typedef nodo *ptrCola;

public:
    Cola();
    ~Cola();
    nodo getPtrCola();
    int getSize(ptrCola c);
    void anular(ptrCola &c);
    bool isEmpty(ptrCola c);
    void encolar(ptrCola &c, int valor);
    int desencolar(ptrCola &c);
    int getPosicion(ptrCola c, int valor);
    bool existe(ptrCola c, int valor);
    int frente(ptrCola &c);
    void prueba();

};


#endif /* COLA_H */

