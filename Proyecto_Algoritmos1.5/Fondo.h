#ifndef FONDO_H
#define FONDO_H

#include <gtkmm.h>
#include <cstdlib>
#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

class Fondo : public Gtk::DrawingArea {
    
public:

    Fondo() {
        this->set_size_request(1200, 720);
        this->add_events(Gdk::BUTTON_PRESS_MASK | Gdk::SCROLL_MASK | Gdk::SMOOTH_SCROLL_MASK);
    }//constructor

    void updateWindow() {
        queue_draw();
    }//updateWindow

protected:
    virtual bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) {
        draw(cr);
    }//on_draw

private:
    //Método para colocar fondo
    void draw(const Cairo::RefPtr<Cairo::Context>& cr) {
        
        Glib::RefPtr<Gdk::Pixbuf> fondo = Gdk::Pixbuf::create_from_file("Assets/avioncito5.jpg");
        Gdk::Cairo::set_source_pixbuf(cr, fondo, 0, 0);
        cr->rectangle(0, 0, fondo->get_width(), fondo->get_height());
        cr->fill();

    }//draw

    void aboutWinClose() {
        cout << "Cerrar" << endl;
    }//aboutWinClose
    
};

#endif /* FONDO_H */

