int isvalidCoordinate(ReversiGame *, int, int);
typedef struct ReversiMove {
	int x, y;
}ReversiMove;
ReversiMove *createMove(int x, int y) {
	ReversiMove *moves = (ReversiMove *)malloc(sizeof(ReversiMove));
	moves->x = x;
	moves->y = y;
	return moves;
}
ReversiMove *inputMove(ReversiGame *game) {
	int x, y;
	while (true)
	{
    		scanf("%d %d", &x, &y);
			if (x <= game->rows && y <= game->cols && x>0 && y>0)return createMove(x, y);
			else continue;
	}
	return NULL;
}
int isvalidCoordinate(ReversiGame *game, int x, int y) {
	if (x <= game->rows && y <= game->cols && x>0 && y>0)  return 1;
	else return 0;
}
char  set(int a)
{
	if (a == 1)return 'w';
	else return 'b';
}
int right(ReversiGame *game, int x, int y, char turn)
{
	if (isvalidCoordinate(game, x, y + 1))
	{
		if (game->board[x][y + 1] != ' ' && game->board[x][y + 1] != turn)
		{
			for (int yc = y + 2; isvalidCoordinate(game, x, yc); yc++)
			{
				if (game->board[x][yc] == ' ')	break;
				if (game->board[x][yc] == turn)
				{
					return 1;
				}
			}
		}
	}
	return 0;
}
int left(ReversiGame *game, int x, int y, char turn)
{
	if (isvalidCoordinate(game, x, y - 1))
	{
		if (game->board[x][y - 1] != ' ' && game->board[x][y - 1] != turn)
		{
			for (int yc = y - 2; isvalidCoordinate(game, x, yc); yc--)
			{
				if (game->board[x][yc] == ' ')	break;
				if (game->board[x][yc] == turn)
				{
					return 1;
				}
			}
		}
	}
	return 0;
}
int up(ReversiGame *game, int x, int y, char turn)
{
	if (isvalidCoordinate(game, x - 1, y))
	{
		if (game->board[x - 1][y] != ' ' && game->board[x - 1][y] != turn)
		{
			for (int xc = x - 2; isvalidCoordinate(game, xc, y); xc--)
			{
				if (game->board[xc][y] == ' ')	break;
				if (game->board[xc][y] == turn)
				{
					return 1;
				}
			}
		}
	}return 0;
}

