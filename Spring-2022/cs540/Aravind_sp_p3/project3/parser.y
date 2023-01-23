%{
#include<stdio.h>
#include"headers.h"
extern int yylineno;
extern char yytext[];
int yylex();
void yyerror(const char *s);
extern symbol sym;
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
ML		:	arrays program {
                        if(strcmp($2.variable,"main")!=0)
                        printf("Error at line %d: The last function must be main\n",yylineno);
                        super_scope.parent=NULL;
                        init_table(super_scope.table);

}
;
arrays		:	arrays array
					|
;
array		:	LEFT_PARAM ARRAY IDENTIFIER NUMBERS RIGHT_PARAM
                                                        {
                                                          add_to_table(super_scope.table,$3,$4,"array");

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
                                          add_to_table(super_scope.table,$3,0,"function");
                                          set_func_return_type($3,"integer");
                                          }
                              param_list {
                                          set_func_param_number($3,$5);
                                         }
                              expr RIGHT_PARAM {
                                                strcpy($$.variable,$3);
                                                set_func_return_type($3,$7.type);
                                                scope_stack_head--;
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

                              func_param_counter++;
                              add_to_table(scope_stack[scope_stack_head].table,$2,0,"integer");

                              }
		|	IDENTIFIER {

                  func_param_counter++;add_to_table(scope_stack[scope_stack_head].table,$1,0,"integer");

                  }
;

expr		: NUMBERS {
$$.val=$1;strcpy($$.type,"integer");
                  }
		|	IDENTIFIER {
                  if(get_value(&scope_stack[scope_stack_head],$1)==-1)
                  {
                  printf("error at line %d: variable %s not defined to avoid cascading errors creating a symbol with name %s and type %s\n",yylineno,$1,$1, required_type_on_error);
                  if(strcmp(required_type_on_error,"integer")==0)
                  add_to_table(scope_stack[scope_stack_head].table,$1,0,"integer");
                  if(strcmp(required_type_on_error,"bool")==0)
                  add_to_table(scope_stack[scope_stack_head].table,$1,0,"bool");
                  if(strcmp(required_type_on_error,"function")==0)
                  add_to_table(scope_stack[scope_stack_head].table,$1,0,"function");

                  }
                  if(strcmp(get_type(&scope_stack[scope_stack_head],$1),"function")==0)
                  {strcpy($$.type,get_func_return_type($1));}
                  else
                  strcpy($$.type,get_type(&scope_stack[scope_stack_head],$1));
                  }
		|	IDENTIFIER LEFT_SQUARE expr RIGHT_SQUARE {
                            if(get_value(&super_scope,$1)==-1)
                            printf("error at line %d: array %s not defined\n",yylineno,$1);
                            strcpy($$.type,"integer");
                            check_if_symbol("array index ",$3.type,"integer");
                  }
		|	TRUE {
strcpy($$.type,"bool");$$.val=1;
            }
		|	FALSE {
strcpy($$.type,"bool");$$.val=0;
            }
		|	LEFT_PARAM IF expr expr expr RIGHT_PARAM {
                                                  check_for_if_statement($3.type,$4.type,$5.type);
                                                  strcpy($$.type,$4.type);$$.val=$4.val;
                                               }
 		|	LEFT_PARAM WHILE expr {check_if_symbol("while ",$3.type, "bool");} expr RIGHT_PARAM {
                                                strcpy($$.type,$5.type);$$.val=$5.val;
                                             }
		|	LEFT_PARAM IDENTIFIER {
                            if(get_value(&super_scope,$2)==-1)
                            printf("error at line %d function %s is not defined\n",yylineno,$2);
                            func_call_param_counter=0;
                            }
      actual_list {
                    if(get_func_param_number($2)!=$4)
                    if(get_value(&super_scope,$2)!=-1)
                    printf("error at line %d: %s function requires %d parameters given %d\n",yylineno,$2,get_func_param_number($2),$4);
                  }
      RIGHT_PARAM {
                    strcpy($$.type,get_func_return_type($2));
                    strcpy($$.variable,$2);
                  }
 		|	LEFT_PARAM WRITE expr RIGHT_PARAM {
                                      check_if_symbol("write ",$3.type, "integer");
                                      $$.val=$3.val;strcpy($$.type,"integer");
                                        }
		|	LEFT_PARAM WRITELN expr RIGHT_PARAM {
                                        check_if_symbol("writeln ",$3.type, "integer");
                                        $$.val=$3.val;strcpy($$.type,"integer");
                                        }
		|	LEFT_PARAM READ RIGHT_PARAM {
                                    strcpy($$.type,"integer");
                                    }
 		|	LEFT_PARAM LET LEFT_PARAM assign_list RIGHT_PARAM expr RIGHT_PARAM {
                                        strcpy($$.type,$6.type);$$.val=$6.val;
                                        scope_stack_head--;
                                        }
		|	LEFT_PARAM SET IDENTIFIER expr RIGHT_PARAM {
                                        strcpy($$.type,$4.type);
                                        $$.val=$4.val;
                                        check_if_symbol("set command",$4.type,get_type(&scope_stack[scope_stack_head],$3));
                                        }
		|	LEFT_PARAM SET IDENTIFIER LEFT_SQUARE expr RIGHT_SQUARE expr RIGHT_PARAM {
                                        check_if_symbol("Array index ",$5.type,"integer");
                                        strcpy($$.type,$7.type);$$.val=$7.val;
                                        check_if_symbol("Array ",$7.type,get_type(&scope_stack[scope_stack_head],$3));
                                        }
 		|	LEFT_PARAM PLUS expr expr RIGHT_PARAM {

                                        check_if_symbol("add operator ",$3.type,"integer");

                                        check_if_symbol("add operator ",$4.type,"integer");
                                        strcpy($$.type,"integer");
                                        $$.val=$3.val+$4.val;
}
		|	LEFT_PARAM MINUS expr expr RIGHT_PARAM {
                                        check_if_symbol("subtract operator ",$3.type,"integer");
                                        check_if_symbol("subtract operator ",$4.type,"integer");
                                        strcpy($$.type,"integer");
                                        $$.val=$3.val-$4.val;
}
 		|	LEFT_PARAM MULTIPLY expr expr RIGHT_PARAM {
                                        check_if_symbol("Multiply operator ",$3.type,"integer");
                                        check_if_symbol("Multiply operator ",$4.type,"integer");
                                        strcpy($$.type,"integer");
                                        $$.val=$3.val*$4.val;
}
		|	LEFT_PARAM DIVISION expr expr RIGHT_PARAM {
                                        check_if_symbol("Division operator ",$3.type,"integer");
                                        check_if_symbol("Division operator ",$4.type,"integer");
                                        strcpy($$.type,"integer");
                                        $$.val=$3.val/$4.val;
}
		|	LEFT_PARAM GREATER_THAN expr expr RIGHT_PARAM {
                                        check_if_symbol("Greater than operator ",$3.type,"integer");
                                        check_if_symbol("Greater than ",$4.type,"integer");
                                        strcpy($$.type,"bool");
                                        $$.val=$3.val>$4.val;
}
		|	LEFT_PARAM GREATER_THAN_OR_EQUAL_TO expr expr RIGHT_PARAM {
                                        check_if_symbol("Greater than or equal to operator ",$3.type,"integer");
                                        check_if_symbol("Greater than or equal to operator ",$4.type,"integer");
                                        strcpy($$.type,"bool");
                                        $$.val=$3.val>=$4.val;
}
 		|	LEFT_PARAM LESS_THAN expr expr RIGHT_PARAM {
                                        check_if_symbol("less than operator ",$3.type,"integer");
                                        check_if_symbol("less than operator ",$4.type,"integer");
                                        strcpy($$.type,"bool");
                                        $$.val=$3.val<$4.val;
}
		|	LEFT_PARAM LESS_THAN_OR_EQUAL_TO expr expr RIGHT_PARAM {
                                        check_if_symbol("less than or equal to operator ",$3.type,"integer");
                                        check_if_symbol("less than or equal to operator ",$4.type,"integer");
                                        strcpy($$.type,"bool");
                                        $$.val=$3.val<=$4.val;
}
 		|	LEFT_PARAM EQUAL expr expr RIGHT_PARAM {
                                        check_if_symbol("equal to operator ",$3.type,"integer");
                                        check_if_symbol("equal to operator ",$4.type,"integer");
                                        strcpy($$.type,"bool");
                                        $$.val=$3.val==$4.val;
}
		|	LEFT_PARAM NOT_EQUAL_TO expr expr RIGHT_PARAM {
                                        check_if_symbol("not equal to operator ",$3.type,"integer");
                                        check_if_symbol("not equal to operator ",$4.type,"integer");
                                        strcpy($$.type,"bool");
                                        $$.val=$3.val!=$4.val;
}
 		|	LEFT_PARAM MINUS expr RIGHT_PARAM {
                                        check_if_symbol("negation operator ",$3.type,"integer");
                                        $$.val=0-$3.val;strcpy($$.type,"integer");
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
                                        $$.val=$3.val;
}
		;
actual_list	:	actual_list expr {
                                        $$++;
                                        check_if_symbol("function parameters ",$2.type,"integer");
}
		| {
                                        func_call_param_counter=$$;
                                        $$=0;
}
		;
assign_list	:	assign_list LEFT_PARAM IDENTIFIER expr RIGHT_PARAM {
                                        add_to_table(scope_stack[scope_stack_head].table,$3,$4.val,"integer");
}
		|	LEFT_PARAM IDENTIFIER expr RIGHT_PARAM {
                                        add_to_table(scope_stack[scope_stack_head].table,$2,$3.val,"integer");
}
		;
expr_list       :    expr_list expr {
                                        strcpy($$.type,$2.type);
                                        $$.val=$2.val;
}
		|	expr {
                strcpy($$.type,$1.type);
                $$.val=$1.val;
          }
		;
%%
void yyerror(const char *s) {

 printf("error at line %d %s unexpected symbol %s\n",yylineno,s,yytext);

}
