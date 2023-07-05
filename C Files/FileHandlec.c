#include "FileHandle.h"
#include "userInputFuncs.h"
#include "FileHandle.h"
#include "ScreenOutput.h"
#include "ValidationFuncs.h"
#include "linkedList.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
Description: This function saves the information of a linked list of GIF frames to a file specified by the 'filePath'.
Input:
'head': A double pointer to the head of the linked list of GIF frames. It represents the starting point of the list.
'filePath': A string that specifies the path to the file where the GIF information will be saved.
Output: none
*/
void saveGifToUserPath(FrameNode** head, char* filePath)
{
    FILE* file = fopen(filePath, "w");

    FrameNode* currentNode = NULL;

    if (file == NULL)
    {
        printf("Failed to open file for writing.\n");
        return;
    }

    currentNode = head;
    while (currentNode != NULL)
    {
        fprintf(file, "%s,%d,%s\n", currentNode->frame->path, currentNode->frame->duration, currentNode->frame->name);
        currentNode = currentNode->next;
    }

    fclose(file);
}




/*
Description:This function loads GIF information from a file specified by the 'filePath' and creates a linked list of frames.
Input:
'head': A double pointer to the head of the linked list of GIF frames. It represents the starting point of the list.
filePath': A string that specifies the path to the file from which the GIF information will be loaded.
Output: none
*/
void loadGifFromUserPath(FrameNode** head, char* filePath) 
{
    char path[100];
    unsigned int duration;
    char name[100];
    char line[256];

    FILE* file = fopen(filePath, "r");
    if (file == NULL) 
    {
        printf("Failed to open file: %s\n", filePath);
        return;
    }

    while (fgets(line, sizeof(line), file) != NULL) 
    {
        sscanf(line, "%[^,],%u,%[^\n\r]", path, &duration, name);

        Frame* frame = (Frame*)malloc(sizeof(Frame));
        frame->name = (char*)malloc(strlen(name) + 1);
        strcpy(frame->name, name);
        frame->duration = duration;
        frame->path = (char*)malloc(strlen(path) + 1);
        strcpy(frame->path, path);

        addNewFrame(head, frame);
    }

    fclose(file);
}



