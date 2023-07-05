#include "ScreenOutput.h"
#include "linkedList.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
Description: Prints the command menu for the user
Input: None
Output: None 
*/
void printCommandMenu()
{
    printf("\nWhat would you like to do?\n [0] Exit\n [1] Add new Frame\n [2] Remove a Frame\n [3] Change frame index\n [4] Change frame duration\n [5] Change duration of all frames\n [6] List frames\n [7] Play movie!\n [8] Save project\n");
}


/*
Description: This function prints a menu for the user to choose between creating a new project or loading an existing project.
Input: None
Output: None
*/
void printNewOrLoadGIFMenu()
{
    printf("Welcome to Magshimim Movie Maker! what would you like to do?\n [0] Create a new project\n [1] Load existing project\n\n");
}


/* 
Description: Prints the list of frames with their details
Input: Head of the linked list
Output: None 
*/
void printFrameList(FrameNode* head)
{
    FrameNode* current = head;

    printf("Name\t\tDuration\tPath\n");

    while (current != NULL)
    {
        printf("%s\t\t%d\t\t%s\n", current->frame->name, current->frame->duration, current->frame->path);
        current = current->next;
    }
}
