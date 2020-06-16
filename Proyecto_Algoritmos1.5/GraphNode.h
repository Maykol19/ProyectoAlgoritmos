/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GraphNode.h
 * Author: curso
 *
 * Created on June 19, 2019, 5:24 PM
 */

#ifndef GRAPHNODE_H
#define GRAPHNODE_H
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

template <typename Object>
class GraphNode {
public:
    //variables
    Object value;
    vector<Object>* vertexList;
    bool visited;

    GraphNode() {
        this->vertexList;
        this->visited = false;
    }//constructor default

    GraphNode(Object value) {
        this->value = value;
        this->vertexList;
        this->visited = false;
    }//Constructor sobrecargado

    GraphNode(Object value, vector<Object> vertexList) {
        this->value = value;
        this->vertexList = vertexList;
        this->visited = false;
    }//Constructor sobrecargado

private:

};

#endif /* GRAPHNODE_H */

