#include "AList.h"

int main() {
  int initial[] = {1, 2, 3, 5, 7};
  AList list(initial, sizeof(initial) / sizeof(int));

  list.insert(5, 1024);  // Insert 1024 at position 3


  return 0;
}
