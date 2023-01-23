/*Sri Parasara Aravind Sri Ram
G# G01301679*/
/*header file to store all the function prototypes,
the Macros and the basic structure of a production.*/
#include<string.h>
#include<stdio.h>

//guard to avoid duplication of variables
#ifndef NEW_GUARD
#define NEW_GUARD
typedef struct symbol_row {
  char variable[256];
  int val;
  char type[25];
  int for_func_param_num;
  char for_func_return_type[25];
  struct symbol_row *next;
}symbol;

typedef struct scope_val {
  symbol *table[47];
  struct scope_val *parent;
}scope;


scope scope_stack[50];
scope super_scope;
int scope_stack_head;
int func_param_counter;
int func_call_param_counter;
char required_type_on_error[256];
#endif
void add_to_table(symbol **table,char variable[256], int val,char type[25]);
int get_hash_code(char variable[256], int size);
int get_value(scope *current_scope, char variable[256]);
int do_we_already_have_this_symbol(symbol **table, char variable[256]);
void print_table(symbol **table);
void init_table(symbol **table);
void stack_scope_init(scope *current,scope *parent);
void stack_push_scope();
void stack_pop_scope();
char *get_type(scope *current_scope, char variable[256]);
char *get_func_return_type(char variable[256]);
int get_func_param_number(char variable[256]);
int check_if_symbol(char *for_this,char *expr_type, char *required);
int check_for_if_statement(char *condtion, char *expr1,char *expr2);
int set_func_return_type(char variable[256],char return_type[25]);
int set_func_param_number(char variable[256],int number_of_params);
//stack implementted as an array

int is_variable_in_scope(char variable[256]);
