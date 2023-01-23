%{
/*Sri Parasara Aravind Sri Ram
G# G01301679*/
/*lexer to identify the tokens
single lower case letter is a terminal
Alphanumeric starting with a Capital is a
non-terminal */
#include<stdio.h>
#include "headers.h"
%}

%%
[a-z] {return TERMINAL;}
[A-Z][A-Za-z0-9]* {return NON_TERMINAL;}
-> {return ARROW;}
\n {return END_OF_LINE;}
.  ;
%%
