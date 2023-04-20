/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

    #include<bits/stdc++.h>
    #include <fstream>
    using namespace std;
    extern FILE* yyin;
    void yyerror(const char * s);
    int yylex();
    int nelem=0;
    int isvoid;
    int isimport=0;
    int issystem=0;
    int isfinal=0;
    int isreturn =0;
    string fullname;
    string classname;
    int isclassaccess=0;
    int ismainstatic=0;
    map<int,vector<int>> shape;
    int isaccess=0;
    int isprivate=0;
    int isstatic=0;
    int isfieldprivate=0;
    string curr_class="";
    int arraccess=0;
    int arrinit=0;
    string arrtype="null";
    int arrflag=0;
    int inloop=0;
    string functype;
    int infunction=0;
    string casttype="";
    int flagyo;
    int ndim=0;
    extern int yylineno;
    int parse_count = 0;
    string constpass;
    
    #define YYERROR_VERBOSE 1

    int nodes = 0;
    map<int, string> node_names;
    vector<pair<int,string>> parents, child;
    string s;
    
    vector<string> ops = {"=",">","<","!","~","?",":","->","==",">=","<=","!=","&&","++","--","+","-","*","/","&",",","^","%","<<",">>",">>>","+=","-=","*=","/=","&=",",=","^=","%=","<<=",">>=",">>>=","||"};
    vector<string> keywords = {"abstract","continue","for","new","switch","assert","default","if","package","synchronized","boolean","do","goto","private","this","break","double","implements","protected","throw","byte","else","import","public","throws","case","enum","instanceof","return","transient","catch","extends","int","SHORT","try","char","final","interface","static","void","class","finally","long","strictfp","volatile","const","float","native","super","while","_","exports","opens","requires","uses","module","permits","sealed","var","non-sealed","provides","to","with","open","record","transitive","yield"};
    vector<string> sep = {"(",")","{","}",",","[","]",";",".","...","::"};
    vector<string> dtype = {"char","byte","short","int","long","float","double","invalid"};
    int getsize(string s)
    {
      if(s=="char")
      return 1;
      else if(s=="byte")
      return 1;
      else if(s=="short")
      return 2;
      else if(s=="int")
      return 4;
      else if(s=="long")
      return 8;
      else if(s=="float")
      return 4;
      else if(s=="double")
      return 8;
      else
      return 0;
    }
    void print_shape(map<int,vector<int>> shape)
    {
      for(auto it=shape.begin();it!=shape.end();it++)
      {
        vector<int> v=it->second;
        cout<<"Dim "<<it->first<<":\n";
        for(auto yo:v)
        {
          cout<<yo<<' ';
        }
        cout<<endl;
      }
      cout<<endl<<endl;
    }
    int invalidoperator(string s,int flag){
      int x;
      if(flag)
      {
        x=5;
      }
      else x=7;

        for(int i=0;i<x;i++){
            if(s==dtype[i])
                return 0;
        }
        return 1;
      // return 0;
    }
    string getorder(string a,string b, int flag)
    {
      int size;
      if(flag==0)
      size=5;
      else
      size=7;
      if(a==b)
      return a;
      else
      {
        int q=7,w=7;
        for(int i=0;i<size;i++)
        {
          if(a==dtype[i])
          q=i;      
        }
        for(int i=0;i<size;i++)
        {
          if(b==dtype[i])
          w=i;      
        }
        if((q==0&&w<5)||(q<5&&w==0))
        {
          return dtype[0];
        }
        if(q>w)
        return dtype[q];
        else
        return dtype[w];
      }

    }
    bool boolgetorder(string a,string b, int flag)
    {
      if(!strcmp(a.c_str(),"String")&&!strcmp(b.c_str(),"string"))
      {
        return 1;
      }
      else if(!strcmp(b.c_str(),"String")&&!strcmp(a.c_str(),"string"))
      {
        return 1;
      }
      int size;
      if(flag==0)
      size=5;
      else
      size=7;

      int q=7,w=7;
      for(int i=0;i<size;i++)
      {
        if(a==dtype[i])
        q=i;      
      }
      for(int i=0;i<size;i++)
      {
        if(b==dtype[i])
        w=i;      
      }
      if(q==7||w==7){return false;}
      if(q>=w || (q==0 && w<=4))
      return true;
      else
      return false;
      

    }
    class Sym_Entry {
      public:
        string token;
        string type;
        int offset;
        string scope_name;
        int line;
        string rtype;
        int narg;
        int argno;
        int isfieldprivate;
        int isitstatic;
        int isitfinal;
        map<int,vector<int>> arrshape;
        Sym_Entry(){ 
        }
        Sym_Entry(string toke, string typ, int offse, string scope_nam, int lin, int argn){
          token = toke;
          type = typ;
          offset = offse;
          scope_name = scope_nam;
          line = lin;
          narg=nelem;
          nelem=0;
          argno = argn;
          isfieldprivate=0;
          arrshape=shape;
          isitstatic=isstatic;
          isitfinal=isfinal;
          if(!strcmp(toke.c_str(),"Constructor")) isitstatic=1;
          // isstatic=0;
          // shape.clear();
        }
        void print_entry(){
          cout << token << " " << type << " " << offset << " " << scope_name << " " << line << " "<<narg << " "<<argno<<" "<<isfieldprivate<<" "<<isitstatic<<endl;
        }
    };
    class Sym_Table {
      public:
        map<string, Sym_Entry> table;
        Sym_Table* parent;
        int level_no;
        void entry(string lexeme, string token, string type, int offset, string scope_name, int line, int argno){
          if(table.find(lexeme) != table.end()){
            
              cout << "Error: Redeclaration of " << lexeme << " at line " << line << endl;  // Redeclaration check done here
              exit(0);
            
          }
          table[lexeme] = Sym_Entry(token, type, offset, scope_name, line, argno);
          table[lexeme].isfieldprivate=isfieldprivate;
        }
        Sym_Table(){}
        Sym_Table(Sym_Table* child){
            if(!child){
              level_no = 0;
              parent = NULL;
            }
            else{
              level_no = child->level_no + 1;
              parent = child;
            }
        }
        Sym_Entry lookup(string lexeme){
          for(auto it=this; it!=NULL; it=it->parent){
            if(it->table.find(lexeme) != it->table.end()){
              return it->table[lexeme];
            }
          }
          return Sym_Entry("null", "null", -1, "null", -1, -2);
        }
        string thislookup(string lexeme){
          for(auto it=this; it!=NULL; it=it->parent){
            // cout<<it->table[lexeme].scope_name.substr(0,5).c_str()<<'\n';
            if((it->table.find(lexeme) != it->table.end())&&!strcmp(it->table[lexeme].scope_name.substr(0,5).c_str(),"Class")){
              return it->table[lexeme].type;
            }
          }
          return "null";
        }
        

        void print_table(){
          for(auto it=table.begin(); it!=table.end(); it++){
            cout<<it->first<<": ";
            it->second.print_entry();
          }
        }
    };
    int offset = 0;
    Sym_Table* curr_table = new Sym_Table(NULL);
    
    string curr_scope = "Global";
    stack<Sym_Table*> tables;
    stack<int> offsets;
    stack<string> scope_names;
    int size; 
    string type="";
    vector<Sym_Table*> list_of_Symbol_Tables(1, curr_table);
    int array_size = 0;
    vector< pair<string,pair<string,int>> > funcparam;
    int funcargno;
    int fl = 0;
    vector<string> objects;
    stack<string> controlflow;
    stack<pair<string, int>> args;
    int addoff = 0;
    stack<string> continuelabels;
    stack<string> breaklabels;


    Sym_Entry lookup1(string funcname, int argno){
          for(auto it: list_of_Symbol_Tables){
            auto tab = it->table;
            for(auto it1 = tab.begin(); it1 != tab.end(); it1++){
                if(it1->second.scope_name == funcname){
                    if(it1->second.argno == argno){
                        return it1->second;
                    }
                }
                else{
                    break;
                }
            }
          }
          return Sym_Entry("null", "null", -1, "null", -1, -2);
    }

     string checkobjentry(string lexeme, int argno, string checkscope){
            string var = lexeme.substr(lexeme.find('.')+1);
            string search_scope = "Method" + var;
            checkscope = "Class" + checkscope;
            for(auto it: list_of_Symbol_Tables){
              auto tab = it->table;
              for(auto it1 = tab.begin(); it1 != tab.end(); it1++){
                  if(it1->second.scope_name == search_scope && it1->second.argno == argno && it->parent->table.begin()->second.scope_name == checkscope){
                    //  cout<<it->parent->table.begin()->second.scope_name<<endl;
                    // cout<<it1->first<<" YO"<<endl;
                      return it1->second.type;
                  }
               }
              }
            
            return "null";
        }
        int checknarg(string lexeme, int argno, string checkscope){
            string var = lexeme.substr(lexeme.find('.')+1);
            string search_scope = "Method" + var;
            checkscope = "Class" + checkscope;
            for(auto it: list_of_Symbol_Tables){
              auto tab = it->table;
              for(auto it1 = tab.begin(); it1 != tab.end(); it1++){
                  if(it1->first == var && it1->second.scope_name == checkscope){
                    //  cout<<it->parent->table.begin()->second.scope_name<<endl;
                    // cout<<it1->first<<" YO"<<endl;
            
                      // cout<<"GTY"<<it1->second.narg<<'\n';
                      return it1->second.narg;
                  }
               }
              }
            
            return -1;
        }
    int checkclass(string lexeme){
        for(auto it: list_of_Symbol_Tables){
            auto tab = it->table;
            for(auto it1 = tab.begin(); it1 != tab.end(); it1++){
                if(it1->second.scope_name == "Class" + lexeme){
                    return 1;
                }
                else{
                    break;
                }
            }
        }
        return 0;
    }

    int checkobj(string lexeme){
      int dot = 0;
        for(auto it: lexeme){
            if(it == '.'){
                dot = 1;
                break;
            }
        }
        if(dot == 0){
          return 0;
        }
        else{
          int dot1= 0 ;
          string obj = lexeme.substr(0, lexeme.find('.'));
          string var = lexeme.substr(lexeme.find('.')+1);
          // cout<< obj <<" "<< var<<curr_table->lookup(obj).token.c_str()<<"\n";
          if(!strcmp(obj.c_str(),"null")) 
          {
            // cout<<"FUCK\n";
            return 0;
          }
  
          if(!strcmp(curr_table->lookup(obj).token.c_str(),"Class")||!strcmp(curr_table->lookup(obj).token.c_str(),"Constructor")){
              dot1 = 1;
          }

          // for(auto it: objects){
          //   if(it == obj){
          //     dot1 = 1;
          //     break;
          //   }
          // }
          if(dot1 == 0){
            return 0;
          }
          else{
            string classname = curr_table->lookup(obj).type;
            string search_scope = "Class" + classname;
            for(auto it: list_of_Symbol_Tables){
              auto tab = it->table;
              for(auto it1 = tab.begin(); it1 != tab.end(); it1++){
                  if(it1->second.scope_name == search_scope){
                      if(it1->first == var){
                        if(it1->second.isitstatic)
                          return 2;
                        else return 1;
                      }
                  }
                  else{
                      break;
                  }
              }
            }
            return 0;
          }
        }
    }
    string typeobj(string lexeme){
          string obj = lexeme.substr(0, lexeme.find('.'));
          string var = lexeme.substr(lexeme.find('.')+1);
          // cout<<"YOU"<<endl;
            string classname = curr_table->lookup(obj).type;
            string search_scope = "Class" + classname;
            for(auto it: list_of_Symbol_Tables){
              auto tab = it->table;
              for(auto it1 = tab.begin(); it1 != tab.end(); it1++){
                  if(it1->second.scope_name == search_scope){
                      if(it1->first == var){
                        if((it1->second.isfieldprivate)&&strcmp(it1->second.scope_name.c_str(),curr_class.c_str()))
                          return "private";
                        else return it1->second.type;
                      }
                  }
                  else{
                      break;
                  }
              }
            }
            return "null";
          }
   
    // Types Supported : Int, Float, Char, String

    // 3AC

    typedef struct quadruple{
        string op;
        string arg1;
        string arg2;
        string res;
        int idx;
    } quad;

    vector<quad> code; 

    long long counter = 0;
    long long counter1 = 0;

    void emit(string op, string arg1, string arg2, string res, int idx){
        quad temp;
        temp.op = op;
        temp.arg1 = arg1;
        temp.arg2 = arg2;
        temp.res = res;
        temp.idx = idx;
        if(idx == -1) temp.idx = code.size();
        code.push_back(temp);
    }

    string newtemp(){
      string temp_var = "t"+to_string(counter++);
      return temp_var;
    }
    string newLabel(){
      string temp_var = "L"+to_string(counter1++);
      return temp_var;
    }
// }

#line 533 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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
#line 466 "parser.y"

  struct {
    int n;
    char str[1000];
  } lex;
    struct {
        int cnt;
        int size;
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

#line 707 "parser.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  36
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   3337

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  100
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  180
/* YYNRULES -- Number of rules.  */
#define YYNRULES  395
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  652

#define YYUNDEFTOK  2
#define YYMAXUTOK   354


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   747,   747,   752,   757,   763,   768,   773,   778,   785,
     793,   820,   826,   833,   839,   846,   852,   858,   864,   870,
     877,   883,   890,   896,   903,   910,   917,   924,   931,   937,
     944,   950,   957,   994,  1033,  1035,  1037,  1039,  1041,  1043,
    1045,  1049,  1052,  1057,  1059,  1063,  1066,  1068,  1071,  1076,
    1079,  1082,  1085,  1088,  1091,  1093,  1096,  1098,  1100,  1104,
    1107,  1109,  1111,  1113,  1115,  1117,  1121,  1121,  1145,  1145,
    1181,  1181,  1216,  1216,  1239,  1239,  1262,  1262,  1298,  1298,
    1321,  1321,  1358,  1364,  1370,  1374,  1381,  1384,  1388,  1392,
    1398,  1402,  1405,  1410,  1414,  1419,  1464,  1504,  1535,  1612,
    1661,  1768,  1793,  1793,  1802,  1811,  1818,  1832,  1847,  1898,
    1949,  1996,  2042,  2086,  2129,  2176,  2220,  2231,  2242,  2246,
    2249,  2253,  2271,  2274,  2276,  2279,  2283,  2291,  2291,  2295,
    2302,  2309,  2315,  2322,  2327,  2370,  2370,  2390,  2397,  2403,
    2409,  2415,  2424,  2432,  2440,  2448,  2448,  2472,  2472,  2494,
    2494,  2512,  2512,  2534,  2539,  2546,  2551,  2558,  2562,  2568,
    2572,  2577,  2582,  2588,  2597,  2607,  2619,  2631,  2639,  2649,
    2655,  2661,  2665,  2671,  2675,  2680,  2685,  2693,  2751,  2755,
    2759,  2763,  2767,  2771,  2776,  2780,  2784,  2788,  2792,  2797,
    2801,  2805,  2809,  2813,  2817,  2821,  2825,  2829,  2833,  2837,
    2842,  2848,  2854,  2860,  2868,  2874,  2880,  2886,  2892,  2898,
    2905,  2911,  2924,  2936,  2943,  2955,  2963,  2975,  2988,  3000,
    3004,  3011,  3017,  3023,  3029,  3033,  3038,  3044,  3048,  3054,
    3060,  3065,  3082,  3092,  3102,  3111,  3128,  3138,  3147,  3160,
    3166,  3172,  3188,  3201,  3214,  3223,  3239,  3252,  3265,  3281,
    3291,  3301,  3317,  3327,  3338,  3349,  3360,  3371,  3382,  3393,
    3404,  3415,  3428,  3439,  3450,  3461,  3472,  3483,  3494,  3505,
    3517,  3519,  3523,  3527,  3529,  3533,  3545,  3561,  3575,  3588,
    3597,  3626,  3632,  3635,  3637,  3639,  3642,  3644,  3647,  3647,
    3664,  3667,  3675,  3682,  3687,  3691,  3698,  3703,  3710,  3717,
    3724,  3806,  3831,  3837,  3846,  3859,  3875,  3890,  3906,  3910,
    3915,  3923,  3929,  3935,  3947,  3954,  3962,  4094,  4131,  4164,
    4177,  4210,  4225,  4286,  4345,  4351,  4362,  4367,  4374,  4407,
    4440,  4446,  4451,  4463,  4472,  4480,  4513,  4543,  4547,  4559,
    4571,  4577,  4603,  4626,  4649,  4681,  4693,  4838,  4981,  5124,
    5130,  5274,  5418,  5425,  5444,  5465,  5483,  5489,  5518,  5548,
    5577,  5608,  5613,  5620,  5651,  5683,  5690,  5698,  5705,  5713,
    5719,  5727,  5733,  5742,  5748,  5754,  5760,  5764,  5770,  5776,
    5889,  5901,  5907,  5916,  5921,  5925,  5929,  5933,  5937,  5941,
    5945,  5949,  5953,  5957,  5962,  5973
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "BYTE", "SHORT", "INT", "LONG", "CHAR",
  "ELSE", "CATCH", "FINALLY", "INTERFACE", "PLUS", "FORWARDSLASH",
  "MODULO", "IF", "SWITCH", "IntegerLiteral", "FloatingPointLiteral",
  "BooleanLiteral", "CharacterLiteral", "StringLiteral", "NullLiteral",
  "FLOAT", "DOUBLE", "BOOLEAN", "CASE", "DEFAULT", "DO", "WHILE",
  "OPENANGULARBRACKET", "CLOSEANGULARBRACKET", "OPENBRACKET",
  "CLOSEBRACKET", "OPENCURLYBRACKET", "CLOSECURLYBRACKET",
  "OPENSQUAREBRACKET", "CLOSESQUAREBRACKET", "EQUAL", "STAREQUAL",
  "FORWARDSLASHEQUAL", "PLUSEQUAL", "MINUSEQUAL",
  "OPENANGULARBRACKETOPENANGULARBRACKETEQUAL",
  "CLOSEANGULARBRACKETCLOSEANGULARBRACKETEQUAL",
  "CLOSEANGULARBRACKETCLOSEANGULARBRACKETCLOSEANGULARBRACKETEQUAL",
  "ANDEQUAL", "XOREQUAL", "OREQUAL", "DOT", "COMMA", "SEMICOLON", "COLON",
  "INSTANCEOF", "Identifier", "PUBLIC", "PROTECTED", "PRIVATE", "STATIC",
  "ABSTRACT", "FINAL", "NATIVE", "SYNCHRONIZED", "TRANSIENT", "VOLATILE",
  "PACKAGE", "IMPORT", "STAR", "CLASS", "EXTENDS", "IMPLEMENTS", "VOID",
  "THIS", "SUPER", "BREAK", "RETURN", "FOR", "TRY", "THROWS", "THROW",
  "CONTINUE", "NEW", "PLUSPLUS", "MINUSMINUS", "TILDA", "NOT", "AND", "OR",
  "OROR", "ANDAND", "NOTEQUAL", "MINUS",
  "OPENANGULARBRACKETOPENANGULARBRACKET",
  "CLOSEANGULARBRACKETCLOSEANGULARBRACKET",
  "CLOSEANGULARBRACKETCLOSEANGULARBRACKETCLOSEANGULARBRACKET", "QUESTION",
  "XOR", "EQUALEQUAL", "OPENANGULARBRACKETEQUAL",
  "CLOSEANGULARBRACKETEQUAL", "$accept", "Goal", "Literal", "Type",
  "PrimitiveType", "NumericType", "IntegralType", "FloatingPointType",
  "ReferenceType", "ClassOrInterfaceType", "ClassType", "InterfaceType",
  "ArrayType", "Name", "SimpleName", "QualifiedName", "CompilationUnit",
  "ImportDeclarations", "TypeDeclarations", "PackageDeclaration",
  "ImportDeclaration", "DummyImport", "SingleTypeImportDeclaration",
  "TypeImportOnDemandDeclaration", "TypeDeclaration", "Modifiers",
  "Modifier", "ClassDeclaration", "$@1", "$@2", "$@3", "$@4", "$@5", "$@6",
  "$@7", "$@8", "Super", "Interfaces", "InterfaceTypeList", "ClassBody",
  "ClassBodyDeclarations", "ClassBodyDeclaration",
  "ClassMemberDeclaration", "FieldDeclaration", "VariableDeclarators",
  "VariableDeclarator", "VariableDeclaratorId", "$@9",
  "VariableInitializer", "MethodDeclaration", "MethodHeader",
  "MethodDeclarator", "FormalParameterList", "FormalParameter", "Throws",
  "ClassTypeList", "MethodBody", "StaticInitializer", "$@10",
  "ConstructorDeclaration", "ConstructorHeader", "ConstructorDeclarator",
  "$@11", "ConstructorBody", "ExplicitConstructorInvocation",
  "InterfaceDeclaration", "$@12", "$@13", "$@14", "$@15",
  "ExtendsInterfaces", "InterfaceBody", "InterfaceMemberDeclarations",
  "InterfaceMemberDeclaration", "ConstantDeclaration",
  "AbstractMethodDeclaration", "ArrayInitializer", "VariableInitializers",
  "Block", "BlockStatements", "BlockStatement",
  "LocalVariableDeclarationStatement", "LocalVariableDeclaration",
  "Statement", "StatementNoShortIf",
  "StatementWithoutTrailingSubstatement", "EmptyStatement",
  "LabeledStatement", "LabeledStatementNoShortIf", "ExpressionStatement",
  "StatementExpression", "DummyIfStatement", "DummyElseStatement",
  "DummyIfStatement1", "IfThenStatement", "DummyIfStatement2",
  "IfThenElseStatement", "IfThenElseStatementNoShortIf",
  "DummySwitchStatement", "SwitchStatement", "SwitchBlock",
  "SwitchBlockStatementGroups", "SwitchBlockStatementGroup",
  "SwitchLabels", "SwitchLabel", "DummyWhileStatement",
  "DummyWhileStatement1", "WhileStatement", "WhileStatementNoShortIf",
  "DummyDoStatement", "DummyDoStatement1", "DoStatement",
  "DummyForStatement", "DummyForStatement1", "DummyForStatement14",
  "DummyForStatement2", "DummyForStatement3", "DummyForStatement4",
  "DummyForStatement15", "DummyForStatement5", "DummyForStatement6",
  "DummyForStatement7", "DummyForStatement8", "DummyForStatement9",
  "DummyForStatement10", "DummyForStatement11", "DummyForStatement12",
  "DummyForStatement13", "ForStatement", "ForStatementNoShortIf",
  "ForInit", "ForUpdate", "StatementExpressionList", "BreakStatement",
  "ContinueStatement", "ReturnStatement", "ThrowStatement",
  "SynchronizedStatement", "TryStatement", "Catches", "CatchClause",
  "$@16", "Finally", "Primary", "PrimaryNoNewArray",
  "ClassInstanceCreationExpression", "ArgumentList",
  "ArrayCreationExpression", "DimExprs", "DimExpr", "Dims", "FieldAccess",
  "DummyMethodInvocation", "MethodInvocation", "ArrayAccess",
  "PostfixExpression", "PostIncrementExpression",
  "PostDecrementExpression", "UnaryExpression", "PreIncrementExpression",
  "PreDecrementExpression", "UnaryExpressionNotPlusMinus",
  "CastExpression", "MultiplicativeExpression", "AdditiveExpression",
  "ShiftExpression", "RelationalExpression", "EqualityExpression",
  "AndExpression", "ExclusiveOrExpression", "InclusiveOrExpression",
  "ConditionalAndExpression", "ConditionalOrExpression",
  "ConditionalExpression", "AssignmentExpression", "Assignment",
  "LeftHandSide", "AssignmentOperator", "Expression", "ConstantExpression", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354
};
# endif

#define YYPACT_NINF (-594)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-383)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1514,    56,  -594,  -594,  -594,  -594,  -594,  -594,  -594,  -594,
    -594,  -594,  -594,    74,  -594,    78,    84,  -594,  1388,   919,
    1388,  -594,    74,  -594,  -594,  -594,   180,  -594,  -594,  -594,
       4,  -594,   159,  -594,  -594,   112,  -594,   919,  -594,  -594,
    1388,   919,   259,    97,   113,  -594,    74,   128,   144,   132,
    -594,    74,    74,   196,   164,  -594,   919,    89,  -594,     4,
     112,  -594,  -594,   167,  3113,  -594,    74,   128,  -594,  -594,
    -594,  -594,   212,  3009,  -594,   196,  -594,   196,   215,   128,
     144,   196,   164,  -594,  -594,  -594,  -594,  -594,  -594,  -594,
    -594,  -594,  -594,   260,   264,   242,  -594,  -594,  -594,  -594,
    -594,   301,   140,  3182,  -594,   282,  3155,  -594,  -594,  -594,
    -594,  -594,    74,  1884,  -594,  -594,   320,   340,  3182,  3071,
    -594,  -594,  -594,  -594,    73,  -594,  -594,  -594,   797,    23,
    -594,  -594,   196,  -594,  -594,  -594,   128,  -594,   196,  -594,
     196,   342,     8,   342,   202,  -594,   248,     8,   339,   341,
     343,   260,   264,  -594,  -594,  -594,  -594,   350,  -594,  -594,
    -594,  -594,  -594,  -594,  -594,  -594,  -594,  2865,  -594,  -594,
     305,   797,   365,  -594,   380,   120,  2442,  -594,   402,  2865,
     151,   797,  2865,  2865,  -594,   386,    82,  -594,  1965,  -594,
    -594,   391,  -594,  -594,  -594,  -594,  -594,   400,  2865,   422,
    -594,   449,  -594,   426,  -594,   428,   430,  -594,  2907,   434,
    -594,   438,   408,  2865,   431,   440,  2907,  2480,   432,   446,
    2907,  1268,   448,  2907,  2834,   451,  2907,  -594,  -594,  -594,
    -594,  -594,  -594,  -594,   436,   450,   145,  -594,   824,   456,
     224,  1801,   303,   325,   349,  -594,  -594,  -594,  1882,   402,
     457,    23,  -594,  -594,  -594,   386,    79,  -594,  2046,    74,
     455,  -594,  -594,  -594,  -594,   196,  -594,   501,   454,  -594,
     386,  -594,  2523,   458,  -594,  -594,  -594,  -594,     8,   384,
       8,  -594,  2865,  1590,  2865,  2865,  2865,   302,  -594,  -594,
     303,  -594,  -594,  -594,  -594,  -594,  -594,  -594,    53,     5,
     270,    28,   -22,   407,   399,   409,   410,    58,  -594,  -594,
    -594,   464,  2907,   447,  2865,   459,  -594,   460,  -594,   461,
     435,   465,  -594,   466,   474,   474,   469,   231,  -594,  -594,
    -594,  -594,  -594,   468,  2561,  -594,  -594,  -594,  -594,  -594,
    2976,  -594,  2907,  2865,  2865,  2907,   490,   471,  1680,   472,
    -594,  3230,  2907,  -594,  -594,  -594,  3237,  2907,  -594,  -594,
    -594,  -594,   470,  2907,  -594,  -594,  -594,  2907,  -594,   473,
    2865,  2599,  -594,  -594,  -594,  -594,  -594,  -594,  -594,  -594,
    -594,  -594,  -594,  -594,  -594,  2865,  -594,   482,   455,  -594,
     496,  -594,   797,  -594,   504,   108,  2127,  2208,  -594,   489,
    -594,  -594,  -594,   133,  -594,  -594,   605,  -594,  -594,  -594,
     508,  -594,  -594,  -594,  -594,   185,  1609,   514,  -594,  -594,
    -594,  2865,  2865,  2865,  2865,  2865,  2865,  2865,  2865,  2865,
    2865,  2865,   797,  2865,  2865,  2865,  2865,  2865,  2865,  2865,
    2865,  2865,  2865,  -594,  -594,  -594,   518,   517,  -594,  -594,
    -594,   402,   435,  -594,  -594,  -594,  -594,  2865,   520,  -594,
     520,  2637,   515,   502,  -594,  -594,   545,  -594,   449,  -594,
     526,  -594,   528,  2976,   534,  2976,   541,  2976,   543,  2976,
    -594,  -594,   546,  -594,  -594,   549,  -594,  -594,  -594,  -594,
     470,  -594,  -594,  -594,  -594,  -594,  -594,  -594,  3254,  -594,
    -594,   551,   552,  -594,   182,  -594,  -594,  -594,  -594,  -594,
    2675,  2713,  -594,  2289,  -594,    74,  -594,  -594,   556,  -594,
      11,  -594,  2865,   555,   187,  2751,   289,  1386,  -594,  -594,
    -594,    53,    53,     5,     5,     5,   270,   270,   242,  -594,
     270,   270,    28,    28,   -22,   407,   399,   409,   410,   542,
     402,  2789,   554,  -594,  -594,  -594,   558,  2751,  -594,   564,
     564,  -594,   232,  -594,  2976,  2976,  2976,  2976,  -594,  2976,
    -594,  2976,  -594,  2976,  -594,   544,  2865,  -594,  2827,  -594,
    -594,  2865,   553,   235,   559,   261,  -594,  -594,  -594,  -594,
    2394,  -594,  -594,  2865,   566,  1386,  -594,  2865,  -594,  -594,
     263,   797,  -594,  -594,  -594,  -594,  -594,  -594,  -594,  -594,
    -594,   229,  -594,  -594,  -594,   269,  -594,  -594,   562,  -594,
     563,  -594,  -594,  -594,  -594,  -594,  -594,  -594,   572,  2865,
     567,  -594,   297,  -594,  1722,  -594,  -594,  -594,  -594,   402,
    -594,   568,  -594,  -594,  -594,  1803,  -594,  2370,  -594,  -594,
    -594,  -594
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,     0,    53,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,     0,    48,     0,     0,     2,    35,    37,
      40,    41,     0,    46,    47,    43,     0,    54,    51,    52,
     151,    32,     0,    30,    31,    78,     1,    39,    42,    44,
      34,    36,     0,     0,     0,    55,     0,     0,   147,     0,
      45,     0,     0,     0,    74,    72,    38,     0,    49,   149,
      76,    26,   153,    24,     0,   152,     0,     0,    33,    25,
      82,    84,    83,     0,    79,     0,    66,     0,     0,     0,
     145,     0,    70,    68,    15,    16,    17,    18,    19,    20,
      21,    12,   155,     0,     0,     9,    11,    13,    14,    10,
      22,    23,    24,     0,   161,     0,     0,   157,   159,   160,
     154,   148,     0,     0,    87,   126,    59,    30,     0,     0,
      88,    90,    93,    94,     0,   107,    91,    92,     0,     0,
     125,    75,     0,    73,    50,   150,     0,    77,     0,    80,
       0,     0,   115,   101,     0,    97,    99,   111,     0,     0,
       0,     0,     0,   162,   156,   158,    85,     0,   218,     3,
       4,     5,     6,     7,     8,   235,   231,     0,   170,   200,
      32,     0,     0,   294,     0,     0,     0,   238,     0,     0,
       0,     0,     0,     0,   293,     0,   380,   189,     0,   171,
     173,     0,   174,   178,   190,   179,   191,     0,     0,     0,
     180,     0,   181,     0,   192,     0,     0,   182,     0,     0,
     193,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   183,   194,   195,
     196,   198,   197,   199,   324,   291,   296,   292,   297,     0,
     298,   299,     0,   207,   208,   205,   206,   204,     0,     0,
     133,     0,    86,    89,   106,     0,     0,   119,     0,     0,
       0,   132,    67,   146,    71,     0,    69,     0,     0,   113,
       0,    96,     0,     0,   110,    27,    29,    28,   114,     0,
     109,   211,     0,     0,     0,     0,     0,   325,   296,   298,
     337,   326,   327,   345,   330,   331,   334,   340,   349,   352,
     356,   362,   365,   367,   369,   371,   373,   375,   377,   394,
     378,     0,     0,     0,     0,     0,   275,     0,   279,     0,
       0,     0,   278,     0,     0,    25,     0,   325,   297,   299,
     335,   336,   101,   177,     0,   169,   172,   175,   203,   213,
       0,   212,     0,     0,     0,     0,     0,     0,     0,   240,
     241,     0,     0,   256,   251,   245,     0,     0,   259,   250,
     273,   249,   272,     0,   258,   253,   252,     0,   260,     0,
       0,     0,   328,   329,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,   393,     0,   128,     0,     0,   130,
     121,   134,     0,   140,   294,     0,     0,     0,   123,   122,
     131,    81,   116,     0,   118,    98,     0,   100,   105,   104,
       0,   112,    95,   108,   332,     0,   325,     0,   338,   339,
     333,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   295,   201,   176,     0,   314,   276,   280,
     288,     0,   283,   286,   285,   281,   277,     0,   305,   308,
     307,     0,     0,    32,   214,   215,   178,   185,     0,   186,
       0,   187,     0,     0,     0,     0,     0,     0,     0,     0,
     188,   216,     0,   232,   233,     0,   237,   244,   271,   239,
     270,   248,   243,   242,   261,   247,   246,   254,     0,   255,
     257,   313,     0,   317,     0,   302,   379,   136,   129,   120,
       0,     0,   139,     0,   138,     0,   117,   166,     0,   167,
       0,   103,     0,     0,     0,     0,     0,   295,   347,   348,
     346,   350,   351,   353,   354,   355,   357,   358,     0,   361,
     359,   360,   364,   363,   366,   368,   370,   372,   374,     0,
       0,     0,     0,   290,   287,   284,     0,     0,   309,   304,
     306,   301,     0,   322,     0,     0,     0,     0,   264,     0,
     267,     0,   266,     0,   268,     0,     0,   274,     0,   323,
     316,     0,     0,     0,     0,     0,   137,   124,   164,   165,
       0,   342,   311,     0,     0,     0,   343,     0,   282,   321,
       0,     0,   310,   300,   202,   217,   234,   269,   262,   263,
     265,     0,   219,   236,   319,     0,   303,   142,     0,   144,
       0,   163,   168,   341,   312,   344,   376,   320,     0,     0,
       0,   223,     0,   224,     0,   227,   318,   141,   143,     0,
     395,     0,   230,   222,   225,     0,   221,   226,   228,   289,
     229,   220
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -594,  -594,  -594,   -63,  -174,  -594,  -594,  -594,   174,   -40,
    -179,   -21,  -594,   -13,    -2,  -594,  -594,   587,    30,  -594,
      71,  -594,  -594,  -594,   136,    19,    -5,  -594,  -594,  -594,
    -594,  -594,  -594,  -594,  -594,  -594,   569,   146,  -594,   -53,
    -594,   497,  -594,   -37,   -83,   348,   373,  -594,  -392,  -594,
     -31,   -57,   363,  -384,  -117,  -594,   507,  -594,  -594,  -594,
    -594,   527,  -594,  -228,  -594,  -594,  -594,  -594,  -594,  -594,
     574,   -32,  -594,   530,  -594,  -594,  -594,  -594,   -70,  -109,
    -183,  -594,  -155,  1151,  -340,  -276,  -594,  -594,  -594,  -594,
    -206,  -594,   170,  -594,  -594,  -266,  -594,  -594,  -594,  -594,
    -594,  -594,    12,    14,  -593,  -594,  -196,  -594,  -594,  -594,
    -594,  -594,  -594,  -594,  -594,  -594,   -23,    -1,  -594,  -594,
      98,   181,  -594,   379,   437,  -594,   589,   650,  -594,  -594,
    -594,  -197,   304,  -594,  -594,  -594,  -594,  -594,  -594,  -594,
     197,  -594,   205,  -594,  -594,   -36,  -448,  -594,   336,  -132,
    -382,   -35,  -594,   245,  1116,   427,   486,   673,  -163,   855,
     914,  -498,  -594,    21,   -62,   -78,    13,   233,   228,   234,
     236,   227,  -594,    75,   290,  1011,  -594,  -594,   516,  -594
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    16,   184,   185,    95,    96,    97,    98,    99,   100,
      70,    62,   101,   287,    33,    34,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,   132,   140,
     138,    77,    75,    81,    53,   265,    54,    55,    72,    74,
     119,   120,   121,   104,   144,   145,   146,   273,   407,   123,
     105,   142,   256,   257,   260,   399,   125,   126,   249,   127,
     128,   129,   387,   261,   396,    29,   136,    67,    79,    47,
      48,    65,   106,   107,   108,   109,   408,   520,   187,   647,
     189,   190,   191,   192,   465,   193,   194,   195,   467,   196,
     197,   198,   342,   199,   200,   201,   202,   469,   203,   204,
     612,   632,   633,   634,   635,   205,   206,   207,   471,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   480,
     489,   361,   362,   228,   229,   230,   231,   232,   233,   452,
     453,   552,   454,   234,   235,   288,   504,   237,   458,   459,
     524,   238,   239,   289,   241,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   247,   248,   385,   505,   641
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      32,    94,   326,   130,   188,   336,    61,   324,   509,    42,
      94,    69,    61,   562,   519,   360,   313,   425,   360,   330,
     331,    45,   131,   389,   133,   269,    61,   366,   137,   596,
     274,    71,   400,    63,   526,   111,   122,   147,    63,    63,
     152,   648,   124,    94,   268,   110,   589,   135,    37,   130,
      41,   102,   648,    63,   130,   152,    94,   258,   430,   431,
     102,   590,   583,   585,   466,   255,   422,   423,   435,   279,
      56,   117,    61,    46,   468,   436,   559,   236,   560,   262,
     398,   432,   122,   103,    36,   264,   259,   266,   124,    38,
     102,   156,   118,   102,   278,   280,   426,   625,    45,    63,
     186,   259,   333,   600,   263,   102,   102,   113,   320,   415,
      30,    38,   391,    45,  -315,   102,   117,   117,   334,   414,
     424,   418,   419,   420,   115,   103,   433,   434,    31,   392,
     615,    49,    35,   568,   388,   570,   -24,   572,   118,   574,
     511,   325,   360,    68,   470,   360,   441,   328,   328,   397,
     360,    59,   236,   442,   493,    39,    78,   315,   102,   496,
     508,   411,    64,   413,  -325,  -325,   516,    60,    63,   327,
     327,   316,   236,    39,   317,   186,   150,    39,  -210,   386,
     236,    51,    52,   392,   236,   236,    68,   236,   236,    49,
     236,    43,    39,   488,    66,  -210,  -210,   466,   622,   466,
      76,   466,   322,   466,   255,   323,    83,   468,    49,   468,
      50,   468,   401,   468,   336,   580,    49,   628,   522,    69,
     593,   523,   236,   594,   604,   605,   606,   607,   139,   608,
      73,   609,   581,   610,    52,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,   186,    63,   328,    44,   328,
     328,   328,   270,   271,   102,   629,   630,  -209,   538,   528,
     529,   530,   112,  -315,   631,   603,   134,   421,   618,   327,
     416,   327,   327,   327,  -209,  -209,   236,   470,   148,   470,
      49,   470,   581,   470,  -102,   581,   272,   513,   466,   466,
     466,   466,   577,   466,   620,   466,   627,   466,   468,   468,
     468,   468,   636,   468,   236,   468,   236,   468,    57,   236,
      58,   581,   236,   581,   141,   236,   236,   472,   143,   581,
     236,   236,   595,   629,   630,   594,   558,   236,   558,   255,
     336,   236,   643,   153,  -315,   186,   587,   149,   421,   473,
    -380,  -380,  -380,  -380,  -380,  -380,  -380,  -380,  -380,  -380,
    -380,    49,   536,   537,  -127,   540,   541,   312,   240,   591,
     236,   236,   427,   428,   429,   533,   534,   535,   470,   470,
     470,   470,   250,   470,   267,   470,   275,   470,   276,   102,
     277,   553,   281,   186,   186,   372,   373,   328,   328,   328,
     328,   328,   328,   328,   328,   328,   328,   314,   328,   328,
     328,   328,   328,   328,   328,   328,   328,  -326,  -326,   327,
     327,   327,   327,   327,   327,   327,   327,   327,   327,   102,
     327,   327,   327,   327,   327,   327,   327,   327,   327,   315,
     623,  -327,  -327,   240,   270,   412,   113,   236,   474,   236,
     332,   236,   337,   236,   450,   451,   531,   532,   542,   543,
     472,   338,   472,   240,   472,   340,   472,   341,   343,   349,
     344,   240,   236,   345,   336,   240,   240,   347,   240,   240,
     348,   240,   473,   352,   473,    69,   473,   236,   473,   357,
     598,   363,   351,   356,   367,   369,   370,   328,   371,   258,
    -135,   404,   328,   437,   410,   438,   439,   443,   445,   440,
     186,   461,    63,   240,    84,    85,    86,    87,    88,   327,
     457,   448,   449,   447,   327,   507,   455,   456,   270,   485,
     498,   475,   486,   491,    89,    90,    91,   501,   236,   236,
     236,   236,  -102,   236,   402,   236,   510,   236,   255,   515,
     242,   472,   472,   472,   472,   521,   472,   527,   472,   551,
     472,   550,   563,  -184,   564,    31,   557,   240,   328,   566,
     328,   567,   328,   473,   473,   473,   473,   569,   473,   649,
     473,   474,   473,   474,   571,   474,   573,   474,   611,   575,
     327,   576,   327,   578,   327,   240,   601,   240,   102,   579,
     240,   588,   592,   240,   597,   602,   240,   240,   236,   243,
     594,   240,   240,   624,   617,   639,   539,    40,   240,   236,
     619,   236,   240,   637,   638,   242,   253,   282,   405,   642,
     650,   186,   159,   160,   161,   162,   163,   164,   390,    82,
     403,   254,   186,    80,   186,   242,   155,   283,   565,   406,
     517,   240,   240,   242,   644,   251,   645,   242,   242,   554,
     242,   242,   490,   242,   475,   518,   475,   555,   475,    31,
     475,   460,   474,   474,   474,   474,   545,   474,   548,   474,
     544,   474,   626,   546,   243,   506,   547,   173,   174,     0,
       0,     0,     0,   311,     0,   242,   181,   182,   183,   284,
     285,     0,   319,     0,   243,   321,   286,     0,     0,     0,
       0,     0,   243,     0,     0,     0,   243,   243,     0,   243,
     243,     0,   243,     0,   339,     0,     0,     0,   240,   476,
     240,     0,   240,     0,   240,     0,     0,     0,     0,   350,
       0,     0,     0,   355,     0,     0,     0,     0,     0,   242,
       0,     0,     0,   240,   243,   475,   475,   475,   475,     0,
     475,     0,   475,     0,   475,     0,     0,     0,   240,     0,
       0,     0,     0,     0,     0,     0,     0,   242,     0,   242,
       0,     0,   242,     0,     0,   242,     0,   477,   242,   242,
       0,     0,     0,   242,   242,     0,   244,     0,   409,     0,
     242,     0,     0,     0,   242,     0,     0,     0,   243,   417,
      84,    85,    86,    87,    88,     0,     0,     0,     0,   240,
     240,   240,   240,     0,   240,     0,   240,     0,   240,     0,
      89,    90,    91,   242,   242,     0,   243,     0,   243,     0,
     446,   243,     0,     0,   243,     0,     0,   243,   243,     0,
       0,     0,   243,   243,     0,     0,     0,     0,     0,   243,
     462,    31,   476,   243,   476,     0,   476,     0,   476,   482,
     483,   244,  -381,  -381,  -381,  -381,  -381,  -381,  -381,  -381,
    -381,  -381,  -381,     0,     0,     0,     0,     0,     0,   240,
       0,   244,   243,   243,     0,     0,   502,     0,     0,   244,
     240,     0,   240,   244,   244,     0,   244,   244,     0,   244,
     242,     0,   242,     0,   242,     0,   242,     0,     0,     0,
     477,     0,   477,     0,   477,     0,   477,     0,     0,     0,
       0,     0,   409,     0,     0,   242,     0,     0,     0,   478,
       1,   244,     0,     0,     0,     0,     0,   462,     0,     0,
     242,     0,     0,   476,   476,   476,   476,     0,   476,     0,
     476,     0,   476,     0,     0,     0,     0,     0,   549,   243,
       0,   243,     0,   243,     0,   243,     0,     0,   245,     0,
       2,     0,     0,   556,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,   243,   244,     0,    15,     0,     0,
     479,   242,   242,   242,   242,     0,   242,     0,   242,   243,
     242,   477,   477,   477,   477,     0,   477,     0,   477,     0,
     477,     0,     0,   244,     0,   244,     0,     0,   244,     0,
       0,   244,     0,     0,   244,   244,     0,   246,     0,   244,
     244,     0,     0,     0,     0,     0,   244,     0,     0,     0,
     244,   462,     0,   245,     0,     0,     0,     0,     0,     0,
     243,   243,   243,   243,     0,   243,     0,   243,     0,   243,
       0,   242,   478,   245,   478,     0,   478,     0,   478,   244,
     244,   245,   242,   556,   242,   245,   245,     0,   245,   245,
       0,   245,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   613,     0,     0,     0,     0,   616,     0,     0,
       0,     0,   246,     0,     0,     0,   409,     0,     0,     0,
       0,     0,     0,   245,     0,     0,     0,     0,     0,     0,
     243,     0,   246,   479,     0,   479,     0,   479,     0,   479,
     246,   243,     0,   243,   246,   246,     0,   246,   246,     0,
     246,     0,     0,     0,     0,   640,   244,     0,   244,     0,
     244,     0,   244,   478,   478,   478,   478,     0,   478,     0,
     478,     0,   478,     0,     0,     0,     0,   245,     0,     0,
       0,   244,   246,     0,     0,     0,     0,     0,   310,     0,
       0,     0,     0,     0,     0,     0,   244,   310,     0,     0,
     310,     0,     0,     0,     0,   245,     0,   245,     0,     0,
     245,     0,     0,   245,     0,     0,   245,   245,     0,   310,
       0,   245,   245,     0,   479,   479,   479,   479,   245,   479,
       0,   479,   245,   479,   310,     0,   246,     0,   310,     0,
       0,     0,     0,     0,     0,     0,     0,   244,   244,   244,
     244,     0,   244,     0,   244,     0,   244,     0,     0,     0,
       0,   245,   245,     0,   246,     0,   246,     0,     0,   246,
       0,     0,   246,     0,     0,   246,   246,     0,     0,     0,
     246,   246,     0,     0,     0,     0,     0,   246,     0,     0,
       0,   246,     0,   310,     0,   159,   160,   161,   162,   163,
     164,     0,     0,     0,   310,     0,     0,     0,   329,   329,
     167,   359,     0,     0,     0,     0,     0,   244,     0,     0,
     246,   246,     0,     0,     0,     0,     0,     0,   244,     0,
     244,     0,    31,     0,     0,   310,     0,     0,   245,     0,
     245,     0,   245,     0,   245,     0,     0,     0,     0,     0,
     173,   174,     0,     0,     0,   310,     0,     0,     0,   181,
     182,   183,     0,   245,   310,   310,     0,     0,     0,   346,
       0,     0,     0,     0,     0,     0,     0,   353,   245,     0,
       0,   358,     0,     0,   364,     0,     0,   368,     0,     0,
       0,   310,   310,     0,     0,     0,     0,   246,     0,   246,
       0,   246,     0,   246,     0,     0,   310,     0,   329,     1,
     329,   329,   329,   159,   160,   161,   162,   163,   164,     0,
       0,     0,   246,     0,     0,     0,     0,   310,   283,   245,
     245,   245,   245,     0,   245,     0,   245,   246,   245,     0,
       0,     0,   310,     0,     0,     0,     0,     0,     0,     2,
      31,     0,     0,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,   310,    14,     0,    15,     0,   173,   174,
       0,     0,     0,   444,     0,     0,     0,   181,   310,     0,
     284,   285,   310,     0,     0,     0,     0,     0,   246,   246,
     246,   246,     0,   246,     0,   246,     0,   246,     0,   245,
       0,   464,     0,   481,     0,     0,   484,     0,     0,     0,
     245,     0,   245,   494,     0,     0,     0,     0,   497,     0,
       0,     0,     0,     0,   499,     0,     0,     0,   500,     0,
       0,   310,   310,     0,     0,     1,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   310,     0,   329,   329,
     329,   329,   329,   329,   329,   329,   329,   329,   246,   329,
     329,   329,   329,   329,   329,   329,   329,   329,     0,   246,
       0,   246,   310,     0,     0,     2,     0,     0,   310,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,     0,    15,     0,     0,     0,     0,   310,     0,   310,
       0,     0,   310,    84,    85,    86,    87,    88,     0,     0,
       0,   310,   282,     0,     0,     0,     0,   159,   160,   161,
     162,   163,   164,    89,    90,    91,     0,     0,     0,     0,
       0,     0,   283,     0,   353,     0,   358,     0,   364,     0,
     368,     0,     0,     0,     0,     0,     0,     0,   329,     0,
     310,  -315,     0,   329,    31,   525,     0,  -380,  -380,  -380,
    -380,  -380,  -380,  -380,  -380,  -380,  -380,  -380,    49,     0,
       0,     0,   173,   174,     0,     0,     0,     0,     0,     0,
       0,   181,   182,   183,   284,   285,     0,     0,     0,     0,
       0,   286,     0,    84,    85,    86,    87,    88,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   159,   160,   161,
     162,   163,   164,    89,    90,    91,     0,     0,     0,   329,
       0,   329,   167,   329,     0,   444,   481,   484,   494,     0,
     497,     0,   499,     0,   500,    84,    85,    86,    87,    88,
       0,   487,     0,     0,    31,     0,     0,   157,   158,   159,
     160,   161,   162,   163,   164,    89,    90,    91,   629,   630,
     165,   166,   173,   174,   167,     0,   113,   646,     0,     0,
       0,   181,   182,   183,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   169,     0,     0,   170,     0,     0,     0,
       0,     0,   171,     0,   172,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   173,   174,   175,   176,   177,   178,
       0,   179,   180,   181,   182,   183,    84,    85,    86,    87,
      88,     0,     0,     0,     0,     0,     0,     0,   157,   158,
     159,   160,   161,   162,   163,   164,    89,    90,    91,   629,
     630,   165,   166,     0,     0,   167,     0,   113,   651,  -382,
    -382,  -382,  -382,  -382,  -382,  -382,  -382,  -382,  -382,  -382,
       0,     0,     0,     0,   169,     0,     0,   170,     0,     0,
       0,     0,     0,   171,     0,   172,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   173,   174,   175,   176,   177,
     178,     0,   179,   180,   181,   182,   183,    84,    85,    86,
      87,    88,     0,     0,     0,     0,     0,     0,     0,   157,
     158,   159,   160,   161,   162,   163,   164,    89,    90,    91,
       0,     0,   165,   166,     0,     0,   167,     0,   113,   168,
     374,   375,   376,   377,   378,   379,   380,   381,   382,   383,
     384,     0,     0,     0,     0,   169,     0,     0,   170,     0,
       0,     0,     0,     0,   171,     0,   172,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   173,   174,   175,   176,
     177,   178,     0,   179,   180,   181,   182,   183,    84,    85,
      86,    87,    88,     0,     0,     0,     0,     0,     0,     0,
     157,   158,   159,   160,   161,   162,   163,   164,    89,    90,
      91,     0,     0,   165,   166,     0,     0,   167,     0,   113,
     335,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   169,     0,     0,   170,
       0,     0,     0,     0,     0,   171,     0,   172,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   173,   174,   175,
     176,   177,   178,     0,   179,   180,   181,   182,   183,    84,
      85,    86,    87,    88,     0,     0,     0,     0,     0,     0,
       0,   157,   158,   159,   160,   161,   162,   163,   164,    89,
      90,    91,     0,     0,   165,   166,     0,     0,   167,     0,
     113,   393,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   169,     0,     0,
     170,     0,     0,     0,     0,     0,   171,     0,   172,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   394,   395,
     175,   176,   177,   178,     0,   179,   180,   181,   182,   183,
      84,    85,    86,    87,    88,     0,     0,     0,     0,     0,
       0,     0,   157,   158,   159,   160,   161,   162,   163,   164,
      89,    90,    91,     0,     0,   165,   166,     0,     0,   167,
       0,   113,   512,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   169,     0,
       0,   170,     0,     0,     0,     0,     0,   171,     0,   172,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   173,
     174,   175,   176,   177,   178,     0,   179,   180,   181,   182,
     183,    84,    85,    86,    87,    88,     0,     0,     0,     0,
       0,     0,     0,   157,   158,   159,   160,   161,   162,   163,
     164,    89,    90,    91,     0,     0,   165,   166,     0,     0,
     167,     0,   113,   514,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   169,
       0,     0,   170,     0,     0,     0,     0,     0,   171,     0,
     172,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     173,   174,   175,   176,   177,   178,     0,   179,   180,   181,
     182,   183,    84,    85,    86,    87,    88,     0,     0,     0,
       0,     0,     0,     0,   157,   158,   159,   160,   161,   162,
     163,   164,    89,    90,    91,     0,     0,   165,   166,     0,
       0,   167,     0,   113,   586,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     169,     0,     0,   170,     0,     0,     0,     0,     0,   171,
       0,   172,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   173,   174,   175,   176,   177,   178,     0,   179,   180,
     181,   182,   183,    84,    85,    86,    87,    88,     0,     0,
       0,     0,     0,     0,     0,   157,   158,   159,   160,   161,
     162,   163,   164,    89,    90,    91,     0,     0,   165,   166,
       0,     0,   167,     0,   113,     0,   282,     0,     0,     0,
       0,   159,   160,   161,   162,   163,   164,     0,     0,     0,
       0,   169,     0,     0,   170,     0,   283,     0,   406,   621,
     171,     0,   172,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   173,   174,   175,   176,   177,   178,    31,   179,
     180,   181,   182,   183,   282,     0,     0,     0,     0,   159,
     160,   161,   162,   163,   164,     0,   173,   174,     0,     0,
       0,     0,     0,     0,   283,   181,   182,   183,   284,   285,
       0,     0,     0,     0,     0,   286,     0,     0,     0,     0,
       0,     0,   282,   318,     0,     0,    31,   159,   160,   161,
     162,   163,   164,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   283,     0,   173,   174,     0,     0,     0,     0,
       0,     0,     0,   181,   182,   183,   284,   285,     0,     0,
       0,   354,     0,   286,    31,   282,     0,     0,     0,     0,
     159,   160,   161,   162,   163,   164,     0,     0,     0,     0,
       0,     0,   173,   174,     0,   283,     0,   406,     0,     0,
       0,   181,   182,   183,   284,   285,     0,     0,     0,     0,
       0,   286,     0,   282,     0,     0,     0,    31,   159,   160,
     161,   162,   163,   164,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   283,     0,   173,   174,     0,   277,     0,
       0,     0,     0,     0,   181,   182,   183,   284,   285,     0,
       0,   282,     0,     0,   286,    31,   159,   160,   161,   162,
     163,   164,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   283,   503,   173,   174,     0,     0,     0,     0,     0,
       0,     0,   181,   182,   183,   284,   285,     0,     0,   282,
       0,     0,   286,    31,   159,   160,   161,   162,   163,   164,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   283,
     561,   173,   174,     0,     0,     0,     0,     0,     0,     0,
     181,   182,   183,   284,   285,     0,     0,   282,     0,     0,
     286,    31,   159,   160,   161,   162,   163,   164,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   283,   582,   173,
     174,     0,     0,     0,     0,     0,     0,     0,   181,   182,
     183,   284,   285,     0,     0,   282,     0,     0,   286,    31,
     159,   160,   161,   162,   163,   164,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   283,   584,   173,   174,     0,
       0,     0,     0,     0,     0,     0,   181,   182,   183,   284,
     285,     0,     0,   282,     0,     0,   286,    31,   159,   160,
     161,   162,   163,   164,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   283,     0,   173,   174,     0,   592,     0,
       0,     0,     0,     0,   181,   182,   183,   284,   285,     0,
       0,   282,     0,     0,   286,    31,   159,   160,   161,   162,
     163,   164,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   283,   599,   173,   174,     0,     0,     0,     0,     0,
       0,     0,   181,   182,   183,   284,   285,     0,     0,   282,
       0,     0,   286,    31,   159,   160,   161,   162,   163,   164,
       0,   159,   160,   161,   162,   163,   164,     0,     0,   283,
     614,   173,   174,     0,     0,     0,   167,   365,     0,     0,
     181,   182,   183,   284,   285,     0,     0,   282,     0,     0,
     286,    31,   159,   160,   161,   162,   163,   164,    31,     0,
       0,     0,     0,     0,     0,     0,     0,   283,     0,   173,
     174,     0,     0,     0,     0,     0,   173,   174,   181,   182,
     183,   284,   285,     0,     0,   181,   182,   183,   286,    31,
       0,     0,   157,   158,   159,   160,   161,   162,   163,   164,
       0,     0,     0,     0,     0,   165,   166,   173,   174,   167,
       0,   113,     0,     0,     0,     0,   181,   182,   183,   284,
     285,     0,     0,     0,     0,     0,   286,     0,   169,     0,
       0,   170,     0,     0,     0,     0,     0,     0,     0,   172,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   173,
     174,   175,   176,   177,   178,     0,   179,   180,   181,   182,
     183,   157,   158,   159,   160,   161,   162,   163,   164,     0,
       0,     0,     0,     0,   165,   166,     0,     0,   167,     0,
     113,     0,    84,    85,    86,    87,    88,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   169,     0,     0,
     463,     0,    89,    90,    91,     0,     0,     0,   172,     0,
       0,     0,     0,   113,   114,     0,     0,     0,   173,   174,
     175,   176,   177,   178,     0,   179,   180,   181,   182,   183,
     115,     0,     0,    31,     3,     4,     5,   116,     7,     8,
       9,    10,    11,    12,    84,    85,    86,    87,    88,     0,
      93,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    89,    90,    91,     0,     0,     0,
       0,     0,     0,     0,     0,   113,   252,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    84,    85,    86,    87,
      88,     0,   115,     0,     0,    31,     3,     4,     5,   116,
       7,     8,     9,    10,    11,    12,    89,    90,    91,     0,
       0,     0,    93,     0,     0,     0,     0,     0,    92,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    84,    85,
      86,    87,    88,     0,     0,     0,     0,    31,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    89,    90,
      91,     0,     0,     0,    93,    84,    85,    86,    87,    88,
     154,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    89,    90,    91,     0,    31,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
       0,     0,     0,     0,     0,     0,    93,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    31,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,   159,   160,   161,
     162,   163,   164,   151,   159,   160,   161,   162,   163,   164,
       0,     0,   167,   492,     0,     0,     0,     0,     0,   167,
     495,   159,   160,   161,   162,   163,   164,     0,     0,     0,
       0,     0,     0,     0,    31,     0,   167,     0,     0,     0,
       0,    31,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   173,   174,     0,     0,     0,     0,    31,   173,
     174,   181,   182,   183,     0,     0,     0,     0,   181,   182,
     183,     0,     0,     0,     0,     0,   173,   174,     0,     0,
       0,     0,     0,     0,     0,   181,   182,   183
};

static const yytype_int16 yycheck[] =
{
      13,    64,   181,    73,   113,   188,    46,   181,   392,    22,
      73,    51,    52,   461,   406,   221,   171,    12,   224,   182,
     183,    26,    75,   251,    77,   142,    66,   224,    81,   527,
     147,    52,   260,    46,   416,    67,    73,    94,    51,    52,
     103,   634,    73,   106,    36,    66,    35,    79,    18,   119,
      20,    64,   645,    66,   124,   118,   119,    34,    30,    31,
      73,    50,   510,   511,   340,   128,    13,    14,    90,   152,
      40,    73,   112,    69,   340,    97,   458,   113,   460,   132,
     259,    53,   119,    64,     0,   138,    78,   140,   119,    18,
     103,   112,    73,   106,   151,   152,    91,   595,   103,   112,
     113,    78,   185,   551,   136,   118,   119,    34,   178,   283,
      54,    40,    33,   118,    32,   128,   118,   119,    36,   282,
      67,   284,   285,   286,    51,   106,    98,    99,    54,    50,
     578,    49,    54,   473,   251,   475,    54,   477,   119,   479,
      32,   181,   348,    54,   340,   351,    88,   182,   183,   258,
     356,    54,   188,    95,   351,    19,    67,    49,   171,   356,
     388,   278,    34,   280,    82,    83,    33,    54,   181,   182,
     183,    51,   208,    37,    54,   188,    36,    41,    33,   249,
     216,    69,    70,    50,   220,   221,    54,   223,   224,    49,
     226,    11,    56,   348,    50,    50,    51,   473,   590,   475,
      54,   477,    51,   479,   267,    54,    60,   473,    49,   475,
      51,   477,   265,   479,   397,    33,    49,   601,    33,   259,
      33,    36,   258,    36,   564,   565,   566,   567,    82,   569,
      34,   571,    50,   573,    70,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,   258,   259,   282,    68,   284,
     285,   286,    50,    51,   267,    26,    27,    33,   432,   422,
     423,   424,    50,    32,    35,    33,    51,    36,    33,   282,
     283,   284,   285,   286,    50,    51,   312,   473,    36,   475,
      49,   477,    50,   479,    36,    50,    38,   396,   564,   565,
     566,   567,   498,   569,    33,   571,    33,   573,   564,   565,
     566,   567,    33,   569,   340,   571,   342,   573,    49,   345,
      51,    50,   348,    50,    54,   351,   352,   340,    54,    50,
     356,   357,    33,    26,    27,    36,   458,   363,   460,   392,
     513,   367,    35,    51,    32,   348,   515,    36,    36,   340,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,   430,   431,    34,   433,   434,    52,   113,   522,
     396,   397,    92,    93,    94,   427,   428,   429,   564,   565,
     566,   567,    32,   569,    32,   571,    37,   573,    37,   392,
      37,   451,    32,   396,   397,    82,    83,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,    32,   433,   434,
     435,   436,   437,   438,   439,   440,   441,    82,    83,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,   439,   440,   441,    49,
     593,    82,    83,   188,    50,    51,    34,   473,   340,   475,
      54,   477,    51,   479,     9,    10,   425,   426,   435,   436,
     473,    51,   475,   208,   477,    33,   479,     8,    32,    51,
      32,   216,   498,    33,   647,   220,   221,    33,   223,   224,
      32,   226,   473,    33,   475,   515,   477,   513,   479,    33,
     550,    33,    51,    51,    33,    49,    36,   522,    32,    34,
      33,    37,   527,    86,    36,    96,    87,    33,    51,    89,
     513,    32,   515,   258,     3,     4,     5,     6,     7,   522,
      36,    51,    51,    54,   527,    33,    51,    51,    50,    29,
      50,   340,    51,    51,    23,    24,    25,    54,   564,   565,
     566,   567,    36,   569,    33,   571,    32,   573,   601,    50,
     113,   564,   565,   566,   567,    37,   569,    33,   571,    32,
     573,    33,    37,     8,    52,    54,    36,   312,   593,    33,
     595,    33,   597,   564,   565,   566,   567,    33,   569,   639,
     571,   473,   573,   475,    33,   477,    33,   479,    34,    33,
     593,    32,   595,    32,   597,   340,    32,   342,   601,    37,
     345,    35,    37,   348,    52,    37,   351,   352,   634,   113,
      36,   356,   357,    37,    51,    33,   432,    20,   363,   645,
      51,   647,   367,    51,    51,   188,   119,    12,   270,    52,
      52,   634,    17,    18,    19,    20,    21,    22,   255,    60,
     267,   124,   645,    59,   647,   208,   106,    32,   468,    34,
      35,   396,   397,   216,   632,   118,   632,   220,   221,   452,
     223,   224,   348,   226,   473,    50,   475,   452,   477,    54,
     479,   325,   564,   565,   566,   567,   438,   569,   441,   571,
     437,   573,   597,   439,   188,   385,   440,    72,    73,    -1,
      -1,    -1,    -1,   167,    -1,   258,    81,    82,    83,    84,
      85,    -1,   176,    -1,   208,   179,    91,    -1,    -1,    -1,
      -1,    -1,   216,    -1,    -1,    -1,   220,   221,    -1,   223,
     224,    -1,   226,    -1,   198,    -1,    -1,    -1,   473,   340,
     475,    -1,   477,    -1,   479,    -1,    -1,    -1,    -1,   213,
      -1,    -1,    -1,   217,    -1,    -1,    -1,    -1,    -1,   312,
      -1,    -1,    -1,   498,   258,   564,   565,   566,   567,    -1,
     569,    -1,   571,    -1,   573,    -1,    -1,    -1,   513,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   340,    -1,   342,
      -1,    -1,   345,    -1,    -1,   348,    -1,   340,   351,   352,
      -1,    -1,    -1,   356,   357,    -1,   113,    -1,   272,    -1,
     363,    -1,    -1,    -1,   367,    -1,    -1,    -1,   312,   283,
       3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,   564,
     565,   566,   567,    -1,   569,    -1,   571,    -1,   573,    -1,
      23,    24,    25,   396,   397,    -1,   340,    -1,   342,    -1,
     314,   345,    -1,    -1,   348,    -1,    -1,   351,   352,    -1,
      -1,    -1,   356,   357,    -1,    -1,    -1,    -1,    -1,   363,
     334,    54,   473,   367,   475,    -1,   477,    -1,   479,   343,
     344,   188,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    -1,    -1,    -1,    -1,    -1,    -1,   634,
      -1,   208,   396,   397,    -1,    -1,   370,    -1,    -1,   216,
     645,    -1,   647,   220,   221,    -1,   223,   224,    -1,   226,
     473,    -1,   475,    -1,   477,    -1,   479,    -1,    -1,    -1,
     473,    -1,   475,    -1,   477,    -1,   479,    -1,    -1,    -1,
      -1,    -1,   406,    -1,    -1,   498,    -1,    -1,    -1,   340,
      11,   258,    -1,    -1,    -1,    -1,    -1,   421,    -1,    -1,
     513,    -1,    -1,   564,   565,   566,   567,    -1,   569,    -1,
     571,    -1,   573,    -1,    -1,    -1,    -1,    -1,   442,   473,
      -1,   475,    -1,   477,    -1,   479,    -1,    -1,   113,    -1,
      51,    -1,    -1,   457,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,   498,   312,    -1,    68,    -1,    -1,
     340,   564,   565,   566,   567,    -1,   569,    -1,   571,   513,
     573,   564,   565,   566,   567,    -1,   569,    -1,   571,    -1,
     573,    -1,    -1,   340,    -1,   342,    -1,    -1,   345,    -1,
      -1,   348,    -1,    -1,   351,   352,    -1,   113,    -1,   356,
     357,    -1,    -1,    -1,    -1,    -1,   363,    -1,    -1,    -1,
     367,   525,    -1,   188,    -1,    -1,    -1,    -1,    -1,    -1,
     564,   565,   566,   567,    -1,   569,    -1,   571,    -1,   573,
      -1,   634,   473,   208,   475,    -1,   477,    -1,   479,   396,
     397,   216,   645,   557,   647,   220,   221,    -1,   223,   224,
      -1,   226,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   576,    -1,    -1,    -1,    -1,   581,    -1,    -1,
      -1,    -1,   188,    -1,    -1,    -1,   590,    -1,    -1,    -1,
      -1,    -1,    -1,   258,    -1,    -1,    -1,    -1,    -1,    -1,
     634,    -1,   208,   473,    -1,   475,    -1,   477,    -1,   479,
     216,   645,    -1,   647,   220,   221,    -1,   223,   224,    -1,
     226,    -1,    -1,    -1,    -1,   629,   473,    -1,   475,    -1,
     477,    -1,   479,   564,   565,   566,   567,    -1,   569,    -1,
     571,    -1,   573,    -1,    -1,    -1,    -1,   312,    -1,    -1,
      -1,   498,   258,    -1,    -1,    -1,    -1,    -1,   167,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   513,   176,    -1,    -1,
     179,    -1,    -1,    -1,    -1,   340,    -1,   342,    -1,    -1,
     345,    -1,    -1,   348,    -1,    -1,   351,   352,    -1,   198,
      -1,   356,   357,    -1,   564,   565,   566,   567,   363,   569,
      -1,   571,   367,   573,   213,    -1,   312,    -1,   217,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   564,   565,   566,
     567,    -1,   569,    -1,   571,    -1,   573,    -1,    -1,    -1,
      -1,   396,   397,    -1,   340,    -1,   342,    -1,    -1,   345,
      -1,    -1,   348,    -1,    -1,   351,   352,    -1,    -1,    -1,
     356,   357,    -1,    -1,    -1,    -1,    -1,   363,    -1,    -1,
      -1,   367,    -1,   272,    -1,    17,    18,    19,    20,    21,
      22,    -1,    -1,    -1,   283,    -1,    -1,    -1,   182,   183,
      32,    33,    -1,    -1,    -1,    -1,    -1,   634,    -1,    -1,
     396,   397,    -1,    -1,    -1,    -1,    -1,    -1,   645,    -1,
     647,    -1,    54,    -1,    -1,   314,    -1,    -1,   473,    -1,
     475,    -1,   477,    -1,   479,    -1,    -1,    -1,    -1,    -1,
      72,    73,    -1,    -1,    -1,   334,    -1,    -1,    -1,    81,
      82,    83,    -1,   498,   343,   344,    -1,    -1,    -1,   208,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   216,   513,    -1,
      -1,   220,    -1,    -1,   223,    -1,    -1,   226,    -1,    -1,
      -1,   370,   371,    -1,    -1,    -1,    -1,   473,    -1,   475,
      -1,   477,    -1,   479,    -1,    -1,   385,    -1,   282,    11,
     284,   285,   286,    17,    18,    19,    20,    21,    22,    -1,
      -1,    -1,   498,    -1,    -1,    -1,    -1,   406,    32,   564,
     565,   566,   567,    -1,   569,    -1,   571,   513,   573,    -1,
      -1,    -1,   421,    -1,    -1,    -1,    -1,    -1,    -1,    51,
      54,    -1,    -1,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,   442,    66,    -1,    68,    -1,    72,    73,
      -1,    -1,    -1,   312,    -1,    -1,    -1,    81,   457,    -1,
      84,    85,   461,    -1,    -1,    -1,    -1,    -1,   564,   565,
     566,   567,    -1,   569,    -1,   571,    -1,   573,    -1,   634,
      -1,   340,    -1,   342,    -1,    -1,   345,    -1,    -1,    -1,
     645,    -1,   647,   352,    -1,    -1,    -1,    -1,   357,    -1,
      -1,    -1,    -1,    -1,   363,    -1,    -1,    -1,   367,    -1,
      -1,   510,   511,    -1,    -1,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   525,    -1,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   634,   433,
     434,   435,   436,   437,   438,   439,   440,   441,    -1,   645,
      -1,   647,   551,    -1,    -1,    51,    -1,    -1,   557,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    -1,    68,    -1,    -1,    -1,    -1,   576,    -1,   578,
      -1,    -1,   581,     3,     4,     5,     6,     7,    -1,    -1,
      -1,   590,    12,    -1,    -1,    -1,    -1,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    -1,    -1,    -1,    -1,
      -1,    -1,    32,    -1,   473,    -1,   475,    -1,   477,    -1,
     479,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   522,    -1,
     629,    32,    -1,   527,    54,    36,    -1,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    -1,
      -1,    -1,    72,    73,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    81,    82,    83,    84,    85,    -1,    -1,    -1,    -1,
      -1,    91,    -1,     3,     4,     5,     6,     7,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    -1,    -1,    -1,   593,
      -1,   595,    32,   597,    -1,   564,   565,   566,   567,    -1,
     569,    -1,   571,    -1,   573,     3,     4,     5,     6,     7,
      -1,    51,    -1,    -1,    54,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    72,    73,    32,    -1,    34,    35,    -1,    -1,
      -1,    81,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    51,    -1,    -1,    54,    -1,    -1,    -1,
      -1,    -1,    60,    -1,    62,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    72,    73,    74,    75,    76,    77,
      -1,    79,    80,    81,    82,    83,     3,     4,     5,     6,
       7,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    -1,    -1,    32,    -1,    34,    35,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      -1,    -1,    -1,    -1,    51,    -1,    -1,    54,    -1,    -1,
      -1,    -1,    -1,    60,    -1,    62,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    72,    73,    74,    75,    76,
      77,    -1,    79,    80,    81,    82,    83,     3,     4,     5,
       6,     7,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      -1,    -1,    28,    29,    -1,    -1,    32,    -1,    34,    35,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    -1,    -1,    -1,    -1,    51,    -1,    -1,    54,    -1,
      -1,    -1,    -1,    -1,    60,    -1,    62,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    72,    73,    74,    75,
      76,    77,    -1,    79,    80,    81,    82,    83,     3,     4,
       5,     6,     7,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    -1,    -1,    28,    29,    -1,    -1,    32,    -1,    34,
      35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    51,    -1,    -1,    54,
      -1,    -1,    -1,    -1,    -1,    60,    -1,    62,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    73,    74,
      75,    76,    77,    -1,    79,    80,    81,    82,    83,     3,
       4,     5,     6,     7,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    -1,    -1,    28,    29,    -1,    -1,    32,    -1,
      34,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    -1,    -1,
      54,    -1,    -1,    -1,    -1,    -1,    60,    -1,    62,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    73,
      74,    75,    76,    77,    -1,    79,    80,    81,    82,    83,
       3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    -1,    -1,    28,    29,    -1,    -1,    32,
      -1,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    -1,
      -1,    54,    -1,    -1,    -1,    -1,    -1,    60,    -1,    62,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,
      73,    74,    75,    76,    77,    -1,    79,    80,    81,    82,
      83,     3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    -1,    -1,    28,    29,    -1,    -1,
      32,    -1,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,
      -1,    -1,    54,    -1,    -1,    -1,    -1,    -1,    60,    -1,
      62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      72,    73,    74,    75,    76,    77,    -1,    79,    80,    81,
      82,    83,     3,     4,     5,     6,     7,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    -1,    -1,    28,    29,    -1,
      -1,    32,    -1,    34,    35,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      51,    -1,    -1,    54,    -1,    -1,    -1,    -1,    -1,    60,
      -1,    62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    72,    73,    74,    75,    76,    77,    -1,    79,    80,
      81,    82,    83,     3,     4,     5,     6,     7,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    -1,    -1,    28,    29,
      -1,    -1,    32,    -1,    34,    -1,    12,    -1,    -1,    -1,
      -1,    17,    18,    19,    20,    21,    22,    -1,    -1,    -1,
      -1,    51,    -1,    -1,    54,    -1,    32,    -1,    34,    35,
      60,    -1,    62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    72,    73,    74,    75,    76,    77,    54,    79,
      80,    81,    82,    83,    12,    -1,    -1,    -1,    -1,    17,
      18,    19,    20,    21,    22,    -1,    72,    73,    -1,    -1,
      -1,    -1,    -1,    -1,    32,    81,    82,    83,    84,    85,
      -1,    -1,    -1,    -1,    -1,    91,    -1,    -1,    -1,    -1,
      -1,    -1,    12,    51,    -1,    -1,    54,    17,    18,    19,
      20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    32,    -1,    72,    73,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    81,    82,    83,    84,    85,    -1,    -1,
      -1,    51,    -1,    91,    54,    12,    -1,    -1,    -1,    -1,
      17,    18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,
      -1,    -1,    72,    73,    -1,    32,    -1,    34,    -1,    -1,
      -1,    81,    82,    83,    84,    85,    -1,    -1,    -1,    -1,
      -1,    91,    -1,    12,    -1,    -1,    -1,    54,    17,    18,
      19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    32,    -1,    72,    73,    -1,    37,    -1,
      -1,    -1,    -1,    -1,    81,    82,    83,    84,    85,    -1,
      -1,    12,    -1,    -1,    91,    54,    17,    18,    19,    20,
      21,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    32,    33,    72,    73,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    81,    82,    83,    84,    85,    -1,    -1,    12,
      -1,    -1,    91,    54,    17,    18,    19,    20,    21,    22,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,
      33,    72,    73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      81,    82,    83,    84,    85,    -1,    -1,    12,    -1,    -1,
      91,    54,    17,    18,    19,    20,    21,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,    33,    72,
      73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    82,
      83,    84,    85,    -1,    -1,    12,    -1,    -1,    91,    54,
      17,    18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    32,    33,    72,    73,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    81,    82,    83,    84,
      85,    -1,    -1,    12,    -1,    -1,    91,    54,    17,    18,
      19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    32,    -1,    72,    73,    -1,    37,    -1,
      -1,    -1,    -1,    -1,    81,    82,    83,    84,    85,    -1,
      -1,    12,    -1,    -1,    91,    54,    17,    18,    19,    20,
      21,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    32,    33,    72,    73,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    81,    82,    83,    84,    85,    -1,    -1,    12,
      -1,    -1,    91,    54,    17,    18,    19,    20,    21,    22,
      -1,    17,    18,    19,    20,    21,    22,    -1,    -1,    32,
      33,    72,    73,    -1,    -1,    -1,    32,    33,    -1,    -1,
      81,    82,    83,    84,    85,    -1,    -1,    12,    -1,    -1,
      91,    54,    17,    18,    19,    20,    21,    22,    54,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,    -1,    72,
      73,    -1,    -1,    -1,    -1,    -1,    72,    73,    81,    82,
      83,    84,    85,    -1,    -1,    81,    82,    83,    91,    54,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      -1,    -1,    -1,    -1,    -1,    28,    29,    72,    73,    32,
      -1,    34,    -1,    -1,    -1,    -1,    81,    82,    83,    84,
      85,    -1,    -1,    -1,    -1,    -1,    91,    -1,    51,    -1,
      -1,    54,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,
      73,    74,    75,    76,    77,    -1,    79,    80,    81,    82,
      83,    15,    16,    17,    18,    19,    20,    21,    22,    -1,
      -1,    -1,    -1,    -1,    28,    29,    -1,    -1,    32,    -1,
      34,    -1,     3,     4,     5,     6,     7,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    -1,    -1,
      54,    -1,    23,    24,    25,    -1,    -1,    -1,    62,    -1,
      -1,    -1,    -1,    34,    35,    -1,    -1,    -1,    72,    73,
      74,    75,    76,    77,    -1,    79,    80,    81,    82,    83,
      51,    -1,    -1,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,     3,     4,     5,     6,     7,    -1,
      71,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    23,    24,    25,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    34,    35,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
       7,    -1,    51,    -1,    -1,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    23,    24,    25,    -1,
      -1,    -1,    71,    -1,    -1,    -1,    -1,    -1,    35,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,     6,     7,    -1,    -1,    -1,    -1,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    23,    24,
      25,    -1,    -1,    -1,    71,     3,     4,     5,     6,     7,
      35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    23,    24,    25,    -1,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      -1,    -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    17,    18,    19,
      20,    21,    22,    71,    17,    18,    19,    20,    21,    22,
      -1,    -1,    32,    33,    -1,    -1,    -1,    -1,    -1,    32,
      33,    17,    18,    19,    20,    21,    22,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    54,    -1,    32,    -1,    -1,    -1,
      -1,    54,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    72,    73,    -1,    -1,    -1,    -1,    54,    72,
      73,    81,    82,    83,    -1,    -1,    -1,    -1,    81,    82,
      83,    -1,    -1,    -1,    -1,    -1,    72,    73,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    81,    82,    83
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,    11,    51,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    68,   101,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   165,
      54,    54,   113,   114,   115,    54,     0,   118,   120,   124,
     117,   118,   113,    11,    68,   126,    69,   169,   170,    49,
      51,    69,    70,   134,   136,   137,   118,    49,    51,    54,
      54,   109,   111,   113,    34,   171,    50,   167,    54,   109,
     110,   111,   138,    34,   139,   132,   137,   131,    67,   168,
     170,   133,   136,   137,     3,     4,     5,     6,     7,    23,
      24,    25,    35,    71,   103,   104,   105,   106,   107,   108,
     109,   112,   113,   125,   143,   150,   172,   173,   174,   175,
     111,   171,    50,    34,    35,    51,    58,   114,   125,   140,
     141,   142,   143,   149,   150,   156,   157,   159,   160,   161,
     178,   139,   128,   139,    51,   171,   166,   139,   130,   137,
     129,    54,   151,    54,   144,   145,   146,   151,    36,    36,
      36,    71,   103,    51,    35,   173,   111,    15,    16,    17,
      18,    19,    20,    21,    22,    28,    29,    32,    35,    51,
      54,    60,    62,    72,    73,    74,    75,    76,    77,    79,
      80,    81,    82,    83,   102,   103,   113,   178,   179,   180,
     181,   182,   183,   185,   186,   187,   189,   190,   191,   193,
     194,   195,   196,   198,   199,   205,   206,   207,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   233,   234,
     235,   236,   237,   238,   243,   244,   245,   247,   251,   252,
     253,   254,   255,   256,   257,   259,   260,   275,   276,   158,
      32,   161,    35,   141,   156,   103,   152,   153,    34,    78,
     154,   163,   139,   171,   139,   135,   139,    32,    36,   154,
      50,    51,    38,   147,   154,    37,    37,    37,   151,   144,
     151,    32,    12,    32,    84,    85,    91,   113,   245,   253,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   278,    52,   182,    32,    49,    51,    54,    51,   278,
     178,   278,    51,    54,   104,   109,   110,   113,   251,   254,
     258,   258,    54,   144,    36,    35,   180,    51,    51,   278,
      33,     8,   192,    32,    32,    33,   183,    33,    32,    51,
     278,    51,    33,   183,    51,   278,    51,    33,   183,    33,
     190,   231,   232,    33,   183,    33,   231,    33,   183,    49,
      36,    32,    82,    83,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,   277,   178,   162,   154,   163,
     146,    33,    50,    35,    72,    73,   164,   179,   110,   155,
     163,   139,    33,   152,    37,   145,    34,   148,   176,   278,
      36,   154,    51,   154,   258,   104,   113,   278,   258,   258,
     258,    36,    13,    14,    67,    12,    91,    92,    93,    94,
      30,    31,    53,    98,    99,    90,    97,    86,    96,    87,
      89,    88,    95,    33,   183,    51,   278,    54,    51,    51,
       9,    10,   239,   240,   242,    51,    51,    36,   248,   249,
     248,    32,   278,    54,   183,   184,   185,   188,   195,   197,
     206,   208,   216,   217,   220,   221,   223,   224,   226,   227,
     229,   183,   278,   278,   183,    29,    51,    51,   182,   230,
     232,    51,    33,   231,   183,    33,   231,   183,    50,   183,
     183,    54,   278,    33,   246,   278,   274,    33,   163,   153,
      32,    32,    35,   179,    35,    50,    33,    35,    50,   148,
     177,    37,    33,    36,   250,    36,   250,    33,   258,   258,
     258,   263,   263,   264,   264,   264,   265,   265,   104,   108,
     265,   265,   266,   266,   267,   268,   269,   270,   271,   278,
      33,    32,   241,   178,   240,   242,   278,    36,   249,   250,
     250,    33,   246,    37,    52,   192,    33,    33,   184,    33,
     184,    33,   184,    33,   184,    33,    32,   190,    32,    37,
      33,    50,    33,   246,    33,   246,    35,   110,    35,    35,
      50,   258,    37,    33,    36,    33,   261,    52,   178,    33,
     246,    32,    37,    33,   184,   184,   184,   184,   184,   184,
     184,    34,   200,   278,    33,   246,   278,    51,    33,    51,
      33,    35,   148,   258,    37,   261,   273,    33,   153,    26,
      27,    35,   201,   202,   203,   204,    33,    51,    51,    33,
     278,   279,    52,    35,   202,   203,    35,   179,   204,   178,
      52,    35
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int16 yyr1[] =
{
       0,   100,   101,   102,   102,   102,   102,   102,   102,   103,
     103,   104,   104,   105,   105,   106,   106,   106,   106,   106,
     107,   107,   108,   108,   109,   110,   111,   112,   112,   112,
     113,   113,   114,   115,   116,   116,   116,   116,   116,   116,
     116,   117,   117,   118,   118,   119,   120,   120,   121,   122,
     123,   124,   124,   124,   125,   125,   126,   126,   126,   126,
     126,   126,   126,   126,   126,   126,   128,   127,   129,   127,
     130,   127,   131,   127,   132,   127,   133,   127,   134,   127,
     135,   127,   136,   137,   138,   138,   139,   139,   140,   140,
     141,   141,   141,   142,   142,   143,   143,   144,   144,   145,
     145,   146,   147,   146,   148,   148,   149,   149,   150,   150,
     150,   150,   150,   150,   150,   150,   151,   151,   151,   152,
     152,   153,   154,   155,   155,   156,   156,   158,   157,   159,
     159,   159,   159,   160,   161,   162,   161,   163,   163,   163,
     163,   164,   164,   164,   164,   166,   165,   167,   165,   168,
     165,   169,   165,   170,   170,   171,   171,   172,   172,   173,
     173,   174,   175,   176,   176,   176,   176,   177,   177,   178,
     178,   179,   179,   180,   180,   181,   181,   182,   183,   183,
     183,   183,   183,   183,   184,   184,   184,   184,   184,   185,
     185,   185,   185,   185,   185,   185,   185,   185,   185,   185,
     186,   187,   188,   189,   190,   190,   190,   190,   190,   190,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   200,   200,   200,   201,   201,   202,   203,   203,   204,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   228,   228,   228,   228,   228,
     228,   228,   229,   229,   229,   229,   229,   229,   229,   229,
     230,   230,   231,   232,   232,   233,   233,   234,   234,   235,
     235,   236,   237,   238,   238,   238,   239,   239,   241,   240,
     242,   243,   243,   244,   244,   244,   244,   244,   244,   244,
     245,   245,   246,   246,   247,   247,   247,   247,   248,   248,
     249,   250,   250,   251,   251,   252,   253,   253,   253,   253,
     253,   253,   254,   254,   255,   255,   255,   255,   256,   257,
     258,   258,   258,   258,   258,   259,   260,   261,   261,   261,
     261,   262,   262,   262,   262,   263,   263,   263,   263,   264,
     264,   264,   265,   265,   265,   265,   266,   266,   266,   266,
     266,   266,   267,   267,   267,   268,   268,   269,   269,   270,
     270,   271,   271,   272,   272,   273,   273,   274,   274,   275,
     276,   276,   276,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   277,   278,   279
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     3,     3,
       1,     1,     1,     3,     2,     1,     2,     1,     3,     2,
       1,     1,     2,     1,     2,     3,     1,     1,     1,     3,
       5,     1,     1,     1,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     6,     0,     6,
       0,     6,     0,     5,     0,     5,     0,     5,     0,     4,
       0,     7,     2,     2,     1,     3,     3,     2,     1,     2,
       1,     1,     1,     1,     1,     4,     3,     1,     3,     1,
       3,     1,     0,     4,     1,     1,     2,     1,     4,     3,
       3,     2,     4,     3,     3,     2,     3,     4,     3,     1,
       3,     2,     2,     1,     3,     1,     1,     0,     3,     4,
       3,     3,     2,     2,     3,     0,     4,     4,     3,     3,
       2,     5,     4,     5,     4,     0,     6,     0,     5,     0,
       5,     0,     4,     2,     3,     2,     3,     1,     2,     1,
       1,     1,     2,     4,     3,     3,     2,     1,     3,     3,
       2,     1,     2,     1,     1,     2,     3,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     3,     2,     1,     1,     1,     1,     1,     1,
       1,     2,     1,     2,     3,     3,     3,     3,     1,     5,
       4,     3,     3,     2,     1,     2,     2,     1,     2,     3,
       2,     1,     3,     3,     3,     1,     5,     3,     1,     3,
       2,     2,     3,     3,     3,     2,     3,     3,     3,     2,
       2,     2,     2,     2,     3,     3,     2,     3,     2,     2,
       2,     3,     3,     3,     2,     3,     2,     2,     2,     3,
       1,     1,     1,     1,     3,     2,     3,     3,     2,     2,
       3,     3,     5,     3,     4,     3,     1,     2,     0,     6,
       2,     1,     1,     1,     1,     3,     1,     1,     1,     1,
       5,     4,     1,     3,     4,     3,     4,     3,     1,     2,
       3,     2,     3,     3,     3,     1,     4,     3,     6,     5,
       6,     5,     4,     4,     1,     1,     1,     1,     2,     2,
       1,     1,     2,     2,     1,     2,     2,     1,     2,     2,
       1,     5,     4,     4,     5,     1,     3,     3,     3,     1,
       3,     3,     1,     3,     3,     3,     1,     3,     3,     3,
       3,     3,     1,     3,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     5,     1,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 747 "parser.y"
                {
  
  
}
#line 2980 "parser.tab.c"
    break;

  case 3:
#line 752 "parser.y"
               {
  strcpy(((yyval.typ)).tempvar,newtemp().c_str());
  emit("=",((yyvsp[0].lex)).str,"null",((yyval.typ)).tempvar, -1);
  strcpy(((yyval.typ)).type,"int");
}
#line 2990 "parser.tab.c"
    break;

  case 4:
#line 757 "parser.y"
                       {
  strcpy(((yyval.typ)).tempvar,newtemp().c_str());
  emit("=",((yyvsp[0].lex)).str,"null",((yyval.typ)).tempvar, -1);
  strcpy(((yyval.typ)).type,"float");
  
}
#line 3001 "parser.tab.c"
    break;

  case 5:
#line 763 "parser.y"
                 {
  strcpy(((yyval.typ)).tempvar,newtemp().c_str());
  emit("=",((yyvsp[0].lex)).str,"null",((yyval.typ)).tempvar, -1);
  strcpy(((yyval.typ)).type,"boolean");
}
#line 3011 "parser.tab.c"
    break;

  case 6:
#line 768 "parser.y"
                   {
  strcpy(((yyval.typ)).tempvar,newtemp().c_str());
  emit("=",((yyvsp[0].lex)).str,"null",((yyval.typ)).tempvar, -1);
  strcpy(((yyval.typ)).type,"char");
}
#line 3021 "parser.tab.c"
    break;

  case 7:
#line 773 "parser.y"
                {
  strcpy(((yyval.typ)).tempvar,newtemp().c_str());
  emit("=",((yyvsp[0].lex)).str,"null",((yyval.typ)).tempvar, -1);
  strcpy(((yyval.typ)).type,"string");
}
#line 3031 "parser.tab.c"
    break;

  case 8:
#line 778 "parser.y"
              {
  strcpy(((yyval.typ)).tempvar,newtemp().c_str());
  emit("=",((yyvsp[0].lex)).str,"null",((yyval.typ)).tempvar, -1);
  strcpy(((yyval.typ)).type,"null");
}
#line 3041 "parser.tab.c"
    break;

  case 9:
#line 785 "parser.y"
               {
  strcpy(((yyval.typ)).tempvar,((yyvsp[0].typ)).tempvar);

  ((yyval.typ)).size = ((yyvsp[0].typ)).size;
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
  type = ((yyvsp[0].typ)).type;
  size = ((yyvsp[0].typ)).size;
}
#line 3054 "parser.tab.c"
    break;

  case 10:
#line 793 "parser.y"
               {
  strcpy(((yyval.typ)).tempvar,((yyvsp[0].typ)).tempvar);

  ((yyval.typ)).size = ((yyvsp[0].typ)).size;
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
  type = ((yyvsp[0].typ)).type;
  size = ((yyvsp[0].typ)).size;
  // cout<<"RRS"<<($1).type;
  if(curr_table->lookup(string((char*)((yyvsp[0].typ)).type)).offset == -1 && checkobj(string((char*)((yyvsp[0].typ)).type)) == 0){
      string s=((yyvsp[0].typ)).type;
      string yo="";
      for(int i=0;i<(int)s.size();i++)
      {
        if(s[i]=='[')
        {
          break;
        }
        yo+=string(1,s[i]);
      }
    if(strcmp(yo.c_str(),"String"))
    {
      cout<<"Undeclared variable on line "<<((yyvsp[0].typ)).type<< yylineno<<"\n";
    }
  }
}
#line 3084 "parser.tab.c"
    break;

  case 11:
#line 820 "parser.y"
            {
  strcpy(((yyval.typ)).tempvar,((yyvsp[0].typ)).tempvar);

  ((yyval.typ)).size = ((yyvsp[0].typ)).size;
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
}
#line 3095 "parser.tab.c"
    break;

  case 12:
#line 826 "parser.y"
         {
  strcpy(((yyval.typ)).tempvar,((yyvsp[0].lex)).str);
  
  ((yyval.typ)).size = 1;
  strcpy(((yyval.typ)).type, "boolean");
}
#line 3106 "parser.tab.c"
    break;

  case 13:
#line 833 "parser.y"
             {
  strcpy(((yyval.typ)).tempvar,((yyvsp[0].typ)).tempvar);

  ((yyval.typ)).size = ((yyvsp[0].typ)).size;
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
}
#line 3117 "parser.tab.c"
    break;

  case 14:
#line 839 "parser.y"
                   {
  strcpy(((yyval.typ)).tempvar,((yyvsp[0].typ)).tempvar);

  ((yyval.typ)).size = ((yyvsp[0].typ)).size;
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
}
#line 3128 "parser.tab.c"
    break;

  case 15:
#line 846 "parser.y"
     {
  strcpy(((yyval.typ)).tempvar,((yyvsp[0].lex)).str);

  ((yyval.typ)).size = 1;
  strcpy(((yyval.typ)).type, "byte"); 
}
#line 3139 "parser.tab.c"
    break;

  case 16:
#line 852 "parser.y"
        {
  strcpy(((yyval.typ)).tempvar,((yyvsp[0].lex)).str);

  ((yyval.typ)).size = 2;
  strcpy(((yyval.typ)).type, "short");
}
#line 3150 "parser.tab.c"
    break;

  case 17:
#line 858 "parser.y"
      {
  strcpy(((yyval.typ)).tempvar,((yyvsp[0].lex)).str);

  ((yyval.typ)).size = 4;
  strcpy(((yyval.typ)).type, "int");
}
#line 3161 "parser.tab.c"
    break;

  case 18:
#line 864 "parser.y"
      {
  strcpy(((yyval.typ)).tempvar,((yyvsp[0].lex)).str);

  ((yyval.typ)).size = 8;
  strcpy(((yyval.typ)).type, "long");
}
#line 3172 "parser.tab.c"
    break;

  case 19:
#line 870 "parser.y"
      {
  strcpy(((yyval.typ)).tempvar,((yyvsp[0].lex)).str);

  ((yyval.typ)).size = 1;
  strcpy(((yyval.typ)).type, "char");
}
#line 3183 "parser.tab.c"
    break;

  case 20:
#line 877 "parser.y"
      {
  strcpy(((yyval.typ)).tempvar,((yyvsp[0].lex)).str);

  ((yyval.typ)).size = 4;
  strcpy(((yyval.typ)).type, "float");
}
#line 3194 "parser.tab.c"
    break;

  case 21:
#line 883 "parser.y"
        {
  strcpy(((yyval.typ)).tempvar,((yyvsp[0].lex)).str);

  ((yyval.typ)).size = 8;
  strcpy(((yyval.typ)).type, "double");
}
#line 3205 "parser.tab.c"
    break;

  case 22:
#line 890 "parser.y"
                     {
  strcpy(((yyval.typ)).tempvar,((yyvsp[0].typ)).tempvar);

  strcpy(((yyval.typ)).type, ((yyvsp[0].typ)).type);
  ((yyval.typ)).size = ((yyvsp[0].typ)).size;
}
#line 3216 "parser.tab.c"
    break;

  case 23:
#line 896 "parser.y"
           {
  strcpy(((yyval.typ)).tempvar,((yyvsp[0].typ)).tempvar);

  strcpy(((yyval.typ)).type, ((yyvsp[0].typ)).type);
  ((yyval.typ)).size = ((yyvsp[0].typ)).size;
}
#line 3227 "parser.tab.c"
    break;

  case 24:
#line 903 "parser.y"
     {
  strcpy(((yyval.typ)).tempvar,((yyvsp[0].typ)).tempvar);

  strcpy(((yyval.typ)).type, ((yyvsp[0].typ)).type);
  ((yyval.typ)).size = ((yyvsp[0].typ)).size;
}
#line 3238 "parser.tab.c"
    break;

  case 25:
#line 910 "parser.y"
                     {
  strcpy(((yyval.typ)).tempvar,((yyvsp[0].typ)).tempvar);

  strcpy(((yyval.typ)).type, ((yyvsp[0].typ)).type);
  ((yyval.typ)).size = ((yyvsp[0].typ)).size;
}
#line 3249 "parser.tab.c"
    break;

  case 26:
#line 917 "parser.y"
                     {
  strcpy(((yyval.typ)).tempvar,((yyvsp[0].typ)).tempvar);

  strcpy(((yyval.typ)).type, ((yyvsp[0].typ)).type);
  ((yyval.typ)).size = ((yyvsp[0].typ)).size;
}
#line 3260 "parser.tab.c"
    break;

  case 27:
#line 924 "parser.y"
                                                   {

  strcpy(((yyval.typ)).type,strcat(((yyvsp[-2].typ)).type,"[]"));
  strcpy(((yyval.typ)).arrtype, ((yyvsp[-2].typ)).type);
  ((yyval.typ)).ndim = 1;
  ((yyval.typ)).size = ((yyvsp[-2].typ)).size*((yyval.typ)).ndim;
}
#line 3272 "parser.tab.c"
    break;

  case 28:
#line 931 "parser.y"
                                           {
  strcpy(((yyval.typ)).type,strcat(((yyvsp[-2].typ)).type,"[]"));
  strcpy(((yyval.typ)).arrtype, ((yyvsp[-2].typ)).type);
  ((yyval.typ)).ndim =1;
  ((yyval.typ)).size = ((yyvsp[-2].typ)).size*((yyval.typ)).ndim;
}
#line 3283 "parser.tab.c"
    break;

  case 29:
#line 937 "parser.y"
                                                {
  strcpy(((yyval.typ)).type,strcat(((yyvsp[-2].typ)).type,"[]"));
  strcpy(((yyval.typ)).arrtype, ((yyvsp[-2].typ)).type);
  ((yyval.typ)).ndim = ((yyvsp[-2].typ)).ndim+1;
  ((yyval.typ)).size = ((yyvsp[-2].typ)).size*((yyval.typ)).ndim;
}
#line 3294 "parser.tab.c"
    break;

  case 30:
#line 944 "parser.y"
           {
   strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);

   strcpy(((yyval.typ)).type, ((yyvsp[0].typ)).type);
   ((yyval.typ)).size = ((yyvsp[0].typ)).size;
}
#line 3305 "parser.tab.c"
    break;

  case 31:
#line 950 "parser.y"
               {
  strcpy(((yyval.typ)).tempvar,((yyvsp[0].typ)).tempvar);

  strcpy(((yyval.typ)).type, ((yyvsp[0].typ)).type);
  ((yyval.typ)).size = ((yyvsp[0].typ)).size;
}
#line 3316 "parser.tab.c"
    break;

  case 32:
#line 957 "parser.y"
           {
  // cout<<($1).str<<" scope: "<<curr_table->lookup(string((char*)($1).str)).scope_name.substr(0,6)<<'\n';
  // cout<<"KKL"<<curr_scope.substr(0,6).c_str()<<" "<<curr_scope.substr(6,curr_scope.size()-6).c_str()<<'\n';
  if(!strcmp(((yyvsp[0].lex)).str,"System")) issystem=1;
  if(curr_table->lookup(string((char*)((yyvsp[0].lex)).str)).offset==-1)
  {
    if(strcmp(((yyvsp[0].lex)).str,"String"))
    {
      if(!isimport||!issystem) cout<<"Undeclared variable "<<((yyvsp[0].lex)).str<<" on line "<<yylineno<<'\n';
      // else isimport=0;
    }
  }
  else
  {
    if(strcmp(curr_table->lookup(string((char*)((yyvsp[0].lex)).str)).scope_name.substr(0,6).c_str(),"Method"))
    {
      if(!strcmp(curr_scope.substr(0,6).c_str(),"Method")&&curr_table->lookup(curr_scope.substr(6,curr_scope.size()-6).c_str()).isitstatic)
      {
        if(curr_table->lookup(string((char*)((yyvsp[0].lex)).str)).isitstatic==0)
        {
          if(strcmp(curr_table->lookup(string((char*)((yyvsp[0].lex)).str)).token.c_str(),"Class")) cout<<"Cannot access non static variable "<<((yyvsp[0].lex)).str<<" in static function on line "<<yylineno<<'\n';
        }
      }
    }
    if(!strcmp(curr_table->lookup(string((char*)((yyvsp[0].lex)).str)).token.c_str(),"Class"))
    {
      isclassaccess=1;
      // cout<<"Class access\n";
    }
    // cout<<curr_table->lookup(string((char*)($1).str)).scope_name<<'\n';
  }
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].lex)).str);

  strcpy(((yyval.typ)).type, ((yyvsp[0].lex)).str);
  ((yyval.typ)).size = (string((char*)((yyvsp[0].lex)).str)).size();
}
#line 3357 "parser.tab.c"
    break;

  case 33:
#line 994 "parser.y"
                    {
    // cout<<"LJO"<<(char*)($1).type<<'\n';
    string mo=curr_table->lookup(string((char*)((yyvsp[-2].typ)).type)).type;
    string s = string((char*)((yyvsp[-2].typ)).type) + "." + string((char*)((yyvsp[0].lex)).str);
    string s1 = mo + "." + string((char*)((yyvsp[0].lex)).str);
    strcpy(((yyval.typ)).tempvar, s.c_str());
    isaccess=1;
    fullname=s;
    classname=mo;
    // auto it = checkobjentry(s, 1, mo);
    // cout<<"AAA\n";
    // cout<<"LJKK"<<checkobj(s1)<<endl;
    if(checkobj(s1)){
      strcpy(((yyval.typ)).type, (typeobj(s)).c_str());
      if(!strcmp((typeobj(s)).c_str(),"private"))
      {
        cout<<"Accessing private variable from outside class on line "<<yylineno<<'\n';
      }
      else if(!strcmp((typeobj(s)).c_str(),"null"))
      {
        cout<<"Accessing undeclared variable from outside class on line "<<yylineno<<'\n';
      }
    }
    else
    {
      // cout<<isimport<<issystem<<'\n';
      if(!isimport||!issystem) cout<<"The variable you are trying to reach is currently undefined on line "<<yylineno<<". Please try again later\n";
      // else isimport=0;
    }
    if(checkobj(s1)==1 and isclassaccess==1)
    {
      cout<<"Invalid: Accessing non static variable from static context on line "<<yylineno<<endl;
    }
    isclassaccess=0;
    // issystem=0;
    ((yyval.typ)).size = ((yyvsp[-2].typ)).size + 1 + (string((char*)(((yyvsp[0].lex)).str))).size();
    // cout<<"GGG"<<($$).type<<'\n';
}
#line 3400 "parser.tab.c"
    break;

  case 34:
#line 1033 "parser.y"
                                      {
}
#line 3407 "parser.tab.c"
    break;

  case 35:
#line 1035 "parser.y"
                    {
}
#line 3414 "parser.tab.c"
    break;

  case 36:
#line 1037 "parser.y"
                                     {
}
#line 3421 "parser.tab.c"
    break;

  case 37:
#line 1039 "parser.y"
                  {
}
#line 3428 "parser.tab.c"
    break;

  case 38:
#line 1041 "parser.y"
                                                        {
}
#line 3435 "parser.tab.c"
    break;

  case 39:
#line 1043 "parser.y"
                                     {
}
#line 3442 "parser.tab.c"
    break;

  case 40:
#line 1045 "parser.y"
                    { 
}
#line 3449 "parser.tab.c"
    break;

  case 41:
#line 1049 "parser.y"
                  {
  // isimport=0;
}
#line 3457 "parser.tab.c"
    break;

  case 42:
#line 1052 "parser.y"
                                      {
  // isimport=0;
}
#line 3465 "parser.tab.c"
    break;

  case 43:
#line 1057 "parser.y"
                {
}
#line 3472 "parser.tab.c"
    break;

  case 44:
#line 1059 "parser.y"
                                  {
}
#line 3479 "parser.tab.c"
    break;

  case 45:
#line 1063 "parser.y"
                       {isclassaccess=0; issystem=0;isfinal=0;
}
#line 3486 "parser.tab.c"
    break;

  case 46:
#line 1066 "parser.y"
                            {
}
#line 3493 "parser.tab.c"
    break;

  case 47:
#line 1068 "parser.y"
                               {
}
#line 3500 "parser.tab.c"
    break;

  case 48:
#line 1071 "parser.y"
                    {
  isimport = 1;
}
#line 3508 "parser.tab.c"
    break;

  case 49:
#line 1076 "parser.y"
                           {isclassaccess=0;issystem=0;isfinal=0;isimport=0;
}
#line 3515 "parser.tab.c"
    break;

  case 50:
#line 1079 "parser.y"
                                    {isclassaccess=0;issystem=0;isfinal=0;isimport=0;
}
#line 3522 "parser.tab.c"
    break;

  case 51:
#line 1082 "parser.y"
                 {
  isimport=0;
}
#line 3530 "parser.tab.c"
    break;

  case 52:
#line 1085 "parser.y"
                      {
  isimport=0;
}
#line 3538 "parser.tab.c"
    break;

  case 53:
#line 1088 "parser.y"
           {isclassaccess=0;issystem=0;isfinal=0;
}
#line 3545 "parser.tab.c"
    break;

  case 54:
#line 1091 "parser.y"
         {
}
#line 3552 "parser.tab.c"
    break;

  case 55:
#line 1093 "parser.y"
                    {
}
#line 3559 "parser.tab.c"
    break;

  case 56:
#line 1096 "parser.y"
        {
}
#line 3566 "parser.tab.c"
    break;

  case 57:
#line 1098 "parser.y"
           {
}
#line 3573 "parser.tab.c"
    break;

  case 58:
#line 1100 "parser.y"
         {
  isprivate=1;
  isfieldprivate=1;
}
#line 3582 "parser.tab.c"
    break;

  case 59:
#line 1104 "parser.y"
        {
  isstatic=1;
}
#line 3590 "parser.tab.c"
    break;

  case 60:
#line 1107 "parser.y"
          {
}
#line 3597 "parser.tab.c"
    break;

  case 61:
#line 1109 "parser.y"
        { isfinal=1;
}
#line 3604 "parser.tab.c"
    break;

  case 62:
#line 1111 "parser.y"
         {
}
#line 3611 "parser.tab.c"
    break;

  case 63:
#line 1113 "parser.y"
               {
}
#line 3618 "parser.tab.c"
    break;

  case 64:
#line 1115 "parser.y"
            {
}
#line 3625 "parser.tab.c"
    break;

  case 65:
#line 1117 "parser.y"
          {
}
#line 3632 "parser.tab.c"
    break;

  case 66:
#line 1121 "parser.y"
                                  {
  emit(((yyvsp[-2].lex)).str,":","","",-1);
  emit("BeginClass","","","",-1);
  // code.push_back("Begin" + string((char*)($2).str));

  curr_table->entry(string((char*)((yyvsp[-2].lex)).str),"Class", string((char*)((yyvsp[-2].lex)).str), offset, curr_scope, yylineno, -1);
  tables.push(curr_table);
  curr_table = new Sym_Table(curr_table);
  list_of_Symbol_Tables.push_back(curr_table);
  scope_names.push(curr_scope);
  string new_scope = "Class" + string((char*)((yyvsp[-2].lex)).str);
  curr_scope = new_scope;
  curr_class=new_scope;
  offsets.push(offset);
  int new_offset = 0;
  offset = new_offset; 
}
#line 3654 "parser.tab.c"
    break;

  case 67:
#line 1138 "parser.y"
          {
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  offset = offsets.top(); offsets.pop();
  objects.clear();
  emit("EndClass","","","",-1);
}
#line 3666 "parser.tab.c"
    break;

  case 68:
#line 1145 "parser.y"
                                       {
  emit(((yyvsp[-1].lex)).str,":","","",-1);
  emit("BeginClass","","","",-1);
  // code.push_back("Begin" + string((char*)($3).str));
  if(isstatic)
  {
    cout<<"Class can not be defined as static on line "<<yylineno<<'\n';
    isstatic=0;
  }
  if(isprivate)
  {
    cout<<"Class can not be defined as private on line "<<yylineno<<'\n';
    isprivate=0;
  }
  curr_table->entry(string((char*)((yyvsp[-1].lex)).str),"Class", string((char*)((yyvsp[-1].lex)).str), offset, curr_scope, yylineno, -1);
  tables.push(curr_table);
  curr_table = new Sym_Table(curr_table);
  list_of_Symbol_Tables.push_back(curr_table);
  scope_names.push(curr_scope);
  string new_scope = "Class" + string((char*)((yyvsp[-1].lex)).str);
  curr_scope = new_scope;
  curr_class=new_scope;
  offsets.push(offset);
  int new_offset = 0;
  offset = new_offset; 
  isprivate=0;
  isfieldprivate=0;
}
#line 3699 "parser.tab.c"
    break;

  case 69:
#line 1173 "parser.y"
          {
  
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  offset = offsets.top(); offsets.pop();
  objects.clear();
  emit("EndClass","","","",-1);
}
#line 3712 "parser.tab.c"
    break;

  case 70:
#line 1181 "parser.y"
                                  {
  emit(((yyvsp[-1].lex)).str,":","","",-1);
  emit("BeginClass","","","",-1);
  // code.push_back("Begin" + string((char*)($3).str));
  if(isstatic)
  {
    cout<<"Class can not be defined as static on line "<<yylineno<<'\n';
  }
  if(isprivate)
  {
    cout<<"Class can not be defined as private on line "<<yylineno<<'\n';
    isprivate=0;
  }
  isstatic=0;
  isprivate=0;
  curr_table->entry(string((char*)((yyvsp[-1].lex)).str),"Class", string((char*)((yyvsp[-1].lex)).str), offset, curr_scope, yylineno, -1);
  tables.push(curr_table);
  curr_table = new Sym_Table(curr_table);
  list_of_Symbol_Tables.push_back(curr_table);
  scope_names.push(curr_scope);
  string new_scope = "Class" + string((char*)((yyvsp[-1].lex)).str);
  curr_scope = new_scope;
  curr_class=new_scope;
  offsets.push(offset);
  int new_offset = 0;
  offset = new_offset;
  isfieldprivate=0;
}
#line 3745 "parser.tab.c"
    break;

  case 71:
#line 1209 "parser.y"
          {
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  offset = offsets.top(); offsets.pop();
  objects.clear();
  emit("EndClass","","","",-1);
}
#line 3757 "parser.tab.c"
    break;

  case 72:
#line 1216 "parser.y"
                             {
  // code.push_back("Begin" + string((char*)($2).str));
  emit(((yyvsp[-1].lex)).str,":","","",-1);
  emit("BeginClass","","","",-1);
  curr_table->entry(string((char*)((yyvsp[-1].lex)).str),"Class", string((char*)((yyvsp[-1].lex)).str), offset, curr_scope, yylineno, -1);
  tables.push(curr_table);
  curr_table = new Sym_Table(curr_table);
  list_of_Symbol_Tables.push_back(curr_table);
  scope_names.push(curr_scope);
  string new_scope = "Class" + string((char*)((yyvsp[-1].lex)).str);
  curr_scope = new_scope;
  curr_class=new_scope;
  offsets.push(offset);
  int new_offset = 0;
  offset = new_offset;
}
#line 3778 "parser.tab.c"
    break;

  case 73:
#line 1232 "parser.y"
          {
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  offset = offsets.top(); offsets.pop();
  objects.clear();
  emit("EndClass","","","",-1);
}
#line 3790 "parser.tab.c"
    break;

  case 74:
#line 1239 "parser.y"
                        {
  // code.push_back("Begin" + string((char*)($2).str));
  emit(((yyvsp[-1].lex)).str,":","","",-1);
  emit("BeginClass","","","",-1);
  curr_table->entry(string((char*)((yyvsp[-1].lex)).str),"Class", string((char*)((yyvsp[-1].lex)).str), offset, curr_scope, yylineno, -1);
  tables.push(curr_table);
  curr_table = new Sym_Table(curr_table);
  list_of_Symbol_Tables.push_back(curr_table);
  scope_names.push(curr_scope);
  string new_scope = "Class" + string((char*)((yyvsp[-1].lex)).str);
  curr_scope = new_scope;
  curr_class=new_scope;
  offsets.push(offset);
  int new_offset = 0;
  offset = new_offset;
}
#line 3811 "parser.tab.c"
    break;

  case 75:
#line 1255 "parser.y"
          {
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  offset = offsets.top(); offsets.pop();
  objects.clear();
  emit("EndClass","","","",-1);
}
#line 3823 "parser.tab.c"
    break;

  case 76:
#line 1262 "parser.y"
                            {
  emit(((yyvsp[0].lex)).str,":","","",-1);
  emit("BeginClass","","","",-1);
  // code.push_back("Begin" + string((char*)($3).str));
  if(isstatic)
  {
    cout<<"Class can not be defined as static on line "<<yylineno<<'\n';
  }
  if(isprivate)
  {
    cout<<"Class can not be defined as private on line "<<yylineno<<'\n';
    isprivate=0;
  }
  isstatic=0;
  isprivate=0;

  curr_table->entry(string((char*)((yyvsp[0].lex)).str),"Class", string((char*)((yyvsp[0].lex)).str), offset, curr_scope, yylineno, -1);
  tables.push(curr_table);
  curr_table = new Sym_Table(curr_table);
  list_of_Symbol_Tables.push_back(curr_table);
  scope_names.push(curr_scope);
  string new_scope = "Class" + string((char*)((yyvsp[0].lex)).str);
  curr_scope = new_scope;
  curr_class=new_scope;
  offsets.push(offset);
  int new_offset = 0;
  offset = new_offset;
  isfieldprivate=0;
}
#line 3857 "parser.tab.c"
    break;

  case 77:
#line 1291 "parser.y"
          {
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  offset = offsets.top(); offsets.pop();
  objects.clear();
  emit("EndClass","","","",-1);
}
#line 3869 "parser.tab.c"
    break;

  case 78:
#line 1298 "parser.y"
                  {
  // code.push_back("Begin" + string((char*)($2).str));
  emit(((yyvsp[0].lex)).str,":","","",-1);
  emit("BeginClass","","","",-1);
  curr_table->entry(string((char*)((yyvsp[0].lex)).str),"Class", string((char*)((yyvsp[0].lex)).str), offset, curr_scope, yylineno, -1);
  tables.push(curr_table);
  curr_table = new Sym_Table(curr_table);
  list_of_Symbol_Tables.push_back(curr_table);
  scope_names.push(curr_scope);
  string new_scope = "Class" + string((char*)((yyvsp[0].lex)).str);
  curr_scope = new_scope;
  curr_class=new_scope;
  offsets.push(offset);
  int new_offset = 0;
  offset = new_offset;
}
#line 3890 "parser.tab.c"
    break;

  case 79:
#line 1314 "parser.y"
          {
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  offset = offsets.top(); offsets.pop();
  objects.clear();
  emit("EndClass","","","",-1);
}
#line 3902 "parser.tab.c"
    break;

  case 80:
#line 1321 "parser.y"
                                             {
  emit(((yyvsp[-2].lex)).str,":","","",-1);
  emit("BeginClass","","","",-1);
  // code.push_back("Begin" + string((char*)($3).str));
  if(isstatic)
  {
    cout<<"Class can not be defined as static on line "<<yylineno<<'\n';
  }
  if(isprivate)
  {
    cout<<"Class can not be defined as private on line "<<yylineno<<'\n';
    isprivate=0;
  }
  isstatic=0;
  isprivate=0;

  curr_table->entry(string((char*)((yyvsp[-2].lex)).str),"Class", string((char*)((yyvsp[-2].lex)).str), offset, curr_scope, yylineno, -1);
  tables.push(curr_table);
  curr_table = new Sym_Table(curr_table);
  list_of_Symbol_Tables.push_back(curr_table);
  scope_names.push(curr_scope);
  string new_scope = "Class" + string((char*)((yyvsp[-2].lex)).str);
  curr_scope = new_scope;
  curr_class=new_scope;
  offsets.push(offset);
  int new_offset = 0;
  offset = new_offset;
  isfieldprivate=0;
}
#line 3936 "parser.tab.c"
    break;

  case 81:
#line 1350 "parser.y"
          {
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  offset = offsets.top(); offsets.pop();
  objects.clear();
  emit("EndClass","","","",-1);
}
#line 3948 "parser.tab.c"
    break;

  case 82:
#line 1358 "parser.y"
                  {
  
  
  
}
#line 3958 "parser.tab.c"
    break;

  case 83:
#line 1364 "parser.y"
                             {
  
  
  
}
#line 3968 "parser.tab.c"
    break;

  case 84:
#line 1370 "parser.y"
              {
  
  
}
#line 3977 "parser.tab.c"
    break;

  case 85:
#line 1374 "parser.y"
                                       {
  
  
  
  
}
#line 3988 "parser.tab.c"
    break;

  case 86:
#line 1381 "parser.y"
                                                         {
  isprivate=0;
}
#line 3996 "parser.tab.c"
    break;

  case 87:
#line 1384 "parser.y"
                                    {
  isprivate=0;
}
#line 4004 "parser.tab.c"
    break;

  case 88:
#line 1388 "parser.y"
                     {
  
  
}
#line 4013 "parser.tab.c"
    break;

  case 89:
#line 1392 "parser.y"
                                            {
  
  
  
}
#line 4023 "parser.tab.c"
    break;

  case 90:
#line 1398 "parser.y"
                       {
  
  
}
#line 4032 "parser.tab.c"
    break;

  case 91:
#line 1402 "parser.y"
                   {
  isstatic=0;
}
#line 4040 "parser.tab.c"
    break;

  case 92:
#line 1405 "parser.y"
                        {
  
  
}
#line 4049 "parser.tab.c"
    break;

  case 93:
#line 1410 "parser.y"
                 {
  
  
}
#line 4058 "parser.tab.c"
    break;

  case 94:
#line 1414 "parser.y"
                   {
  
  
}
#line 4067 "parser.tab.c"
    break;

  case 95:
#line 1419 "parser.y"
                                             {
  isfinal=0;
  isclassaccess=0;
  issystem=0;
  if(strcmp(((yyvsp[-1].typ)).type,"Dishay"))
  {
    if(strcmp(((yyvsp[-2].typ)).type,((yyvsp[-1].typ)).type))
    {
      cout<<((yyvsp[-2].typ)).type<<" "<<((yyvsp[-1].typ)).type<<" "<<"Invalid operator on line "<< yylineno<<"\n";
    }
    else
    {
      strcpy(((yyval.typ)).type,((yyvsp[-2].typ)).type);
    }
  }  
  if(funcparam.size()){
    for(int i=0;i<(int)funcparam.size();i++){
      for(auto it: funcparam[i].second.first){
        // cout<<"FFF"<<isstatic<<'\n';
        if(it == '['){
          fl = 1;
          break;
        }
      }
      if(fl == 0)
      curr_table->entry(funcparam[i].first, "Identifier", funcparam[i].second.first, offset, curr_scope, yylineno, funcparam[i].second.second);
      else 
      curr_table->entry(funcparam[i].first, "Array", funcparam[i].second.first, offset, curr_scope, yylineno, funcparam[i].second.second);
      offset += size;
if(addoff > 0){ offset += (addoff-1)*getsize(type);}
addoff = 0;;
      fl = 0;
      // if(isfieldprivate)
      // {
      //   (curr_table->lookup(funcparam[i].first).isprivate)=1;
      //   cout<<"YOOO"<<curr_table->lookup(funcparam[i].first).isprivate<<funcparam[i].first<<'\n';
      // }
    }
    funcargno = -1;
    funcparam.clear();
  }
  isfieldprivate=0;
  isstatic=0;

}
#line 4117 "parser.tab.c"
    break;

  case 96:
#line 1464 "parser.y"
                                    {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[-2].typ)).tempvar);
  isclassaccess=0;
issystem=0;
  if(strcmp(((yyvsp[-1].typ)).type,"Dishay"))
  {
    if(strcmp(((yyvsp[-2].typ)).type,((yyvsp[-1].typ)).type))
    {
      cout<<((yyvsp[-2].typ)).type<<" "<<((yyvsp[-1].typ)).type<<" "<<"Invalid operator on line "<< yylineno<<"\n";
    }
    else
    {
      strcpy(((yyval.typ)).type,((yyvsp[-2].typ)).type);
    }
  }
  if(funcparam.size()){
    for(int i=0;i<(int)funcparam.size();i++){
      for(auto it: funcparam[i].second.first){
        if(it == '['){
          fl = 1;
          break;
        }
      }
      if(fl == 0)
      curr_table->entry(funcparam[i].first, "Identifier", funcparam[i].second.first, offset, curr_scope, yylineno, funcparam[i].second.second);
      else 
      curr_table->entry(funcparam[i].first, "Array", funcparam[i].second.first, offset, curr_scope, yylineno, funcparam[i].second.second);
      offset += size;
if(addoff > 0){ offset += (addoff-1)*getsize(type);}
addoff = 0;;
      fl = 0;
    }
    funcargno = -1;
    funcparam.clear();
  }
  
  
  
}
#line 4161 "parser.tab.c"
    break;

  case 97:
#line 1504 "parser.y"
                   {
  string s="";
  if(strcmp(type.c_str(),"")) s=type;
  else s=((yyvsp[0].typ)).type;
  string yo="";
  for(int i=0;i<(int)s.size();i++)
  {
    if(s[i]=='[')
    {
      break;
    }
    yo+=string(1,s[i]);
  }
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
  if(!boolgetorder(yo.c_str(),((yyvsp[0].typ)).type,1))
  {
    if(strcmp(yo.c_str(),((yyvsp[0].typ)).type))
    {
      if(!strcmp(yo.c_str(),"String")&&!strcmp(((yyvsp[0].typ)).type,"string"))
      {
        
      }
      else if(strcmp(((yyvsp[0].typ)).type,"Dishay"))cout<<"Invalid variable declaration between "<<yo<<" and "<<((yyvsp[0].typ)).type<<" on line "<<yylineno<<'\n';
    }
  }
  type=yo;
  // cout<<"SSS"<<($1).type<<'\n';

  strcpy(((yyval.typ)).type,yo.c_str());
}
#line 4197 "parser.tab.c"
    break;

  case 98:
#line 1535 "parser.y"
                                              {
  // cout<<type<<' '<<yylineno<<endl;
  string s=type;
  string yo="";
  for(int i=0;i<(int)s.size();i++)
  {
    if(s[i]=='[')
    {
      break;
    }
    yo+=string(1,s[i]);
  }
  type=yo;
  if(strcmp(((yyvsp[-2].typ)).type,"Dishay") && strcmp(((yyvsp[0].typ)).type,"Dishay"))
  {
      // cout<<"1"<<($1).type<<($3).type<<"\n";
      string s=((yyvsp[-2].typ)).type;
      string yo="";
      for(int i=0;i<(int)s.size();i++)
      {
        if(s[i]=='[')
        {
          break;
        }
        yo+=string(1,s[i]);
      }
      string s1=((yyvsp[0].typ)).type;
      string yo1="";
      for(int i=0;i<(int)s1.size();i++)
      {
        if(s1[i]=='[')
        {
          break;
        }
        yo1+=string(1,s1[i]);
      }
      // strcpy(($3).type,yo);
      strcpy(((yyval.typ)).type,getorder(yo.c_str(),yo1.c_str(),1).c_str());
  }
  else if(!strcmp(((yyvsp[-2].typ)).type,"Dishay") && strcmp(((yyvsp[0].typ)).type,"Dishay"))
  {
    // cout<<"2\n";
      string s=((yyvsp[0].typ)).type;
      string yo="";
      for(int i=0;i<(int)s.size();i++)
      {
        if(s[i]=='[')
        {
          break;
        }
        yo+=string(1,s[i]);
      }
      strcpy(((yyval.typ)).type,yo.c_str());
  }
  else if(strcmp(((yyvsp[-2].typ)).type,"Dishay") && !strcmp(((yyvsp[0].typ)).type,"Dishay"))
  {
    // cout<<"3\n";
      string s=((yyvsp[-2].typ)).type;
      string yo="";
      for(int i=0;i<(int)s.size();i++)
      {
        if(s[i]=='[')
        {
          break;
        }
        yo+=string(1,s[i]);
      }
      strcpy(((yyval.typ)).type,yo.c_str());
  }
  else
  {
    // cout<<"4\n";
    strcpy(((yyval.typ)).type,"Dishay");
  }
  // cout<<($3).type<<'\n';
}
#line 4278 "parser.tab.c"
    break;

  case 99:
#line 1612 "parser.y"
                     {
  strcpy(((yyval.typ)).tempvar,((yyvsp[0].typ)).tempvar);

  strcpy(((yyval.typ)).type,"Dishay");
//   curr_table->entry(string((char*)($1).type), "Identifier", type, offset, curr_scope, yylineno, -1);
//   offset += size;
if(addoff > 0){ offset += (addoff-1)*getsize(type);}
addoff = 0; ;
  funcparam.push_back({string((char*)((yyvsp[0].typ)).type), {type, -1}});
//   cout<< "VariableDeclaratorId " << string((char*)($1).type) << " " << type << " " << offset << " " << curr_scope << " " << yylineno << "\n";
  string s=curr_table->lookup(string((char*)((yyvsp[0].typ)).type)).type;
  // cout<<"LKS"<<s<<'\n';
  if(strcmp(s.c_str(),"null"))
  {
    if(!strcmp(curr_table->lookup(string((char*)((yyvsp[0].typ)).type)).scope_name.c_str(),curr_scope.c_str()))
    {
      string yo="";
      for(int i=0;i<(int)s.size();i++)
      {
        if(s[i]=='[')
        {
          break;
        }
        yo+=string(1,s[i]);
      }
      type=yo;
      strcpy(((yyval.typ)).type,type.c_str());
    }
    // cout<<"TYO"<<yo<<'\n';
  }
  else
  {
    s=type;
    string yo="";
    for(int i=0;i<(int)s.size();i++)
    {
      if(s[i]=='[')
      {
        break;
      }
      yo+=string(1,s[i]);
    }
    type=yo;
    strcpy(((yyval.typ)).type,yo.c_str());
  }
  ndim=0;
  // cout<<"SSS"<<s<<'\n';
  
}
#line 4332 "parser.tab.c"
    break;

  case 100:
#line 1661 "parser.y"
                                                {  
//   curr_table->entry(string((char*)($1).type), "Identifier", type, offset, curr_scope, yylineno, -1);
//   offset += size;
if(addoff > 0){ offset += (addoff-1)*getsize(type);}
addoff = 0; ;
  // cout<<ndim <<" "<<($3).ndim<<'\n';
  // cout<<($3).type<<'\n';
  emit("=",((yyvsp[0].typ)).tempvar,"null",((yyvsp[-2].typ)).tempvar, -1);
  // arrname=($1).type;
  // cout<<"YYYY"<<($1).type<<($3).type<<'\n';
  // emit(">=",($1).tempvar,($3).tempvar,($$).tempvar, -1);
  if(arrinit)
  {
    // cout<<"Array "<<($1).type<<endl;
    // cout<<"Offset: "<<offset<<endl;
    // print_shape(curr_table->lookup(string((char*)($1).type)).arrshape);
    for(auto it=shape.begin();it!=shape.end();it++)
      {
        vector<int> v=it->second;
        for(auto yo:v)
        {
          addoff += yo;
          // cout<<"Offsets ";
          // cout<<offset<<' ';
        }
        cout<<endl;
        break;
      }
    // cout<<"Type "<<type<<endl;
    string tp1;
    for(auto it: type){
      if(it=='[')
        break;
      else{
        tp1.push_back(it);
      }
    }
    // cout<<"Type1 "<<tp1<<endl;
    // cout<<"New Offset: "<<offset<<endl;
    // offset = offset + addoff*getsize(tp1);
    // cout<<endl;
    // cout<<"New Offset "<<offset<<endl;
    shape.clear();
  }

  arrinit=0;

  if(ndim!=((yyvsp[0].typ)).ndim)
  {
    cout<<"Invalid assignment: Array dimensions "<<ndim<<" and "<<((yyvsp[0].typ)).ndim<<" don't match in line "<<yylineno<<'\n';
    ndim=0;
  }
  else ndim=0;
  funcparam.push_back({string((char*)((yyvsp[-2].typ)).type), {type, -1}});
  if(curr_table->lookup(string((char*)((yyvsp[-2].typ)).type)).offset != -1)
  {
    if(curr_table->lookup(string((char*)((yyvsp[0].typ)).type)).offset == -1)
    {
  
      if(!boolgetorder(curr_table->lookup(string((char*)((yyvsp[-2].typ)).type)).type.c_str(),((yyvsp[0].typ)).type,1)&&!strcmp(curr_table->lookup(string((char*)((yyvsp[-2].typ)).type)).scope_name.c_str(),curr_scope.c_str()))
      {
        cout<<curr_table->lookup(string((char*)((yyvsp[-2].typ)).type)).type<<" "<<((yyvsp[0].typ)).type<<" "<<"Invalid VariableDeclarator on line "<< yylineno<<"\n";
      }
      else
      {
        strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
      }
    }
    else
    {
      if(!boolgetorder(curr_table->lookup(string((char*)((yyvsp[-2].typ)).type)).type.c_str(),curr_table->lookup(string((char*)((yyvsp[0].typ)).type)).type.c_str(),1))
      {
        if(strcmp(curr_table->lookup(string((char*)((yyvsp[-2].typ)).type)).type.c_str(),curr_table->lookup(string((char*)((yyvsp[0].typ)).type)).type.c_str()))
        {
          cout<<curr_table->lookup(string((char*)((yyvsp[-2].typ)).type)).type<<" "<<((yyvsp[0].typ)).type<<" "<<"Invalid VariableDeclarator on line "<< yylineno<<"\n";
        }
      }
      else
      {
        strcpy(((yyval.typ)).type,curr_table->lookup(string((char*)((yyvsp[0].typ)).type)).type.c_str());
      }
    }
  }
  else
  {
    // cout<<"yo"<<($3).type<<"\n";
    strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
  }
  string s=((yyval.typ)).type;
  string yo="";
  for(int i=0;i<(int)s.size();i++)
  {
    if(s[i]=='[')
    {
      break;
    }
    yo+=string(1,s[i]);
  }
  strcpy(((yyval.typ)).type,yo.c_str());
  // cout<<"TYO"<<yo<<'\n';
  ndim=0;
  if(checkclass(((yyvsp[0].typ)).type)){
    objects.push_back(string((char*)((yyvsp[-2].typ)).type));
  }
  // cout<<"GGG"<<($$).type<<'\n';
}
#line 4443 "parser.tab.c"
    break;

  case 101:
#line 1768 "parser.y"
           {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].lex)).str);

  strcpy(((yyval.typ)).type,((yyvsp[0].lex)).str);
  ndim=0;
  // string yo=type;
  // for(int i=0;i<(int)s.size();i++)
  // {
  //   if(s[i]=='[')
  //   {
  //     break;
  //   }
  //   yo+=string(1,s[i]);
  // }
  // type=yo;
  // cout<<type<<"HI"<<endl;
  // cout<<array_size<<'\n';
  // if(array_size>0)
  // type = type + to_string(array_size);
  // curr_table->entry(string((char*)($1).str), "Identifier", type, offset, curr_scope, yylineno, -1);
  // array_size = 0;
  // offset += size;
if(addoff > 0){ offset += (addoff-1)*getsize(type);}
addoff = 0;;
}
#line 4473 "parser.tab.c"
    break;

  case 102:
#line 1793 "parser.y"
                      {
  type  = type + "[]";
  ndim=ndim+1;
  // type = "Array";
}
#line 4483 "parser.tab.c"
    break;

  case 103:
#line 1797 "parser.y"
                                       {
  
  // ($$).ndim=ndim;
}
#line 4492 "parser.tab.c"
    break;

  case 104:
#line 1802 "parser.y"
           {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);

  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
  if(!flagyo) ((yyval.typ)).ndim=0;
  else ((yyval.typ)).ndim=((yyvsp[0].typ)).ndim;
  // cout<<"YO"<<($$).ndim<<'\n';

}
#line 4506 "parser.tab.c"
    break;

  case 105:
#line 1811 "parser.y"
                  {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);

  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
  ((yyval.typ)).ndim=((yyvsp[0].typ)).ndim;
}
#line 4517 "parser.tab.c"
    break;

  case 106:
#line 1818 "parser.y"
                        {
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  offset = offsets.top(); offsets.pop();
  infunction=0;
  if(strcmp(functype.c_str(),"void")&&!isreturn)
  {
    cout<<"Missing return statement in function on line "<<yylineno<<'\n';
  }
  isreturn=0;
  functype="";
  isstatic=0;

}
#line 4536 "parser.tab.c"
    break;

  case 107:
#line 1832 "parser.y"
            {
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  offset = offsets.top(); offsets.pop();
  infunction=0;
  if(strcmp(functype.c_str(),"void")&&!isreturn)
  {
    cout<<"Missing return statement in function on line "<<yylineno<<'\n';
  }
  isreturn=0;
  functype="";
  isstatic=0;

}
#line 4555 "parser.tab.c"
    break;

  case 108:
#line 1847 "parser.y"
                                       {
emit("BeginFunc","","","",-1);
    if(isvoid)
  {
    cout<<"Main function should be void return type\n";
  }
  if(ismainstatic&&!isstatic)
  {
    cout<<"Main function should be satic\n";
  }
  ismainstatic=0;
  isvoid=0;
  functype=((yyvsp[-2].typ)).type;
  infunction=1;
  nelem=((yyvsp[-1].typ)).nelem;
  // cout<<"FFF"<<isstatic<<'\n';
  curr_table->entry(string((char*)((yyvsp[-1].typ)).type), "Method", string((char*)((yyvsp[-2].typ)).type), offset, curr_scope, yylineno, -1);
  tables.push(curr_table);
  curr_table = new Sym_Table(curr_table);
  list_of_Symbol_Tables.push_back(curr_table);
  scope_names.push(curr_scope);
  string new_scope = "Method" + string((char*)((yyvsp[-1].typ)).type);
  curr_scope = new_scope;
  offsets.push(offset);
  int new_offset = 0;
  nelem=0;
  offset = new_offset;
  if(funcparam.size()){
    for(int i=0;i<(int)funcparam.size();i++){
      for(auto it: funcparam[i].second.first){
        if(it == '['){
          fl = 1;
          break;
        }
      }
      if(fl == 0)
      curr_table->entry(funcparam[i].first, "Identifier", funcparam[i].second.first, offset, curr_scope, yylineno, funcparam[i].second.second);
      else 
      curr_table->entry(funcparam[i].first, "Array", funcparam[i].second.first, offset, curr_scope, yylineno, funcparam[i].second.second);
      offset += size;
if(addoff > 0){ offset += (addoff-1)*getsize(type);}
addoff = 0;;
      fl = 0;
    }
    funcargno = -1;
    funcparam.clear();
  }
  isfieldprivate=0;
  isstatic=0;

}
#line 4611 "parser.tab.c"
    break;

  case 109:
#line 1898 "parser.y"
                                  { 
  
   if(isvoid)
  {
    cout<<"Main function should be void return type\n";
  }
  if(ismainstatic&&!isstatic)
  {
    cout<<"Main function should be satic\n";
  }
  ismainstatic=0;
  isvoid=0;
  functype=((yyvsp[-1].typ)).type;
  infunction=1;
  nelem=((yyvsp[0].typ)).nelem;
  // cout<<"FFF"<<isstatic<<'\n';
  curr_table->entry(string((char*)((yyvsp[0].typ)).type), "Method", string((char*)((yyvsp[-1].typ)).type), offset, curr_scope, yylineno, -1);
  tables.push(curr_table);
  curr_table = new Sym_Table(curr_table);
  list_of_Symbol_Tables.push_back(curr_table);
  scope_names.push(curr_scope);
  string new_scope = "Method" + string((char*)((yyvsp[0].typ)).type);
  curr_scope = new_scope;
  offsets.push(offset);
  int new_offset = 0;
  offset = new_offset;
  nelem=0;
  if(funcparam.size()){
    for(int i=0;i<(int)funcparam.size();i++){
      for(auto it: funcparam[i].second.first){
        if(it == '['){
          fl = 1;
          break;
        }
      }
      if(fl == 0)
      curr_table->entry(funcparam[i].first, "Identifier", funcparam[i].second.first, offset, curr_scope, yylineno, funcparam[i].second.second);
      else 
      curr_table->entry(funcparam[i].first, "Array", funcparam[i].second.first, offset, curr_scope, yylineno, funcparam[i].second.second);
      offset += size;
if(addoff > 0){ offset += (addoff-1)*getsize(type);}
addoff = 0;;
      fl = 0;
    }
    funcargno = -1;
    funcparam.clear();
  }
  isfieldprivate=0;
  isstatic=0;

}
#line 4667 "parser.tab.c"
    break;

  case 110:
#line 1949 "parser.y"
                              {
  if(isvoid)
  {
    cout<<"Main function should be void return type\n";
  }
  if(ismainstatic&&!isstatic)
  {
    cout<<"Main function should be satic\n";
  }
  ismainstatic=0;
  isvoid=0;
  functype=((yyvsp[-2].typ)).type;
  infunction=1;
  nelem=((yyvsp[-1].typ)).nelem;
  curr_table->entry(string((char*)((yyvsp[-1].typ)).type), "Method", string((char*)((yyvsp[-2].typ)).type), offset, curr_scope, yylineno, -1);
  tables.push(curr_table);
  curr_table = new Sym_Table(curr_table);
  list_of_Symbol_Tables.push_back(curr_table);
  scope_names.push(curr_scope);
  string new_scope = "Method" + string((char*)((yyvsp[-1].typ)).type);
  curr_scope = new_scope;
  offsets.push(offset);
  int new_offset = 0;
  offset = new_offset;
  nelem=0;
  if(funcparam.size()){
    for(int i=0;i<(int)funcparam.size();i++){
      for(auto it: funcparam[i].second.first){
        if(it == '['){
          fl = 1;
          break;
        }
      }
      if(fl == 0)
      curr_table->entry(funcparam[i].first, "Identifier", funcparam[i].second.first, offset, curr_scope, yylineno, funcparam[i].second.second);
      else 
      curr_table->entry(funcparam[i].first, "Array", funcparam[i].second.first, offset, curr_scope, yylineno, funcparam[i].second.second);
      offset += size;
if(addoff > 0){ offset += (addoff-1)*getsize(type);}
addoff = 0;;
      fl = 0;
    }
    funcargno = -1;
    funcparam.clear();
  }
  
}
#line 4719 "parser.tab.c"
    break;

  case 111:
#line 1996 "parser.y"
                       {
    if(isvoid)
  {
    cout<<"Main function should be void return type\n";
  }
  if(ismainstatic&&!isstatic)
  {
    cout<<"Main function should be satic\n";
  }
  ismainstatic=0;
  isvoid=0;
  functype=((yyvsp[-1].typ)).type;
  infunction=1;
  nelem=((yyvsp[0].typ)).nelem;
  curr_table->entry(string((char*)((yyvsp[0].typ)).type), "Method", string((char*)((yyvsp[-1].typ)).type), offset, curr_scope, yylineno, -1);
  tables.push(curr_table);
  curr_table = new Sym_Table(curr_table);
  list_of_Symbol_Tables.push_back(curr_table);
  scope_names.push(curr_scope);
  string new_scope = "Method" + string((char*)((yyvsp[0].typ)).type);
  curr_scope = new_scope;
  offsets.push(offset);
  int new_offset = 0;
  offset = new_offset;
  nelem=0;
  if(funcparam.size()){
    for(int i=0;i<(int)funcparam.size();i++){
      for(auto it: funcparam[i].second.first){
        if(it == '['){
          fl = 1;
          break;
        }
      }
      if(fl == 0)
      curr_table->entry(funcparam[i].first, "Identifier", funcparam[i].second.first, offset, curr_scope, yylineno, funcparam[i].second.second);
      else 
      curr_table->entry(funcparam[i].first, "Array", funcparam[i].second.first, offset, curr_scope, yylineno, funcparam[i].second.second);
      offset += size;
if(addoff > 0){ offset += (addoff-1)*getsize(type);}
addoff = 0;;
      fl = 0;
    }
    funcargno = -1;
    funcparam.clear();
  }
}
#line 4770 "parser.tab.c"
    break;

  case 112:
#line 2042 "parser.y"
                                        {
  functype="void";
  infunction=1;
  nelem=((yyvsp[-1].typ)).nelem;
  if(ismainstatic&&!isstatic)
  {
    cout<<"Main function should be satic\n";
  }
  ismainstatic=0;
  isvoid=0;
  // cout<<"FFF"<<isstatic<<'\n';
  curr_table->entry(string((char*)((yyvsp[-1].typ)).type), "Method", string((char*)((yyvsp[-2].lex)).str), offset, curr_scope, yylineno, -1);
  tables.push(curr_table);
  curr_table = new Sym_Table(curr_table);
  list_of_Symbol_Tables.push_back(curr_table);
  scope_names.push(curr_scope);
  string new_scope = "Method" + string((char*)((yyvsp[-1].typ)).type);
  curr_scope = new_scope;
  offsets.push(offset);
  int new_offset = 0;
  offset = new_offset;
  nelem=0;
  if(funcparam.size()){
    for(int i=0;i<(int)funcparam.size();i++){
      for(auto it: funcparam[i].second.first){
        if(it == '['){
          fl = 1;
          break;
        }
      }
      if(fl == 0)
      curr_table->entry(funcparam[i].first, "Identifier", funcparam[i].second.first, offset, curr_scope, yylineno, funcparam[i].second.second);
      else 
      curr_table->entry(funcparam[i].first, "Array", funcparam[i].second.first, offset, curr_scope, yylineno, funcparam[i].second.second);
      offset += size;
if(addoff > 0){ offset += (addoff-1)*getsize(type);}
addoff = 0;;
      fl = 0;
    }
    funcargno = -1;
    funcparam.clear();
  }
  isfieldprivate=0;
}
#line 4819 "parser.tab.c"
    break;

  case 113:
#line 2086 "parser.y"
                              {
  if(ismainstatic&&!isstatic)
  {
    cout<<"Main function should be satic\n";
  }
  ismainstatic=0;
  isvoid=0;
  ismainstatic=0;
  functype="void";
  infunction=1;
  nelem=((yyvsp[-1].typ)).nelem;
  curr_table->entry(string((char*)((yyvsp[-1].typ)).type), "Method", string((char*)((yyvsp[-2].lex)).str), offset, curr_scope, yylineno, -1);
  tables.push(curr_table);
  curr_table = new Sym_Table(curr_table);
  list_of_Symbol_Tables.push_back(curr_table);
  scope_names.push(curr_scope);
  string new_scope = "Method" + string((char*)((yyvsp[-1].typ)).type);
  curr_scope = new_scope;
  offsets.push(offset);
  int new_offset = 0;
  offset = new_offset;
  nelem=0;
  if(funcparam.size()){
    for(int i=0;i<(int)funcparam.size();i++){
      for(auto it: funcparam[i].second.first){
        if(it == '['){
          fl = 1;
          break;
        }
      }
      if(fl == 0)
      curr_table->entry(funcparam[i].first, "Identifier", funcparam[i].second.first, offset, curr_scope, yylineno, funcparam[i].second.second);
      else 
      curr_table->entry(funcparam[i].first, "Array", funcparam[i].second.first, offset, curr_scope, yylineno, funcparam[i].second.second);
      offset += size;
if(addoff > 0){ offset += (addoff-1)*getsize(type);}
addoff = 0;;
      fl = 0;
    }
    funcargno = -1;
    funcparam.clear();
  }
}
#line 4867 "parser.tab.c"
    break;

  case 114:
#line 2129 "parser.y"
                                  {
  if(ismainstatic&&!isstatic)
  {
    cout<<"Main function should be satic\n";
  }
  ismainstatic=0;
  isvoid=0;

  functype="void";
  infunction=1;
  nelem=((yyvsp[0].typ)).nelem;
  // cout<<"FFF"<<isstatic<<'\n';
  curr_table->entry(string((char*)((yyvsp[0].typ)).type), "Method", string((char*)((yyvsp[-1].lex)).str), offset, curr_scope, yylineno, -1);
  tables.push(curr_table);
  curr_table = new Sym_Table(curr_table);
  list_of_Symbol_Tables.push_back(curr_table);
  scope_names.push(curr_scope);
  string new_scope = "Method" + string((char*)((yyvsp[0].typ)).type);
  curr_scope = new_scope;
  offsets.push(offset);
  int new_offset = 0;
  offset = new_offset;
  nelem=0;
  if(funcparam.size()){
    for(int i=0;i<(int)funcparam.size();i++){
      for(auto it: funcparam[i].second.first){
        if(it == '['){
          fl = 1;
          break;
        }
      }
      if(fl == 0)
      curr_table->entry(funcparam[i].first, "Identifier", funcparam[i].second.first, offset, curr_scope, yylineno, funcparam[i].second.second);
      else 
      curr_table->entry(funcparam[i].first, "Array", funcparam[i].second.first, offset, curr_scope, yylineno, funcparam[i].second.second);
      offset += size;
if(addoff > 0){ offset += (addoff-1)*getsize(type);}
addoff = 0;;
      fl = 0;
    }
    funcargno = -1;
    funcparam.clear();
  }
  isfieldprivate=0;
  isstatic=0;

}
#line 4919 "parser.tab.c"
    break;

  case 115:
#line 2176 "parser.y"
                       {
  if(ismainstatic&&!isstatic)
  {
    cout<<"Main function should be satic\n";
  }
  ismainstatic=0;
  isvoid=0;

  functype="void";
  infunction=1;
  nelem=((yyvsp[0].typ)).nelem;
  curr_table->entry(string((char*)((yyvsp[0].typ)).type), "Method", string((char*)((yyvsp[-1].lex)).str), offset, curr_scope, yylineno, -1);
  tables.push(curr_table);
  curr_table = new Sym_Table(curr_table);
  list_of_Symbol_Tables.push_back(curr_table);
  scope_names.push(curr_scope);
  string new_scope = "Method" + string((char*)((yyvsp[0].typ)).type);
  curr_scope = new_scope;
  offsets.push(offset);
  int new_offset = 0;
  offset = new_offset;
  nelem=0;
  if(funcparam.size()){
    for(int i=0;i<(int)funcparam.size();i++){
      for(auto it: funcparam[i].second.first){
        if(it == '['){
          fl = 1;
          break;
        }
      }
      if(fl == 0)
      curr_table->entry(funcparam[i].first, "Identifier", funcparam[i].second.first, offset, curr_scope, yylineno, funcparam[i].second.second);
      else 
      curr_table->entry(funcparam[i].first, "Array", funcparam[i].second.first, offset, curr_scope, yylineno, funcparam[i].second.second);
      offset += size;
if(addoff > 0){ offset += (addoff-1)*getsize(type);}
addoff = 0;;
      fl = 0;
    }
    funcargno = -1;
    funcparam.clear();
  }
}
#line 4967 "parser.tab.c"
    break;

  case 116:
#line 2220 "parser.y"
                                    {
  emit(((yyvsp[-2].lex)).str,":","","",-1);
  emit("BeginFunc","","","",-1);
  strcpy(((yyval.typ)).type,((yyvsp[-2].lex)).str);
  ((yyval.typ)).nelem=0;
  if(!strcmp(((yyvsp[-2].lex)).str,"main"))
  {
    ismainstatic=1;
    isvoid=1;
  }
}
#line 4983 "parser.tab.c"
    break;

  case 117:
#line 2231 "parser.y"
                                                         {
  emit(((yyvsp[-3].lex)).str,":","","",-1);
  emit("BeginFunc","","","",-1);
  strcpy(((yyval.typ)).type,((yyvsp[-3].lex)).str);
  ((yyval.typ)).nelem=((yyvsp[-1].typ)).nelem;
  if(!strcmp(((yyvsp[-3].lex)).str,"main"))
  {
    ismainstatic=1;
    isvoid=1;
  }
}
#line 4999 "parser.tab.c"
    break;

  case 118:
#line 2242 "parser.y"
                                                       {

}
#line 5007 "parser.tab.c"
    break;

  case 119:
#line 2246 "parser.y"
                {
  ((yyval.typ)).nelem=1;
}
#line 5015 "parser.tab.c"
    break;

  case 120:
#line 2249 "parser.y"
                                           {
  ((yyval.typ)).nelem=((yyvsp[-2].typ)).nelem+1;
}
#line 5023 "parser.tab.c"
    break;

  case 121:
#line 2253 "parser.y"
                          {
  ((yyval.typ)).ndim=ndim;
  ndim=0;
//   curr_table->entry(string((char*)($2).type), "Identifier", type, offset, curr_scope, yylineno, -1);
//   offset += size;
if(addoff > 0){ offset += (addoff-1)*getsize(type);}
addoff = 0; ;
  // cout<<"Type: "<<type<<'\n';
  if(funcargno == -1){
    funcargno = 1;
  }
  else{
    funcargno++;
  }
//   cout<<"Funcarg: "<<funcargno<<' '<<endl;
  funcparam.push_back({string((char*)((yyvsp[0].typ)).type), {type, funcargno}});
}
#line 5045 "parser.tab.c"
    break;

  case 122:
#line 2271 "parser.y"
                     {
}
#line 5052 "parser.tab.c"
    break;

  case 123:
#line 2274 "parser.y"
           {
}
#line 5059 "parser.tab.c"
    break;

  case 124:
#line 2276 "parser.y"
                               {
}
#line 5066 "parser.tab.c"
    break;

  case 125:
#line 2279 "parser.y"
       {
  emit("EndFunc","","","",-1);
  infunction=1;
}
#line 5075 "parser.tab.c"
    break;

  case 126:
#line 2283 "parser.y"
           {
  emit("EndFunc","","","",-1);
  infunction=1;
  isclassaccess=0;
  isfinal=0;
  issystem=0;
}
#line 5087 "parser.tab.c"
    break;

  case 127:
#line 2291 "parser.y"
       {isstatic=1;}
#line 5093 "parser.tab.c"
    break;

  case 128:
#line 2291 "parser.y"
                           {
  // cout<<"YIS"<<isstatic<<'\n';
}
#line 5101 "parser.tab.c"
    break;

  case 129:
#line 2295 "parser.y"
                                                       {
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  offset = offsets.top(); offsets.pop();
  isfieldprivate=0;
  nelem=0;
}
#line 5113 "parser.tab.c"
    break;

  case 130:
#line 2302 "parser.y"
                                                 {
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  offset = offsets.top(); offsets.pop();
  isfieldprivate=0;
  nelem=0;
}
#line 5125 "parser.tab.c"
    break;

  case 131:
#line 2309 "parser.y"
                                              {
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  offset = offsets.top(); offsets.pop();
  nelem=0;
}
#line 5136 "parser.tab.c"
    break;

  case 132:
#line 2315 "parser.y"
                                       {
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  offset = offsets.top(); offsets.pop();
  nelem=0;
}
#line 5147 "parser.tab.c"
    break;

  case 133:
#line 2322 "parser.y"
                                         {
  
}
#line 5155 "parser.tab.c"
    break;

  case 134:
#line 2327 "parser.y"
                                                   {
  nelem=((yyvsp[-1].typ)).nelem;
  // cout<<"YO "<<constpass<<endl;
 
  // auto& it = curr_table->lookup(constpass);
  // cout<<it.token<<endl;
  // it.narg = nelem;

  curr_table->entry(string((char*)(((yyvsp[-2].typ)).type)), "Constructor", string((char*)(((yyvsp[-2].typ)).type)), offset, curr_scope, yylineno, -1);
  tables.push(curr_table);
  curr_table = new Sym_Table(curr_table);
  list_of_Symbol_Tables.push_back(curr_table);
  scope_names.push(curr_scope);
  string new_scope = "Constructor" + string((char*)(((yyvsp[-2].typ)).type));
  curr_scope = new_scope;
  // cout<<"cscope "<< curr_scope<<'\n';
  offsets.push(offset);
  int new_offset = 0;
  offset = new_offset;
  constpass = string((char*)(((yyvsp[-2].typ)).type));

  if(funcparam.size()){
    for(int i=0;i<(int)funcparam.size();i++){
      for(auto it: funcparam[i].second.first){
        if(it == '['){
          fl = 1;
          break;
        }
      }
      if(fl == 0)
      curr_table->entry(funcparam[i].first, "Identifier", funcparam[i].second.first, offset, curr_scope, yylineno, funcparam[i].second.second);
      else 
      curr_table->entry(funcparam[i].first, "Array", funcparam[i].second.first, offset, curr_scope, yylineno, funcparam[i].second.second);
      offset += size;
if(addoff > 0){ offset += (addoff-1)*getsize(type);}
addoff = 0;;
      fl = 0;
    }
    funcargno = -1;
    funcparam.clear();
  }
  nelem=0;
}
#line 5203 "parser.tab.c"
    break;

  case 135:
#line 2370 "parser.y"
                        {
  nelem=0;
  curr_table->entry(string((char*)(((yyvsp[-1].typ)).type)), "Constructor", string((char*)(((yyvsp[-1].typ)).type)), offset, curr_scope, yylineno, -1);
  tables.push(curr_table);
  curr_table = new Sym_Table(curr_table);
  list_of_Symbol_Tables.push_back(curr_table);
  scope_names.push(curr_scope);
  string new_scope = "Constructor" + string((char*)(((yyvsp[-1].typ)).type));
  curr_scope = new_scope;
  offsets.push(offset);
  int new_offset = 0;
  offset = new_offset;
}
#line 5221 "parser.tab.c"
    break;

  case 136:
#line 2383 "parser.y"
             {
  
  
  
  
}
#line 5232 "parser.tab.c"
    break;

  case 137:
#line 2390 "parser.y"
                                                                                 {
  
  
  
  
  
}
#line 5244 "parser.tab.c"
    break;

  case 138:
#line 2397 "parser.y"
                                                    {
  
  
  
  
}
#line 5255 "parser.tab.c"
    break;

  case 139:
#line 2403 "parser.y"
                                                                  {
  
  
  
  
}
#line 5266 "parser.tab.c"
    break;

  case 140:
#line 2409 "parser.y"
                                    {
  
  
  
}
#line 5276 "parser.tab.c"
    break;

  case 141:
#line 2415 "parser.y"
                                                     {
  isclassaccess=0;
  isfinal=0;
  issystem=0;
  
  
  
  
}
#line 5290 "parser.tab.c"
    break;

  case 142:
#line 2424 "parser.y"
                                         {
  isclassaccess=0;
  
  isfinal=0;
  issystem=0;
  
  
}
#line 5303 "parser.tab.c"
    break;

  case 143:
#line 2432 "parser.y"
                                                       {
    isclassaccess=0;
  issystem=0;
  
  
  isfinal=0;
  
}
#line 5316 "parser.tab.c"
    break;

  case 144:
#line 2440 "parser.y"
                                          {
    isclassaccess=0;
  issystem=0;
  
  isfinal=0;
  
}
#line 5328 "parser.tab.c"
    break;

  case 145:
#line 2448 "parser.y"
                                                 {
  curr_table->entry(string((char*)((yyvsp[-1].lex)).str), "Identifier", "Interface", offset, curr_scope, yylineno, -1);
  tables.push(curr_table);
  curr_table = new Sym_Table(curr_table);
  list_of_Symbol_Tables.push_back(curr_table);
  scope_names.push(curr_scope);
  string new_scope = "Interface" + string((char*)((yyvsp[-1].lex)).str);
  curr_scope = new_scope;
  offsets.push(offset);
  int new_offset = 0;
  offset = new_offset;
  isfieldprivate=0;
}
#line 5346 "parser.tab.c"
    break;

  case 146:
#line 2461 "parser.y"
              {
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  offset = offsets.top(); offsets.pop();
  
  
  
  
  
  
}
#line 5362 "parser.tab.c"
    break;

  case 147:
#line 2472 "parser.y"
                                        {
  curr_table->entry(string((char*)((yyvsp[-1].lex)).str), "Identifier", "Interface", offset, curr_scope, yylineno, -1);
  tables.push(curr_table);
  curr_table = new Sym_Table(curr_table);
  list_of_Symbol_Tables.push_back(curr_table);
  scope_names.push(curr_scope);
  string new_scope = "Interface" + string((char*)((yyvsp[-1].lex)).str);
  curr_scope = new_scope;
  offsets.push(offset);
  int new_offset = 0;
  offset = new_offset;
}
#line 5379 "parser.tab.c"
    break;

  case 148:
#line 2484 "parser.y"
              {
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  offset = offsets.top(); offsets.pop();
  
  
  
  
  
}
#line 5394 "parser.tab.c"
    break;

  case 149:
#line 2494 "parser.y"
                                {
  curr_table->entry(string((char*)((yyvsp[0].lex)).str), "Identifier", "Interface", offset, curr_scope, yylineno, -1);
  tables.push(curr_table);
  curr_table = new Sym_Table(curr_table);
  list_of_Symbol_Tables.push_back(curr_table);
  scope_names.push(curr_scope);
  string new_scope = "Interface" + string((char*)((yyvsp[0].lex)).str);
  curr_scope = new_scope;
  offsets.push(offset);
  int new_offset = 0;
  offset = new_offset;
  isfieldprivate=0;
}
#line 5412 "parser.tab.c"
    break;

  case 150:
#line 2507 "parser.y"
              {
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  offset = offsets.top(); offsets.pop();
}
#line 5422 "parser.tab.c"
    break;

  case 151:
#line 2512 "parser.y"
                      {
  curr_table->entry(string((char*)((yyvsp[0].lex)).str), "Identifier", "Interface", offset, curr_scope, yylineno, -1);
  tables.push(curr_table);
  curr_table = new Sym_Table(curr_table);
  list_of_Symbol_Tables.push_back(curr_table);
  scope_names.push(curr_scope);
  string new_scope = "Interface" + string((char*)((yyvsp[0].lex)).str);
  curr_scope = new_scope;
  offsets.push(offset);
  int new_offset = 0;
  offset = new_offset;
}
#line 5439 "parser.tab.c"
    break;

  case 152:
#line 2524 "parser.y"
              {
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  offset = offsets.top(); offsets.pop();
  
  
  
  
}
#line 5453 "parser.tab.c"
    break;

  case 153:
#line 2534 "parser.y"
                      {
  
  
  
  }
#line 5463 "parser.tab.c"
    break;

  case 154:
#line 2539 "parser.y"
                                       {
  
  
  
  
  }
#line 5474 "parser.tab.c"
    break;

  case 155:
#line 2546 "parser.y"
                                   {
  
  
  
  }
#line 5484 "parser.tab.c"
    break;

  case 156:
#line 2551 "parser.y"
                                                                {
  
  
  
  
  }
#line 5495 "parser.tab.c"
    break;

  case 157:
#line 2558 "parser.y"
                           {
  
  
  }
#line 5504 "parser.tab.c"
    break;

  case 158:
#line 2562 "parser.y"
                                                        {
  
  
  
  }
#line 5514 "parser.tab.c"
    break;

  case 159:
#line 2568 "parser.y"
                    {
  
  
  }
#line 5523 "parser.tab.c"
    break;

  case 160:
#line 2572 "parser.y"
                           {
  
  
  }
#line 5532 "parser.tab.c"
    break;

  case 161:
#line 2577 "parser.y"
                 {
  
  
  }
#line 5541 "parser.tab.c"
    break;

  case 162:
#line 2582 "parser.y"
                       {
  isfinal=0;
  isclassaccess=0;
    issystem=0;
  }
#line 5551 "parser.tab.c"
    break;

  case 163:
#line 2588 "parser.y"
                                                              {
  strcpy(((yyval.typ)).tempvar, strcat(((yyvsp[-3].lex)).str, strcat(((yyvsp[-2].typ)).tempvar, strcat(((yyvsp[-1].lex)).str, ((yyvsp[0].lex)).str))));
  arrinit=1;
  strcpy(((yyval.typ)).type,((yyvsp[-2].typ)).type);
  // ($$).nelem=($2).nelem;
  ((yyval.typ)).ndim=((yyvsp[-2].typ)).ndim+1;
  shape[((yyval.typ)).ndim].push_back(((yyvsp[-2].typ)).nelem);
  cout<<((yyval.typ)).ndim<<'\n';
  }
#line 5565 "parser.tab.c"
    break;

  case 164:
#line 2597 "parser.y"
                                          {
  strcpy(((yyval.typ)).tempvar, strcat(((yyvsp[-2].lex)).str, strcat(((yyvsp[-1].lex)).str, ((yyvsp[0].lex)).str)));
  arrinit=1;
  strcpy(((yyval.typ)).type,"Dishay");
  // ($$).nelem=0;
  ((yyval.typ)).ndim=1;
  shape[((yyval.typ)).ndim].push_back(0);
  // cout<<($$).ndim<<'\n';
  
  }
#line 5580 "parser.tab.c"
    break;

  case 165:
#line 2607 "parser.y"
                                                         {
  strcpy(((yyval.typ)).tempvar, strcat(((yyvsp[-2].lex)).str, strcat(((yyvsp[-1].typ)).tempvar, ((yyvsp[0].lex)).str)));
  arrinit=1;
  strcpy(((yyval.typ)).type,((yyvsp[-1].typ)).type);
  // ($$).nelem=($2).nelem;
  ((yyval.typ)).ndim=((yyvsp[-1].typ)).ndim+1;
  shape[((yyval.typ)).ndim].push_back(((yyvsp[-1].typ)).nelem);
  // cout<<"OPENCURLYBRACKET VariableInitializers CLOSECURLYBRACKET"<<($$).ndim<<'\n';
  
  
  
  }
#line 5597 "parser.tab.c"
    break;

  case 166:
#line 2619 "parser.y"
                                    {
  strcpy(((yyval.typ)).tempvar, strcat(((yyvsp[-1].lex)).str, ((yyvsp[0].lex)).str));
  arrinit=1;
  strcpy(((yyval.typ)).type,"Dishay");
  // ($$).nelem=0;
  ((yyval.typ)).ndim=1;
  shape[((yyval.typ)).ndim].push_back(0);
  // cout<<"OPENCURLYBRACKET CLOSECURLYBRACKET"<<($$).ndim<<'\n';
  
  
  }
#line 5613 "parser.tab.c"
    break;

  case 167:
#line 2631 "parser.y"
                    {
  strcpy(((yyval.typ)).tempvar,((yyvsp[0].typ)).tempvar);
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
  ((yyval.typ)).ndim=((yyvsp[0].typ)).ndim;
  // shape[($1).ndim+1].back()+=1;
  ((yyval.typ)).nelem=1;
  
  }
#line 5626 "parser.tab.c"
    break;

  case 168:
#line 2639 "parser.y"
                                                {
  strcpy(((yyval.typ)).tempvar, strcat(strcat(((yyvsp[-2].typ)).tempvar,","),((yyvsp[0].typ)).tempvar));
  strcpy(((yyval.typ)).type,getorder(((yyvsp[-2].typ)).type,((yyvsp[0].typ)).type,1).c_str());
  ((yyval.typ)).ndim=((yyvsp[-2].typ)).ndim;
  // shape[($1).ndim+1].back()+=1;
  ((yyval.typ)).nelem=((yyvsp[-2].typ)).nelem+1;
  // cout<<"types "<<($1).type<<" "<<($3).type<<" "<<($$).type<<'\n';
  
  }
#line 5640 "parser.tab.c"
    break;

  case 169:
#line 2649 "parser.y"
                                                   {
  
  
  
  
  }
#line 5651 "parser.tab.c"
    break;

  case 170:
#line 2655 "parser.y"
                                    {
  
  
  
  }
#line 5661 "parser.tab.c"
    break;

  case 171:
#line 2661 "parser.y"
               {
  
  
  }
#line 5670 "parser.tab.c"
    break;

  case 172:
#line 2665 "parser.y"
                                {
  
  
  
  }
#line 5680 "parser.tab.c"
    break;

  case 173:
#line 2671 "parser.y"
                                  {
  
  
  }
#line 5689 "parser.tab.c"
    break;

  case 174:
#line 2675 "parser.y"
           {
  
  
  }
#line 5698 "parser.tab.c"
    break;

  case 175:
#line 2680 "parser.y"
                                   {
  isclassaccess=0;
  type="";
    issystem=0;
  }
#line 5708 "parser.tab.c"
    break;

  case 176:
#line 2686 "parser.y"
{
   isclassaccess=0;
  type="";
    issystem=0;
    isfinal=0;
}
#line 5719 "parser.tab.c"
    break;

  case 177:
#line 2693 "parser.y"
                         {
  // cout<<($1).type<<($2).type<<'\n';
  // cout<<"GHF"<<isstatic<<'\n';
  strcpy(((yyval.typ)).tempvar, ((yyvsp[-1].typ)).tempvar);
  if(strcmp(((yyvsp[0].typ)).type,"Dishay"))
  {
      if(!flagyo)
      {
        if(!boolgetorder(((yyvsp[-1].typ)).type,((yyvsp[0].typ)).type,1))
        { 
          if(strcmp(((yyvsp[-1].typ)).type,((yyvsp[0].typ)).type))
          {
            cout<<((yyvsp[-1].typ)).type<<" "<<((yyvsp[0].typ)).type<<" "<<"Invalid LocalVariableDeclaration operator on line "<< yylineno<<"\n";
          }
          else strcpy(((yyval.typ)).type,((yyvsp[-1].typ)).type);
        }
        else
        {
          strcpy(((yyval.typ)).type,((yyvsp[-1].typ)).type);
        }
      }
      else
      {
        if(strcmp(((yyvsp[-1].typ)).type,((yyvsp[0].typ)).type))
        {
          cout<<((yyvsp[-1].typ)).type<<" "<<((yyvsp[0].typ)).type<<" "<<"Invalid LocalVariableDeclaration operator on line "<< yylineno<<"\n";
        }
        else
        {
          strcpy(((yyval.typ)).type,((yyvsp[-1].typ)).type);
        }
        flagyo=0;
      }
      // cout<<"FFF"<<($2).type<<'\n';

  }
  if(funcparam.size()){
    for(int i=0;i<(int)funcparam.size();i++){
      for(auto it: funcparam[i].second.first){
        if(it == '['){
          fl = 1;
          break;
        }
      }
      if(fl == 0)
      curr_table->entry(funcparam[i].first, "Identifier", funcparam[i].second.first, offset, curr_scope, yylineno, funcparam[i].second.second);
      else 
      curr_table->entry(funcparam[i].first, "Array", funcparam[i].second.first, offset, curr_scope, yylineno, funcparam[i].second.second);
      offset += size;
if(addoff > 0){ offset += (addoff-1)*getsize(type);}
addoff = 0;;
      fl = 0;
    }
    funcargno = -1;
    funcparam.clear();
  }
  }
#line 5781 "parser.tab.c"
    break;

  case 178:
#line 2751 "parser.y"
                                     {
  
  
  }
#line 5790 "parser.tab.c"
    break;

  case 179:
#line 2755 "parser.y"
                  {
  
  
  }
#line 5799 "parser.tab.c"
    break;

  case 180:
#line 2759 "parser.y"
                 {
  
  
  }
#line 5808 "parser.tab.c"
    break;

  case 181:
#line 2763 "parser.y"
                     {
  
  
  }
#line 5817 "parser.tab.c"
    break;

  case 182:
#line 2767 "parser.y"
                {
  
  
  }
#line 5826 "parser.tab.c"
    break;

  case 183:
#line 2771 "parser.y"
              {
  
  
  }
#line 5835 "parser.tab.c"
    break;

  case 184:
#line 2776 "parser.y"
                                     {
  
  
  }
#line 5844 "parser.tab.c"
    break;

  case 185:
#line 2780 "parser.y"
                           {
  
  
  }
#line 5853 "parser.tab.c"
    break;

  case 186:
#line 2784 "parser.y"
                              {
  
  
  }
#line 5862 "parser.tab.c"
    break;

  case 187:
#line 2788 "parser.y"
                         {
  
  
  }
#line 5871 "parser.tab.c"
    break;

  case 188:
#line 2792 "parser.y"
                       {
  
  
  }
#line 5880 "parser.tab.c"
    break;

  case 189:
#line 2797 "parser.y"
      {
  
  
  }
#line 5889 "parser.tab.c"
    break;

  case 190:
#line 2801 "parser.y"
                {
  
  
  }
#line 5898 "parser.tab.c"
    break;

  case 191:
#line 2805 "parser.y"
                     {
  
  
  }
#line 5907 "parser.tab.c"
    break;

  case 192:
#line 2809 "parser.y"
                 {
  
  
  }
#line 5916 "parser.tab.c"
    break;

  case 193:
#line 2813 "parser.y"
             {
  
  
  }
#line 5925 "parser.tab.c"
    break;

  case 194:
#line 2817 "parser.y"
                {
  
  
  }
#line 5934 "parser.tab.c"
    break;

  case 195:
#line 2821 "parser.y"
                   {
  
  
  }
#line 5943 "parser.tab.c"
    break;

  case 196:
#line 2825 "parser.y"
                 {
  
  
  }
#line 5952 "parser.tab.c"
    break;

  case 197:
#line 2829 "parser.y"
                       {
  
  
  }
#line 5961 "parser.tab.c"
    break;

  case 198:
#line 2833 "parser.y"
                {
  
  
  }
#line 5970 "parser.tab.c"
    break;

  case 199:
#line 2837 "parser.y"
              {
  
  
  }
#line 5979 "parser.tab.c"
    break;

  case 200:
#line 2842 "parser.y"
          {
    issystem=0;
  isclassaccess=0;
  isfinal=0;
}
#line 5989 "parser.tab.c"
    break;

  case 201:
#line 2848 "parser.y"
                           {
  if(curr_table->lookup(string((char*)((yyvsp[-2].lex)).str)).offset == -1  && checkobj(string((char*)((yyvsp[-2].lex)).str)) == 0){
    cout<<"Undeclared variable on line "<< yylineno<<"\n";
  }
}
#line 5999 "parser.tab.c"
    break;

  case 202:
#line 2854 "parser.y"
                                    {
  if(curr_table->lookup(string((char*)((yyvsp[-2].lex)).str)).offset == -1 && checkobj(string((char*)((yyvsp[-2].lex)).str)) == 0){
    cout<<"Undeclared variable on line "<< yylineno<<"\n";
  }
  }
#line 6009 "parser.tab.c"
    break;

  case 203:
#line 2860 "parser.y"
                              {
  strcpy(((yyval.typ)).type,((yyvsp[-1].typ)).type);
  strcpy(((yyval.typ)).tempvar, ((yyvsp[-1].typ)).tempvar);
    issystem=0;
  isclassaccess=0;
  isfinal=0;
  }
#line 6021 "parser.tab.c"
    break;

  case 204:
#line 2868 "parser.y"
           {
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);
  
  
  }
#line 6032 "parser.tab.c"
    break;

  case 205:
#line 2874 "parser.y"
                        {
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);
  
  
  }
#line 6043 "parser.tab.c"
    break;

  case 206:
#line 2880 "parser.y"
                        {
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);
  
  
  }
#line 6054 "parser.tab.c"
    break;

  case 207:
#line 2886 "parser.y"
                         {
  
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);
  
  }
#line 6065 "parser.tab.c"
    break;

  case 208:
#line 2892 "parser.y"
                         {
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);
  
  
  }
#line 6076 "parser.tab.c"
    break;

  case 209:
#line 2898 "parser.y"
                  {
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);
  

  
  }
#line 6088 "parser.tab.c"
    break;

  case 210:
#line 2905 "parser.y"
                                 {
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);
  
  
  }
#line 6099 "parser.tab.c"
    break;

  case 211:
#line 2911 "parser.y"
                                 {

  tables.push(curr_table);
  curr_table = new Sym_Table(curr_table);
  list_of_Symbol_Tables.push_back(curr_table);
  scope_names.push(curr_scope);
  string new_scope = "IfStatement";
  curr_scope = new_scope;
  offsets.push(offset);
  int new_offset = 0;
  offset = new_offset;
}
#line 6116 "parser.tab.c"
    break;

  case 212:
#line 2924 "parser.y"
                         {
  tables.push(curr_table);
  curr_table = new Sym_Table(curr_table);
  list_of_Symbol_Tables.push_back(curr_table);
  scope_names.push(curr_scope);
  string new_scope = "ElseStatement";
  curr_scope = new_scope;
  offsets.push(offset);
  int new_offset = 0;
  offset = new_offset;
}
#line 6132 "parser.tab.c"
    break;

  case 213:
#line 2936 "parser.y"
                                               {
  string a = newLabel();
  emit("Goto", ((yyvsp[0].typ)).tempvar, a, "Ifz", -1);
  strcpy(((yyval.typ)).gotoname,a.c_str());
}
#line 6142 "parser.tab.c"
    break;

  case 214:
#line 2943 "parser.y"
                                         {
  
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  offset = offsets.top(); offsets.pop();
  string a = newLabel();
  emit("Goto", "", a, "", -1);
  // strcpy(($$).gotoname,a.c_str());
  emit(((yyvsp[-2].typ)).gotoname, ":", "", "", -1);
  emit(a, ":", "", "", -1);
}
#line 6158 "parser.tab.c"
    break;

  case 215:
#line 2955 "parser.y"
                                                                     {
  string a = newLabel();
  emit("Goto", "", a, "", -1);
  emit(((yyvsp[-2].typ)).gotoname, ":", "", "", -1);
  strcpy(((yyval.typ)).gotoname,a.c_str());
}
#line 6169 "parser.tab.c"
    break;

  case 216:
#line 2963 "parser.y"
                                               {
  emit(((yyvsp[-2].typ)).gotoname, ":", "", "", -1);

  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  offset = offsets.top(); offsets.pop();
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  offset = offsets.top(); offsets.pop();
  
  }
#line 6185 "parser.tab.c"
    break;

  case 217:
#line 2975 "parser.y"
                                                        {
  emit(((yyvsp[-2].typ)).gotoname, ":", "", "", -1);

  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  offset = offsets.top(); offsets.pop();
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  offset = offsets.top(); offsets.pop();
  }
#line 6200 "parser.tab.c"
    break;

  case 218:
#line 2988 "parser.y"
                             {
  tables.push(curr_table);
  curr_table = new Sym_Table(curr_table);
  list_of_Symbol_Tables.push_back(curr_table);
  scope_names.push(curr_scope);
  string new_scope = "SwitchStatement";
  curr_scope = new_scope;
  offsets.push(offset);
  int new_offset = 0;
  offset = new_offset;
}
#line 6216 "parser.tab.c"
    break;

  case 219:
#line 3000 "parser.y"
                                                                     {

  }
#line 6224 "parser.tab.c"
    break;

  case 220:
#line 3004 "parser.y"
                                                                           {
  
  
  
  
  
  }
#line 6236 "parser.tab.c"
    break;

  case 221:
#line 3011 "parser.y"
                                                 {
  
  
  
  
  }
#line 6247 "parser.tab.c"
    break;

  case 222:
#line 3017 "parser.y"
                                                               {
  
  
  
  
  }
#line 6258 "parser.tab.c"
    break;

  case 223:
#line 3023 "parser.y"
                                    {
  
  
  
  }
#line 6268 "parser.tab.c"
    break;

  case 224:
#line 3029 "parser.y"
                          {
  
  
  }
#line 6277 "parser.tab.c"
    break;

  case 225:
#line 3033 "parser.y"
                                                      {

  
  }
#line 6286 "parser.tab.c"
    break;

  case 226:
#line 3038 "parser.y"
                             {
  
  
  
  }
#line 6296 "parser.tab.c"
    break;

  case 227:
#line 3044 "parser.y"
             {
  
  
  }
#line 6305 "parser.tab.c"
    break;

  case 228:
#line 3048 "parser.y"
                          {
  
  
  
  }
#line 6315 "parser.tab.c"
    break;

  case 229:
#line 3054 "parser.y"
                              {
  
  
  
  
  }
#line 6326 "parser.tab.c"
    break;

  case 230:
#line 3060 "parser.y"
               {
  
  
  
  }
#line 6336 "parser.tab.c"
    break;

  case 231:
#line 3065 "parser.y"
                            {
  inloop=1;
  tables.push(curr_table);
  curr_table = new Sym_Table(curr_table);
  list_of_Symbol_Tables.push_back(curr_table);
  scope_names.push(curr_scope);
  string new_scope = "WhileStatement";
  curr_scope = new_scope;
  offsets.push(offset);
  int new_offset = 0;
  offset = new_offset;
  string a = newLabel();
  emit(a, ":", "", "", -1);
  strcpy(((yyval.typ)).gotoname,a.c_str());
  continuelabels.push(a);
}
#line 6357 "parser.tab.c"
    break;

  case 232:
#line 3082 "parser.y"
                                                                 {
  string a = newLabel();
  emit("Goto", ((yyvsp[0].typ)).tempvar, a, "Ifz", -1);
  strcpy(((yyval.typ)).gotoname,a.c_str());
  strcpy(((yyval.typ)).nextgoto,((yyvsp[-2].typ)).gotoname);
  // emit(($1).gotoname, ":", "", "", -1);
  breaklabels.push(a);
}
#line 6370 "parser.tab.c"
    break;

  case 233:
#line 3092 "parser.y"
                                            {
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  offset = offsets.top(); offsets.pop();
  inloop=0;
  emit("Goto", ((yyvsp[-2].typ)).nextgoto, "", "", -1);
  emit(((yyvsp[-2].typ)).gotoname, ":", "", "", -1);
  }
#line 6383 "parser.tab.c"
    break;

  case 234:
#line 3102 "parser.y"
                                                     {
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  offset = offsets.top(); offsets.pop();
  inloop=0;
  emit("Goto", ((yyvsp[-2].typ)).nextgoto, "", "", -1);
  emit(((yyvsp[-2].typ)).gotoname, ":", "", "", -1);
  }
#line 6396 "parser.tab.c"
    break;

  case 235:
#line 3111 "parser.y"
                     {
  inloop=1;
  tables.push(curr_table);
  curr_table = new Sym_Table(curr_table);
  list_of_Symbol_Tables.push_back(curr_table);
  scope_names.push(curr_scope);
  string new_scope = "DoStatement";
  curr_scope = new_scope;
  offsets.push(offset);
  int new_offset = 0;
  offset = new_offset;
  string a = newLabel();
  emit(a, ":", "", "", -1);
  strcpy(((yyval.typ)).gotoname,a.c_str());
  continuelabels.push(a);
}
#line 6417 "parser.tab.c"
    break;

  case 236:
#line 3128 "parser.y"
                                                                           {
  string a = newLabel();
  emit("Goto", ((yyvsp[0].typ)).tempvar, a, "Ifz", -1);
  emit("Goto", ((yyvsp[-4].typ)).gotoname, "", "", -1);
  emit(a, ":", "", "", -1);
  strcpy(((yyval.typ)).gotoname,a.c_str());
  breaklabels.push(a);
}
#line 6430 "parser.tab.c"
    break;

  case 237:
#line 3138 "parser.y"
                                         {
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  offset = offsets.top(); offsets.pop();
  inloop=0;
  isclassaccess=0;
    issystem=0;
    isfinal=0;
  }
#line 6444 "parser.tab.c"
    break;

  case 238:
#line 3147 "parser.y"
                        {
  inloop=1;
  tables.push(curr_table);
  curr_table = new Sym_Table(curr_table);
  list_of_Symbol_Tables.push_back(curr_table);
  scope_names.push(curr_scope);
  string new_scope = "ForStatement";
  curr_scope = new_scope;
  offsets.push(offset);
  int new_offset = 0;
  offset = new_offset;
}
#line 6461 "parser.tab.c"
    break;

  case 239:
#line 3160 "parser.y"
                                                         {
  string a = newLabel();
  emit(a, ":", "", "", -1);
  strcpy(((yyval.typ)).gotoname,a.c_str());
}
#line 6471 "parser.tab.c"
    break;

  case 240:
#line 3166 "parser.y"
                                                  {
 isclassaccess=0;
    issystem=0;
    isfinal=0;
}
#line 6481 "parser.tab.c"
    break;

  case 241:
#line 3172 "parser.y"
                                                   {
  string a = newLabel();
  emit("Goto", ((yyvsp[0].typ)).tempvar, a, "Ifz", -1);
  string b = newLabel();
  emit("Goto", b, "", "", -1);
  strcpy(((yyval.typ)).gotoname,((yyvsp[-1].typ)).gotoname);
  strcpy(((yyval.typ)).nextgoto,a.c_str());
  strcpy(((yyval.typ)).nextgoto1,b.c_str());
  string c = newLabel();
  emit(c, ":", "", "", -1);
  strcpy(((yyval.typ)).nextgoto2,c.c_str());
  isclassaccess=0;
    issystem=0;
  continuelabels.push(c);
}
#line 6501 "parser.tab.c"
    break;

  case 242:
#line 3188 "parser.y"
                                                           {
  emit("Goto", ((yyvsp[-2].typ)).gotoname, "", "", -1);
  emit(((yyvsp[-2].typ)).nextgoto1, ":", "", "", -1);
  strcpy(((yyval.typ)).gotoname,((yyvsp[-2].typ)).gotoname);
  strcpy(((yyval.typ)).nextgoto,((yyvsp[-2].typ)).nextgoto);
  strcpy(((yyval.typ)).nextgoto1,((yyvsp[-2].typ)).nextgoto1);
  strcpy(((yyval.typ)).nextgoto2,((yyvsp[-2].typ)).nextgoto2);
  isclassaccess=0;
    issystem=0;
    isfinal=0;
  breaklabels.push(string((char*)(((yyvsp[-2].typ)).nextgoto)));
}
#line 6518 "parser.tab.c"
    break;

  case 243:
#line 3201 "parser.y"
                                                             {
  emit("Goto", ((yyvsp[-2].typ)).gotoname, "", "", -1);
  emit(((yyvsp[-2].typ)).nextgoto1, ":", "", "", -1);
  strcpy(((yyval.typ)).gotoname,((yyvsp[-2].typ)).gotoname);
  strcpy(((yyval.typ)).nextgoto,((yyvsp[-2].typ)).nextgoto);
  strcpy(((yyval.typ)).nextgoto1,((yyvsp[-2].typ)).nextgoto1);
  strcpy(((yyval.typ)).nextgoto2,((yyvsp[-2].typ)).nextgoto2);
  isclassaccess=0;
    issystem=0;
    isfinal=0;
  breaklabels.push(string((char*)(((yyvsp[-2].typ)).nextgoto)));
}
#line 6535 "parser.tab.c"
    break;

  case 244:
#line 3214 "parser.y"
                                                             {
  string a = newLabel();
  emit(a, ":", "", "", -1);
  strcpy(((yyval.typ)).gotoname,a.c_str());
  isclassaccess=0;
    issystem=0;
    isfinal=0;
}
#line 6548 "parser.tab.c"
    break;

  case 245:
#line 3223 "parser.y"
                                                   {
  string a = newLabel();
  emit("Goto", ((yyvsp[0].typ)).tempvar, a, "Ifz", -1);
  string b = newLabel();
  emit("Goto", b, "", "", -1);
  strcpy(((yyval.typ)).gotoname,((yyvsp[-1].typ)).gotoname);
  strcpy(((yyval.typ)).nextgoto,a.c_str());
  strcpy(((yyval.typ)).nextgoto1,b.c_str());
  string c = newLabel();
  emit(c, ":", "", "", -1);
  strcpy(((yyval.typ)).nextgoto2,c.c_str());
  isclassaccess=0;
    issystem=0;
  continuelabels.push(c);
}
#line 6568 "parser.tab.c"
    break;

  case 246:
#line 3239 "parser.y"
                                                           {
  emit("Goto", ((yyvsp[-2].typ)).gotoname, "", "", -1);
  emit(((yyvsp[-2].typ)).nextgoto1, ":", "", "", -1);
  strcpy(((yyval.typ)).gotoname,((yyvsp[-2].typ)).gotoname);
  strcpy(((yyval.typ)).nextgoto,((yyvsp[-2].typ)).nextgoto);
  strcpy(((yyval.typ)).nextgoto1,((yyvsp[-2].typ)).nextgoto1);
  strcpy(((yyval.typ)).nextgoto2,((yyvsp[-2].typ)).nextgoto2);
  isclassaccess=0;
    issystem=0;
    isfinal=0;
  breaklabels.push(string((char*)(((yyvsp[-2].typ)).nextgoto)));
}
#line 6585 "parser.tab.c"
    break;

  case 247:
#line 3252 "parser.y"
                                                              {
  emit("Goto", ((yyvsp[-2].typ)).gotoname, "", "", -1);
  emit(((yyvsp[-2].typ)).nextgoto1, ":", "", "", -1);
  strcpy(((yyval.typ)).gotoname,((yyvsp[-2].typ)).gotoname);
  strcpy(((yyval.typ)).nextgoto,((yyvsp[-2].typ)).nextgoto);
  strcpy(((yyval.typ)).nextgoto1,((yyvsp[-2].typ)).nextgoto1);
  strcpy(((yyval.typ)).nextgoto2,((yyvsp[-2].typ)).nextgoto2);
  isclassaccess=0;
    issystem=0;
    isfinal=0;
  breaklabels.push(string((char*)(((yyvsp[-2].typ)).nextgoto)));
}
#line 6602 "parser.tab.c"
    break;

  case 248:
#line 3265 "parser.y"
                                                           {
  string a = newLabel();
  string b = newLabel();
  emit("Goto", b, "", "", -1);
  strcpy(((yyval.typ)).gotoname,((yyvsp[-2].typ)).gotoname);
  strcpy(((yyval.typ)).nextgoto,a.c_str());
  strcpy(((yyval.typ)).nextgoto1,b.c_str());
  string c = newLabel();
  emit(c, ":", "", "", -1);
  strcpy(((yyval.typ)).nextgoto2,c.c_str());
  isclassaccess=0;
    issystem=0;
     isfinal=0;
  continuelabels.push(c);
}
#line 6622 "parser.tab.c"
    break;

  case 249:
#line 3281 "parser.y"
                                                 {
  emit("Goto", ((yyvsp[-1].typ)).gotoname, "", "", -1);
  emit(((yyvsp[-1].typ)).nextgoto1, ":", "", "", -1);
  strcpy(((yyval.typ)).gotoname,((yyvsp[-1].typ)).gotoname);
  strcpy(((yyval.typ)).nextgoto,((yyvsp[-1].typ)).nextgoto);
  strcpy(((yyval.typ)).nextgoto1,((yyvsp[-1].typ)).nextgoto1);
  strcpy(((yyval.typ)).nextgoto2,((yyvsp[-1].typ)).nextgoto2);
  breaklabels.push(string((char*)(((yyvsp[-1].typ)).nextgoto)));
}
#line 6636 "parser.tab.c"
    break;

  case 250:
#line 3291 "parser.y"
                                                     {
  emit("Goto", ((yyvsp[-1].typ)).gotoname, "", "", -1);
  emit(((yyvsp[-1].typ)).nextgoto1, ":", "", "", -1);
  strcpy(((yyval.typ)).gotoname,((yyvsp[-1].typ)).gotoname);
  strcpy(((yyval.typ)).nextgoto,((yyvsp[-1].typ)).nextgoto);
  strcpy(((yyval.typ)).nextgoto1,((yyvsp[-1].typ)).nextgoto1);
  strcpy(((yyval.typ)).nextgoto2,((yyvsp[-1].typ)).nextgoto2);
  breaklabels.push(string((char*)(((yyvsp[-1].typ)).nextgoto)));
}
#line 6650 "parser.tab.c"
    break;

  case 251:
#line 3301 "parser.y"
                                                   {
  string a = newLabel();
  string b = newLabel();
  emit("Goto", b, "", "", -1);
  strcpy(((yyval.typ)).gotoname,((yyvsp[-1].typ)).gotoname);
  strcpy(((yyval.typ)).nextgoto,a.c_str());
  strcpy(((yyval.typ)).nextgoto1,b.c_str());
  string c = newLabel();
  emit(c, ":", "", "", -1);
  strcpy(((yyval.typ)).nextgoto2,c.c_str());
  isclassaccess=0;
    issystem=0;
     isfinal=0;
  continuelabels.push(c);
}
#line 6670 "parser.tab.c"
    break;

  case 252:
#line 3317 "parser.y"
                                                   {
  emit("Goto", ((yyvsp[-1].typ)).gotoname, "", "", -1);
  emit(((yyvsp[-1].typ)).nextgoto1, ":", "", "", -1);
  strcpy(((yyval.typ)).gotoname,((yyvsp[-1].typ)).gotoname);
  strcpy(((yyval.typ)).nextgoto,((yyvsp[-1].typ)).nextgoto);
  strcpy(((yyval.typ)).nextgoto1,((yyvsp[-1].typ)).nextgoto1);
  strcpy(((yyval.typ)).nextgoto2,((yyvsp[-1].typ)).nextgoto2);
  breaklabels.push(string((char*)(((yyvsp[-1].typ)).nextgoto)));
}
#line 6684 "parser.tab.c"
    break;

  case 253:
#line 3327 "parser.y"
                                                      {
  emit("Goto", ((yyvsp[-1].typ)).gotoname, "", "", -1);
  emit(((yyvsp[-1].typ)).nextgoto1, ":", "", "", -1);
  strcpy(((yyval.typ)).gotoname,((yyvsp[-1].typ)).gotoname);
  strcpy(((yyval.typ)).nextgoto,((yyvsp[-1].typ)).nextgoto);
  strcpy(((yyval.typ)).nextgoto1,((yyvsp[-1].typ)).nextgoto1);
  strcpy(((yyval.typ)).nextgoto2,((yyvsp[-1].typ)).nextgoto2);
  breaklabels.push(string((char*)(((yyvsp[-1].typ)).nextgoto)));
}
#line 6698 "parser.tab.c"
    break;

  case 254:
#line 3338 "parser.y"
                                          {
  // breaklabels.push(string((char*)(($1).nextgoto)));
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  offset = offsets.top(); offsets.pop();
  inloop=0;
  emit("Goto", ((yyvsp[-2].typ)).nextgoto2, "", "", -1);
  emit(((yyvsp[-2].typ)).nextgoto, ":", "", "", -1);
  continuelabels.pop();
  breaklabels.pop();
  }
#line 6714 "parser.tab.c"
    break;

  case 255:
#line 3349 "parser.y"
                                           {
  // breaklabels.push(string((char*)(($1).nextgoto)));
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  offset = offsets.top(); offsets.pop(); 
  inloop=0;
  emit("Goto", ((yyvsp[-2].typ)).nextgoto2, "", "", -1);
  emit(((yyvsp[-2].typ)).nextgoto, ":", "", "", -1);
  continuelabels.pop();
  breaklabels.pop();
  }
#line 6730 "parser.tab.c"
    break;

  case 256:
#line 3360 "parser.y"
                              {
  // breaklabels.push(string((char*)(($1).nextgoto)));
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  offset = offsets.top(); offsets.pop();
  inloop=0;
  emit("Goto", ((yyvsp[-1].typ)).nextgoto2, "", "", -1);
  emit(((yyvsp[-1].typ)).nextgoto, ":", "", "", -1);
  continuelabels.pop();
  breaklabels.pop();
  }
#line 6746 "parser.tab.c"
    break;

  case 257:
#line 3371 "parser.y"
                                            {
  // breaklabels.push(string((char*)(($1).nextgoto)));
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  offset = offsets.top(); offsets.pop();
  inloop=0;
  emit("Goto", ((yyvsp[-2].typ)).nextgoto2, "", "", -1);
  emit(((yyvsp[-2].typ)).nextgoto, ":", "", "", -1);
  continuelabels.pop();
  breaklabels.pop();
  }
#line 6762 "parser.tab.c"
    break;

  case 258:
#line 3382 "parser.y"
                               {
  // breaklabels.push(string((char*)(($1).nextgoto)));
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  offset = offsets.top(); offsets.pop();
  inloop=0;
  emit("Goto", ((yyvsp[-1].typ)).nextgoto2, "", "", -1);
  emit(((yyvsp[-1].typ)).nextgoto, ":", "", "", -1);
  continuelabels.pop();
  breaklabels.pop();
  }
#line 6778 "parser.tab.c"
    break;

  case 259:
#line 3393 "parser.y"
                              {
  // breaklabels.push(string((char*)(($1).nextgoto)));
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  offset = offsets.top(); offsets.pop();
  inloop=0;
  emit("Goto", ((yyvsp[-1].typ)).nextgoto2, "", "", -1);
  emit(((yyvsp[-1].typ)).nextgoto, ":", "", "", -1);
  continuelabels.pop();
  breaklabels.pop();
  }
#line 6794 "parser.tab.c"
    break;

  case 260:
#line 3404 "parser.y"
                               {
  // breaklabels.push(string((char*)(($1).nextgoto)));
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  offset = offsets.top(); offsets.pop();
  inloop=0;
  emit("Goto", ((yyvsp[-1].typ)).nextgoto2, "", "", -1);
  emit(((yyvsp[-1].typ)).nextgoto, ":", "", "", -1);
  continuelabels.pop();
  breaklabels.pop();
  }
#line 6810 "parser.tab.c"
    break;

  case 261:
#line 3415 "parser.y"
                                           {
  // breaklabels.push(string((char*)(($1).nextgoto)));
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  offset = offsets.top(); offsets.pop();
  inloop=0;
  emit("Goto", ((yyvsp[-2].typ)).nextgoto2, "", "", -1);
  emit(((yyvsp[-2].typ)).nextgoto, ":", "", "", -1);
  continuelabels.pop();
  breaklabels.pop();
  }
#line 6826 "parser.tab.c"
    break;

  case 262:
#line 3428 "parser.y"
                                                   {
  // breaklabels.push(string((char*)(($1).nextgoto)));
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  offset = offsets.top(); offsets.pop();
  inloop=0;
  emit("Goto", ((yyvsp[-2].typ)).nextgoto2, "", "", -1);
  emit(((yyvsp[-2].typ)).nextgoto, ":", "", "", -1);
  continuelabels.pop();
  breaklabels.pop();
  }
#line 6842 "parser.tab.c"
    break;

  case 263:
#line 3439 "parser.y"
                                                    {
  // breaklabels.push(string((char*)(($1).nextgoto)));
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  offset = offsets.top(); offsets.pop();
  inloop=0;
  emit("Goto", ((yyvsp[-2].typ)).nextgoto2, "", "", -1);
  emit(((yyvsp[-2].typ)).nextgoto, ":", "", "", -1);
  continuelabels.pop();
  breaklabels.pop();
  }
#line 6858 "parser.tab.c"
    break;

  case 264:
#line 3450 "parser.y"
                                       {
  // breaklabels.push(string((char*)(($1).nextgoto)));
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  offset = offsets.top(); offsets.pop();
  inloop=0;
  emit("Goto", ((yyvsp[-1].typ)).nextgoto2, "", "", -1);
  emit(((yyvsp[-1].typ)).nextgoto, ":", "", "", -1);
  continuelabels.pop();
  breaklabels.pop();
  }
#line 6874 "parser.tab.c"
    break;

  case 265:
#line 3461 "parser.y"
                                                     {
  // breaklabels.push(string((char*)(($1).nextgoto)));
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  offset = offsets.top(); offsets.pop();
  inloop=0;
  emit("Goto", ((yyvsp[-2].typ)).nextgoto2, "", "", -1);
  emit(((yyvsp[-2].typ)).nextgoto, ":", "", "", -1);
  continuelabels.pop();
  breaklabels.pop();
  }
#line 6890 "parser.tab.c"
    break;

  case 266:
#line 3472 "parser.y"
                                        {
  // breaklabels.push(string((char*)(($1).nextgoto)));
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  offset = offsets.top(); offsets.pop();
  inloop=0;
  emit("Goto", ((yyvsp[-1].typ)).nextgoto2, "", "", -1);
  emit(((yyvsp[-1].typ)).nextgoto, ":", "", "", -1);
  continuelabels.pop();
  breaklabels.pop();
  }
#line 6906 "parser.tab.c"
    break;

  case 267:
#line 3483 "parser.y"
                                       {
  // breaklabels.push(string((char*)(($1).nextgoto)));
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  offset = offsets.top(); offsets.pop();
  inloop=0;
  emit("Goto", ((yyvsp[-1].typ)).nextgoto2, "", "", -1);
  emit(((yyvsp[-1].typ)).nextgoto, ":", "", "", -1);
  continuelabels.pop();
  breaklabels.pop();
  }
#line 6922 "parser.tab.c"
    break;

  case 268:
#line 3494 "parser.y"
                                        {
  // breaklabels.push(string((char*)(($1).nextgoto)));
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  offset = offsets.top(); offsets.pop();
  inloop=0;
  emit("Goto", ((yyvsp[-1].typ)).nextgoto2, "", "", -1);
  emit(((yyvsp[-1].typ)).nextgoto, ":", "", "", -1);
  continuelabels.pop();
  breaklabels.pop();
  }
#line 6938 "parser.tab.c"
    break;

  case 269:
#line 3505 "parser.y"
                                                    {
  // breaklabels.push(string((char*)(($1).nextgoto)));
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  offset = offsets.top(); offsets.pop();
  inloop=0;
  emit("Goto", ((yyvsp[-2].typ)).nextgoto2, "", "", -1);
  emit(((yyvsp[-2].typ)).nextgoto, ":", "", "", -1);
  continuelabels.pop();
  breaklabels.pop();
  }
#line 6954 "parser.tab.c"
    break;

  case 270:
#line 3517 "parser.y"
                        {
}
#line 6961 "parser.tab.c"
    break;

  case 271:
#line 3519 "parser.y"
                          {
}
#line 6968 "parser.tab.c"
    break;

  case 272:
#line 3523 "parser.y"
                        {
}
#line 6975 "parser.tab.c"
    break;

  case 273:
#line 3527 "parser.y"
                    {
}
#line 6982 "parser.tab.c"
    break;

  case 274:
#line 3529 "parser.y"
                                                   {
}
#line 6989 "parser.tab.c"
    break;

  case 275:
#line 3533 "parser.y"
                {
  isclassaccess=0;
   isfinal=0;
  if(!inloop)
  {
    cout<<"Invalid use of break on line "<<yylineno<<'\n';
  }
    issystem=0;
  // cout<<"SIZE "<<breaklabels.size()<<'\n';
  if(breaklabels.size())
  emit("Goto", breaklabels.top(), "", "", -1);
}
#line 7006 "parser.tab.c"
    break;

  case 276:
#line 3545 "parser.y"
                            {
  if(curr_table->lookup(string((char*)((yyvsp[-2].lex)).str)).offset == -1 && checkobj(string((char*)((yyvsp[-2].lex)).str)) == 0){
    cout<<"Undeclared variable on line "<< yylineno<<"\n";
  }
  if(!inloop)
  {
    cout<<"Invalid use of break on line "<<yylineno<<'\n';
  }
  isclassaccess=0;
    issystem=0;
     isfinal=0;
  if(breaklabels.size())
  emit("Goto", breaklabels.top(), "", "", -1);
}
#line 7025 "parser.tab.c"
    break;

  case 277:
#line 3561 "parser.y"
                              {
  if(curr_table->lookup(string((char*)((yyvsp[-2].lex)).str)).offset == -1 && checkobj(string((char*)((yyvsp[-2].lex)).str)) == 0){
    cout<<"Undeclared variable on line "<< yylineno<<"\n";
  }
  if(!inloop)
  {
    cout<<"Invalid continue on line "<<yylineno<<'\n';
  }
    if(continuelabels.size())
  emit("Goto", continuelabels.top(), "", "", -1);
 isfinal=0;
    isclassaccess=0;
    issystem=0;
}
#line 7044 "parser.tab.c"
    break;

  case 278:
#line 3575 "parser.y"
                    {
   isfinal=0;
  if(!inloop)
  {
    cout<<"Invalid continue on line "<<yylineno<<'\n';
  }
  isclassaccess=0;
    issystem=0;
  if(continuelabels.size())
  emit("Goto", continuelabels.top(), "", "", -1);
}
#line 7060 "parser.tab.c"
    break;

  case 279:
#line 3588 "parser.y"
                 {
  if(!infunction)
  {
    cout<<"Invalid return on line "<<yylineno<<'\n';
  }
  isclassaccess=0;
    issystem=0;
  emit("Return", "", "", "", -1);
}
#line 7074 "parser.tab.c"
    break;

  case 280:
#line 3597 "parser.y"
                             {
  string p = string((char*)((yyvsp[-1].typ)).tempvar);
    string o = p.substr(0, p.find('.'));
    if(p != o){
      string v = p.substr(p.find('.')+1, p.size());
      int tp2 = curr_table->lookup(v).offset;
      string tp3 = "*(" + o + "+" + to_string(tp2) + ")";
      strcpy(((yyvsp[-1].typ)).tempvar, tp3.c_str());
    }
    emit("Return", ((yyvsp[-1].typ)).tempvar , "", "", -1);
  if(!infunction)
  {
    cout<<"Invalid return on line "<<yylineno<<'\n';
  }
  else
  {
    isreturn=1;
    if(!boolgetorder(functype.c_str(),((yyvsp[-1].typ)).type,1))
    {
      if(strcmp(functype.c_str(),((yyvsp[-1].typ)).type))
      {
        cout<<"Return type mismatch on line "<<yylineno<<'\n';
      }
    }
  }
  isclassaccess=0;
    issystem=0;
}
#line 7107 "parser.tab.c"
    break;

  case 281:
#line 3626 "parser.y"
                           {
  isclassaccess=0;
    issystem=0;
     isfinal=0;
}
#line 7117 "parser.tab.c"
    break;

  case 282:
#line 3632 "parser.y"
                                                       {
}
#line 7124 "parser.tab.c"
    break;

  case 283:
#line 3635 "parser.y"
                  {
}
#line 7131 "parser.tab.c"
    break;

  case 284:
#line 3637 "parser.y"
                           {
}
#line 7138 "parser.tab.c"
    break;

  case 285:
#line 3639 "parser.y"
                   {
}
#line 7145 "parser.tab.c"
    break;

  case 286:
#line 3642 "parser.y"
            {
}
#line 7152 "parser.tab.c"
    break;

  case 287:
#line 3644 "parser.y"
                     {
}
#line 7159 "parser.tab.c"
    break;

  case 288:
#line 3647 "parser.y"
      {
  tables.push(curr_table);
  curr_table = new Sym_Table(curr_table);
  list_of_Symbol_Tables.push_back(curr_table);
  scope_names.push(curr_scope);
  string new_scope = "CatchStatement";
  curr_scope = new_scope;
  offsets.push(offset);
  int new_offset = 0;
  offset = new_offset;
}
#line 7175 "parser.tab.c"
    break;

  case 289:
#line 3658 "parser.y"
                                               {
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  offset = offsets.top(); offsets.pop();
}
#line 7185 "parser.tab.c"
    break;

  case 290:
#line 3664 "parser.y"
              {
}
#line 7192 "parser.tab.c"
    break;

  case 291:
#line 3667 "parser.y"
                  {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);

  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
  ((yyval.typ)).ndim=((yyvsp[0].typ)).ndim;
}
#line 7203 "parser.tab.c"
    break;

  case 292:
#line 3675 "parser.y"
                         {
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);
  
  
}
#line 7214 "parser.tab.c"
    break;

  case 293:
#line 3682 "parser.y"
        {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);

  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
}
#line 7224 "parser.tab.c"
    break;

  case 294:
#line 3687 "parser.y"
      {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].lex)).str);
  strcpy(((yyval.typ)).type,((yyvsp[0].lex)).str);
}
#line 7233 "parser.tab.c"
    break;

  case 295:
#line 3691 "parser.y"
                                     {

  strcpy(((yyval.typ)).tempvar, strcat(((yyvsp[-2].lex)).str, strcat(((yyvsp[-1].typ)).tempvar, ((yyvsp[0].lex)).str)));
  
  strcpy(((yyval.typ)).type,((yyvsp[-1].typ)).type);
  
}
#line 7245 "parser.tab.c"
    break;

  case 296:
#line 3698 "parser.y"
                                 {
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
  
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);
}
#line 7255 "parser.tab.c"
    break;

  case 297:
#line 3703 "parser.y"
             {

  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);
  
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
  
}
#line 7267 "parser.tab.c"
    break;

  case 298:
#line 3710 "parser.y"
                  {

  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);
  
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
  
}
#line 7279 "parser.tab.c"
    break;

  case 299:
#line 3717 "parser.y"
             {
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
  
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);
  
}
#line 7290 "parser.tab.c"
    break;

  case 300:
#line 3724 "parser.y"
                                                    {
  int pops = 0;
  string ar = "";
  stack<string> args2;
  while(!args.empty())
  {
    auto arg = args.top();
    args2.push(arg.first);
    emit("Pushparams",arg.first,"","",-1);
    pops += arg.second;
    args.pop();
  }
  while(!args2.empty())
  {
    auto arg = args2.top();
    ar = ar + arg;
    args2.pop();
    if(!args2.empty()) ar = ar + ",";
  }
  ar = string((char*)((yyvsp[-3].typ)).tempvar) + "(" + ar + ")";
  string s = newtemp();
  strcpy(((yyval.typ)).tempvar, s.c_str());
  emit("=", "new", ar, ((yyval.typ)).tempvar, -1);
  emit("Popparams",to_string(pops),"","",-1);


  strcpy(((yyval.typ)).type,((yyvsp[-3].typ)).type);
  // cout<<"LLL"<<($$).type<<'\n';
  if((curr_table->lookup(string((char*)((yyvsp[-3].typ)).type)).offset == -1)&& checkobj(string((char*)((yyvsp[-3].typ)).type)) == 0){
    if(strcmp(((yyvsp[-3].typ)).type,"System")&&!isaccess) 
    {
      cout<<"Undeclared variable "<<((yyvsp[-3].typ)).type<<" on line "<< yylineno<<"\n";
      // cout<<"KKK"<<($1).type<<'\n';
    }  
  }
  else
  {
    if(curr_table->lookup(string((char*)((yyvsp[-3].typ)).type)).narg != ((yyvsp[-1].typ)).nelem)
    {
      cout<<"Incorrect number of arguments passed to Constructor on line "<< yylineno<<"\n";
      // cout<<"LLL"<<curr_table->lookup(string((char*)($1).type)).narg<<($3).nelem<<'\n';
    }
    else
    {
      strcat(((yyvsp[-1].typ)).argstring,"#");
      // cout<<($4).argstring<<'\n';
      int j=0;
      string yo="";
      string shubhan="Constructor"+string((char*)((yyvsp[-3].typ)).type);
      // cout<<shubhan<<'\n';
      for(int i=0;i<((yyvsp[-1].typ)).nelem;i++)
      {
        for(;;)
        {
          if(((yyvsp[-1].typ)).argstring[j]=='$'||((yyvsp[-1].typ)).argstring[j]=='#') 
          {
            j++;
            break;
          }
          yo+=((yyvsp[-1].typ)).argstring[j];
          j++;
        }
        // cout<<yo<<'\n';
        auto it = lookup1(shubhan, i+1);
        // cout<<it.type<<'\n';
        if(!boolgetorder(it.type.c_str(),yo.c_str(),1)&&strcmp(it.type.c_str(),yo.c_str()))
        {
          cout<<"Argument "<<i+1<<" does not match Constructor definiton of "<<((yyvsp[-3].typ)).type<<" on line "<<yylineno<<'\n';
          yo="";
        }

        else
        {
          yo="";
        }
      }
    }
  }
  isaccess=0;
  // cout<<($2).type<<'\n';
  
}
#line 7377 "parser.tab.c"
    break;

  case 301:
#line 3806 "parser.y"
                                        {
  string a = newtemp();
  strcpy(((yyval.typ)).tempvar, a.c_str());
  emit("=", "new", string((char*)((yyvsp[-2].typ)).type) + "()", ((yyval.typ)).tempvar, -1);

  strcpy(((yyval.typ)).type,((yyvsp[-2].typ)).type);
  if((curr_table->lookup(string((char*)((yyvsp[-2].typ)).type)).offset == -1)&& checkobj(string((char*)((yyvsp[-2].typ)).type)) == 0){
    if(strcmp(((yyvsp[-2].typ)).type,"System")&&!isaccess) 
    {
      cout<<"Undeclared variable "<<((yyvsp[-2].typ)).type<<" on line "<< yylineno<<"\n";
      // cout<<"KKK"<<($1).type<<'\n';
    }  
  }
  else
  {
    if(curr_table->lookup(string((char*)((yyvsp[-2].typ)).type)).narg != 0)
    {
      cout<<"Incorrect number of arguments passed to Constructor on line "<< yylineno<<"\n";
      // cout<<"LLL"<<curr_table->lookup(string((char*)($1).type)).narg<<($3).nelem<<'\n';
    }
  }
  isaccess=0;
  // cout<<($2).type<<'\n';
}
#line 7406 "parser.tab.c"
    break;

  case 302:
#line 3831 "parser.y"
           {
  args.push({string((char*)((yyvsp[0].typ)).tempvar), size});
  strcpy(((yyval.typ)).argstring, ((yyvsp[0].typ)).type);
  // cout<<"XXX"<<($$).argstring<<'\n';
  ((yyval.typ)).nelem=1;
}
#line 7417 "parser.tab.c"
    break;

  case 303:
#line 3837 "parser.y"
                               {
  args.push({string((char*)((yyvsp[0].typ)).tempvar), size});
  strcat(((yyval.typ)).argstring, "$");
  strcat(((yyval.typ)).argstring, ((yyvsp[0].typ)).type);
  // cout<<"XXX"<<($$).argstring<<'\n';
  ((yyval.typ)).nelem=((yyvsp[-2].typ)).nelem+1;
}
#line 7429 "parser.tab.c"
    break;

  case 304:
#line 3846 "parser.y"
                                {
  offset -= getsize(string((char*)((yyvsp[-2].typ)).type));
  strcpy(((yyval.typ)).tempvar, newtemp().c_str());
  emit("=", "new", string((char*)((yyvsp[-2].typ)).tempvar) + string((char*)((yyvsp[-1].typ)).tempvar) + string((char*)((yyvsp[0].typ)).tempvar), ((yyval.typ)).tempvar, -1);
  flagyo=1;
  strcpy(((yyval.typ)).arrtype,((yyvsp[-2].typ)).type);
  ((yyval.typ)).ndim = ((yyvsp[-1].typ)).ndim + ((yyvsp[0].typ)).ndim;
  strcpy(((yyval.typ)).type,((yyvsp[-2].typ)).type);
  for(int i=0;i<((yyval.typ)).ndim;i++)
  {
    strcat(((yyval.typ)).type,"[]");
  }
}
#line 7447 "parser.tab.c"
    break;

  case 305:
#line 3859 "parser.y"
                            {
  offset -= getsize(string((char*)((yyvsp[-1].typ)).type));
  strcpy(((yyval.typ)).tempvar, newtemp().c_str());
  emit("=", "new", string((char*)((yyvsp[-1].typ)).tempvar) + string((char*)((yyvsp[0].typ)).tempvar), ((yyval.typ)).tempvar, -1);

  flagyo=1;
  strcpy(((yyval.typ)).type,"array");
  strcpy(((yyval.typ)).arrtype,((yyvsp[-1].typ)).type);
  ((yyval.typ)).ndim = ((yyvsp[0].typ)).ndim;  
  strcpy(((yyval.typ)).type,((yyvsp[-1].typ)).type);
  for(int i=0;i<((yyval.typ)).ndim;i++)
  {
    strcat(((yyval.typ)).type,"[]");
  }
  
}
#line 7468 "parser.tab.c"
    break;

  case 306:
#line 3875 "parser.y"
                                        {
  strcpy(((yyval.typ)).tempvar, newtemp().c_str());
  emit("=", "new", string((char*)((yyvsp[-2].typ)).tempvar) + string((char*)((yyvsp[-1].typ)).tempvar) + string((char*)((yyvsp[0].typ)).tempvar), ((yyval.typ)).tempvar, -1);
  flagyo=1;
  strcpy(((yyval.typ)).type,"array");
  strcpy(((yyval.typ)).arrtype,((yyvsp[-2].typ)).type);
  ((yyval.typ)).ndim = ((yyvsp[-1].typ)).ndim + ((yyvsp[0].typ)).ndim;
  strcpy(((yyval.typ)).type,((yyvsp[-2].typ)).type);
  for(int i=0;i<((yyval.typ)).ndim;i++)
  {
    strcat(((yyval.typ)).type,"[]");
  }
  
  
}
#line 7488 "parser.tab.c"
    break;

  case 307:
#line 3890 "parser.y"
                                   {
  strcpy(((yyval.typ)).tempvar, newtemp().c_str());
  emit("=", "new", string((char*)((yyvsp[-1].typ)).tempvar) + string((char*)((yyvsp[0].typ)).tempvar), ((yyval.typ)).tempvar, -1);
  flagyo=1;
  strcpy(((yyval.typ)).type,"array");
  strcpy(((yyval.typ)).arrtype,((yyvsp[-1].typ)).type);
  ((yyval.typ)).ndim = ((yyvsp[0].typ)).ndim;
  strcpy(((yyval.typ)).type,((yyvsp[-1].typ)).type);
  for(int i=0;i<((yyval.typ)).ndim;i++)
  {
    strcat(((yyval.typ)).type,"[]");
  }
  
  
}
#line 7508 "parser.tab.c"
    break;

  case 308:
#line 3906 "parser.y"
        {
  ((yyval.typ)).ndim=1;
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);
}
#line 7517 "parser.tab.c"
    break;

  case 309:
#line 3910 "parser.y"
                  {
  ((yyval.typ)).ndim = ((yyvsp[-1].typ)).ndim + 1;
  strcpy(((yyval.typ)).tempvar, strcat(((yyvsp[-1].typ)).tempvar, ((yyvsp[0].typ)).tempvar));
}
#line 7526 "parser.tab.c"
    break;

  case 310:
#line 3915 "parser.y"
                                                {
  strcpy(((yyval.typ)).tempvar, strcat(((yyvsp[-2].lex)).str, strcat(((yyvsp[-1].typ)).tempvar, ((yyvsp[0].lex)).str)));
  ((yyval.typ)).ndim=1;
  
  
}
#line 7537 "parser.tab.c"
    break;

  case 311:
#line 3923 "parser.y"
                                     {
  strcpy(((yyval.typ)).tempvar, strcat(((yyvsp[-1].lex)).str, ((yyvsp[0].lex)).str));
  strcpy(((yyval.typ)).tempvar, strcat(((yyvsp[-1].lex)).str, ((yyvsp[0].lex)).str));
  ((yyval.typ)).ndim=1;
  
}
#line 7548 "parser.tab.c"
    break;

  case 312:
#line 3929 "parser.y"
                                           {
  strcpy(((yyval.typ)).tempvar, strcat(((yyvsp[-2].typ)).tempvar, strcat(((yyvsp[-1].lex)).str, ((yyvsp[0].lex)).str)));
  ((yyval.typ)).ndim = ((yyvsp[-2].typ)).ndim + 1;
}
#line 7557 "parser.tab.c"
    break;

  case 313:
#line 3935 "parser.y"
                       {
  strcpy(((yyval.typ)).tempvar, strcat(((yyvsp[-2].typ)).tempvar, strcat(((yyvsp[-1].lex)).str, ((yyvsp[0].lex)).str)));
  if(curr_table->lookup(string((char*)((yyvsp[0].lex)).str)).offset == -1 && checkobj(string((char*)((yyvsp[0].lex)).str)) == 0){
    cout<<"Undeclared variable on line "<< yylineno<<"\n";
  }
  if(strcmp(((yyvsp[-2].typ)).type,"this")==0)
  {
    // if(curr_table->lookup(string((char*)($3).str)).isitstatic&&curr_scope.substr(6,curr_scope.size()-6))
    strcpy(((yyval.typ)).type,curr_table->thislookup(((yyvsp[0].lex)).str).c_str());
    // cout<<"GHI"<<curr_table->thislookup(($3).str)<<'\n';
  } 
}
#line 7574 "parser.tab.c"
    break;

  case 314:
#line 3947 "parser.y"
                      {
  strcpy(((yyval.typ)).tempvar, strcat(((yyvsp[-2].lex)).str, strcat(((yyvsp[-1].lex)).str, ((yyvsp[0].lex)).str)));
  if(curr_table->lookup(string((char*)((yyvsp[0].lex)).str)).offset == -1 && checkobj(string((char*)((yyvsp[0].lex)).str)) == 0){
    cout<<"Undeclared variable on line "<< yylineno<<"\n";
  }
}
#line 7585 "parser.tab.c"
    break;

  case 315:
#line 3954 "parser.y"
                            {
  //emit(string((char*)($1).type),"","","",-1);
  //emit("BeginFunc","","","",-1);
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
  strcpy(((yyval.typ)).tempvar,((yyvsp[0].typ)).tempvar);
}
#line 7596 "parser.tab.c"
    break;

  case 316:
#line 3962 "parser.y"
                                                            {
  int pops = 0;
  string ar = "";
  stack<string> args2;
  while(!args.empty())
  {
    auto arg = args.top();
    args2.push(arg.first);
    emit("Pushparams",arg.first,"","",-1);
    pops += arg.second;
    args.pop();
  }
  while(!args2.empty())
  {
    auto arg = args2.top();
    ar = ar + arg;
    args2.pop();
    if(!args2.empty()) ar = ar + ",";
  }
  ar = string((char*)((yyvsp[-3].typ)).tempvar) + "(" + ar + ")";
  string s = newtemp();
  emit("Call",ar,"null",s.c_str(),-1);
  strcpy(((yyval.typ)).tempvar,s.c_str());
  emit("Popparams",to_string(pops),"","",-1);
  //emit("EndFunc","","","",-1);

  // if(curr_table->lookup(string((char*)($1).type))->offset == -1){
  //   cout<<"Undeclared variable on line "<< yylineno<<"\n";
  // }
  // cout<<isaccess<<'\n';
  if((curr_table->lookup(string((char*)((yyvsp[-3].typ)).type)).offset == -1)&& checkobj(string((char*)((yyvsp[-3].typ)).type)) == 0){
    if(strcmp(((yyvsp[-3].typ)).type,"System")&&!isaccess) 
    {
      cout<<"Undeclared variable "<<((yyvsp[-3].typ)).type<<" on line "<< yylineno<<"\n";
      // cout<<"KKK"<<($1).type<<'\n';
    }  
  }
  if(!isaccess)
  {
    if(curr_table->lookup(string((char*)((yyvsp[-3].typ)).type)).narg != ((yyvsp[-1].typ)).nelem)
    {
      cout<<"Incorrect number of arguments passed to function on line "<< yylineno<<"\n";
      // cout<<"LLL"<<curr_table->lookup(string((char*)($1).type)).narg<<($3).nelem<<'\n';
    }
    else
    {
      strcat(((yyvsp[-1].typ)).argstring,"#");
      // cout<<($3).argstring<<'\n';
      int j=0;
      string yo="";
      string shubhan="Method"+string((char*)((yyvsp[-3].typ)).type);
      // cout<<shubhan<<'\n';
      for(int i=0;i<((yyvsp[-1].typ)).nelem;i++)
      {
        for(;;)
        {
          if(((yyvsp[-1].typ)).argstring[j]=='$'||((yyvsp[-1].typ)).argstring[j]=='#') 
          {
            j++;
            break;
          }
          yo+=((yyvsp[-1].typ)).argstring[j];
          j++;
        }
        // cout<<yo<<'\n';
        auto it = lookup1(shubhan, i+1);
        // cout<<it.type<<'\n';
        if(!boolgetorder(it.type.c_str(),yo.c_str(),1)&&strcmp(it.type.c_str(),yo.c_str()))
        {
          cout<<"Argument "<<i+1<<" does not match function definiton of "<<((yyvsp[-3].typ)).type<<" on line "<<yylineno<<'\n';
          yo="";
        }

        else
        {
          yo="";
        }
      }
    }
  }
  else if(isaccess)
  {
    // cout<<"YOYO\n";
    // cout<<checknarg(fullname, 0, classname)<<($3).nelem<<'\n';
    if(checknarg(fullname, 0, classname)!=((yyvsp[-1].typ)).nelem)
    {
      // cout<<classname<<'\n';
      // cout<<"YOOOOO"<<checknarg(fullname,0, classname)<<'\n';
      if(strcmp(classname.c_str(),"null")&&!issystem)cout<<"Incorrect number of arguments passed to function on line "<< yylineno<<"\n";
      // cout<<"LLL"<<curr_table->lookup(string((char*)($1).type)).narg<<($3).nelem<<'\n';
    }
    else
    {
      strcat(((yyvsp[-1].typ)).argstring,"#");
      // cout<<($3).argstring<<'\n';
      int j=0;
      string yo="";
      string shubhan="Method"+string((char*)((yyvsp[-3].typ)).type);
      // cout<<shubhan<<'\n';
      for(int i=0;i<((yyvsp[-1].typ)).nelem;i++)
      {
        for(;;)
        {
          if(((yyvsp[-1].typ)).argstring[j]=='$'||((yyvsp[-1].typ)).argstring[j]=='#') 
          {
            j++;
            break;
          }
          yo+=((yyvsp[-1].typ)).argstring[j];
          j++;
        }
        // cout<<yo<<'\n';
        auto it = checkobjentry(fullname, i+1,classname);
        // cout<<it<<yo<<'\n';
        if(!boolgetorder(it.c_str(),yo.c_str(),1)&&strcmp(it.c_str(),yo.c_str()))
        {
          cout<<"Argument "<<i+1<<" does not match function definition on line "<<yylineno<<'\n';
          yo="";
        }

        else
        {
          yo="";
        }
      }
    }
  }
  fullname="";
  classname="";
  isaccess=0;
  // yo="";
}
#line 7733 "parser.tab.c"
    break;

  case 317:
#line 4094 "parser.y"
                                                {
  string s = newtemp();
  emit("Call",string((char*)((yyvsp[-2].typ)).tempvar) + "()","null",s.c_str(),-1);
  strcpy(((yyval.typ)).tempvar,s.c_str());
  // emit("EndFunc","","","",-1);
    if((curr_table->lookup(string((char*)((yyvsp[-2].typ)).type)).offset == -1)&& checkobj(string((char*)((yyvsp[-2].typ)).type)) == 0){
    if(strcmp(((yyvsp[-2].typ)).type,"System")&&!isaccess) 
    {
      cout<<"Undeclared variable "<<((yyvsp[-2].typ)).type<<" on line "<< yylineno<<"\n";
      // cout<<"KKK"<<($1).type<<'\n';
    }  
  }
  if(!isaccess)
  {
    if(curr_table->lookup(string((char*)((yyvsp[-2].typ)).type)).narg != 0)
    {
      cout<<"Incorrect number of arguments passed to function on line "<< yylineno<<"\n";
      // cout<<"LLL"<<curr_table->lookup(string((char*)($1).type)).narg<<($3).nelem<<'\n';
    }
  }
  else if(isaccess)
  {
    // cout<<"YOYO\n";
    // cout<<checknarg(fullname, 0, classname)<<($3).nelem<<'\n';
    if(checknarg(fullname, 0, classname)!=0)
    {
      // cout<<classname<<'\n';
      // cout<<"YOOOOO"<<checknarg(fullname,0, classname)<<'\n';
      if(checknarg(fullname, 0, classname)==-1) cout<<"The accessed function is not defined on line "<<yylineno<<'\n';
      else if(strcmp(classname.c_str(),"null"))cout<<"Incorrect number of arguments passed to function on line "<< yylineno<<"\n";
      // cout<<"LLL"<<curr_table->lookup(string((char*)($1).type)).narg<<($3).nelem<<'\n';
    }
  }
  fullname="";
  classname="";
  isaccess=0;
}
#line 7775 "parser.tab.c"
    break;

  case 318:
#line 4131 "parser.y"
                                                              {
  int pops = 0;
  string ar = "";
  stack<string> args2;
  while(!args.empty())
  {
    auto arg = args.top();
    args2.push(arg.first);
    emit("Pushparams",arg.first,"","",-1);
    pops += arg.second;
    args.pop();
  }
  while(!args2.empty())
  {
    auto arg = args2.top();
    ar = ar + arg;
    args2.pop();
    if(!args2.empty()) ar = ar + ",";
  }
  ar = string((char*)((yyvsp[-5].typ)).tempvar) + string((char*)((yyvsp[-4].lex)).str) + string((char*)((yyvsp[-3].lex)).str) + "(" + ar + ")";
  string s = newtemp();
  emit("Call",ar,"null",s.c_str(),-1);
  strcpy(((yyval.typ)).tempvar,s.c_str());
  emit("Popparams",to_string(pops),"","",-1);

  if(curr_table->lookup(string((char*)((yyvsp[-3].lex)).str)).offset == -1 && checkobj(string((char*)((yyvsp[-3].lex)).str)) == 0){
    if(!isaccess)
    {
      cout<<"Undeclared variable on line "<< yylineno<<"\n";
    }
  }
  isaccess=0;
}
#line 7813 "parser.tab.c"
    break;

  case 319:
#line 4164 "parser.y"
                                                 {
  string s = newtemp();
  emit("Call",string((char*)((yyvsp[-4].typ)).tempvar) + string((char*)((yyvsp[-3].lex)).str) + string((char*)((yyvsp[-2].lex)).str) + "()","null",s.c_str(),-1);
  strcpy(((yyval.typ)).tempvar,s.c_str());

  if(curr_table->lookup(string((char*)((yyvsp[-2].lex)).str)).offset == -1 && checkobj(string((char*)((yyvsp[-2].lex)).str)) == 0){
  if(!isaccess)
    {
      cout<<"Undeclared variable on line "<< yylineno<<"\n";
    }
  }
  isaccess=0;
}
#line 7831 "parser.tab.c"
    break;

  case 320:
#line 4177 "parser.y"
                                                            {
  int pops = 0;
  string ar = "";
  stack<string> args2;
  while(!args.empty())
  {
    auto arg = args.top();
    args2.push(arg.first);
    emit("Pushparams",arg.first,"","",-1);
    pops += arg.second;
    args.pop();
  }
  while(!args2.empty())
  {
    auto arg = args2.top();
    ar = ar + arg;
    args2.pop();
    if(!args2.empty()) ar = ar + ",";
  }
  ar = string((char*)((yyvsp[-5].lex)).str) + string((char*)((yyvsp[-4].lex)).str) + string((char*)((yyvsp[-3].lex)).str) + "(" + ar + ")";
  string s = newtemp();
  emit("Call",ar,"null",s.c_str(),-1);
  strcpy(((yyval.typ)).tempvar,s.c_str());
  emit("Popparams",to_string(pops),"","",-1);

  if(curr_table->lookup(string((char*)((yyvsp[-3].lex)).str)).offset == -1 && checkobj(string((char*)((yyvsp[-3].lex)).str)) == 0){
  if(!isaccess)
    {
      cout<<"Undeclared variable on line "<< yylineno<<"\n";
    }
  }
  isaccess=0;
}
#line 7869 "parser.tab.c"
    break;

  case 321:
#line 4210 "parser.y"
                                               {
  string s = newtemp();
  emit("Call",string((char*)((yyvsp[-4].lex)).str) + string((char*)((yyvsp[-3].lex)).str) + string((char*)((yyvsp[-2].lex)).str) + "()","null",s.c_str(),-1);
  strcpy(((yyval.typ)).tempvar,s.c_str());

  if(curr_table->lookup(string((char*)((yyvsp[-2].lex)).str)).offset == -1 && checkobj(string((char*)((yyvsp[-2].lex)).str)) == 0){
  if(!isaccess)
    {
      cout<<"Undeclared variable on line "<< yylineno<<"\n";
    }
  }
  isaccess=0;
}
#line 7887 "parser.tab.c"
    break;

  case 322:
#line 4225 "parser.y"
                                                     {
    strcpy(((yyval.typ)).tempvar, newtemp().c_str());
  string tp4;
  string tp5 = curr_table->lookup(string((char*)((yyvsp[-3].typ)).type)).type;
  for(auto it: tp5){
    if(it != '['){
      tp4.push_back(it);
    }
    else{
      break;
    }
  }
  string tp7 = newtemp();
  string tp8 = string((char*)((yyvsp[-1].typ)).tempvar)+ "*" + to_string(4);
  emit("=",tp8,"null",tp7,-1);
  string tp6 = "*(" + string((char*)((yyvsp[-3].typ)).tempvar) + "+" + tp7 + ")";
  emit("=",tp6,"null",string((char*)((yyval.typ)).tempvar),-1);
  

  arraccess=1;
  if(curr_table->lookup(string((char*)((yyvsp[-3].typ)).type)).offset == -1 && checkobj(string((char*)((yyvsp[-3].typ)).type)) == 0){
    cout<<"Undeclared variable on line "<< yylineno<<"\n";
  }
  else
  {
    arrtype=curr_table->lookup(string((char*)((yyvsp[-3].typ)).type)).type;
    string s=arrtype;
    string yo="";
    int flag=1;
    for(int i=0;i<(int)s.size();i++)
    {
      if(s[i]=='['&&s[i+1]==']'&&i==(int)s.size()-2)
      {
        flag=0;
        break;
      }
      yo+=string(1,s[i]);
    }
    // cout<<"FFF"<<yo<<'\n';
    if(strcmp(((yyvsp[-1].typ)).type,"int"))
    {
      cout<<"Array index not integer and is "<<((yyvsp[-1].typ)).type<<" on line "<< yylineno<<"\n";
    }
    else
    {
        // cout<<"yooo "<<curr_table->lookup(string((char*)($1).type)).token.c_str()<<'\n';
      if(strcmp(curr_table->lookup(string((char*)((yyvsp[-3].typ)).type)).token.c_str(),"Array"))
      {
        cout<<"Can not access index of "<<curr_table->lookup(string((char*)((yyvsp[-3].typ)).type)).token.c_str() <<" on line "<< yylineno<<"\n";
      }
      arrtype=yo;
      if(flag)
      {
        arrtype="null";
      }
      strcpy(((yyval.typ)).type,arrtype.c_str());
      // cout<<"yoo"<<($$).type<<'\n';
    }
  }
  // yo="";
}
#line 7953 "parser.tab.c"
    break;

  case 323:
#line 4286 "parser.y"
                                                                   {
 strcpy(((yyval.typ)).tempvar, newtemp().c_str());
  string tp4;
  string tp5 = curr_table->lookup(string((char*)((yyvsp[-3].typ)).type)).type;
  for(auto it: tp5){
    if(it != '['){
      tp4.push_back(it);
    }
    else{
      break;
    }
  }
  string tp7 = newtemp();
  string tp8 = string((char*)((yyvsp[-1].typ)).tempvar)+ "*" + to_string(4);
  emit("=",tp8,"null",tp7,-1);
  string tp6 = "*(" + string((char*)((yyvsp[-3].typ)).tempvar) + "+" + tp7 + ")";
  emit("=",tp6,"null",string((char*)((yyval.typ)).tempvar),-1);
  arraccess=1;
  // if(curr_table->lookup(string((char*)($1).type)).offset == -1 && checkobj(string((char*)($1).type)) == 0){
  //   if(strcmp(curr_table->lookup(string((char*)($1).type)).type.c_str(),"null"))
  //   {
  //     cout<<"Undeclared variable on line "<< yylineno<<"\n";
  //   }
  // }
  // else
  // {
    // cout<<"SHU\n";
    string s=arrtype;
    string yo="";
    int flag=1;
    for(int i=0;i<(int)s.size();i++)
    {
      if(s[i]=='['&&s[i+1]==']'&&i==(int)s.size()-2)
      {
        flag=0;
        break;
      }
      yo+=string(1,s[i]);
    }
    // cout<<"hhh"<<yo<<'\n';
    if(strcmp(((yyvsp[-1].typ)).type,"int"))
    {
      cout<<"Array index not integer and is "<<((yyvsp[-1].typ)).type<<" on line "<< yylineno<<"\n";
    }
    else
    {
      arrtype=yo;
      if(flag)
      {
        arrtype="null";
        // cout<<"null\n";
      }
      strcpy(((yyval.typ)).type,arrtype.c_str());
      // cout<<"yoo"<<($$).type<<'\n';
    }
  // }
  yo="";
}
#line 8016 "parser.tab.c"
    break;

  case 324:
#line 4345 "parser.y"
        {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);

  ((yyval.typ)).ndim=((yyvsp[0].typ)).ndim;
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
}
#line 8027 "parser.tab.c"
    break;

  case 325:
#line 4351 "parser.y"
      {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);
  
  if(curr_table->lookup(string((char*)((yyvsp[0].typ)).type)).offset == -1 && checkobj(string((char*)((yyvsp[0].typ)).type)) == 0){
    if(!isaccess)
    {
      cout<<"Undeclared variable on line "<< yylineno<<"\n";
    }
  }
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
}
#line 8043 "parser.tab.c"
    break;

  case 326:
#line 4362 "parser.y"
                         {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);
  
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
}
#line 8053 "parser.tab.c"
    break;

  case 327:
#line 4367 "parser.y"
                         {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);

  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
  
}
#line 8064 "parser.tab.c"
    break;

  case 328:
#line 4374 "parser.y"
                           {
  // cout<<($1).type<<'\n';
  string tmp = newtemp();
  emit("=",((yyvsp[-1].typ)).tempvar,"null",tmp, -1);
  emit("+", tmp, "1", ((yyvsp[-1].typ)).tempvar, -1);
  strcpy(((yyval.typ)).tempvar, tmp.c_str());
  // cout<<"LHK"<<curr_table->lookup(string((char*)($1).type)).type<<'\n';
  string s;
  if(curr_table->lookup(string((char*)((yyvsp[-1].typ)).type)).offset!=-1)
  {
    s=curr_table->lookup(string((char*)((yyvsp[-1].typ)).type)).type;
  }
  else s=((yyvsp[-1].typ)).type;
  string yo="";
  int flag=0;
  for(int i=0;i<(int)s.size();i++)
  {
    if(s[i]=='[')
    {
      flag=1;
      break;
    }
    yo+=string(1,s[i]);
  }
  // cout<<"SHU"<<yo<<s<<'\n';
  if(invalidoperator(yo,0)&&!flag){
    cout<<"Invalid PostIncrementExpression Operator on line "<< yylineno<<"\n";
  }
  else strcpy(((yyval.typ)).type,((yyvsp[-1].typ)).type);
  yo="";

}
#line 8101 "parser.tab.c"
    break;

  case 329:
#line 4407 "parser.y"
                             {

  string tmp = newtemp();
  emit("=",((yyvsp[-1].typ)).tempvar,"null",tmp, -1);
  emit("-", tmp, "1", ((yyvsp[-1].typ)).tempvar, -1);
  strcpy(((yyval.typ)).tempvar, tmp.c_str());

  string s;
  if(curr_table->lookup(string((char*)((yyvsp[-1].typ)).type)).offset!=-1)
  {
    s=curr_table->lookup(string((char*)((yyvsp[-1].typ)).type)).type;
  }
  else s=((yyvsp[-1].typ)).type;
  string yo="";
  int flag=0;
  for(int i=0;i<(int)s.size();i++)
  {
    if(s[i]=='[')
    {
      flag=1;
      break;
    }
    yo+=string(1,s[i]);
  }
  // cout<<"SHU"<<yo<<s<<'\n';
  if(invalidoperator(yo,0)&&!flag){
    cout<<"Invalid PostDecrementExpression Operator on line "<< yylineno<<"\n";
  }
  else strcpy(((yyval.typ)).type,((yyvsp[-1].typ)).type);
  yo="";
  
}
#line 8138 "parser.tab.c"
    break;

  case 330:
#line 4440 "parser.y"
                       {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);

  ((yyval.typ)).ndim=((yyvsp[0].typ)).ndim;
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
}
#line 8149 "parser.tab.c"
    break;

  case 331:
#line 4446 "parser.y"
                        {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);
  
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
}
#line 8159 "parser.tab.c"
    break;

  case 332:
#line 4451 "parser.y"
                      {
  strcpy(((yyval.typ)).tempvar, newtemp().c_str());
  emit("plus",((yyvsp[0].typ)).tempvar,"null",((yyval.typ)).tempvar, -1); 
  
 cout<<string((char*)((yyvsp[0].typ)).type)<<endl;
 if(invalidoperator(string((char*)((yyvsp[0].typ)).type),0) || !strcmp(string((char*)((yyvsp[0].typ)).type).c_str() ,"boolean" )){
    cout<<"Invalid Operator on line "<< yylineno<<"\n";
  }
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
  
  
}
#line 8176 "parser.tab.c"
    break;

  case 333:
#line 4463 "parser.y"
                       {
strcpy(((yyval.typ)).tempvar, newtemp().c_str());  
  emit("minus",((yyvsp[0].typ)).tempvar,"null",((yyval.typ)).tempvar, -1); 
 if(invalidoperator(string((char*)((yyvsp[0].typ)).type),0) || !strcmp(string((char*)((yyvsp[0].typ)).type).c_str() ,"boolean" )){
    cout<<"Invalid Operator on line "<< yylineno<<"\n";
  }
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
  
}
#line 8190 "parser.tab.c"
    break;

  case 334:
#line 4472 "parser.y"
                             {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);

  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
  ((yyval.typ)).ndim=((yyvsp[0].typ)).ndim;
}
#line 8201 "parser.tab.c"
    break;

  case 335:
#line 4480 "parser.y"
                         {
  string tmp = newtemp();
  emit("+",((yyvsp[0].typ)).tempvar,"1",tmp, -1);
  emit("=", tmp, "null", ((yyvsp[0].typ)).tempvar, -1);
  strcpy(((yyval.typ)).tempvar, tmp.c_str());
  string s;
  if(curr_table->lookup(string((char*)((yyvsp[0].typ)).type)).offset!=-1)
  {
    s=curr_table->lookup(string((char*)((yyvsp[0].typ)).type)).type;
  }
  else s=((yyvsp[0].typ)).type;
  string yo="";
  int flag=0;
  for(int i=0;i<(int)s.size();i++)
  {
    if(s[i]=='[')
    {
      flag=1;
      break;
    }
    yo+=string(1,s[i]);
  }
  // cout<<"SHU"<<yo<<s<<'\n';
  if(invalidoperator(yo,0)&&!flag){
    cout<<"Invalid PreIncrementExpression Operator on line "<< yylineno<<"\n";
  }
  else strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
  
  
  yo="";
  
}
#line 8238 "parser.tab.c"
    break;

  case 336:
#line 4513 "parser.y"
                           {
  string tmp = newtemp();
  emit("-",((yyvsp[0].typ)).tempvar,"1",tmp, -1);
  emit("=", tmp, "null", ((yyvsp[0].typ)).tempvar, -1);
  strcpy(((yyval.typ)).tempvar, tmp.c_str());
    string s;
  if(curr_table->lookup(string((char*)((yyvsp[0].typ)).type)).offset!=-1)
  {
    s=curr_table->lookup(string((char*)((yyvsp[0].typ)).type)).type;
  }
  else s=((yyvsp[0].typ)).type;
  string yo="";
  int flag=0;
  for(int i=0;i<(int)s.size();i++)
  {
    if(s[i]=='[')
    {
      flag=1;
      break;
    }
    yo+=string(1,s[i]);
  }
  // cout<<"SHU"<<yo<<s<<'\n';
  if(invalidoperator(yo,0)&&!flag){
    cout<<"Invalid PreDecrementExpression Operator on line "<< yylineno<<"\n";
  }
  else strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
  
}
#line 8272 "parser.tab.c"
    break;

  case 337:
#line 4543 "parser.y"
                  {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
}
#line 8281 "parser.tab.c"
    break;

  case 338:
#line 4547 "parser.y"
                       {
  
  if(invalidoperator(curr_table->lookup(string((char*)((yyvsp[0].typ)).type)).type,1) || !strcmp(curr_table->lookup(string((char*)((yyvsp[0].typ)).type)).type.c_str() ,"boolean" )){
    cout<<"Invalid TILDA Operator on line "<< yylineno<<"\n";
  }
  string a=newtemp();
  emit("~",((yyvsp[0].typ)).tempvar,"null",a.c_str(), -1);
  strcpy(((yyval.typ)).tempvar, a.c_str());
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
  
  
}
#line 8298 "parser.tab.c"
    break;

  case 339:
#line 4559 "parser.y"
                     {
 
   if(strcmp(curr_table->lookup(string((char*)((yyvsp[0].typ)).type)).type.c_str() ,"boolean" )){
    cout<<"Invalid NOT Operator on line "<< yylineno<<"\n";
  }
  string a=newtemp();
  emit("!",((yyvsp[0].typ)).tempvar,"null",((yyval.typ)).tempvar, -1);
   strcpy(((yyval.typ)).tempvar, a.c_str());
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
  
  
}
#line 8315 "parser.tab.c"
    break;

  case 340:
#line 4571 "parser.y"
                {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
  
}
#line 8325 "parser.tab.c"
    break;

  case 341:
#line 4577 "parser.y"
                                                            {
  string casttp= "cast_to_" + string((char*)((yyvsp[-3].typ)).tempvar) + string((char*)((yyvsp[-2].typ)).tempvar);
  strcpy(((yyval.typ)).tempvar, newtemp().c_str());
  emit("=",casttp, ((yyvsp[0].typ)).tempvar, ((yyval.typ)).tempvar, -1);
  casttype=((yyvsp[-3].typ)).type;
  for(int i=0;i<((yyvsp[-2].typ)).ndim;i++)
  {
    casttype+="[]";
  }
  strcpy(((yyval.typ)).type,casttype.c_str());
  casttype="";
  if(curr_table->lookup(string((char*)((yyvsp[0].typ)).type)).offset == -1)
  {
    if(invalidoperator(((yyvsp[0].typ)).type,0))
    {
      cout<<"Invalid type cast on line from "<<((yyvsp[0].typ)).type<<" on line "<<yylineno<<'\n';
    }
  }
  else
  {
    if(invalidoperator(curr_table->lookup(string((char*)((yyvsp[0].typ)).type)).type,0))
    {
      cout<<"Invalid type cast on line from "<<curr_table->lookup(string((char*)((yyvsp[0].typ)).type)).type<<" on line "<<yylineno<<'\n';
    }
  }
}
#line 8356 "parser.tab.c"
    break;

  case 342:
#line 4603 "parser.y"
                                                        {
  string casttp= "cast_to_" + string((char*)((yyvsp[-2].typ)).tempvar);
  strcpy(((yyval.typ)).tempvar, newtemp().c_str());
  emit("=",casttp, ((yyvsp[0].typ)).tempvar, ((yyval.typ)).tempvar, -1);
  
  if(curr_table->lookup(string((char*)((yyvsp[0].typ)).type)).offset == -1)
  {
    if(invalidoperator(((yyvsp[0].typ)).type,0))
    {
      cout<<"Invalid type cast on line from "<<((yyvsp[0].typ)).type<<" on line "<<yylineno<<'\n';
    }
  }
  else
  {
    if(invalidoperator(curr_table->lookup(string((char*)((yyvsp[0].typ)).type)).type,0))
    {
      cout<<"Invalid type cast on line from "<<curr_table->lookup(string((char*)((yyvsp[0].typ)).type)).type<<" on line "<<yylineno<<'\n';
    }
  }
  strcpy(((yyval.typ)).type,((yyvsp[-2].typ)).type);
  
  
}
#line 8384 "parser.tab.c"
    break;

  case 343:
#line 4626 "parser.y"
                                                                 {
  string casttp= "cast_to_" + string((char*)((yyvsp[-2].typ)).tempvar);
  strcpy(((yyval.typ)).tempvar, newtemp().c_str());
  emit("=",casttp, ((yyvsp[0].typ)).tempvar, ((yyval.typ)).tempvar, -1);
  
   if(curr_table->lookup(string((char*)((yyvsp[0].typ)).type)).offset == -1)
  {
    if(invalidoperator(((yyvsp[0].typ)).type,0))
    {
      cout<<"Invalid type cast on line from "<<((yyvsp[0].typ)).type<<" on line "<<yylineno<<'\n';
    }
  }
  else
  {
    if(invalidoperator(curr_table->lookup(string((char*)((yyvsp[0].typ)).type)).type,0))
    {
      cout<<"Invalid type cast on line from "<<curr_table->lookup(string((char*)((yyvsp[0].typ)).type)).type<<" on line "<<yylineno<<'\n';
    }
  }
  strcpy(((yyval.typ)).type,((yyvsp[-2].typ)).type);
  
  
}
#line 8412 "parser.tab.c"
    break;

  case 344:
#line 4649 "parser.y"
                                                                {
  string casttp= "cast_to_" + string((char*)((yyvsp[-3].typ)).tempvar) + string((char*)((yyvsp[-2].typ)).tempvar);
  strcpy(((yyval.typ)).tempvar, newtemp().c_str());
  emit("=",casttp, ((yyvsp[0].typ)).tempvar, ((yyval.typ)).tempvar, -1);
  
  strcpy(((yyval.typ)).type,((yyvsp[-3].typ)).type);
  if(curr_table->lookup(string((char*)((yyvsp[-3].typ)).type)).offset == -1 && checkobj(string((char*)((yyvsp[-3].typ)).type)) == 0){
    cout<<"Undeclared variable on line "<< yylineno<<"\n";
  }
  casttype=((yyvsp[-3].typ)).type;
  for(int i=0;i<((yyvsp[-2].typ)).ndim;i++)
  {
    casttype+="[]";
  }
  strcpy(((yyval.typ)).type,casttype.c_str());
  casttype="";
   if(curr_table->lookup(string((char*)((yyvsp[0].typ)).type)).offset == -1)
  {
    if(invalidoperator(((yyvsp[0].typ)).type,0))
    {
      cout<<"Invalid type cast on line from "<<((yyvsp[0].typ)).type<<" on line "<<yylineno<<'\n';
    }
  }
  else
  {
    if(invalidoperator(curr_table->lookup(string((char*)((yyvsp[0].typ)).type)).type,0))
    {
      cout<<"Invalid type cast on line from "<<curr_table->lookup(string((char*)((yyvsp[0].typ)).type)).type<<" on line "<<yylineno<<'\n';
    }
  }
}
#line 8448 "parser.tab.c"
    break;

  case 345:
#line 4681 "parser.y"
                {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);
  ((yyval.typ)).ndim=((yyvsp[0].typ)).ndim;
  if(curr_table->lookup(string((char*)((yyvsp[0].typ)).type)).offset != -1)
  {
    strcpy(((yyval.typ)).type,curr_table->lookup(string((char*)((yyvsp[0].typ)).type)).type.c_str());
  }
  else
  {
    strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
  }
}
#line 8465 "parser.tab.c"
    break;

  case 346:
#line 4693 "parser.y"
                                               {

  // strcpy(($$).tempvar, newtemp().c_str());
  // emit("*",($1).tempvar,($3).tempvar,($$).tempvar, -1);


 if(curr_table->lookup(string((char*)((yyvsp[-2].typ)).type)).offset == -1&&curr_table->lookup(string((char*)((yyvsp[0].typ)).type)).offset == -1)
  {
    strcpy(((yyval.typ)).type,getorder(((yyvsp[-2].typ)).type,((yyvsp[0].typ)).type,1).c_str());
    if(strcmp(((yyvsp[-2].typ)).type,((yyvsp[0].typ)).type))
    {
    if(strcmp(getorder(((yyvsp[-2].typ)).type,((yyvsp[0].typ)).type,1).c_str(),((yyvsp[-2].typ)).type))//means 3 is bigger
    {
      //cout<<(getorder(($1).type,($3).type,1).c_str())<<" "<<($3).type<<'\n';
      string a=newtemp();
      string b=string("cast_to_")+string(((yyvsp[0].typ)).type);
      string c=string("*")+string(((yyvsp[0].typ)).type);
      emit("=",b.c_str(),((yyvsp[-2].typ)).tempvar,a.c_str(), -1);
      strcpy(((yyval.typ)).tempvar, newtemp().c_str());
      emit(c.c_str(),a.c_str(),((yyvsp[0].typ)).tempvar,((yyval.typ)).tempvar, -1);
    }
    else
    {
      string a=newtemp();
      string b=string("cast_to_")+string(((yyvsp[-2].typ)).type);
      string c=string("*")+string(((yyvsp[-2].typ)).type);
      emit("=",b.c_str(),((yyvsp[0].typ)).tempvar,a.c_str(), -1);
      strcpy(((yyval.typ)).tempvar, newtemp().c_str());
      emit(c.c_str(),((yyvsp[-2].typ)).tempvar,a.c_str(),((yyval.typ)).tempvar, -1);
    }
    }
    else{
      string c=string("*")+string(((yyvsp[-2].typ)).type);
      strcpy(((yyval.typ)).tempvar, newtemp().c_str());
      emit(c.c_str(),((yyvsp[-2].typ)).tempvar,((yyvsp[0].typ)).tempvar,((yyval.typ)).tempvar, -1);
    }
  }
  else if(curr_table->lookup(string((char*)((yyvsp[-2].typ)).type)).offset == -1&&curr_table->lookup(string((char*)((yyvsp[0].typ)).type)).offset != -1)
  {
    strcpy(((yyval.typ)).type,getorder(((yyvsp[-2].typ)).type,curr_table->lookup(string((char*)((yyvsp[0].typ)).type)).type.c_str(),1).c_str());
    if(strcmp(((yyvsp[-2].typ)).type,curr_table->lookup(string((char*)((yyvsp[0].typ)).type)).type.c_str()))
    {
    if(strcmp(getorder(((yyvsp[-2].typ)).type,curr_table->lookup(string((char*)((yyvsp[0].typ)).type)).type.c_str(),1).c_str(),((yyvsp[-2].typ)).type))//means 3 is bigger
    {
      //cout<<(getorder(($1).type,($3).type,1).c_str())<<" "<<($3).type<<'\n';
      string a=newtemp();
      string b=string("cast_to_")+string(curr_table->lookup(string((char*)((yyvsp[0].typ)).type)).type.c_str());
      // string c=string(curr_table->lookup(string((char*)($3).type)).type.c_str())+string(" ")+string(($3).tempvar);
      string c=string("*")+string(curr_table->lookup(string((char*)((yyvsp[0].typ)).type)).type.c_str());
      emit("=",b.c_str(),((yyvsp[-2].typ)).tempvar,a.c_str(), -1);
      strcpy(((yyval.typ)).tempvar, newtemp().c_str());
      // emit("*",a.c_str(),c.c_str(),($$).tempvar, -1);
      emit(c.c_str(),a.c_str(),((yyvsp[0].typ)).tempvar,((yyval.typ)).tempvar, -1);
    }
    else
    {
      string a=newtemp();
      string b=string("cast_to_")+string(((yyvsp[-2].typ)).type);
      // string c=string(($1).type)+string(" ")+string(($1).tempvar);
      string c=string("*")+string(((yyvsp[-2].typ)).type);
      emit("=",b.c_str(),((yyvsp[0].typ)).tempvar,a.c_str(), -1);
      strcpy(((yyval.typ)).tempvar, newtemp().c_str());
      // emit("*",c.c_str(),a.c_str(),($$).tempvar, -1);
      emit(c.c_str(),((yyvsp[-2].typ)).tempvar,a.c_str(),((yyval.typ)).tempvar, -1);
    }
    }
    else{
      string c=string("*")+string(((yyvsp[-2].typ)).type);
      strcpy(((yyval.typ)).tempvar, newtemp().c_str());
      emit(c.c_str(),((yyvsp[-2].typ)).tempvar,((yyvsp[0].typ)).tempvar,((yyval.typ)).tempvar, -1);
    }
  }
  else if(curr_table->lookup(string((char*)((yyvsp[0].typ)).type)).offset != -1&&curr_table->lookup(string((char*)((yyvsp[-2].typ)).type)).offset != -1)
  {
    strcpy(((yyval.typ)).type,getorder(curr_table->lookup(string((char*)((yyvsp[0].typ)).type)).type.c_str(),curr_table->lookup(string((char*)((yyvsp[-2].typ)).type)).type.c_str(),1).c_str());
    if(strcmp(curr_table->lookup(string((char*)((yyvsp[0].typ)).type)).type.c_str(),curr_table->lookup(string((char*)((yyvsp[-2].typ)).type)).type.c_str()))
    {
    if(strcmp(getorder(curr_table->lookup(string((char*)((yyvsp[0].typ)).type)).type.c_str(),curr_table->lookup(string((char*)((yyvsp[-2].typ)).type)).type.c_str(),1).c_str(),curr_table->lookup(string((char*)((yyvsp[-2].typ)).type)).type.c_str()))//means 3 is bigger
    {
      //cout<<(getorder(($1).type,($3).type,1).c_str())<<" "<<($3).type<<'\n';
      string a=newtemp();
      string b=string("cast_to_")+string(curr_table->lookup(string((char*)((yyvsp[0].typ)).type)).type.c_str());
      // string c=string(curr_table->lookup(string((char*)($3).type)).type.c_str())+string(" ")+string(($3).tempvar);
      string c=string("*")+string(curr_table->lookup(string((char*)((yyvsp[0].typ)).type)).type.c_str());
      emit("=",b.c_str(),((yyvsp[-2].typ)).tempvar,a.c_str(), -1);
      strcpy(((yyval.typ)).tempvar, newtemp().c_str());
      // emit("*",a.c_str(),c.c_str(),($$).tempvar, -1);
      emit(c.c_str(),a.c_str(),((yyvsp[0].typ)).tempvar,((yyval.typ)).tempvar, -1);
    }
    else
    {
      string a=newtemp();
      string b=string("cast_to_")+string(curr_table->lookup(string((char*)((yyvsp[-2].typ)).type)).type.c_str());
      // string c=string(curr_table->lookup(string((char*)($1).type)).type.c_str())+string(" ")+string(($1).tempvar);
      string c=string("*")+string(curr_table->lookup(string((char*)((yyvsp[-2].typ)).type)).type.c_str());
      emit("=",b.c_str(),((yyvsp[0].typ)).tempvar,a.c_str(), -1);
      strcpy(((yyval.typ)).tempvar, newtemp().c_str());
      // emit("*",c.c_str(),a.c_str(),($$).tempvar, -1);
      emit(c.c_str(),((yyvsp[-2].typ)).tempvar,a.c_str(),((yyval.typ)).tempvar, -1);
    }
  }
  else{
      string c=string("*")+string(((yyvsp[-2].typ)).type);
      strcpy(((yyval.typ)).tempvar, newtemp().c_str());
      emit(c.c_str(),((yyvsp[-2].typ)).tempvar,((yyvsp[0].typ)).tempvar,((yyval.typ)).tempvar, -1);
    }
  }
  else
  {
    strcpy(((yyval.typ)).type,getorder(((yyvsp[0].typ)).type,curr_table->lookup(string((char*)((yyvsp[-2].typ)).type)).type.c_str(),1).c_str());
    if(strcmp(((yyvsp[0].typ)).type,curr_table->lookup(string((char*)((yyvsp[-2].typ)).type)).type.c_str()))
    {
    if(strcmp(getorder(((yyvsp[0].typ)).type,curr_table->lookup(string((char*)((yyvsp[-2].typ)).type)).type.c_str(),1).c_str(),((yyvsp[0].typ)).type))//means 3 is bigger
    {
      //cout<<(getorder(($1).type,($3).type,1).c_str())<<" "<<($3).type<<'\n';
      string a=newtemp();
      string b=string("cast_to_")+string(curr_table->lookup(string((char*)((yyvsp[-2].typ)).type)).type.c_str());
      // string c=string(curr_table->lookup(string((char*)($1).type)).type.c_str())+string(" ")+string(($1).tempvar);
      string c=string("*")+string(curr_table->lookup(string((char*)((yyvsp[-2].typ)).type)).type.c_str());
      emit("=",b.c_str(),((yyvsp[0].typ)).tempvar,a.c_str(), -1);
      strcpy(((yyval.typ)).tempvar, newtemp().c_str());
      // emit("*",c.c_str(),a.c_str(),($$).tempvar, -1);
      emit(c.c_str(),((yyvsp[-2].typ)).tempvar,a.c_str(),((yyval.typ)).tempvar, -1);
    }
    else
    {
      string a=newtemp();
      string b=string("cast_to_")+string(((yyvsp[0].typ)).type);
      // string c=string(($3).type)+string(" ")+string(($3).tempvar);
      string c=string("*")+string(((yyvsp[0].typ)).type);
      emit("=",b.c_str(),((yyvsp[-2].typ)).tempvar,a.c_str(), -1);
      strcpy(((yyval.typ)).tempvar, newtemp().c_str());
      // emit("*",a.c_str(),c.c_str(),($$).tempvar, -1);
      emit(c.c_str(),a.c_str(),((yyvsp[0].typ)).tempvar,((yyval.typ)).tempvar, -1);
    }
    }
    else{
      string c=string("*")+string(((yyvsp[-2].typ)).type);
      strcpy(((yyval.typ)).tempvar, newtemp().c_str());
      emit(c.c_str(),((yyvsp[-2].typ)).tempvar,((yyvsp[0].typ)).tempvar,((yyval.typ)).tempvar, -1);
    }
  }

  
}
#line 8615 "parser.tab.c"
    break;

  case 347:
#line 4838 "parser.y"
                                                       {

  // strcpy(($$).tempvar, newtemp().c_str());
  // emit("/",($1).tempvar,($3).tempvar,($$).tempvar, -1);

//  strcpy(($$).type,getorder(($1).type,($3).type,1).c_str());
 if(curr_table->lookup(string((char*)((yyvsp[-2].typ)).type)).offset == -1&&curr_table->lookup(string((char*)((yyvsp[0].typ)).type)).offset == -1)
  {
    strcpy(((yyval.typ)).type,getorder(((yyvsp[-2].typ)).type,((yyvsp[0].typ)).type,1).c_str());
    if(strcmp(((yyvsp[-2].typ)).type,((yyvsp[0].typ)).type))
    {
    if(strcmp(getorder(((yyvsp[-2].typ)).type,((yyvsp[0].typ)).type,1).c_str(),((yyvsp[-2].typ)).type))//means 3 is bigger
    {
      //cout<<(getorder(($1).type,($3).type,1).c_str())<<" "<<($3).type<<'\n';
      string a=newtemp();
      string b=string("cast_to_")+string(((yyvsp[0].typ)).type);
      string c=string("/")+string(((yyvsp[0].typ)).type);
      emit("=",b.c_str(),((yyvsp[-2].typ)).tempvar,a.c_str(), -1);
      strcpy(((yyval.typ)).tempvar, newtemp().c_str());
      emit(c.c_str(),a.c_str(),((yyvsp[0].typ)).tempvar,((yyval.typ)).tempvar, -1);
    }
    else
    {
      string a=newtemp();
      string b=string("cast_to_")+string(((yyvsp[-2].typ)).type);
      string c=string("/")+string(((yyvsp[-2].typ)).type);
      emit("=",b.c_str(),((yyvsp[0].typ)).tempvar,a.c_str(), -1);
      strcpy(((yyval.typ)).tempvar, newtemp().c_str());
      emit(c.c_str(),((yyvsp[-2].typ)).tempvar,a.c_str(),((yyval.typ)).tempvar, -1);
    }
    }
    else{
      string c=string("/")+string(((yyvsp[-2].typ)).type);
      strcpy(((yyval.typ)).tempvar, newtemp().c_str());
      emit(c.c_str(),((yyvsp[-2].typ)).tempvar,((yyvsp[0].typ)).tempvar,((yyval.typ)).tempvar, -1);
    }
  }
  else if(curr_table->lookup(string((char*)((yyvsp[-2].typ)).type)).offset == -1&&curr_table->lookup(string((char*)((yyvsp[0].typ)).type)).offset != -1)
  {
    strcpy(((yyval.typ)).type,getorder(((yyvsp[-2].typ)).type,curr_table->lookup(string((char*)((yyvsp[0].typ)).type)).type.c_str(),1).c_str());
    if(strcmp(((yyvsp[-2].typ)).type,curr_table->lookup(string((char*)((yyvsp[0].typ)).type)).type.c_str()))
    {
    if(strcmp(getorder(((yyvsp[-2].typ)).type,curr_table->lookup(string((char*)((yyvsp[0].typ)).type)).type.c_str(),1).c_str(),((yyvsp[-2].typ)).type))//means 3 is bigger
    {
      //cout<<(getorder(($1).type,($3).type,1).c_str())<<" "<<($3).type<<'\n';
      string a=newtemp();
      string b=string("cast_to_")+string(curr_table->lookup(string((char*)((yyvsp[0].typ)).type)).type.c_str());
      // string c=string(curr_table->lookup(string((char*)($3).type)).type.c_str())+string(" ")+string(($3).tempvar);
      string c=string("/")+string(curr_table->lookup(string((char*)((yyvsp[0].typ)).type)).type.c_str());
      emit("=",b.c_str(),((yyvsp[-2].typ)).tempvar,a.c_str(), -1);
      strcpy(((yyval.typ)).tempvar, newtemp().c_str());
      // emit("*",a.c_str(),c.c_str(),($$).tempvar, -1);
      emit(c.c_str(),a.c_str(),((yyvsp[0].typ)).tempvar,((yyval.typ)).tempvar, -1);
    }
    else
    {
      string a=newtemp();
      string b=string("cast_to_")+string(((yyvsp[-2].typ)).type);
      // string c=string(($1).type)+string(" ")+string(($1).tempvar);
      string c=string("/")+string(((yyvsp[-2].typ)).type);
      emit("=",b.c_str(),((yyvsp[0].typ)).tempvar,a.c_str(), -1);
      strcpy(((yyval.typ)).tempvar, newtemp().c_str());
      // emit("*",c.c_str(),a.c_str(),($$).tempvar, -1);
      emit(c.c_str(),((yyvsp[-2].typ)).tempvar,a.c_str(),((yyval.typ)).tempvar, -1);
    }
    }
    else{
      string c=string("/")+string(((yyvsp[-2].typ)).type);
      strcpy(((yyval.typ)).tempvar, newtemp().c_str());
      emit(c.c_str(),((yyvsp[-2].typ)).tempvar,((yyvsp[0].typ)).tempvar,((yyval.typ)).tempvar, -1);
    }
  }
  else if(curr_table->lookup(string((char*)((yyvsp[0].typ)).type)).offset != -1&&curr_table->lookup(string((char*)((yyvsp[-2].typ)).type)).offset != -1)
  {
    strcpy(((yyval.typ)).type,getorder(curr_table->lookup(string((char*)((yyvsp[0].typ)).type)).type.c_str(),curr_table->lookup(string((char*)((yyvsp[-2].typ)).type)).type.c_str(),1).c_str());
    if(strcmp(curr_table->lookup(string((char*)((yyvsp[0].typ)).type)).type.c_str(),curr_table->lookup(string((char*)((yyvsp[-2].typ)).type)).type.c_str()))
    {
    if(strcmp(getorder(curr_table->lookup(string((char*)((yyvsp[0].typ)).type)).type.c_str(),curr_table->lookup(string((char*)((yyvsp[-2].typ)).type)).type.c_str(),1).c_str(),curr_table->lookup(string((char*)((yyvsp[-2].typ)).type)).type.c_str()))//means 3 is bigger
    {
      //cout<<(getorder(($1).type,($3).type,1).c_str())<<" "<<($3).type<<'\n';
      string a=newtemp();
      string b=string("cast_to_")+string(curr_table->lookup(string((char*)((yyvsp[0].typ)).type)).type.c_str());
      // string c=string(curr_table->lookup(string((char*)($3).type)).type.c_str())+string(" ")+string(($3).tempvar);
      string c=string("/")+string(curr_table->lookup(string((char*)((yyvsp[0].typ)).type)).type.c_str());
      emit("=",b.c_str(),((yyvsp[-2].typ)).tempvar,a.c_str(), -1);
      strcpy(((yyval.typ)).tempvar, newtemp().c_str());
      // emit("*",a.c_str(),c.c_str(),($$).tempvar, -1);
      emit(c.c_str(),a.c_str(),((yyvsp[0].typ)).tempvar,((yyval.typ)).tempvar, -1);
    }
    else
    {
      string a=newtemp();
      string b=string("cast_to_")+string(curr_table->lookup(string((char*)((yyvsp[-2].typ)).type)).type.c_str());
      // string c=string(curr_table->lookup(string((char*)($1).type)).type.c_str())+string(" ")+string(($1).tempvar);
      string c=string("/")+string(curr_table->lookup(string((char*)((yyvsp[-2].typ)).type)).type.c_str());
      emit("=",b.c_str(),((yyvsp[0].typ)).tempvar,a.c_str(), -1);
      strcpy(((yyval.typ)).tempvar, newtemp().c_str());
      // emit("*",c.c_str(),a.c_str(),($$).tempvar, -1);
      emit(c.c_str(),((yyvsp[-2].typ)).tempvar,a.c_str(),((yyval.typ)).tempvar, -1);
    }
    }
    else{
      string c=string("/")+string(((yyvsp[-2].typ)).type);
      strcpy(((yyval.typ)).tempvar, newtemp().c_str());
      emit(c.c_str(),((yyvsp[-2].typ)).tempvar,((yyvsp[0].typ)).tempvar,((yyval.typ)).tempvar, -1);
    }
  }
  else
  {
    strcpy(((yyval.typ)).type,getorder(((yyvsp[0].typ)).type,curr_table->lookup(string((char*)((yyvsp[-2].typ)).type)).type.c_str(),1).c_str());
    if(strcmp(((yyvsp[0].typ)).type,curr_table->lookup(string((char*)((yyvsp[-2].typ)).type)).type.c_str()))
    {
    if(strcmp(getorder(((yyvsp[0].typ)).type,curr_table->lookup(string((char*)((yyvsp[-2].typ)).type)).type.c_str(),1).c_str(),((yyvsp[0].typ)).type))//means 3 is bigger
    {
      //cout<<(getorder(($1).type,($3).type,1).c_str())<<" "<<($3).type<<'\n';
      string a=newtemp();
      string b=string("cast_to_")+string(curr_table->lookup(string((char*)((yyvsp[-2].typ)).type)).type.c_str());
      // string c=string(curr_table->lookup(string((char*)($1).type)).type.c_str())+string(" ")+string(($1).tempvar);
      string c=string("/")+string(curr_table->lookup(string((char*)((yyvsp[-2].typ)).type)).type.c_str());
      emit("=",b.c_str(),((yyvsp[0].typ)).tempvar,a.c_str(), -1);
      strcpy(((yyval.typ)).tempvar, newtemp().c_str());
      // emit("*",c.c_str(),a.c_str(),($$).tempvar, -1);
      emit(c.c_str(),((yyvsp[-2].typ)).tempvar,a.c_str(),((yyval.typ)).tempvar, -1);
    }
    else
    {
      string a=newtemp();
      string b=string("cast_to_")+string(((yyvsp[0].typ)).type);
      // string c=string(($3).type)+string(" ")+string(($3).tempvar);
      string c=string("/")+string(((yyvsp[0].typ)).type);
      emit("=",b.c_str(),((yyvsp[-2].typ)).tempvar,a.c_str(), -1);
      strcpy(((yyval.typ)).tempvar, newtemp().c_str());
      // emit("*",a.c_str(),c.c_str(),($$).tempvar, -1);
      emit(c.c_str(),a.c_str(),((yyvsp[0].typ)).tempvar,((yyval.typ)).tempvar, -1);
    }
    }
    else{
      string c=string("/")+string(((yyvsp[-2].typ)).type);
      strcpy(((yyval.typ)).tempvar, newtemp().c_str());
      emit(c.c_str(),((yyvsp[-2].typ)).tempvar,((yyvsp[0].typ)).tempvar,((yyval.typ)).tempvar, -1);
    }
}
}
#line 8763 "parser.tab.c"
    break;

  case 348:
#line 4981 "parser.y"
                                                 {
//   strcpy(($$).tempvar, newtemp().c_str());
//   emit("%",($1).tempvar,($3).tempvar,($$).tempvar, -1);

//  strcpy(($$).type,getorder(($1).type,($3).type,0).c_str());
if(curr_table->lookup(string((char*)((yyvsp[-2].typ)).type)).offset == -1&&curr_table->lookup(string((char*)((yyvsp[0].typ)).type)).offset == -1)
  {
    strcpy(((yyval.typ)).type,getorder(((yyvsp[-2].typ)).type,((yyvsp[0].typ)).type,1).c_str());
    if(strcmp(((yyvsp[-2].typ)).type,((yyvsp[0].typ)).type))
    {
    if(strcmp(getorder(((yyvsp[-2].typ)).type,((yyvsp[0].typ)).type,1).c_str(),((yyvsp[-2].typ)).type))//means 3 is bigger
    {
      //cout<<(getorder(($1).type,($3).type,1).c_str())<<" "<<($3).type<<'\n';
      string a=newtemp();
      string b=string("cast_to_")+string(((yyvsp[0].typ)).type);
      string c=string("%")+string(((yyvsp[0].typ)).type);
      emit("=",b.c_str(),((yyvsp[-2].typ)).tempvar,a.c_str(), -1);
      strcpy(((yyval.typ)).tempvar, newtemp().c_str());
      emit(c.c_str(),a.c_str(),((yyvsp[0].typ)).tempvar,((yyval.typ)).tempvar, -1);
    }
    else
    {
      string a=newtemp();
      string b=string("cast_to_")+string(((yyvsp[-2].typ)).type);
      string c=string("%")+string(((yyvsp[-2].typ)).type);
      emit("=",b.c_str(),((yyvsp[0].typ)).tempvar,a.c_str(), -1);
      strcpy(((yyval.typ)).tempvar, newtemp().c_str());
      emit(c.c_str(),((yyvsp[-2].typ)).tempvar,a.c_str(),((yyval.typ)).tempvar, -1);
    }
    }
    else{
      string c=string("%")+string(((yyvsp[-2].typ)).type);
      strcpy(((yyval.typ)).tempvar, newtemp().c_str());
      emit(c.c_str(),((yyvsp[-2].typ)).tempvar,((yyvsp[0].typ)).tempvar,((yyval.typ)).tempvar, -1);
    }
  }
  else if(curr_table->lookup(string((char*)((yyvsp[-2].typ)).type)).offset == -1&&curr_table->lookup(string((char*)((yyvsp[0].typ)).type)).offset != -1)
  {
    strcpy(((yyval.typ)).type,getorder(((yyvsp[-2].typ)).type,curr_table->lookup(string((char*)((yyvsp[0].typ)).type)).type.c_str(),1).c_str());
    if(strcmp(((yyvsp[-2].typ)).type,curr_table->lookup(string((char*)((yyvsp[0].typ)).type)).type.c_str()))
    {
    if(strcmp(getorder(((yyvsp[-2].typ)).type,curr_table->lookup(string((char*)((yyvsp[0].typ)).type)).type.c_str(),1).c_str(),((yyvsp[-2].typ)).type))//means 3 is bigger
    {
      //cout<<(getorder(($1).type,($3).type,1).c_str())<<" "<<($3).type<<'\n';
      string a=newtemp();
      string b=string("cast_to_")+string(curr_table->lookup(string((char*)((yyvsp[0].typ)).type)).type.c_str());
      // string c=string(curr_table->lookup(string((char*)($3).type)).type.c_str())+string(" ")+string(($3).tempvar);
      string c=string("%")+string(curr_table->lookup(string((char*)((yyvsp[0].typ)).type)).type.c_str());
      emit("=",b.c_str(),((yyvsp[-2].typ)).tempvar,a.c_str(), -1);
      strcpy(((yyval.typ)).tempvar, newtemp().c_str());
      // emit("*",a.c_str(),c.c_str(),($$).tempvar, -1);
      emit(c.c_str(),a.c_str(),((yyvsp[0].typ)).tempvar,((yyval.typ)).tempvar, -1);
    }
    else
    {
      string a=newtemp();
      string b=string("cast_to_")+string(((yyvsp[-2].typ)).type);
      // string c=string(($1).type)+string(" ")+string(($1).tempvar);
      string c=string("%")+string(((yyvsp[-2].typ)).type);
      emit("=",b.c_str(),((yyvsp[0].typ)).tempvar,a.c_str(), -1);
      strcpy(((yyval.typ)).tempvar, newtemp().c_str());
      // emit("*",c.c_str(),a.c_str(),($$).tempvar, -1);
      emit(c.c_str(),((yyvsp[-2].typ)).tempvar,a.c_str(),((yyval.typ)).tempvar, -1);
    }
    }
    else{
      string c=string("%")+string(((yyvsp[-2].typ)).type);
      strcpy(((yyval.typ)).tempvar, newtemp().c_str());
      emit(c.c_str(),((yyvsp[-2].typ)).tempvar,((yyvsp[0].typ)).tempvar,((yyval.typ)).tempvar, -1);
    }
  }
  else if(curr_table->lookup(string((char*)((yyvsp[0].typ)).type)).offset != -1&&curr_table->lookup(string((char*)((yyvsp[-2].typ)).type)).offset != -1)
  {
    strcpy(((yyval.typ)).type,getorder(curr_table->lookup(string((char*)((yyvsp[0].typ)).type)).type.c_str(),curr_table->lookup(string((char*)((yyvsp[-2].typ)).type)).type.c_str(),1).c_str());
    if(strcmp(curr_table->lookup(string((char*)((yyvsp[0].typ)).type)).type.c_str(),curr_table->lookup(string((char*)((yyvsp[-2].typ)).type)).type.c_str()))
    {
    if(strcmp(getorder(curr_table->lookup(string((char*)((yyvsp[0].typ)).type)).type.c_str(),curr_table->lookup(string((char*)((yyvsp[-2].typ)).type)).type.c_str(),1).c_str(),curr_table->lookup(string((char*)((yyvsp[-2].typ)).type)).type.c_str()))//means 3 is bigger
    {
      //cout<<(getorder(($1).type,($3).type,1).c_str())<<" "<<($3).type<<'\n';
      string a=newtemp();
      string b=string("cast_to_")+string(curr_table->lookup(string((char*)((yyvsp[0].typ)).type)).type.c_str());
      // string c=string(curr_table->lookup(string((char*)($3).type)).type.c_str())+string(" ")+string(($3).tempvar);
      string c=string("%")+string(curr_table->lookup(string((char*)((yyvsp[0].typ)).type)).type.c_str());
      emit("=",b.c_str(),((yyvsp[-2].typ)).tempvar,a.c_str(), -1);
      strcpy(((yyval.typ)).tempvar, newtemp().c_str());
      // emit("*",a.c_str(),c.c_str(),($$).tempvar, -1);
      emit(c.c_str(),a.c_str(),((yyvsp[0].typ)).tempvar,((yyval.typ)).tempvar, -1);
    }
    else
    {
      string a=newtemp();
      string b=string("cast_to_")+string(curr_table->lookup(string((char*)((yyvsp[-2].typ)).type)).type.c_str());
      // string c=string(curr_table->lookup(string((char*)($1).type)).type.c_str())+string(" ")+string(($1).tempvar);
      string c=string("%")+string(curr_table->lookup(string((char*)((yyvsp[-2].typ)).type)).type.c_str());
      emit("=",b.c_str(),((yyvsp[0].typ)).tempvar,a.c_str(), -1);
      strcpy(((yyval.typ)).tempvar, newtemp().c_str());
      // emit("*",c.c_str(),a.c_str(),($$).tempvar, -1);
      emit(c.c_str(),((yyvsp[-2].typ)).tempvar,a.c_str(),((yyval.typ)).tempvar, -1);
    }
    }
    else{
      string c=string("%")+string(((yyvsp[-2].typ)).type);
      strcpy(((yyval.typ)).tempvar, newtemp().c_str());
      emit(c.c_str(),((yyvsp[-2].typ)).tempvar,((yyvsp[0].typ)).tempvar,((yyval.typ)).tempvar, -1);
    }
  }
  else
  {
    strcpy(((yyval.typ)).type,getorder(((yyvsp[0].typ)).type,curr_table->lookup(string((char*)((yyvsp[-2].typ)).type)).type.c_str(),1).c_str());
    if(strcmp(((yyvsp[0].typ)).type,curr_table->lookup(string((char*)((yyvsp[-2].typ)).type)).type.c_str()))
    {
    if(strcmp(getorder(((yyvsp[0].typ)).type,curr_table->lookup(string((char*)((yyvsp[-2].typ)).type)).type.c_str(),1).c_str(),((yyvsp[0].typ)).type))//means 3 is bigger
    {
      //cout<<(getorder(($1).type,($3).type,1).c_str())<<" "<<($3).type<<'\n';
      string a=newtemp();
      string b=string("cast_to_")+string(curr_table->lookup(string((char*)((yyvsp[-2].typ)).type)).type.c_str());
      // string c=string(curr_table->lookup(string((char*)($1).type)).type.c_str())+string(" ")+string(($1).tempvar);
      string c=string("%")+string(curr_table->lookup(string((char*)((yyvsp[-2].typ)).type)).type.c_str());
      emit("=",b.c_str(),((yyvsp[0].typ)).tempvar,a.c_str(), -1);
      strcpy(((yyval.typ)).tempvar, newtemp().c_str());
      // emit("*",c.c_str(),a.c_str(),($$).tempvar, -1);
      emit(c.c_str(),((yyvsp[-2].typ)).tempvar,a.c_str(),((yyval.typ)).tempvar, -1);
    }
    else
    {
      string a=newtemp();
      string b=string("cast_to_")+string(((yyvsp[0].typ)).type);
      // string c=string(($3).type)+string(" ")+string(($3).tempvar);
      string c=string("%")+string(((yyvsp[0].typ)).type);
      emit("=",b.c_str(),((yyvsp[-2].typ)).tempvar,a.c_str(), -1);
      strcpy(((yyval.typ)).tempvar, newtemp().c_str());
      // emit("*",a.c_str(),c.c_str(),($$).tempvar, -1);
      emit(c.c_str(),a.c_str(),((yyvsp[0].typ)).tempvar,((yyval.typ)).tempvar, -1);
    }
    }
    else{
      string c=string("%")+string(((yyvsp[-2].typ)).type);
      strcpy(((yyval.typ)).tempvar, newtemp().c_str());
      emit(c.c_str(),((yyvsp[-2].typ)).tempvar,((yyvsp[0].typ)).tempvar,((yyval.typ)).tempvar, -1);
    }
}
}
#line 8910 "parser.tab.c"
    break;

  case 349:
#line 5124 "parser.y"
                         {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);

  ((yyval.typ)).ndim=((yyvsp[0].typ)).ndim;
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
}
#line 8921 "parser.tab.c"
    break;

  case 350:
#line 5130 "parser.y"
                                                  {
  // strcpy(($$).tempvar, newtemp().c_str());
  // emit("+",($1).tempvar,($3).tempvar,($$).tempvar, -1);
  

 if(curr_table->lookup(string((char*)((yyvsp[-2].typ)).type)).offset == -1&&curr_table->lookup(string((char*)((yyvsp[0].typ)).type)).offset == -1)
  {
    strcpy(((yyval.typ)).type,getorder(((yyvsp[-2].typ)).type,((yyvsp[0].typ)).type,1).c_str());
    if(strcmp(((yyvsp[-2].typ)).type,((yyvsp[0].typ)).type))
    {
    if(strcmp(getorder(((yyvsp[-2].typ)).type,((yyvsp[0].typ)).type,1).c_str(),((yyvsp[-2].typ)).type))//means 3 is bigger
    {
      //cout<<(getorder(($1).type,($3).type,1).c_str())<<" "<<($3).type<<'\n';
      string a=newtemp();
      string b=string("cast_to_")+string(((yyvsp[0].typ)).type);
      string c=string("+")+string(((yyvsp[0].typ)).type);
      emit("=",b.c_str(),((yyvsp[-2].typ)).tempvar,a.c_str(), -1);
      strcpy(((yyval.typ)).tempvar, newtemp().c_str());
      emit(c.c_str(),a.c_str(),((yyvsp[0].typ)).tempvar,((yyval.typ)).tempvar, -1);
    }
    else
    {
      string a=newtemp();
      string b=string("cast_to_")+string(((yyvsp[-2].typ)).type);
      string c=string("+")+string(((yyvsp[-2].typ)).type);
      emit("=",b.c_str(),((yyvsp[0].typ)).tempvar,a.c_str(), -1);
      strcpy(((yyval.typ)).tempvar, newtemp().c_str());
      emit(c.c_str(),((yyvsp[-2].typ)).tempvar,a.c_str(),((yyval.typ)).tempvar, -1);
    }
    }
    else{
      string c=string("+")+string(((yyvsp[-2].typ)).type);
      strcpy(((yyval.typ)).tempvar, newtemp().c_str());
      emit(c.c_str(),((yyvsp[-2].typ)).tempvar,((yyvsp[0].typ)).tempvar,((yyval.typ)).tempvar, -1);
    }
  }
  else if(curr_table->lookup(string((char*)((yyvsp[-2].typ)).type)).offset == -1&&curr_table->lookup(string((char*)((yyvsp[0].typ)).type)).offset != -1)
  {
     
    strcpy(((yyval.typ)).type,getorder(((yyvsp[-2].typ)).type,curr_table->lookup(string((char*)((yyvsp[0].typ)).type)).type.c_str(),1).c_str());
    if(strcmp(((yyvsp[-2].typ)).type,curr_table->lookup(string((char*)((yyvsp[0].typ)).type)).type.c_str()))
    {
    if(strcmp(getorder(((yyvsp[-2].typ)).type,curr_table->lookup(string((char*)((yyvsp[0].typ)).type)).type.c_str(),1).c_str(),((yyvsp[-2].typ)).type))//means 3 is bigger
    {
      //cout<<(getorder(($1).type,($3).type,1).c_str())<<" "<<($3).type<<'\n';
      string a=newtemp();
      string b=string("cast_to_")+string(curr_table->lookup(string((char*)((yyvsp[0].typ)).type)).type.c_str());
      // string c=string(curr_table->lookup(string((char*)($3).type)).type.c_str())+string(" ")+string(($3).tempvar);
      string c=string("+")+string(curr_table->lookup(string((char*)((yyvsp[0].typ)).type)).type.c_str());
      emit("=",b.c_str(),((yyvsp[-2].typ)).tempvar,a.c_str(), -1);
      strcpy(((yyval.typ)).tempvar, newtemp().c_str());
      // emit("*",a.c_str(),c.c_str(),($$).tempvar, -1);
      emit(c.c_str(),a.c_str(),((yyvsp[0].typ)).tempvar,((yyval.typ)).tempvar, -1);
    }
    else
    {
      string a=newtemp();
      string b=string("cast_to_")+string(((yyvsp[-2].typ)).type);
      // string c=string(($1).type)+string(" ")+string(($1).tempvar);
      string c=string("+")+string(((yyvsp[-2].typ)).type);
      emit("=",b.c_str(),((yyvsp[0].typ)).tempvar,a.c_str(), -1);
      strcpy(((yyval.typ)).tempvar, newtemp().c_str());
      // emit("*",c.c_str(),a.c_str(),($$).tempvar, -1);
      emit(c.c_str(),((yyvsp[-2].typ)).tempvar,a.c_str(),((yyval.typ)).tempvar, -1);
    }
    }
    else{
      string c=string("+")+string(((yyvsp[-2].typ)).type);
      strcpy(((yyval.typ)).tempvar, newtemp().c_str());
      emit(c.c_str(),((yyvsp[-2].typ)).tempvar,((yyvsp[0].typ)).tempvar,((yyval.typ)).tempvar, -1);
    }
  }
  else if(curr_table->lookup(string((char*)((yyvsp[0].typ)).type)).offset != -1&&curr_table->lookup(string((char*)((yyvsp[-2].typ)).type)).offset != -1)
  {
    
    strcpy(((yyval.typ)).type,getorder(curr_table->lookup(string((char*)((yyvsp[0].typ)).type)).type.c_str(),curr_table->lookup(string((char*)((yyvsp[-2].typ)).type)).type.c_str(),1).c_str());
    if(strcmp(curr_table->lookup(string((char*)((yyvsp[0].typ)).type)).type.c_str(),curr_table->lookup(string((char*)((yyvsp[-2].typ)).type)).type.c_str()))
    {
    if(strcmp(getorder(curr_table->lookup(string((char*)((yyvsp[0].typ)).type)).type.c_str(),curr_table->lookup(string((char*)((yyvsp[-2].typ)).type)).type.c_str(),1).c_str(),curr_table->lookup(string((char*)((yyvsp[-2].typ)).type)).type.c_str()))//means 3 is bigger
    {
      //cout<<(getorder(($1).type,($3).type,1).c_str())<<" "<<($3).type<<'\n';
      string a=newtemp();
      string b=string("cast_to_")+string(curr_table->lookup(string((char*)((yyvsp[0].typ)).type)).type.c_str());
      // string c=string(curr_table->lookup(string((char*)($3).type)).type.c_str())+string(" ")+string(($3).tempvar);
      string c=string("+")+string(curr_table->lookup(string((char*)((yyvsp[0].typ)).type)).type.c_str());
      emit("=",b.c_str(),((yyvsp[-2].typ)).tempvar,a.c_str(), -1);
      strcpy(((yyval.typ)).tempvar, newtemp().c_str());
      // emit("*",a.c_str(),c.c_str(),($$).tempvar, -1);
      emit(c.c_str(),a.c_str(),((yyvsp[0].typ)).tempvar,((yyval.typ)).tempvar, -1);
    }
    else
    {
      string a=newtemp();
      string b=string("cast_to_")+string(curr_table->lookup(string((char*)((yyvsp[-2].typ)).type)).type.c_str());
      // string c=string(curr_table->lookup(string((char*)($1).type)).type.c_str())+string(" ")+string(($1).tempvar);
      string c=string("+")+string(curr_table->lookup(string((char*)((yyvsp[-2].typ)).type)).type.c_str());
      emit("=",b.c_str(),((yyvsp[0].typ)).tempvar,a.c_str(), -1);
      strcpy(((yyval.typ)).tempvar, newtemp().c_str());
      // emit("*",c.c_str(),a.c_str(),($$).tempvar, -1);
      emit(c.c_str(),((yyvsp[-2].typ)).tempvar,a.c_str(),((yyval.typ)).tempvar, -1);
    }
    }
    else{
      string c=string("+")+string(((yyvsp[-2].typ)).type);
      strcpy(((yyval.typ)).tempvar, newtemp().c_str());
      emit(c.c_str(),((yyvsp[-2].typ)).tempvar,((yyvsp[0].typ)).tempvar,((yyval.typ)).tempvar, -1);
    }
  }
  else
  {
    strcpy(((yyval.typ)).type,getorder(((yyvsp[0].typ)).type,curr_table->lookup(string((char*)((yyvsp[-2].typ)).type)).type.c_str(),1).c_str());
    if(strcmp(((yyvsp[0].typ)).type,curr_table->lookup(string((char*)((yyvsp[-2].typ)).type)).type.c_str()))
    {
    if(strcmp(getorder(((yyvsp[0].typ)).type,curr_table->lookup(string((char*)((yyvsp[-2].typ)).type)).type.c_str(),1).c_str(),((yyvsp[0].typ)).type))//means 3 is bigger
    {
      //cout<<(getorder(($1).type,($3).type,1).c_str())<<" "<<($3).type<<'\n';
      string a=newtemp();
      string b=string("cast_to_")+string(curr_table->lookup(string((char*)((yyvsp[-2].typ)).type)).type.c_str());
      // string c=string(curr_table->lookup(string((char*)($1).type)).type.c_str())+string(" ")+string(($1).tempvar);
      string c=string("+")+string(curr_table->lookup(string((char*)((yyvsp[-2].typ)).type)).type.c_str());
      emit("=",b.c_str(),((yyvsp[0].typ)).tempvar,a.c_str(), -1);
      strcpy(((yyval.typ)).tempvar, newtemp().c_str());
      // emit("*",c.c_str(),a.c_str(),($$).tempvar, -1);
      emit(c.c_str(),((yyvsp[-2].typ)).tempvar,a.c_str(),((yyval.typ)).tempvar, -1);
    }
    else
    {
      string a=newtemp();
      string b=string("cast_to_")+string(((yyvsp[0].typ)).type);
      // string c=string(($3).type)+string(" ")+string(($3).tempvar);
      string c=string("+")+string(((yyvsp[0].typ)).type);
      emit("=",b.c_str(),((yyvsp[-2].typ)).tempvar,a.c_str(), -1);
      strcpy(((yyval.typ)).tempvar, newtemp().c_str());
      // emit("*",a.c_str(),c.c_str(),($$).tempvar, -1);
      emit(c.c_str(),a.c_str(),((yyvsp[0].typ)).tempvar,((yyval.typ)).tempvar, -1);
    }
    }
    else{
      string c=string("+")+string(((yyvsp[-2].typ)).type);
      strcpy(((yyval.typ)).tempvar, newtemp().c_str());
      emit(c.c_str(),((yyvsp[-2].typ)).tempvar,((yyvsp[0].typ)).tempvar,((yyval.typ)).tempvar, -1);
    }
}
}
#line 9070 "parser.tab.c"
    break;

  case 351:
#line 5274 "parser.y"
                                                   {

  // strcpy(($$).tempvar, newtemp().c_str());
  // emit("-",($1).tempvar,($3).tempvar,($$).tempvar, -1);
  
if(curr_table->lookup(string((char*)((yyvsp[-2].typ)).type)).offset == -1&&curr_table->lookup(string((char*)((yyvsp[0].typ)).type)).offset == -1)
  {
    strcpy(((yyval.typ)).type,getorder(((yyvsp[-2].typ)).type,((yyvsp[0].typ)).type,1).c_str());
    if(strcmp(((yyvsp[-2].typ)).type,((yyvsp[0].typ)).type))
    {
    if(strcmp(getorder(((yyvsp[-2].typ)).type,((yyvsp[0].typ)).type,1).c_str(),((yyvsp[-2].typ)).type))//means 3 is bigger
    {
      //cout<<(getorder(($1).type,($3).type,1).c_str())<<" "<<($3).type<<'\n';
      string a=newtemp();
      string b=string("cast_to_")+string(((yyvsp[0].typ)).type);
      string c=string("-")+string(((yyvsp[0].typ)).type);
      emit("=",b.c_str(),((yyvsp[-2].typ)).tempvar,a.c_str(), -1);
      strcpy(((yyval.typ)).tempvar, newtemp().c_str());
      emit(c.c_str(),a.c_str(),((yyvsp[0].typ)).tempvar,((yyval.typ)).tempvar, -1);
    }
    else
    {
      string a=newtemp();
      string b=string("cast_to_")+string(((yyvsp[-2].typ)).type);
      string c=string("-")+string(((yyvsp[-2].typ)).type);
      emit("=",b.c_str(),((yyvsp[0].typ)).tempvar,a.c_str(), -1);
      strcpy(((yyval.typ)).tempvar, newtemp().c_str());
      emit(c.c_str(),((yyvsp[-2].typ)).tempvar,a.c_str(),((yyval.typ)).tempvar, -1);
    }
    }
    else{
      string c=string("-")+string(((yyvsp[-2].typ)).type);
      strcpy(((yyval.typ)).tempvar, newtemp().c_str());
      emit(c.c_str(),((yyvsp[-2].typ)).tempvar,((yyvsp[0].typ)).tempvar,((yyval.typ)).tempvar, -1);
    }
  }
  else if(curr_table->lookup(string((char*)((yyvsp[-2].typ)).type)).offset == -1&&curr_table->lookup(string((char*)((yyvsp[0].typ)).type)).offset != -1)
  {
    strcpy(((yyval.typ)).type,getorder(((yyvsp[-2].typ)).type,curr_table->lookup(string((char*)((yyvsp[0].typ)).type)).type.c_str(),1).c_str());
    if(strcmp(((yyvsp[-2].typ)).type,curr_table->lookup(string((char*)((yyvsp[0].typ)).type)).type.c_str()))
    {
    if(strcmp(getorder(((yyvsp[-2].typ)).type,curr_table->lookup(string((char*)((yyvsp[0].typ)).type)).type.c_str(),1).c_str(),((yyvsp[-2].typ)).type))//means 3 is bigger
    {
      //cout<<(getorder(($1).type,($3).type,1).c_str())<<" "<<($3).type<<'\n';
      string a=newtemp();
      string b=string("cast_to_")+string(curr_table->lookup(string((char*)((yyvsp[0].typ)).type)).type.c_str());
      // string c=string(curr_table->lookup(string((char*)($3).type)).type.c_str())+string(" ")+string(($3).tempvar);
      string c=string("-")+string(curr_table->lookup(string((char*)((yyvsp[0].typ)).type)).type.c_str());
      emit("=",b.c_str(),((yyvsp[-2].typ)).tempvar,a.c_str(), -1);
      strcpy(((yyval.typ)).tempvar, newtemp().c_str());
      // emit("*",a.c_str(),c.c_str(),($$).tempvar, -1);
      emit(c.c_str(),a.c_str(),((yyvsp[0].typ)).tempvar,((yyval.typ)).tempvar, -1);
    }
    else
    {
      string a=newtemp();
      string b=string("cast_to_")+string(((yyvsp[-2].typ)).type);
      // string c=string(($1).type)+string(" ")+string(($1).tempvar);
      string c=string("-")+string(((yyvsp[-2].typ)).type);
      emit("=",b.c_str(),((yyvsp[0].typ)).tempvar,a.c_str(), -1);
      strcpy(((yyval.typ)).tempvar, newtemp().c_str());
      // emit("*",c.c_str(),a.c_str(),($$).tempvar, -1);
      emit(c.c_str(),((yyvsp[-2].typ)).tempvar,a.c_str(),((yyval.typ)).tempvar, -1);
    }
    }
    else{
      string c=string("-")+string(((yyvsp[-2].typ)).type);
      strcpy(((yyval.typ)).tempvar, newtemp().c_str());
      emit(c.c_str(),((yyvsp[-2].typ)).tempvar,((yyvsp[0].typ)).tempvar,((yyval.typ)).tempvar, -1);
    }
  }
  else if(curr_table->lookup(string((char*)((yyvsp[0].typ)).type)).offset != -1&&curr_table->lookup(string((char*)((yyvsp[-2].typ)).type)).offset != -1)
  {
    strcpy(((yyval.typ)).type,getorder(curr_table->lookup(string((char*)((yyvsp[0].typ)).type)).type.c_str(),curr_table->lookup(string((char*)((yyvsp[-2].typ)).type)).type.c_str(),1).c_str());
    if(strcmp(curr_table->lookup(string((char*)((yyvsp[0].typ)).type)).type.c_str(),curr_table->lookup(string((char*)((yyvsp[-2].typ)).type)).type.c_str()))
    {
    if(strcmp(getorder(curr_table->lookup(string((char*)((yyvsp[0].typ)).type)).type.c_str(),curr_table->lookup(string((char*)((yyvsp[-2].typ)).type)).type.c_str(),1).c_str(),curr_table->lookup(string((char*)((yyvsp[-2].typ)).type)).type.c_str()))//means 3 is bigger
    {
      //cout<<(getorder(($1).type,($3).type,1).c_str())<<" "<<($3).type<<'\n';
      string a=newtemp();
      string b=string("cast_to_")+string(curr_table->lookup(string((char*)((yyvsp[0].typ)).type)).type.c_str());
      // string c=string(curr_table->lookup(string((char*)($3).type)).type.c_str())+string(" ")+string(($3).tempvar);
      string c=string("-")+string(curr_table->lookup(string((char*)((yyvsp[0].typ)).type)).type.c_str());
      emit("=",b.c_str(),((yyvsp[-2].typ)).tempvar,a.c_str(), -1);
      strcpy(((yyval.typ)).tempvar, newtemp().c_str());
      // emit("*",a.c_str(),c.c_str(),($$).tempvar, -1);
      emit(c.c_str(),a.c_str(),((yyvsp[0].typ)).tempvar,((yyval.typ)).tempvar, -1);
    }
    else
    {
      string a=newtemp();
      string b=string("cast_to_")+string(curr_table->lookup(string((char*)((yyvsp[-2].typ)).type)).type.c_str());
      // string c=string(curr_table->lookup(string((char*)($1).type)).type.c_str())+string(" ")+string(($1).tempvar);
      string c=string("-")+string(curr_table->lookup(string((char*)((yyvsp[-2].typ)).type)).type.c_str());
      emit("=",b.c_str(),((yyvsp[0].typ)).tempvar,a.c_str(), -1);
      strcpy(((yyval.typ)).tempvar, newtemp().c_str());
      // emit("*",c.c_str(),a.c_str(),($$).tempvar, -1);
      emit(c.c_str(),((yyvsp[-2].typ)).tempvar,a.c_str(),((yyval.typ)).tempvar, -1);
    }
    }
    else{
      string c=string("-")+string(((yyvsp[-2].typ)).type);
      strcpy(((yyval.typ)).tempvar, newtemp().c_str());
      emit(c.c_str(),((yyvsp[-2].typ)).tempvar,((yyvsp[0].typ)).tempvar,((yyval.typ)).tempvar, -1);
    }
  }
  else
  {
    strcpy(((yyval.typ)).type,getorder(((yyvsp[0].typ)).type,curr_table->lookup(string((char*)((yyvsp[-2].typ)).type)).type.c_str(),1).c_str());
    if(strcmp(((yyvsp[0].typ)).type,curr_table->lookup(string((char*)((yyvsp[-2].typ)).type)).type.c_str()))
    {
    if(strcmp(getorder(((yyvsp[0].typ)).type,curr_table->lookup(string((char*)((yyvsp[-2].typ)).type)).type.c_str(),1).c_str(),((yyvsp[0].typ)).type))//means 3 is bigger
    {
      //cout<<(getorder(($1).type,($3).type,1).c_str())<<" "<<($3).type<<'\n';
      string a=newtemp();
      string b=string("cast_to_")+string(curr_table->lookup(string((char*)((yyvsp[-2].typ)).type)).type.c_str());
      // string c=string(curr_table->lookup(string((char*)($1).type)).type.c_str())+string(" ")+string(($1).tempvar);
      string c=string("-")+string(curr_table->lookup(string((char*)((yyvsp[-2].typ)).type)).type.c_str());
      emit("=",b.c_str(),((yyvsp[0].typ)).tempvar,a.c_str(), -1);
      strcpy(((yyval.typ)).tempvar, newtemp().c_str());
      // emit("*",c.c_str(),a.c_str(),($$).tempvar, -1);
      emit(c.c_str(),((yyvsp[-2].typ)).tempvar,a.c_str(),((yyval.typ)).tempvar, -1);
    }
    else
    {
      string a=newtemp();
      string b=string("cast_to_")+string(((yyvsp[0].typ)).type);
      // string c=string(($3).type)+string(" ")+string(($3).tempvar);
      string c=string("-")+string(((yyvsp[0].typ)).type);
      emit("=",b.c_str(),((yyvsp[-2].typ)).tempvar,a.c_str(), -1);
      strcpy(((yyval.typ)).tempvar, newtemp().c_str());
      // emit("*",a.c_str(),c.c_str(),($$).tempvar, -1);
      emit(c.c_str(),a.c_str(),((yyvsp[0].typ)).tempvar,((yyval.typ)).tempvar, -1);
    }
    }
    else{
      string c=string("-")+string(((yyvsp[-2].typ)).type);
      strcpy(((yyval.typ)).tempvar, newtemp().c_str());
      emit(c.c_str(),((yyvsp[-2].typ)).tempvar,((yyvsp[0].typ)).tempvar,((yyval.typ)).tempvar, -1);
    }
}
}
#line 9217 "parser.tab.c"
    break;

  case 352:
#line 5418 "parser.y"
                   {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);

  ((yyval.typ)).ndim=((yyvsp[0].typ)).ndim;
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
  
}
#line 9229 "parser.tab.c"
    break;

  case 353:
#line 5425 "parser.y"
                                                                         {

  strcpy(((yyval.typ)).tempvar, newtemp().c_str());
  emit("<<",((yyvsp[-2].typ)).tempvar,((yyvsp[0].typ)).tempvar,((yyval.typ)).tempvar, -1);

  if(!invalidoperator(((yyvsp[-2].typ)).type,0))
  {
    if(!strcmp(((yyvsp[0].typ)).type,"int"))
    {
      strcpy(((yyval.typ)).type,((yyvsp[-2].typ)).type);
    }
    else
    {
      cout<<"Invalid shift operator on line "<< yylineno<<"\n";
    }
  }
  else cout<<"Invalid shift operator on line "<< yylineno<<"\n";
//  strcpy(($$).type,getorder(($1).type,($3).type,1).c_str());
}
#line 9253 "parser.tab.c"
    break;

  case 354:
#line 5444 "parser.y"
                                                                            {
  strcpy(((yyval.typ)).tempvar, newtemp().c_str());
  emit(">>",((yyvsp[-2].typ)).tempvar,((yyvsp[0].typ)).tempvar,((yyval.typ)).tempvar, -1);
 if(!invalidoperator(((yyvsp[-2].typ)).type,0))
  {

    if(!strcmp(((yyvsp[0].typ)).type,"int"))
    {
      strcpy(((yyval.typ)).type,((yyvsp[-2].typ)).type);
    }
    else
    {
      cout<<"Invalid shift operator on line "<< yylineno<<"\n";
    }
  }
  else cout<<"Invalid shift operator on line "<< yylineno<<"\n";
  
  
  
  
}
#line 9279 "parser.tab.c"
    break;

  case 355:
#line 5465 "parser.y"
                                                                                              {
  strcpy(((yyval.typ)).tempvar, newtemp().c_str());
  emit("<<<",((yyvsp[-2].typ)).tempvar,((yyvsp[0].typ)).tempvar,((yyval.typ)).tempvar, -1);
 if(!invalidoperator(((yyvsp[-2].typ)).type,0))
  {
    if(!strcmp(((yyvsp[0].typ)).type,"int"))
    {
      strcpy(((yyval.typ)).type,((yyvsp[-2].typ)).type);
    }
    else
    {
      cout<<"Invalid shift operator on line "<< yylineno<<"\n";
    }
  }
  else cout<<"Invalid shift operator on line "<< yylineno<<"\n";
  
}
#line 9301 "parser.tab.c"
    break;

  case 356:
#line 5483 "parser.y"
                {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);

  ((yyval.typ)).ndim=((yyvsp[0].typ)).ndim;
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
}
#line 9312 "parser.tab.c"
    break;

  case 357:
#line 5489 "parser.y"
                                                         {
  // cout<<strcmp(($1).type,"boolean")<<" "<<($3).type<<"yo"<<(!strcmp(($1).type,"boolean")||!strcmp(($3).type,"boolean"))<<'\n';
  
 if(!strcmp(((yyvsp[-2].typ)).type,"boolean")||!strcmp(((yyvsp[0].typ)).type,"boolean"))
  {
    cout<<"Invalid relation comparision operator on line "<< yylineno<<"\n";
  }
  else 
  {
    if(strcmp(getorder(((yyvsp[-2].typ)).type,((yyvsp[0].typ)).type,1).c_str(),((yyvsp[-2].typ)).type))//means 1 is bigger
    {
      string a=newtemp();
      string b=string("cast_to_")+string(((yyvsp[0].typ)).type);
      emit("=",b.c_str(),((yyvsp[-2].typ)).tempvar,a.c_str(), -1);
      //cout<<(getorder(($1).type,($3).type,1).c_str())<<" "<<($3).type<<'\n';
    }
    if(strcmp(getorder(((yyvsp[-2].typ)).type,((yyvsp[0].typ)).type,1).c_str(),((yyvsp[0].typ)).type))//means 1 is bigger
    {
      string a=newtemp();
      string b=string("cast_to_")+string(((yyvsp[-2].typ)).type);
      emit("=",b.c_str(),((yyvsp[0].typ)).tempvar,a.c_str(), -1);
      //cout<<(getorder(($1).type,($3).type,1).c_str())<<" "<<($3).type<<'\n';
    }
    strcpy(((yyval.typ)).type,"boolean");
  }
  strcpy(((yyval.typ)).tempvar, newtemp().c_str());
  emit("<",((yyvsp[-2].typ)).tempvar,((yyvsp[0].typ)).tempvar,((yyval.typ)).tempvar, -1);
  
}
#line 9346 "parser.tab.c"
    break;

  case 358:
#line 5518 "parser.y"
                                                          {
  // strcpy(($$).tempvar, newtemp().c_str());
  // emit(">",($1).tempvar,($3).tempvar,($$).tempvar, -1);
  
 if(!strcmp(((yyvsp[-2].typ)).type,"boolean")||!strcmp(((yyvsp[0].typ)).type,"boolean"))
  {
    cout<<"Invalid relation comparision operator on line "<< yylineno<<"\n";
  }
  else 
  {
    if(strcmp(getorder(((yyvsp[-2].typ)).type,((yyvsp[0].typ)).type,1).c_str(),((yyvsp[-2].typ)).type))//means 1 is bigger
    {
      string a=newtemp();
      string b=string("cast_to_")+string(((yyvsp[0].typ)).type);
      emit("=",b.c_str(),((yyvsp[-2].typ)).tempvar,a.c_str(), -1);
      //cout<<(getorder(($1).type,($3).type,1).c_str())<<" "<<($3).type<<'\n';
    }
    if(strcmp(getorder(((yyvsp[-2].typ)).type,((yyvsp[0].typ)).type,1).c_str(),((yyvsp[0].typ)).type))//means 1 is bigger
    {
      string a=newtemp();
      string b=string("cast_to_")+string(((yyvsp[-2].typ)).type);
      emit("=",b.c_str(),((yyvsp[0].typ)).tempvar,a.c_str(), -1);
      //cout<<(getorder(($1).type,($3).type,1).c_str())<<" "<<($3).type<<'\n';
    }
    strcpy(((yyval.typ)).type,"boolean");
  }
  strcpy(((yyval.typ)).tempvar, newtemp().c_str());
  emit(">",((yyvsp[-2].typ)).tempvar,((yyvsp[0].typ)).tempvar,((yyval.typ)).tempvar, -1);
  
}
#line 9381 "parser.tab.c"
    break;

  case 359:
#line 5548 "parser.y"
                                                              {
  // strcpy(($$).tempvar, newtemp().c_str());
  // emit("<=",($1).tempvar,($3).tempvar,($$).tempvar, -1);

 if(!strcmp(((yyvsp[-2].typ)).type,"boolean")||!strcmp(((yyvsp[0].typ)).type,"boolean"))
  {
    cout<<"Invalid relation comparision operator on line "<< yylineno<<"\n";
  }
  else 
  {
    if(strcmp(getorder(((yyvsp[-2].typ)).type,((yyvsp[0].typ)).type,1).c_str(),((yyvsp[-2].typ)).type))//means 1 is bigger
    {
      string a=newtemp();
      string b=string("cast_to_")+string(((yyvsp[0].typ)).type);
      emit("=",b.c_str(),((yyvsp[-2].typ)).tempvar,a.c_str(), -1);
      //cout<<(getorder(($1).type,($3).type,1).c_str())<<" "<<($3).type<<'\n';
    }
    if(strcmp(getorder(((yyvsp[-2].typ)).type,((yyvsp[0].typ)).type,1).c_str(),((yyvsp[0].typ)).type))//means 1 is bigger
    {
      string a=newtemp();
      string b=string("cast_to_")+string(((yyvsp[-2].typ)).type);
      emit("=",b.c_str(),((yyvsp[0].typ)).tempvar,a.c_str(), -1);
      //cout<<(getorder(($1).type,($3).type,1).c_str())<<" "<<($3).type<<'\n';
    }
    strcpy(((yyval.typ)).type,"boolean");
  }
  strcpy(((yyval.typ)).tempvar, newtemp().c_str());
  emit("<=",((yyvsp[-2].typ)).tempvar,((yyvsp[0].typ)).tempvar,((yyval.typ)).tempvar, -1);
}
#line 9415 "parser.tab.c"
    break;

  case 360:
#line 5577 "parser.y"
                                                               {
  // strcpy(($$).tempvar, newtemp().c_str());
  // emit(">=",($1).tempvar,($3).tempvar,($$).tempvar, -1);
  
 if(!strcmp(((yyvsp[-2].typ)).type,"boolean")||!strcmp(((yyvsp[0].typ)).type,"boolean"))
  {
    cout<<"Invalid relation comparision operator on line "<< yylineno<<"\n";
  }
  else 
  {
    if(strcmp(getorder(((yyvsp[-2].typ)).type,((yyvsp[0].typ)).type,1).c_str(),((yyvsp[-2].typ)).type))//means 1 is bigger
    {
      string a=newtemp();
      string b=string("cast_to_")+string(((yyvsp[0].typ)).type);
      emit("=",b.c_str(),((yyvsp[-2].typ)).tempvar,a.c_str(), -1);
      //cout<<(getorder(($1).type,($3).type,1).c_str())<<" "<<($3).type<<'\n';
    }
    if(strcmp(getorder(((yyvsp[-2].typ)).type,((yyvsp[0].typ)).type,1).c_str(),((yyvsp[0].typ)).type))//means 1 is bigger
    {
      string a=newtemp();
      string b=string("cast_to_")+string(((yyvsp[-2].typ)).type);
      emit("=",b.c_str(),((yyvsp[0].typ)).tempvar,a.c_str(), -1);
      //cout<<(getorder(($1).type,($3).type,1).c_str())<<" "<<($3).type<<'\n';
    }
    strcpy(((yyval.typ)).type,"boolean");
  }
  strcpy(((yyval.typ)).tempvar, newtemp().c_str());
  emit(">=",((yyvsp[-2].typ)).tempvar,((yyvsp[0].typ)).tempvar,((yyval.typ)).tempvar, -1);
  
  
}
#line 9451 "parser.tab.c"
    break;

  case 361:
#line 5608 "parser.y"
                                               {
  
  
}
#line 9460 "parser.tab.c"
    break;

  case 362:
#line 5613 "parser.y"
                     {
  
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);

  ((yyval.typ)).ndim=((yyvsp[0].typ)).ndim;
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
}
#line 9472 "parser.tab.c"
    break;

  case 363:
#line 5620 "parser.y"
                                                    {
  // strcpy(($$).tempvar, newtemp().c_str());
  // emit("==",($1).tempvar,($3).tempvar,($$).tempvar, -1);
  
  if(!strcmp(((yyvsp[-2].typ)).type,"boolean")||!strcmp(((yyvsp[0].typ)).type,"boolean"))
  {
    cout<<"Invalid equality comparision operator on line "<< yylineno<<"\n";
  }
  else 
  {
    if(strcmp(getorder(((yyvsp[-2].typ)).type,((yyvsp[0].typ)).type,1).c_str(),((yyvsp[-2].typ)).type))//means 1 is bigger
    {
      string a=newtemp();
      string b=string("cast_to_")+string(((yyvsp[0].typ)).type);
      emit("=",b.c_str(),((yyvsp[-2].typ)).tempvar,a.c_str(), -1);
      //cout<<(getorder(($1).type,($3).type,1).c_str())<<" "<<($3).type<<'\n';
    }
    if(strcmp(getorder(((yyvsp[-2].typ)).type,((yyvsp[0].typ)).type,1).c_str(),((yyvsp[0].typ)).type))//means 1 is bigger
    {
      string a=newtemp();
      string b=string("cast_to_")+string(((yyvsp[-2].typ)).type);
      emit("=",b.c_str(),((yyvsp[0].typ)).tempvar,a.c_str(), -1);
      //cout<<(getorder(($1).type,($3).type,1).c_str())<<" "<<($3).type<<'\n';
    }
    strcpy(((yyval.typ)).type,"boolean");
  }
  strcpy(((yyval.typ)).tempvar, newtemp().c_str());
  emit("==",((yyvsp[-2].typ)).tempvar,((yyvsp[0].typ)).tempvar,((yyval.typ)).tempvar, -1);
  
  
}
#line 9508 "parser.tab.c"
    break;

  case 364:
#line 5651 "parser.y"
                                                  {
  // strcpy(($$).tempvar, newtemp().c_str());
  // emit("!=",($1).tempvar,($3).tempvar,($$).tempvar, -1);
  
 if(!strcmp(((yyvsp[-2].typ)).type,"boolean")||!strcmp(((yyvsp[0].typ)).type,"boolean"))
  {
    cout<<"Invalid equality comparision operator on line "<< yylineno<<"\n";
  }
  else 
  {
    if(strcmp(getorder(((yyvsp[-2].typ)).type,((yyvsp[0].typ)).type,1).c_str(),((yyvsp[-2].typ)).type))//means 1 is bigger
    {
      string a=newtemp();
      string b=string("cast_to_")+string(((yyvsp[0].typ)).type);
      emit("=",b.c_str(),((yyvsp[-2].typ)).tempvar,a.c_str(), -1);
      //cout<<(getorder(($1).type,($3).type,1).c_str())<<" "<<($3).type<<'\n';
    }
    if(strcmp(getorder(((yyvsp[-2].typ)).type,((yyvsp[0].typ)).type,1).c_str(),((yyvsp[0].typ)).type))//means 1 is bigger
    {
      string a=newtemp();
      string b=string("cast_to_")+string(((yyvsp[-2].typ)).type);
      emit("=",b.c_str(),((yyvsp[0].typ)).tempvar,a.c_str(), -1);
      //cout<<(getorder(($1).type,($3).type,1).c_str())<<" "<<($3).type<<'\n';
    }
    strcpy(((yyval.typ)).type,"boolean");
  }
  strcpy(((yyval.typ)).tempvar, newtemp().c_str());
  emit("!=",((yyvsp[-2].typ)).tempvar,((yyvsp[0].typ)).tempvar,((yyval.typ)).tempvar, -1);
  
  
}
#line 9544 "parser.tab.c"
    break;

  case 365:
#line 5683 "parser.y"
                   {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);

  ((yyval.typ)).ndim=((yyvsp[0].typ)).ndim;
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
  
}
#line 9556 "parser.tab.c"
    break;

  case 366:
#line 5690 "parser.y"
                                      {
  strcpy(((yyval.typ)).tempvar, newtemp().c_str());
  emit("&",((yyvsp[-2].typ)).tempvar,((yyvsp[0].typ)).tempvar,((yyval.typ)).tempvar, -1);
  
 strcpy(((yyval.typ)).type,getorder(((yyvsp[-2].typ)).type,((yyvsp[0].typ)).type,0).c_str());
  
}
#line 9568 "parser.tab.c"
    break;

  case 367:
#line 5698 "parser.y"
              {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);

  ((yyval.typ)).ndim=((yyvsp[0].typ)).ndim;
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
  
}
#line 9580 "parser.tab.c"
    break;

  case 368:
#line 5705 "parser.y"
                                         {
  strcpy(((yyval.typ)).tempvar, newtemp().c_str());
  emit("^",((yyvsp[-2].typ)).tempvar,((yyvsp[0].typ)).tempvar,((yyval.typ)).tempvar, -1);
 strcpy(((yyval.typ)).type,getorder(((yyvsp[-2].typ)).type,((yyvsp[0].typ)).type,0).c_str());
  
  
}
#line 9592 "parser.tab.c"
    break;

  case 369:
#line 5713 "parser.y"
                      {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);

  ((yyval.typ)).ndim=((yyvsp[0].typ)).ndim;
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
}
#line 9603 "parser.tab.c"
    break;

  case 370:
#line 5719 "parser.y"
                                                {
  strcpy(((yyval.typ)).tempvar, newtemp().c_str());
  emit("|",((yyvsp[-2].typ)).tempvar,((yyvsp[0].typ)).tempvar,((yyval.typ)).tempvar, -1);
  
 strcpy(((yyval.typ)).type,getorder(((yyvsp[-2].typ)).type,((yyvsp[0].typ)).type,0).c_str());

}
#line 9615 "parser.tab.c"
    break;

  case 371:
#line 5727 "parser.y"
                      {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);

  ((yyval.typ)).ndim=((yyvsp[0].typ)).ndim;
   strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
}
#line 9626 "parser.tab.c"
    break;

  case 372:
#line 5733 "parser.y"
                                                       {
  strcpy(((yyval.typ)).tempvar, newtemp().c_str());
  emit("&&",((yyvsp[-2].typ)).tempvar,((yyvsp[0].typ)).tempvar,((yyval.typ)).tempvar, -1);
  
  strcpy(((yyval.typ)).type,"boolean");
  
  
}
#line 9639 "parser.tab.c"
    break;

  case 373:
#line 5742 "parser.y"
                         {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);

  ((yyval.typ)).ndim=((yyvsp[0].typ)).ndim;
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
}
#line 9650 "parser.tab.c"
    break;

  case 374:
#line 5748 "parser.y"
                                                       {
  strcpy(((yyval.typ)).tempvar, newtemp().c_str());
  emit("||",((yyvsp[-2].typ)).tempvar,((yyvsp[0].typ)).tempvar,((yyval.typ)).tempvar, -1);
  strcpy(((yyval.typ)).type,"boolean");
}
#line 9660 "parser.tab.c"
    break;

  case 375:
#line 5754 "parser.y"
                        {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);

  ((yyval.typ)).ndim=((yyvsp[0].typ)).ndim;
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
}
#line 9671 "parser.tab.c"
    break;

  case 376:
#line 5760 "parser.y"
                                                                         {
 strcpy(((yyval.typ)).type,getorder(((yyvsp[-2].typ)).type,((yyvsp[0].typ)).type,1).c_str());
}
#line 9679 "parser.tab.c"
    break;

  case 377:
#line 5764 "parser.y"
                      {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);

  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
  ((yyval.typ)).ndim=((yyvsp[0].typ)).ndim;
}
#line 9690 "parser.tab.c"
    break;

  case 378:
#line 5770 "parser.y"
            {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);
  strcpy(((yyval.typ)).type, ((yyvsp[0].typ)).type);
  ((yyval.typ)).size = ((yyvsp[0].typ)).size;
}
#line 9700 "parser.tab.c"
    break;

  case 379:
#line 5776 "parser.y"
                                                     {
  // cout<<"FFF"<<($1).type<<($3).type<<arrtype<<'\n';
  if(!strcmp(((yyvsp[-1].typ)).tempvar,"="))
  {
    string p = string((char*)((yyvsp[-2].typ)).tempvar);
    string o = p.substr(0, p.find('.'));
    if(p != o){
      string v = p.substr(p.find('.')+1, p.size());
      int tp2 = curr_table->lookup(v).offset;
      string tp3 = "*(" + o + "+" + to_string(tp2) + ")";
      emit("=",((yyvsp[0].typ)).tempvar,"null",tp3.c_str(), -1);
      strcpy(((yyval.typ)).tempvar, tp3.c_str());
    }
    else
      emit("=",((yyvsp[0].typ)).tempvar,"null",((yyvsp[-2].typ)).tempvar, -1);
    
    //emit(($2).tempvar,($$).tempvar,"null",($1).tempvar, -1); This is an optimization
  }
  else
  {
    strcpy(((yyval.typ)).tempvar, newtemp().c_str());
    string a=((yyvsp[-1].typ)).tempvar;
    a=a.substr(0,a.size()-1);
    emit(a,((yyvsp[-2].typ)).tempvar,((yyvsp[0].typ)).tempvar,((yyval.typ)).tempvar, -1);
    emit("=",((yyval.typ)).tempvar,"null",((yyvsp[-2].typ)).tempvar, -1);
  }
  // emit("=",($3).tempvar,"null",($$).tempvar, -1);
  // emit(($2).tempvar,($$).tempvar,"null",($1).tempvar, -1);
  string s=curr_table->lookup(string((char*)((yyvsp[-2].typ)).type)).type;
  string yo="";
  // cout<<"SSS"<<arrtype<<'\n';
  // cout<<"YYY"<<flag<<'\n';
 
  if(curr_table->lookup(string((char*)((yyvsp[-2].typ)).type)).offset != -1)
  {
    if(curr_table->lookup(string((char*)((yyvsp[0].typ)).type)).offset != -1)
    {
      if(!boolgetorder(curr_table->lookup(string((char*)((yyvsp[-2].typ)).type)).type.c_str(),curr_table->lookup(string((char*)((yyvsp[0].typ)).type)).type.c_str(),1))
      {
        if(strcmp(curr_table->lookup(string((char*)((yyvsp[-2].typ)).type)).type.c_str(),((yyvsp[0].typ)).type)) 
        {
          cout<<"Invalid assignment between "<<curr_table->lookup(string((char*)((yyvsp[-2].typ)).type)).type.c_str()<<" and "<<((yyvsp[0].typ)).type<<" on line "<<yylineno<<'\n';
        }
      }
      else
      {
        strcpy(((yyval.typ)).type,curr_table->lookup(string((char*)((yyvsp[0].typ)).type)).type.c_str());
      }
    }
    else
    {
      if(!strcmp(arrtype.c_str(),"null"))
      {
        if(!boolgetorder(curr_table->lookup(string((char*)((yyvsp[-2].typ)).type)).type.c_str(),((yyvsp[0].typ)).type,1))
        {
          if(strcmp(curr_table->lookup(string((char*)((yyvsp[-2].typ)).type)).type.c_str(),((yyvsp[0].typ)).type)) 
          {
            cout<<"Invalid assignment between "<<curr_table->lookup(string((char*)((yyvsp[-2].typ)).type)).type.c_str()<<" and "<<((yyvsp[0].typ)).type<<" on line "<<yylineno<<'\n';
          }
        }
        else
        {
          strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
        }
      }
      else
      {
        if(!boolgetorder(curr_table->lookup(string((char*)((yyvsp[-2].typ)).type)).type.c_str(),arrtype,1))
        {
          if(strcmp(curr_table->lookup(string((char*)((yyvsp[-2].typ)).type)).type.c_str(),arrtype.c_str())) 
          {
            cout<<"Invalid assignment between "<<curr_table->lookup(string((char*)((yyvsp[-2].typ)).type)).type.c_str()<<" and "<<arrtype<<" on line "<<yylineno<<'\n';
          }
        }
        else
        {
          strcpy(((yyval.typ)).type,arrtype.c_str());
        }
      }
    }
  }
  else
  {
    if(curr_table->lookup(string((char*)((yyvsp[0].typ)).type)).offset != -1)
    {
      if(strcmp(((yyvsp[-2].typ)).type,curr_table->lookup(string((char*)((yyvsp[0].typ)).type)).type.c_str()))
      {
        cout<<"Invalid assignment between "<<((yyvsp[-2].typ)).type<<" and "<<curr_table->lookup(string((char*)((yyvsp[0].typ)).type)).type<<" on line "<<yylineno<<'\n';
      }
      else
      {
        strcpy(((yyval.typ)).type,((yyvsp[-2].typ)).type);
      }
    }
    else
    {
      if(!boolgetorder(((yyvsp[-2].typ)).type,((yyvsp[0].typ)).type,1))
      {
        if(!strcmp(((yyvsp[-2].typ)).type,"String")&&!strcmp(((yyvsp[0].typ)).type,"string"))
        {

        }
        else if(strcmp(((yyvsp[-2].typ)).type,((yyvsp[0].typ)).type))cout<<"Invalid assignment between "<<((yyvsp[-2].typ)).type<<" and "<<((yyvsp[0].typ)).type<<" on line "<<yylineno<<'\n';
      }
      else
      {
        strcpy(((yyval.typ)).type,((yyvsp[-2].typ)).type);
      }
    }
  }
  arrtype="null";
}
#line 9817 "parser.tab.c"
    break;

  case 380:
#line 5889 "parser.y"
     {
  // cout<<"shrey"<<($1).type<<'\n';
  if(curr_table->lookup(string((char*)((yyvsp[0].typ)).type)).offset == -1 && checkobj(string((char*)((yyvsp[0].typ)).type)) == 0){
    if(!isaccess)
    {
      cout<<"Undeclared variable on line "<< yylineno<<"\n";
    }
  }
  strcpy(((yyval.typ)).type, ((yyvsp[0].typ)).type);
  ((yyval.typ)).size = ((yyvsp[0].typ)).size;
  isaccess=0;
}
#line 9834 "parser.tab.c"
    break;

  case 381:
#line 5901 "parser.y"
             {
  strcpy(((yyval.typ)).type, ((yyvsp[0].typ)).type);
  // cout<<"shrey"<<($1).type<<'\n';
  ((yyval.typ)).size = ((yyvsp[0].typ)).size;
  
}
#line 9845 "parser.tab.c"
    break;

  case 382:
#line 5907 "parser.y"
             {
  // cout<<"shubhan\n";
  // cout<<"SHUBHAN"<<($1).type<<'\n';
  strcpy(((yyval.typ)).type, ((yyvsp[0].typ)).type);
  // cout<<"GGG"<< ($1).type<<'\n';
  ((yyval.typ)).size = ((yyvsp[0].typ)).size;
  arrtype="null";
}
#line 9858 "parser.tab.c"
    break;

  case 383:
#line 5916 "parser.y"
      {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].lex)).str);
  
  
}
#line 9868 "parser.tab.c"
    break;

  case 384:
#line 5921 "parser.y"
           {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].lex)).str);
  
}
#line 9877 "parser.tab.c"
    break;

  case 385:
#line 5925 "parser.y"
                   {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].lex)).str);
  
}
#line 9886 "parser.tab.c"
    break;

  case 386:
#line 5929 "parser.y"
           {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].lex)).str);
  
}
#line 9895 "parser.tab.c"
    break;

  case 387:
#line 5933 "parser.y"
            {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].lex)).str);
  
}
#line 9904 "parser.tab.c"
    break;

  case 388:
#line 5937 "parser.y"
                                           {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].lex)).str);
  
}
#line 9913 "parser.tab.c"
    break;

  case 389:
#line 5941 "parser.y"
                                             {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].lex)).str);
  
}
#line 9922 "parser.tab.c"
    break;

  case 390:
#line 5945 "parser.y"
                                                                {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].lex)).str);
  
}
#line 9931 "parser.tab.c"
    break;

  case 391:
#line 5949 "parser.y"
          {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].lex)).str);
  
}
#line 9940 "parser.tab.c"
    break;

  case 392:
#line 5953 "parser.y"
          {
  
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].lex)).str);
}
#line 9949 "parser.tab.c"
    break;

  case 393:
#line 5957 "parser.y"
         {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].lex)).str);
  
}
#line 9958 "parser.tab.c"
    break;

  case 394:
#line 5962 "parser.y"
                     {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);

  ((yyval.typ)).ndim=((yyvsp[0].typ)).ndim;
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
  // strcpy(($1).argstring,($1).type);
    // cout<<"YO"<<($1).argstring<<'\n';

  
}
#line 9973 "parser.tab.c"
    break;

  case 395:
#line 5973 "parser.y"
           {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
  
}
#line 9983 "parser.tab.c"
    break;


#line 9987 "parser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 5978 "parser.y"

int main(int argc, char *argv[])
{  string executible_name(argv[0]);
  argc--, argv++;
  if(argc != 2) {
    cerr << executible_name << ": Error: provide arguments correctly\n";
    exit(1);
  }
  char *input_filename = argv[0];
  int verbose = atoi(argv[1]);
  if(verbose) yydebug = 1;
  yyin = fopen(input_filename, "r");
  if(yyin == NULL) {
    cerr << executible_name << ": Error: Input file " << input_filename << " not found.\n";
    exit(1);
  }
  yyparse();
  // yyparse();
  int changes = 0;
  ofstream fout;
  for(auto it: list_of_Symbol_Tables){
    if(it->table.begin() == it->table.end()){
      continue;
    }
    string it1 = it->table.begin()->second.scope_name;
    if(it1 == "Global"){
      changes = 1;
      fout.close();
    }
    else if(it1.substr(0, 5) == "Class"){
      changes = 1;
      fout.close();
    }
    else if(it1.substr(0, 6) == "Method"){
      changes = 1;
      fout.close();
    }
    if(changes == 0){
      for(auto it2=it->table.begin(); it2!=it->table.end(); it2++){
        fout<<it2->first<<", "<<it2->second.token<<", "<<it2->second.type<<", "<<it2->second.offset<<", "<<it2->second.scope_name<<", "<<it2->second.line<<'\n';
      }
    }
    else{
      changes = 0;
      string output = it1 + ".csv";
      // cout<<output<<endl;
      fout.open(output);
      fout<<"Lexeme"<<','<<"Token"<<','<<"Type"<<','<<"Offset"<<','<<"Scope Name"<<','<<"Line Number"<<'\n';
      for(auto it2=it->table.begin(); it2!=it->table.end(); it2++){
        fout<<it2->first<<", "<<it2->second.token<<", "<<it2->second.type<<", "<<it2->second.offset<<", "<<it2->second.scope_name<<", "<<it2->second.line<<'\n';
      }
    }
  }
  fout.close();
  
  // cout<<endl;
  /* cout<<getorder("int","long",1)<<'\n'; */
  for(auto it: list_of_Symbol_Tables){
    // cout<<"NEW TABLE"<<'\n';
    it->print_table();
    cout<<'\n';
  }
// cout<<"Op"<<' '<<"Arg1"<<' '<<"Arg2"<<' '<<"Res"<<'\n';
int flag=0;
string classname,n,funcname,m;
   for(auto it: code){
    cout<<it.op<<' '<<it.arg1<<' '<<it.arg2<<' '<<it.res<<'\n';
    if(it.op=="BeginClass")
    {
      classname=n;
    }
    n=it.op;
    if(it.op=="BeginFunc")
    {
      funcname=m;
      flag=1;
      fout.open(classname+"."+funcname+".3ac");
    }
    m=it.op;
    if(it.op=="EndFunc")
    {
      flag=0;
      fout<<it.op<<' '<<it.arg1<<' '<<it.arg2<<' '<<it.res<<'\n';
      fout.close();
    }
    if(flag==1)
    {
      if(it.op=="BeginFunc")
      {
        fout<<it.op<<'\n';
      }
      else if(it.arg2=="null" && it.res=="null")
      {
        fout<<it.op<<" "<<it.res<<"\n";
      }
      else if(it.op=="Call")
      {
        fout<<it.res<<" = "<<it.op<<" "<<it.arg1<<'\n';
      }
      else if(it.arg2=="null" && it.res!="null")
      {
      if(it.op=="minus"||it.op=="plus"||it.op=="!"||it.op=="~")
        {
      fout<<it.res<<' '<<"= "<<it.op<<' '<<it.arg1<<'\n';
        }
      else 
        {
        fout<<it.res<<' '<<"="<<' '<<it.arg1<<"\n";
        }
      }
      else if(it.op=="Pushparams"||it.op=="Popparams")
      {
        fout<<it.op<<" "<<it.arg1<<'\n';
      }
      else if(it.res=="Ifz")
      {
        fout<<it.res<<" "<<it.arg1<<" "<<it.op<<" "<<it.arg2<<"\n";
      }
      else if(it.op=="Goto")
      {
        fout<<it.op<<" "<<it.arg1<<it.arg2<<it.res<<"\n";
      }
      else if(it.arg1==":")
      {
        fout<<it.op<<it.arg1<<"\n";
      }
      else if(it.arg1=="new")
      {
        fout<<it.res<<" = "<<it.arg1<<" "<<it.arg2<<"\n";
      }
      else if(it.op=="Return")
      {
        fout<<it.op<<" "<<it.arg1<<"\n";
      }
      else if(it.arg1=="cast_to_int"||it.arg1=="cast_to_float"||it.arg1=="cast_to_byte"||it.arg1=="cast_to_boolean"||it.arg1=="cast_to_byte"||it.arg1=="cast_to_short"||it.arg1=="cast_to_long"||it.arg1=="cast_to_double"||it.arg1=="cast_to_string")
      {
        fout<<it.res<<" = "<<it.arg1<<" "<<it.arg2<<"\n";
      }
      else
      {
        fout<<it.res<<" = "<<it.arg1<<" "<<it.op<<" "<<it.arg2<<"\n";
      }

      }
    }

  return 0;
}
void yyerror(const char * s)
{
  cout<<"Error in line " << yylineno << " : " << s << endl;
  exit(0);
}
