/*
	Name: Clark Chen
	NetID: schen237
	File: proj5Stack.cpp
	Description: Stack Class Source File
	Date: 4/5/2018
	Project #: 5
	Term: Spring 2018
*/

#include "proj5Stack.h" // Header file for Stack Class

// Default Constructor for numStack Class
numStack::numStack(){
	used = 0;
	allocate(10); // allocate 10 space as default
}

// Constructor with parameter of size for numStack Class
numStack::numStack(int size){
	used = 0;
	allocate(size);
}

// allocate additional memory space
void numStack::allocate(int size){
	if (data == NULL){
		data = new int[size];
		allocated = size;
	}
	else{
		int* temp = new int[size+allocated];
		for (int i = 0; i < used; i++){
			temp[i] = data[i];
		}
		delete [] data;
		data = temp;
		allocated += size;
	}
}

// Check if is empty
bool numStack::isEmpty(){
	if (used == 0){
		return true;
	}
	else{
		return false;
	}
}

// Push a value into the stack
void numStack::push(int newVal){
	if (used <= allocated){
		allocate(10);
	}
	data[used] = newVal;
	used++;
}

// Get the top value in Stack
int numStack::top(){
	if (used <= 0){
		return 0;
	}
	return data[used-1];
}

// Pop the top value in stack
void numStack::pop(){
	used--;
}

// Reset Stack, by reset the used count and wipe all the data
void numStack::reset(){
	for (int i = 0; i < allocated; i++){
		data[i] = 0;
	}
	used = 0;
}


// Default Constructor for opStack Class
opStack::opStack(){
	used = 0;
        allocate(10);
}

// Constructor with parameter of size for opStack Class
opStack::opStack(int size){
	used = 0;
	allocate(size);
}

// allocate additional memory space
void opStack::allocate(int size){
        if (data == NULL){
                data = new char[size];
		allocated = size;
        }
        else{
                char* temp = new char[size+allocated];
                for (int i = 0; i < used; i++){
                        temp[i] = data[i];
                }
                delete [] data;
                data = temp;
                allocated += size;
        }
}

// Check if is empty
bool opStack::isEmpty(){
        if (used == 0){
                return true;
        }
        else{
                return false;
        }
}

// Push a value into the stack
void opStack::push(int newVal){
	if (used <= allocated){
		allocate(10);
	}
        data[used] = newVal;
        used++;
}

// Get the top value in Stack
char opStack::top(){
	if (used <= 0){
		return 0;
	}
        return data[used-1];
}

// Pop the top value in stack
void opStack::pop(){
        used--;
}

// Reset Stack, by reset the used count and wipe all the data
void opStack::reset(){
	for (int i = 0; i < allocated; i++){
		data[i] = 0;
	}
        used = 0;
}

// Check if is Plus, Minus, Time, or Divide
bool opStack::topIsPMTD(){
	if (top() == '+' || top() == '-' || top() == '*' || top() == '/')
	{
		return true;
	}
	return false;
}

// Check if is Time, or Divide
bool opStack::topIsTD(){
        if (top() == '*' || top() == '/')
        {
                return true;
        }
        return false;
}


