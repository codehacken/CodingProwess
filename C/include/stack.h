// This is a header file for the data structure - STACK.

// This is the constants file where all the constants are defined.
#include "constants.h"

// Size is initialized to the size of the stack.
// Top is initiated to -1.

struct Stack{
	int Value[MAX_ARRAY],Top,Size;
};

// List of stack functions.
int Push(struct Stack *MyStack, int Value);

int Pop(struct Stack *MyStack);

int IsFull(struct Stack *MyStack);

int IsEmpty(struct Stack *MyStack);

void PrintStack(struct Stack MyStack);

void StackMenu();

// END OF HEADER.
