#ifndef FileHandle
#define FileHandle

#include "linkedList.h"

void saveGifToUserPath(FrameNode** head, char* filePath);
void loadGifFromUserPath(FrameNode** head, char* filePath);

#endif