#ifndef VIAJE_H
#define VIAJE_H

#include <ostream>
#include <iostream>
#include <string>
#include <sstream>
#include "Aerolineas.h"

using namespace std;

class Viaje {
public:

    Viaje() {
        strcpy(this->nombreAe, "NULL");
        strcpy(this->destSalida, "NULL");
        strcpy(this->desLlegada, "NULL");
        strcpy(this->horaSalida, "NULL");
        strcpy(this->horaLlegada, "NULL");
        strcpy(this->avion, "NULL");
    }//constructor

    Viaje(char* nombreAero, char* destSalida, char* destLlegada, char* horaSalida, char* horaLlegada, char* avion) {
        strcpy(this->nombreAe, nombreAero);
        strcpy(this->destSalida, destSalida);
        strcpy(this->desLlegada, destLlegada);
        strcpy(this->horaSalida, horaSalida);
        strcpy(this->horaLlegada, horaLlegada);
        strcpy(this->avion, avion);
    }//constructor

    //getters and setters
    char* GetHoraLlegada() {
        return horaLlegada;
    }

    char* GetHoraSalida() {
        return horaSalida;
    }

    char* GetDesLlegada() {
        return desLlegada;
    }

    char* GetDestSalida() {
        return destSalida;
    }

    char* GetNombreAe() {
        return nombreAe;
    }
    
    char* GetAvion() {
        return avion;
    }

    string toString() {

        stringstream s;
        s << nombreAe << "                 "<< destSalida << "-" << desLlegada << "              "<< horaSalida << "              " << avion;
        return s.str();

    }//toString

private:
    //VariableS
    char nombreAe[30];
    char destSalida[30];
    char desLlegada[30];
    char horaSalida[30];
    char horaLlegada[30];
    char avion[30];
    
};

#endif /* VIAJE_H */

