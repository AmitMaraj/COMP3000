/*
 * NAME :      Mitra Kalloo
 * Student # : 812000767
*/



/*
 * PROBLEM
 * In the question a major problem is the repetition of paths to obtain a solution. This means that some paths will be checked more than once
 * which is in efficient.
 *
 *
 *
 *
 * SOLUTION
 * To solve the problem an array is used to store the answers of paths. These answers can then be used to solve for a larger path
 * when there is a solution/solutions for different paths of the larger path
 *
*/




#include <stdio.h>

#define MaxSize 100
#define ERR 10000

int Data[MaxSize][MaxSize],Memo[MaxSize][MaxSize];

// Function Prototypes
void Greedy(FILE*,int Arr[MaxSize][MaxSize],int i, int j, int check);
int BestPath(int i, int j,int x ,int y);
int findMin( int left, int middle, int right);



int main()
{
	
	FILE*in = fopen("input.txt","r");
	FILE*out = fopen("output.txt","w");

	// storing values
	int i,j;
	fscanf(in,"%d %d",&i,&j);

	int x,y;
	for (x = 0; x < i; x++)
		for (y = 0; y < j; y++)
		{
			fscanf(in,"%d",&Data[x][y]); // storing data to Data array
			if (x<(i-1)) Memo[x][y] = -1; // placing -1 to Memo array except the last row
			else Memo[x][y] = Data[x][y]; // let Memo last row have the same value as Data last row
		}

	for (x=0; x < j; x++)
		BestPath(0,x,i,j); // finding the BestPath from each location in the first row of Data array

	Greedy(out,Memo,i,j,0); // printing out the best path using the greedy method on the Memo array
	Greedy(out,Data,i,j,1); // printing out the Data array using greedy method


	fclose(in);
	fclose(out);

	printf("\nCOMP3000 Assignment 1\n\nStudent # : 812000767\n\n\n\n********** Fire ************* \n\n\n");

	system("PAUSE");
	return 0;
}


void Greedy(FILE*out,int Arr[MaxSize][MaxSize],int i, int j, int check)
{
	int start = 0,smallest = Arr[0][0],x,y, Path[i+1];

	for (x = 1; x < j; x++)
		if (Arr[0][x] < smallest)
		{
			// finding the samllest temp in the first row
			smallest = Arr[0][x];
			start = x;
		}
	


	Path[0] = 0;
	Path[0] = Path[0] + Arr[0][start]; // summing the temp and storing it in the first location of the Path array

	Path[1] = start+1; // placin the first found path in the path array at location 1
	x = start;
	for (y = 1; y < i; y++)
	{		
			// storing the item located underneath the current item
			int middle = Arr[y][x],
				left,right;

			// checking for a left. If there is a left store the value, if there isn't a left return a error
			if((x-1) >= 0) left  = Arr[y][x-1];
			else left = ERR;

			// checking for a right. If there is a right store the value, if there isn't a right return a error
			if((x+1) < j) right = Arr[y][x+1]; 
			else right = ERR;

			// finding next smallest location to move to
			if (left <= middle && left <= right) x = x-1;
			else if (middle < left && middle < right ) x = x;
			else if (right < middle && right < left) x = x+1;

		
			// store the next found path
			Path[y+1] = x+1;

			// add to current sum
			Path[0] = Path[0] + Arr[y][x];

	}

	// this prints the Sum for the greedy solution
	if (check == 1){
		fprintf(out,"%d\n",Path[0]);
		for (x=1; x < (i+1); x++)
			fprintf(out,"%d ",Path[x]);
		fprintf(out,"\n");
	}
	// this prints the Answer for the lesat temp, which is the smallest value in the first row of Memo
	else {
		fprintf(out,"%d\n",smallest);
		for (x=1; x < (i+1); x++)
			fprintf(out,"%d ",Path[x]);
		fprintf(out,"\n");
	}
}


int BestPath(int i, int j, int x, int y){
	// checking array bounds
	if(i > x || j < 0 || j >= y) return ERR;
	// check to see if there is a solution for known path
	if (Memo[i][j] != -1) return Memo[i][j];

		int left = BestPath(i+1,j-1,x,y);
		int middle = BestPath(i+1,j,x,y);
		int right = BestPath(i+1,j+1,x,y);
		int min = findMin(left,middle,right); // finding the smallest of the three paths
		return Memo[i][j] = Data[i][j] + min; // storing a completed path so it can be used again if needed
}


// finding the smallest of three numbers
int findMin( int left, int middle, int right ){
    if( left<right && left<middle ) return left;
   	if( middle<left && middle<right ) return middle;
    return right;
}
