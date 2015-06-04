#include "AList.h"
int main() {
  int initial[] = {};
  AList list(initial, sizeof(initial) / sizeof(int));

  list.insert(0, 1024);  // Insert -1 at the beginning


  return 0;
}
