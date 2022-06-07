#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	int L[n1], R[n2];

	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	i = 0; 
	j = 0; 
	k = l; 
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(int arr[], int l, int r)
{
	if (l < r) {
		int m = l + (r - l) / 2;

		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}

void printArray(int A[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", A[i]);
	printf("\n");
}

int main()
{
	int arr[] = { 12, 11, 13, 5, 6, 7 };
	int arr_size = sizeof(arr) / sizeof(arr[0]);

	printf("Given array is \n");
	printArray(arr, arr_size);

	mergeSort(arr, 0, arr_size - 1);

	printf("\nSorted array is \n");
	printArray(arr, arr_size);
	return 0;
}



//INCASE BEST CASE ETC COMES 
// #include <stdio.h>
// #include <time.h>

// void mergeSort(int a[], int b[], int low, int high);
// void combine(int a[], int b[], int low, int mid, int high);

// int main() {
//     clock_t start_t, end_t, total_t;
//     int n = 50000;
//     int a[n];
//     int b[n];

//     // // Best Case 
//     for (int i = 0; i < n; i++) {
//         a[i] = i;
//     }
//     start_t = clock();
// 	mergeSort(a, b, 0, n - 1);
// 	end_t = clock();
//     total_t = (double)(end_t - start_t);
// 	printf("BEST CASE \nTotal time taken by CPU: %ld\n", total_t);

    // Worst Case 
    // for (int i = n; i > 0; i--) {
    //     a[i] = i;
    // }
    // start_t = clock();
	// mergeSort(a, b, 0, n - 1);
	// end_t = clock();
    // total_t = (double)(end_t - start_t);
	// printf("WORST CASE \nTotal time taken by CPU: %ld\n", total_t  );

    // Average Case 
    // srand(time(0));
    // for (int i = 0; i < n; i++) {
    //     a[i] = rand();
    // }
    // start_t = clock();
	// mergeSort(a, b, 0, n - 1);
	// end_t = clock();
    // total_t = (double)(end_t - start_t);
	// printf("AVERAGE CASE \nTotal time taken by CPU: %ld\n", total_t  );
    
//     return 0;
// }

// void mergeSort(int a[], int b[], int low, int high) {
//     if (low < high) {
//         int mid = (low + high) / 2;
//         mergeSort(a, b, low, mid);
//         mergeSort(a, b, mid + 1, high);
//         combine(a, b, low, mid, high);
//     }
// }

// void combine(int a[], int b[], int low, int mid, int high) {
//     int k = low, i = low, j = mid + 1;
//     while (i <= mid && j <= high) {
//         if (a[i] < a[j]) {
//             b[k] = a[k];
//             k++;
//             i++;
//         } else {
//             b[k] = a[j];
//             j++;
//         }
//     }
//     while (i <= mid) {
//         b[k] = a[k];
//         k++;
//         i++;
//     }
//     while (j <= high) {
//         b[k] = a[k];
//         k++;
//         j++;
//     }
// }