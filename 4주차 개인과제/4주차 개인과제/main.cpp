#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"

#define ONE 1001
#define TWO 10001
#define THREE 100001
#define RANDOM 10
#define TABLE 16
#define SORT 9
#define CASE 6

clock_t stt,ed;

int data[THREE];
double table[TABLE][TABLE] = { 0 };

void part(int n);
int compare(const void *first, const void*second);
int main() {

	char *sortname[SORT] = { "Bubble","Selection","Insertion","Merge","Quick1","Quick2","Quick3","Heap","C_language_Sort" };
	char *dataname[CASE] = { "Random1000","Reverse1000","Random10000","Reverse10000","Random100000","Reverse100000" };
	
	part(ONE);
	part(TWO);
	part(THREE);

	for (int i = 0; i < SORT; i++) {
		for (int j = 0; j < CASE; j++) {
			if (i == 0 && j == 0)
				printf("                ");
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
				printf("        ");
				printf("%lf ", table[i][j] / 1000); 
			}
		}
		printf("\n");
	}

}

int test[THREE] = { 0 };
void part(int n) {

	double average[TABLE] = { 0 };
	/*random part*/
	srand((unsigned int)time(NULL));
	for (int i = 0; i < RANDOM; i++) {
		for (int i = 1; i <= n; i++) {
			data[i] = (rand() % n) + 1;
		}
		for (int j = 0; j < SORT; j++) {
			for (int k = 1; k <= n; k++) {
				test[k] = data[k];
			}
			switch (j) {
			case 0: average[j] += bubbleSort(test, n);break;
			case 1: average[j] += selectionSort(test, n);break;
			case 2: average[j] += insertionSort(test, n); break;
			case 3: 
				stt = clock();
				mergeSort(test, 0, n);
				ed = clock();
				average[j] += (double)ed - stt;
				break;
			case 4: 
				stt = clock();
				quickSort(test, 0, n, 1);
				ed = clock();
				average[j] += (double)ed - stt;
				break;
			case 5:
				stt = clock();
				quickSort(test, 0, n, 2);
				ed = clock();
				average[j] += (double)ed - stt;
				break;
			case 6:
				stt = clock(); 
				quickSort(test, 0, n, 3);
				ed = clock();
				average[j] += (double)ed - stt;
				break;
			case 7:
				stt = clock();
				heapSort(test, n);
				ed = clock();
				average[j] += (double)ed - stt;
				break;
			case 8:
				stt = clock();
				qsort(test, n, sizeof(int), compare);
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
	for (int i = 1; i <= n; i++) {
		data[i] = n-i;
	}
	for (int i = 0; i < SORT; i++) {
		for (int j = 1; j <= n; j++) {
			test[j] = data[j];
		}
		switch (i) {
		case 0: table[i][t + 1] = bubbleSort(test, n); break;
		case 1: table[i][t + 1] = selectionSort(test, n); break;
		case 2: table[i][t + 1] = insertionSort(test, n); break;
		case 3:
			stt = clock();
			mergeSort(test, 0, n);
			ed = clock();
			table[i][t + 1] = (double)(ed - stt);
			break;
		case 4:
			//stt = clock();
			//quickSort(test, 0, n-1, 1);
			//ed = clock();
			//table[i][t + 1] = (double)(ed - stt);
			break;
		case 5:
			stt = clock();
			quickSort(test, 0, n, 2);
			ed = clock();
			table[i][t + 1] = (double)ed - stt;
			break;
		case 6:
			stt = clock();
			quickSort(test, 0, n, 3);
			ed = clock();
			table[i][t + 1] = (double)ed - stt;
			break;
		case 7:
			stt = clock();
			heapSort(test, n);
			ed = clock();
			table[i][t + 1] += (double)ed - stt;
			break;
		case 8:
			stt = clock();
			qsort(data, n, sizeof(int), compare);
			ed = clock();
			table[i][t + 1] += (double)ed - stt;
			break;
		}
	}
}

int compare(const void *first, const void*second) {
	if (*(int*)first > *(int*)second)
		return 1;
	else if (*(int*)first < *(int*)second)
		return -1;
	else return 0;
}