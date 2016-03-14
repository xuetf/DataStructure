#include "header.h"

int* add_binary(int *A, int *B,int n) {
	int *C = (int*)malloc(sizeof(int)*(n + 1));
	if (C == NULL)
		exit(-1);
	int carry = 0;
	int i = 0;
	for (i = n; i >= 1; i--) {
		C[i] = (A[i] + B[i] + carry) % 2;
		carry = (A[i] + B[i] + carry) / 2;
	}
	C[i] = carry;
	return C;
}

# if 0
int main() {
	int A[ARRAY_SIZE] = { -1,0,1,1,1,0,1,1,0,0,1 };
	int B[ARRAY_SIZE] = { -1,1,1,1,0,1,0,0,0,0,1 };
	int *C = add_binary(A,B,MAX);
	for (int i = 0; i <= MAX; i++) {
		printf("%d", C[i]);
	}
	getchar();
}
#endif