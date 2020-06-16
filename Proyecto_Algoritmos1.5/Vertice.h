#ifndef VERTICE_H
#define VERTICE_H

#include <cairomm-1.0/cairomm/context.h>

#include "Destinos.h"

template <typename Destinos>
class Vertice {
private:
    Destinos elemento; //elemento almacenado en el vertice
    int x, y;
    Glib::RefPtr<Gdk::Pixbuf> image;

public:

    Vertice(Destinos elemento) {
        this.elemento = elemento;
        this->image = Gdk::Pixbuf::create_from_file("assets/aPapel.png");
        this.x = 500;
        this.y = 500;
    }//constructor

    Vertice(int x, int y) {
        this.elemento = elemento;
        this->image = Gdk::Pixbuf::create_from_file("assets/aPapel.png");
        this.x = x;
        this.y = y;
    }//constructor

    void draw(const Cairo::RefPtr<Cairo::Context>& cr) {
        Gdk::Cairo::set_source_pixbuf(cr, this->image, this->x, this->y);
        cr->rectangle(this->x, this->y, this->image->get_width(), this->image->get_height());
        cr->fill();
    }
};



#endif /* VERTICE_H */

