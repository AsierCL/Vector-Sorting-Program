#include <stdio.h>
#include <stdlib.h>
#include "./vectordinamico.h"
///#define TAM 100

/* 
void Burb1(vectorD *v){
    int e,i,aux;
    for (e=0;e<(TAM-1);e++){
        for (i=0;i<(TAM-e-1);i++){
            if (v[i]>v[i+1]){
                aux=v[i];
                v[i]=v[i+1];
                v[i+1]=aux;
            }
        }
    }
}


void swap(TELEMENTO* p1, TELEMENTO* p2) {
    TELEMENTO temp;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int partition(vectorD v1, unsigned long int low, unsigned long int high) {
    TELEMENTO* arr = (TELEMENTO*)v1;
    // choose the pivot
    TELEMENTO pivot = Componentei(v1, high);

    // Index of smaller element and Indicate
    // the right position of pivot found so far
    unsigned long int i = low - 1;

    for (unsigned long int j = low; j <= high; j++) {
        // If current element is smaller than the pivot
        if (Componentei(v1, j) < pivot) {
            // Increment index of smaller element
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// The Quicksort function Implement

void quickSort(vectorD v1, unsigned long int low, unsigned long int high) {
    // when low is less than high
    if (low < high) {
        // pi is the partition return index of pivot

        int pi = partition(v1, low, high);

        // Recursion Call
        // smaller element than pivot goes left and
        // higher element goes right
        quickSort(v1, low, pi - 1);
        quickSort(v1, pi + 1, high);
    }
}
 */
void swap (vectorD *pvector, unsigned long m, unsigned long n){
    TELEMENTO aux, aux2;
    aux = Componentei(*pvector,m);
    aux2 = Componentei(*pvector,n);
    AsignaVector(pvector,m,aux2);
    AsignaVector(pvector,n,aux);
}

void bubblesort(vectorD *v, unsigned long int TAM){
    unsigned long int e, i;
    TELEMENTO aux;
    for (e = 0; e < (TAM - 1); e++){
        for (i = 0; i < (TAM - e - 1); i++){
            if (Componentei(*v, i) > Componentei(*v, i + 1)){
                aux = Componentei(*v, i);
                AsignaVector(v, i, Componentei(*v, i + 1));
                AsignaVector(v, i + 1, aux);
            }
        }
    }
}


void quicksort(vectorD *pvector, unsigned long beg, unsigned long end){
    if (end > beg + 1){
        TELEMENTO piv = Componentei(*pvector, beg);
        unsigned long l = beg + 1, r = end;
        while (l < r){
            if (Componentei(*pvector, l) <= piv){
                l++;
            }else{
                r--;
                swap(pvector, l, r);
            }
        }
        l--;
        swap(pvector, l, beg);
        quicksort(pvector, beg, l);
        quicksort(pvector, r, end);
    }
}