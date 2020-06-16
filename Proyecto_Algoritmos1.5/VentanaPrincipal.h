#ifndef VENTANAPRINCIPAL_H
#define VENTANAPRINCIPAL_H

#include <bits/stl_tempbuf.h>
#include "iostream"
#include "Fondo.h"
#include "VentanaViajes.h"
#include "IngresarUsuario.h"
#include "IngresarAdministrativo.h"
#include <gtkmm.h>

using namespace std;

class VentanaPrincipal : public Gtk::Window {
public:

    VentanaPrincipal() {
        this->set_size_request(800, 600);
        this->fixed.put(this->fondo, 0, 0);
        init();
    }//constructor

    ~VentanaPrincipal() {
    }//destructor

    VentanaPrincipal(const VentanaPrincipal& orig) {
    }//constructor

private:

    void init() {

        this->fixed.put(contieneTodo, 0, 0); //se agrega el menuBar al contenedor fixed
        this->principal.set_label("Opciones de ingreso");
        this->contieneTodo.append(this->principal);
        this->principal.set_submenu(this->subMenuArchivo);
        this->administrativo.set_label("Ingreso administrador");
        this->usuario.set_label("Ingreso Usuario");

        this->subMenuArchivo.append(this->administrativo);
        this->subMenuArchivo.append(this->usuario);

        this->usuario.signal_activate().connect(sigc::mem_fun(this, &VentanaPrincipal::abrirVentanaUsuario));
        this->administrativo.signal_activate().connect(sigc::mem_fun(this, &VentanaPrincipal::abrirVentanaAdministrativo));

        this->add(fixed);

        this->ingresarUsuario = 0;
        this->ingresarAdministrativo = 0;
        this->show_all_children();

    }//init

    void abrirVentanaUsuario() {

        if (this->ingresarUsuario != 0)
            return;
        this->ingresarUsuario = new IngresarUsuario();
        this->ingresarUsuario->signal_hide().connect(sigc::mem_fun(this, &VentanaPrincipal::aboutWinClose));
        this->ingresarUsuario->show();

    }//abrirVentanaViajes

    void abrirVentanaAdministrativo() {

        if (this->ingresarAdministrativo != 0)
            return;
        this->ingresarAdministrativo = new IngresarAdministrativo();
        this->ingresarAdministrativo->signal_hide().connect(sigc::mem_fun(this, &VentanaPrincipal::aboutWinClose));
        this->ingresarAdministrativo->show();

    }//abrirVentanaViajes

    void aboutWinClose() {
        this->ingresarUsuario = 0;
        this->ingresarAdministrativo=0;
    }//aboutWinClose

    //atributos
    Gtk::MenuBar contieneTodo;
    Gtk::MenuItem principal;
    Gtk::Menu subMenuArchivo;
    Gtk::ImageMenuItem administrativo;
    Gtk::ImageMenuItem usuario;
    Fondo fondo;
    IngresarUsuario* ingresarUsuario;
    IngresarAdministrativo* ingresarAdministrativo;
    Gtk::Fixed fixed;

};

#endif /* VENTANAPRINCIPAL_H */

