//Sri Parasara Aravind Sri Ram
//G#:G01301679
//this is parent file that holds all the supporting functions used for parsing
#include<string.h>
#include<stdio.h>
#include"headers.h"
#include<stdlib.h>
extern int yylineno;
extern char yytext[];

void init_table(symbol **table)
{
  //function to initialize the new table
  int i=0;
  for(i=0;i<47;i++)
  {
    table[i]=NULL;
  }
}
int get_hash_code(char variable[256], int size)
{
  //function to get the hashcode for a given symbol
  int i=0;
  int val=0;
  for(i=0;i<strlen(variable);i++)
  {
    val=val+(int)variable[i];
  }
  return val%size;
}
void add_to_table(symbol **table,char variable[256], int val,char type[25])
{
  //add symbol to the hash table
  symbol *new_sym,*walker;
  new_sym=malloc(sizeof(symbol));
  strcpy(new_sym->variable,variable);
  new_sym->val=val;
  new_sym->next=NULL;
  strcpy(new_sym->type,type);
  int index=get_hash_code(variable,47);
  if(do_we_already_have_this_symbol(table,variable)==0)
  {
    //check if we already have the symbol if we do error out
    printf("error at line %d: duplicate definition of a variable %s\n",yylineno,variable);
    //exit(1);
  }

  if(table[index]==NULL)
  {
    table[index]=new_sym;
  }
  else
  {
    symbol *walker=table[index];
    while(walker->next!=NULL)
    {
        walker=walker->next;
    }
    //append
    walker->next=new_sym;
  }
}

void print_table(symbol **table)
{
  //print table function for debugging
  int i = 0;
  symbol *walker = NULL;

  /* Iterate every index, looking for symbols to print */
  for(i = 0; i < 47; i++) {
    walker = table[i];
    /* For each found linked list, print every symbol therein */
    while(walker != NULL) {
      printf(" %s: %d %s\n", walker->variable, walker->val, walker->type);
      walker = walker->next;
    }
  }
  return;
}
int do_we_already_have_this_symbol(symbol **table, char variable[256])
{
  //check if the variable is already defined in the current table
  int i = 0;
  symbol *walker = NULL;
  int index=get_hash_code(variable,47);
  walker = table[index];
      while(walker != NULL) {
      if(strcmp(walker->variable,variable)==0)
      {return 0;}
      walker = walker->next;
    }
  return 1;
}
int get_value(scope *current_scope, char variable[256])
{
  //get the value of a symbol
  scope *scope_walker=current_scope;
  while(scope_walker!=NULL)
  {
    if(do_we_already_have_this_symbol(scope_walker->table, variable)==0)
    {
      current_scope=scope_walker;
      break;
    }
    else
    scope_walker=scope_walker->parent;

  }
  int index=get_hash_code(variable,47);
  symbol *walker = NULL;
  walker = current_scope->table[index];
      while(walker != NULL)
      {
      if(strcmp(walker->variable,variable)==0)
      {
        return walker->val;
      }
      walker = walker->next;
    }
  return -1;

}
char *get_type(scope *current_scope, char variable[256])
{
  //get the type of a symbol bool or int
  scope *scope_walker=current_scope;
  while(scope_walker!=NULL)
  {
    if(do_we_already_have_this_symbol(scope_walker->table, variable)==0)
    {
      current_scope=scope_walker;
      break;
    }
    else
    scope_walker=scope_walker->parent;

  }
  int index=get_hash_code(variable,47);
  symbol *walker = NULL;
  walker = current_scope->table[index];
      while(walker != NULL)
      {
      if(strcmp(walker->variable,variable)==0)
      {
        return walker->type;
      }
      walker = walker->next;
    }
  return NULL;
}

void stack_push_scope()
{
  //push to stack
  scope_stack_head=scope_stack_head+1;
}
void stack_pop_scope()
{
  //pop from stack
  scope_stack_head=scope_stack_head-1;
}
void stack_scope_init(scope *current,scope *parent)
{
  current->parent=parent;
}

