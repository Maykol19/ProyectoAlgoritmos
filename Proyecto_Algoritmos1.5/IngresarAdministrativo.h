#ifndef INGRESARADMINISTRATIVO_H
#define INGRESARADMINISTRATIVO_H

#include <gtkmm.h>
#include "Fondo.h"
#include "VentanaViajes.h"
#include "AdministrativoData.h"
#include "Usuario.h"
#include "VentanaViajesAdministrador.h"

class IngresarAdministrativo : public Gtk::Window {
public:

    IngresarAdministrativo() {
        this->set_title("Registrar Usuario");
        this->set_size_request(400, 300);
        administrativoData = new AdministrativoData();
        init();
    }//constructor default

    void updateWindow() {
        queue_draw();
    } // updateWindow  

protected:
    //variables
    Gtk::Fixed fixed;
    Gtk::Label lblNombre;
    Gtk::Label lblIDAdministrativo;
    Gtk::Label lblContrasenna;
    Gtk::Entry etNombre;
    Gtk::Entry etIDAdministrativo;
    Gtk::Entry etContrasenna;
    Gtk::Button btnGuardar;
    Gtk::Button btnIngresar;
    Gtk::Button btnSalir;
    AdministrativoData* administrativoData;
    VentanaViajesAdministrador* ventanaViajesAdministrativos;


private:

    void init() {//inicializar la variables

        this->lblNombre.set_label("Nombre: ");
        this->fixed.put(this->lblNombre, 20, 30);
        this->fixed.put(this->etNombre, 150, 30);

        this->lblIDAdministrativo.set_label("ID Administrativo: ");
        this->fixed.put(this->lblIDAdministrativo, 20, 100);
        this->fixed.put(this->etIDAdministrativo, 150, 100);

        this->lblContrasenna.set_label("Contraseña: ");
        this->fixed.put(this->lblContrasenna, 20, 170);
        this->fixed.put(this->etContrasenna, 150, 170);
        this->etContrasenna.set_visibility(false);

        this->btnGuardar.set_label("Guardar");
        this->fixed.put(this->btnGuardar, 30, 220);

        this->btnIngresar.set_label("Ingresar");
        this->fixed.put(this->btnIngresar, 130, 220);

        this->btnSalir.set_label("Salir");
        this->fixed.put(this->btnSalir, 230, 220);


        this->btnGuardar.signal_clicked().connect(sigc::mem_fun(*this, &IngresarAdministrativo::onButtonClickedGuardar));
        this->btnIngresar.signal_clicked().connect(sigc::mem_fun(*this, &IngresarAdministrativo::onButtonClickedIngresar));
        this->btnSalir.signal_clicked().connect(sigc::mem_fun(*this, &IngresarAdministrativo::onButtonClickedSalir));

        
        ventanaViajesAdministrativos=0;

        this->add(fixed);
        this->show_all_children();

    }
    //metodo de registro

    void onButtonClickedGuardar() {
        if (!etNombre.get_text().empty()&&!etIDAdministrativo.get_text().empty()&&!etContrasenna.get_text().empty()) {
            Administrativo* administrativo = new Administrativo(etNombre.get_text(), etIDAdministrativo.get_text(), etContrasenna.get_text());
            administrativoData->write(administrativo);
        } else {
            Gtk::MessageDialog dialogo(
                    *this,
                    "Error",
                    false,
                    Gtk::MESSAGE_INFO
                    );
            dialogo.set_secondary_text("Por favor llene los campos");
            dialogo.run();
        }


    }//abrirVentanaViajes

    void onButtonClickedIngresar() {
        administrativoData->read();

        if (this->administrativoData->checkPassword(this->etNombre.get_text(), this->etContrasenna.get_text())) {

            Gtk::MessageDialog dialogo(
                    *this,
                    "Successfully",
                    false,
                    Gtk::MESSAGE_INFO
                    );
            dialogo.set_secondary_text("Bienvenido");
            dialogo.run();
            
            if (this->ventanaViajesAdministrativos != 0)
                return;
            this->ventanaViajesAdministrativos = new VentanaViajesAdministrador();
            this->ventanaViajesAdministrativos->signal_hide().connect(sigc::mem_fun(this, &IngresarAdministrativo::aboutWinClose));
            this->ventanaViajesAdministrativos->show();

            this->close();
        } else {

            Gtk::MessageDialog dialogo(
                    *this,
                    "Error",
                    false,
                    Gtk::MESSAGE_INFO
                    );
            dialogo.set_secondary_text("Datos incorrectos");
            dialogo.run();
            this->etContrasenna.set_text("");
            this->etNombre.set_text("");
        }//if

    }//abrirVentanaViajes

    void onButtonClickedSalir() {
        this->close();
    }

    void aboutWinClose() {
        this->ventanaViajesAdministrativos=0;
    }//aboutWinClose



};



#endif /* INGRESARADMINISTRATIVO_H */

