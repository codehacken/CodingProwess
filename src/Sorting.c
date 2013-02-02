// This is a program to implement various sorting methods.

#include "constants.h"
#include <stdio.h>
#include <math.h>

// This function is to copy the elements from one array into another.
void CopyArray(int a[], int b[], int n){
    int i;
    for(i=0;i<n;i++){
        b[i] = a[i];
    }
}

// This is the function to print the array.
// NUM is the Iteration Number.
void PrintArray(int a[],int n,int num){
    int i;
    printf("\nIteration Number %d : ",num);
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
}

// This is a swap function.
void SwapValue(int a[], int i, int j){
    int temp;
    temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

// This function implements the standard bubble sort method.
void BubbleSort(int a[], int n){
    int i,j;
    printf("\n-----------START----------");
    PrintArray(a,n,-1);
    printf("\n-----------START----------\n");

    // Sorting section.
    for(i=0;i<n;i++){
        for(j=0;j<n-1;j++){
            if(a[j] > a[j+1])
                SwapValue(a, j, j+1);
        }
        PrintArray(a,n,i);
    }

    printf("\n-----------END----------");
    PrintArray(a,n,n-1);
    printf("\n-----------END----------\n");
}

// This function is to implement selection sort.
void SelectionSort(int a[], int n){
    int i,j;
    printf("\n-----------START----------");
    PrintArray(a,n,-1);
    printf("\n-----------START----------\n");

    // Sorting section.
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(a[i] > a[j])
                SwapValue(a, i, j);
        }
        PrintArray(a,n,i);
    }

    printf("\n-----------END----------");
    PrintArray(a,n,n-1);
    printf("\n-----------END----------\n");
}

// This is the function to merge 2 lists which are in sorted order.
void Merge(int a[], int start, int end){
    int mid = floor((start + end)/2);
    int i = start, j = mid + 1, k = 0;

    int b[MAX_ARRAY];

    while(i <= mid && j <= end){
        if(a[i] < a[j])
            b[k++] = a[i++];
        else if(a[i] > a[j])
            b[k++] = a[j++];
    }

    while(i <= mid)
        b[k++] = a[i++];

    while(j <= end)
        b[k++] = a[j++];

    // Copy the contents back to a.
    printf("\n");
    for(i=0, j=start;i<k;i++, j++){
        printf("%d ", b[i]);
        a[j] = b[i];
    }
}

// This is the merge sort function.
void MergeSort(int a[], int start, int end){
    if(end-start > 0){
        MergeSort(a, start, floor((start+end)/2));
        MergeSort(a, floor((start+end)/2) + 1, end);
        Merge(a,start,end);
    }
}

// This is the partition function.
int Partition(int a[], int start, int end){
    int pos = 0, val = a[start];
    int b[end - start], c[end - start], k=0, l=0, i=0, m=0;

    for (i=start+1;i<=end;i++){
        if(a[i] > val)
            c[k++] = a[i];
        else if(a[i] < val)
            b[l++] = a[i];
    }

    // Copy the values back to a.
    // Copy the smaller values.
    for(i=0, m=start;i<l;i++, m++)
        a[m] = b[i];

    pos = start + l;
    a[pos] = val;

    // Copy the larger values.
    for(i=0, m=pos+1;i<k;i++, m++)
        a[m] = c[i];

    // Print the values.
    printf("\n");
    for(i=start;i<=end;i++)
        printf("%d ", a[i]);

    return pos;
}

// This is a function to implement Quick sort.
void QuickSort(int a[], int start, int end){
    if(end - start > 0){
        int pos = Partition(a, start, end);
        if(start < pos)
            QuickSort(a, start, pos-1);

        if(pos < end)
            QuickSort(a, pos+1, end);
    }
}

// This function implements Introsort method.
void IntroSort(){

}

// This is the menu for sorting operations.
void SortingMenu(){
    // choice variable for the menu.
    int Choice=0;
    int a[MAX_ARRAY] = {8,4,5,6,873,23,2,1},b[MAX_ARRAY];

    // Now the Menu.
    while(Choice != 10){
        CopyArray(a,b,10);
        printf("\n---------------------------MENU--------------------------");
        printf("\n1.  Sort Array using Bubble Sort.");
        printf("\n2.  Sort Array using Selection Sort.");
        printf("\n3.  Sort Array using Merge Sort.");
        printf("\n4.  Sort Array using Quick Sort.");
        printf("\n10. Exit.");
        printf("\nEnter Your Choice: ");
        fflush(stdout);
        scanf("%d", &Choice);
        switch(Choice){

            case 1:	printf("\n-----------Bubble Sort----------");
                    BubbleSort(b,8);
                    break;

            case 2:	printf("\n-----------Selection Sort----------");
                    SelectionSort(b,8);
                    break;

            case 3:	printf("\n-----------Merge Sort----------");
                    MergeSort(b,0,7);
                    break;

            case 4:	printf("\n-----------Quick Sort----------");
                    QuickSort(b,0,7);
                    PrintArray(b,8,0);
                    break;

            case 10: break;

            default: break;
        }
    }

}

// END OF PROGRAM.
