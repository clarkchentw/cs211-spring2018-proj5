/*
	Name: Clark Chen
	NetID: schen237
	File: proj5Stack.h
	Description: Stack Class Header File
	Date: 4/5/2018
	Project #: 5
	Term: Spring 2018
*/

#include <cstdio>
#include <cstring>
#include <cctype>

// Stack that store number value(int)
class numStack
{
	private:
		int* data;	// Dynamic Array
		int allocated; // num of space allocated
		int used; // Num of space used
	public:
		numStack(); // Default constructor
		numStack(int size); // Constructor with parameter of initial size
		void allocate(int size); // initialize the stack for use
		bool isEmpty ( ); // return true if the stack has no members
		void push (int newVal); // add the data to the top of stack; grow dynamic array if needed
		int top ( ); // return the data value on the top of the stack
		void pop ( ); // remove the data value from the top of the stack
		void reset ( ); // “clear” the stack to remove any values it contains 
};

class opStack
{
	private:
		char* data; // Dynamic Array
		int allocated; // num of space allocated
		int used; // Num of space used
	public:
		opStack(); // Default constructor
		opStack(int size); // Constructor with parameter of initial size
		void allocate(int size); // initialize the stack for use
		bool isEmpty ( ); // return true if the stack has no members
		void push (int newVal); // add the data to the top of stack; grow dynamic array if needed
		char top ( ); // return the data value on the top of the stack
		void pop ( ); // remove the data value from the top of the stack
		void reset ( ); // “clear” the stack to remove any values it contains
		char getIndexOf(int index);
		bool topIsPMTD(); // Top is Plus, Monis, Time or Divide
		bool topIsTD(); // Top is Time or Divide
};

