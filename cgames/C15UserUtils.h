#include <string.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct User{
	char *name;
	int movesCount;
}User;
User * createUser(char *name){
	User *user = (struct User*)malloc(sizeof(struct User));
	user->name = name;
	user->movesCount = 0;
	return user;
}
void modifyMoveCountBasedOnProccessInput(User *user, int processInputOutCome){
	if (processInputOutCome == 1)user->movesCount++;
	return;
}

/*
Print the Following String from User Information .Replace accordingly .Dont ask what to Replace .
"Hey Abhijith , You have played 43 Moves "
*/
void printUser(User *user){
	printf("hey krishna, you have played %d mooves", user->movesCount);
}