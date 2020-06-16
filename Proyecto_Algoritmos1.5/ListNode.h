#ifndef LISTNODE_H
#define LISTNODE_H

#include <iostream>
#include <cstdlib>

using namespace std;

template <typename Obj>

class ListNode {
    
public:
    //atributo
    Obj value;
    ListNode<Obj>* next;
    ListNode<Obj>* prev;

    ListNode() {
        value = NULL;
        next = NULL;
        prev = NULL;
    }//constructor

    ListNode(Obj value) {
        this->value = value;
        this->next = NULL;
        this->prev = NULL;
    }//constructor

};

#endif /* LISTNODE_H */

