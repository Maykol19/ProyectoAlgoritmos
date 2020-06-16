#ifndef ARISTA_H
#define ARISTA_H
#include "Vertice.h"

template <typename Destinos>


class Arista {
private:
    int peso;
    Destinos v1, v2;

public:

    Arista(Destinos v1, Destinos v2, int peso) {
        this.peso = peso;
        this.v1 = v1;
        this.v2 = v2;
    }

    int getPeso() {
        return peso;
    }

    void setPeso(int peso) {
        this.peso = peso;
    }

    Destinos getV1() {
        return v1;
    }

    void setV1(Destinos v1) {
        this.v1 = v1;
    }

    Destinos getV2() {
        return v2;
    }

    void setV2(Destinos v2) {
        this.v2 = v2;
    }

    void draw(const Cairo::RefPtr<Cairo::Context>& cr) {
    }

};


#endif /* ARISTA_H */

