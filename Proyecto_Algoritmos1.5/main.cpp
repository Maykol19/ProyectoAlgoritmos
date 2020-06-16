#include <cstdlib>
#include <list>
#include <ostream>
#include <iostream>
#include <string>
#include <bits/stl_tempbuf.h>
#include <cstring>
#include <stdlib.h>

#include "VentanaPrincipal.h"

using namespace std;

int main(int argc, char** argv) {


    //        Glib::RefPtr<Gtk::Application> app =
    //                Gtk::Application::create(argc, argv, "Viajes");
    //        VentanaPrincipal window;
    //        return app->run(window);
    
    Grafo<Vertice<DoublyLinkedCircular<Destinos>>*>* grafo;
    grafo = new Grafo<Vertice<DoublyLinkedCircular<Destinos>>*>();
    
    Destinos* destino1;
    destino1 = new Destinos("Avianca", "Costa Rica", "Argentina");
    Destinos* v1 = destino1;

    Destinos* destino2;
    destino2 = new Destinos("Avianca", "Holanda", "Japon");
    Destinos* v2 = destino2;

    grafo->agregaVertice(v1);
    grafo->agregaVertice(v2);
    grafo->agregaAristayPeso(v1, v2, 30);

};

