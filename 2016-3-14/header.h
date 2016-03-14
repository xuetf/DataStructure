#include <cstdlib>
#include<cstdio>
#include<cstring>
#define MAX 10
#define ARRAY_SIZE 10+1
#define NONE -1
typedef struct {
	int low;
	int high;
	int sum;
}Result;


void insert_sort(int *A, int p,int r);
void insert_sort_2(int *A, int p, int r); //��������ʹ�ö��ֲ���
void select_sort(int *A, int n);
void merge_sort(int *A, int p, int r);
void mixed_sort_insertion(int *A, int p, int r);
void bubble_sort(int *A, int p, int r);
void merge(int *A, int p, int q, int r);
int* add_binary(int *A, int *B, int n);
int binary_search(int *A, int p,int r, int key);//�ݹ�
int binary_search_2(int *A, int p, int r, int key);//����
int binary_search_3(int *A, int p, int r, int key);//�������������һ����keyС����
Result *find_maximum_subarray(int *A, int low, int high);