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

Result *find_maximum_subarray_2(int *A, int low, int high) {
	int n = high - low + 1;
	Result *suffixes = (Result*)malloc(sizeof(Result)*(n+low));//suffixes[i]存储以A[i]结尾的A[1..i]的最大连续和,浪费前面几个空间
	if (suffixes == NULL)
		exit(-1);
	//初始化
	suffixes[low].low = low;
	suffixes[low].high = low;
	suffixes[low].sum = A[low];
	//遍历一遍
	for (int i = low + 1; i <= high; i++) {
		if (suffixes[i - 1].sum < 0) {
			suffixes[i].low = i;
			suffixes[i].high = i;
			suffixes[i].sum = A[i];
		}
		else {
			suffixes[i].low = suffixes[i - 1].low;
			suffixes[i].high = i;
			suffixes[i].sum = suffixes[i - 1].sum + A[i];
		}
	}
	Result *max = &suffixes[low];
	for (int i = low + 1; i <= high; i++) {
		if (suffixes[i].sum > max->sum)
			max = &suffixes[i];
	}
	return max;
}


# if 1
int main(){
	int A[ARRAY_SIZE] = { NONE, 2, -3, -1, 6, -5, 0, 2, -3, 10, 7 };
	int B[ARRAY_SIZE] = { NONE, -2, -3, -1, -6, -5, -3, -2, -3, -10, -7 };//全部负数
	int C[ARRAY_SIZE] = { NONE, 2, 3, 1, 6, 5, 3, 2, 3, 10, 7 };//全部正数
	Result *r = find_maximum_subarray(A, 1, MAX);
	printf("max sum=%d,low=%d,high=%d\n", r->sum, r->low, r->high);
	r = find_maximum_subarray_2(A, 1, MAX);
	printf("max sum=%d,low=%d,high=%d\n", r->sum, r->low, r->high);
	r = find_maximum_subarray_2(B, 1, MAX);
	printf("max sum=%d,low=%d,high=%d\n", r->sum, r->low, r->high);
	r = find_maximum_subarray_2(C, 1, MAX);
	printf("max sum=%d,low=%d,high=%d\n",r->sum,r->low,r->high);
	getchar();


}
#endif