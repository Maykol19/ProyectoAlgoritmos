#ifndef ADMINISTRATIVO_H
#define ADMINISTRATIVO_H

#include <iostream>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include "string.h"
#include <string>
#include <regex>

using namespace std;

class Administrativo {
public:

    Administrativo() {
    }//Constructor

    Administrativo(string nombre, string numeroID, string contrasena) {
        this->nombre = nombre;
        this->numeroID = numeroID;
        this->contrasena = contrasena;
    }//Constructor

    //getters and setters
    void setNombre(string nombre) {
        this->nombre = nombre;
    }

    string getNombre() const {
        return nombre;
    }

    void setContrasena(string contrasena) {
        this->contrasena = contrasena;
    }

    string getContrasena() const {
        return contrasena;
    }

    void setNumeroID(string numeroID) {
        this->numeroID = numeroID;
    }

    string getNumeroID() const {
        return numeroID;
    }

private:
    //Variables
    string nombre;
    string numeroID;
    string contrasena;
    
};

#endif /* ADMINISTRATIVO_H */

