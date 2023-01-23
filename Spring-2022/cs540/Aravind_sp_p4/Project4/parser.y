%{
#include<stdio.h>
#include"headers.h"
extern int yylineno;
extern char yytext[];
int yylex();
void yyerror(const char *s);
extern symbol sym;
int actual_number,assign_counter,label_count=1;
char sample_string_n[20],sample_string_o[20],sample_string_w[20],sample_string_f[20];
%}
%token <string> IDENTIFIER
%token <number> NUMBERS
%token <string> END_OF_LINE
%token <string> ARRAY
%token <string> SEQ
%token <string> DEFINE
%token <string> IF
%token <string> WHILE
%token <string> WRITE
%token <string> WRITELN
%token <string> READ
%token <string> AND
%token <string> OR
%token <string> NOT
%token <string> SET
%token <string> LET
%token <string> TRUE
%token <string> FALSE
%token <string> LEFT_PARAM
%token <string> RIGHT_PARAM
%token <string> PLUS
%token <string> MINUS
%token <string> MULTIPLY
%token <string> DIVISION
%token <string> LESS_THAN
%token <string> LESS_THAN_OR_EQUAL_TO
%token <string> NOT_EQUAL_TO
%token <string> GREATER_THAN
%token <string> GREATER_THAN_OR_EQUAL_TO
%token <string> EQUAL
%token <string> LEFT_SQUARE
%token <string> RIGHT_SQUARE
%token <string> AND_SYMBOL
%token <string> OR_SYMBOL
%token <string> NOT_SYMBOL
%type <sym> expr
%type <sym> expr_list
%type <sym> function
%type <number> param_list
%type <number> id_list
%type <number> actual_list
%type <sym> ML
%type <sym> program
%union
{

        int number;
        char *string;
        symbol sym;

}
%%

ML		:	{initialize_global_register_array();super_scope.parent=NULL;number_of_to_be_cleaned=0;to_be_cleaned=(char **)malloc(10*sizeof(char *));init_table(super_scope.table);} arrays program {
                        if(strcmp($3.variable,"main")!=0)
                        printf("Error at line %d: The last function must be main\n",yylineno);
                        printf("\t.section        .note.GNU-stack,\"\",@progbits\n");



}
;
arrays		:	arrays array
					|
;
array		:	LEFT_PARAM ARRAY IDENTIFIER NUMBERS RIGHT_PARAM
                                                        {
                                                          add_to_table(super_scope.table,$3,$4,"array","global","-");
                                                          printf("\t.text\n");
                                                          printf("\t.comm %s,%d\n",$3,4*$4);


                                                        }
;
program		:	program function {
                              strcpy($$.variable,$2.variable);
                              scope_stack_head++;
                              stack_scope_init(&scope_stack[scope_stack_head],&super_scope);
                              init_table(scope_stack[scope_stack_head].table);

}
		|	function {
                strcpy($$.variable,$1.variable);
                scope_stack_head++;
                stack_scope_init(&scope_stack[scope_stack_head],&super_scope);
                init_table(scope_stack[scope_stack_head].table);

                }
		;
function	:	LEFT_PARAM DEFINE IDENTIFIER {
                                          add_to_table(super_scope.table,$3,0,"function","global","-");
                                          set_func_return_type($3,"integer");
                                          printf("	.text\n");
                                          if(strcmp($3,"main")==0)
                                          {
                                          printf("   .globl minlisp_main\n");
                                          printf("  .type   minlisp_main, @function\n");
                                          printf("minlisp_main:\n");
                                          }
                                          else
                                          {
                                          printf("   .globl %s\n",$3);
                                          printf("  .type   %s, @function\n",$3);
                                          printf("%s:\n",$3);
                                          }
                                          callee_save();
                                          }
                              param_list {
                                          set_func_param_number($3,$5);
                                         }
                              expr RIGHT_PARAM {
                                                strcpy($$.variable,$3);
                                                set_func_return_type($3,$7.type);
                                                scope_stack_head--;
                                                printf("\t// end of function\n");
                                                printf("\tmovl %s, %%eax\n",$7.in_register);
                                                clean_register($7.in_register);
                                                printf("\taddq $128, %%rsp\n");
                                                callee_restore();
                                                if(strcmp($3,"main")==0)
                                                printf("	.size   minlisp_main, .-minlisp_main\n");
                                                else
                                                printf("	.size   %s, .-%s\n",$3,$3);
                                                initialize_global_register_array("-");
                                                //printf("for function\n");
                                                //print_free_register();
                                                }
