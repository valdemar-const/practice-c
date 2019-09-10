P=test_list
OBJECTS=linked_list.c test_list.c
CFLAGS=-g3 -Wall
LDLIBS=

CPPCFLAGS=-q --enable=all --suppress=missingIncludeSystem .

$(P): $(OBJECTS)

test: $(P)
	valgrind --leak-check=full ./$(P)

debug: $(P)
	cgdb ./$(P)

check: $(OBJECTS)
	cppcheck $(CPPCFLAGS)