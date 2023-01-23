Name: Sri Parasara Aravind Sri Ram
G#: G01301679*/
Language, Grammar rules can be found at:
https://mymasonportal.gmu.edu/bbcswebdav/pid-14984265-dt-content-rid-238232721_1/courses/H5202210/MinLispSpec%282%29.html

This project is written in C
lexer.l - contains the lexer
parser.y - contains the YACC parser
headers.h - is the parent file with all the function prototypes and required variables
table.c - this is the file that holds the entire symbol table, scope stack implementation

Makefile defined to compile and create an executable
instructions to compile: run `make`
this creates a executable called typecheck
instructions to run:
type check expects string input from STDIN
eg: `./typecheck < tests/part3.my`

Datastructures used:
A linked list of Scopes - each scope has a pointer to its parent scope
A hash table to store the variables found within a scope
A stack - used to determine the current scope
