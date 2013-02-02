CC=gcc
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=src/Main.c src/AVLTree.c src/BinarySearchTree.c src/Graph.c src/KDTree.c src/MatrixOperations.c src/Queue.c src/Stack.c src/AutoBalancedTree.c src/BinaryTree.c src/Hashmap.c src/LinkList.c src/PermComb.c src/Searching.c src/ThreadedBinaryTree.c src/BinaryOperations.c src/Btree.c src/Heap.c src/Main.c src/Problems.c src/Sorting.c
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=intproject
INCLUDE=include/

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) ; $(CC) $(LDFLAGS) -I $(INCLUDE) $(OBJECTS) -o $@

.cpp.o: ; $(CC) $(CFLAGS) -I $(INCLUDE) $< -c $@

clean: ; rm src/*.o
