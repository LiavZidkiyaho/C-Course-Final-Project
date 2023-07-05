#include "userInputFuncs.h"
#include "FileHandle.h"
#include "ScreenOutput.h"
#include "ValidationFuncs.h"
#include "linkedList.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100



int main()
{
	FrameNode* head = NULL;

	int userInput = -1;
	int loadOrNewUserInput = -1;
	int len = 0;

	char gifPath[MAX_LEN];

	printNewOrLoadGIFMenu();
	loadOrNewUserInput = checkIfTheInputIsValidLoadOrNew();
	if (loadOrNewUserInput == 1)
	{
		printf("Enter the path of the project (including project name):\n");
		getGifPath(gifPath);

		if (checkIfTheFileIsExists(gifPath) == 0)
		{
			printf("Error!- cant open file, creating a new project\n");
		}
		else
		{
			printf("Project loaded successfully\n\n");
			loadGifFromUserPath(&head, gifPath);
		}

	}

	do
	{
		printCommandMenu();
		userInput = checkIfTheInputIsValid();
		switchCaseFuncCall(userInput, &head);

	} while (userInput != 0);

	getchar();
	getchar();
	return 0;
}