#include <stdio.h>

int isAvailable(int puzzle[][9], int row, int col, int num)
{
    int rowStart = (row/3) * 3;
    int colStart = (col/3) * 3;
    int i;

    for(i=0; i<9; ++i)
    {
        if (puzzle[row][i] == num) return 0;
        if (puzzle[i][col] == num) return 0;
        if (puzzle[rowStart + (i%3)][colStart + (i/3)] == num) return 0;
    }
    return 1;
}

int fillSudoku(int puzzle[][9], int row, int col)
{
    int i;
    if(row<9 && col<9)
    {
        if(puzzle[row][col] != 0)
        {
            if((col+1)<9) return fillSudoku(puzzle, row, col+1);
            else if((row+1)<9) return fillSudoku(puzzle, row+1, 0);
            else return 1;
        }
        else
        {
            for(i=0; i<9; ++i)
            {
                if(isAvailable(puzzle, row, col, i+1))
                {
                    puzzle[row][col] = i+1;
                    if((col+1)<9)
                    {
                        if(fillSudoku(puzzle, row, col +1)) return 1;
                        else puzzle[row][col] = 0;
                    }
                    else if((row+1)<9)
                    {
                        if(fillSudoku(puzzle, row+1, 0)) return 1;
                        else puzzle[row][col] = 0;
                    }
                    else return 1;
                }
            }
        }
        return 0;
    }
    else return 1;
}

int main()
{
	FILE *in = fopen("input.txt","r");
	FILE *out = fopen("output.txt","w");
    int i, j,puzzle[9][9];
//    int puzzle[9][9]={{5, 0, 0, 9, 4, 1, 8, 7, 2},
//                      {0, 0, 1, 0, 0, 0, 4, 0, 3},
//                      {0, 8, 4, 0, 0, 0, 0, 0, 0},
//                      {0, 0, 0, 6, 0, 0, 1, 0, 0},
//                      {0, 7, 0, 0, 8, 0, 0, 4, 0},
//                      {0, 0, 5, 0, 0, 2, 0, 0, 0},
//                      {0, 0, 0, 0, 1, 0, 9, 8, 0},
//                      {3, 0, 0, 0, 5, 0, 0, 0, 0},
//					  {6, 0, 0, 0, 0, 7, 0, 0, 0}};

	for(i=1; i<10; ++i)
        {
            for(j=1; j<10; ++j) {
				fscanf(in,"%d", &puzzle[i-1][j-1]);
			}
        }

    if(fillSudoku(puzzle, 0, 0) == 1)
    {
        fprintf(out,"\n+-----+-----+-----+\n");
        for(i=1; i<10; ++i)
        {
            for(j=1; j<10; ++j) {
				fprintf(out,"|%d", puzzle[i-1][j-1]);
			}
            fprintf(out,"|\n");
            if (i%3 == 0) fprintf(out,"+-----+-----+-----+\n");
        }
    }
    else fprintf(out,"\n\nNO SOLUTION\n\n");

    printf("program \n");
    

	fclose(out);
    return 0;
}
