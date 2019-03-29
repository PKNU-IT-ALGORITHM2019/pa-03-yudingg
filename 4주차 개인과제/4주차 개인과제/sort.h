#ifndef SORT_H
#define SORT_H

void swap(int *xxx, int *yyy);
double selectionSort(int data[], int n);
double bubbleSort(int data[], int n);
double insertionSort(int data[], int n);
void mergeSort(int data[], int p, int r);
void merge(int data[], int p, int q, int r);
void quickSort(int data[], int p, int r,int pivot);
int partition(int data[], int p, int r,int pivot);

#endif