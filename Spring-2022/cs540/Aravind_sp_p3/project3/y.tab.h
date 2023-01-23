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
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union
{

        int number;
        char *string;
        symbol sym;

} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;
