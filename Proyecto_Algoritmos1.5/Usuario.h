#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include "string.h"
#include <string>
#include <regex>

using namespace std;

class Usuario {
public:

    Usuario() {
    }//Constructor

    Usuario(string nombre, string genero, string edad, string numPasaporte, string nacionalidad) {
        this->nombre = nombre;
        this->edad = edad;
        this->genero = genero;
        this->numPasaporte = numPasaporte;
        this->nacionalidad = nacionalidad;
    }//Constructor

    //getters and setters
    void setNacionalidad(string nacionalidad) {
        this->nacionalidad = nacionalidad;
    }

    string getNacionalidad() const {
        return nacionalidad;
    }

    void setNumPasaporte(string numPasaporte) {
        this->numPasaporte = numPasaporte;
    }

    string getNumPasaporte() const {
        return numPasaporte;
    }

    void setGenero(string genero) {
        this->genero = genero;
    }

    string getGenero() const {
        return genero;
    }

    void setNombre(string nombre) {
        this->nombre = nombre;
    }

    string getNombre() const {
        return nombre;
    }

    void setEdad(string edad) {
        this->edad = edad;
    }

    string getEdad() const {
        return edad;
    }


private:
    //Variables
    string nombre;
    string genero;
    string edad;
    string numPasaporte;
    string nacionalidad;
    
};

#endif /* USUARIO_H */

