#include <stdio.h>

#define Max 100

void findAge(int);
int largest (int a, int b, int c);

int main()
{
	int i;
	for (i=1;i<=1000000;i++)
		findAge(i);
	
printf("Finish...\n");
	getchar();
	return 0;
}


void findAge(int num){
	int i,j,k;

	for (i=1; i<=Max; i++)
		for (j=1; j<=Max; j++)
			for (k=1; k<=Max; k++){
				if ( ((k*j*i) == num) && (k*2 == (k+j+i)) ) {
						printf("start num %d\n",num);
						printf("the ages are %d %d %d\n",i,j,k );
						printf("the prist age is %d\n", largest(i,j,k)+1 );
						printf("++++++++++++++++++++\n");
						return;
				}
			}
}

int largest (int a, int b, int c){
	if ( (a>b) && (a>c) ) return a;
	if ( (b>a) && (b>c) ) return b;
	return c;
}