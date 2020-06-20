#ifndef VIAJE_H
#define VIAJE_H

#include <iostream>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include "string.h"
#include "Aerolineas.h"
#include <string>

using namespace std;

class Viaje {
    
public:
    Viaje(Aerolineas* aerolinea, Destinos* destino, Horarios* horario) {
        this->aerolina = aerolinea;
        this->destino = destino;
        this->horario = horario;
    }

    void SetHorario(Horarios* horario) {
        this->horario = horario;
    }

    Horarios* GetHorario() const {
        return horario;
    }

    void SetDestino(Destinos* destino) {
        this->destino = destino;
    }

    Destinos* GetDestino() const {
        return destino;
    }

    void SetAerolina(Aerolineas* aerolina) {
        this->aerolina = aerolina;
    }

    Aerolineas* GetAerolina() const {
        return aerolina;
    }//constructor
    
private:
    //Variables
    Aerolineas* aerolina;
    Destinos* destino;
    Horarios* horario;

};

#endif /* VIAJE_H */

