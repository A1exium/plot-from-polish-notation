CC=gcc
CFLAGS=-Wall -Wextra -Werror
IDIR=include
EXECUTABLE=main
TEST_DIR=./tests/
SRC_DIR=./source/
ADD_INCLUDE=-I $(IDIR)
SRC_FILES=$(patsubst $(SRC_DIR)%.c,%.o,$(wildcard $(SRC_DIR)*.c))

all: $(EXECUTABLE)

$(EXECUTABLE):$(SRC_FILES) main.o
	$(CC) -o $@ $^ $(CFLAGS) $(ADD_INCLUDE)

%.o: $(TEST_DIR)%.c
	$(CC) -c -o $@ $^ $(CFLAGS) $(ADD_INCLUDE)

%.o: $(SRC_DIR)%.c
	$(CC) -c -o $@ $^ $(CFLAGS) $(ADD_INCLUDE) 

check_all: $(SRC_FILES)

test_stack: test_stack.o dbg.o libstructures.o
	$(CC) -o $@ $^

test_list: test_list.o dbg.o libstructures.o
	$(CC) -o $@ $^

test_eval: test_eval.o dbg.o functions.o libstructures.o parse.o str.o
	$(CC) -o $@ $^

test_ITP: libstructures.o str.o dbg.o test_infixtoprefix.o misc.o infixtoprefix.o
	$(CC) -o $@ $^

clean:
	rm *.o