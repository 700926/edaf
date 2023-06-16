//
// Created by Carlos Almeida on 09/06/2023.
//

#ifndef LISTAS_NODES_H
#define LISTAS_NODES_H
#include <iostream>
/*
 * For to implement Liner Linked List or Circular Liner Linked List
 */
struct LLL_NODE {
    int valor;
    LLL_NODE *next;
    LLL_NODE *prev;

    LLL_NODE(int v, LLL_NODE *n=NULL ) {
        valor = v;
        next = n;
    }
};
/*
 * For to implement Circular Double Linked List
 */
struct DLL_NODE {
    int valor;
    DLL_NODE *next;
    DLL_NODE *prev;

    DLL_NODE(int v, DLL_NODE *n=NULL, DLL_NODE *p = NULL) {
        valor = v;
        next = n;
        prev = p;
    }
};
#endif //LISTAS_NODES_H
