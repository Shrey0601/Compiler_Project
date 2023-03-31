CC = g++
FLAGS = -g -Wall
PARSER_NAME = parser
PARSER = $(PARSER_NAME).y
PARSER_TAB_C = $(PARSER_NAME).tab.c
PARSER_TAB_H = $(PARSER_NAME).tab.h
LEXER = lexer.l
EXEC = parser_exec.out

all:	$(EXEC)

$(PARSER_TAB_C) $(PARSER_TAB_H):	$(PARSER)
	bison -t -v -d $(PARSER)

lex.yy.c: $(LEXER)
	flex $(LEXER)

lex.o:	lex.yy.c $(PARSER_TAB_H)
	$(CC) $(FLAGS) -c lex.yy.c -o lex.o

bison.o:	$(PARSER_TAB_C)
	$(CC) $(FLAGS) -c $(PARSER_TAB_C) -o bison.o

$(EXEC): lex.o bison.o
	$(CC) $(FLAGS) lex.o bison.o -o $(EXEC)

# AST.dot: test $1
# 	./test $1 -o AST.dot

# test.png: AST.dot
# 	dot -Tpng AST.dot -o test.png

clean:
	rm *.o *.out *.output *.tab.* lex.yy.c