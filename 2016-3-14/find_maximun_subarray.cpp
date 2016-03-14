#include "header.h"

Result *find_cross_subarray(int *A, int low, int mid, int high) {
	//Left
	int left_sum = INT_MIN;
	int left_low = -1;
	int sum = 0;
	for (int i = mid; i >= low ; i--) {
		sum = sum + A[i];
		if (sum > left_sum) {
			left_sum = sum;
			left_low = i;
		}
	}
	//Right
	int right_sum = INT_MIN;
	int right_high = high + 1;
	sum = 0;
	for (int i = mid + 1; i <= high; i++) {
		sum = sum + A[i];
		if (sum > right_sum) {
			right_sum = sum;
			right_high = i;
		}
	}
	Result * r = (Result*)malloc(sizeof(Result));
	r->low = left_low;
	r->high = right_high;
	r->sum = left_sum + right_sum;
	return r;
}


Result *find_maximum_subarray(int *A, int low, int high) {
	if (low == high) {
		Result * r = (Result*)malloc(sizeof(Result));
		r->low = low;
		r->high = high;
		r->sum = A[low];
		return r;
	}
	else {
		int mid = (low + high) / 2;
		Result *left = find_maximum_subarray(A, low, mid);
		Result *right = find_maximum_subarray(A,mid+1,high);
		Result *cross = find_cross_subarray(A, low, mid, high);
		Result *max = NULL;
		max = left->sum > right->sum ? left : right;
		max = max->sum > cross->sum ? max : cross;
		return max;
	}
}


# if 0
int main(){
	int A[ARRAY_SIZE] = { NONE, 2, -3, -1, 6, -5, 0, 2, -3, 10, 7 };
	int B[ARRAY_SIZE] = { NONE, -2, -3, -1, -6, -5, -3, -2, -3, -10, -7 };//全部负数
	int C[ARRAY_SIZE] = { NONE, 2, 3, 1, 6, 5, 3, 2, 3, 10, 7 };//全部正数
	Result *r = find_maximum_subarray(C, 1, MAX);
	printf("max sum=%d,low=%d,high=%d\n",r->sum,r->low,r->high);
	getchar();


}
#endif