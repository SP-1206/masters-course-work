/*Sri Parasara Aravind Sri Ram
G# G01301679*/
/*header file to store all the function prototypes,
the Macros and the basic structure of a production.*/
#include<string.h>
#include<stdio.h>
#define NON_TERMINAL 1
#define ARROW 2
#define TERMINAL 3
#define END_OF_LINE 4
struct A_Production {
  char left[256];
  char on_seeing;
  char goes_to[256];
};
struct A_Production productions[30];

void print_it_terminal(char *s);
void print_it_nonterminal(char *s);
void print_it_arrow(char *s);
void print_it_terminal(char *s);
void print_it_nonterminal(char *s);
void print_it_arrow(char *s);
void error();
void match(int token);
void NFA();
void grammar();
void grammar_prime();
void production();
void production_prime();
void strings();
void strings_prime();
void string();
void string_prime();
void initialize(char left[256],char on_seeing,char goes_to[256]);
int is_it_final(char state[256]);
int NFA_search(char state[256],char string[256],int index_of_element_at);
