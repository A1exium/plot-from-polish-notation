CC=gcc
CFLAGS=-Wall -Wextra -Werror
SOURCES=graph.c infixtopostfix.c parsing.c libstuctures.c
SDIR=source
IDIR=include
_OBJ=$(SOURCES:.c=.o)
OBJ=$(patsubst %,$(SDIR)/%,$(_OBJ)) main.o
_DEPS=graph.h infixtopostfix.h parsing.h libstuctures.h
DEPS=$(patsubst %,$(IDIR)/%,$(_DEPS))
EXACUTABLE=main
TEST_DIR=./tests/
SRC_DIR=./source/
ADD_INCLUDE=-I $(IDIR)

all: $(EXACUTABLE)

$(EXACUTABLE):$(OBJ)
	$(CC) -o $@ $(OBJ) $(CFLAGS)$(IDIR)

%.o: $(TEST_DIR)%.c
	$(CC) -c -o $@ $^ $(CFLAGS) $(ADD_INCLUDE)

%.o: $(SRC_DIR)%.c
	$(CC) -c -o $@ $^ $(CFLAGS) $(ADD_INCLUDE) 

check_all: functions.o libstructures.o parse.o str.o

test_stack: test_stack.o dbg.o libstructures.o
	$(CC) -o $@ $^

test_list: test_list.o dbg.o libstructures.o
	$(CC) -o $@ $^

test_eval: test_eval.o dbg.o functions.o libstructures.o parse.o str.o
	$(CC) -o $@ $^