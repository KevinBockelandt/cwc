#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../header/counter.h"

// TODO is there a syntax for documenting macros?
#define OPT_BYTES 0b0001
#define OPT_CHARS 0b0010
#define OPT_WORDS 0b0100
#define OPT_LINES 0b1000

/**
 * @brief Compare if the 2 provided strings are identical
 * @param str1 First string to compare
 * @param str2 Second string to compare
 * @return 1 if the 2 strings are identical. 0 Otherwise
*/
int areStringsEqual(char* str1, char* str2) {
  int i = 0;

  while (1) {
    if (str1[i] == 0 && str2[i] == 0) return 1;
    else if (str1[i] != str2[i]) return 0;

    i++;
  }
}

int main(int argc, char *argv[]) {
  int opts = 0;
    
  for (int i = 0; i < argc; i++) {
    if (areStringsEqual(argv[i], "-c") || areStringsEqual(argv[i], "--bytes")) {
      opts |= OPT_BYTES;
    }

    if (areStringsEqual(argv[i], "-m") || areStringsEqual(argv[i], "--chars")) {
      opts |= OPT_CHARS;
    }

    if (areStringsEqual(argv[i], "-w") || areStringsEqual(argv[i], "--words")) {
      opts |= OPT_WORDS;
    }

    if (areStringsEqual(argv[i], "-l") || areStringsEqual(argv[i], "--lines")) {
      opts |= OPT_LINES;
    }
  }

  fgetsCount("test/data/basic-lorem-ipsum.txt", opts);
  return 0;
}
