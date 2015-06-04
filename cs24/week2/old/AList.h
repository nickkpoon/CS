#ifndef ALIST_H
#define ALIST_H

class AList {
 private:
  int allocated;
  int *items;
  int size;

 public:
  ~AList();

  /* Default constructor that pre-allocates space for 4 items. */
  AList();

  /* Constructor that initializes the array with the passed in `initial` array.

     :param initial: An array of values to initialize the list with.
     :param size: The size of the `initial` array.

     Note: If size is not a power of two, the end of the List will be padded
     such that the total allocation amount is a power of two.
  */
  AList(int *initial, int size);

  /* Return the number of elements stored in the list. */
  int get_size() const;

  /* Insert an item with value `value` at `position` in the list.

     Position 0 inserts at the beginning of the list, and position SIZE means
     insert at the end of the list, where SIZE corresponds to the number of
     elements already in the list.
  */
  void insert(int position, int value);

  /* Output the contents of the list to standard out. */
  void output() const;
};

#endif /* ALIST_H */
