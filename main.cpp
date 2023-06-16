#include <iostream>


#include <stack>
#include "LLL.h"
#include "CDLL.h"
#include "CLL.h"
#include <string>

void linerLinkedList();

void CircularlinerLinkedList();

void CircularDoubleLinkedList();

void selectionSort(int data[], int n);
void merge(int data[], int low, int mid, int high);
void mergeSort(int data[], int low, int high);
int main() {
    int opcao = 4;
    if (opcao == 1)
        linerLinkedList();
    else if (opcao == 2)
        CircularDoubleLinkedList();
    else if (opcao == 3)
        CircularlinerLinkedList();
    else if (opcao == 4) {
        int n = 4;
        int data[] = {3, 10, 1, 15};
        selectionSort(data, n);
        for (int i = 0; i < n; i++)
            printf("%d ", data[i]);
        printf("\n");
    }


//    STACK<std::string> *s = new STACK<std::string>();
//    s->push("Um");
//    s->push("dia");
//    s->push("solarento");


    //    std::stack<std::string> pilha;
    //    pilha.push("teste");
    //    pilha.pop();

    return 0;
}

void linerLinkedList() {
    LLL list;
    list.addInicio(10);
    list.addFim(30);
    list.addFim(40);
    list.show();
    list.removeLast();
    list.show();
    list.removeFirst();
    list.show();
    list.removeItem(10);
    list.show();

}

void CircularDoubleLinkedList() {
    CDLL list;
    list.add(20);
    list.add(10);
    list.add(5);
    list.show();
    list.removeItem(15);

    // list.removeFirst();
    // list.removeFirst();
    // list.show();
    //list.removeLast();
    list.show();

}

void CircularlinerLinkedList() {
    CLL list;
    list.add(10);
    list.add(20, false);
    list.add(30, false);
    list.show();


}

void swap(int *v, int a1, int a2) {
    int tmp = v[a1];
    v[a1] = v[a2];
    v[a2] = tmp;

}

//N = (n-1) + (n-2) + ... + 2 + 1 = n(n-1)/2 O(n^2)
void selectionSort(int data[], int n) {
    for (int i = 0, least, j; i < n - 1; i++) {
        for (j = i + 1, least = i; j < n; j++)
            if (data[j] < data[least])
                least = j;
        swap(data, least, i);
    }
}

// Número de comparações  N = 1 + 2 + (n-2) + (n-1) = n(n-1)/2
// O(n^2)
void insertionSort(int data[], int n) {
    for (int i = 1, j; i < n; i++) {
        int tmp = data[i];
        for (j = i; j > 0 && tmp < data[j - 1]; j--)
            data[j] = data[j - 1];
        data[j] = tmp;
    }
}

//O(n log n).
void merge(int data[], int low, int mid, int high) {
    int lowEnd = mid - 1;
    int tmpPos = low;
    int numElements = high - low + 1;
    // Copiar para a array temporária
    while (low <= lowEnd && mid <= high)
        if (data[low] <= data[mid])
            temp[tmpPos++] = data[low++];
        else
            temp[tmpPos++] = a[mid++];
    // Copiar o resto da metade inferior
    while (low <= lowEnd)
        temp[tmpPos++] = data[low++];
    // Copiar o resto da metade superior
    while (mid <= high)
        temp[tmpPos++] = data[mid++];
    //Copiar de volta
    for (int i = 0; i < numElements; i++, high--)
        a[high] = temp[high];
}

void mergeSort(int data[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergeSort(data, low, mid);
        mergeSort(data, mid + 1, high);
        merge(data, low, mid + 1, high);
    }
}

