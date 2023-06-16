//
// Created by Carlos Almeida on 09/06/2023.
//

#ifndef LISTAS_LLL_H
#define LISTAS_LLL_H

#include "NODES.h"

/*
 *  Liner Linked List
 */
class LLL {
public:
    LLL_NODE *first;

    void show() {
        LLL_NODE *aux = first;
        while (aux != NULL) {
            printf("%d ", aux->valor);
            aux = aux->next;
        }
        printf("\n");
    }

    void addInicio(int i) {
        LLL_NODE *n = new LLL_NODE(i, first);
        first = n;
    }

    void addFim(int i) {
        LLL_NODE *aux = first;
        LLL_NODE *n = new LLL_NODE(i, NULL);
        while (aux->next != NULL) {
            aux = aux->next;
        }
        aux->next = n;

    }

    void removeFirst() {
        if (first == NULL) {
            printf("The liner linked list is empty()");
            return;
        }
        // Just one element
        if (first->next == NULL) {
            free(first);
            first = NULL;
            return;
        }
        // More than one element
        LLL_NODE *aux = first->next;
        free(first);
        first = aux;
        free(aux);

    }

    void removeLast() {
        // don't have elements
        if (first == NULL) {
            printf("The liner linked list is empty()");
            return;
        }
        // Just one element
        if (first->next == NULL) {
            free(first);
            first = NULL;
            return;
        }
        // More one element
        LLL_NODE *last = first;
        LLL_NODE *before = first;

        // When get out while the last is the last node
        while (last->next != NULL) {
            printf("[%d] ", last->valor);
            before = last;
            last = last->next;
        }
        //here last is the last node
        printf("[%d] \n", last->valor);
        free(last);
        last = NULL;
        before->next = last;
    }

    void removeItem(int i) {
        LLL_NODE *remove = NULL;
        LLL_NODE *aux = first;
        LLL_NODE *beforeRemove = NULL;
        if (first == NULL)
            return;

        // find the Node with value equals i
        while (aux != NULL) {
            if (aux->valor == i) {
                remove = aux;
                break;
            }
            beforeRemove = aux;
            aux = aux->next;
        }

        if (remove != NULL) {
            // remove first element
            if ( remove == first ) {
                // Just one element
                if (first->next == NULL ){
                    free(remove);
                    free(first);
                    first=NULL;
                } else {
                    first = first->next;
                    free(remove);
                    remove = NULL;
                }
            }
            // element at the midle of list
            else if (remove != first) {
                beforeRemove->next = remove->next;
                free(remove);
                remove = NULL;
            }
        }
    }

    LLL() {
        printf("Estou a iniciar uma Lista Simplesmente ligada \n");
        first = NULL;
    }

    ~LLL() {
        printf("Destrutor da lista simplesmente ligada!\n");
        LLL_NODE *aux = first;
        printf("Vou libertar a memoria da lista simplesmente ligada\n");
        while (aux != NULL) {
            aux = aux->next;
            printf(" %d ", first->valor);
            free(first);
            first = aux;
        }
        printf("\n");
    }
};


#endif //LISTAS_LLL_H
