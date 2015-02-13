#include <stdio.h>
#include <stdlib.h>


// FUNCTION PROTOTYPES
long long int power(int x, int n);


int main()
{
	int x,n;
	printf("please enter a Base\n");
	scanf("%d",&x);
	printf("plase enter the power\n");
	scanf("%d",&n);
    printf("%lld\n", power(x,n));
    system("PAUSE");
    return 0;
}


// FUNCTIONS

long long int  power(int x, int n)
{
    if (n == 0) return 1;
    if (n == 1) return x;
    long long int pn = power(x,n/2);
    if (n%2 == 0) return pn*pn;
    return x*pn*pn;
}