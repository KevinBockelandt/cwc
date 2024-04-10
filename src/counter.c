#include <stdio.h>
#include <stdlib.h>
#include "../header/counter.h"

#define BUFFER_SIZE_READ 100

/**
 * @brief Process a file to extract infos needed by the command
 * @param file Handler to the file to process
 */
CountRes fgetsCount(FILE *file) {
  CountRes res = { 0, 0, 0 };

  // buffer to store what's read in the file
  // TODO how to choose the best value here?
  char line[BUFFER_SIZE_READ];

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

  return res;
}
