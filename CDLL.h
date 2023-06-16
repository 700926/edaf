//
// Created by Carlos Almeida on 09/06/2023.
//

#ifndef LISTAS_DLL_H
#define LISTAS_DLL_H


#include "NODES.h"

/*
 *  Cirular Double linked list
 */
class CDLL {
public:
    DLL_NODE *first;

    void show() {
        if (first == NULL) {
            printf("CDLL está vazia");
        } else {
            DLL_NODE *aux = first;
            while (aux->next != first) {
                printf("%d ", aux->valor);
                aux = aux->next;
            }
            printf("%d ", aux->valor);
        }
        printf("\n");
    }

    /*
     * insertBegin = true - Insert at begin of list
     * insertBegin = false - insert at end of list
     */
    void add(int i, bool insertBegin = true) {
        DLL_NODE *n;
        if (first == NULL) {
            n = new DLL_NODE(i);
            n->next = n;
            n->prev = n;
        } else {
            n = new DLL_NODE(i, first, first->prev);
            // last = tail->prev;
            first->prev->next = n;
            first->prev = n;
        }
        if (insertBegin)
            first = n;
    }

    void removeItem(int i) {
        if (first == NULL)
            return;
        DLL_NODE *remove = NULL;
        DLL_NODE *tmp = first;
        while (tmp->next != first) {
            if (tmp->valor == i) {
                remove = tmp;
                break;
            } else {
                if (tmp->next->valor == i) {
                    remove = tmp->next;
                    break;
                }
            }
            tmp = tmp->next;
        }
        if (remove == NULL)
            return;

        // is the First
        if (remove == first) {
            // has an element
            if (remove->next == first) {
                free(first);
                first = NULL;
                return;
            }
            // Has than an element
            first->prev->next = first->next;
            first->next->prev = first->prev;
            first = first->next;
            free(remove);
            return;
        }
        if ( remove != first ) {
            remove->prev->next = remove->next;
            remove->next->prev = remove->prev;
            free(remove);
        }

    }

    void removeFirst() {
        if (first == NULL)
            return;
        // Has an element
        if (first->prev == first) {
            free(first);
            first = NULL;
            return;
        }

        // Has more than an element
        DLL_NODE *tmp = first;
        first->prev->next = first->next;
        first->next->prev = first->prev;
        first = first->next;
        free(tmp);
    }

    void removeLast() {
        if (first == NULL)
            return;

        // Has an element
        if (first->next == first) {
            free(first);
            first = NULL;
            return;
        }

        // has more than an element
        DLL_NODE *tmp = first->prev;
        first->prev = first->prev->prev;
        first->prev->next = first;
        free(tmp);
        return;


    }

    CDLL() {
        printf("Init Circular Double linked List\n");
        first = NULL;

    };

    ~

    CDLL() {
        printf("Destrutor Circular Double linked List!\n");
        if (first == NULL)
            return;
        DLL_NODE *aux = first->prev; // last
        while (aux != first) {
            aux->next = first->next;
            printf(" %d", first->valor);
            free(first);
            first = aux->next;
        }
        printf(" %d", first->valor);
        free(first);
        first = NULL;
    }

};


#endif //LISTAS_DLL_H
