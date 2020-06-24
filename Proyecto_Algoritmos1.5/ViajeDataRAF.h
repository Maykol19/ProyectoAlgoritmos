#ifndef VIAJEDATARAF_H
#define VIAJEDATARAF_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <memory>
#include <bits/stl_vector.h>
#include "Viaje.h"

using namespace std;

class ViajeDataRAF : public fstream {
    
public:

    ViajeDataRAF() : fstream("VIAJE.dat", ios::in | ios::out | ios::binary) {
        if (!good()) { // saber si es archivo existe de lo contrario se crea
            open("VIAJE.dat", ios::in | ios::out | ios::trunc | ios::binary);
        } // if
    } // constructor

    void registrarViaje(Viaje &viaje) {
        clear();
        seekg(0, ios::end);
        write(reinterpret_cast<char *> (&viaje), sizeof (Viaje));
    }//fin guardarAvatar    
    
    

    Viaje obtenerViaje(long n) {
        Viaje viaje;
        clear();
        seekg(n * sizeof (Viaje), ios::beg);
        read(reinterpret_cast<char *> (&viaje), sizeof (Viaje));

        return viaje;
    }
    
    vector<Viaje>* cargarViajes() {
        int i = 1;
        vector<Viaje>* temp = new vector<Viaje>();
        Viaje viaje = obtenerViaje(0);

        while (strcmp(viaje.GetNombreAe(), "NULL") != 0) {
            temp->push_back(viaje);
            viaje = obtenerViaje(i);
            i++;
        }//while

        vector<Viaje>* vectorViaje = new vector<Viaje>();
        vectorViaje->push_back(temp->at(0));
        int conta = 0;
        for (int i = 1; i < temp->size(); i++) {
            for (int j = 0; j < vectorViaje->size(); j++) {

                if (temp->at(i).toString() == vectorViaje->at(j).toString()) {
                    conta++;
                }

            }
            if (conta == 0) {
                vectorViaje->push_back(temp->at(i));
            }
            conta = 0;
        }

        return vectorViaje;
    } //obtenerVector


    int obtenerIndice(char* nombre) {

        vector<Viaje>* viajeBuscar = cargarViajes();
        for (int i = 0; i < viajeBuscar->size(); i++) {
            if (strcmp(viajeBuscar->at(i).GetNombreAe(), nombre) == 0) {
                return i;
            }
        }
        return -1;
    }//indice

    Viaje buscarViaje(char* nombreA) {

        vector<Viaje>* viajeBuscar = cargarViajes();

        for (int i = 0; i < viajeBuscar->size(); i++) {
            if (strcmp(viajeBuscar->at(i).GetNombreAe(), nombreA) == 0) {
                return viajeBuscar->at(i);
            }
        }
        Viaje vacio;
        return vacio;
    }//indice

};





#endif /* VIAJEDATARAF_H */

