#ifndef ARBOLBINARIOBUSQUEDA_H
#define ARBOLBINARIOBUSQUEDA_H

#include <cstdlib>
#include <iostream>
#include <string.h>
#include <string>
#include "NodoBinario.h"
#include "Avion.h"

using namespace std;

template <typename Object>

class ArbolBinarioBusqueda {
public:

    ArbolBinarioBusqueda() {
        this->raiz = NULL;
    }//constructor

    bool isEmpty() {
        return this->raiz == NULL;
    }//isEmpty

    bool existe(Avion* elemento) {
        if (isEmpty()) {
            cout << "El arbol esta vacio" << endl;
        }
        return busquedaBinaria(this->raiz, elemento);
    }//existe

    Object insertar(Avion* elemento) {
        this->raiz = insertar(this->raiz, elemento);
        cout << elemento->toString() << endl;
        return elemento;
    }//insertar

    string salida() {
        cout << "ENTRA SALIDA";
        string salida = "";
        salida = preOrden2(raiz);
        return salida;
    }//salida

    void toString() {
        if (isEmpty()) {
            cout << "El arbol esta vacio" << endl;
        }
        
        cout << "Historial: ";
        preOrden(raiz);
        cout << "" << endl;

        cout << "InOrden: ";
        inOrden(raiz);

        cout << "" << endl;
        cout << "PostOrden: ";
        postOrden(raiz);
    }//toString


private:
    NodoBinario<Object>* raiz;

    bool busquedaBinaria(NodoBinario<Avion*>* nodo, Avion* elemento) {
        if (nodo == NULL) {
            return false;
        } else if (elemento == nodo->elemento) {
            return true;
        } else if (comparar(elemento, nodo->elemento) < 0) {
            return busquedaBinaria(nodo->izq, elemento);
        } else {
            return busquedaBinaria(nodo->der, elemento);
        }
    }//busquedaBinaria

    int comparar(Avion* element1, Avion* element2) {
        if ((typeid (element1->toString()) == typeid (string))&&(typeid (element2->toString()) == typeid (string))) {
            if ((element1->toString() == element2->toString()) < 0) {
                return -1;
            }
            if ((element1->toString() == element2->toString()) > 0) {
                return 1;
            }
        }//instacia de enteros
        return 0; //si elemento1 y elementos 2 son iguales
    }//comparar

    NodoBinario<Avion*>* insertar(NodoBinario<Avion*>* nodo, Avion* elemento) {
        if (nodo == NULL) {
            nodo = new NodoBinario<Avion*>(elemento);
        } else if (compara(elemento, nodo->elemento) < 0) {
            nodo->izq = insertar(nodo->izq, elemento);
        }
        return nodo; //arbol modificado
    }//insertar

    string preOrden2(NodoBinario<Avion*>* nodo) {
        cout << "ENTRA PREORDEN" << endl;
        string result = "";

        if (nodo != NULL) {
            result = nodo->elemento->toString() + "\n";
            result += preOrden2(nodo->izq);
            result += preOrden2(nodo->der);
        }//if

        return result;
    }//preOrdenstring

    void preOrden(NodoBinario<Avion*>* nodo) {

        if (nodo != NULL) {

            cout << nodo->elemento->toString() << ", ";
            preOrden(nodo->izq);
            preOrden(nodo->der);
        }

    }//preOrden

    void inOrden(NodoBinario<Avion*>* nodo) {
        if (nodo != NULL) {
            inOrden(nodo->izq);
            cout << nodo->elemento->toString() << ", ";
            inOrden(nodo->der);
        }
    }//inOrden

    void postOrden(NodoBinario<Avion*>* nodo) {
        if (nodo != NULL) {
            postOrden(nodo->izq);
            postOrden(nodo->der);
            cout << nodo->elemento->toString() << ", ";
        }
    }//postOrden

    int compara(Avion* element1, Avion* element2) {

        return -1; //si elemento1 y elementos 2 son iguales
    }//compara

};

#endif /* ARBOLBINARIOBUSQUEDA_H */


