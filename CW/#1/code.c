#include <stdio.h>

// Functions


///////////////////////////////////////////////////////////////////////////////////
// Longest Commom Subsequence

int max(int a, int b){
	if (a>b) return a;
	return b;
}

int LCS(char A[], char B[], int DP[][100],int n, int m){
	int i,j;
	for(i=0; i<=n; i++)
		DP[i][0] = 0;

	for(j=0; j<=m; j++)
		DP[j][0] = 0;

	for ( i=1; i<=n; i++){
		for (j=1; j<=m; j++){
			if (A[i] == B[j]) DP[i][j] = DP[i-1][j-1] + 1;
			else DP[i][j] = max( DP[i][j-1], DP[i-1][j] );
		}
	}
	return DP[n][m];
}
///////////////////////////////////////////////////////////////////////////////////

void printBinary( int C[], int n ){
     int j;
     for( j=1; j<=n; j++ ) 
          printf("%d", C[j] );
          //system("pause");
          
     printf( "\n" );
}

void BinaryCounter(int C[], int n){
int j,k;
 for( j=0; j<=n; j++ ) 
         C[j]= -1; //initialise
    
    k=1;
    while( k>=1 ){
           while( C[k]<1 ){
                  C[k]= C[k]+1; 
                  if( k==n ) 
                      printBinary(C, k); 
                  ++k; 
                  if( k>n ) 
                      break; 
                  C[k]= -1; 
           }
           --k;
    }
}

/////////////////////////////////////////////////////////////////////




int main()
{

	int A[100];
	BinaryCounter(A,2);
	
	return 0;
}