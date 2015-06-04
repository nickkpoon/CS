#include "AList.h"
int main() {
  int initial[] = {1,2};
  AList list(initial, sizeof(initial) / sizeof(int));

	
  //list.insert(1, 1024);  // Insert -1 at the beginning
  //list.output();	

  return list.get_size();
}
