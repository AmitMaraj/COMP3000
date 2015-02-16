#include <stdio.h>
#include <stdlib.h>

#define INFINITY 9999999
#define SIZE 5000000

// Prototypes
int min(int a, int b);


int main()
{
	FILE*in = fopen("input.txt","r");
	FILE*out = fopen("output.txt","w");

	int AmtTickets, AmtCoins,i,j;
	fscanf(in,"%d %d",&AmtTickets,&AmtCoins);

		 int** calculate;

		int Coins[AmtCoins+1];

		calculate = (int**)malloc((AmtCoins+1) * sizeof(int*));
			for ( i = 0; i <= AmtCoins; i++) {
		  		calculate[i] = (int*)malloc((SIZE+1) * sizeof(int*));
			}
	
	
	// storing coins to be used
	for (i = 1; i <= AmtCoins; i++)
		fscanf(in,"%d",&Coins[i]);


	//setting up array for calculations
	for(i=0;i<=AmtCoins;i++)
		for (j=0;j<=SIZE;j++){
			if (i==0) calculate[i][j] = INFINITY;
			else if (j==0) calculate[i][j] = 0;
			else {
				// do nothing
			} 
		}



	 for( i=1; i<=AmtCoins; i++ ){
         for( j=1; j<=SIZE; j++ ){ 
               if( j<Coins[i] ){ 
                  calculate[i][j]=calculate[i-1][j];
              	}
              	else{
                   calculate[i][j]=min( calculate[i-1][j], calculate[i][j-Coins[i]]+1 );
              	}

              	if (i == AmtCoins){
              		if (calculate[AmtCoins][j] > AmtTickets){
	   					printf("%d\n",j-1);
	   					break;
   					}

   					if (j==SIZE && calculate[AmtCoins][j] <= AmtTickets){
   						printf("array limit reach..\n");
   					}
              	}  	
         }
     }

        for (i = 0; i <= AmtCoins; i++) {
  			free(calculate[i]);
		}
		free(calculate); 



	fclose(in);
	fclose(out);
	system("PAUSE");
	return 0;
}


int min(int a, int b){
	if (a>b) return b;
	return a;
}




