#ifndef AVION_H
#define AVION_H

#include "Avion.h"

#include <string>

using namespace std;

class Avion {
    //atributo
    string nombre;
    int x;
    int y;
    int horas;

public:
    //Métodos
    Avion(string nombre, int x, int y);
    Avion(string nombre, int horas);
    void SetNombre(string nombre);
    string GetNombre() const;
    void SetX(int x);
    int GetX() const;
    void SetY(int y);
    int GetY() const;
    int GetHoras() const;
    string toString();
    string toStringH();

};

#endif /* AVION_H */

