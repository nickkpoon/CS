#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;

#include "LinkedList2.h"

/* This reads in an input file.  The input file is expected to have the 
 * following format: On each line, there is a list of numbers.  Each number
 * will become a node in the linked list, and the list will be in the 
 * opposite order as the original list.
 * Each line can be no longer than 256 characters.
 */

LinkedList *makeList(char *str);

int main(int argc, char *argv[])
{
	FILE *file;
	LinkedList *list = NULL;
	char buffer[256];
	if (argc != 2)
	{
		printf("usage: ./a.out filename\n");
		exit(1);
	}
	if ((file = fopen(argv[1],"r")) == NULL)
	{
		printf("Could not open file %s\n",argv[1]);
		exit(1);
	}
	
	while(fgets(buffer,256,file) != NULL)
	{
		list = makeList(buffer);

		list->printList(stdout);

		// here you should test your length function
		// printf("length: %d\n",list->length());
		// here you should test your deletefourth function
		// list->deleteFourth();
		// list->printList(stdout);
		
		// note: this has a horrible memory leak because we don't
		// have a function to delete all the nodes in the list!!!
		delete list;
	}
}

LinkedList *makeList(char *str)
{
  // make the list
  LinkedList *l = new LinkedList();
  // chop up the list into numbers, make a node for each number, and put 
  // into list
  char *s = strtok(str," \t\n");
  while(s != NULL)
  {
	l->addHead(atoi(s));
	s = strtok(NULL," \t\n");
  }

  // return the list
  return l;
}
