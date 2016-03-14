#include"header.h"

void insert_sort(int *A,int p, int r) {
	int n = r - p + 1;
	for (int i = 2; i <= n; i++) {
		int key = A[i];
		int j = i - 1;
		while (j > 0 && A[j] > key) {
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = key;
	}
}


void insert_sort_2(int *A, int p, int r) {
	int n = r - p + 1;
	for (int i = 2; i <= n; i++) {
		int key = A[i];
		int j = i - 1;
		int q = binary_search_3(A, 1, j, key);
		if (q != i && A[q] == key)//±£Ö¤ÎÈ¶¨ÅÅÐò
			++q;
		for (int k = j; k >= q; k--)
			A[k + 1] = A[k];
		A[q] = key;
	}
}
#if 0
int main() {
	int A[ARRAY_SIZE] = { -1, 2, 3, 1, 6, 4, 5, 0, 10, 10, 7 };
	insert_sort_2(A, 1, MAX);
	for (int i = 1; i <= MAX; i++) {
		printf("%d ", A[i]);
	}
	getchar();
}
#endif