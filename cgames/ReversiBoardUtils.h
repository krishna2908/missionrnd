#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ReversiGame {
	char **board;	// char 'w' for whites, 'b' for blacks ' ' for empty 
	char *player1name;
	char *player2name;
	int whiteCount = 0;
	int blackCount = 0;
	int NumberofMoves = 0;
	int rows, cols;
	int turn = 1;   //1 for white, -1 for black
	int state = 0;  //0 for unfinished, 1 for game over
	int winner = 0; //1 for white, -1 for black
}ReversiGame;


void endGame(ReversiGame *game);
int hasMove(ReversiGame *game);
void modifyTurn(ReversiGame *game);
int checkReversiGameOver(ReversiGame *game);

ReversiGame * createNewGame(int rows, int cols, char *player1, char *player2) {
	if (rows <= 0 || cols <= 0 || rows != cols)
		return NULL;
	ReversiGame *game = (ReversiGame *)malloc(sizeof(ReversiGame));
	char **playboard = (char **)malloc(sizeof(char *)*(rows + 1));
	for (int i = 1; i <= rows; i++)	{
		playboard[i] = (char *)malloc(sizeof(char)*(cols + 2));
		playboard[i][cols + 1] = '\0';
	}
	game->rows = rows;
	game->cols = cols;
	game->board = playboard;
	game->player1name = player1;
	game->player2name = player2;
	return game;
}
void initializeReversiGame(ReversiGame *game, char *tobeCopiedBoard, int rows, int cols, int turn) {
	game->whiteCount = 0;
	game->blackCount = 0;
	for (int i = 1; i <= rows; i++)
	{
		for (int j = 1; j <= cols; j++)
		{
			game->board[i][j] = *((tobeCopiedBoard + (i - 1)*(cols + 1)) + j - 1);
			if (game->board[i][j] == 'w')	game->whiteCount++;
			else if (game->board[i][j] == 'b')	game->blackCount++;
		}
	}
	game->NumberofMoves = 0;
	game->winner = 0;
	game->state = 0;
	game->turn = turn;
	if (checkReversiGameOver(game) == 0)endGame(game);
	if (hasMove(game) == 0)game->turn *= -1;
	return;
}
int checkReversiGameOver(ReversiGame *game){
	int w = game->whiteCount;
	int b = game->blackCount;
	if (w+b== (game->rows*game->cols) || w==0|| b==0)
	{
		endGame(game);
		return 0;
	}
	if (!hasMove(game))
	{
		game->turn *= -1;
		if (!hasMove(game))
		{
			endGame(game);
			return 0;
		}
		game->turn *= -1;
	}
	return 1;
}

void printMoves(ReversiGame *game){
	printf("\nWhites Count : %d\n", game->whiteCount);
	printf("Black Count : %d\n", game->blackCount);
	printf("Move Count : %d\n", game->NumberofMoves);
	return;
}
void drawBoardOnScreen(ReversiGame *game) {
	for (int i = 1; i <= game->rows; i++)
	{
		for (int j = 1; j <= game->cols; j++)
		{
			printf("%c   ", game->board[i][j]);
		}
		printf("\n");
	}
	return;
}
void clearScreen(ReversiGame *game){	system("cls");
}

void clearAndRedrawScreen(ReversiGame *game){
	clearScreen(game);
	drawBoardOnScreen(game);
}