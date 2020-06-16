/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Graph.h
 * Author: curso
 *
 * Created on June 19, 2019, 5:24 PM
 */

#ifndef GRAPH_H
#define GRAPH_H
#include <cstdlib>
#include <iostream>
#include <vector>

#include "GraphNode.h"
#include "Vertex.h"
using namespace std;

template <typename Object>
class Graph {
public:
    //variables
    vector<GraphNode<Object>*> nodes;

    Graph() {
        this->nodes;
    }//constructor default

    bool createGraph(Object value) {
        this->nodes.push_back(new GraphNode<Object>(value));
        return true;
    }//createGraph

    bool createVertex(Object start, Object end, int weight) {
        GraphNode<Object>* graph1 = NULL;
        GraphNode<Object>* graph2 = NULL;
        for (GraphNode<Object>* temp : this->nodes) {
            GraphNode<Object>* node = (GraphNode<Object>*) temp;
            if (node->value == start) {
                graph1 = node;
            }
            if (node->value == end) {
                graph2 = node;
            }
        }
        if (graph1 == NULL || graph2 == NULL || graph1 == graph2) {
            return false;
        }
        Vertex<Object>* a = new Vertex<Object>(graph2, weight);

        graph1->vertexList->push_back(a);
        return true;
    }//createVertex

    void linkAll() {
        for (int i = 0; i < this->nodes.size(); i++) {
            Object start = (Canal*) this->nodes[i]->value;
            for (int y = 0; y < this->nodes.size(); y++) {
                Canal* end = (Canal*) this->nodes[y]->value;
                createVertex(start, end, 0);
            }
        }
    }//linkAll

    bool destroyVertex(Object start, Object end) {
        GraphNode<Object> graph = NULL;
        for (Object temp : this->nodes) {
            GraphNode<Object> node = (GraphNode<Object>) temp;
            if (node.value == start) {
                graph = node;
            }
        }
        if (graph == NULL) {
            return false;
        }
        for (Object temp : graph.vertexList) {
            Vertex<Object> vertex = (Vertex<Object>) temp;
            if (vertex.destiny.value == end) {
                graph.vertexList.remove(vertex);
                break;
            }
        }
        return true;
    }//destroyVertex

    void print() {
        //        cout << "------Graph print------" << endl;
        //        if (this->nodes.empty()) {
        //            cout << "There are no nodes" << endl;
        //            return;
        //        }
        //        for (GraphNode<Object>* tempNode : this->nodes) {
        //            GraphNode<Object>* node = (GraphNode<Object>*) tempNode;
        //            cout << "Graph: " << node->value << endl;
        //            cout << "Vertex list:" << endl;
        //            if (node->vertexList->empty()) {
        //                cout << "No vertex connections" << endl;
        //                cout << "" << endl;
        //            } else {
        //                for (Vertex<Object>* tempVertex : node->vertexList) {
        //                    Vertex<Object>* vertex = (Vertex<Object>*) tempVertex;
        //                    cout << "Connection with Graph: " << vertex->destiny->value << endl;
        //                    cout << "Connection weight: " + vertex->weight << endl;
        //                    cout << "" << endl;
        //                }
        //            }
        //        }
    }

    GraphNode<Object>* getNode(Object value) {
        for (GraphNode<Object>* temp : this->nodes) {
            if (temp->value == value) {
                return temp;
            }
        }
        //        return NULL;

    }//getNode

private:

};

#endif /* GRAPH_H */

