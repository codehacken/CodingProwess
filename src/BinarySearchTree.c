/* This is the program to implement a binary search tree and related functions. */

#include "binarytree.h"
#include <stdio.h>
#include <stdlib.h>

/* This is a function to initialize a tree. */
int InitializeTree(struct BinarySearchTree *MyTree){
    MyTree->root = NULL;
    MyTree->no = 0;

    return 0;
}

/* This function will create the tree from an array. */
int CreateTree(struct BinarySearchTree *MyTree, int a[], int n){
    int i=0;
    for(i=0;i<n;i++){
        MyTree->root = AddNode(MyTree->root, a[i]);
    }

    /* Update the number of nodes in the tree. */
    MyTree->no = n;

    return 0;
}

/* This is to add a node to the binary search tree. */
struct BinarySearchTreeNode * AddNode(struct BinarySearchTreeNode *Curr, int value){
    /* This condition is only for the root. */
    if(Curr == NULL){
        Curr = (struct BinarySearchTreeNode *)malloc(sizeof(struct BinarySearchTreeNode));
        Curr->value = value;
        Curr->left = NULL;
        Curr->right = NULL;
    }
    else if(value > Curr->value)
        /* Add a new node to the right. */
        Curr->right = AddNode(Curr->right,value);
    else if(value < Curr->value)
        /* Add a new node to the left. */
        Curr->left = AddNode(Curr->left,value);

    return Curr;
}

/* This function print the binary tree in inorder. */
void PrintInOrder(struct BinarySearchTreeNode *Curr){
    if(Curr == NULL)
        return;
    else{
        PrintInOrder(Curr->left);
        printf("%d ",Curr->value);
        PrintInOrder(Curr->right);
    }
}

// This function print the binary tree in preorder.
void PrintPreOrder(struct BinarySearchTreeNode *Curr){
    if(Curr == NULL)
        return;
    else{
        printf("%d ",Curr->value);
        PrintPreOrder(Curr->left);
        PrintPreOrder(Curr->right);
    }
}

/* This function print the binary tree in postorder. */
void PrintPostOrder(struct BinarySearchTreeNode *Curr){
    if(Curr == NULL)
        return;
    else{
        PrintPostOrder(Curr->left);
        PrintPostOrder(Curr->right);
        printf("%d ",Curr->value);
    }
}

/* This function to check if a tree is balanced. */
int IfBalanced(struct BinarySearchTreeNode *Curr){
    if(Curr == NULL)
        return 0;
    else
    {
        int lh, rh;
        lh = IfBalanced(Curr->left);
        if(lh == -1)
            return -1;

        rh = IfBalanced(Curr->right);
        if(rh == -1)
            return -1;

        if(abs(lh - rh) > 1)
            return -1;

        if(lh >= rh)
            return lh + 1;
        else
            return rh + 1;
    }
}

/* This Function is to print between 2 numbers. */
void PrintRange(struct BinarySearchTreeNode *Curr, int Start, int End){
    if(Curr == NULL)
        return;
    else{
        if((Curr->value >= Start) && (Curr->value <= End)){
            PrintRange(Curr->left,Start,End);
            printf("%d ",Curr->value);
            PrintRange(Curr->right,Start,End);
        }
    }
}

/* END OF PROGRAM. */

