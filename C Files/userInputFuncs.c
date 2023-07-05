#include "userInputFuncs.h"
#include "FileHandle.h"
#include "ValidationFuncs.h"
#include "GIFEditor.h"
#include "linkedList.h"
#include "view.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100


/*
Description: This function reads an integer input from the user and returns the entered value.
Input: None
Output: An integer value representing the user's input
*/
int scanUserInput()
{
    int userInput = 0;
    scanf("%d", &userInput);
    return userInput;
}


/*
Description: This function retrieves a GIF path from the user and stores it in the 'userStrInput' string.
Input: 'userStrInput': A character array to store the user's input for the GIF path. It should have enough capacity to hold the input.
Output: none
*/
void getGifPath(char* userStrInput)
{
    getchar();
    fgets(userStrInput, MAX_LEN, stdin);

    // Remove trailing newline character if present
    int length = strlen(userStrInput);
    if (length > 0 && userStrInput[length - 1] == '\n')
    {
        userStrInput[length - 1] = '\0';
    }
}



/* 
Description: Executes the corresponding function based on user input
Input: User input, Pointer to the head of the linked list
Output: None 
*/
void switchCaseFuncCall(int userInput, FrameNode** head)
{
    char gifPath[MAX_LEN];

    int len = 0;

    switch (userInput)
    {
    case 0:
        // Exit
        freeFrameList(head);
        printf("Bye!");
        break;
    case 1:
        // Add new Frame
        case1_func_AddFrame(head);
        break;
    case 2:
        // Remove a Frame
        case2_func_RemoveFrame(head);
        break;
    case 3:
        // Change frame index
        case3_func_ChangeIndex(head);
        break;
    case 4:
        // Change frame duration
        case4_func_ChangeDuration(head);
        break;
    case 5:
        // Change duration of all frames
        case5_func_ChangeAllDurations(head);
        break;
    case 6:
        // List frames
        printFrameList(*head);
        break;
    case 7:
        // Play movie
        play(*head);
        break;
    case 8:

        printf("Enter the path of the project (including project name):\n");
        getchar();
        fgets(gifPath, MAX_LEN, stdin);

        // Remove trailing newline character if present
        len = strlen(gifPath);
        if (len > 0 && gifPath[len - 1] == '\n') 
        {
            gifPath[len - 1] = '\0';
        }

        
        saveGifToUserPath(*head, gifPath);
        break;
    }

}


/* 
Description: Creates a new frame by taking input from the user
Input: None
Output: Pointer to the newly created frame 
*/
Frame* createNewFrameFromInput()
{
    Frame* newFrame = malloc(sizeof(Frame));

    char path[MAX_LEN];
    char name[MAX_LEN];

    printf("Enter the frame path: ");
    getGifPath(path);

    newFrame->path = malloc(strlen(path) + 1);
    strcpy(newFrame->path, path);

    printf("Enter the frame duration: ");
    scanf("%d", &(newFrame->duration));

    if (!checkIfDurationIsValid(newFrame->duration))
    {
        newFrame->duration = 0;
    }

    printf("Enter the frame name: ");
    getGifPath(name);

    newFrame->name = malloc(strlen(name) + 1);
    strcpy(newFrame->name, name);

    return newFrame;
}