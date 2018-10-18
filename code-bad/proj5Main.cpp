/* This file contains the user interface code for the Infix Evaluation Project
 *  Project 5 for CS 211 for Fall 2017
 *
 * Date: 10/21/17
 *
 * Author: Pat Troy
 *
 */

#include "proj5Tokens.h"

void printCommands();

void processExpression (Token inputToken, TokenReader *tr);

void init(Token* tokenPtr); // initialize the stack for use THIS MAY BE A CONSTRUCTOR
int isEmpty (Token* tokenPtr); // return true if the stack has no members
void push (Token* tokenPtr); // add the data to the top of stack; grow dynamic array if needed
Token top ( ); // return the data value on the top of the stack
void pop ( ); // remove the data value from the top of the stack
void reset ( ); // “clear” the stack to remove any values it contains 

int main(int argc, char *argv[])
{
    /***************************************************************/
    /* Add code for checking command line arguments for debug mode */
	Token* opStack;
	Token* valStack;
	init(opStack);
	init(valStack);
	if (isEmpty(opStack)){
		printf("OK");
	}
	else{
		printf( "123");
	}

    Token inputToken;
    TokenReader tr;

    printf ("Starting Expression Evaluation Program\n\n");
    printf ("Enter Expression: ");


    inputToken = tr.getNextToken ();

    while (inputToken.equalsType(QUIT) == false)
    {
      /* check first Token on Line of input */
      if(inputToken.equalsType(HELP))
      {
       printCommands();
       tr.clearToEoln();
      }
      else if(inputToken.equalsType(ERROR))
      {
       printf ("Invalid Input - For a list of valid commands, type ?\n");
       tr.clearToEoln();
      }
      else if(inputToken.equalsType(EOLN))
      {
       printf ("Blank Line - Do Nothing\n");
       /* blank line - do nothing */
      }
      else
      {
       processExpression(inputToken, &tr);
      }

      printf ("\nEnter Expression: ");
      inputToken = tr.getNextToken ();
    }

  printf ("Quitting Program\n");
  return 1;
}

void printCommands()
{
 printf ("The commands for this program are:\n\n");
 printf ("q - to quit the program\n");
 printf ("? - to list the accepted commands\n");
 printf ("or any infix mathematical expression using operators of (), *, /, +, -\n");
}

void processExpression (Token inputToken, TokenReader *tr)
{
 /**********************************************/
 /* Declare both stack head pointers here      */

 /* Loop until the expression reaches its End */
 while (inputToken.equalsType(EOLN) == false)
   {
    /* The expression contain a VALUE */
    if (inputToken.equalsType(VALUE))
      {
       /* make this a debugMode statement */
       printf ("Val: %d, ", inputToken.getValue() );

       // add code to perform this operation here

      }

    /* The expression contains an OPERATOR */
    else if (inputToken.equalsType(OPERATOR))
      {
       /* make this a debugMode statement */
       printf ("OP: %c, ", inputToken.getOperator() );

       // add code to perform this operation here

      }

    /* get next token from input */
    inputToken = tr->getNextToken ();
   }

 /* The expression has reached its end */

 // add code to perform this operation here

 printf ("\n");
}

void init(Token* tokenPtr){
	tokenPtr = new Token();
}

int isEmpty(Token* tokenPtr){
	if (tokenPtr == NULL){
		return 1;
	}
	return 0;
}
