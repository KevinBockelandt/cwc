#include <stdio.h>

#include "../../header/test-helper.h"
#include "../../header/counter.h"

int testFgetsCount() {
  int numErrors = 0;

  CountRes actualRet1 = fgetsCount("./test/data/basic-small-file.txt");
  CountRes expectedRet1 = { 0, 30, 5, 1 };
  numErrors += compareCountRes(expectedRet1, actualRet1);

  return numErrors;
}
