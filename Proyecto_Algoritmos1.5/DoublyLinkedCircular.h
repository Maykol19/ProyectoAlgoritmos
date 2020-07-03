#ifndef DOUBLYLINKEDCIRCULAR_H
#define DOUBLYLINKEDCIRCULAR_H

#include "ListNode.h"
#include <cstdlib>
#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

template<typename Obj>

class DoublyLinkedCircular {
    
public:

    DoublyLinkedCircular() {
        this->first = NULL;
        this->last = NULL;
    }//constructor

    void insert(Obj value) {
        
        //Si la lista está vacía
        if (this->first == NULL) {
            this->first = new ListNode<Obj>(value);
            this->last = this->first;
            this->first->prev = this->last;
            this->last->next = this->first;
        }
        else {//Si la lista no está vacía
            this->last->next = new ListNode<Obj>(value);
            this->last->next->prev = this->last;
            this->last = this->last->next;
            this->last->next = this->first;
            this->first->prev = this->last;
        }
        
    }//insert

    void remove(Obj value) {
        
        //Si la lista está vacía no se elimina
        if (size() == 0) {
            cout << "Lista Vacía" << endl;
        }
        //Si hay que eliminar el primero
        if (value == this->first->value) {
            //Si hay solo un elemento
            if (size() == 1) {
                this->first = NULL;
                this->last = NULL;
            }//Si hay más de 2 elementos
            else {
                this->first = this->first->next;
                this->last->next = this->first;
            }
        }//Se elimina cualquiera que no sea el primero
        else {
            ListNode<Obj>* temp = this->first;
            ListNode<Obj>* prev = temp;
            while (!temp->value == value) {
                prev = temp;
                temp = temp->next;
                if (temp == NULL) {
                }
            }
            prev->next = temp->next;
            temp->prev = prev;
        }
        
    }//remove

    int size() {
        
        ListNode<Obj>* temp = this->first;
        int size = 0;
        do {
            size++;
            temp = temp->next;
        } while (temp != this->first);
        return size;
        
    }//size

    //getters and setters
    Obj getFirstValue() {
        return this->first->value;
    }

    Obj* getLastValue() {
        return this->last->value;
    }

    ListNode<Obj>* getFirst() {
        return this->first;
    }

    ListNode<Obj>* getLast() {
        return this->last;
    }

    ListNode<Obj>* siguiente() {
        this->first = this->first->next;
        return this->first;
    }

    ListNode<Obj>* anterior() {
        this->first = this->first->prev;
        return this->first;
    }

private:
    //atributos
    ListNode<Obj>* first;
    ListNode<Obj>* last;
    
};

#endif /* DOUBLYLINKEDCIRCULAR_H */