int check_if_symbol(char *for_this,char *expr_type, char *required)
{
  //check if the given symbol is of the required type
  if(strcmp(expr_type,"array")==0)
  {
    printf("error at line %d: array not accessed properly \n",yylineno);
    return 1;

  }
  if(strcmp(required,"array")==0)
  strcpy(required,"integer");
  if(strcmp(expr_type,"NULL")==0||strcmp(required,"NULL")==0)
  return 1;
  if(strcmp(expr_type,required)!=0)
  {
    printf("error at line %d: for %s expected %s but got %s \n",yylineno,for_this,required,expr_type);
    return 1;
  }
  else return 0;
}
int check_for_if_statement(char *condition, char *expr1,char *expr2)
{
  //if statement requires both the exprs to be of same type and condition to be of bool type
  check_if_symbol("if statement ",condition, "bool");

  if(strcmp(expr1,"integer")!=0)
   if(strcmp(expr1,"bool")!=0)
   {
     printf("error at line %d: if statement requires either int|bool type\n",yylineno);
   }

  if(strcmp(expr2,"integer")!=0)
    if(strcmp(expr2,"bool")!=0)
     {
       printf("error at line %d: if statement requires either int|bool type\n",yylineno);
     }
  if(strcmp(expr1,expr2)!=0)
    {
      printf("error at line %d: if statement requires both the statement to be of same type\n",yylineno);
    }
  return 1;
}

char *get_func_return_type(char variable[256])
{
  //function to get a functions return type
  int index=get_hash_code(variable,47);
  symbol *walker = NULL;
  walker = super_scope.table[index];
      while(walker != NULL)
      {
      if(strcmp(walker->variable,variable)==0)
      {
        return walker->for_func_return_type;
      }
      walker = walker->next;
    }
  return "NULL";
}

int get_func_param_number(char variable[256])
{
  //function to get the number of parameters required for a func
  int index=get_hash_code(variable,47);
  symbol *walker = NULL;
  walker = super_scope.table[index];
      while(walker != NULL)
      {
      if(strcmp(walker->variable,variable)==0)
      {
        return walker->for_func_param_num;
      }
      walker = walker->next;
    }
  return 0;
}
int set_func_return_type(char variable[256],char return_type[25])
{
  //function to set a functions return type
  int index=get_hash_code(variable,47);
  symbol *walker = NULL;
  walker = super_scope.table[index];
      while(walker != NULL)
      {
      if(strcmp(walker->variable,variable)==0)
      {
        strcpy(walker->for_func_return_type,return_type);
        return 1;
      }
      walker = walker->next;
    }
  return 0;
}

int set_func_param_number(char variable[256],int number_of_params)
{
  //function to set the number of parameters required for a function
  int index=get_hash_code(variable,47);
  symbol *walker = NULL;
  walker = super_scope.table[index];
      while(walker != NULL)
      {
      if(strcmp(walker->variable,variable)==0)
      {
        walker->for_func_param_num=number_of_params;
        return 1;
      }
      walker = walker->next;
    }
  return 0;
}

//void main()
//{
//  yyparse();
//  //super_scope.parent=NULL;
//  //init_table(super_scope.table);
//  //scope_stack_head=scope_stack_head+1;
//  //stack_scope_init(&scope_stack[scope_stack_head],&super_scope);
//  //init_table(scope_stack[scope_stack_head].table);
//  //add_to_table(scope_stack[scope_stack_head].table,"varaible",7);
//  //add_to_table(scope_stack[scope_stack_head].table,"vairable",8);
//  //add_to_table(super_scope.table,"vale",9);
//  //scope_stack_head=scope_stack_head+1;
//  //stack_scope_init(&scope_stack[scope_stack_head],&scope_stack[scope_stack_head-1]);
//  //init_table(scope_stack[scope_stack_head].table);
//  //add_to_table(scope_stack[scope_stack_head].table,"parent_it",7);
//  //add_to_table(scope_stack[scope_stack_head].table,"no_parent_it",8);
//  //printf("\n %d \n",get_value(&scope_stack[scope_stack_head], "vairable"));
//  //printf("\n %d \n",get_value(&scope_stack[scope_stack_head], "vale"));
//  //print_table(scope_stack[scope_stack_head].table);
//}
