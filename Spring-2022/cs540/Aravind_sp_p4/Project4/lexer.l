%{
#include<stdio.h>
#include "headers.h"
#include "y.tab.h"
#include<stdlib.h>
int lineCount=0;
%}
%option yylineno
%%
[0-9]+ {char *s=strdup(yytext);yylval.number=atoi(s);return NUMBERS;}
#.* ;
array  {return ARRAY;}
seq  {return SEQ;}
define  {return DEFINE;}
if  {return IF;}
while  {strcpy(required_type_on_error,"bool");return WHILE;}
write  {strcpy(required_type_on_error,"integer");return WRITE;}
writeln  {strcpy(required_type_on_error,"integer");return WRITELN;}
read  {return READ;}
and  {strcpy(required_type_on_error,"bool");return AND;}
or  {strcpy(required_type_on_error,"bool");return OR;}
not  {strcpy(required_type_on_error,"bool");return NOT;}
set  {strcpy(required_type_on_error,"integer");return SET;}
let  {scope_stack_head++;stack_scope_init(&scope_stack[scope_stack_head],&scope_stack[scope_stack_head-1]);init_table(scope_stack[scope_stack_head].table);return LET;}
true  {return TRUE;}
false  {return FALSE;}
\(  {return LEFT_PARAM;}
\)  {return RIGHT_PARAM;}
\+  {strcpy(required_type_on_error,"integer");return PLUS;}
-  {strcpy(required_type_on_error,"integer");return MINUS;}
\*  {strcpy(required_type_on_error,"integer");return MULTIPLY;}
\/  {strcpy(required_type_on_error,"integer");return DIVISION;}
\<  {strcpy(required_type_on_error,"integer");return LESS_THAN;}
\<=  {strcpy(required_type_on_error,"integer");return LESS_THAN_OR_EQUAL_TO;}
\<>  {strcpy(required_type_on_error,"integer");return NOT_EQUAL_TO;}
>  {strcpy(required_type_on_error,"integer");return GREATER_THAN;}
>=  {strcpy(required_type_on_error,"integer");return GREATER_THAN_OR_EQUAL_TO;}
=  {strcpy(required_type_on_error,"integer");return EQUAL;}
\[  {return LEFT_SQUARE;}
]  {return RIGHT_SQUARE;}
&  {strcpy(required_type_on_error,"bool");return AND_SYMBOL;}
\|  {strcpy(required_type_on_error,"bool");return OR_SYMBOL;}
!  {strcpy(required_type_on_error,"bool");return NOT_SYMBOL;}
[\n]		{++lineCount; }
[A-Za-z][A-Za-z0-9_]* {yylval.string=strdup(yytext);return IDENTIFIER; }
.  ;
%%
