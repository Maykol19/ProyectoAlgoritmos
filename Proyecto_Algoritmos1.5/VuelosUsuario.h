#ifndef VUELOSUSUARIO_H
#define VUELOSUSUARIO_H

#include <gtkmm.h>
#include "VuelosUsuario.h"
#include "ViajeDataRAF.h"

#include <iostream>
#include <string>

using namespace std;

class VuelosUsuario : public Gtk::Window {
public:

    VuelosUsuario() {
        this->set_title("Vuelos");
        this->set_size_request(500, 500);
        init();
    }//constructor

    void init() {//inicializar la variables

        this->bAerolineas.set_label("Aerolineas");
        this->fixed.put(this->bAerolineas, 20, 10);

        this->bDestinos.set_label("Destinos");
        this->fixed.put(this->bDestinos, 110, 10);

        this->bHorarios.set_label("Horarios");
        this->fixed.put(this->bHorarios, 185, 10);

        this->bVuelos.set_label("Actualizar itinerario");
        this->fixed.put(this->bVuelos, 350, 10);
        this->bVuelos.signal_clicked().connect(sigc::mem_fun(*this, &VuelosUsuario::onButtonClickedActualizar));

        this->info.set_size_request(350, 250);
        this->fixed.put(this->info, 20, 100);
        this->info.set_editable(false);
        this->add(this->fixed);

        this->show_all_children();

    }//init

    void onButtonClickedActualizar() {

        ViajeDataRAF viajeData;

        string ss = "";

        for (int i = 0; i < viajeData.cargarViajes()->size(); i++) {
            ss += viajeData.cargarViajes()->at(i).toString() + "\n"+"\n";

            cout << viajeData.cargarViajes()->at(i).toString();

        }

        Glib::RefPtr<Gtk::TextBuffer>resultado;
        resultado = Gtk::TextBuffer::create();
        resultado->set_text(ss);
        this->info.set_buffer(resultado);
    }

private:
    Gtk::Fixed fixed;
    Gtk::TextView info;
    Gtk::Label lAerolineas;
    Gtk::Label lDestinos;
    Gtk::Label lHorarios;
    Gtk::Button bAerolineas;
    Gtk::Button bDestinos;
    Gtk::Button bHorarios;
    Gtk::Button bVuelos;

};

#endif /* VUELOSUSUARIO_H */

