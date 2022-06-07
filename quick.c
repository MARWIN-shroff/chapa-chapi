#include <stdio.h>
#include <time.h>

void swap(int *x, int *y);
void quickSort(int a[], int n, int low, int high);
int partition(int a[], int n, int low, int high);

int main() {
    clock_t start_t, end_t, total_t;
    int n = 50000;
    int a[n];

    // Best Case 
    // for (int i = 0; i < n; i++) {
    //     a[i] = i;
    // }
    // start_t = clock();
	// quickSort(a, n, 0, n - 1);
	// end_t = clock();
    // total_t = (double)(end_t - start_t);
	// printf("BEST CASE \nTotal time taken by CPU: %ld\n", total_t  );
    // 2754379

    // Worst Case 
    // for (int i = n-1; i >= 0; i--) {
    //     a[i] = i;
    // }
    // start_t = clock();
	// quickSort(a, n, 0, n - 1);
	// end_t = clock();
    // total_t = (double)(end_t - start_t);
	// printf("WORST CASE \nTotal time taken by CPU: %ld\n", total_t  );
    // 2563121

    // Average Case 
    // srand(time(0));
    // for (int i = 0; i < n; i++) {
    //     a[i] = rand();
    // }
    // start_t = clock();
	// quickSort(a, n, 0, n - 1);
	// end_t = clock();
    // total_t = (double)(end_t - start_t);
	// printf("AVERAGE CASE \nTotal time taken by CPU: %ld\n", total_t  );
    // 8668
    quickSort(a, 5, 0, 4);
    for (int i = 0; i < 5; i++) {
        printf("%d  ", a[i]);
    }
    printf("\n");
    return 0;
}

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int a[], int n, int low, int high) {
    int pivot = low, i = low, j = high;
    if (low < high) {
        while (i < j) {
            while (a[pivot] < a[j]) {
                j--;
            }
            while (a[pivot] >= a[i]) {
                i++;
            }
            if (i < j) {
                swap(&a[i], &a[j]);
            }
        }
        if (i >= j) { 
            swap(&a[j], &a[pivot]);
        }
    }
    return j;
}

void quickSort(int a[], int n, int low, int high) {
    if (low < high) {
        int j = partition(a, n, low, high);
        quickSort(a, n, low, j - 1);
        quickSort(a, n, j + 1, high);
    }

}