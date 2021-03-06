#ifndef GRAFOVUELOS_H
#define GRAFOVUELOS_H

#include <gtkmm.h>
#include "GrafoVuelos.h"
#include "ViajeDataRAF.h"
#include <iostream>
#include <ctime>

class GrafoVuelos : public Gtk::Window {
public:

    GrafoVuelos() {
        this->set_title("Vuelos");
        this->set_size_request(600, 600);
        init();
    }//constructor

    void init() {//inicializar la variables

        this->bAerolineas.set_label("Aerolineas");
        this->fixed.put(this->bAerolineas, 20, 10);

        this->bDestinos.set_label("Destinos");
        this->fixed.put(this->bDestinos, 140, 10);

        this->bHorarios.set_label("Horarios");
        this->fixed.put(this->bHorarios, 260, 10);

        this->bAvion.set_label("Avion");
        this->fixed.put(this->bAvion, 370, 10);

        this->bVuelos.set_label("Actualizar itinerario");
        this->fixed.put(this->bVuelos, 377, 500);
        this->bVuelos.signal_clicked().connect(sigc::mem_fun(*this, &GrafoVuelos::onButtonClickedActualizar));

        this->info.set_size_request(500, 400);
        this->fixed.put(this->info, 20, 80);
        this->info.set_editable(false);
        this->add(this->fixed);

        this->show_all_children();

    }//init

    void onButtonClickedActualizar() {

        ViajeDataRAF viajeData;
        string ss = "";

        for (int i = 0; i < viajeData.cargarGrafo()->size(); i++) {//Llama al método cargarGrafo para que imprima los vuelos según la hora
            ss += viajeData.cargarGrafo()->at(i).toString() + "\n" + "\n";
        }

        Glib::RefPtr<Gtk::TextBuffer>resultado;
        resultado = Gtk::TextBuffer::create();
        resultado->set_text(ss);
        this->info.set_buffer(resultado);
        
    }//onButtonClickedActualizar

private:
    //Variables
    Gtk::Fixed fixed;
    Gtk::TextView info;
    Gtk::Label lAerolineas;
    Gtk::Label lDestinos;
    Gtk::Label lHorarios;
    Gtk::Button bAerolineas;
    Gtk::Button bDestinos;
    Gtk::Button bHorarios;
    Gtk::Button bVuelos;
    Gtk::Button bAvion;

};

#endif /* GRAFOVUELOS_H */

