/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    BYTE = 258,                    /* BYTE  */
    SHORT = 259,                   /* SHORT  */
    INT = 260,                     /* INT  */
    LONG = 261,                    /* LONG  */
    CHAR = 262,                    /* CHAR  */
    ELSE = 263,                    /* ELSE  */
    CATCH = 264,                   /* CATCH  */
    FINALLY = 265,                 /* FINALLY  */
    INTERFACE = 266,               /* INTERFACE  */
    PLUS = 267,                    /* PLUS  */
    FORWARDSLASH = 268,            /* FORWARDSLASH  */
    MODULO = 269,                  /* MODULO  */
    IF = 270,                      /* IF  */
    SWITCH = 271,                  /* SWITCH  */
    IntegerLiteral = 272,          /* IntegerLiteral  */
    FloatingPointLiteral = 273,    /* FloatingPointLiteral  */
    BooleanLiteral = 274,          /* BooleanLiteral  */
    CharacterLiteral = 275,        /* CharacterLiteral  */
    StringLiteral = 276,           /* StringLiteral  */
    NullLiteral = 277,             /* NullLiteral  */
    FLOAT = 278,                   /* FLOAT  */
    DOUBLE = 279,                  /* DOUBLE  */
    BOOLEAN = 280,                 /* BOOLEAN  */
    CASE = 281,                    /* CASE  */
    DEFAULT = 282,                 /* DEFAULT  */
    DO = 283,                      /* DO  */
    WHILE = 284,                   /* WHILE  */
    OPENANGULARBRACKET = 285,      /* OPENANGULARBRACKET  */
    CLOSEANGULARBRACKET = 286,     /* CLOSEANGULARBRACKET  */
    OPENBRACKET = 287,             /* OPENBRACKET  */
    CLOSEBRACKET = 288,            /* CLOSEBRACKET  */
    OPENCURLYBRACKET = 289,        /* OPENCURLYBRACKET  */
    CLOSECURLYBRACKET = 290,       /* CLOSECURLYBRACKET  */
    OPENSQUAREBRACKET = 291,       /* OPENSQUAREBRACKET  */
    CLOSESQUAREBRACKET = 292,      /* CLOSESQUAREBRACKET  */
    EQUAL = 293,                   /* EQUAL  */
    STAREQUAL = 294,               /* STAREQUAL  */
    FORWARDSLASHEQUAL = 295,       /* FORWARDSLASHEQUAL  */
    PLUSEQUAL = 296,               /* PLUSEQUAL  */
    MINUSEQUAL = 297,              /* MINUSEQUAL  */
    OPENANGULARBRACKETOPENANGULARBRACKETEQUAL = 298, /* OPENANGULARBRACKETOPENANGULARBRACKETEQUAL  */
    CLOSEANGULARBRACKETCLOSEANGULARBRACKETEQUAL = 299, /* CLOSEANGULARBRACKETCLOSEANGULARBRACKETEQUAL  */
    CLOSEANGULARBRACKETCLOSEANGULARBRACKETCLOSEANGULARBRACKETEQUAL = 300, /* CLOSEANGULARBRACKETCLOSEANGULARBRACKETCLOSEANGULARBRACKETEQUAL  */
    ANDEQUAL = 301,                /* ANDEQUAL  */
    XOREQUAL = 302,                /* XOREQUAL  */
    OREQUAL = 303,                 /* OREQUAL  */
    DOT = 304,                     /* DOT  */
    COMMA = 305,                   /* COMMA  */
    SEMICOLON = 306,               /* SEMICOLON  */
    COLON = 307,                   /* COLON  */
    INSTANCEOF = 308,              /* INSTANCEOF  */
    Identifier = 309,              /* Identifier  */
    PUBLIC = 310,                  /* PUBLIC  */
    PROTECTED = 311,               /* PROTECTED  */
    PRIVATE = 312,                 /* PRIVATE  */
    STATIC = 313,                  /* STATIC  */
    ABSTRACT = 314,                /* ABSTRACT  */
    FINAL = 315,                   /* FINAL  */
    NATIVE = 316,                  /* NATIVE  */
    SYNCHRONIZED = 317,            /* SYNCHRONIZED  */
    TRANSIENT = 318,               /* TRANSIENT  */
    VOLATILE = 319,                /* VOLATILE  */
    PACKAGE = 320,                 /* PACKAGE  */
    IMPORT = 321,                  /* IMPORT  */
    STAR = 322,                    /* STAR  */
    CLASS = 323,                   /* CLASS  */
    EXTENDS = 324,                 /* EXTENDS  */
    IMPLEMENTS = 325,              /* IMPLEMENTS  */
    VOID = 326,                    /* VOID  */
    THIS = 327,                    /* THIS  */
    SUPER = 328,                   /* SUPER  */
    BREAK = 329,                   /* BREAK  */
    RETURN = 330,                  /* RETURN  */
    FOR = 331,                     /* FOR  */
    TRY = 332,                     /* TRY  */
    THROWS = 333,                  /* THROWS  */
    THROW = 334,                   /* THROW  */
    CONTINUE = 335,                /* CONTINUE  */
    NEW = 336,                     /* NEW  */
    PLUSPLUS = 337,                /* PLUSPLUS  */
    MINUSMINUS = 338,              /* MINUSMINUS  */
    TILDA = 339,                   /* TILDA  */
    NOT = 340,                     /* NOT  */
    AND = 341,                     /* AND  */
    OR = 342,                      /* OR  */
    OROR = 343,                    /* OROR  */
    ANDAND = 344,                  /* ANDAND  */
    NOTEQUAL = 345,                /* NOTEQUAL  */
    MINUS = 346,                   /* MINUS  */
    OPENANGULARBRACKETOPENANGULARBRACKET = 347, /* OPENANGULARBRACKETOPENANGULARBRACKET  */
    CLOSEANGULARBRACKETCLOSEANGULARBRACKET = 348, /* CLOSEANGULARBRACKETCLOSEANGULARBRACKET  */
    CLOSEANGULARBRACKETCLOSEANGULARBRACKETCLOSEANGULARBRACKET = 349, /* CLOSEANGULARBRACKETCLOSEANGULARBRACKETCLOSEANGULARBRACKET  */
    QUESTION = 350,                /* QUESTION  */
    XOR = 351,                     /* XOR  */
    EQUALEQUAL = 352,              /* EQUALEQUAL  */
    OPENANGULARBRACKETEQUAL = 353, /* OPENANGULARBRACKETEQUAL  */
    CLOSEANGULARBRACKETEQUAL = 354 /* CLOSEANGULARBRACKETEQUAL  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 660 "parser.y"

  struct {
    int n;
    char str[1000];
  } lex;
    struct {
        int cnt;
        int sz;
        int ndim;
        int nelem;
        char argstring[10000];
        char arrtype[1000];
        char type[1000];
        char tempvar[1000];
        char gotoname[1000];
        char nextgoto[1000];
        char nextgoto1[1000];
        char nextgoto2[1000];
        char arraystore[1000];
    } typ;

#line 185 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
