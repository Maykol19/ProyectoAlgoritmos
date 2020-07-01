#ifndef UTIL_H
#define UTIL_H

#include "Avion.h"
#include "ArbolBinarioBusqueda.h"


class Util {
public:

    //Cosas por hacer:
    //Grafos con avión ?
    //Historial de vuelos con árboles
    //Administrador: Ingresar datos nuevos(Aerolineas, Destinos y Horarios)
    
    Util() {
        aerolinea1 = new Aerolineas("Avianca");
        aerolinea2 = new Aerolineas("Latam");
        aerolinea3 = new Aerolineas("American");

        listaA = new DoublyLinkedCircular<Aerolineas*>();

        destino1 = new Destinos("Avianca", "Costa Rica", "Argentina", " ", "El Skipper");
        destino2 = new Destinos("Avianca", "Costa Rica", "Chile", "China", "Airbus100");
        destino3 = new Destinos("Latam", "Costa Rica", "Panama", " ", "JL608");
        destino4 = new Destinos("Latam", "Espana", "Holanda", "Camerun", "El Batman DC");
        destino5 = new Destinos("American", "Japon", "Afganistan", "USA", "Perla Negra-6");
        destino6 = new Destinos("American", "Costa Rica", "USA", "Mexico", "Airbus A-319");

        listaAvi = new DoublyLinkedCircular<Destinos*>();
        listaLat = new DoublyLinkedCircular<Destinos*>();
        listaAme = new DoublyLinkedCircular<Destinos*>();

        //CR-AR
        CR_AR1 = new Horarios("1:00", "8:00");
        CR_AR2 = new Horarios("4:00", "11:00");
        
        //CR--CH
        CR_Ch1 = new Horarios("9:00", "10:25");
        CR_Ch2 = new Horarios("13:00", "14:25");
        
        //CR--PA
        CR_PA1 = new Horarios("10:00", "19:00");
        CR_PA2 = new Horarios("7:00", "10:00");
        
        //ESP-HO
        ESP_HO1 = new Horarios("7:00", "9:25");
        ESP_HO2 = new Horarios("11:00", "13:50");
        
        //JA--AF
        JA_AF1 = new Horarios("11:00", "18:50");
        JA_AF2 = new Horarios("17:00", "24:50");
        
        //CR--USA
        CR_USA1 = new Horarios("15:00", "21:30");
        CR_USA2 = new Horarios("19:00", "1:30");

        cola1Avi = new ColaEnlazada<Horarios*>();
        cola2Avi = new ColaEnlazada<Horarios*>();
        cola1Lat = new ColaEnlazada<Horarios*>();
        cola2Lat = new ColaEnlazada<Horarios*>();
        cola1Ame = new ColaEnlazada<Horarios*>();
        cola2Ame = new ColaEnlazada<Horarios*>();
        
        avionAvi1 = new Avion("El Skipper");
        avionAvi2 = new Avion("Airbus100");
        avionLat1 = new Avion("JL608");
        avionLat2 = new Avion("El Batman DC");
        avionAmer1 = new Avion("Perla Negra-6");
        avionAmer2 = new Avion("Airbus A-319");
        
        arbolAvianca = new ArbolBinarioBusqueda<Avion*>();
        arbolLatam = new ArbolBinarioBusqueda<Avion*>();
        arbolAmerican = new ArbolBinarioBusqueda<Avion*>();

    }

