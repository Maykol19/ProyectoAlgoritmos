#include <iostream>
#include "Cola.h"
#include <string>

using namespace std;

Cola::Cola() {
    this->anterior = NULL;
    this->posterior = NULL;
}

Cola::~Cola() {
}

//Java es nodod, c++ es ptrCola y java es ptrCola, c++ es c

int Cola::getSize(ptrCola c) {

    ptrCola aux = this->anterior; //inicio de la cola

    //Control de la cantidad de nodos de la cola
    int cont = 0;
    while (aux != NULL) {
        cont++;
        aux = aux->sgte;
    }
    return cont;

}

void Cola::anular(ptrCola& c) {
    this->anterior = this->posterior = NULL;
    cout << "Se anulo la cola" << endl;
}

bool Cola::isEmpty(ptrCola c) {
    return this->anterior == NULL;
}

void Cola::encolar(ptrCola& c, int valor) {

    struct nodo *aux = new(struct nodo);

    aux->numero = valor;
    aux->sgte = NULL;

    if (this->anterior == NULL)
        this->anterior = aux; // encola el primero elemento
    else
        this->posterior->sgte = aux;

    this->posterior = aux;

}

int Cola::desencolar(ptrCola& c) {

    int num;
    struct nodo *aux;

    aux = this->anterior; // aux apunta al inicio de la cola
    num = aux->numero;
    this->anterior = this->anterior->sgte;
    delete(aux); // libera memoria a donde apuntaba aux

    return num;

}

int Cola::getPosicion(ptrCola c, int valor) {

    ptrCola aux = this->anterior;
    int cont = 1; // inicia el primer nodo de la lista
    while (aux != NULL) {
        if (aux->numero == valor) {
            return cont;
        }
        cont++;
        aux = aux->sgte;
    }
    return -1;

}

bool Cola::existe(ptrCola c, int valor) {

    ptrCola aux = anterior;
    while (aux != NULL) {
        if (aux->numero == valor)
            return true;
        aux = aux->sgte;
    }

    return false;

}

int Cola::frente(ptrCola& c) {

    return this->anterior->numero;

}

void Cola::prueba() {

    cout << "PRUEBA DE LA COLA EN C++ \n +++++++++++++++++++++++++++++++++++++++++++++++" << endl;

    ptrCola c = NULL;

    encolar(c, 1);
    encolar(c, 2);
    encolar(c, 3);
    encolar(c, 4);
    cout << "Tamaño de la cola: " << getSize(c) << endl;

    cout << "La posición del número es: " << getPosicion(c, 80) << endl;

    cout << "El valor existe ?: " << existe(c, 10) << endl;
    cout << "El valor existe ?: " << existe(c, 18) << endl;

    cout << "Cola vacía ?: " << isEmpty(c) << endl;

    cout << "El frente es: " << frente(c) << endl;

    cout << "Valor desencolado: " << desencolar(c) << endl;
    cout << "Valor desencolado: " << desencolar(c) << endl;

    cout << "Tamaño de la cola: " << getSize(c) << endl;

    anular(c);

    cout << "Cola vacía ?: " << isEmpty(c) << endl;

}