#include <stdio.h>
#include <stdlib.h>

#define INFINITY 9999999
#define SIZE 5000001

// Prototypes
void solve(FILE*out,int Coins[], int AmtCoins,int AmtTickets);


int main()
{
	FILE*in = fopen("input.txt","r");
	FILE*out = fopen("output.txt","w");

	int AmtTickets, AmtCoins,i,j;
	fscanf(in,"%d %d",&AmtTickets,&AmtCoins);

	int Coins[AmtCoins+1];

	// storing coins to be used
	for (i = 1; i <= AmtCoins; i++)
		fscanf(in,"%d",&Coins[i]);

	printf("\nCOMP3000 Assignment 2\n\nStudent # : 812000767\n\n\n\n********** Stamps ************* \n\n\n");

	solve(out,Coins,AmtCoins,AmtTickets);
		
	fclose(in);
	fclose(out);
	system("PAUSE");
	return 0;
}


// function used for finding the last number that can be made
// with the given set of coins
void solve(FILE*out,int Coins[], int AmtCoins,int AmtTickets){
	int i,j;
	int* storage;

	// Using a 1D array since it saves on storage of using a 2D array
	// to obtain the large size of the array malloc was used to create all the space needed
	storage = (int*)malloc((SIZE) * sizeof(int*));
	storage[0] = 0;

	printf("Processing...\n");
	for(i=1;i<=SIZE;i++){
		storage[i] = INFINITY;  // place a very large value as first value
			for(j=1;j<=AmtCoins;j++){
				// checks for if the coin is less than of equal to index and if the coin subtract 
				// the index plus one more coin is a better value than if current best
				// then replace previous best with new best
				if (Coins[j] <= i && storage[i-Coins[j]] + 1 < storage[i] ){ 
					storage[i] = storage[i-Coins[j]] + 1;
				}
			}
			// stop when there is greater amount of tickets needed
			if (storage[i] > AmtTickets){
				printf("answer saved to output.txt ...\n\n\n");
				fprintf(out,"The value of M is %d\n",i-1);
				break;
			}
		}
	// freeing memory
	free(storage);
}