    void llenar() {


        listaA->insert(aerolinea1);
        listaA->insert(aerolinea2);
        listaA->insert(aerolinea3);

        listaAvi->insert(destino1);
        listaAvi->insert(destino2);
        listaLat->insert(destino3);
        listaLat->insert(destino4);
        listaAme->insert(destino5);
        listaAme->insert(destino6);


        cola1Avi->enQueue(CR_AR1);
        cola1Avi->enQueue(CR_AR2);
        cola2Avi->enQueue(CR_Ch1);
        cola2Avi->enQueue(CR_Ch2);
        cola1Lat->enQueue(CR_PA1);
        cola1Lat->enQueue(CR_PA2);
        cola2Lat->enQueue(ESP_HO1);
        cola2Lat->enQueue(ESP_HO2);
        cola1Ame->enQueue(JA_AF1);
        cola1Ame->enQueue(JA_AF2);
        cola2Ame->enQueue(CR_USA1);
        cola2Ame->enQueue(CR_USA2);

        destino1->SetHorarios(cola1Avi);
        destino2->SetHorarios(cola2Avi);
        destino3->SetHorarios(cola1Lat);
        destino4->SetHorarios(cola2Lat);
        destino5->SetHorarios(cola1Ame);
        destino6->SetHorarios(cola2Ame);
        
        arbolAvianca->insertar(avionAvi1);
        arbolAvianca->insertar(avionAvi2);
        
        arbolLatam->insertar(avionLat1);
        arbolLatam->insertar(avionLat2);
        
        arbolAmerican->insertar(avionAmer1);
        arbolAmerican->insertar(avionAmer2);

    }

    ColaEnlazada<Horarios*>* getCola2Ame() const {
        return cola2Ame;
    }

    ColaEnlazada<Horarios*>* getCola1Ame() const {
        return cola1Ame;
    }

    ColaEnlazada<Horarios*>* getCola2Lat() const {
        return cola2Lat;
    }

    ColaEnlazada<Horarios*>* getCola1Lat() const {
        return cola1Lat;
    }

    ColaEnlazada<Horarios*>* getCola2Avi() const {
        return cola2Avi;
    }

    ColaEnlazada<Horarios*>* getCola1Avi() const {
        return cola1Avi;
    }

    DoublyLinkedCircular<Destinos*>* getListaAme() const {
        return listaAme;
    }

    DoublyLinkedCircular<Destinos*>* getListaLat() const {
        return listaLat;
    }

    DoublyLinkedCircular<Destinos*>* getListaAvi() const {
        return listaAvi;
    }

    DoublyLinkedCircular<Aerolineas*>* getListaA() const {
        return listaA;
    }

    ArbolBinarioBusqueda<Avion*>* getArbolAmerican() const {
        return arbolAmerican;
    }

    ArbolBinarioBusqueda<Avion*>* getArbolLatam() const {
        return arbolLatam;
    }

    ArbolBinarioBusqueda<Avion*>* getArbolAvianca() const {
        return arbolAvianca;
    }
    
private:

    Aerolineas* aerolinea1;
    Aerolineas* aerolinea2;
    Aerolineas* aerolinea3;

    DoublyLinkedCircular<Aerolineas*>* listaA;

    Destinos* destino1;
    Destinos* destino2;
    Destinos* destino3;
    Destinos* destino4;
    Destinos* destino5;
    Destinos* destino6;

    DoublyLinkedCircular<Destinos*>* listaAvi;
    DoublyLinkedCircular<Destinos*>* listaLat;
    DoublyLinkedCircular<Destinos*>* listaAme;

    //CR-AR
    Horarios* CR_AR1;
    Horarios* CR_AR2;
    //CR--CH
    Horarios* CR_Ch1;
    Horarios* CR_Ch2;
    //CR--PA
    Horarios* CR_PA1;
    Horarios* CR_PA2;
    //ESP-HO
    Horarios* ESP_HO1;
    Horarios* ESP_HO2;
    //JA--AF
    Horarios* JA_AF1;
    Horarios* JA_AF2;
    //CR--USA
    Horarios* CR_USA1;
    Horarios* CR_USA2;

    ColaEnlazada<Horarios*>* cola1Avi;
    ColaEnlazada<Horarios*>* cola2Avi;
    ColaEnlazada<Horarios*>* cola1Lat;
    ColaEnlazada<Horarios*>* cola2Lat;
    ColaEnlazada<Horarios*>* cola1Ame;
    ColaEnlazada<Horarios*>* cola2Ame;
    
    Avion* avionAvi1;
    Avion* avionAvi2;
    Avion* avionLat1;
    Avion* avionLat2;
    Avion* avionAmer1;
    Avion* avionAmer2;
    
    ArbolBinarioBusqueda<Avion*>* arbolAvianca;
    ArbolBinarioBusqueda<Avion*>* arbolLatam;
    ArbolBinarioBusqueda<Avion*>* arbolAmerican;
    
};



#endif /* UTIL_H */

