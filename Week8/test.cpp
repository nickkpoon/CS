#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctype.h>
#include <fstream>
#include <limits.h>

int main()
{
	FILE *fp;
	fp = fopen("gameinfo.txt", "r");
	//char question1[1000];
	//char question2[1000];

	int i = 0;	
	char ch, buffer, line[256];
	//std::ifstream infile("gameinfo.txt");
	//string blah;
	//get root question
	fgets(line, INT_MAX ,fp); 
	char *ch1 = new char[100];
	char *ch2 = new char[100];
	char *ch3 = new char[100];
	char *c1 = new char[100];
	char *c2 = new char[100];
	char *c3 = new char[100];
	ch1 = strtok(line, ",");
	strcpy(c1, ch1);
	printf("%s\n", c1);
	
	ch2 = strtok(NULL, ",");
	strcpy(c2, ch2);
	printf("%s\n", c2);
	
	ch3 = strtok(NULL, "\n");
	strcpy(c3, ch3);
	printf("%s\n", c3);
	
	while(fgets(line, 256 ,fp)!=NULL)
	{

		char *ch1 = new char[100];
		char *ch2 = new char[100];
		char *ch3 = new char[100];
		char *c1 = new char[100];
		char *c2 = new char[100];
		char *c3 = new char[100];
		ch1 = strtok(line, ",");
		strcpy(c1, ch1);
		if (c1 == '\0')
			break;
		printf("%s\n", c1);
		
		ch2 = strtok(NULL, ",");
		strcpy(c2, ch2);
		printf("%s\n", c2);

		ch3 = strtok(NULL, "\n");
		strcpy(c3, ch3);
		printf("%s\n", c3);
	}
	//root->question = rootquestion;

	//get next 2 questions on that line


/*
	char* question2 = strtok(NULL, ","); //strtok uses in stream from what was left after last delimiter
	char* question3 = strtok(NULL, "\n");

	printf("%s%s%s", question1, question2, question3); //debug
*/

	//do insert here	

	/*while(fgets(line,INT_MAX,fp) != NULL ) 
    {
	char *ch = new char[100];
	char *p;
	ch = strtok( line, ",");
	p = strdup(ch);
	printf("%s\n", *p);
	ch = strtok( NULL, ",");
	
	strcpy(question[i++], ch);
	ch = strtok( NULL, "\n");
	strcpy(question[i++], ch);
    }
	for(int x = 0; x<i; x++)
	printf("%i: %s\n",x, question[x]);
*/
	return 0;

}
