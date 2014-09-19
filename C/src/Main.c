// This is main program which gets executed and calls other functions.

#include <stdio.h>
#include "PermComb.h"
#include "stack.h"
#include "Sorting.h"
#include "linklist.h"
#include "binarytree.h"

int main(){

    // choice variable for the menu.
    int choice=0;

    while(choice != 10){
        printf("\n---------------------------MENU--------------------------");
        printf("\n1.  Perform Permutation Operations.");
        printf("\n2.  Perform Stack Operations.");
        printf("\n3.  Perform Sorting Operations.");
        printf("\n4.  Perform Link List Operations.");
        printf("\n5.  Perform Binary Search Tree Operations.");
        printf("\n10. Exit.");
        printf("\nEnter Your Choice: ");
        fflush(stdout);
        scanf("%d", &choice);
        switch(choice){
            case 1:	PermutationMenu();
                    break;

            case 2: StackMenu();
                    break;

            case 3: SortingMenu();
                    break;

            case 4: LinkListMenu();
                    break;

            case 5: BinarySearchTreeMenu();
                    break;

            case 10: break;

            default: break;
        }
    }
    return 0;
}

// END OF PROGRAM.
