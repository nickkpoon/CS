#include "AList.h"

int main() {
  int initial[] = {1, 2, 3, 5, 7};
  AList list(initial, sizeof(initial) / sizeof(int));
  list.output();

  list.insert(0, -1);  // Insert -1 at the beginning
  list.output();

  list.insert(3, 1024);  // Insert 1024 at position 3
  list.output();

  list.insert(2, 2048);  // Insert 2048 at position 2
  list.output();

  return 0;
}
