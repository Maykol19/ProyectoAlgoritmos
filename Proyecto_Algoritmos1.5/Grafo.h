#ifndef GRAFO_H
#define GRAFO_H

#include <cstdlib>
#include <iostream>
#include <vector>
#include "Vertice.h"

using namespace std;

template <typename Object>

class Grafo {
public:
    vector<Vertice<Object>> vertice;
    int n;
    int contador;

    Grafo() {
        this->contador = 0;
        this->vertice;

    }

    bool existVertice(Object element) {
        if (isEmpty()) {
            cout << "El grafo no existe" << endl;
        }
        for (int i = 0; i < contador; i++) {
            if (vertice[i] == element) {
                return true; //se encuentra el elemento
            }
        }
        return false;
    }

    void agregarVertice(Object element) {
        if (contador >= 1) {
            cout << "El grafo alcanzo el limite" << endl;
        }
        this->vertice[contador++] = new Vertice<Object*>(element);
    }

    void agregarArista(Object v1, Object v2) {

        vertice[getPosicion(v1)].listaArista->insert(v2);

        vertice[getPosicion(v2)].listaArista->insert(v1);

    }

    void agregarPeso(Object v1, Object v2, Object peso) {

        vertice[getPosicion(v1)].listaPeso->insert(peso);

        vertice[getPosicion(v2)].listaPeso->insert(peso);

    }

    int getPosicion(Object element) {
        for (int i = 0; i < contador; i++) {
            if (vertice[i].element == element) {
                return i; //ubicacion del vertices
            }
        }
        return -1; //no se encontro
    }

    bool isEmpty() {

        return contador == 0;
    }

    void prueba() {
        agregarVertice((Object) "A");
        agregarVertice((Object) "B");

        agregarArista((Object) "A", (Object) "B");

    }

    void draw(const Cairo::RefPtr<Cairo::Context>& cr) {
        for (int i = 0; i < 5; i++) {
            vertice[i].draw(cr);
        }
        cr->fill();
    }

};

#endif /* GRAFO_H */

