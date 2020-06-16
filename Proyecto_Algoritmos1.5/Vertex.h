/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Vertex.h
 * Author: curso
 *
 * Created on June 19, 2019, 5:23 PM
 */

#ifndef VERTEX_H
#define VERTEX_H
#include <cstdlib>
#include <iostream>
using namespace std;

template <typename Object>
class Vertex {
public:
    //variables
    GraphNode<Object>* destiny;
    int weight;

    Vertex() {
        this->destiny = NULL;
        this->weight = 0;
    }//constructor defauly

    Vertex(GraphNode<Object>* destiny, int weight) {
        this->destiny = destiny;
        this->weight = weight;
    }//constructor sobrecargado

private:

};

#endif /* VERTEX_H */

