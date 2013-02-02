// This is a program to implement a stack.

#include <stdio.h>
#include<stdlib.h>
#include "stack.h"

// This function pushes a value into the stack.
// Return value of 0 means the value was successfully inserted into the stack.
// Return value of -1 means the stack is full.
int Push(struct Stack *MyStack, int Value){
    if(MyStack->Top < (MyStack->Size - 1)){
        MyStack->Value[++MyStack->Top] = Value;
        return 0;
    }
    else
        return ERROR_VAL;
}

// This function pops a value from the top of the stack.
// Return value of -1 means the stack is empty.
// Return value of anything apart from -1 means the value has been properly popped from the stack.
int Pop(struct Stack *MyStack){
    if(MyStack->Top > -1)
        return(MyStack->Value[MyStack->Top--]);
    else
        return ERROR_VAL;
}

// This function checks if the stack is full.
int IsFull(struct Stack *MyStack){
    if(MyStack->Top < (MyStack->Size - 1))
        return 0;
    else
        return -1;
}

// This function checks if the stack is empty.
int IsEmpty(struct Stack *MyStack){
    if(MyStack->Top > -1)
        return 0;
    else
        return -1;
}

// This function is check the value in the top of the stack.
int Peek(struct Stack *MyStack){
    return (MyStack->Value[MyStack->Top]);
}

// This function is to initialize the stack.
void InitializeStack(struct Stack *MyStack, int n){
    MyStack->Size = n;
    MyStack->Top = -1;
}

// This function is to sort the values in a stack.
// It uses only stack functions.

int StackSort(struct Stack *MyStack){
    struct Stack *OtherStack = (struct Stack*) malloc(sizeof(struct Stack));

    // If the stack is not empty, there are values in the stack.
    int temp1;

    // Initialize Stack.
    InitializeStack(OtherStack, 10);

    while(IsEmpty(MyStack) == 0){
        temp1 = Pop(MyStack);

        // Push all the values that are greater than temp1 in the main stack and the
        // values which are smaller in the other stack.
        while(IsEmpty(OtherStack) == 0 && (Peek(OtherStack) > temp1)){
            Push(MyStack, Pop(OtherStack));
        }

        // Now push the current value in the other stack.
        Push(OtherStack, temp1);
    }
    while(IsEmpty(OtherStack) == 0){
        Push(MyStack, Pop(OtherStack));
    }

    free(OtherStack);

    return 0;
}

// This function is to print the values in the stack in the order in which they are popped.
void PrintStack(struct Stack MyStack){
    int i=0;
    for(i=MyStack.Top;i> -1;i--){
        printf("%d ",MyStack.Value[i]);
    }
}

// This is the menu for stack operations.
void StackMenu(){
    // choice variable for the menu.
    int Choice=0, Value;
    struct Stack MyStack;

    // Initialize the stack.
    InitializeStack(&MyStack, 10);

    // Now the Menu.
    while(Choice != 10){
        printf("\n---------------------------MENU--------------------------");
        printf("\n1.  Insert Value into the Stack.");
        printf("\n2.  Delete Value from the Stack.");
        printf("\n3.  Check if Stack is Full.");
        printf("\n4.  Check if Stack is Empty.");
        printf("\n5.  Print the Stack.");
        printf("\n6.  Sort Stack.");
        printf("\n10. Exit.");
        printf("\nEnter Your Choice: ");
        fflush(stdout);
        scanf("%d", &Choice);
        switch(Choice){

            case 1:	printf("\nEnter the Value: ");
                    fflush(stdout);
                    scanf("%d",&Value);
                    Push(&MyStack, Value);
                    break;

            case 2: Value = Pop(&MyStack);
                    printf("\nPop Value: %d",Value);
                    break;

            case 3: Value = IsFull(&MyStack);
                    if(Value == -1)
                        printf("\nStack is Full!!!");
                    else
                        printf("\nStack is not Full!!!");
                    break;

            case 4: Value = IsEmpty(&MyStack);
                    if(Value == -1)
                        printf("\nStack is Empty!!!");
                    else
                        printf("\nStack is not Empty!!!");
                    break;

            case 5: PrintStack(MyStack);
                    break;

            case 6: StackSort(&MyStack);
                    break;

            case 10: break;

            default: break;
        }
    }

}

// END OF PROGRAM.

