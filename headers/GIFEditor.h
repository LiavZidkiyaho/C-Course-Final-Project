#ifndef GIFEditor
#define GIFEditor

#include "linkedList.h"

void addNewFrame(FrameNode* head, Frame* theNewFrame);
void removeFrame(FrameNode* head, char* frameNameToDel);
void changeFrameIndex(FrameNode* head, char* frameNameToChange, int newIndex);
void changeFrameDuration(FrameNode* head, char* frameNameToChange, int newDuration);
void changeAllFrameDuration(FrameNode* head, int newDuration);
void searchFrameByName(FrameNode* head, char* frameNameToSearch);
int listLength(FrameNode* head);
void freeFrame(Frame* frame);
void freeFrameList(FrameNode** head);

#endif