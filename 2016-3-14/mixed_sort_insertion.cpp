#include "header.h"
#define INSERTION_SORT_TRESHOLD 20

void mixed_sort_insertion(int *A, int p, int r){
	if (p >= r) return;

	if (r - p < INSERTION_SORT_TRESHOLD) {
		insert_sort(A, p, r);
	}
	else {
		int q = (p + r) / 2;
		mixed_sort_insertion(A, p, q);
		mixed_sort_insertion(A, q + 1, r);
		merge(A, p, q, r);
	}
}