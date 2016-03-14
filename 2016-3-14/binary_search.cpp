#include "header.h"
int binary_search(int *A, int p, int r, int key) {
	if (p <= r) {
		int q = (p + r)/2;
		if (A[q] == key)
			return q;
		else if (key < A[q])
			return binary_search(A, p, q-1, key);
		else {
			return binary_search(A, q + 1, r, key);
		}
	}
	return -1;
}

int binary_search_2(int *A, int p, int r, int key) {
	while (p <= r) {
		int q = (p + r) / 2;
		if (A[q] == key)
			return q;
		else if (key < A[q])
			r = q - 1;
		else
			p = q + 1;
	
	}
	return -1;
}
int binary_search_3(int *A, int p, int r, int key) {//返回最后一个比key小的数
	while (p <= r) {
		int q = (p + r) / 2;
		if (A[q] < key)
			p = q + 1;
		else
			r = q - 1;
	}
	return p;
}
#if 0
int main() {
	int A[ARRAY_SIZE] = { -1, 1, 2, 3, 4, 5, 9, 12, 14, 19, 29 };
	printf("%d\n",binary_search_3(A,1, MAX, 29));//10
	printf("%d\n", binary_search_3(A, 1, MAX, 10));//7
	getchar();
}
#endif