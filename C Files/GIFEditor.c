#include "GIFEditor.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>




/* 
Description: Adds a new frame to the end of the linked list
Input: Pointer to the head of the linked list, Pointer to the new frame to be added
Output: None 
*/
void addNewFrame(FrameNode** head, Frame* theNewFrame) 
{
    // Create a new node
    FrameNode* newNode = (FrameNode*)malloc(sizeof(FrameNode));
    newNode->frame = theNewFrame;
    newNode->next = NULL;

    if (*head == NULL) 
    {
        // If the list is empty, make the new node the head
        *head = newNode;
    }
    else {
        // Find the last node in the list
        FrameNode* current = *head;
        while (current->next != NULL) 
        {
            current = current->next;
        }

        // Append the new node to the end of the list
        current->next = newNode;
    }
}


/* 
Description: Removes a frame from the linked list based on the frame name
Input: Pointer to the head of the linked list, Name of the frame to be removed
Output: None 
*/
void removeFrame(FrameNode** head, char* frameNameToDel)
{
    FrameNode* current = *head;
    FrameNode* previous = NULL;

    while (current != NULL && strcmp(current->frame->name, frameNameToDel) != 0)
    {
        previous = current;
        current = current->next;
    }
    if (previous == NULL)
    {
        *head = current->next;
    }
    else
    {
        previous->next = current->next;
    }
    
}


/*
Description: Changes the index of a frame in the linked list
Input: Pointer to the head of the linked list, Name of the frame to be moved, New index for the frame
Output: None 
*/
void changeFrameIndex(FrameNode** head, char* frameNameToChange, int newIndex)
{
    FrameNode* currentNode = *head;
    FrameNode* prevNode = NULL;
    FrameNode* foundNode = NULL;
    FrameNode* prevFoundNode = NULL;

    int currentIndex = 0;

    // Traverse the list to find the frame to be moved
    while (currentNode != NULL)
    {
        if (strcmp(currentNode->frame->name, frameNameToChange) == 0)
        {
            foundNode = currentNode;
            break;
        }
        prevNode = currentNode;
        currentNode = currentNode->next;
    }

    // Check if the frame to be moved is found
    if (foundNode != NULL)
    {
        // If the new index is the same as the current index, no need to move
        if (prevNode != NULL && prevNode->next == foundNode->next)
            return;

        // Remove the found node from its current position
        if (prevNode != NULL)
        {
            prevNode->next = foundNode->next;
        }
        else
        {
            *head = foundNode->next;
        }

        // Find the node at the new index
        currentNode = *head;
        prevNode = NULL;
        currentIndex = 1;

        // Traverse until the desired index or the end of the list is reached
        while (currentNode != NULL && currentIndex < newIndex)
        {
            prevNode = currentNode;
            currentNode = currentNode->next;
            currentIndex++;
        }

        // Insert the found node at the new index
        if (prevNode != NULL)
        {
            prevNode->next = foundNode;
            foundNode->next = currentNode;
        }
        else
        {
            foundNode->next = *head;
            *head = foundNode;
        }
    }
}


/* 
Description: Changes the duration of a frame in the linked list
Input: Pointer to the head of the linked list, Name of the frame to be updated, New duration for the frame
Output: None 
*/
void changeFrameDuration(FrameNode** head, char* frameNameToChange, int newDuration)
{
    FrameNode* current = *head;

    // Traverse the linked list to find the frame to change its duration
    while (current != NULL)
    {
        if (strcmp(current->frame->name, frameNameToChange) == 0)
        {
            // Update the frame's duration
            current->frame->duration = newDuration;
        }

        current = current->next;
    }
}


/* 
Description: Changes the duration of all frames in the linked list
Input: Pointer to the head of the linked list, New duration for all frames
Output: None
*/
void changeAllFrameDuration(FrameNode** head, int newDuration)
{
    FrameNode* current = *head;

    // Traverse the linked list and update the duration of all frames
    while (current != NULL)
    {
        current->frame->duration = newDuration;
        current = current->next;
    }
}


/* 
Description: Calculates the length of the linked list
Input: Head of the linked list
Output: Length of the linked list 
*/
int listLength(FrameNode* head)
{
    if (head == NULL)
    {
        return 0;
    }
    else
    {
        return 1 + listLength(head->next);
    }
}


/* 
Description: Frees the memory occupied by a single frame
Input: Pointer to the frame to be freed
Output: None 
*/
void freeFrame(Frame* frame)
{
    free(frame);
}


/* 
Description: Frees the memory occupied by the entire linked list of frames
Input: Pointer to the head of the linked list
Output: None 
*/
void freeFrameList(FrameNode** head)
{
    FrameNode* current = *head;
    FrameNode* next = NULL;

    while (current != NULL)
    {
        next = current->next;

        // Free the frame
        freeFrame(current->frame);

        // Free the node
        free(current);

        current = next;
    }

    *head = NULL;
}