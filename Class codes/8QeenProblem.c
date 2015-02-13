
#include <stdio.h>


// FUNCTION PROTOTYPES
void SolveEightQueens(FILE *out, int rows[], int num_Queens);
int CanBePlaced(int rows[], int loc_in_row, int num_Queens);


int main()
{
    FILE *out = fopen("output.txt", "w");
    int rows[8];
    SolveEightQueens(out, rows, 0);
    fclose(out);
    getchar();
    return 0;
}

// FUNCTIONS


void SolveEightQueens(FILE *out, int rows[], int num_Queens)
{
    int loc_in_row;
    for (loc_in_row = 0; loc_in_row < 8; loc_in_row++)
    {
        if (CanBePlaced(rows, loc_in_row, num_Queens) == 1)
        {
            rows[num_Queens] = loc_in_row;
            if (num_Queens == 7)
            {
                int i, j;
                for (j = 0; j < 8; j++)
                {
                    for (i = 0; i < 8; i++)
                    {
                        if (rows[j] == i)
                            fprintf(out, " Q ");
                        else
                            fprintf(out, " * ");
                    }
                    fprintf(out, "\n");
                }
                fprintf(out, "\n+++++++++++++++++++++++\n\n");
            }
            else
            {
                SolveEightQueens(out, rows, num_Queens + 1);
            }
        }
    }
}


int CanBePlaced(int rows[], int loc_in_row, int num_Queens)
{
    if (num_Queens == 0) return 1; // this is the first Queen so it can be place with out checking for another queen
    int i;
    for (i = 0; i < num_Queens; i++)
    {
        // rows[i] == x  test for Queens in the same column
        if (rows[i] == loc_in_row || rows[i] == loc_in_row + num_Queens - i || rows[i] == loc_in_row - num_Queens + i)
            return 0;
    }
    return 1;
}