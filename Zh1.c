#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10

int table[COLS][ROWS];

int HAJOK[5]= {2,3,3,4,5};

void init()
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            table[i][j] = 0;
        }
    }

    for (int i = 0; i < 5; i++)
    {
        HAJOK[i] = 0;
    }
}

void printTable()
{
    for (int i = 1; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            printf("%d", table[j][i]);
        }
        printf("\n");
    }
}

void submitfugg(int col, int row, int shiplength)
{
    if (row+shiplength < 10 && row-shiplength < 0)
    {
        while (shiplength != 0)
        {
            if (table[col][row+shiplength] == 1)
            {
                printf("Ezen a helyen van mar hajo%d%d\n",col , row);
                break;
            }
            else if (table[col+1][row + shiplength] == 1 || table[col-1][row + shiplength] == 1)
            {
                printf("A hajo mellet mar van egy masik\n");
                break;
            }
            else 
            {
                table[col][row+shiplength-1] = 1;
                shiplength--;
            }
        }
    }
    else if (row+shiplength > 10 && row-shiplength > 0)
    {
        while (shiplength != 0)
        {
            if (table[col][row-shiplength] == 1)
            {
                printf("Ezen a helyen van mar hajo\n");
                break;
            }
            else if (table[col+1][row - shiplength] == 1 || table[col-1][row - shiplength] == 1)
            {
                printf("A hajo mellet mar van egy masik\n");
                break;
            }
            else 
            {
                table[col][row-shiplength] = 1;
                shiplength--;
            }
        }
    }
    else if (row+shiplength < 10 && row-shiplength > 0)
    {
        while (shiplength != 0)
        {
            if (table[col][row-shiplength] == 1)
            {
                printf("Ezen a helyen van mar hajo\n");
                break;
            }
            else if (table[col+1][row - shiplength] == 1 || table[col-1][row - shiplength] == 1)
            {
                printf("A hajo mellet mar van egy masik\n");
                break;
            }
            else 
            {
                table[col][row-shiplength] = 1;
                shiplength--;
            }
        }
    }
    else 
    {
        printf("Ez a hajo nem fer el a tablan:%d\n", shiplength);
    }
}

void submitviz(int col, int row, int shiplength)
{   
    if (col+shiplength < 10 && col-shiplength < 0)
    {
        while (shiplength != 0)
        {
            if (table[col+shiplength][row] == 1)
            {
                printf("Ezen a helyen van mar hajo\n");
                break;
            }
            else if (table[col+shiplength][row + 1] == 1 || table[col + shiplength][row - 1] == 1)
            {
                printf("A hajo mellet mar van egy masik\n");
                break;
            }
            else 
            {
                table[col+shiplength][row] = 1;
                shiplength--;
            }
        }
    }
    else if (col+shiplength > 10 && col-shiplength > 0)
    {
        while (shiplength != 0)
        {
            if (table[col][row-shiplength] == 1)
            {
                printf("Ezen a helyen van mar hajo\n");
                break;
            }
            else if (table[col- shiplength][row  + 1] == 1 || table[col-shiplength][row - 1] == 1)
            {
                printf("A hajo mellet mar van egy masik\n");
                break;
            }
            else 
            {
                table[col-shiplength][row] = 1;
                shiplength--;
            }
        }
    }
    else if (col+shiplength < 10 && col-shiplength > 0) 
    {
        while (shiplength != 0)
        {
            if (table[col][row-shiplength] == 1)
            {
                printf("Ezen a helyen van mar hajo\n");
            }
            else if (table[col- shiplength][row  + 1] == 1 || table[col-shiplength][row - 1] == 1)
            {
                printf("A hajo mellet mar van egy masik\n");
                break;
            }
            else 
            {
                table[col-shiplength][row] = 1;
                shiplength--;
            }
        }
    }
    else 
    {
        printf("Ez a hajo nem fer el a tablan\n");
    }
}

void submit(int col, int row, int shiplength, char direction)
{
    if (col > 10 || col < 0)
    {
        printf("Nincs ilyen oszlop\n");
    }
    else if (row > 10 || row < 0)
    {
        printf("Nincs ilyen sor\n");
    }
    else 
    {
        if (direction == '|')
        {
            submitfugg(col, row, shiplength);
        }
        else if (direction == '_')
        {
            submitviz(col, row, shiplength);
        }
    }
}


int main()
{
    const char inputcol[]={'A', 'I', 'I', 'F', 'F'};
    const int inputrow[] = {1, 3, 3, 6, 7};
    const int inputlength[] = {2, 4, 4, 3, 3};
    const int inputdirection[] = {'|', '_', '_', '|', '|'};
    
    init();
    for (int i = 0; i < 5; i++)
    {
        int col = inputcol[i] - 'A';
        int row = inputrow[i] - 1;
        int shiplength = inputlength[i];
        char direction = inputdirection[i];
        submit(col, row, shiplength, direction);
    }
    printTable();
}