;
param_list	:	LEFT_PARAM RIGHT_PARAM
                                  {
                                  $$=0;
                                  }
			|	LEFT_PARAM {
                    func_param_counter=0;
                    }
       id_list RIGHT_PARAM {
                              $$=func_param_counter;
                            }
			;
id_list		:	id_list IDENTIFIER {
                              add_to_table(scope_stack[scope_stack_head].table,$2,0,"integer","parameter",function_register_store[func_param_counter]);
                              func_param_counter++;
                              }
		|	IDENTIFIER {

                  add_to_table(scope_stack[scope_stack_head].table,$1,0,"integer","parameter",function_register_store[func_param_counter]);
                  func_param_counter++;

                  }
;

expr		: NUMBERS {
                  $$.val=$1;strcpy($$.type,"integer");
                  strcpy($$.in_register,get_free_register());
                  printf("\tmovl $%d, %s\n",$$.val,$$.in_register);
                  //print_free_register();

                  }
		|	IDENTIFIER {
                  if(get_value(&scope_stack[scope_stack_head],$1)==-99999)
                  {
                  printf("error at line %d: variable %s not defined to avoid cascading errors creating a symbol with name %s and type %s\n",yylineno,$1,$1, required_type_on_error);
                  if(strcmp(required_type_on_error,"integer")==0)
                  add_to_table(scope_stack[scope_stack_head].table,$1,0,"integer","local","-");
                  if(strcmp(required_type_on_error,"bool")==0)
                  add_to_table(scope_stack[scope_stack_head].table,$1,0,"bool","local","-");
                  if(strcmp(required_type_on_error,"function")==0)
                  add_to_table(scope_stack[scope_stack_head].table,$1,0,"function","global","-");
                  }
                  if(strcmp(get_type(&scope_stack[scope_stack_head],$1),"function")==0)
                  {
                  strcpy($$.type,get_func_return_type($1));
                  caller_save();
                  printf("\tcall %s\n",$1);
                  caller_restore();
                  printf("movl %%eax, %s\n",get_free_register());
                  }
                  else
                  {
                  strcpy($$.type,get_type(&scope_stack[scope_stack_head],$1));
                  if(strcmp(get_scope_type(&scope_stack[scope_stack_head],$1),"parameter")==0)
                  {
                  //print_free_register();
                  strcpy($$.in_register,get_free_register());
                  printf("\tmovl %s, %s\n",get_in_register(&scope_stack[scope_stack_head],$1),$$.in_register);
                  clean_register(get_in_register(&scope_stack[scope_stack_head],$1));
                  }
                  if(strcmp(get_scope_type(&scope_stack[scope_stack_head],$1),"local")==0)
                  {
                  strcpy($$.in_register,get_free_register());
                  printf("\tmovl %s, %s\n",get_in_register(&scope_stack[scope_stack_head],$1),$$.in_register);

                  }

                  }

                  }
		|	IDENTIFIER LEFT_SQUARE expr RIGHT_SQUARE {
                            if(get_value(&super_scope,$1)==-99999)
                            printf("error at line %d: array %s not defined\n",yylineno,$1);
                            strcpy($$.type,"integer");
                            check_if_symbol("array index ",$3.type,"integer");
                            strcpy($$.in_register,get_free_register());
                            printf("\tmovl %s(,%.4s,4), %s\n",$1,$3.in_register,$$.in_register);
                  }
		|	TRUE {
      strcpy($$.type,"bool");$$.val=1;
      strcpy($$.in_register,get_free_register());
      printf("\tmovl $1, %s\n",$$.in_register);
      //print_free_register();

            }
		|	FALSE {
strcpy($$.type,"bool");$$.val=0;
strcpy($$.in_register,get_free_register());
printf("\tmovl $0, %s\n",$$.in_register);
//print_free_register()();

            }
		|	LEFT_PARAM IF expr {
    printf("\tcmpl $0, %s\n",$3.in_register);
    sprintf(sample_string_n,"LABEL%d",label_count);
    printf("\tje	%s\n",sample_string_n);
    //clean_register($3.in_register);
    label_count++;
    }
    expr {

    sprintf(sample_string_o,"LABEL%d",label_count);
    printf("\tjmp	%s\n",sample_string_o);
    printf("%s:\n",sample_string_n);
    label_count++;
    }
    expr {
    printf("\tmovl %s,%s\n", $7.in_register,$5.in_register);
    printf("%s:\n",sample_string_o);}
    RIGHT_PARAM
     {
                                                  check_for_if_statement($3.type,$5.type,$7.type);
                                                  strcpy($$.type,$5.type);
                                                  $$.val=$5.val;
                                                  strcpy($$.in_register,$5.in_register);
                                                  clean_register($3.in_register);
                                                  clean_register($7.in_register);

                                               }
 		|	LEFT_PARAM WHILE {
        sprintf(sample_string_w,"LABEL%d",label_count);
        printf("%s:\n",sample_string_w);
        label_count++;
}
    expr {
    check_if_symbol("while ",$4.type, "bool");
    printf("\tcmpl $0, %s\n",$4.in_register);
    sprintf(sample_string_f,"LABEL%d",label_count);
    printf("\tje	%s\n",sample_string_f);
    label_count++;


    }
    expr RIGHT_PARAM { printf("\tjmp %s\n",sample_string_w);
      printf("%s:\n",sample_string_f);
      strcpy($$.type,$6.type);$$.val=$6.val;
      strcpy($$.in_register,$6.in_register);
      clean_register($4.in_register);
      //clean_register($6.in_register);

                                             }
		|	LEFT_PARAM IDENTIFIER {
                            if(get_value(&super_scope,$2)==-99999)
                            printf("error at line %d function %s is not defined\n",yylineno,$2);
                            func_call_param_counter=0;
                            actual_number=0;
                            caller_save();
                            printf("\t//parameter\n");
                            }
      actual_list {

                    if(get_func_param_number($2)!=$4)
                    if(get_value(&super_scope,$2)!=-99999)
                    printf("error at line %d: %s function requires %d parameters given %d\n",yylineno,$2,get_func_param_number($2),$4);
                  }
      RIGHT_PARAM {
                    printf("\tcall %s\n",$2);
                    strcpy($$.type,get_func_return_type($2));
                    strcpy($$.variable,$2);
                    caller_restore();
                    strcpy($$.in_register,get_free_register());
                    printf("\tmovl %%eax, %s\n",$$.in_register);

                  }
 		|	LEFT_PARAM WRITE expr RIGHT_PARAM {
                                      check_if_symbol("write ",$3.type, "integer");
                                      $$.val=$3.val;strcpy($$.type,"integer");
                                      printf("\t//printf\n");
                                      caller_save();
                                      printf("\tmovl %s, %%esi\n",$3.in_register);
                                      printf("\tmovq S1(%%rip), %%rdi\n\tmovl $0, %%eax\n\tcall printf\n");
                                      caller_restore();
                                      strcpy($$.in_register,$3.in_register);
                                      //clean_register($3.in_register);
                                        }
		|	LEFT_PARAM WRITELN expr RIGHT_PARAM {
                                        check_if_symbol("writeln ",$3.type, "integer");
                                        $$.val=$3.val;strcpy($$.type,"integer");
                                        }
		|	LEFT_PARAM READ RIGHT_PARAM {
                                    strcpy($$.type,"integer");
                                    printf("\t//input\n");
                                    caller_save();
                                    printf("	call minlisp_input\n");
                                    caller_restore();
                                    strcpy($$.in_register,get_free_register());
                                    printf("\tmovl %%eax, %s\n",$$.in_register);


                                    }
 		|	LEFT_PARAM LET LEFT_PARAM{assign_counter=0;} assign_list RIGHT_PARAM expr RIGHT_PARAM {
                                        strcpy($$.type,$7.type);$$.val=$7.val;
                                        strcpy($$.in_register,$7.in_register);
                                        scope_stack_head--;
                                        }
		|	LEFT_PARAM SET IDENTIFIER expr RIGHT_PARAM {
                                        strcpy($$.type,$4.type);
                                        $$.val=$4.val;
                                        check_if_symbol("set command",$4.type,get_type(&scope_stack[scope_stack_head],$3));
                                        printf("\tmovl %s, %s\n", $4.in_register,get_in_register(&scope_stack[scope_stack_head],$3));
                                        strcpy($$.in_register,$4.in_register);

                                        }
		|	LEFT_PARAM SET IDENTIFIER LEFT_SQUARE expr RIGHT_SQUARE expr RIGHT_PARAM {
                                        check_if_symbol("Array index ",$5.type,"integer");
                                        strcpy($$.type,$7.type);$$.val=$7.val;
                                        check_if_symbol("Array ",$7.type,get_type(&scope_stack[scope_stack_head],$3));
                                        printf("\tmovl %s, %s(,%.4s,4)\n", $7.in_register,$3,$5.in_register);
                                        strcpy($$.in_register,$5.in_register);
                                        clean_register($7.in_register);
                                        }
 		|	LEFT_PARAM PLUS expr expr RIGHT_PARAM {

                                        check_if_symbol("add operator ",$3.type,"integer");
                                        check_if_symbol("add operator ",$4.type,"integer");
                                        strcpy($$.type,"integer");
                                        $$.val=$3.val+$4.val;
                                        printf("\taddl %s, %s\n",$4.in_register,$3.in_register);
                                        clean_register($4.in_register);
                                        //print_free_register()();
                                        strcpy($$.in_register,$3.in_register);



}
		|	LEFT_PARAM MINUS expr expr RIGHT_PARAM {
                                        check_if_symbol("subtract operator ",$3.type,"integer");
                                        check_if_symbol("subtract operator ",$4.type,"integer");
                                        strcpy($$.type,"integer");
                                        $$.val=$3.val-$4.val;
                                        printf("\tsubl %s, %s\n",$4.in_register,$3.in_register);
                                        clean_register($4.in_register);
                                        //print_free_register()();
                                        strcpy($$.in_register,$3.in_register);

}
 		|	LEFT_PARAM MULTIPLY expr expr RIGHT_PARAM {
                                        check_if_symbol("Multiply operator ",$3.type,"integer");
                                        check_if_symbol("Multiply operator ",$4.type,"integer");
                                        strcpy($$.type,"integer");
                                        $$.val=$3.val*$4.val;
                                        printf("\timull %s, %s\n",$4.in_register,$3.in_register);
                                        clean_register($4.in_register);
                                        //print_free_register()();
                                        strcpy($$.in_register,$3.in_register);

}

		|	LEFT_PARAM DIVISION expr expr RIGHT_PARAM {
                                        check_if_symbol("Division operator ",$3.type,"integer");
                                        check_if_symbol("Division operator ",$4.type,"integer");
                                        strcpy($$.type,"integer");
                                        $$.val=$3.val/$4.val;
                                        printf("\tdivl %s, %s\n",$4.in_register,$3.in_register);
                                        clean_register($4.in_register);
                                        //print_free_register()();
                                        strcpy($$.in_register,$3.in_register);


}
		|	LEFT_PARAM GREATER_THAN expr expr RIGHT_PARAM {
                                        check_if_symbol("Greater than operator ",$3.type,"integer");
                                        check_if_symbol("Greater than ",$4.type,"integer");
                                        strcpy($$.type,"bool");
                                        $$.val=$3.val>$4.val;
                                        printf("\tcmpl %s, %s\n", $4.in_register, $3.in_register);
                                        printf("\tsetg	%%al\n");
                                        printf("\tmovzbl %%al, %s\n", $3.in_register);
                                        strcpy($$.in_register,$3.in_register);
                                        clean_register($4.in_register);
}
		|	LEFT_PARAM GREATER_THAN_OR_EQUAL_TO expr expr RIGHT_PARAM {
                                        check_if_symbol("Greater than or equal to operator ",$3.type,"integer");
                                        check_if_symbol("Greater than or equal to operator ",$4.type,"integer");
                                        strcpy($$.type,"bool");
                                        $$.val=$3.val>=$4.val;
                                        printf("\tcmpl %s, %s\n", $4.in_register, $3.in_register);
                                        printf("\tsetge	%%al\n");
                                        printf("\tmovzbl %%al, %s\n", $3.in_register);
                                        strcpy($$.in_register,$3.in_register);
                                        clean_register($4.in_register);

}
 		|	LEFT_PARAM LESS_THAN expr expr RIGHT_PARAM {
                                        check_if_symbol("less than operator ",$3.type,"integer");
                                        check_if_symbol("less than operator ",$4.type,"integer");
                                        strcpy($$.type,"bool");
                                        $$.val=$3.val<$4.val;
                                        printf("\tcmpl %s, %s\n", $4.in_register, $3.in_register);
                                        printf("\tsetl	%%al\n");
                                        printf("\tmovzbl %%al, %s\n", $3.in_register);
                                        strcpy($$.in_register,$3.in_register);
                                        clean_register($4.in_register);

}
		|	LEFT_PARAM LESS_THAN_OR_EQUAL_TO expr expr RIGHT_PARAM {
                                        check_if_symbol("less than or equal to operator ",$3.type,"integer");
                                        check_if_symbol("less than or equal to operator ",$4.type,"integer");
                                        strcpy($$.type,"bool");
                                        $$.val=$3.val<=$4.val;
                                        printf("\tcmpl %s, %s\n", $4.in_register, $3.in_register);
                                        printf("\tsetle	%%al\n");
                                        printf("\tmovzbl %%al, %s\n", $3.in_register);
                                        strcpy($$.in_register,$3.in_register);
                                        clean_register($4.in_register);

}
 		|	LEFT_PARAM EQUAL expr expr RIGHT_PARAM {
                                        check_if_symbol("equal to operator ",$3.type,"integer");
                                        check_if_symbol("equal to operator ",$4.type,"integer");
                                        strcpy($$.type,"bool");
                                        $$.val=$3.val==$4.val;
                                        printf("\tcmpl %s, %s\n", $4.in_register, $3.in_register);
                                        printf("\tsete	%%al\n");
                                        printf("\tmovzbl %%al, %s\n", $3.in_register);
                                        strcpy($$.in_register,$3.in_register);
                                        clean_register($4.in_register);

}
		|	LEFT_PARAM NOT_EQUAL_TO expr expr RIGHT_PARAM {
                                        check_if_symbol("not equal to operator ",$3.type,"integer");
                                        check_if_symbol("not equal to operator ",$4.type,"integer");
                                        strcpy($$.type,"bool");
                                        $$.val=$3.val!=$4.val;
                                        printf("\tcmpl %s, %s\n", $4.in_register, $3.in_register);
                                        printf("\tsetne	%%al\n");
                                        printf("\tmovzbl %%al, %s\n", $3.in_register);
                                        strcpy($$.in_register,$3.in_register);
                                        clean_register($4.in_register);

}
 		|	LEFT_PARAM MINUS expr RIGHT_PARAM {
                                        check_if_symbol("negation operator ",$3.type,"integer");
                                        $$.val=0-$3.val;strcpy($$.type,"integer");
                                        printf("\tnegl %s\n",$3.in_register);
                                        strcpy($$.in_register,$3.in_register);

}
		|	LEFT_PARAM AND expr expr RIGHT_PARAM {
                                        check_if_symbol("AND operator ",$3.type,"bool");

                                        check_if_symbol("AND operator ",$4.type,"bool");
                                        strcpy($$.type,"bool");
                                        $$.val=$3.val&&$4.val;
}
		|	LEFT_PARAM AND_SYMBOL  expr expr RIGHT_PARAM {
                                        check_if_symbol("& operator ",$3.type,"bool");
                                        check_if_symbol("& operator ",$4.type,"bool");
                                        strcpy($$.type,"bool");
                                        $$.val=$3.val&&$4.val;
}
 		|	LEFT_PARAM OR  expr expr RIGHT_PARAM {
                                        check_if_symbol("OR operator",$3.type,"bool");
                                        check_if_symbol("OR operator",$4.type,"bool");
                                        strcpy($$.type,"bool");
                                        $$.val=$3.val||$4.val;
}
		|	LEFT_PARAM OR_SYMBOL  expr expr RIGHT_PARAM {
                                        check_if_symbol("| symbol ",$3.type,"bool");
                                        check_if_symbol("| symbol ",$4.type,"bool");
                                        strcpy($$.type,"bool");
                                        $$.val=$3.val||$4.val;
}
		|	LEFT_PARAM NOT expr RIGHT_PARAM  {
                                        check_if_symbol("NOT operator",$3.type,"bool");
                                        $$.val=!$3.val;strcpy($$.type,"bool");
}
		|	LEFT_PARAM NOT_SYMBOL expr RIGHT_PARAM {
                                        check_if_symbol("! symbol",$3.type,"bool");
                                        $$.val=!$3.val;strcpy($$.type,"bool");
}
    | LEFT_PARAM SEQ expr_list RIGHT_PARAM {
                                        strcpy($$.type,$3.type);
                                        strcpy($$.in_register,$3.in_register);
                                        $$.val=$3.val;
                                        //clean_register($3.in_register);

}
		;
