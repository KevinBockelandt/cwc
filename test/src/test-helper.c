#include <stdio.h>

#include "../../header/test-helper.h"
#include "../../header/counter.h"

int compareInt(int expected, int actual) {
  if (expected != actual) {
    printf("ERROR! Expected: %d, actual: %d\n", expected, actual);
    return 1;
  }
  return 0;
}

int compareCountRes(CountRes expected, CountRes actual) {
  if (compareInt(expected.numBytes, actual.numBytes)) { return 1; }
  if (compareInt(expected.numChars, actual.numChars)) { return 1; }
  if (compareInt(expected.numWords, actual.numWords)) { return 1; }
  if (compareInt(expected.numLines, actual.numLines)) { return 1; }
  return 0;
}