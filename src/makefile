CC=gcc
CFLAGS=-Wall -Wextra -Werror
SOURCES=
SDIR=source
IDIR=include
EXACUTABLE=main
ADD_INCLUDE=-I $(IDIR)
SRC_DIR=./source/
SRC_FILES=$(patsubst $(SRC_DIR)%.c,%.o,$(wildcard $(SRC_DIR)*.c))

.PHONY: all clean

all:$(EXACUTABLE)

$(EXACUTABLE): $(SRC_FILES) main.o
	$(CC) -o ../build/graph $^ $(CFLAGS) $(ADD_INCLUDE) -O3

main.o: main.c
	$(CC) -c -o $@ $^ $(CFLAGS) $(ADD_INCLUDE)

%.o: $(SDIR)/%.c
	$(CC) -c -o $@ $^ $(CFLAGS) $(ADD_INCLUDE)

clean:
	rm *.o
	rm ../build/*