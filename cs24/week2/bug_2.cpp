#include "AList.h"

int main() {
  int initial[] = {1, 2, 3, 5, 7};
  AList list(initial, sizeof(initial) / sizeof(int));

  list.insert(6, 1024);  // Insert -1 at the beginning


  return 0;
}
