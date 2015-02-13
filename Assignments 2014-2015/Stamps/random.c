#include <stdio.h>

int main()
{
	int x,y;
	// printf("enter # of Tickets :\n");
	// scanf("%d",&y);
	// printf("enter # of Coins  :\n");
	// scanf("%d",&x);
	srand(time(0));
	x = y = 500;


	FILE*out = fopen("input.txt","w");
	fprintf(out,"%d %d\n\n",y,x);

	int i,j;
	
		for (j = 1; j <= x; j++)
			fprintf(out,"%d ",rand()%10000);  //rand()%100
		


	fclose(out);
	printf("input generated...\n");
	return 0;
}
