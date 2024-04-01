#ifndef HEADER_COUNTER
#define HEADER_COUNTER

// Contain the result of a count execution
// todo comment better
typedef struct CountRes {
  int numBytes;
  int numChars;
  int numWords;
  int numLines;
} CountRes;

/**
 * Reproduce the result of the 'wc' command using fgets internally
 * @param fileName Path of the file to process
 * @returns A struct containg all the counters
 */
CountRes fgetsCount(char *fileName);

#endif