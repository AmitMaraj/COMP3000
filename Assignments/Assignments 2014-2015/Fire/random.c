#include <stdio.h>

int main()
{
	int x,y;
	printf("enter # rows :\n");
	scanf("%d",&y);
	printf("enter # col  :\n");
	scanf("%d",&x);
	srand(time(0));


	FILE*out = fopen("input.txt","w");
	fprintf(out,"%d %d\n\n",y,x);

	int i,j;
	for (i = 0; i < y; i++){
		for (j = 0; j < x; j++)
			fprintf(out,"%d ",rand()%100);
		fprintf(out,"\n");
	}

	fclose(out);
	return 0;
}
