/* This file contains the user interface code for the Infix Evaluation Project
 *  Project 5 for CS 211 for Fall 2017
 *
 * Date: 10/21/17
 *
 * Author: Pat Troy
 *
 */
 
/*
	Name: Clark Chen
	NetID: schen237
	File: schen237Proj5.cpp
	Description: Main Source File
	Date: 4/5/2018
	Project #: 5
	Term: Spring 2018
*/

#include "proj5Tokens.h" // Token header
#include "proj5Stack.h" // Stack header

int debugMode = false; // Global Variable for Debug Mode

void printCommands(); // Print out the command available
void processExpression (Token inputToken, TokenReader *tr, numStack& numArray, opStack& opArray); // Process the expression
int mathEval(int val1, int val2, char op); // Evaluate Math Operation
void popAndEval(numStack& numArray, opStack& opArray); // pop the value/op and evaluate


int main(int argc, char *argv[])
{
	// To Detect Debug Mode
    for (int i = 0; i < argc; i++){
		if ('-' == argv[i][0] && 'd' == argv[i][1]){
			debugMode = true;
		}
    }
    
    // variable use during 
	numStack numArray;
	opStack opArray;
	Token inputToken;
	TokenReader tr;
	
	// Initial Output
	printf ("Starting Expression Evaluation Program\n\n");
	printf ("Enter Expression: ");
	
	// Getting the next Token
	inputToken = tr.getNextToken ();

	// Main program loop, loop until quit command received
	while (inputToken.equalsType(QUIT) == false)
	{
		/* check first Token on Line of input */
		if(inputToken.equalsType(HELP)) // When input help command
		{
			printCommands();
			tr.clearToEoln();
		}
		else if(inputToken.equalsType(ERROR)) // When error
		{
			printf ("Invalid Input - For a list of valid commands, type ?\n");
			tr.clearToEoln();
		}
		else if(inputToken.equalsType(EOLN)) // When nothing input
		{
			printf ("Blank Line - Do Nothing\n");
			/* blank line - do nothing */
		}
		else // Normal process
		{
			processExpression(inputToken, &tr, numArray, opArray);
		}
		
		printf ("\nEnter Expression: "); //Output to prompt for the next input
		inputToken = tr.getNextToken (); //Getting next input
	}

  printf ("Quitting Program\n");
  return 1;
}

// Display Help message
void printCommands()
{
 printf ("The commands for this program are:\n\n");
 printf ("q - to quit the program\n");
 printf ("? - to list the accepted commands\n");
 printf ("or any infix mathematical expression using operators of (), *, /, +, -\n");
}

// Process the expression
void processExpression (Token inputToken, TokenReader *tr, numStack& numArray, opStack& opArray)
{
	/* Loop until the expression reaches its End */
	while (inputToken.equalsType(EOLN) == false)
	{
		/* The expression contain a VALUE */
		if (inputToken.equalsType(VALUE))
		{
			// For debug purpose
			if (debugMode == true){
				printf ("Val: %d, ", inputToken.getValue() );
			}
			numArray.push(inputToken.getValue()); // Push the value into the stack
		}
		
		/* The expression contains an OPERATOR */
		else if (inputToken.equalsType(OPERATOR))
		{
			// For debug purpose
			if (debugMode == true){
				printf ("OP: %c, ", inputToken.getOperator() );
			}
			
			// Determine the process to evaluate the expression
			if (inputToken.getOperator() == '('){
				opArray.push(inputToken.getOperator());
			}
			if (inputToken.getOperator() == '+' || inputToken.getOperator() == '-'){
				while (!opArray.isEmpty() && opArray.topIsPMTD()){
					popAndEval(numArray, opArray);
				}
				opArray.push(inputToken.getOperator());
			}
			if (inputToken.getOperator() == '*' || inputToken.getOperator() == '/'){
				while (!opArray.isEmpty() && opArray.topIsTD()){
					popAndEval(numArray, opArray);
				}
				opArray.push(inputToken.getOperator());
			}
			if (inputToken.getOperator() == ')'){
				while (!opArray.isEmpty() && opArray.top() != '('){
					popAndEval(numArray, opArray);
				}
				if (opArray.isEmpty()){
					printf("Error: opArray is empty");
				}
				opArray.pop();
			}
		}
		
		/* get next token from input */
		inputToken = tr->getNextToken ();
	}
		
	/* The expression has reached its end */
	while (!opArray.isEmpty()){
		popAndEval(numArray, opArray);
	}
	printf("Result: %d", numArray.top()); // Display Result
	printf ("\n");
}

// Evaluate math operation, by taking 2 value and it's operation sign.
int mathEval(int val1, int val2, char op){
	if (op == '+'){
		return val1+val2;
	}
	else if (op == '-'){
		return val1-val2;
	}
	else if (op == '*'){
		return val1*val2;
	}
	else if (op == '/'){
		return val1/val2;
	}
}

// Pop the top value and evaluate the result.
void popAndEval(numStack& numArray, opStack& opArray){
	if (opArray.isEmpty()){
		printf("Error");
		return;
	}
        char Op = opArray.top();
        opArray.pop();
        int Val2 = numArray.top();
        numArray.pop();
        int Val1 = numArray.top();
        numArray.pop();
	int Val3 = mathEval(Val1, Val2, Op);
	numArray.push(Val3);
}
