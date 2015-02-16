#include <stdio.h>
#include <stdlib.h>

#define MaxItems 29


// Function Prototypes
void CreateSet(FILE*in, int n, int num);
void printSubset(FILE*in, int Set[],int Numbers[], int n, int num);


int main()
{       
    FILE*in = fopen("input.txt","r");

    int Size, num;
    fscanf(in,"%d %d",&Size, &num);
    CreateSet(in, Size, num);
    
    fclose(in);
    return 0;
}


// functions

// print all subSets
void CreateSet(FILE*in, int n, int num){
    if ( n<1 || n>MaxItems ) return;

    int k, j, Set[MaxItems+1], Numbers[n+1];

    for (j=1;j<= n;j++)
        fscanf(in,"%d",&Numbers[j]);


    for( j=0; j<=n; j++ ) 
         Set[j]= -1; //initialise
    
    k=1;
    while( k>=1 ){
           while( Set[k]<1 ){ 
                  Set[k]= Set[k]+1;
                  if( k==n ) 
                      printSubset(in, Set,Numbers, k, num); 
                  ++k; 
                  if( k>n ) 
                      break; 
                  Set[k]= -1; 
           }
           --k; 
    }
}


void printSubset(FILE*in, int Set[], int Numbers[], int n, int num){

    int j, sum = 0;
    
     for( j=1; j<=n; j++ ){
        if (Set[j] != 0){
            sum = sum + Numbers[j];
        } 
     }

    if (sum == num){
            for( j=1; j<=n; j++ ){
                if (Set[j] == 1){
                    printf("|%d",Numbers[j]);
                }
            }
            printf("|\n");
    }
}