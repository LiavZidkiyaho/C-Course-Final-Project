#ifndef USERINPUTFUNCS_H
#define USERINPUTFUNCS_H

#include "linkedList.h"


int scanUserInput();
void getGifPath(char* userStrInput);
void switchCaseFuncCall(int userInput, FrameNode** head);
Frame* createNewFrameFromInput();

#endif
