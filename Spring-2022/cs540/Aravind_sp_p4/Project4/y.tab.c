/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20170709

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "parser.y"
#include<stdio.h>
#include"headers.h"
extern int yylineno;
extern char yytext[];
int yylex();
void yyerror(const char *s);
extern symbol sym;
int actual_number,assign_counter,label_count=1;
char sample_string_n[20],sample_string_o[20],sample_string_w[20],sample_string_f[20];
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#line 55 "parser.y"
typedef union
{

        int number;
        char *string;
        symbol sym;

} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 47 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define IDENTIFIER 257
#define NUMBERS 258
#define END_OF_LINE 259
#define ARRAY 260
#define SEQ 261
#define DEFINE 262
#define IF 263
#define WHILE 264
#define WRITE 265
#define WRITELN 266
#define READ 267
#define AND 268
#define OR 269
#define NOT 270
#define SET 271
#define LET 272
#define TRUE 273
#define FALSE 274
#define LEFT_PARAM 275
#define RIGHT_PARAM 276
#define PLUS 277
#define MINUS 278
#define MULTIPLY 279
#define DIVISION 280
#define LESS_THAN 281
#define LESS_THAN_OR_EQUAL_TO 282
#define NOT_EQUAL_TO 283
#define GREATER_THAN 284
#define GREATER_THAN_OR_EQUAL_TO 285
#define EQUAL 286
#define LEFT_SQUARE 287
#define RIGHT_SQUARE 288
#define AND_SYMBOL 289
#define OR_SYMBOL 290
#define NOT_SYMBOL 291
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    9,    0,    8,    8,   10,    7,    7,   11,   12,    3,
    4,   13,    4,    5,    5,    1,    1,    1,    1,    1,
   14,   15,   16,    1,   17,   18,    1,   19,   20,    1,
    1,    1,    1,   22,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    6,    6,   21,   21,    2,
    2,
};
static const YYINT yylen[] = {                            2,
    0,    3,    2,    0,    5,    2,    1,    0,    0,    8,
    2,    0,    4,    2,    1,    1,    1,    4,    1,    1,
    0,    0,    0,    9,    0,    0,    7,    0,    0,    6,
    4,    4,    3,    0,    8,    5,    8,    5,    5,    5,
    5,    5,    5,    5,    5,    5,    5,    4,    5,    5,
    5,    5,    4,    4,    4,    2,    0,    5,    4,    2,
    1,
};
static const YYINT yydefred[] = {                         1,
    0,    4,    0,    0,    7,    0,    3,    0,    0,    0,
    6,    0,    8,    0,    0,    5,    0,    9,   11,    0,
    0,   15,    0,    0,   16,   19,   20,    0,    0,   14,
   13,    0,   28,    0,    0,   25,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   10,    0,   57,
   61,    0,   21,    0,    0,    0,   33,    0,    0,    0,
    0,   34,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   18,    0,   55,   60,    0,
   26,   31,   32,    0,    0,   53,    0,    0,    0,    0,
   48,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   54,   56,    0,   22,    0,   49,   51,    0,
   36,    0,    0,   38,   39,   40,   41,   44,   45,   47,
   42,   43,   46,   50,   52,   30,    0,    0,    0,    0,
    0,    0,   23,   27,    0,    0,    0,    0,    0,   37,
   59,    0,   35,   24,   58,
};
static const YYINT yydgoto[] = {                          1,
   29,   62,    5,   18,   23,   87,    6,    3,    2,    7,
   15,   21,   20,   90,  137,  149,   64,  117,   60,  115,
  123,   99,
};
static const YYINT yysindex[] = {                         0,
    0,    0, -274, -229,    0, -271,    0, -219, -217, -209,
    0, -204,    0, -220, -218,    0, -216,    0,    0, -198,
 -246,    0, -250, -226,    0,    0,    0, -191, -214,    0,
    0, -246,    0, -246, -246,    0, -246, -246, -213, -246,
 -246, -246, -193, -208, -246, -246, -246, -246, -246, -246,
 -246, -246, -246, -246, -246, -246, -246,    0, -206,    0,
    0, -136,    0, -246, -207, -205,    0, -246, -246, -192,
 -161,    0, -246, -130, -246, -246, -246, -246, -246, -246,
 -246, -246, -246, -246, -173,    0, -246,    0,    0, -246,
    0,    0,    0, -172, -170,    0, -246, -167, -164, -160,
    0, -153, -152, -151, -147, -146, -145, -143, -142, -141,
 -140, -135,    0,    0, -134,    0, -246,    0,    0, -139,
    0, -189, -241,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0, -246, -129, -246, -246,
 -174, -246,    0,    0, -128, -126, -246, -125, -124,    0,
    0, -123,    0,    0,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,  154,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0, -219,    0,    0,    0,
    0,    0,    0, -156,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0, -121,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
  -32,    0,  150,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,
};
#define YYTABLESIZE 156
static const YYINT yytable[] = {                         59,
    4,   61,   63,   10,   65,   66,   30,   68,   69,   70,
   24,   25,   73,   74,   75,   76,   77,   78,   79,   80,
   81,   82,   83,   84,   85,   31,   26,   27,   28,   89,
    8,   91,    9,  141,  142,   94,   95,   12,   98,   13,
  100,  102,  103,  104,  105,  106,  107,  108,  109,  110,
  111,  112,    9,   14,  114,   16,   17,  116,   22,   19,
   32,   58,   67,   71,  120,   33,   72,  140,   92,   34,
   93,   35,   36,   37,   38,   39,   40,   41,   42,   43,
   44,   86,  147,   96,  138,   45,   46,   47,   48,   49,
   50,   51,   52,   53,   54,   24,   25,   55,   56,   57,
   17,   17,  113,  118,  143,  119,  145,  146,  121,  148,
  122,   26,   27,   28,  152,  124,   17,   17,   17,   17,
   24,   25,  125,  126,  127,   97,   24,   25,  128,  129,
  130,   17,  131,  132,  133,  134,   26,   27,   28,   88,
  135,  136,   26,   27,   28,  101,  144,  150,  139,  151,
  153,  154,  155,    2,   29,   11,
};
static const YYINT yycheck[] = {                         32,
  275,   34,   35,  275,   37,   38,  257,   40,   41,   42,
  257,  258,   45,   46,   47,   48,   49,   50,   51,   52,
   53,   54,   55,   56,   57,  276,  273,  274,  275,   62,
  260,   64,  262,  275,  276,   68,   69,  257,   71,  257,
   73,   74,   75,   76,   77,   78,   79,   80,   81,   82,
   83,   84,  262,  258,   87,  276,  275,   90,  257,  276,
  287,  276,  276,  257,   97,  257,  275,  257,  276,  261,
  276,  263,  264,  265,  266,  267,  268,  269,  270,  271,
  272,  288,  257,  276,  117,  277,  278,  279,  280,  281,
  282,  283,  284,  285,  286,  257,  258,  289,  290,  291,
  257,  258,  276,  276,  137,  276,  139,  140,  276,  142,
  275,  273,  274,  275,  147,  276,  273,  274,  275,  276,
  257,  258,  276,  276,  276,  287,  257,  258,  276,  276,
  276,  288,  276,  276,  276,  276,  273,  274,  275,  276,
  276,  276,  273,  274,  275,  276,  276,  276,  288,  276,
  276,  276,  276,    0,  276,    6,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 291
#define YYUNDFTOKEN 316
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"IDENTIFIER","NUMBERS",
"END_OF_LINE","ARRAY","SEQ","DEFINE","IF","WHILE","WRITE","WRITELN","READ",
"AND","OR","NOT","SET","LET","TRUE","FALSE","LEFT_PARAM","RIGHT_PARAM","PLUS",
"MINUS","MULTIPLY","DIVISION","LESS_THAN","LESS_THAN_OR_EQUAL_TO",
"NOT_EQUAL_TO","GREATER_THAN","GREATER_THAN_OR_EQUAL_TO","EQUAL","LEFT_SQUARE",
"RIGHT_SQUARE","AND_SYMBOL","OR_SYMBOL","NOT_SYMBOL",0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : ML",
"$$1 :",
"ML : $$1 arrays program",
"arrays : arrays array",
"arrays :",
"array : LEFT_PARAM ARRAY IDENTIFIER NUMBERS RIGHT_PARAM",
"program : program function",
"program : function",
"$$2 :",
"$$3 :",
"function : LEFT_PARAM DEFINE IDENTIFIER $$2 param_list $$3 expr RIGHT_PARAM",
"param_list : LEFT_PARAM RIGHT_PARAM",
"$$4 :",
"param_list : LEFT_PARAM $$4 id_list RIGHT_PARAM",
"id_list : id_list IDENTIFIER",
"id_list : IDENTIFIER",
"expr : NUMBERS",
"expr : IDENTIFIER",
"expr : IDENTIFIER LEFT_SQUARE expr RIGHT_SQUARE",
"expr : TRUE",
"expr : FALSE",
"$$5 :",
"$$6 :",
"$$7 :",
"expr : LEFT_PARAM IF expr $$5 expr $$6 expr $$7 RIGHT_PARAM",
"$$8 :",
"$$9 :",
"expr : LEFT_PARAM WHILE $$8 expr $$9 expr RIGHT_PARAM",
"$$10 :",
"$$11 :",
"expr : LEFT_PARAM IDENTIFIER $$10 actual_list $$11 RIGHT_PARAM",
"expr : LEFT_PARAM WRITE expr RIGHT_PARAM",
"expr : LEFT_PARAM WRITELN expr RIGHT_PARAM",
"expr : LEFT_PARAM READ RIGHT_PARAM",
"$$12 :",
"expr : LEFT_PARAM LET LEFT_PARAM $$12 assign_list RIGHT_PARAM expr RIGHT_PARAM",
"expr : LEFT_PARAM SET IDENTIFIER expr RIGHT_PARAM",
"expr : LEFT_PARAM SET IDENTIFIER LEFT_SQUARE expr RIGHT_SQUARE expr RIGHT_PARAM",
"expr : LEFT_PARAM PLUS expr expr RIGHT_PARAM",
"expr : LEFT_PARAM MINUS expr expr RIGHT_PARAM",
"expr : LEFT_PARAM MULTIPLY expr expr RIGHT_PARAM",
"expr : LEFT_PARAM DIVISION expr expr RIGHT_PARAM",
"expr : LEFT_PARAM GREATER_THAN expr expr RIGHT_PARAM",
"expr : LEFT_PARAM GREATER_THAN_OR_EQUAL_TO expr expr RIGHT_PARAM",
"expr : LEFT_PARAM LESS_THAN expr expr RIGHT_PARAM",
"expr : LEFT_PARAM LESS_THAN_OR_EQUAL_TO expr expr RIGHT_PARAM",
"expr : LEFT_PARAM EQUAL expr expr RIGHT_PARAM",
"expr : LEFT_PARAM NOT_EQUAL_TO expr expr RIGHT_PARAM",
"expr : LEFT_PARAM MINUS expr RIGHT_PARAM",
"expr : LEFT_PARAM AND expr expr RIGHT_PARAM",
"expr : LEFT_PARAM AND_SYMBOL expr expr RIGHT_PARAM",
"expr : LEFT_PARAM OR expr expr RIGHT_PARAM",
"expr : LEFT_PARAM OR_SYMBOL expr expr RIGHT_PARAM",
"expr : LEFT_PARAM NOT expr RIGHT_PARAM",
"expr : LEFT_PARAM NOT_SYMBOL expr RIGHT_PARAM",
"expr : LEFT_PARAM SEQ expr_list RIGHT_PARAM",
"actual_list : actual_list expr",
"actual_list :",
"assign_list : assign_list LEFT_PARAM IDENTIFIER expr RIGHT_PARAM",
"assign_list : LEFT_PARAM IDENTIFIER expr RIGHT_PARAM",
"expr_list : expr_list expr",
"expr_list : expr",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 565 "parser.y"
void yyerror(const char *s) {

 printf("error at line %d %s unexpected symbol %s\n",yylineno,s,yytext);

}
#line 366 "y.tab.c"

#if YYDEBUG
#include <stdio.h>	/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yym = 0;
    yyn = 0;
    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        yychar = YYLEX;
        if (yychar < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if (((yyn = yysindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if (((yyn = yyrindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag != 0) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab; /* redundant goto avoids 'unused label' warning */
yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if (((yyn = yysindex[*yystack.s_mark]) != 0) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym > 0)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);

    switch (yyn)
    {
case 1:
#line 65 "parser.y"
	{initialize_global_register_array();super_scope.parent=NULL;number_of_to_be_cleaned=0;to_be_cleaned=(char **)malloc(10*sizeof(char *));init_table(super_scope.table);}
break;
case 2:
#line 65 "parser.y"
	{
                        if(strcmp(yystack.l_mark[0].sym.variable,"main")!=0)
                        printf("Error at line %d: The last function must be main\n",yylineno);
                        printf("\t.section        .note.GNU-stack,\"\",@progbits\n");



}
break;
case 5:
#line 78 "parser.y"
	{
                                                          add_to_table(super_scope.table,yystack.l_mark[-2].string,yystack.l_mark[-1].number,"array","global","-");
                                                          printf("\t.text\n");
                                                          printf("\t.comm %s,%d\n",yystack.l_mark[-2].string,4*yystack.l_mark[-1].number);


                                                        }
break;
case 6:
#line 86 "parser.y"
	{
                              strcpy(yyval.sym.variable,yystack.l_mark[0].sym.variable);
                              scope_stack_head++;
                              stack_scope_init(&scope_stack[scope_stack_head],&super_scope);
                              init_table(scope_stack[scope_stack_head].table);

}
break;
case 7:
#line 93 "parser.y"
	{
                strcpy(yyval.sym.variable,yystack.l_mark[0].sym.variable);
                scope_stack_head++;
                stack_scope_init(&scope_stack[scope_stack_head],&super_scope);
                init_table(scope_stack[scope_stack_head].table);

                }
break;
case 8:
#line 101 "parser.y"
	{
                                          add_to_table(super_scope.table,yystack.l_mark[0].string,0,"function","global","-");
                                          set_func_return_type(yystack.l_mark[0].string,"integer");
                                          printf("	.text\n");
                                          if(strcmp(yystack.l_mark[0].string,"main")==0)
                                          {
                                          printf("   .globl minlisp_main\n");
                                          printf("  .type   minlisp_main, @function\n");
                                          printf("minlisp_main:\n");
                                          }
                                          else
                                          {
                                          printf("   .globl %s\n",yystack.l_mark[0].string);
                                          printf("  .type   %s, @function\n",yystack.l_mark[0].string);
                                          printf("%s:\n",yystack.l_mark[0].string);
                                          }
                                          callee_save();
                                          }
break;
case 9:
#line 119 "parser.y"
	{
                                          set_func_param_number(yystack.l_mark[-2].string,yystack.l_mark[0].number);
                                         }
break;
case 10:
#line 122 "parser.y"
	{
                                                strcpy(yyval.sym.variable,yystack.l_mark[-5].string);
                                                set_func_return_type(yystack.l_mark[-5].string,yystack.l_mark[-1].sym.type);
                                                scope_stack_head--;
                                                printf("\t// end of function\n");
                                                printf("\tmovl %s, %%eax\n",yystack.l_mark[-1].sym.in_register);
                                                clean_register(yystack.l_mark[-1].sym.in_register);
                                                printf("\taddq $128, %%rsp\n");
                                                callee_restore();
                                                if(strcmp(yystack.l_mark[-5].string,"main")==0)
                                                printf("	.size   minlisp_main, .-minlisp_main\n");
                                                else
                                                printf("	.size   %s, .-%s\n",yystack.l_mark[-5].string,yystack.l_mark[-5].string);
                                                initialize_global_register_array("-");
                                                /*printf("for function\n");*/
                                                /*print_free_register();*/
                                                }
break;
case 11:
#line 141 "parser.y"
	{
                                  yyval.number=0;
                                  }
break;
case 12:
#line 144 "parser.y"
	{
                    func_param_counter=0;
                    }
break;
case 13:
#line 147 "parser.y"
	{
                              yyval.number=func_param_counter;
                            }
break;
case 14:
#line 151 "parser.y"
	{
                              add_to_table(scope_stack[scope_stack_head].table,yystack.l_mark[0].string,0,"integer","parameter",function_register_store[func_param_counter]);
                              func_param_counter++;
                              }
break;
case 15:
#line 155 "parser.y"
	{

                  add_to_table(scope_stack[scope_stack_head].table,yystack.l_mark[0].string,0,"integer","parameter",function_register_store[func_param_counter]);
                  func_param_counter++;

                  }
break;
case 16:
#line 163 "parser.y"
	{
                  yyval.sym.val=yystack.l_mark[0].number;strcpy(yyval.sym.type,"integer");
                  strcpy(yyval.sym.in_register,get_free_register());
                  printf("\tmovl $%d, %s\n",yyval.sym.val,yyval.sym.in_register);
                  /*print_free_register();*/

                  }
break;
case 17:
#line 170 "parser.y"
	{
                  if(get_value(&scope_stack[scope_stack_head],yystack.l_mark[0].string)==-99999)
                  {
                  printf("error at line %d: variable %s not defined to avoid cascading errors creating a symbol with name %s and type %s\n",yylineno,yystack.l_mark[0].string,yystack.l_mark[0].string, required_type_on_error);
                  if(strcmp(required_type_on_error,"integer")==0)
                  add_to_table(scope_stack[scope_stack_head].table,yystack.l_mark[0].string,0,"integer","local","-");
                  if(strcmp(required_type_on_error,"bool")==0)
                  add_to_table(scope_stack[scope_stack_head].table,yystack.l_mark[0].string,0,"bool","local","-");
                  if(strcmp(required_type_on_error,"function")==0)
                  add_to_table(scope_stack[scope_stack_head].table,yystack.l_mark[0].string,0,"function","global","-");
                  }
                  if(strcmp(get_type(&scope_stack[scope_stack_head],yystack.l_mark[0].string),"function")==0)
                  {
                  strcpy(yyval.sym.type,get_func_return_type(yystack.l_mark[0].string));
                  caller_save();
                  printf("\tcall %s\n",yystack.l_mark[0].string);
                  caller_restore();
                  printf("movl %%eax, %s\n",get_free_register());
                  }
                  else
                  {
                  strcpy(yyval.sym.type,get_type(&scope_stack[scope_stack_head],yystack.l_mark[0].string));
                  if(strcmp(get_scope_type(&scope_stack[scope_stack_head],yystack.l_mark[0].string),"parameter")==0)
                  {
                  /*print_free_register();*/
                  strcpy(yyval.sym.in_register,get_free_register());
                  printf("\tmovl %s, %s\n",get_in_register(&scope_stack[scope_stack_head],yystack.l_mark[0].string),yyval.sym.in_register);
                  clean_register(get_in_register(&scope_stack[scope_stack_head],yystack.l_mark[0].string));
                  }
                  if(strcmp(get_scope_type(&scope_stack[scope_stack_head],yystack.l_mark[0].string),"local")==0)
                  {
                  strcpy(yyval.sym.in_register,get_free_register());
                  printf("\tmovl %s, %s\n",get_in_register(&scope_stack[scope_stack_head],yystack.l_mark[0].string),yyval.sym.in_register);

                  }

                  }

                  }
break;
case 18:
#line 209 "parser.y"
	{
                            if(get_value(&super_scope,yystack.l_mark[-3].string)==-99999)
                            printf("error at line %d: array %s not defined\n",yylineno,yystack.l_mark[-3].string);
                            strcpy(yyval.sym.type,"integer");
                            check_if_symbol("array index ",yystack.l_mark[-1].sym.type,"integer");
                            strcpy(yyval.sym.in_register,get_free_register());
                            printf("\tmovl %s(,%.4s,4), %s\n",yystack.l_mark[-3].string,yystack.l_mark[-1].sym.in_register,yyval.sym.in_register);
                  }
break;
case 19:
#line 217 "parser.y"
	{
      strcpy(yyval.sym.type,"bool");yyval.sym.val=1;
      strcpy(yyval.sym.in_register,get_free_register());
      printf("\tmovl $1, %s\n",yyval.sym.in_register);
      /*print_free_register();*/

            }
break;
case 20:
#line 224 "parser.y"
	{
strcpy(yyval.sym.type,"bool");yyval.sym.val=0;
strcpy(yyval.sym.in_register,get_free_register());
printf("\tmovl $0, %s\n",yyval.sym.in_register);
/*print_free_register()();*/

            }
break;
case 21:
#line 231 "parser.y"
	{
    printf("\tcmpl $0, %s\n",yystack.l_mark[0].sym.in_register);
    sprintf(sample_string_n,"LABEL%d",label_count);
    printf("\tje	%s\n",sample_string_n);
    /*clean_register($3.in_register);*/
    label_count++;
    }
break;
case 22:
#line 238 "parser.y"
	{

    sprintf(sample_string_o,"LABEL%d",label_count);
    printf("\tjmp	%s\n",sample_string_o);
    printf("%s:\n",sample_string_n);
    label_count++;
    }
break;
case 23:
#line 245 "parser.y"
	{
    printf("\tmovl %s,%s\n", yystack.l_mark[0].sym.in_register,yystack.l_mark[-2].sym.in_register);
    printf("%s:\n",sample_string_o);}
break;
case 24:
#line 249 "parser.y"
	{
                                                  check_for_if_statement(yystack.l_mark[-6].sym.type,yystack.l_mark[-4].sym.type,yystack.l_mark[-2].sym.type);
                                                  strcpy(yyval.sym.type,yystack.l_mark[-4].sym.type);
                                                  yyval.sym.val=yystack.l_mark[-4].sym.val;
                                                  strcpy(yyval.sym.in_register,yystack.l_mark[-4].sym.in_register);
                                                  clean_register(yystack.l_mark[-6].sym.in_register);
                                                  clean_register(yystack.l_mark[-2].sym.in_register);

                                               }
break;
case 25:
#line 258 "parser.y"
	{
        sprintf(sample_string_w,"LABEL%d",label_count);
        printf("%s:\n",sample_string_w);
        label_count++;
}
break;
case 26:
#line 263 "parser.y"
	{
    check_if_symbol("while ",yystack.l_mark[0].sym.type, "bool");
    printf("\tcmpl $0, %s\n",yystack.l_mark[0].sym.in_register);
    sprintf(sample_string_f,"LABEL%d",label_count);
    printf("\tje	%s\n",sample_string_f);
    label_count++;


    }
break;
case 27:
#line 272 "parser.y"
	{ printf("\tjmp %s\n",sample_string_w);
      printf("%s:\n",sample_string_f);
      strcpy(yyval.sym.type,yystack.l_mark[-1].sym.type);yyval.sym.val=yystack.l_mark[-1].sym.val;
      strcpy(yyval.sym.in_register,yystack.l_mark[-1].sym.in_register);
      clean_register(yystack.l_mark[-3].sym.in_register);
      /*clean_register($6.in_register);*/

                                             }
break;
case 28:
#line 280 "parser.y"
	{
                            if(get_value(&super_scope,yystack.l_mark[0].string)==-99999)
                            printf("error at line %d function %s is not defined\n",yylineno,yystack.l_mark[0].string);
                            func_call_param_counter=0;
                            actual_number=0;
                            caller_save();
                            printf("\t//parameter\n");
                            }
break;
case 29:
#line 288 "parser.y"
	{

                    if(get_func_param_number(yystack.l_mark[-2].string)!=yystack.l_mark[0].number)
                    if(get_value(&super_scope,yystack.l_mark[-2].string)!=-99999)
                    printf("error at line %d: %s function requires %d parameters given %d\n",yylineno,yystack.l_mark[-2].string,get_func_param_number(yystack.l_mark[-2].string),yystack.l_mark[0].number);
                  }
break;
case 30:
#line 294 "parser.y"
	{
                    printf("\tcall %s\n",yystack.l_mark[-4].string);
                    strcpy(yyval.sym.type,get_func_return_type(yystack.l_mark[-4].string));
                    strcpy(yyval.sym.variable,yystack.l_mark[-4].string);
                    caller_restore();
                    strcpy(yyval.sym.in_register,get_free_register());
                    printf("\tmovl %%eax, %s\n",yyval.sym.in_register);

                  }
break;
case 31:
#line 303 "parser.y"
	{
                                      check_if_symbol("write ",yystack.l_mark[-1].sym.type, "integer");
                                      yyval.sym.val=yystack.l_mark[-1].sym.val;strcpy(yyval.sym.type,"integer");
                                      printf("\t//printf\n");
                                      caller_save();
                                      printf("\tmovl %s, %%esi\n",yystack.l_mark[-1].sym.in_register);
                                      printf("\tmovq S1(%%rip), %%rdi\n\tmovl $0, %%eax\n\tcall printf\n");
                                      caller_restore();
                                      strcpy(yyval.sym.in_register,yystack.l_mark[-1].sym.in_register);
                                      /*clean_register($3.in_register);*/
                                        }
break;
case 32:
#line 314 "parser.y"
	{
                                        check_if_symbol("writeln ",yystack.l_mark[-1].sym.type, "integer");
                                        yyval.sym.val=yystack.l_mark[-1].sym.val;strcpy(yyval.sym.type,"integer");
                                        }
break;
case 33:
#line 318 "parser.y"
	{
                                    strcpy(yyval.sym.type,"integer");
                                    printf("\t//input\n");
                                    caller_save();
                                    printf("	call minlisp_input\n");
                                    caller_restore();
                                    strcpy(yyval.sym.in_register,get_free_register());
                                    printf("\tmovl %%eax, %s\n",yyval.sym.in_register);


                                    }
break;
case 34:
#line 329 "parser.y"
	{assign_counter=0;}
break;
case 35:
#line 329 "parser.y"
	{
                                        strcpy(yyval.sym.type,yystack.l_mark[-1].sym.type);yyval.sym.val=yystack.l_mark[-1].sym.val;
                                        strcpy(yyval.sym.in_register,yystack.l_mark[-1].sym.in_register);
                                        scope_stack_head--;
                                        }
break;
case 36:
#line 334 "parser.y"
	{
                                        strcpy(yyval.sym.type,yystack.l_mark[-1].sym.type);
                                        yyval.sym.val=yystack.l_mark[-1].sym.val;
                                        check_if_symbol("set command",yystack.l_mark[-1].sym.type,get_type(&scope_stack[scope_stack_head],yystack.l_mark[-2].string));
                                        printf("\tmovl %s, %s\n", yystack.l_mark[-1].sym.in_register,get_in_register(&scope_stack[scope_stack_head],yystack.l_mark[-2].string));
                                        strcpy(yyval.sym.in_register,yystack.l_mark[-1].sym.in_register);

                                        }
break;
case 37:
#line 342 "parser.y"
	{
                                        check_if_symbol("Array index ",yystack.l_mark[-3].sym.type,"integer");
                                        strcpy(yyval.sym.type,yystack.l_mark[-1].sym.type);yyval.sym.val=yystack.l_mark[-1].sym.val;
                                        check_if_symbol("Array ",yystack.l_mark[-1].sym.type,get_type(&scope_stack[scope_stack_head],yystack.l_mark[-5].string));
                                        printf("\tmovl %s, %s(,%.4s,4)\n", yystack.l_mark[-1].sym.in_register,yystack.l_mark[-5].string,yystack.l_mark[-3].sym.in_register);
                                        strcpy(yyval.sym.in_register,yystack.l_mark[-3].sym.in_register);
                                        clean_register(yystack.l_mark[-1].sym.in_register);
                                        }
break;
case 38:
#line 350 "parser.y"
	{

                                        check_if_symbol("add operator ",yystack.l_mark[-2].sym.type,"integer");
                                        check_if_symbol("add operator ",yystack.l_mark[-1].sym.type,"integer");
                                        strcpy(yyval.sym.type,"integer");
                                        yyval.sym.val=yystack.l_mark[-2].sym.val+yystack.l_mark[-1].sym.val;
                                        printf("\taddl %s, %s\n",yystack.l_mark[-1].sym.in_register,yystack.l_mark[-2].sym.in_register);
                                        clean_register(yystack.l_mark[-1].sym.in_register);
                                        /*print_free_register()();*/
                                        strcpy(yyval.sym.in_register,yystack.l_mark[-2].sym.in_register);



}
break;
case 39:
#line 364 "parser.y"
	{
                                        check_if_symbol("subtract operator ",yystack.l_mark[-2].sym.type,"integer");
                                        check_if_symbol("subtract operator ",yystack.l_mark[-1].sym.type,"integer");
                                        strcpy(yyval.sym.type,"integer");
                                        yyval.sym.val=yystack.l_mark[-2].sym.val-yystack.l_mark[-1].sym.val;
                                        printf("\tsubl %s, %s\n",yystack.l_mark[-1].sym.in_register,yystack.l_mark[-2].sym.in_register);
                                        clean_register(yystack.l_mark[-1].sym.in_register);
                                        /*print_free_register()();*/
                                        strcpy(yyval.sym.in_register,yystack.l_mark[-2].sym.in_register);

}
break;
case 40:
#line 375 "parser.y"
	{
                                        check_if_symbol("Multiply operator ",yystack.l_mark[-2].sym.type,"integer");
                                        check_if_symbol("Multiply operator ",yystack.l_mark[-1].sym.type,"integer");
                                        strcpy(yyval.sym.type,"integer");
                                        yyval.sym.val=yystack.l_mark[-2].sym.val*yystack.l_mark[-1].sym.val;
                                        printf("\timull %s, %s\n",yystack.l_mark[-1].sym.in_register,yystack.l_mark[-2].sym.in_register);
                                        clean_register(yystack.l_mark[-1].sym.in_register);
                                        /*print_free_register()();*/
                                        strcpy(yyval.sym.in_register,yystack.l_mark[-2].sym.in_register);

}
break;
case 41:
#line 387 "parser.y"
	{
                                        check_if_symbol("Division operator ",yystack.l_mark[-2].sym.type,"integer");
                                        check_if_symbol("Division operator ",yystack.l_mark[-1].sym.type,"integer");
                                        strcpy(yyval.sym.type,"integer");
                                        yyval.sym.val=yystack.l_mark[-2].sym.val/yystack.l_mark[-1].sym.val;
                                        printf("\tdivl %s, %s\n",yystack.l_mark[-1].sym.in_register,yystack.l_mark[-2].sym.in_register);
                                        clean_register(yystack.l_mark[-1].sym.in_register);
                                        /*print_free_register()();*/
                                        strcpy(yyval.sym.in_register,yystack.l_mark[-2].sym.in_register);


}
break;
case 42:
#line 399 "parser.y"
	{
                                        check_if_symbol("Greater than operator ",yystack.l_mark[-2].sym.type,"integer");
                                        check_if_symbol("Greater than ",yystack.l_mark[-1].sym.type,"integer");
                                        strcpy(yyval.sym.type,"bool");
                                        yyval.sym.val=yystack.l_mark[-2].sym.val>yystack.l_mark[-1].sym.val;
                                        printf("\tcmpl %s, %s\n", yystack.l_mark[-1].sym.in_register, yystack.l_mark[-2].sym.in_register);
                                        printf("\tsetg	%%al\n");
                                        printf("\tmovzbl %%al, %s\n", yystack.l_mark[-2].sym.in_register);
                                        strcpy(yyval.sym.in_register,yystack.l_mark[-2].sym.in_register);
                                        clean_register(yystack.l_mark[-1].sym.in_register);
}
break;
case 43:
#line 410 "parser.y"
	{
                                        check_if_symbol("Greater than or equal to operator ",yystack.l_mark[-2].sym.type,"integer");
                                        check_if_symbol("Greater than or equal to operator ",yystack.l_mark[-1].sym.type,"integer");
                                        strcpy(yyval.sym.type,"bool");
                                        yyval.sym.val=yystack.l_mark[-2].sym.val>=yystack.l_mark[-1].sym.val;
                                        printf("\tcmpl %s, %s\n", yystack.l_mark[-1].sym.in_register, yystack.l_mark[-2].sym.in_register);
                                        printf("\tsetge	%%al\n");
                                        printf("\tmovzbl %%al, %s\n", yystack.l_mark[-2].sym.in_register);
                                        strcpy(yyval.sym.in_register,yystack.l_mark[-2].sym.in_register);
                                        clean_register(yystack.l_mark[-1].sym.in_register);

}
break;
case 44:
#line 422 "parser.y"
	{
                                        check_if_symbol("less than operator ",yystack.l_mark[-2].sym.type,"integer");
                                        check_if_symbol("less than operator ",yystack.l_mark[-1].sym.type,"integer");
                                        strcpy(yyval.sym.type,"bool");
                                        yyval.sym.val=yystack.l_mark[-2].sym.val<yystack.l_mark[-1].sym.val;
                                        printf("\tcmpl %s, %s\n", yystack.l_mark[-1].sym.in_register, yystack.l_mark[-2].sym.in_register);
                                        printf("\tsetl	%%al\n");
                                        printf("\tmovzbl %%al, %s\n", yystack.l_mark[-2].sym.in_register);
                                        strcpy(yyval.sym.in_register,yystack.l_mark[-2].sym.in_register);
                                        clean_register(yystack.l_mark[-1].sym.in_register);

}
break;
case 45:
#line 434 "parser.y"
	{
                                        check_if_symbol("less than or equal to operator ",yystack.l_mark[-2].sym.type,"integer");
                                        check_if_symbol("less than or equal to operator ",yystack.l_mark[-1].sym.type,"integer");
                                        strcpy(yyval.sym.type,"bool");
                                        yyval.sym.val=yystack.l_mark[-2].sym.val<=yystack.l_mark[-1].sym.val;
                                        printf("\tcmpl %s, %s\n", yystack.l_mark[-1].sym.in_register, yystack.l_mark[-2].sym.in_register);
                                        printf("\tsetle	%%al\n");
                                        printf("\tmovzbl %%al, %s\n", yystack.l_mark[-2].sym.in_register);
                                        strcpy(yyval.sym.in_register,yystack.l_mark[-2].sym.in_register);
                                        clean_register(yystack.l_mark[-1].sym.in_register);

}
break;
case 46:
#line 446 "parser.y"
	{
                                        check_if_symbol("equal to operator ",yystack.l_mark[-2].sym.type,"integer");
                                        check_if_symbol("equal to operator ",yystack.l_mark[-1].sym.type,"integer");
                                        strcpy(yyval.sym.type,"bool");
                                        yyval.sym.val=yystack.l_mark[-2].sym.val==yystack.l_mark[-1].sym.val;
                                        printf("\tcmpl %s, %s\n", yystack.l_mark[-1].sym.in_register, yystack.l_mark[-2].sym.in_register);
                                        printf("\tsete	%%al\n");
                                        printf("\tmovzbl %%al, %s\n", yystack.l_mark[-2].sym.in_register);
                                        strcpy(yyval.sym.in_register,yystack.l_mark[-2].sym.in_register);
                                        clean_register(yystack.l_mark[-1].sym.in_register);

}
break;
case 47:
#line 458 "parser.y"
	{
                                        check_if_symbol("not equal to operator ",yystack.l_mark[-2].sym.type,"integer");
                                        check_if_symbol("not equal to operator ",yystack.l_mark[-1].sym.type,"integer");
                                        strcpy(yyval.sym.type,"bool");
                                        yyval.sym.val=yystack.l_mark[-2].sym.val!=yystack.l_mark[-1].sym.val;
                                        printf("\tcmpl %s, %s\n", yystack.l_mark[-1].sym.in_register, yystack.l_mark[-2].sym.in_register);
                                        printf("\tsetne	%%al\n");
                                        printf("\tmovzbl %%al, %s\n", yystack.l_mark[-2].sym.in_register);
                                        strcpy(yyval.sym.in_register,yystack.l_mark[-2].sym.in_register);
                                        clean_register(yystack.l_mark[-1].sym.in_register);

}
break;
case 48:
#line 470 "parser.y"
	{
                                        check_if_symbol("negation operator ",yystack.l_mark[-1].sym.type,"integer");
                                        yyval.sym.val=0-yystack.l_mark[-1].sym.val;strcpy(yyval.sym.type,"integer");
                                        printf("\tnegl %s\n",yystack.l_mark[-1].sym.in_register);
                                        strcpy(yyval.sym.in_register,yystack.l_mark[-1].sym.in_register);

}
break;
case 49:
#line 477 "parser.y"
	{
                                        check_if_symbol("AND operator ",yystack.l_mark[-2].sym.type,"bool");

                                        check_if_symbol("AND operator ",yystack.l_mark[-1].sym.type,"bool");
                                        strcpy(yyval.sym.type,"bool");
                                        yyval.sym.val=yystack.l_mark[-2].sym.val&&yystack.l_mark[-1].sym.val;
}
break;
case 50:
#line 484 "parser.y"
	{
                                        check_if_symbol("& operator ",yystack.l_mark[-2].sym.type,"bool");
                                        check_if_symbol("& operator ",yystack.l_mark[-1].sym.type,"bool");
                                        strcpy(yyval.sym.type,"bool");
                                        yyval.sym.val=yystack.l_mark[-2].sym.val&&yystack.l_mark[-1].sym.val;
}
break;
case 51:
#line 490 "parser.y"
	{
                                        check_if_symbol("OR operator",yystack.l_mark[-2].sym.type,"bool");
                                        check_if_symbol("OR operator",yystack.l_mark[-1].sym.type,"bool");
                                        strcpy(yyval.sym.type,"bool");
                                        yyval.sym.val=yystack.l_mark[-2].sym.val||yystack.l_mark[-1].sym.val;
}
break;
case 52:
#line 496 "parser.y"
	{
                                        check_if_symbol("| symbol ",yystack.l_mark[-2].sym.type,"bool");
                                        check_if_symbol("| symbol ",yystack.l_mark[-1].sym.type,"bool");
                                        strcpy(yyval.sym.type,"bool");
                                        yyval.sym.val=yystack.l_mark[-2].sym.val||yystack.l_mark[-1].sym.val;
}
break;
case 53:
#line 502 "parser.y"
	{
                                        check_if_symbol("NOT operator",yystack.l_mark[-1].sym.type,"bool");
                                        yyval.sym.val=!yystack.l_mark[-1].sym.val;strcpy(yyval.sym.type,"bool");
}
break;
case 54:
#line 506 "parser.y"
	{
                                        check_if_symbol("! symbol",yystack.l_mark[-1].sym.type,"bool");
                                        yyval.sym.val=!yystack.l_mark[-1].sym.val;strcpy(yyval.sym.type,"bool");
}
break;
case 55:
#line 510 "parser.y"
	{
                                        strcpy(yyval.sym.type,yystack.l_mark[-1].sym.type);
                                        strcpy(yyval.sym.in_register,yystack.l_mark[-1].sym.in_register);
                                        yyval.sym.val=yystack.l_mark[-1].sym.val;
                                        /*clean_register($3.in_register);*/

}
break;
case 56:
#line 518 "parser.y"
	{
                                        yyval.number++;
                                        check_if_symbol("function parameters ",yystack.l_mark[0].sym.type,"integer");
                                        printf("\tmovl %s, %s\n", yystack.l_mark[0].sym.in_register, function_register_store[actual_number]);
                                        clean_register(yystack.l_mark[0].sym.in_register);
                                        actual_number++;

}
break;
case 57:
#line 526 "parser.y"
	{
                                        func_call_param_counter=yyval.number;
                                        yyval.number=0;
}
break;
case 58:
#line 531 "parser.y"
	{
                                        assign_counter++;
                                        char sample_string[10];
                                        sprintf(sample_string,"%d(%%rsp)",4*assign_counter);
                                        printf("\tmovl %s, %s\n",yystack.l_mark[-1].sym.in_register,sample_string);
                                        clean_register(yystack.l_mark[-1].sym.in_register);
                                        add_to_table(scope_stack[scope_stack_head].table,yystack.l_mark[-2].string,yystack.l_mark[-1].sym.val,"integer","local",sample_string);
}
break;
case 59:
#line 539 "parser.y"
	{
    assign_counter++;
    char sample_string[10];
    sprintf(sample_string,"%d(%%rsp)",4*assign_counter);
    printf("\tmovl %s, %s\n",yystack.l_mark[-1].sym.in_register,sample_string);
    clean_register(yystack.l_mark[-1].sym.in_register);
    add_to_table(scope_stack[scope_stack_head].table,yystack.l_mark[-2].string,yystack.l_mark[-1].sym.val,"integer","local",sample_string);
}
break;
case 60:
#line 548 "parser.y"
	{
                                        strcpy(yyval.sym.type,yystack.l_mark[0].sym.type);
                                        strcpy(yyval.sym.in_register,yystack.l_mark[0].sym.in_register);
                                        yyval.sym.val=yystack.l_mark[0].sym.val;


}
break;
case 61:
#line 555 "parser.y"
	{
                strcpy(yyval.sym.type,yystack.l_mark[0].sym.type);
                /*strcpy($$.in_register,$1.in_register);*/
                yyval.sym.val=yystack.l_mark[0].sym.val;



          }
break;
#line 1225 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            yychar = YYLEX;
            if (yychar < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if (((yyn = yygindex[yym]) != 0) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
