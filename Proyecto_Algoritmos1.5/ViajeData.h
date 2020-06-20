#ifndef VIAJEDATA_H
#define VIAJEDATA_H

#include <fstream>
#include <vector>
#include <string.h>
#include <string>

#include "Viaje.h"

using namespace std;

class ViajeData {
public:

    ViajeData() {
    }//constructor

    void write(Viaje* viaje) {
        cout << "Entra write" << endl;
        ofstream file;
        file.open("Viajes.txt", ios::app);
        if (file.fail()) {
            cout << "Error al abrir el archivo";
        }
        file << viaje->GetAerolina()->GetNombre() << "," << viaje->GetDestino()->GetPaisSalida() << "," << viaje->GetDestino()->GetPaisLlegada() 
                << "," << viaje->GetHorario()->GetSalida() << endl;
        file.close();
    }//write

    void read() {
        string content;
        ifstream file;
        vector<string> travelListVector;
        file.open("Viajes.txt", ios::in);
        if (file.fail()) {
            cout << "Error al abrir el archivo";
        }
        while (!file.eof()) { //mientras no este en la linea final
            file>>content;
            travelListVector = split(content, ',');
            //this->viajesList.push_back(new Viaje(travelListVector[0], travelListVector[1], travelListVector[2]));
        }
        file.close();
    }//read

    vector<string> split(string linea, char token) {
        std::string buff;
        std::vector<std::string>
                resultVector;

        for (int i = 0; i < linea.length(); i++) {
            if (linea[i] != token)
                buff += linea[i];
            else if (linea[i] == token && buff != "") {
                resultVector.push_back(buff);
                buff = "";
            }
        }
        if (buff != "")
            resultVector.push_back(buff);
        return resultVector;
    }//split
    
    vector<Viaje*> getLista() {
        return this->viajesList;
    }//getLista

private:
    vector<Viaje*> viajesList;

};

#endif /* VIAJEDATA_H */

