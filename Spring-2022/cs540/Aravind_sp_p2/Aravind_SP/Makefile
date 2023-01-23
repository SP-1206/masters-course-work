nfa_parser:	lex.yy.c headers.h
	gcc -o nfa_parser parser.c lex.yy.c -ll

lex.yy.c:	lexer.l
	flex lexer.l
