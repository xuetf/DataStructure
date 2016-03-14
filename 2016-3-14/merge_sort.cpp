#include "header.h"
#include <climits>



void merge(int *A, int p, int q, int r) {
	int n1 = q - p + 1;
	int n2 = r - q;
	
	int *L = (int*)malloc(sizeof(int)*(n1+1));
	int *R = (int*)malloc(sizeof(int)*(n2+1));
	if (L == NULL || R == NULL)
		exit(-1);

	memcpy(L, A + p, n1 * sizeof(int));
    memcpy(R, A + q + 1, n2 * sizeof(int));

	L[n1] = INT_MAX;//из╠Ь
	R[n2] = INT_MAX;//из╠Ь

	for (int i = p,j=0,k=0; i <= r; i++)
		A[i] = L[j] < R[k] ?  L[j++] : R[k++];
	free(L);
	free(R);

}

void merge_sort(int *A, int p, int r) {
	if (p < r) {
		int q = (p + r) / 2;
		merge_sort(A, p, q);
		merge_sort(A, q + 1, r);
		merge(A, p, q, r);
	}
}

#if 0
int main() {
	int A[ARRAY_SIZE] = { -1, 2, 3, 1, 6, 4, 5, 0, 9, 10, 7 };
	merge_sort(A, 1, MAX);
	for (int i = 1; i <= MAX; i++) {
		printf("%d ", A[i]);
	}
	getchar();
}
#endif