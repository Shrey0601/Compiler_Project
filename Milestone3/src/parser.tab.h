/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    BYTE = 258,
    SHORT = 259,
    INT = 260,
    LONG = 261,
    CHAR = 262,
    ELSE = 263,
    CATCH = 264,
    FINALLY = 265,
    INTERFACE = 266,
    PLUS = 267,
    FORWARDSLASH = 268,
    MODULO = 269,
    IF = 270,
    SWITCH = 271,
    IntegerLiteral = 272,
    FloatingPointLiteral = 273,
    BooleanLiteral = 274,
    CharacterLiteral = 275,
    StringLiteral = 276,
    NullLiteral = 277,
    FLOAT = 278,
    DOUBLE = 279,
    BOOLEAN = 280,
    CASE = 281,
    DEFAULT = 282,
    DO = 283,
    WHILE = 284,
    OPENANGULARBRACKET = 285,
    CLOSEANGULARBRACKET = 286,
    OPENBRACKET = 287,
    CLOSEBRACKET = 288,
    OPENCURLYBRACKET = 289,
    CLOSECURLYBRACKET = 290,
    OPENSQUAREBRACKET = 291,
    CLOSESQUAREBRACKET = 292,
    EQUAL = 293,
    STAREQUAL = 294,
    FORWARDSLASHEQUAL = 295,
    PLUSEQUAL = 296,
    MINUSEQUAL = 297,
    OPENANGULARBRACKETOPENANGULARBRACKETEQUAL = 298,
    CLOSEANGULARBRACKETCLOSEANGULARBRACKETEQUAL = 299,
    CLOSEANGULARBRACKETCLOSEANGULARBRACKETCLOSEANGULARBRACKETEQUAL = 300,
    ANDEQUAL = 301,
    XOREQUAL = 302,
    OREQUAL = 303,
    DOT = 304,
    COMMA = 305,
    SEMICOLON = 306,
    COLON = 307,
    INSTANCEOF = 308,
    Identifier = 309,
    PUBLIC = 310,
    PROTECTED = 311,
    PRIVATE = 312,
    STATIC = 313,
    ABSTRACT = 314,
    FINAL = 315,
    NATIVE = 316,
    SYNCHRONIZED = 317,
    TRANSIENT = 318,
    VOLATILE = 319,
    PACKAGE = 320,
    IMPORT = 321,
    STAR = 322,
    CLASS = 323,
    EXTENDS = 324,
    IMPLEMENTS = 325,
    VOID = 326,
    THIS = 327,
    SUPER = 328,
    BREAK = 329,
    RETURN = 330,
    FOR = 331,
    TRY = 332,
    THROWS = 333,
    THROW = 334,
    CONTINUE = 335,
    NEW = 336,
    PLUSPLUS = 337,
    MINUSMINUS = 338,
    TILDA = 339,
    NOT = 340,
    AND = 341,
    OR = 342,
    OROR = 343,
    ANDAND = 344,
    NOTEQUAL = 345,
    MINUS = 346,
    OPENANGULARBRACKETOPENANGULARBRACKET = 347,
    CLOSEANGULARBRACKETCLOSEANGULARBRACKET = 348,
    CLOSEANGULARBRACKETCLOSEANGULARBRACKETCLOSEANGULARBRACKET = 349,
    QUESTION = 350,
    XOR = 351,
    EQUALEQUAL = 352,
    OPENANGULARBRACKETEQUAL = 353,
    CLOSEANGULARBRACKETEQUAL = 354
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 579 "parser.y"

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

#line 179 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
