// This program is a function to generate permutations and combinations.

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "constants.h"

// This function creates all the possible permutations with the numbers in a.
void AllPermutation(int a[], int n, int depth, int b[]){
    if(depth < n){
        int i;
        for(i=0;i<n;i++){
            b[depth] = a[i];
            AllPermutation(a, n, depth+1, b);
        }
    }
    else{
        int j;
        printf("\n");
        for(j=0;j<n;j++){
            printf("%d",b[j]);
        }
    }
}

// This is a simple swap function.
void swap(int a[], int i, int j)
{
    int temp;
    temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

// This function generates distinct permutations of the numbers.
void UniquePermutation(int a[], int n, int depth, int b[], int flag[]){
    if(depth < n){
        int i;
        for(i=0;i<n;i++){
            if(flag[i] == 0){
                b[depth] = a[i];
                flag[i] = 1;
                UniquePermutation(a, n, depth+1, b, flag);
                flag[i] = 0;
            }
        }
    }
    else{
        int j;
        printf("\n");
        for(j=0;j<n;j++){
            printf("%d",b[j]);
        }
    }
}

// This function generates the combinations of all strings in the array.
// This includes upper and lower case strings.
void PermuteString(char a[], int n, int depth, char b[], int flag[]){
    if(depth < n){
        int i;
        for(i=0;i<n;i++){
            if(flag[i] == 0){
                b[depth] = a[i];
                flag[i] = 1;
                PermuteString(a, n, depth+1, b, flag);
                b[depth] = toupper(a[i]);
                PermuteString(a, n, depth+1, b, flag);
                flag[i] = 0;
            }
        }
    }
    else{
            int j;
            printf("\n");
            for(j=0;j<n;j++){
                printf("%c",b[j]);
        }
    }
}

// This is a function to remove duplicates.
int RemoveDuplicates(int a[], int n){
    int i=0,j=0;
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if((a[i] == a[j]) && (i != j)){
                printf("\n Duplicates at %d and %d", i, j);
                return 1;
            }
        }
    }

    // No duplicates found.
    printf("\n No Duplicates Found.");
    return 0;
}

// This is a function to add 2 numbers without arithmetic operators.
int BitwiseAdd(int a,int b){
    int c,d;
    do{
        c = a & b;
        c = c << 1;
        d = a ^ b;
        a = d;
        b = c;
    }while(a & b);
    return (a|b);
}

// This is a recursive function to print all the combinations of brackets.
// {{{{}}}}
void PrintBrackets(char output[], int n, int i, int j){
    if(i==n && j==n)
        printf("\n%s", output);
    else{
        if(i<n){
            char newoutput_open[20]="";
            strcat(newoutput_open, output);
            strcat(newoutput_open, "{");
            PrintBrackets(newoutput_open, n, i+1, j);
        }

        if(j<n && i > j){
            char newoutput_close[20]="";
            strcat(newoutput_close, output);
            strcat(newoutput_close, "}");
            PrintBrackets(newoutput_close, n, i, j+1);
        }
    }
}

// This is the menu for permutation operations.
void PermutationMenu(){
    // choice variable for the menu.
    int Choice=0;

    // Variables required.
    int a[6]={1,2,3,4,2,3}, b[4], flag[4]={0,0,0,0};
    char c[3] = {'a','b','c'}, d[3];

    // Now the Menu.
    while(Choice != 10){
        printf("\n---------------------------MENU--------------------------");
        printf("\n1.  Perform Unique Permutation Operation.");
        printf("\n2.  Perform All Permutation Operation.");
        printf("\n3.  Permute String.");
        printf("\n4.  Check for Duplicates in String.");
        printf("\n5.  Bitwise Addition of two numbers.");
        printf("\n6.  Print Legal combinations of {} brackets.");
        printf("\n10. Exit.");
        printf("\nEnter Your Choice: ");
        fflush(stdout);
        scanf("%d", &Choice);
        switch(Choice){

            case 1:	UniquePermutation(a,4,0,b,flag);
                    break;

            case 2: AllPermutation(a,4,0,b);
                    break;

            case 3: printf("\nGiven String: %s",c);
                    PermuteString(c,3,0,d,flag);
                    break;

            case 4: RemoveDuplicates(a,6);
                    break;

            case 5: printf("ADDING: %d and %d: %d",16,16,BitwiseAdd(16,16));
                    break;

            case 6: PrintBrackets("",5,0,0);
                    break;

            case 10: break;

            default: break;
        }
    }
}

// END OF PROGRAM.