int down(ReversiGame *game, int x, int y, char turn)
{
	if (isvalidCoordinate(game, x + 1, y))
	{
		if (game->board[x + 1][y] != ' ' && game->board[x + 1][y] != turn)
		{
			for (int xc = x + 2; isvalidCoordinate(game, xc, y); xc++)
			{
				if (game->board[xc][y] == ' ')	break;
				if (game->board[xc][y] == turn)
				{
					return 1;
				}
			}
		}
	}

	return 0;
}
int diag1(ReversiGame *game, int x, int y, char turn)
{
	if (isvalidCoordinate(game, x - 1, y + 1))
	{
		if (game->board[x - 1][y + 1] != ' ' && game->board[x - 1][y + 1] != turn)
		{
			for (int xc = x - 2, yc = y + 2; isvalidCoordinate(game, xc, yc); xc--, yc++)
			{
				if (game->board[xc][yc] == ' ')	break;
				if (game->board[xc][yc] == turn)
				{
					return 1;
				}
			}
		}
	}
	return 0;
}
int diag2(ReversiGame *game, int x, int y, char turn)
{
	if (isvalidCoordinate(game, x + 1, y - 1))
	{
		if (game->board[x + 1][y - 1] != ' ' && game->board[x + 1][y - 1] != turn)
		{
			for (int xc = x + 2, yc = y - 2; isvalidCoordinate(game, xc, yc); xc++, yc--)
			{
				if (game->board[xc][yc] == ' ')	break;
				if (game->board[xc][yc] == turn)
				{
					return 1;
				}
			}
		}
	}


	return 0;
}
int diag3(ReversiGame *game, int x, int y, char turn)
{
	if (isvalidCoordinate(game, x + 1, y + 1))
	{
		if (game->board[x + 1][y + 1] != ' ' && game->board[x + 1][y + 1] != turn)
		{
			for (int xc = x + 2, yc = y + 2; isvalidCoordinate(game, xc, yc); xc++, yc++)
			{
				if (game->board[xc][yc] == ' ')	break;
				if (game->board[xc][yc] == turn)
				{
					return 1;
				}
			}
		}
	}
	return 0;
}
int diag4(ReversiGame *game, int x, int y, char turn)
{
	if (isvalidCoordinate(game, x - 1, y - 1))
	{
		if (game->board[x - 1][y - 1] != ' ' && game->board[x - 1][y - 1] != turn)
		{
			for (int xc = x - 2, yc = y - 2; isvalidCoordinate(game, xc, yc); xc--, yc--)
			{
				if (game->board[xc][yc] == ' ')	break;
				if (game->board[xc][yc] == turn)
				{
					return 1;
				}
			}
		}
	}
	return 0;
}
int isValidMove(ReversiGame *game, ReversiMove *move) {
	if (isvalidCoordinate(game, move->x, move->y) && game->board[move->x][move->y] != ' ')return 0;
	if (isvalidCoordinate(game, move->x, move->y) == 0)return 0;
	int x, y;
	char turn=set(game->turn);
	x = move->x;
	y = move->y;
	if (right(game, x, y, turn))return 1;
	if (left(game, x, y, turn))return 1;
	if (up(game, x, y, turn))return 1;
	if (down(game, x, y, turn))return 1;
	if (diag1(game, x, y, turn))return 1;
	if (diag2(game, x, y, turn))return 1;
	if (diag3(game, x, y, turn))return 1;
	if (diag4(game, x, y, turn))return 1;
	return 0;
}
int hasMove(ReversiGame *game){
	for (int i = 1; i <= game->rows; i++)
	{
		for (int j = 1; j <= game->cols; j++)
		{
			ReversiMove  *move = createMove(i, j);
			if (isValidMove(game, move))return 1;
		}
	}
	return 0;
}
void incrementMoves(ReversiGame *game) {
	game->NumberofMoves++;
	return;
}
void modifyTurn(ReversiGame *game) {
	game->turn *= -1;
	return;
}
void endGame(ReversiGame *game) {
	int b = game->blackCount, w = game->whiteCount;
	if (b>w)game->winner = -1;
	 if(b<w) game->winner = 1;
	game->state = 1;
	return;
}
void modify(ReversiGame *game) {
	incrementMoves(game);
	modifyTurn(game);
}
void playright(ReversiGame *game, int x, int y, char turn,int *t){
	int to = *t;
	if (isvalidCoordinate(game, x, y + 1))
	{
		if (game->board[x][y + 1] != ' ' && game->board[x][y + 1] != turn)
		{
			for (int yc = y + 2; isvalidCoordinate(game, x, yc); yc++)
			{
				if (game->board[x][yc] == turn)
				{
					yc--;
					while (yc != y)
					{
						to++;
						*t = to;
						game->board[x][yc] = turn;
						yc--;
					}
					break;
				}
				if (game->board[x][yc] == ' ')	break;
			}
		}
	}
}
void playleft(ReversiGame *game, int x, int y, char turn, int *t){
	int to = *t;
	if (isvalidCoordinate(game, x, y - 1))
	{
		if (game->board[x][y - 1] != ' ' && game->board[x][y - 1] != turn)
		{
			for (int yc = y - 2; isvalidCoordinate(game, x, yc); yc--)
			{

				if (game->board[x][yc] == turn)
				{
					yc++;
					while (yc != y)
					{
						to++;
						*t = to;
						game->board[x][yc] = turn;
						yc++;
					}
					break;
				}
				if (game->board[x][yc] == ' ')	break;
			}
		}
	}

}
void playup(ReversiGame *game, int x, int y, char turn, int *t){
	int to = *t;
	if (isvalidCoordinate(game, x - 1, y))
	{
		if (game->board[x - 1][y] != ' ' && game->board[x - 1][y] != turn)
		{
			for (int xc = x - 2; isvalidCoordinate(game, xc, y); xc--)
			{
				if (game->board[xc][y] == turn)
				{
					xc++;
					while (xc != x)
					{
						to++;
						*t = to;
						game->board[xc][y] = turn;
						xc++;
					}
					break;
				}
				if (game->board[xc][y] == ' ')	break;
			}
		}
	}
}
void playdown(ReversiGame *game, int x, int y, char turn, int *t){
	int to = *t;
	if (isvalidCoordinate(game, x + 1, y))
	{
		if (game->board[x + 1][y] != ' ' && game->board[x + 1][y] != turn)
		{
			for (int xc = x + 2; isvalidCoordinate(game, xc, y); xc++)
			{
				if (game->board[xc][y] == turn)
				{
					xc--;
					while (xc != x)
					{
						to++;
						*t = to;
						game->board[xc][y] = turn;
						xc--;
					}
					break;
				}
				if (game->board[xc][y] == ' ')	break;
			}
		}
	}

}
void playdiag1(ReversiGame *game, int x, int y, char turn, int *t){
	int to = *t;
	if (isvalidCoordinate(game, x - 1, y + 1))
	{
		if (game->board[x - 1][y + 1] != ' ' && game->board[x - 1][y + 1] != turn)
		{
			for (int xc = x - 2, yc = y + 2; isvalidCoordinate(game, xc, yc); xc--, yc++)
			{
				if (game->board[xc][yc] == turn)
				{
					xc++;
					yc--;
					while (xc != x)							{
						to++;
						*t = to;
						game->board[xc][yc] = turn;
						xc++;
						yc--;
					}
					break;
				}
				if (game->board[xc][yc] == ' ')	break;
			}
		}
	}
}
void playdiag2(ReversiGame *game, int x, int y, char turn, int *t){
	int to = *t;
	if (isvalidCoordinate(game, x + 1, y + 1))
	{
		if (game->board[x + 1][y + 1] != ' ' && game->board[x + 1][y + 1] != turn)
		{
			for (int xc = x + 2, yc = y + 2; isvalidCoordinate(game, xc, yc); xc++, yc++)
			{
				if (game->board[xc][yc] == turn)
				{
					xc--;
					yc--;
					while (xc != x)
					{
						to++;
						*t = to;
						game->board[xc][yc] = turn;
						xc--;
						yc--;
					}
					break;
				}
				if (game->board[xc][yc] == ' ')	break;
			}
		}
	}

}
 void playdiag3(ReversiGame *game, int x, int y, char turn, int *t){
	 int to = *t;
	if (isvalidCoordinate(game, x - 1, y - 1))
	{
		if (game->board[x - 1][y - 1] != ' ' && game->board[x - 1][y - 1] != turn)
		{
			for (int xc = x - 2, yc = y - 2; isvalidCoordinate(game, xc, yc); xc--, yc--)
			{
				if (game->board[xc][yc] == turn)
				{
					xc++;
					yc++;
					while (xc != x)
					{
						to++;
						*t = to;
						game->board[xc][yc] = turn;
						xc++;
						yc++;
					}
					break;
				}
				if (game->board[xc][yc] == ' ')	break;
			}
		}
	}

}
 void playdiag4(ReversiGame *game, int x, int y, char turn, int *t){
	 int to = *t;
	 if (isvalidCoordinate(game, x + 1, y - 1))
	 {
		 if (game->board[x + 1][y - 1] != ' ' && game->board[x + 1][y - 1] != turn)
		 {
			 for (int xc = x + 2, yc = y - 2; isvalidCoordinate(game, xc, yc); xc++, yc--)
			 {
				 if (game->board[xc][yc] == turn)
				 {
					 xc--;
					 yc++;
					 while (xc != x)
					 {
						 to++;
						 *t = to;
						 game->board[xc][yc] = turn;
						 xc--;
						 yc++;
					 }
					 break;
				 }
				 if (game->board[xc][yc] == ' ')	break;
			 }
		 }
	 }

 }
 void setcount(ReversiGame *game,int *t)
 {
	 int total = *t;
	 if (game->turn == 1)
	 {
		 game->whiteCount += total;
		 game->blackCount -= (total - 1);
	 }
	 else
	 {
		 game->blackCount += total;
		 game->whiteCount -= (total - 1);
	 }

 }
 bool playMove(ReversiGame *game, ReversiMove *move) {
	int total = 1;
	int x = move->x, y = move->y, r = game->rows, c = game->cols;
	if (x > 0 && x <= r&& y > 0 && y <=c)
	{
		if (isValidMove(game, move))
		{
			char turn = set(game->turn);
			playright(game, x, y, turn,&total);
			playleft(game, x, y, turn, &total);
			playup(game, x, y, turn, &total);
			playdown(game, x, y, turn, &total);
			playdiag1(game, x, y, turn, &total);
			playdiag2(game, x, y, turn, &total);
			playdiag3(game, x, y, turn, &total);
			playdiag4(game, x, y, turn, &total);
			game->board[x][y] = turn;
			setcount(game, &total);
			modify(game);
			if (hasMove(game) == 0)
			{
				modify(game);
				game->NumberofMoves--;
			}
			return true;
		}
	}
	return false;
}
void printWinner(ReversiGame *game) {
	if (game->winner==0)
		printf("Game is Drawn\n");
	else if (game->winner == -1)
	{
		printf("%s  won the game ", game->player1name);
	}
	else
	{
		printf("%s  won the game \n", game->player2name);
	}
}