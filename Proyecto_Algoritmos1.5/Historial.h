#ifndef HISTORIAL_H
#define HISTORIAL_H

#include <gtkmm.h>
#include "Historial.h"
#include "Util.h"
#include "ColaEnlazada.h"
#include "ViajeDataRAF.h"

class Historial : public Gtk::Window {
public:

    Historial() {
        this->set_title("Historial");
        this->set_size_request(600, 600);

        arbolAvianca = new ArbolBinarioBusqueda<Avion*>();
        arbolLatam = new ArbolBinarioBusqueda<Avion*>();
        arbolAmerican = new ArbolBinarioBusqueda<Avion*>();

        init();
    }//constructor

    void init() {//inicializar la variables

        this->lA.set_label("Listado por Aerolineas");
        this->fixed.put(this->lA, 20, 10);
        this->lA.signal_clicked().connect(sigc::mem_fun(*this, &Historial::onButtonClickedL));

        this->info.set_size_request(100, 200);
        this->fixed.put(this->info, 50, 80);
        this->info.set_editable(false);

        this->lG.set_label("Listado General");
        this->fixed.put(this->lG, 200, 10);
        this->lG.signal_clicked().connect(sigc::mem_fun(*this, &Historial::onButtonClickedLG));

        this->infoGen.set_size_request(100, 200);
        this->fixed.put(this->infoGen, 210, 80);
        this->infoGen.set_editable(false);

        this->lH.set_label("Listado por horas");
        this->fixed.put(this->lH, 380, 10);
        this->lH.signal_clicked().connect(sigc::mem_fun(*this, &Historial::onButtonClickedLH));
        
        this->contTiquetes.set_label("Tiquetes Comprados:");
        this->fixed.put(this->contTiquetes, 10, 400);
        this->contTiquetes.signal_clicked().connect(sigc::mem_fun(*this, &Historial::onButtonClickedCont1));

        this->fixed.put(this->eContTiquete, 200, 400);

        this->infoHor.set_size_request(115, 200);
        this->fixed.put(this->infoHor, 390, 80);
        this->infoHor.set_editable(false);

        avionAvi1 = new Avion("El Skipper", 23);
        avionAvi2 = new Avion("Airbus100", 11);
        avionLat1 = new Avion("JL608", 29);
        avionLat2 = new Avion("El Batman DC", 10);
        avionAmer1 = new Avion("Perla Negra-6", 72);
        avionAmer2 = new Avion("Airbus A-319", 45);


        arbolAvianca->insertar(avionAvi1);
        arbolAvianca->insertar(avionAvi2);

        arbolLatam->insertar(avionLat1);
        arbolLatam->insertar(avionLat2);

        arbolAmerican->insertar(avionAmer1);
        arbolAmerican->insertar(avionAmer2);


        this->add(this->fixed);
        this->show_all_children();

    }

    void onButtonClickedL() {
        string ss = "";

        ss += "Latam: \n \n" + this->arbolLatam->salida() + "\n \n" + "Avianca: \n \n" + this->arbolAvianca->salida() + "\n \n" + "American: \n \n" + this->arbolAmerican->salida();

        Glib::RefPtr<Gtk::TextBuffer>resultado;
        resultado = Gtk::TextBuffer::create();
        resultado->set_text(ss);
        this->info.set_buffer(resultado);
    }

    void onButtonClickedLG() {

        char nombres[][50] = {"Airbus100", "Airbus A-319", "El Batman DC", "El Skipper", "JL608", "Perla Negra-6"};

        string salida = "";
        cout << "NOMBRES" << endl;
        for (int i = 0; i < 6; i++) {
            salida += (string) nombres[i] + "\n" + "\n";
        }
        Glib::RefPtr<Gtk::TextBuffer>resultado;
        resultado = Gtk::TextBuffer::create();
        resultado->set_text(salida);
        this->infoGen.set_buffer(resultado);
    }

    void onButtonClickedLH() {

        string salida = "";
        
        ViajeDataRAF* viajes= new ViajeDataRAF();
        
        cout<<"CONTADOR"<< viajes->contador()<<endl;

        salida += avionAmer1->toStringH() + "\n" + "\n" + avionAmer2->toStringH() + "\n" + "\n" + avionLat1->toStringH() + "\n" + "\n" +
                avionAvi1->toStringH() + "\n" + "\n" + avionAvi2->toStringH() + "\n" + "\n" + avionLat2->toStringH() + "\n";

        Glib::RefPtr<Gtk::TextBuffer>resultado;
        resultado = Gtk::TextBuffer::create();
        resultado->set_text(salida);
        this->infoHor.set_buffer(resultado);
    }
    
    void onButtonClickedCont1() {
        
        ViajeDataRAF* viaje = new ViajeDataRAF();

        stringstream s;
        s << viaje->contador();

        this->eContTiquete.set_text(s.str());
        
    }

private:
    Gtk::Fixed fixed;
    Gtk::TextView info;
    Gtk::Button lA;
    Gtk::TextView infoGen;
    Gtk::Button lG;
    Gtk::Button contTiquetes;
    Gtk::Entry eContTiquete;
    Gtk::TextView infoHor;
    Gtk::Button lH;

    Util* utilarbol;

    ArbolBinarioBusqueda<Avion*>* arbolAvianca;
    ArbolBinarioBusqueda<Avion*>* arbolLatam;
    ArbolBinarioBusqueda<Avion*>* arbolAmerican;


    Avion* avionAvi1;
    Avion* avionAvi2;
    Avion* avionLat1;
    Avion* avionLat2;
    Avion* avionAmer1;
    Avion* avionAmer2;

};

#endif /* HISTORIAL_H */

