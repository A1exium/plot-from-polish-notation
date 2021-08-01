CC=gcc
CFLAGS=-Wall -Wextra -Werror
SOURCES=graph.c parse.c libstructures.c functions.c input.c str.c #infixtoprefix.c
SDIR=source
IDIR=include
_OBJ=$(SOURCES:.c=.o)
OBJ=$(patsubst %,$(SDIR)/%,$(_OBJ)) main.o
_DEPS=graph.h parse.h libstructures.h functions.h input.h str.h #infixtoprefix.h
DEPS=$(patsubst %,$(IDIR)/%,$(_DEPS))
EXACUTABLE=main
ADD_INCLUDE=-I $(IDIR)

.PHONY: all

all:$(EXACUTABLE)

$(EXACUTABLE):$(OBJ) $(DEPS)
	@$(CC) -o $@ $(OBJ) $(CFLAGS)$(IDIR)
	@make clean

%.o: $(SDIR)/%.c
	@$(CC) -c -o $@ $^ $(CFLAGS) $(ADD_INCLUDE) 

.PHONY: clean

clean:
	@rm *.o; cd source; rm *.o