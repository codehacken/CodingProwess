CC=gcc
INC=include/
CFLAGS=-Wall
LDFLAGS=
SOURCES=src/AVLTree.c src/BinarySearchTree.c src/Graph.c src/KDTree.c src/MatrixOperations.c src/Queue.c src/Stack.c src/AutoBalancedTree.c src/BinaryTree.c src/Hashmap.c src/LinkList.c src/PermComb.c src/Searching.c src/ThreadedBinaryTree.c src/BinaryOperations.c src/Btree.c src/Heap.c src/Problems.c src/Sorting.c
OBJECTS=$(SOURCES:%.c=%.o)
EXECUTABLE=intproject
OBJECT_LOC=out/
MAIN_FILE=src/Main.c

%.o : %.c ; $(CC) $(CFLAGS) -I $(INC) -c $? -o $@

install: $(OBJECTS) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) ; $(CC) $(LDFLAGS) -I $(INC) $(OBJECTS) -o $(EXECUTABLE) $(MAIN_FILE)

clean: ; rm src/*.o

