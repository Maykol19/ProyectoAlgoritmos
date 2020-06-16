#ifndef VENTANAVIAJES_H
#define VENTANAVIAJES_H

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
#include "Usuario.h"
#include "Util.h"

class VentanaViajes : public Gtk::Window {
public:

    class ModelColumns : public Gtk::TreeModel::ColumnRecord {
    public:

        ModelColumns() {
            add(m_col_horarios);
        }

        Gtk::TreeModelColumn<Glib::ustring> m_col_horarios;
    };

    VentanaViajes(Usuario* usuario) {
        this->set_title("Viajes");
        this->set_size_request(400, 300);
        this->util = new Util();
        this->fixedAerlonias.show_all();
        this->fixedAerlonias.put(this->fondo2, 0, 0);
        usuarioAux = usuario;
        add_events(Gdk::KEY_PRESS_MASK);
        this->add(this->fixedAerlonias);
        init();
        this->show_all_children();
    }//constructor

    bool on_key_press_event(GdkEventKey* event) {

        if (event->keyval == GDK_KEY_Up) {
            this->aerolinea.set_label(this->util->getListaA()->siguiente()->value->toString());
        } else if (event->keyval == GDK_KEY_Down) {
            this->aerolinea.set_label(this->util->getListaA()->anterior()->value->toString());
        }

        for (int i = 0; i < this->util->getListaA()->size(); i++) {
            if ("Avianca" == aux->GetNombre()) {
                if (event->keyval == GDK_KEY_Up) {
                    this->destino.set_label(this->util->getListaAvi()->siguiente()->value->toString());
                } else if (event->keyval == GDK_KEY_Down) {
                    this->destino.set_label(this->util->getListaAvi()->anterior()->value->toString());
                }
            } else if ("Latam" == aux->GetNombre()) {
                if (event->keyval == GDK_KEY_Up) {
                    this->destino.set_label(this->util->getListaLat()->siguiente()->value->toString());
                } else if (event->keyval == GDK_KEY_Down) {
                    this->destino.set_label(this->util->getListaLat()->anterior()->value->toString());
                }
            }
            if ("American" == aux->GetNombre()) {
                if (event->keyval == GDK_KEY_Up) {
                    this->destino.set_label(this->util->getListaAme()->siguiente()->value->toString());
                } else if (event->keyval == GDK_KEY_Down) {
                    this->destino.set_label(this->util->getListaAme()->anterior()->value->toString());
                }
            }
        }

    }//on_key_press_event

private:
    //atributo
    Gtk::Fixed fixedAerlonias;
    Gtk::Fixed fixedDestinos;
    Gtk::Fixed fixedHorarios;
    Gtk::Button seleccionarAerolinea;
    Gtk::Button aerolinea;
    Gtk::Button seleccionarDestinos;
    Gtk::Button destino;
    Gtk::Button seleccionarHorarios;
    Gtk::Button horario;
    Aerolineas* aux;
    Destinos* auxDest;
    Fondo2 fondo2;
    Gtk::ComboBox comboBoxDstinos;
    Usuario* usuarioAux;
    Util* util;


    ModelColumns m_Columns;

    //Child widgets:
    Gtk::ComboBox m_Combo;
    Gtk::CellRendererText m_cell;
    Glib::RefPtr<Gtk::ListStore> m_refTreeModel;

    void init() {

        this->seleccionarAerolinea.set_label("Seleccionar Aerolinea");
        this->aerolinea.set_label("Eligir Aerolinea");
        this->seleccionarAerolinea.signal_clicked().connect(sigc::mem_fun(*this, &VentanaViajes::onButtonClickedSeleccionarAero));
        this->fixedAerlonias.put(this->seleccionarAerolinea, 30, 40);
        this->fixedAerlonias.put(this->aerolinea, 250, 43);

        this->util->llenar();


        aux = this->util->getListaA()->getFirstValue();





        for (int i = 0; i < this->util->getListaA()->size(); i++) {
            if ("Avianca" == aux->GetNombre()) {
                aux->SetDestinos(this->util->getListaAvi());


            } else if ("Latam" == aux->GetNombre()) {
                aux->SetDestinos(this->util->getListaLat());

            }
            if ("American" == aux->GetNombre()) {
                aux->SetDestinos(this->util->getListaAme());

            }
            aux = this->util->getListaA()->siguiente()->value;
        }



    }//init

    void onButtonClickedSeleccionarAero() {

        for (int i = 0; i < this->util->getListaA()->size(); i++) {
            if (aerolinea.get_label() == this->util->getListaA()->siguiente()->value->toString()) {
                aux = this->util->getListaA()->siguiente()->prev->value;
                //guardamos la aerolinea seleccionada
            }
        }


        this->fixedAerlonias.~Fixed();

        this->fixedDestinos.put(this->fondo2, 0, 0);
        this->seleccionarDestinos.set_label("Seleccionar Destinos");
        this->destino.set_label("Elegir Destino");
        this->seleccionarDestinos.signal_clicked().connect(sigc::mem_fun(*this, &VentanaViajes::OnButtonClickedSeleccionarDes));
        this->fixedDestinos.put(this->seleccionarDestinos, 30, 40);
        this->fixedDestinos.put(this->destino, 250, 43);


        this->add(this->fixedAerlonias);
        this->add(this->fixedDestinos);
        this->show_all_children();

    }//onButtonClickedCambiar

    //int conta=0;

    void OnButtonClickedSeleccionarDes() {

        for (int i = 0; i < aux->GetDestinos()->size(); i++) {
            if (destino.get_label() == aux->GetDestinos()->siguiente()->value->toString()) {
                auxDest = aux->GetDestinos()->siguiente()->prev->value;

            }
        }

        this->fixedDestinos.~Fixed();

        this->fixedHorarios.put(this->fondo2, 0, 0);
        this->seleccionarHorarios.set_label("Seleccionar Horarios");
        this->horario.set_label("Elegir Hora");
        this->seleccionarHorarios.signal_clicked().connect(sigc::mem_fun(*this, &VentanaViajes::OnButtonClickedSeleccionarHor));
        this->fixedHorarios.put(this->seleccionarHorarios, 30, 40);
        this->fixedHorarios.put(this->horario, 250, 43);



        m_refTreeModel = Gtk::ListStore::create(m_Columns);
        m_Combo.set_model(m_refTreeModel);

        //Fill the ComboBox's Tree Model:

        Gtk::TreeModel::Row row = *(m_refTreeModel->append());

        for (int j = 0; j < auxDest->GetHorarios()->getSize(); j++) {
            if (j == 0) {
                row[m_Columns.m_col_horarios] = auxDest->GetHorarios()->getNodo(j)->toString();
                m_Combo.set_active(row);

            } else {

                row = *(m_refTreeModel->append());
                row[m_Columns.m_col_horarios] = auxDest->GetHorarios()->getNodo(j)->toString();


            }

        }


        m_Combo.pack_start(m_Columns.m_col_horarios);
        m_Combo.pack_start(m_cell);

        this->fixedHorarios.put(this->m_Combo, 250, 100);

        this->add(this->fixedDestinos);
        this->add(this->fixedHorarios);
        this->show_all_children();

    } //OnButtonClickedSeleccionarDes

    void OnButtonClickedSeleccionarHor() {



    }


};

#endif /* VENTANAVIAJES_H */

