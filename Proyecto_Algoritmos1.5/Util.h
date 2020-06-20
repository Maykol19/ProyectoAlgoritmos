#ifndef UTIL_H
#define UTIL_H

class Util {
public:

    Util() {
        aerolinea1 = new Aerolineas("Avianca");
        aerolinea2 = new Aerolineas("Latam");
        aerolinea3 = new Aerolineas("American");

        listaA = new DoublyLinkedCircular<Aerolineas*>();

        destino1 = new Destinos("Avianca", "Costa Rica", "Argentina", " ");
        destino2 = new Destinos("Avianca", "Costa Rica", "Chile", "China");
        destino3 = new Destinos("Latam", "Costa Rica", "Panama", " ");
        destino4 = new Destinos("Latam", "Espana", "Holanda", "Camerun");
        destino5 = new Destinos("American", "Japon", "Afganistan", "USA");
        destino6 = new Destinos("American", "Costa Rica", "USA", "Mexico");

        listaAvi = new DoublyLinkedCircular<Destinos*>();
        listaLat = new DoublyLinkedCircular<Destinos*>();
        listaAme = new DoublyLinkedCircular<Destinos*>();

        //CR-AR
        CR_AR1 = new Horarios("1:00", "2:00");
        CR_AR2 = new Horarios("4:00", "6:00");
        //CR--CH
        CR_Ch1 = new Horarios("13:00", "18:00");
        CR_Ch2 = new Horarios("9:00", "10:00");
        //CR--PA
        CR_PA1 = new Horarios("10:00", "19:00");
        CR_PA2 = new Horarios("7:00", "10:00");
        //ESP-HO
        ESP_HO1 = new Horarios("1:00", "8:00");
        ESP_HO2 = new Horarios("4:00", "9:00");
        //JA--AF
        JA_AF1 = new Horarios("6:00", "8:00");
        JA_AF2 = new Horarios("17", "20:00");
        //CR--USA
        CR_USA1 = new Horarios("13:00", "19:00");
        CR_USA2 = new Horarios("7:00", "16:00");

        cola1Avi = new ColaEnlazada<Horarios*>();
        cola2Avi = new ColaEnlazada<Horarios*>();
        cola1Lat = new ColaEnlazada<Horarios*>();
        cola2Lat = new ColaEnlazada<Horarios*>();
        cola1Ame = new ColaEnlazada<Horarios*>();
        cola2Ame = new ColaEnlazada<Horarios*>();


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


};



#endif /* UTIL_H */