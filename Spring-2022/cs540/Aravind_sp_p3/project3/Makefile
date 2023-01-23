typecheck: lex.yy.c y.tab.c y.tab.h headers.h table.c
	gcc -o typecheck table.c y.tab.c lex.yy.c  -ly -ll

lex.yy.c: lexer.l
	lex -l lexer.l

y.tab.c: parser.y
	yacc -d parser.y
clean:
	rm -rf lex.yy.c y.tab.* typecheck
