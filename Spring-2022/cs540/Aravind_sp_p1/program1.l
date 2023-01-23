%{
/*Aravind Sri Ram Sri Parasara
G# - G01301679*/
#include<string.h>
int count=5;
int bullet_count;
%}
%x BULLET
%%
<INITIAL>^\*  {
        BEGIN BULLET;
        printf("\n\n     * ");
        bullet_count=7;
    }
<BULLET>[A-Za-z0-9,.?!;:()\"\']+[-]* {
        bullet_count=bullet_count+yyleng;
        if(bullet_count<=53 && bullet_count!=0)
          {
            printf("%s ",yytext);
            bullet_count=bullet_count+1;
          }
        else
          {
          bullet_count=yyleng+7;
          printf("\n       %s ",yytext);
          bullet_count=bullet_count+1;
          }
        }
<BULLET>.
<BULLET>\n([ \t]*\n)*  BEGIN INITIAL;unput('\n');unput('\n');
<INITIAL>[A-Za-z0-9,.?!;:()\"\']+[-]* {
        count=count+yyleng;
        if(count<=60 && count!=0)
          {
            printf("%s ",yytext);
            count=count+1;
          }
        else
          {
          count=yyleng;
          printf("\n%s ",yytext);
          count=count+1;
          }
        }
.
\n printf(" ");count=count+1;
\n([ \t]*\n)+[^\*] count=6;printf("\n\n     %c",yytext[yyleng-1]);
^[ ]{1,4} ;
[ ][ ]+
%[^\n]*\n ;
%%
int main()
{
printf("     ");
yylex();
printf("\n");
return 1;
}
int yywrap(){return 1;}
