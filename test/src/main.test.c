#include <stdio.h>
#include "../../header/main.test.h"

int main () {
  int numErrors = 0;

  printf("\nTesting\n");
  printf("--------------------------------------------------\n");
  printf("  fgets count\n");
  testFgetsCount();

  printf("\nTotal number of errors: %d\n", numErrors);

  if (numErrors == 0) {
    printf("\nBenchmarking\n");
    printf("--------------------------------------------------\n");
    printf("  TODO benchmark stuff\n");
  }

  return 0;
}