#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;

#include "LinkedList.h"

/* This reads in an input file.  The input file is expected to have the 
 * following format: On each line, there is a list of numbers.  Each number
 * will become a node in the linked list, and the list will be in the 
 * opposite order as the original list.
 * Each line can be no longer than 256 characters.
 */


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
		// make the list
		list = new LinkedList();
     		// chop up the list into numbers, make a node for each number, and put 
	       	// into list
         	char *s = strtok(buffer," \t\n\r");
           	while(s != NULL)
             	{
                    	list->addHead(atoi(s));
                        s = strtok(NULL," \t\n\r");
                }
		list->printList(stdout);
		// Note: This is a horrible memory leak.
		// deleting the list doesn't delete the nodes in the list.
		// We'll do that next week.
		delete list;
	}
}

