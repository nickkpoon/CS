#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctype.h>
#include "TwentyQuestionsTree.h"

using namespace std;

int main(int argc, char *argv[])
{
  TwentyQuestionsTree *tree;
  FILE *fp;

  bool filenameGiven = false;
  // TODO:
  // if there was a command-line argument,
  if (argc > 1)
  {
	filenameGiven = true;  	
	// open the file (the command-line argument)
  	fp = fopen(argv[1], "r");
  	// pass that file pointer to the constructor, which will 
  	// read the file and populate the tree
	tree = new TwentyQuestionsTree(fp);
  }
  else
  	// otherwise, use default constructor
  	tree = new TwentyQuestionsTree();

  int play;
  do{
    char buf[256];
    // start the game
    tree->reset();
    const char *question = tree->currentQuestion();
    const char *lastquestion;
    int answer = 0;
    // Here, we use the iterator to go through the 
    // tree.  Each time, we ask the question in the node.
    // The answer advances the iterator down either the 
    // left subtree or the right subtree.  Then we ask
    // the next question.  The leaf is always a guess.
    // Once there are no questions left, we are done.
    while(question != NULL)
      {
        // ask the question
        printf("%s (yes=1, no=0): ", question);
        // read the response
        fgets(buf, 256, stdin);
        answer = atoi(buf);
        if (answer == 0)
          printf("No\n");
        else
          printf("Yes\n");
        tree->recordAnswer(answer);
        lastquestion = question;
        question = tree->currentQuestion();
      }
    // check to see if computer was correct
    if (answer == 1)
      printf("Yippee!  I got it right!\n");
    else
      {
	// if the computer was wrong, then we need to find out
	// what the proper guess was.
        printf("What should I have guessed?\n");
        printf("(i.e. Is it a platypus?)?  ");
        char *o;
        char realanswer[300], otherquestion[256];
        fgets(realanswer, 256, stdin);
        // strip last \n
        strtok(realanswer, "\n");
        printf("Real answer: %s\n", realanswer);
	// now we need a question to distinguish the real answer
	// from what the computer guessed.
        printf("What question would have distinguished this from %s\n",
               lastquestion);
        fgets(otherquestion, 256, stdin);
        // strip last \n, leading spaces
        strtok(otherquestion, "\n");
        printf("Other question: %s\n", otherquestion);
	// now figure out which guess is the left child and which is 
	// the right child.
        do{
          printf("Would the answer to that question have been yes or no (yes=1,\
no=0)? ");
          o = fgets(buf, 256, stdin);
          answer = atoi(o);
        } while(!isdigit(*o));
	// Now we have everything we need - the old guess (which is the parent),
	// the new guess, and the question to distinguish them.
	// This modifies the tree with the new info.
        if (answer == 0)
          tree->modifyAndInsert(strdup(otherquestion), strdup(realanswer),
                                lastquestion);
        else
          tree->modifyAndInsert(strdup(otherquestion), lastquestion,
                                strdup(realanswer));
      }

    printf("Would you like to play again (yes=1,no=0)?");
    fgets(buf, 256, stdin);
    play = atoi(buf);
  }while(play == 1);
  // TODO
  // if a filename was given, reopen the file for writing and
  // write out the current state of the tree
	if (filenameGiven)
	{		
		fp = fopen(argv[1], "w");
		tree->storeTree(fp);
	}

}
