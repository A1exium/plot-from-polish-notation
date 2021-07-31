CC=gcc
CFLAGS=-Wall -Wextra -Werror -I
SOURCES=graph.c infixtopostfix.c parsing.c libstuctures.c
SDIR=source
IDIR=include
_OBJ=$(SOURCES:.c=.o)
OBJ=$(patsubst %,$(SDIR)/%,$(_OBJ)) main.o
_DEPS=graph.h infixtopostfix.h parsing.h libstuctures.h
DEPS=$(patsubst %,$(IDIR)/%,$(_DEPS))
EXACUTABLE=main


all: $(EXACUTABLE)

$(EXACUTABLE):$(OBJ)
	$(CC) -o $@ $(OBJ) $(CFLAGS)$(IDIR)
%.o:%.c
	$(CC) -c -o $@ $<
