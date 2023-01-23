/*Sri Parasara Aravind Sri Ram
G# G01301679*/
/*
Production                                              Predict
input -> grammar strings                                   N
grammar -> production grammar_prime                        N
grammar_prime -> production grammar_prime                  N
grammar_prime -> epsilon                                   T,E
production -> NON_TERMINAL ARROW production_prime          N
production_prime -> TERMINAL NON_TERMINAL END_OF_LINE      T
production_prime -> NON_TERMINAL END_OF_LINE               N
production_prime -> END_OF_LINE                            E
strings -> string END_OF_LINE strings_prime                E,T
strings_prime -> string END_OF_LINE string_prime           E,T
string_prime -> epsilon                                     $ (end)
string -> string_prime                                      T
string_prime -> TERMINAL string_prime                       T
string_prime -> epsilon                                     E
*/
#include<stdio.h>
#include "headers.h"
#include<stdlib.h>
extern int yylex();
extern char* yytext;
int lookahead;
char string_to_parse[256];
int string_to_parse_length=0;
int production_count=0;

int main()
{
lookahead=yylex();
NFA();
if (lookahead != 0) /* eof */
    printf("Extra tokens: String rejected\n");
//to print the NFA
//for(int i=0;i<production_count;i++)
//{
//  printf("%s on seeing %c goes to %s\n",productions[i].left, productions[i].on_seeing,productions[i].goes_to );
//}

return 1;
}

/*recursive parent function that kicks of the NFA parsing*/
int NFA_search(char state[256],char string[256],int index_of_element_at)
{
  int i;
if(index_of_element_at==strlen(string) && is_it_final(state)==1)
  return 1;
else
  if(index_of_element_at==strlen(string) && is_it_final(state)!=1)
    return 0;
for(i=0;i<production_count;i++)
{
    if(strcmp(productions[i].left,state)==0 && (productions[i].on_seeing==string[index_of_element_at]))
    {
    if((NFA_search(productions[i].goes_to,string,index_of_element_at+1))==1)
      return 1;
    }
}
for(i=0;i<production_count;i++)
{
if(strcmp(productions[i].left,state)==0 && productions[i].on_seeing =='~')
{
  if((NFA_search(productions[i].goes_to,string,index_of_element_at))==1)
  {
    return 1;
  }
}
}
return 0;
}
/*Helper function that returns if a state is final or not*/
int is_it_final(char state[256])
{
  int i;
  for(i=0;i<production_count;i++)
  {
    if(strcmp(state,productions[i].left)==0 && productions[i].on_seeing=='~' && strcmp(productions[i].goes_to,"~")==0)
    return 1;
  }
  return 0;
}

/*init function to initialize the variables*/
void initialize(char left[256],char on_seeing,char goes_to[256])
{
  strcpy(productions[production_count].left,left);
  productions[production_count].on_seeing=on_seeing;
  strcpy(productions[production_count].goes_to,goes_to);
  production_count++;
}

void error() {
  printf("syntax error: String rejected\n");
  exit(2);
}
void match(int token) {
  if (token == lookahead) lookahead = yylex();
  else error();
}

/*Parent function that parses the File contents
based on the CFG*/
//input -> grammar strings
void NFA() {
  if (lookahead == NON_TERMINAL)
  {
     grammar();
     strings();
   }
  else error();
}
//grammar -> production grammar_prime
/*helper function to parse the string in file*/
void grammar()
{
if (lookahead == NON_TERMINAL)
{
   production();
   grammar_prime();
}
else error();
}
//grammar_prime -> production grammar_prime
//grammar_prime -> epsilon
/*helper function to parse the string in file*/
void grammar_prime()
{
if (lookahead == NON_TERMINAL)
{
  production();
  grammar_prime();
}
else if(lookahead == TERMINAL || lookahead == END_OF_LINE)
{
   return;
}
else error();
}

//production -> NON_TERMINAL ARROW production_prime
/*helper function to parse the string in file*/
void production()
{
char source[20];
if (lookahead == NON_TERMINAL)
  {
  strcpy(source,yytext);
  match(NON_TERMINAL);
  match(ARROW);
  production_prime(source);
  }
else error();
}
//production_prime -> TERMINAL NON_TERMINAL END_OF_LINE
//production_prime -> NON_TERMINAL END_OF_LINE
//production_prime -> END_OF_LINE
/*helper function to parse the string in file*/
void production_prime(char source[20])
{
char termi;
if (lookahead == TERMINAL)
{
  termi=yytext[0];
  match(TERMINAL);
  initialize(source,termi,yytext);
  match(NON_TERMINAL);match(END_OF_LINE);
}
else if(lookahead == NON_TERMINAL)
{
  initialize(source,'~',yytext);
  match(NON_TERMINAL);
  match(END_OF_LINE);
}
else if(lookahead == END_OF_LINE)
{
  initialize(source,'~',"~");
  match(END_OF_LINE);
}
else error();
}

//strings -> string END_OF_LINE strings_prime
/*helper function to parse the string in file*/
void strings()
{
if(lookahead == END_OF_LINE || lookahead == TERMINAL) {
string();
match(END_OF_LINE);strings_prime();}
}

//strings_prime -> string END_OF_LINE string_prime
//string_prime -> epsilon
/*helper function to parse the string in file*/
void strings_prime()
{
if(lookahead == TERMINAL || lookahead == END_OF_LINE)
{
string();
match(END_OF_LINE);
strings_prime(); }
else if(lookahead == 0) { return; }
else error();
}

//string -> string_prime
/*helper function to parse the string in file*/
void string()
{
if(lookahead == TERMINAL || lookahead == END_OF_LINE){
 string_prime();
if(NFA_search(productions[0].left,string_to_parse,0)==1)
{
printf("Accept %s\n",string_to_parse);
}
else
printf("Reject %s\n",string_to_parse);
memset(string_to_parse,0,sizeof(string_to_parse));
string_to_parse_length=0;

 }
}

//string_prime -> TERMINAL string_prime
//string_prime -> epsilon
/*helper function to parse the string in file*/
void string_prime()
{
if(lookahead == TERMINAL)
{
  string_to_parse[string_to_parse_length]=yytext[0];
  string_to_parse_length++;
  match(TERMINAL);
  string_prime();
}
else if(lookahead == END_OF_LINE)
{
  return;
}
}
