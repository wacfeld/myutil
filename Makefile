CC = gcc
CFLAGS = -g -MMD -Wall -L~/con/libs -I ~/con/libs
EXEC = $(shell basename $(CURDIR)).a
OBJECTS = queue.o
DEPENDS = ${OBJECTS:.o=.d}
${EXEC}: ${OBJECTS}
	ar rcs ${EXEC} ${OBJECTS}
-include ${DEPENDS}
.PHONY: clean
clean:
	rm ${OBJECTS} ${DEPENDS} ${EXEC}

