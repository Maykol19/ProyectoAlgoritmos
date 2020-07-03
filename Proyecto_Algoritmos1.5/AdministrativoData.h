#ifndef ADMINISTRATIVODATA_H
#define ADMINISTRATIVODATA_H

#include "Administrativo.h"
#include <fstream>
#include <vector>
#include <string.h>
#include <string>

using namespace std;

class AdministrativoData {
public:

    AdministrativoData() {
    }//constructor

    //Método que crea y guarda en el archivo los datos del administrador
    void write(Administrativo* administrativo) {
        
        ofstream file;
        file.open("Administrativo.txt", ios::app);
        
        if (file.fail()) {
            cout << "Error al abrir el archivo";
        }
        file << administrativo->getNombre() << "," << administrativo->getNumeroID() << "," << administrativo->getContrasena() << endl;
        file.close();
        
    }//write

    //Método que lee los datos del archivo
    void read() {
        
        string content;
        ifstream file;
        vector<string> adminListVector;
        file.open("Administrativo.txt", ios::in);
        
        if (file.fail()) {
            cout << "Error al abrir el archivo";
        }
        while (!file.eof()) { //mientras no este en la linea final
            file>>content;
            adminListVector = split(content, ',');
            this->administrativoList.push_back(new Administrativo(adminListVector[0], adminListVector[1], adminListVector[2]));
        }
        file.close();
        
    }//read

    //Método que se encarga de separar distintos datos dentro del archivo
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

    //Método que se encargar de verificar que los usuarios administrativos estén registrados
    bool checkPassword(string usernameSearch, string passwordSearch) {

        bool found = false;

        for (int i = 0; i < administrativoList.size(); i++) {
            if (administrativoList[i]->getNombre() == usernameSearch) {
                if (administrativoList[i]->getContrasena() == passwordSearch) {
                    found = true;
                    break;
                } else {
                    found = false;
                }//else
            }//if
        }//for
        return found;
        
    }//check password

    //gett and sett
    vector<Administrativo*> getLista() {
        return this->administrativoList;
    }//getLista

    //Método que valida el id de los administradores
    bool validateID(string idSearch) {
        
        bool playerFound = false;

        if (playerFound == false) {
            for (int i = 0; i < administrativoList.size(); i++) {
                if (administrativoList[i]->getNumeroID() == idSearch) {
                    playerFound = true;
                    break;
                }
            }
        }
        return playerFound;
        
    }//validateID

private:
    //Atributo
    vector<Administrativo*> administrativoList;
    
};

#endif /* ADMINISTRATIVODATA_H */

