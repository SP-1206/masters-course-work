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
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#line 53 "parser.y"
typedef union
{

        int number;
        char *string;
        symbol sym;

} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 45 "y.tab.c"

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
    0,    8,    8,    9,    7,    7,   10,   11,    3,    4,
   12,    4,    5,    5,    1,    1,    1,    1,    1,    1,
   13,    1,   14,   15,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    6,
    6,   16,   16,    2,    2,
};
static const YYINT yylen[] = {                            2,
    2,    2,    0,    5,    2,    1,    0,    0,    8,    2,
    0,    4,    2,    1,    1,    1,    4,    1,    1,    6,
    0,    6,    0,    0,    6,    4,    4,    3,    7,    5,
    8,    5,    5,    5,    5,    5,    5,    5,    5,    5,
    5,    4,    5,    5,    5,    5,    4,    4,    4,    2,
    0,    5,    4,    2,    1,
};
static const YYINT yydefred[] = {                         3,
    0,    0,    0,    6,    0,    2,    0,    0,    0,    5,
    0,    7,    0,    0,    4,    0,    8,   10,    0,    0,
   14,    0,    0,   15,   18,   19,    0,    0,   13,   12,
    0,   23,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    9,    0,   51,   55,
    0,    0,   21,    0,    0,   28,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   17,    0,   49,   54,    0,    0,
   26,   27,    0,    0,   47,    0,    0,    0,    0,    0,
   42,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   48,   50,    0,    0,    0,   43,   45,    0,
   30,    0,    0,    0,   32,   33,   34,   35,   38,   39,
   41,   36,   37,   40,   44,   46,   25,   20,   22,    0,
    0,    0,    0,    0,   53,    0,   29,   31,   52,
};
static const YYINT yydgoto[] = {                          1,
   28,   61,    4,   17,   22,   86,    5,    2,    6,   14,
   20,   19,   90,   59,  115,   99,
};
static const YYINT yysindex[] = {                         0,
    0, -274, -228,    0, -242,    0, -222, -217, -224,    0,
 -198,    0, -215, -213,    0, -212,    0,    0, -194, -246,
    0, -250, -221,    0,    0,    0, -183, -209,    0,    0,
 -246,    0, -246, -246, -246, -246, -246, -208, -246, -246,
 -246, -184, -200, -246, -246, -246, -246, -246, -246, -246,
 -246, -246, -246, -246, -246, -246,    0, -211,    0,    0,
 -204, -246,    0, -197, -186,    0, -246, -246, -166, -145,
 -199, -246, -142, -246, -246, -246, -246, -246, -246, -246,
 -246, -246, -246, -162,    0, -246,    0,    0, -246, -246,
    0,    0, -159, -158,    0, -246, -157, -165, -219, -152,
    0, -151, -150, -149, -140, -139, -138, -137, -136, -135,
 -133, -132,    0,    0, -131, -130, -129,    0,    0, -134,
    0, -246, -109, -246,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -246,
 -127, -246, -126, -125,    0, -124,    0,    0,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,  153,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0, -222,    0,    0,    0,    0,
    0,    0, -153,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0, -121,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
  -31,    0,  151,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,
};
#define YYTABLESIZE 156
static const YYINT yytable[] = {                         58,
    3,   60,   62,   63,   64,   65,   29,   67,   68,   69,
   23,   24,   72,   73,   74,   75,   76,   77,   78,   79,
   80,   81,   82,   83,   84,   30,   25,   26,   27,   88,
   89,    7,    9,    8,   11,   93,   94,    8,   97,   12,
  100,  102,  103,  104,  105,  106,  107,  108,  109,  110,
  111,  112,   23,   24,  114,  123,  124,  116,  117,   13,
   15,   16,   21,   18,  120,   31,   57,   66,   25,   26,
   27,   87,   70,   32,   71,   98,   85,   33,   91,   34,
   35,   36,   37,   38,   39,   40,   41,   42,   43,   92,
  141,  122,  143,   44,   45,   46,   47,   48,   49,   50,
   51,   52,   53,   16,   16,   54,   55,   56,  144,   95,
  146,   23,   24,  113,   23,   24,  118,  119,  121,   16,
   16,   16,   16,  125,  126,  127,  128,   25,   26,   27,
   25,   26,   27,  101,   16,  129,  130,  131,  132,  133,
  134,   96,  135,  136,  137,  138,  139,  142,  145,  147,
  148,  149,    1,  140,   24,   10,
};
static const YYINT yycheck[] = {                         31,
  275,   33,   34,   35,   36,   37,  257,   39,   40,   41,
  257,  258,   44,   45,   46,   47,   48,   49,   50,   51,
   52,   53,   54,   55,   56,  276,  273,  274,  275,   61,
   62,  260,  275,  262,  257,   67,   68,  262,   70,  257,
   72,   73,   74,   75,   76,   77,   78,   79,   80,   81,
   82,   83,  257,  258,   86,  275,  276,   89,   90,  258,
  276,  275,  257,  276,   96,  287,  276,  276,  273,  274,
  275,  276,  257,  257,  275,  275,  288,  261,  276,  263,
  264,  265,  266,  267,  268,  269,  270,  271,  272,  276,
  122,  257,  124,  277,  278,  279,  280,  281,  282,  283,
  284,  285,  286,  257,  258,  289,  290,  291,  140,  276,
  142,  257,  258,  276,  257,  258,  276,  276,  276,  273,
  274,  275,  276,  276,  276,  276,  276,  273,  274,  275,
  273,  274,  275,  276,  288,  276,  276,  276,  276,  276,
  276,  287,  276,  276,  276,  276,  276,  257,  276,  276,
  276,  276,    0,  288,  276,    5,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 291
#define YYUNDFTOKEN 310
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
0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : ML",
"ML : arrays program",
"arrays : arrays array",
"arrays :",
"array : LEFT_PARAM ARRAY IDENTIFIER NUMBERS RIGHT_PARAM",
"program : program function",
"program : function",
"$$1 :",
"$$2 :",
"function : LEFT_PARAM DEFINE IDENTIFIER $$1 param_list $$2 expr RIGHT_PARAM",
"param_list : LEFT_PARAM RIGHT_PARAM",
"$$3 :",
"param_list : LEFT_PARAM $$3 id_list RIGHT_PARAM",
"id_list : id_list IDENTIFIER",
"id_list : IDENTIFIER",
"expr : NUMBERS",
"expr : IDENTIFIER",
"expr : IDENTIFIER LEFT_SQUARE expr RIGHT_SQUARE",
"expr : TRUE",
"expr : FALSE",
"expr : LEFT_PARAM IF expr expr expr RIGHT_PARAM",
"$$4 :",
"expr : LEFT_PARAM WHILE expr $$4 expr RIGHT_PARAM",
"$$5 :",
"$$6 :",
"expr : LEFT_PARAM IDENTIFIER $$5 actual_list $$6 RIGHT_PARAM",
"expr : LEFT_PARAM WRITE expr RIGHT_PARAM",
"expr : LEFT_PARAM WRITELN expr RIGHT_PARAM",
"expr : LEFT_PARAM READ RIGHT_PARAM",
"expr : LEFT_PARAM LET LEFT_PARAM assign_list RIGHT_PARAM expr RIGHT_PARAM",
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
#line 339 "parser.y"
void yyerror(const char *s) {

 printf("error at line %d %s unexpected symbol %s\n",yylineno,s,yytext);

}
#line 351 "y.tab.c"

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
#line 62 "parser.y"
	{
                        if(strcmp(yystack.l_mark[0].sym.variable,"main")!=0)
                        printf("Error at line %d: The last function must be main\n",yylineno);
                        super_scope.parent=NULL;
                        init_table(super_scope.table);

}
break;
case 4:
#line 74 "parser.y"
	{
                                                          add_to_table(super_scope.table,yystack.l_mark[-2].string,yystack.l_mark[-1].number,"array");

                                                        }
break;
case 5:
#line 79 "parser.y"
	{
                              strcpy(yyval.sym.variable,yystack.l_mark[0].sym.variable);
                              scope_stack_head++;
                              stack_scope_init(&scope_stack[scope_stack_head],&super_scope);
                              init_table(scope_stack[scope_stack_head].table);

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
#line 94 "parser.y"
	{
                                          add_to_table(super_scope.table,yystack.l_mark[0].string,0,"function");
                                          set_func_return_type(yystack.l_mark[0].string,"integer");
                                          }
break;
case 8:
#line 98 "parser.y"
	{
                                          set_func_param_number(yystack.l_mark[-2].string,yystack.l_mark[0].number);
                                         }
break;
case 9:
#line 101 "parser.y"
	{
                                                strcpy(yyval.sym.variable,yystack.l_mark[-5].string);
                                                set_func_return_type(yystack.l_mark[-5].string,yystack.l_mark[-1].sym.type);
                                                scope_stack_head--;
                                                }
break;
case 10:
#line 108 "parser.y"
	{
                                  yyval.number=0;
                                  }
break;
case 11:
#line 111 "parser.y"
	{
                    func_param_counter=0;
                    }
break;
case 12:
#line 114 "parser.y"
	{
                              yyval.number=func_param_counter;
                            }
break;
case 13:
#line 118 "parser.y"
	{

                              func_param_counter++;
                              add_to_table(scope_stack[scope_stack_head].table,yystack.l_mark[0].string,0,"integer");

                              }
break;
case 14:
#line 124 "parser.y"
	{

                  func_param_counter++;add_to_table(scope_stack[scope_stack_head].table,yystack.l_mark[0].string,0,"integer");

                  }
break;
case 15:
#line 131 "parser.y"
	{
yyval.sym.val=yystack.l_mark[0].number;strcpy(yyval.sym.type,"integer");
                  }
break;
case 16:
#line 134 "parser.y"
	{
                  if(get_value(&scope_stack[scope_stack_head],yystack.l_mark[0].string)==-1)
                  {
                  printf("error at line %d: variable %s not defined to avoid cascading errors creating a symbol with name %s and type %s\n",yylineno,yystack.l_mark[0].string,yystack.l_mark[0].string, required_type_on_error);
                  if(strcmp(required_type_on_error,"integer")==0)
                  add_to_table(scope_stack[scope_stack_head].table,yystack.l_mark[0].string,0,"integer");
                  if(strcmp(required_type_on_error,"bool")==0)
                  add_to_table(scope_stack[scope_stack_head].table,yystack.l_mark[0].string,0,"bool");
                  if(strcmp(required_type_on_error,"function")==0)
                  add_to_table(scope_stack[scope_stack_head].table,yystack.l_mark[0].string,0,"function");

                  }
                  if(strcmp(get_type(&scope_stack[scope_stack_head],yystack.l_mark[0].string),"function")==0)
                  {strcpy(yyval.sym.type,get_func_return_type(yystack.l_mark[0].string));}
                  else
                  strcpy(yyval.sym.type,get_type(&scope_stack[scope_stack_head],yystack.l_mark[0].string));
                  }
break;
case 17:
#line 151 "parser.y"
	{
                            if(get_value(&super_scope,yystack.l_mark[-3].string)==-1)
                            printf("error at line %d: array %s not defined\n",yylineno,yystack.l_mark[-3].string);
                            strcpy(yyval.sym.type,"integer");
                            check_if_symbol("array index ",yystack.l_mark[-1].sym.type,"integer");
                  }
break;
case 18:
#line 157 "parser.y"
	{
strcpy(yyval.sym.type,"bool");yyval.sym.val=1;
            }
break;
case 19:
#line 160 "parser.y"
	{
strcpy(yyval.sym.type,"bool");yyval.sym.val=0;
            }
break;
case 20:
#line 163 "parser.y"
	{
                                                  check_for_if_statement(yystack.l_mark[-3].sym.type,yystack.l_mark[-2].sym.type,yystack.l_mark[-1].sym.type);
                                                  strcpy(yyval.sym.type,yystack.l_mark[-2].sym.type);yyval.sym.val=yystack.l_mark[-2].sym.val;
                                               }
break;
case 21:
#line 167 "parser.y"
	{check_if_symbol("while ",yystack.l_mark[0].sym.type, "bool");}
break;
case 22:
#line 167 "parser.y"
	{
                                                strcpy(yyval.sym.type,yystack.l_mark[-1].sym.type);yyval.sym.val=yystack.l_mark[-1].sym.val;
                                             }
break;
case 23:
#line 170 "parser.y"
	{
                            if(get_value(&super_scope,yystack.l_mark[0].string)==-1)
                            printf("error at line %d function %s is not defined\n",yylineno,yystack.l_mark[0].string);
                            func_call_param_counter=0;
                            }
break;
case 24:
#line 175 "parser.y"
	{
                    if(get_func_param_number(yystack.l_mark[-2].string)!=yystack.l_mark[0].number)
                    if(get_value(&super_scope,yystack.l_mark[-2].string)!=-1)
                    printf("error at line %d: %s function requires %d parameters given %d\n",yylineno,yystack.l_mark[-2].string,get_func_param_number(yystack.l_mark[-2].string),yystack.l_mark[0].number);
                  }
break;
case 25:
#line 180 "parser.y"
	{
                    strcpy(yyval.sym.type,get_func_return_type(yystack.l_mark[-4].string));
                    strcpy(yyval.sym.variable,yystack.l_mark[-4].string);
                  }
break;
case 26:
#line 184 "parser.y"
	{
                                      check_if_symbol("write ",yystack.l_mark[-1].sym.type, "integer");
                                      yyval.sym.val=yystack.l_mark[-1].sym.val;strcpy(yyval.sym.type,"integer");
                                        }
break;
case 27:
#line 188 "parser.y"
	{
                                        check_if_symbol("writeln ",yystack.l_mark[-1].sym.type, "integer");
                                        yyval.sym.val=yystack.l_mark[-1].sym.val;strcpy(yyval.sym.type,"integer");
                                        }
break;
case 28:
#line 192 "parser.y"
	{
                                    strcpy(yyval.sym.type,"integer");
                                    }
break;
case 29:
#line 195 "parser.y"
	{
                                        strcpy(yyval.sym.type,yystack.l_mark[-1].sym.type);yyval.sym.val=yystack.l_mark[-1].sym.val;
                                        scope_stack_head--;
                                        }
break;
case 30:
#line 199 "parser.y"
	{
                                        strcpy(yyval.sym.type,yystack.l_mark[-1].sym.type);
                                        yyval.sym.val=yystack.l_mark[-1].sym.val;
                                        check_if_symbol("set command",yystack.l_mark[-1].sym.type,get_type(&scope_stack[scope_stack_head],yystack.l_mark[-2].string));
                                        }
break;
case 31:
#line 204 "parser.y"
	{
                                        check_if_symbol("Array index ",yystack.l_mark[-3].sym.type,"integer");
                                        strcpy(yyval.sym.type,yystack.l_mark[-1].sym.type);yyval.sym.val=yystack.l_mark[-1].sym.val;
                                        check_if_symbol("Array ",yystack.l_mark[-1].sym.type,get_type(&scope_stack[scope_stack_head],yystack.l_mark[-5].string));
                                        }
break;
case 32:
#line 209 "parser.y"
	{

                                        check_if_symbol("add operator ",yystack.l_mark[-2].sym.type,"integer");

                                        check_if_symbol("add operator ",yystack.l_mark[-1].sym.type,"integer");
                                        strcpy(yyval.sym.type,"integer");
                                        yyval.sym.val=yystack.l_mark[-2].sym.val+yystack.l_mark[-1].sym.val;
}
break;
case 33:
#line 217 "parser.y"
	{
                                        check_if_symbol("subtract operator ",yystack.l_mark[-2].sym.type,"integer");
                                        check_if_symbol("subtract operator ",yystack.l_mark[-1].sym.type,"integer");
                                        strcpy(yyval.sym.type,"integer");
                                        yyval.sym.val=yystack.l_mark[-2].sym.val-yystack.l_mark[-1].sym.val;
}
break;
case 34:
#line 223 "parser.y"
	{
                                        check_if_symbol("Multiply operator ",yystack.l_mark[-2].sym.type,"integer");
                                        check_if_symbol("Multiply operator ",yystack.l_mark[-1].sym.type,"integer");
                                        strcpy(yyval.sym.type,"integer");
                                        yyval.sym.val=yystack.l_mark[-2].sym.val*yystack.l_mark[-1].sym.val;
}
break;
case 35:
#line 229 "parser.y"
	{
                                        check_if_symbol("Division operator ",yystack.l_mark[-2].sym.type,"integer");
                                        check_if_symbol("Division operator ",yystack.l_mark[-1].sym.type,"integer");
                                        strcpy(yyval.sym.type,"integer");
                                        yyval.sym.val=yystack.l_mark[-2].sym.val/yystack.l_mark[-1].sym.val;
}
break;
case 36:
#line 235 "parser.y"
	{
                                        check_if_symbol("Greater than operator ",yystack.l_mark[-2].sym.type,"integer");
                                        check_if_symbol("Greater than ",yystack.l_mark[-1].sym.type,"integer");
                                        strcpy(yyval.sym.type,"bool");
                                        yyval.sym.val=yystack.l_mark[-2].sym.val>yystack.l_mark[-1].sym.val;
}
break;
case 37:
#line 241 "parser.y"
	{
                                        check_if_symbol("Greater than or equal to operator ",yystack.l_mark[-2].sym.type,"integer");
                                        check_if_symbol("Greater than or equal to operator ",yystack.l_mark[-1].sym.type,"integer");
                                        strcpy(yyval.sym.type,"bool");
                                        yyval.sym.val=yystack.l_mark[-2].sym.val>=yystack.l_mark[-1].sym.val;
}
break;
case 38:
#line 247 "parser.y"
	{
                                        check_if_symbol("less than operator ",yystack.l_mark[-2].sym.type,"integer");
                                        check_if_symbol("less than operator ",yystack.l_mark[-1].sym.type,"integer");
                                        strcpy(yyval.sym.type,"bool");
                                        yyval.sym.val=yystack.l_mark[-2].sym.val<yystack.l_mark[-1].sym.val;
}
break;
case 39:
#line 253 "parser.y"
	{
                                        check_if_symbol("less than or equal to operator ",yystack.l_mark[-2].sym.type,"integer");
                                        check_if_symbol("less than or equal to operator ",yystack.l_mark[-1].sym.type,"integer");
                                        strcpy(yyval.sym.type,"bool");
                                        yyval.sym.val=yystack.l_mark[-2].sym.val<=yystack.l_mark[-1].sym.val;
}
break;
case 40:
#line 259 "parser.y"
	{
                                        check_if_symbol("equal to operator ",yystack.l_mark[-2].sym.type,"integer");
                                        check_if_symbol("equal to operator ",yystack.l_mark[-1].sym.type,"integer");
                                        strcpy(yyval.sym.type,"bool");
                                        yyval.sym.val=yystack.l_mark[-2].sym.val==yystack.l_mark[-1].sym.val;
}
break;
case 41:
#line 265 "parser.y"
	{
                                        check_if_symbol("not equal to operator ",yystack.l_mark[-2].sym.type,"integer");
                                        check_if_symbol("not equal to operator ",yystack.l_mark[-1].sym.type,"integer");
                                        strcpy(yyval.sym.type,"bool");
                                        yyval.sym.val=yystack.l_mark[-2].sym.val!=yystack.l_mark[-1].sym.val;
}
break;
case 42:
#line 271 "parser.y"
	{
                                        check_if_symbol("negation operator ",yystack.l_mark[-1].sym.type,"integer");
                                        yyval.sym.val=0-yystack.l_mark[-1].sym.val;strcpy(yyval.sym.type,"integer");
}
break;
case 43:
#line 275 "parser.y"
	{
                                        check_if_symbol("AND operator ",yystack.l_mark[-2].sym.type,"bool");

                                        check_if_symbol("AND operator ",yystack.l_mark[-1].sym.type,"bool");
                                        strcpy(yyval.sym.type,"bool");
                                        yyval.sym.val=yystack.l_mark[-2].sym.val&&yystack.l_mark[-1].sym.val;
}
break;
case 44:
#line 282 "parser.y"
	{
                                        check_if_symbol("& operator ",yystack.l_mark[-2].sym.type,"bool");
                                        check_if_symbol("& operator ",yystack.l_mark[-1].sym.type,"bool");
                                        strcpy(yyval.sym.type,"bool");
                                        yyval.sym.val=yystack.l_mark[-2].sym.val&&yystack.l_mark[-1].sym.val;
}
break;
case 45:
#line 288 "parser.y"
	{
                                        check_if_symbol("OR operator",yystack.l_mark[-2].sym.type,"bool");
                                        check_if_symbol("OR operator",yystack.l_mark[-1].sym.type,"bool");
                                        strcpy(yyval.sym.type,"bool");
                                        yyval.sym.val=yystack.l_mark[-2].sym.val||yystack.l_mark[-1].sym.val;
}
break;
case 46:
#line 294 "parser.y"
	{
                                        check_if_symbol("| symbol ",yystack.l_mark[-2].sym.type,"bool");
                                        check_if_symbol("| symbol ",yystack.l_mark[-1].sym.type,"bool");
                                        strcpy(yyval.sym.type,"bool");
                                        yyval.sym.val=yystack.l_mark[-2].sym.val||yystack.l_mark[-1].sym.val;
}
break;
case 47:
#line 300 "parser.y"
	{
                                        check_if_symbol("NOT operator",yystack.l_mark[-1].sym.type,"bool");
                                        yyval.sym.val=!yystack.l_mark[-1].sym.val;strcpy(yyval.sym.type,"bool");
}
break;
case 48:
#line 304 "parser.y"
	{
                                        check_if_symbol("! symbol",yystack.l_mark[-1].sym.type,"bool");
                                        yyval.sym.val=!yystack.l_mark[-1].sym.val;strcpy(yyval.sym.type,"bool");
}
break;
case 49:
#line 308 "parser.y"
	{
                                        strcpy(yyval.sym.type,yystack.l_mark[-1].sym.type);
                                        yyval.sym.val=yystack.l_mark[-1].sym.val;
}
break;
case 50:
#line 313 "parser.y"
	{
                                        yyval.number++;
                                        check_if_symbol("function parameters ",yystack.l_mark[0].sym.type,"integer");
}
break;
case 51:
#line 317 "parser.y"
	{
                                        func_call_param_counter=yyval.number;
                                        yyval.number=0;
}
break;
case 52:
#line 322 "parser.y"
	{
                                        add_to_table(scope_stack[scope_stack_head].table,yystack.l_mark[-2].string,yystack.l_mark[-1].sym.val,"integer");
}
break;
case 53:
#line 325 "parser.y"
	{
                                        add_to_table(scope_stack[scope_stack_head].table,yystack.l_mark[-2].string,yystack.l_mark[-1].sym.val,"integer");
}
break;
case 54:
#line 329 "parser.y"
	{
                                        strcpy(yyval.sym.type,yystack.l_mark[0].sym.type);
                                        yyval.sym.val=yystack.l_mark[0].sym.val;
}
break;
case 55:
#line 333 "parser.y"
	{
                strcpy(yyval.sym.type,yystack.l_mark[0].sym.type);
                yyval.sym.val=yystack.l_mark[0].sym.val;
          }
break;
#line 970 "y.tab.c"
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
