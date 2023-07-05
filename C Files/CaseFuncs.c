#include "CaseFuncs.h"
#include "ValidationFuncs.h"
#include "ScreenOutput.h"
#include "userInputFuncs.h"
#include "GIFEditor.h"
#include "linkedList.h"
#include "view.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100




/* 
Description: create the base steps before Adding a new frame to the linked list
Input: Pointer to the head of the linked list
Output: None 
*/
void case1_func_AddFrame(FrameNode** head)
{
    Frame* theNewFrame = createNewFrameFromInput();
    addFrameValidationCheck(head, theNewFrame);
}


/* 
Description: create the base steps Removing a frame from the linked list
Input: Pointer to the head of the linked list
Output: None 
*/
void case2_func_RemoveFrame(FrameNode** head)
{
    char frameName[MAX_LEN];
    int len = 0;

    printf("Enter the name of the frame you wish to erase\n");
    getGifPath(frameName);
    removeFrameValidationCheck(head, frameName);
}


/* 
Description: create the base steps Changing the index of a frame in the linked list
Input: Pointer to the head of the linked list
Output: None
*/
void case3_func_ChangeIndex(FrameNode** head)
{
    char frameName[MAX_LEN];
    int len = 0;
    int newIndex = 0;

    printf("Enter the name of the frame\n");
    getGifPath(frameName);
    printf("Enter the new index in the movie you wish to place the frame\n");
    scanf("%d", &newIndex);
    changeIndexValidationCheck(head, frameName, newIndex);
}


/* 
Description: create the base steps Changing the duration of a frame in the linked list
Input: Pointer to the head of the linked list
Output: None
*/
void case4_func_ChangeDuration(FrameNode** head)
{
    char frameName[MAX_LEN];
    int len = 0;
    int newDuration = 0;

    printf("Enter the name of the frame\n");
    getGifPath(frameName);
    printf("Enter the new duration\n");
    scanf("%d", &newDuration);
    if (!checkIfDurationIsValid(newDuration))
    {
        newDuration = 0;
    }
    getchar();
    changeDurationValidationCheck(head, frameName, newDuration);
}


/* 
Description: create the base steps Changing the duration of all frames in the linked list 
Input: Pointer to the head of the linked list 
Output: None 
*/
void case5_func_ChangeAllDurations(FrameNode** head)
{
    int newDuration = 0;
    printf("Enter the new duration for all frames\n");
    scanf("%d", &newDuration);
    if (!checkIfDurationIsValid(newDuration))
    {
        newDuration = 0;
    }
    getchar();
    changeAllDurationsValidationCheck(head, newDuration);
}