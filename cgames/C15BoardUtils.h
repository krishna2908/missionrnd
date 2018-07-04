#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct Board {
	int **table;
	int rows;
	int cols;
	int emptyTileRow;
	int emptyTileCol;
}Board;
Board * createBoard(int rows, int cols){
	Board *changeThis =(struct Board*)malloc(sizeof(struct Board));
	int **arr = (int**)malloc(sizeof(int *)*rows);
	for (int i = 0; i < rows; i++)arr[i] = (int*)malloc(sizeof(int)*cols);
	 changeThis->rows = rows;
	 changeThis->cols = cols;
	 changeThis->emptyTileCol = 0;
	 changeThis->emptyTileRow = 0;

     changeThis->table = arr;
	if (cols <= 0 || rows <= 0)return NULL;
	return changeThis;
}
void initializeBoard(Board * source, int *tobeCopiedArray, int rows, int cols){
	int k = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
		 
			if (tobeCopiedArray[k] == 0){
				source->emptyTileCol = j;
				source->emptyTileRow = i;
				//k++;
			}
			source->table[i][j] = tobeCopiedArray[k++];
			
		}
	}
}

/*
Check if the Current board is in Win / Loss Condition . Return 1 if it is Win conditon , 0 if not .
Win Condition : Every Element should be in sequential Order starting from smallest number at table[0][0]
and ending at table[rows-1][cols-2] & table[rows-1][cols-1] will be 0 .
Example Input :
1,2,3,4
5,6,7,8
9,10,11,12
13,14,15,0
Example Output : Return 1
Example Input :
1,2,3,4
5,6,7,8
9,10,15,11
13,14,0,12
Example Output :Return 0
Note : Order will always start from 1 and keep on increasing by 1 , till last but 1 element is reached , Last element will be 0.
*/
int checkBoard(Board * board){
	int val = 1;
	for (int i = 0; i < board->rows; i++)
	{

		for (int j = 0; j < board->cols; j++)
		{
			if (board->table[i][j] == val){
				val++;
				continue;
			}
			if (j == 3 && i == 3&& board->table[3][3] == 0)return 1;
			//else return 0;
		}
	}
	return 0;
}



/*
Print the Board in a Good Way . Make sure Each Number is properly formatted and Seperated ,and Row lines too .
Print Empty Space when you encounter 0 . Also make sure your board looks good for 5x5 or 7x7 boards too .
Use your Thinking /UI Skills .
*/
void drawBoardOnScreen(Board *board){

	/*
	Example  : Print the current board like
	1  2  3  4
	5  6  7  8
	9 10 11 12
	13 14  0 15
	----------[W] UP --- [S] Down --- [A] LEFT --- [D] Right--------------
	*/
	for (int i = 0; i < board->rows; i++)
	{
		for (int j = 0; j < board->cols; j++)
		{
			if (board->table[i][j] == 0){
				printf(" \t");
				continue;
			}
			printf("%d\t", board->table[i][j]);
		}
		printf("\n");
	}


	printf("\n\n\n\n\t\t\t\t****       YET TO IMPLEMENT THIS FUNCTION       ****\n");

}

/*
Clear The Screen , So that we can redraw the Board (which has modified values )
*/
void clearScreen(){
	//system("cls");
}

/*
Clear the Screen and ReDraw the Board ,Call above two functions
*/
void clearAndRedrawScreen(Board * board){
	clearScreen();
	drawBoardOnScreen(board);
}
