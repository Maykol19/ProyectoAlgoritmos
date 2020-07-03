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
#include <iostream>
#include <ctime>

using namespace std;

class ViajeDataRAF : public fstream {
public:

    ViajeDataRAF() : fstream("VIAJE.dat", ios::in | ios::out | ios::binary) {
        if (!good()) { // saber si es archivo existe de lo contrario se crea
            open("VIAJE.dat", ios::in | ios::out | ios::trunc | ios::binary);
        } // if
    }//constructor

    //Método que crea y guarda en el archivo RAF los vuelos comprados
    void registrarViaje(Viaje &viaje) {

        clear();
        seekg(0, ios::end);
        write(reinterpret_cast<char *> (&viaje), sizeof (Viaje));

    }//registrarViaje 

    //Obtiene los vuelos del archivo RAF
    Viaje obtenerViaje(long n) {

        Viaje viaje;
        clear();
        seekg(n * sizeof (Viaje), ios::beg);
        read(reinterpret_cast<char *> (&viaje), sizeof (Viaje));

        return viaje;

    }//obtenerViaje

    //Método que se encarga de mostrar los vuelos en la tabla de vuelos del momento
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

        for (int i = 1; i < temp->size(); i++) {//Verifica que no muestre vuelos repetidos
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

    }//cargarViajes

    //LLeva la cuenta de cuántos tiquetes se han comprado para el informe
    int contador() {

        int i = 1, conta = 0;
        vector<Viaje>* temp2 = new vector<Viaje>();
        Viaje viaje = obtenerViaje(0);

        while (strcmp(viaje.GetNombreAe(), "NULL") != 0) {
            temp2->push_back(viaje);
            conta++;
            viaje = obtenerViaje(i);
            i++;
        }//while

        return conta;
        
    }//contador

    //Método que se encarga de mostrar los vuelos apartir de la hora de salida
    vector<Viaje>* cargarGrafo() {

        int i = 1, cont = 0;
        string salida = "";
        vector<Viaje>* aux = cargarViajes();
        vector<Viaje>* grafo = new vector<Viaje>();
        time_t curr_time;
        curr_time = time(NULL);
        tm *tm_local = localtime(&curr_time);
        char *token;
        Viaje viajeAux;

        for (int i = 0; i < aux->size(); i++) {
            viajeAux = aux->at(i);
            token = strtok(aux->at(i).GetHoraSalida(), ":");
            salida = (string) token;
            cont = stoi(salida);
            if (cont <= tm_local->tm_hour) {//Compara para saber cuales ya puede mostrar(salir) y cuales no
                grafo->push_back(viajeAux);
            }
        }
        return grafo;

    }//cargarGrafo

    //Obtiene índice del archivo RAF
    int obtenerIndice(char* nombre) {

        vector<Viaje>* viajeBuscar = cargarViajes();

        for (int i = 0; i < viajeBuscar->size(); i++) {
            if (strcmp(viajeBuscar->at(i).GetNombreAe(), nombre) == 0) {
                return i;
            }
        }
        return -1;

    }//obtenerIndice

    //Busca los viajes del archivo
    Viaje buscarViaje(char* nombreA) {

        vector<Viaje>* viajeBuscar = cargarViajes();

        for (int i = 0; i < viajeBuscar->size(); i++) {
            if (strcmp(viajeBuscar->at(i).GetNombreAe(), nombreA) == 0) {
                return viajeBuscar->at(i);
            }
        }
        Viaje vacio;
        return vacio;

    }//buscarViaje

};

#endif /* VIAJEDATARAF_H */

