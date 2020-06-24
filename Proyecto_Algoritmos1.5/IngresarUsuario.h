#ifndef INGRESARUSUARIO_H
#define INGRESARUSUARIO_H

#include <gtkmm.h>
#include "Fondo.h"
#include "VentanaViajes.h"
#include "VuelosUsuario.h"

class IngresarUsuario : public Gtk::Window {
public:

    static IngresarUsuario* getInstance() {
        if (instance == 0) {
            instance = new IngresarUsuario();
        }
        return instance;
    }

    IngresarUsuario() {
        this->set_title("Registrar Usuario");
        this->set_size_request(400, 480);
        init();
    }//constructor default

    void updateWindow() {
        queue_draw();
    }

    Usuario* getUsuarioAux() const {
        return usuarioAux;
    }

protected:
    //variables
    Gtk::Fixed fixed;
    Gtk::Fixed fixed2;
    Gtk::Label lblNombre;
    Gtk::Label lblGenero;
    Gtk::Label lblEdad;
    Gtk::Label lblNumPas;
    Gtk::Label lblNacio;
    Gtk::Entry etNombre;
    Gtk::Entry etGenero;
    Gtk::Entry etEdad;
    Gtk::Entry etNumPas;
    Gtk::Entry etNacio;
    Gtk::Button btnGuardar;
    Gtk::Button btnVuelos;
    Gtk::Button btnSalir;
    Fondo drawingGame;
    Usuario* usuarioAux;
    VuelosUsuario* vuelosUsuario;


    //string nombre, string genero, int edad, string numPasaporte, string nacionalidad

private:

    void init() {//inicializar la variables

        this->lblNombre.set_label("Nombre: ");
        this->fixed.put(this->lblNombre, 20, 30);
        this->fixed.put(this->etNombre, 140, 30);

        this->lblGenero.set_label("Genero: ");
        this->fixed.put(this->lblGenero, 20, 100);
        this->fixed.put(this->etGenero, 140, 100);

        this->lblEdad.set_label("Edad: ");
        this->fixed.put(this->lblEdad, 20, 170);
        this->fixed.put(this->etEdad, 140, 170);

        this->lblNumPas.set_label("Num. Pasaporte: ");
        this->fixed.put(this->lblNumPas, 20, 240);
        this->fixed.put(this->etNumPas, 140, 240);

        this->lblNacio.set_label("Nacionalidad: ");
        this->fixed.put(this->lblNacio, 20, 310);
        this->fixed.put(this->etNacio, 140, 310);

        this->btnGuardar.set_label("Ingresar");
        this->fixed.put(this->btnGuardar, 20, 380);

        this->btnVuelos.set_label("Vuelos");
        this->fixed.put(this->btnVuelos, 150, 380);
        
        this->btnSalir.set_label("Salir");
        this->fixed.put(this->btnSalir, 280, 380);


        this->btnGuardar.signal_clicked().connect(sigc::mem_fun(*this, &IngresarUsuario::onButtonClicked));
        this->btnVuelos.signal_clicked().connect(sigc::mem_fun(*this, &IngresarUsuario::onButtonClicked3));
        this->btnSalir.signal_clicked().connect(sigc::mem_fun(*this, &IngresarUsuario::onButtonClicked2));

        ventanaViajes = 0;

        this->add(fixed);
        this->show_all_children();

    }
    //metodo de registro

    void onButtonClicked() {
        usuarioAux = new Usuario(etNombre.get_text(), etGenero.get_text(), etEdad.get_text(), etNumPas.get_text(), etNacio.get_text());
        if (this->ventanaViajes != 0)
            return;
        this->ventanaViajes = new VentanaViajes(usuarioAux);
        this->ventanaViajes->signal_hide().connect(sigc::mem_fun(this, &IngresarUsuario::aboutWinClose));
        this->ventanaViajes->show();

        this->close();
    }//abrirVentanaViajes

    void aboutWinClose() {
        this->ventanaViajes = 0;
        this->vuelosUsuario = 0;
    }//aboutWinClose

    void onButtonClicked2() {
        this->close();
    }
    
    void onButtonClicked3() {
        if (this->vuelosUsuario != 0)
            return;
        this->vuelosUsuario = new VuelosUsuario();
        this->vuelosUsuario->signal_hide().connect(sigc::mem_fun(this, &IngresarUsuario::aboutWinClose));
        this->vuelosUsuario->show();
    }

    VentanaViajes* ventanaViajes;
    static IngresarUsuario* instance; // atributo

};

IngresarUsuario* IngresarUsuario::instance = 0;
#endif /* INGRESARUSUARIO_H */

