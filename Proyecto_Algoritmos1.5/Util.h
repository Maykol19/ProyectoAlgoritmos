#ifndef UTIL_H
#define UTIL_H

#include "Avion.h"
#include "ArbolBinarioBusqueda.h"
#include "Aerolineas.h"

class Util {
    
public:

    Util() {
        aerolinea1 = new Aerolineas("Avianca");
        aerolinea2 = new Aerolineas("Volaris");
        aerolinea3 = new Aerolineas("American");
        aerolinea4 = new Aerolineas("Latam");
        aerolinea5 = new Aerolineas("Volaton");

        listaA = new DoublyLinkedCircular<Aerolineas*>();

        destino1 = new Destinos("Avianca", "Costa Rica", "Argentina", " ", "El Skipper");
        destino2 = new Destinos("Avianca", "Costa Rica", "Chile", "China", "Airbus100");
        destino3 = new Destinos("Latam", "Costa Rica", "Panama", " ", "JL608");
        destino4 = new Destinos("Latam", "Espana", "Holanda", "Camerun", "El Batman DC");
        destino5 = new Destinos("American", "Japon", "Afganistan", "USA", "Perla Negra-6");
        destino6 = new Destinos("American", "Costa Rica", "USA", "Mexico", "Airbus A-319");

        destino7 = new Destinos("Volaris", "España", "Alemania", " ", "Avioncito 2.0");
        destino8 = new Destinos("Volaris", "Rusia", "Holanda", "Camerun", "Bamba Negra");
        destino9 = new Destinos("Volaton", "Dubai", "Afganistan", "USA", "Coronavairus");
        destino0 = new Destinos("Volaton", "Argetina", "Colombia", "Mexico", "El Bicho");

        listaAvi = new DoublyLinkedCircular<Destinos*>();
        listaLat = new DoublyLinkedCircular<Destinos*>();
        listaAme = new DoublyLinkedCircular<Destinos*>();
        listaVolar = new DoublyLinkedCircular<Destinos*>();
        listaVolat = new DoublyLinkedCircular<Destinos*>();

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

        //ESP--ALE
        ESP_ALE1 = new Horarios("09:00", "11:20");
        ESP_ALE2 = new Horarios("20:00", "22:20");
        //RUS--HOL
        RUS_HOL1 = new Horarios("01:00", "8:50");
        RUS_HOL2 = new Horarios("13:00", "20:50");
        //DUB--AFG
        DUB_AFG1 = new Horarios("09:00", "11:40");
        DUB_AFG2 = new Horarios("14:00", "16:40");
        //ARG--COL
        ARG_COL1 = new Horarios("01:00", "06:20");
        ARG_COL2 = new Horarios("15:00", "20:20");

        cola1Avi = new ColaEnlazada<Horarios*>();
        cola2Avi = new ColaEnlazada<Horarios*>();
        cola1Lat = new ColaEnlazada<Horarios*>();
        cola2Lat = new ColaEnlazada<Horarios*>();
        cola1Ame = new ColaEnlazada<Horarios*>();
        cola2Ame = new ColaEnlazada<Horarios*>();

        cola1Volar = new ColaEnlazada<Horarios*>();
        cola2Volar = new ColaEnlazada<Horarios*>();
        cola1Volat = new ColaEnlazada<Horarios*>();
        cola2Volat = new ColaEnlazada<Horarios*>();

    }//init

    void llenar() {

        listaA->insert(aerolinea1);
        listaA->insert(aerolinea2);
        listaA->insert(aerolinea3);
        listaA->insert(aerolinea4);
        listaA->insert(aerolinea5);

        listaAvi->insert(destino1);
        listaAvi->insert(destino2);
        listaLat->insert(destino3);
        listaLat->insert(destino4);
        listaAme->insert(destino5);
        listaAme->insert(destino6);

        listaVolar->insert(destino7);
        listaVolar->insert(destino8);
        listaVolat->insert(destino9);
        listaVolat->insert(destino0);

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

        cola1Volar->enQueue(ESP_ALE1);
        cola1Volar->enQueue(ESP_ALE2);
        cola2Volar->enQueue(RUS_HOL1);
        cola2Volar->enQueue(RUS_HOL2);

        cola1Volat->enQueue(DUB_AFG1);
        cola1Volat->enQueue(DUB_AFG2);
        cola2Volat->enQueue(ARG_COL1);
        cola2Volat->enQueue(ARG_COL2);

        destino1->SetHorarios(cola1Avi);
        destino2->SetHorarios(cola2Avi);
        destino3->SetHorarios(cola1Lat);
        destino4->SetHorarios(cola2Lat);
        destino5->SetHorarios(cola1Ame);
        destino6->SetHorarios(cola2Ame);

        destino7->SetHorarios(cola1Volar);
        destino8->SetHorarios(cola2Volar);
        destino9->SetHorarios(cola1Volat);
        destino0->SetHorarios(cola2Volat);

    }//llenar

    //getters and setters
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

    ColaEnlazada<Horarios*>* getCola2Volat() const {
        return cola2Volat;
    }

    ColaEnlazada<Horarios*>* getCola1Volat() const {
        return cola1Volat;
    }

    ColaEnlazada<Horarios*>* getCola2Volar() const {
        return cola2Volar;
    }

    ColaEnlazada<Horarios*>* getCola1Volar() const {
        return cola1Volar;
    }

    DoublyLinkedCircular<Destinos*>* getListaVolat() const {
        return listaVolat;
    }

    DoublyLinkedCircular<Destinos*>* getListaVolar() const {
        return listaVolar;
    }
  
private:

    Aerolineas* aerolinea1;
    Aerolineas* aerolinea2;
    Aerolineas* aerolinea3;
    Aerolineas* aerolinea4;
    Aerolineas* aerolinea5;

    DoublyLinkedCircular<Aerolineas*>* listaA;

    Destinos* destino1;
    Destinos* destino2;
    Destinos* destino3;
    Destinos* destino4;
    Destinos* destino5;
    Destinos* destino6;
    Destinos* destino7;
    Destinos* destino8;
    Destinos* destino9;
    Destinos* destino0;

    DoublyLinkedCircular<Destinos*>* listaAvi;
    DoublyLinkedCircular<Destinos*>* listaLat;
    DoublyLinkedCircular<Destinos*>* listaAme;
    DoublyLinkedCircular<Destinos*>* listaVolar;
    DoublyLinkedCircular<Destinos*>* listaVolat;

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
    //ESP--ALE
    Horarios* ESP_ALE1;
    Horarios* ESP_ALE2;
    //RUS--HOL
    Horarios* RUS_HOL1;
    Horarios* RUS_HOL2;
    //DUB--AFG
    Horarios* DUB_AFG1;
    Horarios* DUB_AFG2;
    //ARG--COL
    Horarios* ARG_COL1;
    Horarios* ARG_COL2;

    ColaEnlazada<Horarios*>* cola1Avi;
    ColaEnlazada<Horarios*>* cola2Avi;
    ColaEnlazada<Horarios*>* cola1Lat;
    ColaEnlazada<Horarios*>* cola2Lat;
    ColaEnlazada<Horarios*>* cola1Ame;
    ColaEnlazada<Horarios*>* cola2Ame;

    ColaEnlazada<Horarios*>* cola1Volar;
    ColaEnlazada<Horarios*>* cola2Volar;
    ColaEnlazada<Horarios*>* cola1Volat;
    ColaEnlazada<Horarios*>* cola2Volat;

};

#endif /* UTIL_H */

