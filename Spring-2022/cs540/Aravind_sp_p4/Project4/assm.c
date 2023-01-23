#include<string.h>
#include<stdio.h>
#include"headers.h"
#include<stdlib.h>
void initialize_global_register_array(char *s)
{
  register_head=NULL;
  clean_register("%r15d");
  clean_register("%r14d");
  clean_register("%r13d");
  clean_register("%r12d");
  clean_register("%ebp");
  clean_register("%ebx");
  clean_register("%r11d");
  clean_register("%r10d");
  sscanf( "%edi %esi %edx %ecx %r8d %r9d", "\%s %s %s %s %s %s %s ", function_register_store[0],function_register_store[1],function_register_store[2],function_register_store[3],function_register_store[4],function_register_store[5],function_register_store[6]);
}

//void main()
//{
//  clean_register("%r10d");
//  clean_register("%r11d");
//  clean_register("%ebx");
//  clean_register("%ebp");
//  clean_register("%r12d");
//  clean_register("%r13d");
//  clean_register("%r14d");
//  clean_register("%r15d");
//
//  printf("%s\n",get_free_register());
//  printf("%s\n",get_free_register());
//  clean_register("%r10d");
//  printf("%s\n",get_free_register());
//}

char *get_free_register_old()
{
  int i=0;
  char *tmp=(char*) malloc(5*sizeof(char));
  for(i=0;i<8;i++)
  {
    if(strcmp(register_store[i],"EMPTY")==0)
    {
      continue;
    }
    else
    {
      strcpy(tmp,register_store[i]);
      strcpy(register_store[i],"EMPTY");
      //printf("%s\n",register_store[i]);
      //printf("%s",tmp);
      return tmp;
    }
  }
}

void clean_register_old(char *reg)
{
  printf("cleaning -> reg %s\n",reg);
  int i;
  for(i=0;i<8;i++)
  {
    if(strcmp(register_store[i],"EMPTY")==0)
    {
      strcpy(register_store[i],reg);
      return;
    }
  }

}
void print_free_register()
{
  printf("printing free registers\n");
  nregisters *walker=(register_head);
  while ( walker!= NULL) {
          printf("| %s |\n", walker->s);
          walker = walker->next;
      }}

void caller_save()
{
  printf("\t// caller save\n");
  printf("\tmovq %%rdi, 64(%%rsp)\n");
  printf("\tmovq %%rsi, 72(%%rsp)\n");
  printf("\tmovq %%rdx, 80(%%rsp)\n");
  printf("\tmovq %%rcx, 88(%%rsp)\n");
  printf("\tmovq %%r8, 96(%%rsp)\n");
  printf("\tmovq %%r9, 104(%%rsp)\n");
  printf("\tmovq %%r10, 112(%%rsp)\n");
  printf("\tmovq %%r11, 120(%%rsp)\n");
return;
}
void callee_save()
{
  printf("\t// callee save\n");
  printf("\tpushq %%rbx\n");
  printf("\tpushq %%rbp\n");
  printf("\tpushq %%r12\n");
  printf("\tpushq %%r13\n");
  printf("\tpushq %%r14\n");
  printf("\tpushq %%r15\n");
  printf("\tsubq $128, %%rsp\n");
return;
}
void caller_restore()
{
  printf("\t// caller restore\n");
  printf("\tmovq 64(%%rsp), %%rdi\n");
  printf("\tmovq 72(%%rsp), %%rsi\n");
  printf("\tmovq 80(%%rsp), %%rdx\n");
  printf("\tmovq 88(%%rsp), %%rcx\n");
  printf("\tmovq 96(%%rsp), %%r8\n");
  printf("\tmovq 104(%%rsp), %%r9\n");
  printf("\tmovq 112(%%rsp), %%r10\n");
  printf("\tmovq 120(%%rsp), %%r11\n");
return;
}
void callee_restore()
{
  printf("\t// callee restore\n");
  printf("\tpopq %%r15\n");
  printf("\tpopq %%r14\n");
  printf("\tpopq %%r13\n");
  printf("\tpopq %%r12\n");
  printf("\tpopq %%rbp\n");
  printf("\tpopq %%rbx\n");
  printf("\tret\n");
return;
}

char *get_scope_type(scope *current_scope, char variable[256])
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
        return walker->scope_type;
      }
      walker = walker->next;
    }
  return NULL;
}


char *get_in_register(scope *current_scope, char variable[256])
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
        return walker->in_register;
      }
      walker = walker->next;
    }
  return NULL;
}
int is_it_in_a_param_register(char *s)
{
  char *reg=get_in_register(&scope_stack[scope_stack_head],s);
  int i;
  for(i=0;i<6;i++)
  {
    if(strcmp(reg,function_register_store[i])==0)
    return 1;
  }
  return 0;
}

void clean_register(char *s)
{
  int i;
  for(i=0;i<6;i++)
  {
    if(strcmp(s,function_register_store[i])==0)
    return;
  }
  int falg=1;

  nregisters *walker=(register_head);
  while ( walker!= NULL) {
          if(strcmp(s,walker->s)==0)
          {
            falg=0;
          }
          walker = walker->next;
      }
if(falg==1)
{
  //printf("%s cleaning..........\n",s);
  nregisters* new_node = (nregisters*) malloc(sizeof(nregisters));
  new_node->s=(char *)malloc(5*sizeof(char));
  strcpy(new_node->s,s);
  new_node->next = (register_head);
  register_head = new_node;
}
  //print_free_register();
}
char* get_free_register()
{

  if(register_head==NULL)
  {
    printf("no registers left\n");
    exit(1);
  }
  nregisters* temp = register_head;
    register_head = register_head->next;
    return temp->s;


}

void garbage_collector()
{
  int i;
  for(i=0;i<number_of_to_be_cleaned;i++)
  {
  printf("what is going on?--------%s\n",to_be_cleaned[i]);
  clean_register(to_be_cleaned[i]);
  }
  number_of_to_be_cleaned=0;
//print_free_register();
}
void append_to_clean_register(char *s)
{
  int i=0;int flag=0;
  if(number_of_to_be_cleaned!=0)
  {
    for(i=0;i<number_of_to_be_cleaned;i++)
    {
      if(strcmp(to_be_cleaned[i],s)==0)
      flag=1;
    }
    printf("\n");
  }
if(flag!=1)
  {    to_be_cleaned[number_of_to_be_cleaned]=(char *)malloc(5*sizeof(char));
  strcpy(to_be_cleaned[number_of_to_be_cleaned],s);

  number_of_to_be_cleaned++;
}

}
