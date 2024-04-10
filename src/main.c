#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../header/counter.h"

// TODO is there a syntax for documenting macros?
#define OPT_CHARS 0b0010
#define OPT_WORDS 0b0100
#define OPT_LINES 0b1000

/**
 * @brief Compare if the 2 provided strings are identical
 * @param str1 First string to compare
 * @param str2 Second string to compare
 * @return 1 if the 2 strings are identical. 0 Otherwise
*/
int areStringsEqual(char *str1, char *str2) {
  int i = 0;

  while (1) {
    if (str1[i] == 0 && str2[i] == 0) return 1;
    else if (str1[i] != str2[i]) return 0;

    i++;
  }
}

int main(int argc, char *argv[]) {
  int opts = 0;
  char *filePath = NULL;
  FILE *file = NULL;
  CountRes res;
    
  // process all the input arguments to get the options and the file to process
  for (int i = 0; i < argc; i++) {
    if (i == 0) continue;
    char *arg = argv[i];

    if (areStringsEqual(arg, "--chars")) opts |= OPT_CHARS;
    else if (areStringsEqual(arg, "--words")) opts |= OPT_WORDS;
    else if (areStringsEqual(arg, "--lines")) opts |= OPT_LINES;
    else if (arg[0] == '-' && arg[1] != '\0') {
      int j = 1;
      while (arg[j] != '\0') {
        if (arg[j] == 'm') opts |= OPT_CHARS;
        else if (arg[j] == 'w') opts |= OPT_WORDS;
        else if (arg[j] == 'l') opts |= OPT_LINES;
        else printf("Unknown option '%c'\n", arg[j]);
        j++;
      }
    }
    // if nothing worked so far we assume the argument should be a file path
    else {
      if (filePath != NULL) {
        printf("Warning: only one file can be processed at a time\n");
        printf("'%s' was kept\n", filePath);
      } else {
        filePath = arg;

        // make sure that this file can be opened
        file = fopen(filePath, "rb");
        if (file == NULL) {
          printf("Warning: '%s' is not a valid option nor a valid file path\n", filePath);
          filePath = NULL;
        }
      }
    }
  }

  if (filePath == NULL) {
    printf("Error: You need to enter a path to the file to process\n");
    return 1;
  }

  // by default, if no option is specified we activate every options
  opts = opts == 0 ? 0b1111 : opts;

  // call the function doing the actual counting
  res = fgetsCount(file);

  // display only results for which the option was activated
  if (opts & OPT_CHARS) {
    printf("Characters: %d\n", res.numChars);
  }
  if (opts & OPT_WORDS) {
    printf("Words: %d\n", res.numWords);
  }
  if (opts & OPT_LINES) {
    printf("Lines: %d\n", res.numLines);
  }

  if (file != NULL) {
    fclose(file);
  }

  return 0;
}
