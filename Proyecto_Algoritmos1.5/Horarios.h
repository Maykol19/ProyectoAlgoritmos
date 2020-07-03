#ifndef HORARIOS_H
#define HORARIOS_H

#include <string>

using namespace std;

class Horarios {
    
    //atributo
    string nombreAerolinea;
    string llegada;
    string salida;
    string nombreLlegada;
    string nombreSalida;
    
public:
    //Métodos
    Horarios(string llegada, string salida);
    Horarios();
    void SetSalida(string salida);
    string GetSalida() const;
    void SetLlegada(string llegada);
    string GetLlegada() const;
    string toString();
    string GetNombreSalida() const;
    string GetNombreLlegada() const;
    string GetNombreAerolinea() const;

};

#endif /* HORARIOS_H */

