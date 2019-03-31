#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"

#define MAX 100000
clock_t start, end;

void swap(int *xxx, int *yyy) {
	int tmp = *xxx;
	*xxx = *yyy;
	*yyy = tmp;
}

double selectionSort(int data[], int n) {

	start = clock();
	for (int i = n; i > 1; i--) {
		int max = i;
		for (int j = 1; j < i; j++) {
			if (max < data[j])
				max = j;
		}
		swap(&data[max], &data[i]);
	}
	end = clock();

	return (double)end - start;
}
double bubbleSort(int data[], int n) {

	start = clock();
	for (int i = n; i > 1; i--) {
		for (int j = 1; j < i; j++) {
			if (data[j]>data[j + 1]) {
				swap(&data[j + 1], &data[j]);
			}
		}
	}
	end = clock();
	
	return (double)end - start;
}
double insertionSort(int data[], int n) {

	start = clock();
	for (int i = 1; i <= n; i++) {
		int tmp = data[i];
		for (int j = i - 1; i > 0; j--) {
			if (data[j] > tmp)
				data[j + 1] = data[j];
			else {
				data[j + 1] = tmp;
				break;
			}
		}
	}
	end = clock();

	return (double)end - start;
}

void mergeSort(int data[], int p, int r) {

	int q;
	if (p < r) {
		q = (p + r) / 2;
		mergeSort(data, p, q);
		mergeSort(data, q + 1, r);
		merge(data, p, q, r);
	}

}
int tmp[MAX];
void merge(int data[], int p, int q, int r) {

	int i = p, j = q + 1, k = p;
	while (i <= q&&j <= r) {
		if (data[i] <= data[j])
			tmp[k++] = data[i++];
		else
			tmp[k++] = data[j++];
	}
	while (i <= q)
		tmp[k++] = data[i++];
	while (j <= r)
		tmp[k++] = data[j++];
	for (int i = p; i <= r; i++)
		data[i] = tmp[i];

}

void quickSort(int data[], int p, int r,int pivot) {

	int q;
	if (p < r) {
		q = partition(data, p, r, pivot);
		quickSort(data, p, q - 1, pivot);
		quickSort(data, q + 1, r, pivot);
	}

}

int partition(int data[], int p, int r, int pivot) {

	srand((unsigned)time(NULL));
	int x, a, b, c,ran;
	if (pivot == 1)
		x = data[r];
	else if (pivot == 2) {
		a = data[p];
		b = data[r];
		c = data[(p + r) / 2];
		if (b <= a&&a <= c || c <= a&&a <= b) {
			x = a;
			swap(&data[r], &data[p]);
		}
		else if (a <= b&&b <= c || c <= b&&b <= a) {
			x = b;
		}
		else { 
			x = c;
			swap(&data[r], &data[(p+r)/2]);
		}
	}
	else if (pivot == 3) {
		ran = rand() % (r + 1 - p) + p;
		x = data[ran];
		swap(&data[r], &data[ran]);
	}

	int i = p - 1, tmp;

	for (int j = p; j < r; j++) {
		if (data[j] <= x) {
			i++;
			swap(&data[i], &data[j]);
		}
	}
	swap(&data[i + 1], &data[r]);
	return i + 1;
}

void heapSort(int data[], int n) {

	for (int i = n / 2; i > 0; i--) {	//build_max_heap
		maxHeapity(data, i, n);
	}
	for (int i = n; i > 1; i--) {
		swap(&data[1], &data[i]);
		n--;
		maxHeapity(data, 1, n);
	}

}

void maxHeapity(int data[], int i, int n) {
	
	if (2*i > n)
		return;
	int k = 2 * i;
	if (2 * i + 1 <= n&&data[2 * i + 1] > data[k])
		k = 2 * i + 1;
	if (data[i] >= data[k])
		return;
	swap(&data[i], &data[k]);
	maxHeapity(data, k, n);

}