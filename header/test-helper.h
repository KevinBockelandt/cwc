#ifndef HEADER_TEST_HELPER
#define HEADER_TEST_HELPER

#include "./counter.h"

/**
 * Compare 2 ints
 * @param expected Expected value from the test
 * @param actual The actual result from the test
 * @returns 0 if the provided ints are identical. 1 otherwise
 */
int compareInt(int expected, int actual);

/**
 * Compare 2 structs holding results of a count function
 * @param expected Expected value from the test
 * @param actual The actual result from the test
 * @returns 0 if everything is identical. 1 otherwise
 */
int compareCountRes(CountRes expected, CountRes actual);

#endif
