#include <stdio.h>
#include <stdlib.h>
#include "../header/counter.h"

#define BUFFER_SIZE_READ 100

// TODO comment
CountRes fgetsCount(char *fileName, int opts) {
  CountRes res = { 0, 0, 0, 0};
  FILE *file;

  // buffer to store what's read in the file
  // TODO how to choose the best value here?
  char line[BUFFER_SIZE_READ];

  // important to open in "rb" otherwise the number of character for newline
  // may be wrong
  file = fopen(fileName, "rb");

  // Check if the file was opened successfully
  if (file == NULL) {
    perror("Error opening file");
    return res;
  }

  // 1 if the next "regular" character we find increases the word counter
  int isWaitingForNewWord = 1;

  // try to read the whole line
  while (fgets(line, sizeof(line), file)) {
    // for each character in the buffer we read
    for (int i = 0; i < BUFFER_SIZE_READ; i++) {

      if (line[i] == '\0') {
        break;
      } else {

        if (line[i] == ' ') {
          if (!isWaitingForNewWord) {
            isWaitingForNewWord = 1;
          }
        } else if (line[i] == '\n') {
          isWaitingForNewWord = 1;
          res.numLines++;
        } else {
          if (isWaitingForNewWord) {
            isWaitingForNewWord = 0;
            res.numWords++;
          }
        }

        // anyting other that a terminating char is counted
        res.numChars++;
      }
    }
  }

  fclose(file);
  return res;
}
