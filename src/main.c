#include <stdio.h>
#include <stdlib.h>


int main() {
  FILE *file;
  // buffer to store what's read in the file
  // TODO how to choose the best value here?
  // TOOD fread should be the most efficient in theory. Do another implementation with it to compare
  char line[100];

  // important to open in "rb" otherwise the number of character for newline
  // may be wrong
  file = fopen("test/data/basic-small-file.txt", "rb");
  
  // Check if the file was opened successfully
  if (file == NULL) {
    perror("Error opening file");
    return 1;
  }

  int bufferSize = 100;

  int numCharas = 0;
  int numWords = 0;
  int numLines = 0;

  // todo poor namming here. This is somewhat misleading
  int isInSpaceSequence = 1;

  // try to read the whole line
  while (fgets(line, sizeof(line), file)) {
    for (int i = 0; i < bufferSize; i++) {

      if (line[i] == '\0') {
        break;
      } else {

        if (line[i] == ' ') {
          if (!isInSpaceSequence) {
            isInSpaceSequence = 1;
          }
        } else if (line[i] == '\n') {
          isInSpaceSequence = 1;
          numLines++;
        } else {
          if (isInSpaceSequence) {
            isInSpaceSequence = 0;
            numWords++;
          }
        }

        numCharas++;
      }
    }
  }

  printf("Characters: %d\n", numCharas);
  printf("Words: %d\n", numWords);
  printf("Lines: %d\n", numLines);

  fclose(file);

  return 0;
}
