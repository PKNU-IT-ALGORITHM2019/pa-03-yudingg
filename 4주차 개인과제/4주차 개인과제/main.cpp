#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"

#define ONE 1000
#define TWO 10000
#define THREE 100000
#define RANDOM 10
#define TABLE 15
#define SORT 7
#define CASE 6

clock_t stt,ed;

int data[THREE];
double table[TABLE][TABLE] = { 0 };

void part(int n);
int main() {

	char *sortname[SORT] = { "Bubble","Selection","Insertion","Merge","Quick1","Quick2","Quick3" };
	char *dataname[CASE] = { "Random1000","Reverse1000","Random10000","Reverse10000","Random100000","Reverse100000" };
	
	part(ONE);
	part(TWO);
	part(THREE);

	for (int i = 0; i < SORT; i++) {
		for (int j = 0; j < CASE; j++) {
			if (i == 0 && j == 0)
				printf("               ");
			else if (j == 0) {
				printf("%s", sortname[i]);
				int length = strlen(sortname[i]);
				for (int k = length; k < TABLE; k++)
					printf(" ");
			}
			if (i == 0) {
				printf("%s", dataname[j]);
				int length = strlen(dataname[i]);
				for (int k = length; k < TABLE; k++)
					printf(" ");
			}
			else {
				printf("       ");
				printf("%lf ", table[i][j] / 1000); 
			}
		}
		printf("\n");
	}

}

void part(int n) {

	int test[THREE];
	double average[TABLE] = { 0 };
	/*random part*/
	srand((unsigned int)time(NULL));
	for (int i = 0; i < RANDOM; i++) {
		for (int i = 0; i < n; i++) {
			data[i] = (rand() % n) + 1;
		}
		for (int j = 0; j < SORT; j++) {
			for (int k = 0; k < n; k++) {
				test[k] = data[k];
			}
			switch (j) {
			case 0: average[j] += bubbleSort(test, n);break;
			case 1: average[j] += selectionSort(test, n);break;
			case 2: average[j] += insertionSort(test, n); break;
			case 3: 
				stt = clock();
				mergeSort(test, 0, n-1);
				ed = clock();
				average[j] += (double)ed - stt;
				break;
			case 4: 
				stt = clock();
				quickSort(test, 0, n-1, 1);
				ed = clock();
				average[j] += (double)ed - stt;
				break;
			case 5:
				stt = clock();
				quickSort(test, 0, n-1, 2);
				ed = clock();
				average[j] += (double)ed - stt;
				break;
			case 6:
				stt = clock(); 
				quickSort(test, 0, n-1, 3);
				ed = clock();
				average[j] += (double)ed - stt;
				break;
			}
		}
	}
	int t = 0;
	if (n == TWO) t = 2;
	else if(n==THREE) t = 4;
	for (int i = 0; i < SORT; i++) {
		table[i][t] = average[i] / (double)RANDOM;
	}

	/*descending part*/
	for (int i = 0; i < n; i++) {
		data[i] = n - i;
	}
	for (int i = 0; i < SORT; i++) {
		for (int j = 0; j < n; j++) {
			test[j] = data[j];
		}
		switch (i) {
		case 0: table[i][t + 1] = bubbleSort(test, n); break;
		case 1: table[i][t + 1] = selectionSort(test, n); break;
		case 2: table[i][t + 1] = insertionSort(test, n); break;
		case 3:
			stt = clock();
			mergeSort(test, 0, n-1);
			ed = clock();
			table[i][t + 1] = (double)(ed - stt);
			break;
		case 4:/*
			stt = clock();
			quickSort(test, 0, n-1, 1);
			ed = clock();
			table[i][t + 1] = (double)(ed - stt);*/
			break;
		case 5:
			stt = clock();
			quickSort(test, 0, n-1, 2);
			ed = clock();
			table[i][t + 1] = (double)ed - stt;
			break;
		case 6:
			stt = clock();
			quickSort(test, 0, n-1, 3);
			ed = clock();
			table[i][t + 1] = (double)ed - stt;
			break;
		}
	}
}
