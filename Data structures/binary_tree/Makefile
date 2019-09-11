P=test_tree
OBJECTS=binary_tree.c test_binary_tree.c
CFLAGS=-g3 -Wall
LDLIBS=

CPPCFLAGS=-q --enable=all --suppress=missingIncludeSystem .

$(P): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(P)

test: $(P)
	valgrind --leak-check=full ./$(P)

debug: $(P)
	cgdb ./$(P)

check: $(OBJECTS)
	cppcheck $(CPPCFLAGS)