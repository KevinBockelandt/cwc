#ifndef HEADER_COUNTER
#define HEADER_COUNTER

/**
 * @struct CountRes
 * @brief Contain the result of a count execution
 */
typedef struct CountRes {
  /// @brief The number of bytes of the file
  int numBytes;
  /// @brief The number of characters of the file
  int numChars;
  /// @brief The number of words of the file
  int numWords;
  /// @brief The number of lines of the file
  int numLines;
} CountRes;

/**
 * Reproduce the result of the 'wc' command using fgets internally
 * @param fileName Path of the file to process
 * @param opts Options from the command line
 * @returns A struct containg all the counters
 */
CountRes fgetsCount(char *fileName, int opts);

#endif
