/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Grafo.h
 * Author: sojo
 *
 * Created on 15 de junio de 2020, 03:05 PM
 */

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
        // this->prueba();

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
    //
    //    bool existArista(Object v1, Object v2) {
    //        if (isEmpty()) {
    //            cout << "El grafo no existe" << endl;
    //        }
    //        if (vertice[getPosicion(v1)].listaArista->exist(v2)) {
    //            return true;
    //        }
    //        return false;
    //    }

    void agregarVertice(Object element) {
        if (contador >= 1) {
            cout << "El grafo alcanzo el limite" << endl;
        }
        this->vertice[contador++] = new Vertice<Object*>(element);
    }

    void agregarArista(Object v1, Object v2) {

        //        if (!existVertice(v1) || !existVertice(v2)) {
        //            cout << "Alguno o ninguno de los 2 vertices no existe" << endl;
        //        }
        vertice[getPosicion(v1)].listaArista->insert(v2);

        //        vertices[getPosicion(v2)].listaPesos.insertar(v1);
        vertice[getPosicion(v2)].listaArista->insert(v1);
        //        vertices[getPosicion(v2)].listaPesos.insertar(v1);

    }

    void agregarPeso(Object v1, Object v2, Object peso) {

        //        if (!existArista(v1, v2)) {
        //            cout << "No existe una arista entre el vertice: " << v1 << " y el vertice 2" << v2 << endl;
        //        }
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



private:

};



#endif /* GRAFO_H */

