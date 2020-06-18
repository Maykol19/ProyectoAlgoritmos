/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Vertice.h
 * Author: sojo
 *
 * Created on 15 de junio de 2020, 03:05 PM
 */

#ifndef VERTICE_H
#define VERTICE_H

#include <cstdlib>
#include <iostream>

#include "DoublyLinkedCircular.h"

using namespace std;

template <typename Object>
class Vertice {
public:
    Object element; //elemento almacenado en el vertice
    DoublyLinkedCircular<Object>*listaArista;
    DoublyLinkedCircular<Object>*listaPeso;
    int x, y;
    Glib::RefPtr<Gdk::Pixbuf> image;

    Vertice(Object element) {
        this->element = element;
        listaArista = new DoublyLinkedCircular<Object>();
        listaPeso = new DoublyLinkedCircular<Object>();
    }

    Vertice(int x, int y) {
        this.element = element;
        this->image = Gdk::Pixbuf::create_from_file("assets/aPapel.png");
        this.x = x;
        this.y = y;
    }//constructor

    void draw(const Cairo::RefPtr<Cairo::Context>& cr) {
        Gdk::Cairo::set_source_pixbuf(cr, this->image, this->x, this->y);
        cr->rectangle(this->x, this->y, this->image->get_width(), this->image->get_height());
        cr->fill();
    }

private:

};


#endif /* VERTICE_H */

