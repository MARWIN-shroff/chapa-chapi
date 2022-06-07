#include <stdio.h> 
#include <time.h>
#include <stdlib.h>

void swap(int *x, int *y) {
	int temp = *y;
	*y = *x;
	*x = temp;
}

void printArray(int array[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}

void insertionSort(int a[], int n) {
    int i, x, j;
    for (i = 1; i < n; i++) {
        x = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > x) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = x;
    }
}

int main() {
  int data[] = {9, 5, 1, 4, 3};
  int size = sizeof(data) / sizeof(data[0]);
  insertionSort(data, size);
  printf("Sorted array in ascending order:\n");
  printArray(data, size);
}

//AVERAGE CASE
// int main() {
// 	clock_t start_t, end_t, total_t;
// 	int n = 50000;
// 	int a[n];
// 	srand(time(0));
// 	for(int i = 0; i < n; i++) {
// 		a[i] = rand();
// 	}
// 	start_t = clock();
// 	insertionSort(a, n);
// 	end_t = clock();
// 	total_t = (double)(end_t - start_t);
// 	printf("AVERAGE CASE \nTotal time taken by CPU: %ld\n", total_t  );
// 	return 0;		
// }

//BEST CASE
// int main() {
// 	clock_t start_t, end_t, total_t;
// 	int n = 50000;
// 	int a[n];
// 	srand(time(0));
// 	for(int i = 0; i < n; i++) {
// 		a[i] = i;
// 	}
// 	start_t = clock();
// 	insertionSort(a, n);
// 	end_t = clock();
// 	total_t = (double)(end_t - start_t);
// 	printf("BEST CASE \nTotal time taken by CPU: %ld\n", total_t);
// 	return 0;		
// }

//WORST CASE
// int main() {
// 	clock_t start_t, end_t, total_t;
// 	int n = 50000;
// 	int a[n];
// 	srand(time(0));
// 	for(int i = n - 1; i >= 0; i--) {
// 		a[i] = i;
// 	}
// 	start_t = clock();
// 	insertionSort(a, n);
// 	end_t = clock();
// 	total_t = (double)(end_t - start_t);
// 	printf("WORST CASE \nTotal time taken by CPU: %ld\n", total_t);
// 	return 0;		
// }