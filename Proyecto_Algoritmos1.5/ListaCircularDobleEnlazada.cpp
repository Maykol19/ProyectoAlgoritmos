#include <iostream>
#include "ListaCircularDobleEnlazada.h"
#include <string>

using namespace std;

ListaCircularDobleEnlazada::ListaCircularDobleEnlazada() {
    inicio = NULL;
    fin = NULL;
}

ListaCircularDobleEnlazada::~ListaCircularDobleEnlazada() {
}

int ListaCircularDobleEnlazada::getSize() {

    ptrLista aux = inicio;
    int cont = 0;

    while (aux != fin) {
        cont++;
        aux = aux->sgte;
    }
    cont++;
    return cont;

}//getSize

void ListaCircularDobleEnlazada::anular() {
    inicio = fin = NULL;
    cout << "\nLista eliminada" << endl;
}//anular

bool ListaCircularDobleEnlazada::isEmpty() {
    return inicio == NULL;
}//isEmpty

void ListaCircularDobleEnlazada::insertar(int valor) {

    ptrLista aux = inicio;
    ptrLista nuevoNodo = new (struct nodo);
    nuevoNodo->numero = valor;

    if (isEmpty()) {
        inicio = fin = nuevoNodo;
    } else {
        while (aux != fin) {
            aux = aux->sgte;
        }
        nuevoNodo->ant = aux;
        aux->sgte = nuevoNodo;
        fin = nuevoNodo;
    }
    fin->sgte = inicio;
    cout << "Se agregó el elemento: " << valor << endl;

}//insertar

int ListaCircularDobleEnlazada::getPosicion(int valor) {

    ptrLista aux = inicio; //aux sirve para movernos por la lista
    int posicion = 1;

    while (aux != NULL && aux->numero != valor) {
        posicion++;
        aux = aux->sgte;
    }
    return posicion;

}//getPosicion

void ListaCircularDobleEnlazada::borrar(int valor) {

    if (!isEmpty()) {
        if (inicio == fin && valor == inicio->numero) {
            inicio = fin = NULL;
        } else if (valor == inicio->numero) {
            inicio = inicio->sgte;
        } else {
            ptrLista anterior, temporal;
            anterior = inicio;
            temporal = inicio->sgte;

            while (temporal != NULL && temporal->numero != valor) {
                anterior = anterior->sgte;
                temporal = temporal->sgte;
            }
            if (temporal != NULL) {
                anterior->sgte = temporal->sgte;
                if (temporal == fin) {
                    fin = anterior;
                }
            }
        }
    }
    cout << "Elemento eliminado: " << valor << endl;

}//borrar

bool ListaCircularDobleEnlazada::exist(int valor) {

    if (isEmpty()) {
        return false;
    }
    ptrLista aux = inicio;
    if (inicio->numero == valor || fin->numero == valor)
        return true;
    while (aux != fin) {
        if (aux->numero == valor) {
            return true;
        }
        aux = aux->sgte;
    }
    return false;

}//exist

void ListaCircularDobleEnlazada::insertarOrdenado(int valor) {

    ptrLista aux, nodoAnt, temp;
    aux = inicio;
    nodoAnt = NULL;
    bool continuar = true;
    while (aux != NULL) {
        if (inicio->numero > valor) {
            temp = new(struct nodo);
            temp->numero = valor;
            temp->sgte = inicio;
            inicio = temp;
            continuar = false;
            break;
        } else {
            if (aux->numero > valor) {
                temp = new(struct nodo);
                temp->numero = valor;
                temp->sgte = aux;
                nodoAnt->sgte = temp;
                continuar = false;
                break;
            }
        }
        nodoAnt = aux;
        aux = aux->sgte;
    }
    if (continuar) {
        insertar(valor);
    }

}//insertarOrdenado

int ListaCircularDobleEnlazada::firstInList() {
    return inicio->numero;
}//firstInList

int ListaCircularDobleEnlazada::lastInList() {
    return fin->numero;
}//lastInList

void ListaCircularDobleEnlazada::mostrarLista() {
    if (!isEmpty()) {
        ptrLista aux = inicio;
        cout << "Mostrando la Lista:\n" << endl;

        for (int i = 0; i < getSize(); i++) {
            cout << "[" << aux->numero << "]" << "   ";
            aux = aux->sgte;
        }
        cout << "\n" << endl;
    } else {
        cout << "ListaVacia" << endl;
    }//if-else

}//mostrarLista

