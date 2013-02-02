// This is a program to implement a Linklist and linklist traversal methods.
// To be implemented with dynamic allocation of memory.

// By Design the Head node is dummy node to show the start the list.
// It does not contain any value.

#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"

// List of functions.
int CreateLinkList(int a[], int n, struct LinkList *MyList){
    int i=0;
    struct LinkListNode *Curr,*New;
    // Initialize List.
    // First allocate space to the head node.
    MyList->head = (struct LinkListNode*) malloc(sizeof(struct LinkListNode));
    // Assign a default value to the head node.
    MyList->head->num = -1;
    MyList->head->nextptr = NULL;

    printf("%d", MyList->head->num);

    // Assign the values in the array to the list.
    Curr = MyList->head;
    for(i=0;i<n;i++){
        // Create a new Node.
        New = (struct LinkListNode *)malloc(sizeof(struct LinkListNode));
        New->num = a[i];
        New->nextptr = NULL;

        // Add the Node to the list.
        Curr->nextptr = New;
        Curr = New;
    }

    // The number of nodes in the List.
    MyList->no = n;

    return 0;
}

// Print the List Values.
int PrintLinkList(struct LinkList *MyList){
    if(MyList->head->nextptr == NULL){
        return 1;
    }

    struct LinkListNode *Curr = MyList->head->nextptr;

    // Loop till the next pointer is NULL, the end of the Link List.
    while(Curr!=NULL){
        printf("%d ", Curr->num);
        Curr = Curr->nextptr;
    }

    return 0;
}

// This is a function to reverse the Link List.
int LinkListReverse(struct LinkList *MyList){
    if(MyList->head->nextptr == NULL)
        return 0;

    struct LinkListNode *First = MyList->head->nextptr;
    struct LinkListNode *Next = MyList->head->nextptr->nextptr;
    struct LinkListNode *Curr = MyList->head->nextptr;
    struct LinkListNode *temp;

    while(Next != NULL){
        temp = Next->nextptr;
        Next->nextptr = Curr;
        Curr = Next;
        Next = temp;
    }

    // Link the Head node to the first element.
    MyList->head->nextptr = Curr;
    First->nextptr = NULL;

    // Return 0.
    return 0;
}

// This is the menu for Link List operations.
void LinkListMenu(){
    // choice variable for the menu.
    int Choice=0;

    struct LinkList MyList;

    // Variables required.
    int a[15] = {4,3,2,7,8,9,1,2,33,23,4,54,32,21};

    CreateLinkList(a,14,&MyList);

    // Now the Menu.
    while(Choice != 10){
        printf("\n---------------------------MENU--------------------------");
        printf("\n1.  Print the Link List.");
        printf("\n2.  Reverse the Link List.");
        printf("\n10. Exit.");
        printf("\nEnter Your Choice: ");
        fflush(stdout);
        scanf("%d", &Choice);
        switch(Choice){

            case 1: PrintLinkList(&MyList);
                    break;

            case 2: LinkListReverse(&MyList);
                    break;

            case 10: break;

            default: break;
        }
    }
}

// End of Program.

