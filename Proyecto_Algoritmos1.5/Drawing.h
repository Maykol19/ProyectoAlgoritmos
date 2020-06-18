#ifndef DRAWING_H
#define DRAWING_H

#include <gtkmm.h>
#include "Grafo.h"

using namespace std;

class Drawing : public Gtk::DrawingArea {
public:

    Drawing() {
        this->set_size_request(600, 600);
        grafo = new Grafo<Object*>();
    }//constructor

    void updateDrawingArea() {
        this->queue_draw();
    }//updateDrawingArea

protected:

    bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) {
        grafo->draw(cr);
    } // on_draw


private:
    Grafo<Object*>* grafo;

};

#endif /* DRAWING_H */

