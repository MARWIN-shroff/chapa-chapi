#include <stdio.h> 
#include <time.h>
#include <stdlib.h>

void swap(int *x, int *y) {
	int temp = *y;
	*y = *x;
	*x = temp;
}

void SelectionSort(int a[], int n) {
	for(int i = 0; i < n; i++) {
		int min = i;
		for(int j = i + 1; j < n; j++) {
			if(a[j] < a[min]) {
				min = j;
			}
		}
		swap(&a[min], &a[i]);
	}
}

// AVERAGE CASE
int main() {
	clock_t start_t, end_t, total_t;
	int n = 50000;
	int a[n];
	srand(time(0));
	for(int i = 0; i < n; i++) {
		a[i] = rand();
	}
	start_t = clock();
	SelectionSort(a, n);
	end_t = clock();
	total_t = (double)(end_t - start_t);
	printf("AVERAGE CASE \nTotal time taken by CPU: %ld\n", total_t  );
	return 0;		
}

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
// 	SelectionSort(a, n);
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
// 	SelectionSort(a, n);
// 	end_t = clock();
// 	total_t = (double)(end_t - start_t);
// 	printf("WORST CASE \nTotal time taken by CPU: %ld\n", total_t);
// 	return 0;		
// }