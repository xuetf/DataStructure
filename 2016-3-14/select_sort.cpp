#include "header.h"

void select_sort(int *A, int n) {
	for (int i = 1; i < n; i++) {
		int min = A[i];
		int min_index = i;
		int j = i + 1;
		while (j <= n) {
			if (A[j] < min) {
				min = A[j];
				min_index = j;
			}
			j++;
		}
		if (min_index != i) {
			A[min_index] = A[i];
			A[i] = min;
		}
	}

}

#if 0
int main() {
	int A[ARRAY_SIZE] = { -1, 2, 3, 1, 6, 4, 5, 0, 9, 10, 7 };
	select_sort(A, MAX);
	for (int i = 1; i <= MAX; i++) {
		printf("%d ", A[i]);
	}
	getchar();
}
#endif