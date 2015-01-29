#include <stdio.h>

#define MaxSize 100

int Data[MaxSize][MaxSize],Memo[MaxSize][MaxSize];

// Function Prototypes
void Greedy(int Arr[MaxSize][MaxSize],int i, int j);
int BestPath(int i, int j);


int main()
{
	
	FILE*in = fopen("input.txt","r");
	FILE*out = fopen("output.txt","w");

	// storing values
	int i,j;
	fscanf(in,"%d %d",&i,&j);

	

	int x,y;

	for (x = 0; x < i; x++)
	{
		for (y = 0; y < j; y++)
		{
			fscanf(in,"%d",&Data[x][y]);
			if (x<(i-1)) Memo[x][y] = -1;
			else Memo[x][y] = Data[x][y];
		}
	}


	for (x = 0; x < i; x++)
	{
		for (y = 0; y < j; y++)
		{
			printf("%d ",Memo[x][y]);
		}
		printf("\n");
	}

	//for (x=0; x < j; x++){
		BestPath(0,1);
	//}


printf("\n\n");

for (x = 0; x < i; x++)
	{
		for (y = 0; y < j; y++)
		{
			printf("%d ",Memo[x][y]);
		}
		printf("\n");
	}


	Greedy(Memo,i,j);
	
	Greedy(Data,i,j);


	fclose(in);
	fclose(out);
	system("PAUSE");
	return 0;
}


void Greedy(int Arr[MaxSize][MaxSize],int i, int j)
{
	int start = 0,smallest = Arr[0][0],x,y, Path[i+1];

	for (x = 1; x < j; x++)
	{
		if (Arr[0][x] < smallest)
		{
			smallest = Arr[0][x];
			start = x;
		}
	}
	Path[0] = 0;
	Path[0] = Path[0] + Arr[0][start];
	
	Path[1] = start+1;
	x = start;
	for (y = 1; y < i; y++)
	{
			int middle = Arr[y][x],
				left,right;

			if((x-1) >= 0) left  = Arr[y][x-1];
			else left = 101;

			if((x+1) < j) right = Arr[y][x+1]; 
			else right = 101;

			if (left <= middle && left <= right) x = x-1;

			else if (middle < left && middle < right ) x = x;

			else if (right < middle && right < left) x = x+1;

	
			Path[y+1] = x+1;

			Path[0] = Path[0] + Arr[y][x];

	}

	printf ("%d\n",Path[0]);
	for (x=1; x < (i+1); x++)
		printf("%d ",Path[x]);
	printf("\n");

}


int BestPath(int i, int j){
	if (Memo[i][j] != -1) return Memo[i][j];

	int left, middle, right;
	if(j > -1 && j <5)
	{
		left = BestPath(i+1,j-1);
		middle = BestPath(i+1,j);
		right = BestPath(i+1,j+1);
	} 
	else return 101;
	


	if (left < middle && left < right) return Memo[i][j] = Data[i][j] + left;
	if (middle <= left && middle <= right ) return Memo[i][j] = Data[i][j] + middle;
	return Memo[i][j] = Data[i][j] + right;


}
