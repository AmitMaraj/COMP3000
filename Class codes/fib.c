#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 46

long int Fib(long int Memo[], int n);

int main()
{	
	long int* storage;
	storage = (long int*)malloc(MAX_SIZE * sizeof(long int*));

	int i,number;
	for (i=0;i< MAX_SIZE; i++)
		storage[i] = -1;

	printf("enter a number to find the fib of it\n");
	scanf("%d",&number);
	if (number <= MAX_SIZE )
		printf("the fib of %d = %ld \n\n\n\n",number,Fib(storage,number));
	else
		printf("number entered is to large\n\n\n\n");
	free(storage);
	//system("PAUSE");
	return 0;
}


long int Fib(long int Memo[], int n){
	if (Memo[n] != -1) return Memo[n];
	if (n == 0) return 0;
	if (n == 1) return 1;
	return Memo[n] = Fib(Memo,n-1) + Fib(Memo,n-2);
}
