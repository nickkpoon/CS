#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// forward declarations
void printarray(int *array, int length);
int findmaxindex(int *array, int length);
int findsecondlargest(int *array, int length);
int findcharindex(char *array, char c);

int main(int argc, char **argv)
{


	char *sa[] = {"Hello, how are you?","I.m just fine, thank you.", 
		"Monkeys are awesome.", 
		"I complete agree, though I also really like platypi."};
	int i = 4;
	int size;
	FILE *file;
	char buf[256];
	char buf2[5];
	int arr[20];
	char *p;

	printf("Enter a test array of no more than 20 numbers.\n");
	printf("Enter all numbers on the same line, separated by a space.\n");
	printf("Do not enter more than 256 characters total.\n");
	printf("If you want to quit this portion of testing, press return\n");
	printf("with nothing on the line\n");
	fgets(buf,256,stdin);
	while (buf[0] != '\n')
	{
		p = strtok(buf," \n");
		i = 0;
		for(i=0;i<20 && (p!=NULL);i++)
		{
			arr[i] = atoi(p);
			p = strtok(NULL," \n");
		}

		printf("array entered: ");
		printarray(arr,i);

		printf("maxindex is %d\n",findmaxindex(arr,i));
		printf("secondlargest is %d\n",findsecondlargest(arr,i));

		printf("Enter new array.  Enter blank line to exit\n");
		fgets(buf,256,stdin);
	}

	printf("Enter a test string.\n");
	printf("To quit, make the first letter 'Q'\n");
	fgets(buf,256,stdin);
	while(buf[0] != 'Q')
	{
		char *str;
		printf("String: %s",buf);
		printf("Enter a character to find.\n");
		fgets(buf2,5,stdin);
		printf("Find %c\n",buf2[0]);

		printf("The index of %c in %s is %d\n",
			buf2[0],buf,findcharindex(buf,buf2[0]));


		printf("Enter a test string.\n");
		printf("To quit, make the first letter 'Q'\n");
		fgets(buf,256,stdin);
	}
}
/* printarray
 *
 * Inputs: int *array - integer array
 * 	   int length - the number of ints in the integer array
 *
 * 	   This prints out all items in the array, separated by a space.
 * 	   It prints a '\n' at the end.
 */
void printarray(int *array, int length)
{
	int i;
	for(i=0;i<length;i++)
		printf("%d ",array[i]);
	printf("\n");
}

/********* DO NOT CHANGE ANY CODE ABOVE THIS LINE *************/

/* findmaxindex
 *
 * Inputs:  int *array - integer array
 * 	    int length - the number of ints in the integer array
 *
 * Return value: the index of the largest item in the array.
 * If the length is less than 1, return -1.
 *
 * Note:  You may not call ANY functions from this code.
 */
int findmaxindex(int *array, int length)
{  
	int i, x = 0;
	int max = array[x];
	
	if (length < 1)
		return -1;
		
	for (i = 0; i < length; i++)
	{
		if (array[i] > max)
		{
			max = array[i];
			x = i;
		}
	}
	
	return x;
	
	
	
}
/* findsecondlargest
 *
 * Inputs:  int *array - integer array
 * 	    int length - the number of ints in the integer array
 *
 * Return value: the value of the second largest item in the array.
 * If there are two items of the maximum value, it returns that max value.
 * If the length is less than 2, return -1.
 *
 * Note:  You may not call ANY functions from this code.
 */
int findsecondlargest(int *array, int length)
{
	int i, max, second_max;
	
	if (length < 2)
		return -1;;
		
	if (array[0] > array[1])
	{
		second_max = array[1];
		max = array[0];
	}
	else
	{
		second_max = array[0];
		max = array[1];
	}
	
	for (i = 2; i < length; i++)
	{
		if (array[i] >= max)
		{
			second_max=max;
			max=array[i];
		}
		else if(array[i] > second_max)
		{
			second_max=array[i];
		}
	}
	
	return second_max;

}


/* findcharindex
 *
 * Inputs:  char *array - character array, or string
 * 	    char c - character to find within the string
 *
 * Return value: the index of the character c in the string.
 * If the character is not in the string, return -1.
 *
 * Note:  You may not call ANY functions from this code.
*/
int findcharindex(char *array, char c)
{
	int index = 0;
	while(array[index] != '\0')
	{
		if (array[index] == c)
			return index;
			
		index++;
	}
	
	return -1;
}

	/*int i, index = -1, size = sizeof(array)/sizeof(char);
	
	for (i = 0; i < size; i++)
	{
		if ((char)array[i] == c)
			index = i;
	}
	
	return index;*/


