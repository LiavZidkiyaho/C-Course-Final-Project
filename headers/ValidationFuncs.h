#ifndef ValidationFuncs
#define ValidationFuncs

#include "linkedList.h"
#include "GIFEditor.h"


int checkIfTheInputIsValid();
int checkIfTheInputIsValidLoadOrNew();
int checkIfTheFileIsExists(char* filePath);
int checkIfTheNameAlreadyExists(FrameNode* head, char* frameName);
int checkIfTheIndexIsValid(FrameNode* head, int userIndexInput);
int checkIfDurationIsValid(int newDuration);

void addFrameValidationCheck(FrameNode** head, Frame* theNewFrame);
void removeFrameValidationCheck(FrameNode** head, const char* frameName);
void changeIndexValidationCheck(FrameNode** head, const char* frameName, int newIndex);
void changeDurationValidationCheck(FrameNode** head, const char* frameName, int newDuration);
void changeAllDurationsValidationCheck(FrameNode** head, int newDuration);


#endif