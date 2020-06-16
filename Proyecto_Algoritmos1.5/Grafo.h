#ifndef GRAFO_H
#define GRAFO_H

#include <vector>

#include "Arista.h"
#include "DoublyLinkedCircular.h"
#include "Destinos.h"

template <typename Destinos>

class Grafo {
private:

    DoublyLinkedCircular<Vertice<Destinos>*>* vertices;
    DoublyLinkedCircular<Arista<Destinos>*>* aristas;
    
//    Vertice<Object>* verticeAux;
//    Arista<Object>* aristaAux;

public:

    Grafo() {
        vertices = new DoublyLinkedCircular<Vertice<Destinos>*>();
        aristas = new DoublyLinkedCircular<Arista<Destinos>*>();
//        verticeAux = vertices->getFirstValue();
//        aristaAux = aristas->getFirstValue();
    }//constructor

    void agregaVertice(Destinos elemento) {
//        Vertice<Object> verticeAu(elemento);
//        vertices->insert(verticeAux);
        vertices->insert(elemento);
    }//agregarVertice

    bool existeVertice(Destinos v) {
        for (int i = 0; i < vertices->size(); i++) {
            if (v == vertices->siguiente()->value) {
                return true;
            }
        }
        return false;

    }//existeArista

    void agregaAristayPeso(Destinos v1, Destinos v2, int peso) {

        if (!existeVertice(v1) || !existeVertice(v2)) {
            cout << ("alguno o ninguno de los vertices existe") << endl;
        }
//        Arista<Object> aristaAu(v1, v2, peso);
//        aristas->insert(aristaAu);
        aristas->insert(v1, v2, peso);

    } //agregaAristayPeso

//    void prueba() {
//        
//        Destinos* destino1;
//        destino1 = new Destinos("Avianca", "Costa Rica", "Argentina");
//        Destinos v1 = destino1;
//        
//        Destinos* destino2;
//        destino2 = new Destinos("Avianca", "Holanda", "Japon");
//        Destinos v2 = destino2;
//
//        agregaVertice(v1);
//        agregaVertice(v2);
//        agregaAristayPeso(v1, v2, 30);
//
//    }

    void draw(const Cairo::RefPtr<Cairo::Context>& cr) {
        for (int i = 0; i < vertices->size(); i++) {
            vertices->siguiente()->value->draw(cr);
        }

        for (int i = 0; i < aristas->size(); i++) {
            aristas->siguiente()->value->draw(cr);
        }

        cr->fill();
    }
    
};

#endif /* GRAFO_H */

