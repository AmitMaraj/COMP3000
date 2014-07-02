#include <stdio.h>

// Function Prototypes
void selectionSorting (int arr[], int size);

int main() {
	
	FILE*in = fopen("input.txt","r");
	FILE*out = fopen("output.txt","w");
	
	int amt,num[26],count;
	fscanf(in,"%d",&amt);
	
	int i,j,k;
	
		for (i=0;i<amt;i++){
			count = 0;
			for (j=0;j<26;j++){
				fscanf(in,"%d",&k);
				if (k != 0){
					num[count] = k;
					count++;
				}	
			}

			selectionSorting(num,count);
			
			for (j=0;j<count;j++)
				for (k=0;k<num[j];k++)
					fprintf(out,"%c",122-j);
			fprintf(out,"\n");	
		}
	

	fclose(in);
	fclose(out);
	system("PAUSE");
	return 0;
}

// Functions

void selectionSorting (int arr[], int size){
	int i=0,y=0,temp=0;
	for (i=0; i < size - 1; i++){
	int largest = i;
	 for (y = i+1; y < size; y++){
		if (arr[y] > arr[largest])
			largest = y;
	           }
		temp = arr[largest];                     
		arr[largest] = arr[i];                          
		arr[i] = temp;
	}
}






