#ifndef HISTORIAL_H
#define HISTORIAL_H

#include <gtkmm.h>
#include "Historial.h"
#include "Util.h"
#include "ColaEnlazada.h"
#include "Avion.h"
#include "ArbolBinarioBusqueda.h"

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

        avionAvi1 = new Avion("El Skipper");
        avionAvi2 = new Avion("Airbus100");
        avionLat1 = new Avion("JL608");
        avionLat2 = new Avion("El Batman DC");
        avionAmer1 = new Avion("Perla Negra-6");
        avionAmer2 = new Avion("Airbus A-319");


        arbolAvianca->insertar(avionAvi1);
        arbolAvianca->insertar(avionAvi2);

        arbolLatam->insertar(avionLat1);
        arbolLatam->insertar(avionLat2);

        arbolAmerican->insertar(avionAmer1);
        arbolAmerican->insertar(avionAmer2);


        aviones.push_back(avionAvi2->GetNombre());
        aviones.push_back(avionAmer2->GetNombre());

        aviones.push_back(avionLat2->GetNombre());
        aviones.push_back(avionAvi1->GetNombre());

        aviones.push_back(avionLat1->GetNombre());
        aviones.push_back(avionAmer1->GetNombre());



        this->add(this->fixed);
        this->show_all_children();

    }

    void onButtonClickedL() {
        cout << "ENTRA CLICKED" << endl;
        string ss = "";

        ss += "Latam: \n \n" + this->arbolLatam->salida() + "\n \n" + "Avianca: \n \n" + this->arbolAvianca->salida() + "\n \n" + "American: \n \n" + this->arbolAmerican->salida();

        Glib::RefPtr<Gtk::TextBuffer>resultado;
        resultado = Gtk::TextBuffer::create();
        resultado->set_text(ss);
        this->info.set_buffer(resultado);
    }

    void onButtonClickedLG() {
        cout << "ENTRA CLICKED" << endl;

        char *nombres[aviones.size()];
        char nombre [25];
        char *letra;
        int i, j, n = sizeof (nombres) / sizeof (char*);


        for (i = 0; i < n; i++)//Ciclo q va pidiendo los nombres
        {
            fgets(nombre, sizeof (aviones[i]), stdin); //guarda la  longitud de la palabra en la variable nombre
            letra = strchr(nombre, '\n'); //localiza o ubica al apuntador letra en los caracteres empezando por el salto de linea
            if (letra != NULL) {//si temp no es un elemento nulo
                *letra = '\0';
                nombres[i] = strdup(nombre);
            }
        }


        for (i = 0; i < n; i++) {//Ciclo q realiza el proceso de ordenamiento, recorre el apuntador la cadena para ordenar
            for (j = n - 1; j > 0; j--) {
                if (strcmp(nombres[j], nombres[j - 1]) < 0) {
                    letra = nombres[j];
                    nombres[j] = nombres[j - 1];
                    nombres[j - 1] = letra;

                }

            }
        }


        for (i = 0; i < n; i++)//ciclo q muestra los nombres ya ordenados q aparecera en pantalla
        {
            printf("%d: %s\n", i + 1, nombres[i]);
        }
        Glib::RefPtr<Gtk::TextBuffer>resultado;
        resultado = Gtk::TextBuffer::create();
        resultado->set_text("ooi");
        this->infoGen.set_buffer(resultado);
    }

private:
    Gtk::Fixed fixed;
    Gtk::TextView info;
    Gtk::Button lA;
    Gtk::TextView infoGen;
    Gtk::Button lG;


    vector<string> aviones;

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

