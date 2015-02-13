#include <stdio.h>
#include <stdlib.h>


void quicksort(int A[], int lo ,int hi);
int partition(int A[], int lo, int hi);
int random(int m , int n);
void swap(int list[], int i, int j);



int main()
{
	
	return 0;
}


void quicksort(int A[], int lo ,int hi){
	if (lo < hi){
		int dp = partition(A,lo,hi);
		quicksort(A,lo,dp);
		quicksort(A,dp+1,hi);
	}
}

int partition(int A[], int lo, int hi){
	 int pivot = A[lo];
	 --lo;++hi;
	 while(lo < hi){
	 	do --hi; while (A[hi] > pivot);
	 	do ++lo; while (A[lo] < pivot);
	 	if (lo < hi) swap(A,lo,hi);
	 }
	 return hi;
}


int random(int m , int n){
	int offset = rand()/(RAND_MAX + 1.0) * (n-m+1);
	return m + offset;
}

void swap(int list[], int i, int j){
	int hold = list[i];
	list[i] = list[j];
	list[j] = hold;
}