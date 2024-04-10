#ifndef HEADER_COUNTER
#define HEADER_COUNTER

/**
 * @struct CountRes
 * @brief Contain the result of a count execution
 */
typedef struct CountRes {
  /// @brief The number of characters of the file
  int numChars;
  /// @brief The number of words of the file
  int numWords;
  /// @brief The number of lines of the file
  int numLines;
} CountRes;

/**
 * Reproduce the result of the 'wc' command using fgets internally
 * @param file Handler for the file to process
 * @returns A struct containg all the counters
 */
CountRes fgetsCount(FILE *file);

#endif
