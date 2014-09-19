/*
 * linklist.h
 *
 */

// Create the structure for the Link list Node.
struct LinkListNode{
	int num;
	struct LinkListNode *nextptr;
};

// Create the Link list structure.
struct LinkList{
	struct LinkListNode *head;
	int no;
};

typedef struct LinkListNode lnode;

// List of functions.
int CreateLinkList(int a[], int n, struct LinkList *MyList);

// Other Functions.
int PrintLinkList(struct LinkList *MyList);
void LinkListMenu();
// End of Header.
