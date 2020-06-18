#ifndef VENTANAVIAJESADMINISTRADOR_H
#define VENTANAVIAJESADMINISTRADOR_H

#include <gtkmm-3.0/gtkmm/fixed.h>
#include <gtkmm-3.0/gtkmm/button.h>
#include <gtkmm-3.0/gtkmm/label.h>
#include <gtkmm-3.0/gtkmm/combobox.h>
#include "Aerolineas.h"
#include "DoublyLinkedCircular.h"
#include "ListNode.h"
#include "ColaNode.h"
#include "Fondo2.h"
#include "ColaEnlazada.h"
#include "Fondo3.h"
#include "GrafoVuelosMainWIndows.h"

class VentanaViajesAdministrador : public Gtk::Window {
public:

    VentanaViajesAdministrador() {
        this->set_title("Control Administrador");
        this->set_size_request(400, 400);
        this->fixedPrincipal.show_all();
        this->fixedPrincipal.put(this->fondo3, 0, 0);
        this->add(this->fixedPrincipal);
        init();
        this->show_all_children();
    }//constructor

    void init() {

        this->agregaViajes.set_label("Agregar");
        this->vuelos.set_label("Vuelos");
        this->agregaViajes.signal_clicked().connect(sigc::mem_fun(*this, &VentanaViajesAdministrador::onButtonClickedAgregar));
        //this->seleccionarAerolinea.signal_clicked().connect(sigc::mem_fun(*this, &VentanaViajes::onButtonClickedSeleccionarAero));
        this->fixedPrincipal.put(this->agregaViajes, 20, 10);
        this->fixedPrincipal.put(this->vuelos, 20, 50);

        this->grafoVuelos = 0;
        this->vuelos.signal_clicked().connect(sigc::mem_fun(*this, &VentanaViajesAdministrador::onButtonClickedVuelos));


    }//init

    void onButtonClickedVuelos() {

        if (this->grafoVuelos != 0)
            return;
        this->grafoVuelos = new GrafoVuelosMainWindows();
        this->grafoVuelos->signal_hide().connect(sigc::mem_fun(this, &VentanaViajesAdministrador::aboutWinClose));
        this->grafoVuelos->show();

        this->close();
    }

    void aboutWinClose() {
        this->grafoVuelos = 0;
    }//aboutWinClose

    void onButtonClickedAgregar() {

        this->fixedPrincipal.~Fixed();

        this->fixedAgregar.put(this->fondo3, 0, 0);
        this->bAerolineas.set_label("Ingrese Aerolinea:");
        this->bDestino.set_label("Ingrese Destino:");
        this->bHorarios.set_label("Ingrese Horarios:");
        this->fixedAgregar.put(this->bAerolineas, 20, 15);
        this->fixedAgregar.put(this->bDestino, 20, 55);
        this->fixedAgregar.put(this->bHorarios, 20, 105);
        this->fixedAgregar.put(this->eAerolineas, 165, 10);
        this->fixedAgregar.put(this->eDestinos, 163, 50);
        this->fixedAgregar.put(this->eDestinos2, 373, 50);
        this->fixedAgregar.put(this->eHorarios, 163, 100);
        this->fixedAgregar.put(this->eHorarios2, 373, 100);

        this->add(this->fixedPrincipal);
        this->add(this->fixedAgregar);
        this->show_all_children();

    }//onButtonClickedAgregar

private:
    //atributo
    Gtk::Fixed fixedPrincipal;
    Gtk::Fixed fixedAgregar;
    Gtk::Fixed fixedViajes;
    Gtk::Button agregaViajes;
    Gtk::Button vuelos;
    Gtk::Button bAerolineas;
    Gtk::Button bDestino;
    Gtk::Button bHorarios;
    Gtk::Entry eAerolineas;
    Gtk::Entry eDestinos;
    Gtk::Entry eHorarios;
    Gtk::Entry eDestinos2;
    Gtk::Entry eHorarios2;
    GrafoVuelosMainWindows* grafoVuelos;
    //    Gtk::Label lAerolineas;
    //    Gtk::Label lDestinos;
    //    Gtk::Label lHorarios;
    Fondo3 fondo3;

};

#endif /* VENTANAVIAJESADMINISTRADOR_H */