actual_list	:	actual_list expr {
                                        $$++;
                                        check_if_symbol("function parameters ",$2.type,"integer");
                                        printf("\tmovl %s, %s\n", $2.in_register, function_register_store[actual_number]);
                                        clean_register($2.in_register);
                                        actual_number++;

}
		| {
                                        func_call_param_counter=$$;
                                        $$=0;
}
		;
assign_list	:	assign_list LEFT_PARAM IDENTIFIER expr RIGHT_PARAM {
                                        assign_counter++;
                                        char sample_string[10];
                                        sprintf(sample_string,"%d(%%rsp)",4*assign_counter);
                                        printf("\tmovl %s, %s\n",$4.in_register,sample_string);
                                        clean_register($4.in_register);
                                        add_to_table(scope_stack[scope_stack_head].table,$3,$4.val,"integer","local",sample_string);
}
		|	LEFT_PARAM IDENTIFIER expr RIGHT_PARAM {
    assign_counter++;
    char sample_string[10];
    sprintf(sample_string,"%d(%%rsp)",4*assign_counter);
    printf("\tmovl %s, %s\n",$3.in_register,sample_string);
    clean_register($3.in_register);
    add_to_table(scope_stack[scope_stack_head].table,$2,$3.val,"integer","local",sample_string);
}
		;
expr_list       :    expr_list expr {
                                        strcpy($$.type,$2.type);
                                        strcpy($$.in_register,$2.in_register);
                                        $$.val=$2.val;


}
		|	expr {
                strcpy($$.type,$1.type);
                //strcpy($$.in_register,$1.in_register);
                $$.val=$1.val;



          }
		;
%%
void yyerror(const char *s) {

 printf("error at line %d %s unexpected symbol %s\n",yylineno,s,yytext);

}
