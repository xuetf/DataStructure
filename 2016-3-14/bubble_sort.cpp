#include "header.h"
void bubble_sort(int *A, int p, int r) {

	for (int i = p; i < r; i++) {
		bool bswap = false;
		for (int j = p+1; j <= r-i+1; j++) {//往后冒泡，第一轮结束最大的冒泡到最后面
			if (A[j-1] > A[j]) {
				int t = A[j];
				A[j] = A[j - 1];
				A[j - 1] = t;
				bswap = true;
			}
		}
		if (!bswap)
			break;
	}
}

#if 0
int main() {
	int A[ARRAY_SIZE] = { -1, 2, 3, 1, 6, 5, 5, 0, 12, 10, 7 };
	bubble_sort(A, 1, MAX);
	for (int i = 1; i <= MAX; i++) {
		printf("%d ", A[i]);
	}
	getchar();
}
#endif