//
// Created by csalmeida on 10/06/2023.
//

#ifndef LISTAS_CLL_H
#define LISTAS_CLL_H

#include "NODES.h"

/*
 *  Circular Liner Linked List
 */
class CLL {
public:
    LLL_NODE *tail;

    void show() {
        if (tail == NULL) {
            printf("CLL está vazia");
        } else {
            LLL_NODE *aux = tail->next;
            while (aux != tail) {
                printf("%d ", aux->valor);
                aux = aux->next;
            }
            printf("%d ", aux->valor);
        }
        printf("\n");
    }

    void add(int i, bool insertBegin = true) {
        LLL_NODE *n;
        if (tail == NULL) {
            n = new LLL_NODE(i);
            n->next = n;
            tail = n;
        } else {
            if (insertBegin)
            {
                n = new LLL_NODE(i, tail->next);
                tail->next = n;
            } else {
                n = new LLL_NODE(i, tail->next);
                tail->next = n;
                tail = n;
            }
        }

    }


    CLL() {
        printf("Start Circular Linked List \n");
        tail = NULL;
    }

    ~CLL() {
        printf("Delete Circular Linked List!\n");
        if (tail == NULL)
            return;
        LLL_NODE *aux = tail->next; //first
        while (aux != tail) {
            printf(" %d", tail->next->valor);
            free(tail->next);
            tail->next = aux->next;
            aux = aux->next;

        }
        printf(" %d", tail->valor);
        free(tail);
        tail = NULL;
    }
};


#endif //LISTAS_CLL_H
