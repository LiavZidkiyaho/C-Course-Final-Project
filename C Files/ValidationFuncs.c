#include "userInputFuncs.h"
#include "GIFEditor.h"
#include "linkedList.h"
#include "view.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



/* 
Description: Checks if the user input is a valid option 
Input: None
Output: Valid user input 
*/
int checkIfTheInputIsValid()
{
    int userInput = -1;

    while (userInput < 0 || userInput > 8)
    {
        userInput = scanUserInput();
        if (userInput < 0 || userInput > 8)
        {
            printf("You should type one of the options - 0-8!\n\n");
            printCommandMenu();
        }
    }
    return userInput;
}


/* 
Description: Checks if a file exists at the given file path
Input: File path
Output: Returns 1 if the file exists, 0 otherwise 
*/
int checkIfTheFileIsExists(char* filePath)
{
    FILE* file = fopen(filePath, "r");
    if (file != NULL)
    {
        // File exists
        fclose(file);
        return 1;
    }
    else
    {
        // File does not exist
        return 0;
    }
}


/* 
Description: Checks if a frame name already exists in the linked list
Input: Head of the linked list, Frame name
Output: Returns 1 if the name already exists, 0 otherwise 
*/
int checkIfTheNameAlreadyExists(FrameNode* head, char* frameName)
{
    FrameNode* current = head;

    while (current != NULL)
    {
        if (strcmp(current->frame->name, frameName) == 0)
        {
            // Name already exists
            return 1;
        }

        current = current->next;
    }

    // Name does not exist
    return 0;
}



/* 
Description: Checks if a given index is valid within the linked list
Input: Head of the linked list, User index input
Output: Returns 1 if the index is valid, 0 otherwise 
*/
int checkIfTheIndexIsValid(FrameNode* head, int userIndexInput)
{
    int frameCount = 0;
    FrameNode* current = head;

    while (current != NULL)
    {
        frameCount++;
        current = current->next;
    }

    // Check if the userIndexInput is within the valid range
    if (userIndexInput >= 1 && userIndexInput <= frameCount)
    {
        // Index is valid
        return 1;
    }

    // Index is invalid
    return 0;
}


/* 
Description: Checks if a given duration is valid
Input: New duration
Output: Returns 1 if the duration is valid, 0 otherwise 
*/
int checkIfDurationIsValid(int newDuration)
{
    if (newDuration >= 0) 
    {
        return 1; // Duration is valid
    }
    else 
    {
        return 0; // Duration is invalid
    }
}


/* 
Description: Performs validation checks before adding a frame to the linked list
Input: Head of the linked list, Pointer to the new frame
Output: None 
*/
void addFrameValidationCheck(FrameNode** head, Frame* theNewFrame)
{
    if (checkIfTheFileIsExists(theNewFrame->path) == 0)
    {
        printf("Can't find file! Frame will not be added");
        return;
    }
    else if (checkIfTheNameAlreadyExists(*head, theNewFrame->name) == 1)
    {
        int isValidName = 0; // Flag to indicate if the name is valid

        while (!isValidName)
        {
            if (checkIfTheNameAlreadyExists(*head, theNewFrame->name) == 1)
            {
                printf("The name is already taken, please enter another name: \n");
                scanf("%s", theNewFrame->name);
            }
            else
            {
                isValidName = 1; // Set the flag to indicate a valid name
            }
        }
    }
    addNewFrame(head, theNewFrame);
    
}


/* 
Description: Performs validation checks before removing a frame from the linked list
Input: Head of the linked list, Frame name
Output: None 
*/
void removeFrameValidationCheck(FrameNode** head, const char* frameName)
{
    if (checkIfTheNameAlreadyExists(*head, frameName) == 1)
    {
        removeFrame(head, frameName);
    }
    else
    {
        printf("The frame was not found");
    }
}


/* 
Description: Performs validation checks before changing the index of a frame in the linked list
Input: Head of the linked list, Frame name, New index
Output: None 
*/
void changeIndexValidationCheck(FrameNode** head, const char* frameName, int newIndex)
{
    int isValidIndex = 0; // Flag to indicate if the index is valid

    if (checkIfTheNameAlreadyExists(*head, frameName) == 0)
    {
        printf("This frame does not exist");
        return;
    }

    while (!isValidIndex)
    {
        if (checkIfTheIndexIsValid(*head, newIndex) == 0)
        {
            printf("The movie contains only %d frames!\n", listLength(*head));
            printf("Enter the new index in the movie you wish to place the frame\n");
            scanf("%d", &newIndex);
        }
        else
        {
            isValidIndex = 1;
        }
    }

    changeFrameIndex(head, frameName, newIndex);
}


/* 
Description: Performs validation checks before changing the duration of a frame in the linked list
Input: Head of the linked list, Frame name, New duration
Output: None 
*/
void changeDurationValidationCheck(FrameNode** head, const char* frameName, int newDuration)
{
    if (checkIfTheNameAlreadyExists(*head, frameName) == 0)
    {
        printf("The frame does not exist");
        return;
    }
    changeFrameDuration(head, frameName, newDuration);
}


/* 
Description: Performs validation checks before changing the duration of all frames in the linked list
Input: Head of the linked list, New duration
Output: None 
*/
void changeAllDurationsValidationCheck(FrameNode** head, int newDuration)
{
    changeAllFrameDuration(head, newDuration);
}



/*
Description: This function checks if the user input is valid for loading or creating a new user profile.
Input: None
Output: An integer representing the user's choice (0 for loading, 1 for creating a new profile)
*/
int checkIfTheInputIsValidLoadOrNew()
{
    int loadOrNewUserInput = -1;

    while (loadOrNewUserInput != 0 && loadOrNewUserInput != 1)
    {
        loadOrNewUserInput = scanUserInput();
        if (loadOrNewUserInput != 0 && loadOrNewUserInput != 1)
        {
            printf("Invalid choice, try again:\n");
            printNewOrLoadGIFMenu();
        }
    }
    return loadOrNewUserInput;
}