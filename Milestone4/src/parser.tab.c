/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

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
    #define PTR_SZ 8
    using namespace std;
    extern FILE* yyin;
    void yyerror(const char * s);
    int yylex();
    int nelem=0;
    vector<int> newdim;
    int dimint;
    int ispopped = 1;
    int isvoid;
    int isimport=0;
    string arrayname;
    int issystem=0;
    int isfinal=0;
    int isreturn =0;
    int arrayaccesscount = 0;
    string fullname;
    string newhandle = "null";
    string classname;
    int isclassaccess=0;
    int ismainstatic=0;
    map<int,vector<int>> shape;
    int isaccess=0;
    int isprivate=0;
    int isstatic=0;
    int isfieldprivate=0;
    string curr_class="";
    stack<string> currfunc;
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
    int totalstack = 0;
    
    #define YYERROR_VERBOSE 1

    int nodes = 0;
    map<int, string> node_names;
    vector<pair<int,string>> parents, child;
    string s;
    
    vector<string> ops = {"=",">","<","!","~","?",":","->","==",">=","<=","!=","&&","++","--","+","-","*","/","&",",","^","%","<<",">>",">>>","+=","-=","*=","/=","&=",",=","^=","%=","<<=",">>=",">>>=","||"};
    vector<string> keywords = {"abstract","continue","for","new","switch","assert","default","if","package","synchronized","boolean","do","goto","private","this","break","double","implements","protected","throw","byte","else","import","public","throws","case","enum","instanceof","return","transient","catch","extends","int","SHORT","try","char","final","interface","static","void","class","finally","long","strictfp","volatile","const","float","native","super","while","_","exports","opens","requires","uses","module","permits","sealed","var","non-sealed","provides","to","with","open","record","transitive","yield"};
    vector<string> sep = {"(",")","{","}",",","[","]",";",".","...","::"};
    vector<string> dtype = {"char","byte","short","int","long","float","double","invalid"};
    void print_dims()
    {
      cout<<"DIMS: ";
      for(auto i:newdim)
      {
        cout<<i<<" ";
      }
      cout<<"\n";
      //   
    }
    int getsz(string s)
    {
      int count = 0;
      string t = "";
      for(auto it: s){
        if(count == 0 && it != '['){
          t.push_back(it);
        }
        if(it == '['){
          count++;
        }
      }
      s = t;
      if(s=="char")
      return 2;
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
      else if(s=="null")
      return -1;
      else return 8;
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
      int sz;
      if(flag==0)
      sz=5;
      else
      sz=7;
      if(a==b)
      return a;
      else
      {
        int q=7,w=7;
        for(int i=0;i<sz;i++)
        {
          if(a==dtype[i])
          q=i;      
        }
        for(int i=0;i<sz;i++)
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
      int sz;
      if(flag==0)
      sz=5;
      else
      sz=7;

      int q=7,w=7;
      for(int i=0;i<sz;i++)
      {
        if(a==dtype[i])
        q=i;      
      }
      for(int i=0;i<sz;i++)
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
        int classwidth = 0;
        vector<int> dims;
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
          classwidth = classwidth;
          if(!strcmp(toke.c_str(),"Constructor")) isitstatic=1;
          // isstatic=0;
          // dims=newdim;
          copy(newdim.begin(), newdim.end(), back_inserter(dims)); 
          // if(!dims.empty())
          // {
          // cout<<"DIMS: ";
          // for(auto i:dims)
          // {
          //   cout<<i<<" ";
          // }
          // cout<<'\n';
          // }
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
        int classwidth;
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
    int sz = 0; 
    string type="";
    vector<Sym_Table*> list_of_Symbol_Tables(1, curr_table);
    int array_sz = 0;
    vector< pair<string,pair<string,int>> > funcparam;
    vector <int> sizeparam;
    vector<string> tempparam;
    int funcargno;
    int fl = 0;
    vector<string> objects;
    stack<string> controlflow;
    stack<pair<string, int>> args;
    int addoff = 0;
    stack<string> continuelabels;
    stack<string> breaklabels;
    map<string, string> objtotemp;


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

    int getclasswidth(string lexeme){
        for(auto it: list_of_Symbol_Tables){
            auto tab = it->table;
            for(auto it1 = tab.begin(); it1 != tab.end(); it1++){
                if(it1->second.scope_name == "Class" + lexeme){
                    return it->classwidth;
                }
                else{
                    break;
                }
            }
        }
        return 0;
    }
    int getfuncwidth(string lexeme){
        for(auto it: list_of_Symbol_Tables){
            auto tab = it->table;
            for(auto it1 = tab.begin(); it1 != tab.end(); it1++){
                if(it1->second.scope_name == "Method" + lexeme){
                    return it->classwidth;
                }
                else{
                    break;
                }
            }
        }
        return 0;
    }

    int offsetobj(string classname, string lexeme){
      for(auto it : list_of_Symbol_Tables){
          auto tab = it->table;
          for(auto it1 = tab.begin(); it1 != tab.end(); it1++){
                if(it1->second.scope_name == "Class" + classname){
                    if(it1->first == lexeme){
                      return it1->second.offset;
                    }
                }
                else{
                    break;
                }
            }
      }
      return -1;
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

    int funcargtypesz(int iscurrclass, string funcname){
      if(iscurrclass){
        int cnt = -1;
        for(auto it: list_of_Symbol_Tables){
          auto tab = it->table;
          for(auto it1 = tab.begin(); it1 != tab.end(); it1++){
              if(it1->second.scope_name == "Method" + funcname){
                if(it1->second.argno > 0 && it1->second.offset > cnt){
                  cnt = it1->second.offset;
                }
              }
              else{
                break;
              }
          }
          if(cnt != -1){
            int ret = 1000000000;
            for(auto it1 = tab.begin(); it1 != tab.end(); it1++){
                if(it1->second.scope_name == "Method" + funcname){
                  if(it1->second.offset > cnt && ret > it1->second.offset){
                    ret = it1->second.offset;
                  }
                }
                else{
                  break;
                }
            }
            if(ret == 1000000000){
              ret = it->classwidth;
            }
            return ret;
          }
        }
      }
      return 0;
    }

// }

#line 672 "parser.tab.c"

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

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_BYTE = 3,                       /* BYTE  */
  YYSYMBOL_SHORT = 4,                      /* SHORT  */
  YYSYMBOL_INT = 5,                        /* INT  */
  YYSYMBOL_LONG = 6,                       /* LONG  */
  YYSYMBOL_CHAR = 7,                       /* CHAR  */
  YYSYMBOL_ELSE = 8,                       /* ELSE  */
  YYSYMBOL_CATCH = 9,                      /* CATCH  */
  YYSYMBOL_FINALLY = 10,                   /* FINALLY  */
  YYSYMBOL_INTERFACE = 11,                 /* INTERFACE  */
  YYSYMBOL_PLUS = 12,                      /* PLUS  */
  YYSYMBOL_FORWARDSLASH = 13,              /* FORWARDSLASH  */
  YYSYMBOL_MODULO = 14,                    /* MODULO  */
  YYSYMBOL_IF = 15,                        /* IF  */
  YYSYMBOL_SWITCH = 16,                    /* SWITCH  */
  YYSYMBOL_IntegerLiteral = 17,            /* IntegerLiteral  */
  YYSYMBOL_FloatingPointLiteral = 18,      /* FloatingPointLiteral  */
  YYSYMBOL_BooleanLiteral = 19,            /* BooleanLiteral  */
  YYSYMBOL_CharacterLiteral = 20,          /* CharacterLiteral  */
  YYSYMBOL_StringLiteral = 21,             /* StringLiteral  */
  YYSYMBOL_NullLiteral = 22,               /* NullLiteral  */
  YYSYMBOL_FLOAT = 23,                     /* FLOAT  */
  YYSYMBOL_DOUBLE = 24,                    /* DOUBLE  */
  YYSYMBOL_BOOLEAN = 25,                   /* BOOLEAN  */
  YYSYMBOL_CASE = 26,                      /* CASE  */
  YYSYMBOL_DEFAULT = 27,                   /* DEFAULT  */
  YYSYMBOL_DO = 28,                        /* DO  */
  YYSYMBOL_WHILE = 29,                     /* WHILE  */
  YYSYMBOL_OPENANGULARBRACKET = 30,        /* OPENANGULARBRACKET  */
  YYSYMBOL_CLOSEANGULARBRACKET = 31,       /* CLOSEANGULARBRACKET  */
  YYSYMBOL_OPENBRACKET = 32,               /* OPENBRACKET  */
  YYSYMBOL_CLOSEBRACKET = 33,              /* CLOSEBRACKET  */
  YYSYMBOL_OPENCURLYBRACKET = 34,          /* OPENCURLYBRACKET  */
  YYSYMBOL_CLOSECURLYBRACKET = 35,         /* CLOSECURLYBRACKET  */
  YYSYMBOL_OPENSQUAREBRACKET = 36,         /* OPENSQUAREBRACKET  */
  YYSYMBOL_CLOSESQUAREBRACKET = 37,        /* CLOSESQUAREBRACKET  */
  YYSYMBOL_EQUAL = 38,                     /* EQUAL  */
  YYSYMBOL_STAREQUAL = 39,                 /* STAREQUAL  */
  YYSYMBOL_FORWARDSLASHEQUAL = 40,         /* FORWARDSLASHEQUAL  */
  YYSYMBOL_PLUSEQUAL = 41,                 /* PLUSEQUAL  */
  YYSYMBOL_MINUSEQUAL = 42,                /* MINUSEQUAL  */
  YYSYMBOL_OPENANGULARBRACKETOPENANGULARBRACKETEQUAL = 43, /* OPENANGULARBRACKETOPENANGULARBRACKETEQUAL  */
  YYSYMBOL_CLOSEANGULARBRACKETCLOSEANGULARBRACKETEQUAL = 44, /* CLOSEANGULARBRACKETCLOSEANGULARBRACKETEQUAL  */
  YYSYMBOL_CLOSEANGULARBRACKETCLOSEANGULARBRACKETCLOSEANGULARBRACKETEQUAL = 45, /* CLOSEANGULARBRACKETCLOSEANGULARBRACKETCLOSEANGULARBRACKETEQUAL  */
  YYSYMBOL_ANDEQUAL = 46,                  /* ANDEQUAL  */
  YYSYMBOL_XOREQUAL = 47,                  /* XOREQUAL  */
  YYSYMBOL_OREQUAL = 48,                   /* OREQUAL  */
  YYSYMBOL_DOT = 49,                       /* DOT  */
  YYSYMBOL_COMMA = 50,                     /* COMMA  */
  YYSYMBOL_SEMICOLON = 51,                 /* SEMICOLON  */
  YYSYMBOL_COLON = 52,                     /* COLON  */
  YYSYMBOL_INSTANCEOF = 53,                /* INSTANCEOF  */
  YYSYMBOL_Identifier = 54,                /* Identifier  */
  YYSYMBOL_PUBLIC = 55,                    /* PUBLIC  */
  YYSYMBOL_PROTECTED = 56,                 /* PROTECTED  */
  YYSYMBOL_PRIVATE = 57,                   /* PRIVATE  */
  YYSYMBOL_STATIC = 58,                    /* STATIC  */
  YYSYMBOL_ABSTRACT = 59,                  /* ABSTRACT  */
  YYSYMBOL_FINAL = 60,                     /* FINAL  */
  YYSYMBOL_NATIVE = 61,                    /* NATIVE  */
  YYSYMBOL_SYNCHRONIZED = 62,              /* SYNCHRONIZED  */
  YYSYMBOL_TRANSIENT = 63,                 /* TRANSIENT  */
  YYSYMBOL_VOLATILE = 64,                  /* VOLATILE  */
  YYSYMBOL_PACKAGE = 65,                   /* PACKAGE  */
  YYSYMBOL_IMPORT = 66,                    /* IMPORT  */
  YYSYMBOL_STAR = 67,                      /* STAR  */
  YYSYMBOL_CLASS = 68,                     /* CLASS  */
  YYSYMBOL_EXTENDS = 69,                   /* EXTENDS  */
  YYSYMBOL_IMPLEMENTS = 70,                /* IMPLEMENTS  */
  YYSYMBOL_VOID = 71,                      /* VOID  */
  YYSYMBOL_THIS = 72,                      /* THIS  */
  YYSYMBOL_SUPER = 73,                     /* SUPER  */
  YYSYMBOL_BREAK = 74,                     /* BREAK  */
  YYSYMBOL_RETURN = 75,                    /* RETURN  */
  YYSYMBOL_FOR = 76,                       /* FOR  */
  YYSYMBOL_TRY = 77,                       /* TRY  */
  YYSYMBOL_THROWS = 78,                    /* THROWS  */
  YYSYMBOL_THROW = 79,                     /* THROW  */
  YYSYMBOL_CONTINUE = 80,                  /* CONTINUE  */
  YYSYMBOL_NEW = 81,                       /* NEW  */
  YYSYMBOL_PLUSPLUS = 82,                  /* PLUSPLUS  */
  YYSYMBOL_MINUSMINUS = 83,                /* MINUSMINUS  */
  YYSYMBOL_TILDA = 84,                     /* TILDA  */
  YYSYMBOL_NOT = 85,                       /* NOT  */
  YYSYMBOL_AND = 86,                       /* AND  */
  YYSYMBOL_OR = 87,                        /* OR  */
  YYSYMBOL_OROR = 88,                      /* OROR  */
  YYSYMBOL_ANDAND = 89,                    /* ANDAND  */
  YYSYMBOL_NOTEQUAL = 90,                  /* NOTEQUAL  */
  YYSYMBOL_MINUS = 91,                     /* MINUS  */
  YYSYMBOL_OPENANGULARBRACKETOPENANGULARBRACKET = 92, /* OPENANGULARBRACKETOPENANGULARBRACKET  */
  YYSYMBOL_CLOSEANGULARBRACKETCLOSEANGULARBRACKET = 93, /* CLOSEANGULARBRACKETCLOSEANGULARBRACKET  */
  YYSYMBOL_CLOSEANGULARBRACKETCLOSEANGULARBRACKETCLOSEANGULARBRACKET = 94, /* CLOSEANGULARBRACKETCLOSEANGULARBRACKETCLOSEANGULARBRACKET  */
  YYSYMBOL_QUESTION = 95,                  /* QUESTION  */
  YYSYMBOL_XOR = 96,                       /* XOR  */
  YYSYMBOL_EQUALEQUAL = 97,                /* EQUALEQUAL  */
  YYSYMBOL_OPENANGULARBRACKETEQUAL = 98,   /* OPENANGULARBRACKETEQUAL  */
  YYSYMBOL_CLOSEANGULARBRACKETEQUAL = 99,  /* CLOSEANGULARBRACKETEQUAL  */
  YYSYMBOL_YYACCEPT = 100,                 /* $accept  */
  YYSYMBOL_Goal = 101,                     /* Goal  */
  YYSYMBOL_Literal = 102,                  /* Literal  */
  YYSYMBOL_Type = 103,                     /* Type  */
  YYSYMBOL_PrimitiveType = 104,            /* PrimitiveType  */
  YYSYMBOL_NumericType = 105,              /* NumericType  */
  YYSYMBOL_IntegralType = 106,             /* IntegralType  */
  YYSYMBOL_FloatingPointType = 107,        /* FloatingPointType  */
  YYSYMBOL_ReferenceType = 108,            /* ReferenceType  */
  YYSYMBOL_ClassOrInterfaceType = 109,     /* ClassOrInterfaceType  */
  YYSYMBOL_ClassType = 110,                /* ClassType  */
  YYSYMBOL_InterfaceType = 111,            /* InterfaceType  */
  YYSYMBOL_ArrayType = 112,                /* ArrayType  */
  YYSYMBOL_Name = 113,                     /* Name  */
  YYSYMBOL_SimpleName = 114,               /* SimpleName  */
  YYSYMBOL_QualifiedName = 115,            /* QualifiedName  */
  YYSYMBOL_CompilationUnit = 116,          /* CompilationUnit  */
  YYSYMBOL_ImportDeclarations = 117,       /* ImportDeclarations  */
  YYSYMBOL_TypeDeclarations = 118,         /* TypeDeclarations  */
  YYSYMBOL_PackageDeclaration = 119,       /* PackageDeclaration  */
  YYSYMBOL_ImportDeclaration = 120,        /* ImportDeclaration  */
  YYSYMBOL_DummyImport = 121,              /* DummyImport  */
  YYSYMBOL_SingleTypeImportDeclaration = 122, /* SingleTypeImportDeclaration  */
  YYSYMBOL_TypeImportOnDemandDeclaration = 123, /* TypeImportOnDemandDeclaration  */
  YYSYMBOL_TypeDeclaration = 124,          /* TypeDeclaration  */
  YYSYMBOL_Modifiers = 125,                /* Modifiers  */
  YYSYMBOL_Modifier = 126,                 /* Modifier  */
  YYSYMBOL_ClassDeclaration = 127,         /* ClassDeclaration  */
  YYSYMBOL_128_1 = 128,                    /* $@1  */
  YYSYMBOL_129_2 = 129,                    /* $@2  */
  YYSYMBOL_130_3 = 130,                    /* $@3  */
  YYSYMBOL_131_4 = 131,                    /* $@4  */
  YYSYMBOL_132_5 = 132,                    /* $@5  */
  YYSYMBOL_133_6 = 133,                    /* $@6  */
  YYSYMBOL_134_7 = 134,                    /* $@7  */
  YYSYMBOL_135_8 = 135,                    /* $@8  */
  YYSYMBOL_Super = 136,                    /* Super  */
  YYSYMBOL_Interfaces = 137,               /* Interfaces  */
  YYSYMBOL_InterfaceTypeList = 138,        /* InterfaceTypeList  */
  YYSYMBOL_ClassBody = 139,                /* ClassBody  */
  YYSYMBOL_ClassBodyDeclarations = 140,    /* ClassBodyDeclarations  */
  YYSYMBOL_ClassBodyDeclaration = 141,     /* ClassBodyDeclaration  */
  YYSYMBOL_ClassMemberDeclaration = 142,   /* ClassMemberDeclaration  */
  YYSYMBOL_FieldDeclaration = 143,         /* FieldDeclaration  */
  YYSYMBOL_VariableDeclarators = 144,      /* VariableDeclarators  */
  YYSYMBOL_VariableDeclarator = 145,       /* VariableDeclarator  */
  YYSYMBOL_VariableDeclaratorId = 146,     /* VariableDeclaratorId  */
  YYSYMBOL_147_9 = 147,                    /* $@9  */
  YYSYMBOL_VariableInitializer = 148,      /* VariableInitializer  */
  YYSYMBOL_MethodDeclaration = 149,        /* MethodDeclaration  */
  YYSYMBOL_MethodHeader = 150,             /* MethodHeader  */
  YYSYMBOL_MethodDeclarator = 151,         /* MethodDeclarator  */
  YYSYMBOL_FormalParameterList = 152,      /* FormalParameterList  */
  YYSYMBOL_FormalParameter = 153,          /* FormalParameter  */
  YYSYMBOL_Throws = 154,                   /* Throws  */
  YYSYMBOL_ClassTypeList = 155,            /* ClassTypeList  */
  YYSYMBOL_MethodBody = 156,               /* MethodBody  */
  YYSYMBOL_StaticInitializer = 157,        /* StaticInitializer  */
  YYSYMBOL_158_10 = 158,                   /* $@10  */
  YYSYMBOL_ConstructorDeclaration = 159,   /* ConstructorDeclaration  */
  YYSYMBOL_ConstructorHeader = 160,        /* ConstructorHeader  */
  YYSYMBOL_ConstructorDeclarator = 161,    /* ConstructorDeclarator  */
  YYSYMBOL_162_11 = 162,                   /* $@11  */
  YYSYMBOL_ConstructorBody = 163,          /* ConstructorBody  */
  YYSYMBOL_ExplicitConstructorInvocation = 164, /* ExplicitConstructorInvocation  */
  YYSYMBOL_InterfaceDeclaration = 165,     /* InterfaceDeclaration  */
  YYSYMBOL_166_12 = 166,                   /* $@12  */
  YYSYMBOL_167_13 = 167,                   /* $@13  */
  YYSYMBOL_168_14 = 168,                   /* $@14  */
  YYSYMBOL_169_15 = 169,                   /* $@15  */
  YYSYMBOL_ExtendsInterfaces = 170,        /* ExtendsInterfaces  */
  YYSYMBOL_InterfaceBody = 171,            /* InterfaceBody  */
  YYSYMBOL_InterfaceMemberDeclarations = 172, /* InterfaceMemberDeclarations  */
  YYSYMBOL_InterfaceMemberDeclaration = 173, /* InterfaceMemberDeclaration  */
  YYSYMBOL_ConstantDeclaration = 174,      /* ConstantDeclaration  */
  YYSYMBOL_AbstractMethodDeclaration = 175, /* AbstractMethodDeclaration  */
  YYSYMBOL_ArrayInitializer = 176,         /* ArrayInitializer  */
  YYSYMBOL_VariableInitializers = 177,     /* VariableInitializers  */
  YYSYMBOL_Block = 178,                    /* Block  */
  YYSYMBOL_BlockStatements = 179,          /* BlockStatements  */
  YYSYMBOL_BlockStatement = 180,           /* BlockStatement  */
  YYSYMBOL_LocalVariableDeclarationStatement = 181, /* LocalVariableDeclarationStatement  */
  YYSYMBOL_LocalVariableDeclaration = 182, /* LocalVariableDeclaration  */
  YYSYMBOL_Statement = 183,                /* Statement  */
  YYSYMBOL_StatementNoShortIf = 184,       /* StatementNoShortIf  */
  YYSYMBOL_StatementWithoutTrailingSubstatement = 185, /* StatementWithoutTrailingSubstatement  */
  YYSYMBOL_EmptyStatement = 186,           /* EmptyStatement  */
  YYSYMBOL_LabeledStatement = 187,         /* LabeledStatement  */
  YYSYMBOL_LabeledStatementNoShortIf = 188, /* LabeledStatementNoShortIf  */
  YYSYMBOL_ExpressionStatement = 189,      /* ExpressionStatement  */
  YYSYMBOL_StatementExpression = 190,      /* StatementExpression  */
  YYSYMBOL_DummyIfStatement = 191,         /* DummyIfStatement  */
  YYSYMBOL_DummyElseStatement = 192,       /* DummyElseStatement  */
  YYSYMBOL_DummyIfStatement1 = 193,        /* DummyIfStatement1  */
  YYSYMBOL_IfThenStatement = 194,          /* IfThenStatement  */
  YYSYMBOL_DummyIfStatement2 = 195,        /* DummyIfStatement2  */
  YYSYMBOL_IfThenElseStatement = 196,      /* IfThenElseStatement  */
  YYSYMBOL_IfThenElseStatementNoShortIf = 197, /* IfThenElseStatementNoShortIf  */
  YYSYMBOL_DummySwitchStatement = 198,     /* DummySwitchStatement  */
  YYSYMBOL_SwitchStatement = 199,          /* SwitchStatement  */
  YYSYMBOL_SwitchBlock = 200,              /* SwitchBlock  */
  YYSYMBOL_SwitchBlockStatementGroups = 201, /* SwitchBlockStatementGroups  */
  YYSYMBOL_SwitchBlockStatementGroup = 202, /* SwitchBlockStatementGroup  */
  YYSYMBOL_SwitchLabels = 203,             /* SwitchLabels  */
  YYSYMBOL_SwitchLabel = 204,              /* SwitchLabel  */
  YYSYMBOL_DummyWhileStatement = 205,      /* DummyWhileStatement  */
  YYSYMBOL_DummyWhileStatement1 = 206,     /* DummyWhileStatement1  */
  YYSYMBOL_WhileStatement = 207,           /* WhileStatement  */
  YYSYMBOL_WhileStatementNoShortIf = 208,  /* WhileStatementNoShortIf  */
  YYSYMBOL_DummyDoStatement = 209,         /* DummyDoStatement  */
  YYSYMBOL_DummyDoStatement1 = 210,        /* DummyDoStatement1  */
  YYSYMBOL_DoStatement = 211,              /* DoStatement  */
  YYSYMBOL_DummyForStatement = 212,        /* DummyForStatement  */
  YYSYMBOL_DummyForStatement1 = 213,       /* DummyForStatement1  */
  YYSYMBOL_DummyForStatement14 = 214,      /* DummyForStatement14  */
  YYSYMBOL_DummyForStatement2 = 215,       /* DummyForStatement2  */
  YYSYMBOL_DummyForStatement3 = 216,       /* DummyForStatement3  */
  YYSYMBOL_DummyForStatement4 = 217,       /* DummyForStatement4  */
  YYSYMBOL_DummyForStatement15 = 218,      /* DummyForStatement15  */
  YYSYMBOL_DummyForStatement5 = 219,       /* DummyForStatement5  */
  YYSYMBOL_DummyForStatement6 = 220,       /* DummyForStatement6  */
  YYSYMBOL_DummyForStatement7 = 221,       /* DummyForStatement7  */
  YYSYMBOL_DummyForStatement8 = 222,       /* DummyForStatement8  */
  YYSYMBOL_DummyForStatement9 = 223,       /* DummyForStatement9  */
  YYSYMBOL_DummyForStatement10 = 224,      /* DummyForStatement10  */
  YYSYMBOL_DummyForStatement11 = 225,      /* DummyForStatement11  */
  YYSYMBOL_DummyForStatement12 = 226,      /* DummyForStatement12  */
  YYSYMBOL_DummyForStatement13 = 227,      /* DummyForStatement13  */
  YYSYMBOL_ForStatement = 228,             /* ForStatement  */
  YYSYMBOL_ForStatementNoShortIf = 229,    /* ForStatementNoShortIf  */
  YYSYMBOL_ForInit = 230,                  /* ForInit  */
  YYSYMBOL_ForUpdate = 231,                /* ForUpdate  */
  YYSYMBOL_StatementExpressionList = 232,  /* StatementExpressionList  */
  YYSYMBOL_BreakStatement = 233,           /* BreakStatement  */
  YYSYMBOL_ContinueStatement = 234,        /* ContinueStatement  */
  YYSYMBOL_ReturnStatement = 235,          /* ReturnStatement  */
  YYSYMBOL_ThrowStatement = 236,           /* ThrowStatement  */
  YYSYMBOL_SynchronizedStatement = 237,    /* SynchronizedStatement  */
  YYSYMBOL_TryStatement = 238,             /* TryStatement  */
  YYSYMBOL_Catches = 239,                  /* Catches  */
  YYSYMBOL_CatchClause = 240,              /* CatchClause  */
  YYSYMBOL_241_16 = 241,                   /* $@16  */
  YYSYMBOL_Finally = 242,                  /* Finally  */
  YYSYMBOL_Primary = 243,                  /* Primary  */
  YYSYMBOL_PrimaryNoNewArray = 244,        /* PrimaryNoNewArray  */
  YYSYMBOL_ClassInstanceCreationExpression = 245, /* ClassInstanceCreationExpression  */
  YYSYMBOL_ArgumentList = 246,             /* ArgumentList  */
  YYSYMBOL_ArrayCreationExpression = 247,  /* ArrayCreationExpression  */
  YYSYMBOL_DimExprs = 248,                 /* DimExprs  */
  YYSYMBOL_DimExpr = 249,                  /* DimExpr  */
  YYSYMBOL_Dims = 250,                     /* Dims  */
  YYSYMBOL_FieldAccess = 251,              /* FieldAccess  */
  YYSYMBOL_DummyMethodInvocation = 252,    /* DummyMethodInvocation  */
  YYSYMBOL_MethodInvocation = 253,         /* MethodInvocation  */
  YYSYMBOL_ArrayAccess = 254,              /* ArrayAccess  */
  YYSYMBOL_PostfixExpression = 255,        /* PostfixExpression  */
  YYSYMBOL_PostIncrementExpression = 256,  /* PostIncrementExpression  */
  YYSYMBOL_PostDecrementExpression = 257,  /* PostDecrementExpression  */
  YYSYMBOL_UnaryExpression = 258,          /* UnaryExpression  */
  YYSYMBOL_PreIncrementExpression = 259,   /* PreIncrementExpression  */
  YYSYMBOL_PreDecrementExpression = 260,   /* PreDecrementExpression  */
  YYSYMBOL_UnaryExpressionNotPlusMinus = 261, /* UnaryExpressionNotPlusMinus  */
  YYSYMBOL_CastExpression = 262,           /* CastExpression  */
  YYSYMBOL_MultiplicativeExpression = 263, /* MultiplicativeExpression  */
  YYSYMBOL_AdditiveExpression = 264,       /* AdditiveExpression  */
  YYSYMBOL_ShiftExpression = 265,          /* ShiftExpression  */
  YYSYMBOL_RelationalExpression = 266,     /* RelationalExpression  */
  YYSYMBOL_EqualityExpression = 267,       /* EqualityExpression  */
  YYSYMBOL_AndExpression = 268,            /* AndExpression  */
  YYSYMBOL_ExclusiveOrExpression = 269,    /* ExclusiveOrExpression  */
  YYSYMBOL_InclusiveOrExpression = 270,    /* InclusiveOrExpression  */
  YYSYMBOL_ConditionalAndExpression = 271, /* ConditionalAndExpression  */
  YYSYMBOL_ConditionalOrExpression = 272,  /* ConditionalOrExpression  */
  YYSYMBOL_ConditionalExpression = 273,    /* ConditionalExpression  */
  YYSYMBOL_AssignmentExpression = 274,     /* AssignmentExpression  */
  YYSYMBOL_Assignment = 275,               /* Assignment  */
  YYSYMBOL_LeftHandSide = 276,             /* LeftHandSide  */
  YYSYMBOL_AssignmentOperator = 277,       /* AssignmentOperator  */
  YYSYMBOL_Expression = 278,               /* Expression  */
  YYSYMBOL_ConstantExpression = 279        /* ConstantExpression  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if 1

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
#endif /* 1 */

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

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   354


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

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
       0,   885,   885,   890,   897,   902,   907,   912,   917,   923,
     931,   958,   964,   971,   977,   984,   990,   996,  1002,  1008,
    1016,  1022,  1029,  1035,  1042,  1049,  1056,  1063,  1070,  1076,
    1083,  1089,  1096,  1137,  1180,  1182,  1184,  1186,  1188,  1190,
    1192,  1196,  1199,  1204,  1206,  1210,  1213,  1215,  1218,  1223,
    1226,  1229,  1232,  1235,  1238,  1240,  1243,  1245,  1247,  1251,
    1254,  1256,  1258,  1260,  1262,  1264,  1268,  1268,  1292,  1292,
    1328,  1328,  1364,  1364,  1388,  1388,  1412,  1412,  1449,  1449,
    1473,  1473,  1511,  1517,  1523,  1527,  1534,  1537,  1541,  1545,
    1551,  1555,  1558,  1563,  1567,  1572,  1622,  1667,  1699,  1776,
    1828,  1954,  1960,  1960,  1970,  1979,  1987,  2001,  2020,  2079,
    2137,  2191,  2244,  2295,  2345,  2399,  2451,  2465,  2480,  2484,
    2487,  2491,  2510,  2513,  2515,  2519,  2531,  2548,  2548,  2552,
    2560,  2568,  2575,  2583,  2588,  2638,  2638,  2662,  2677,  2690,
    2702,  2714,  2724,  2732,  2740,  2748,  2748,  2772,  2772,  2794,
    2794,  2812,  2812,  2834,  2839,  2846,  2851,  2858,  2862,  2868,
    2872,  2877,  2882,  2890,  2899,  2909,  2917,  2929,  2937,  2947,
    2953,  2959,  2963,  2969,  2973,  2978,  2984,  2994,  3068,  3072,
    3076,  3080,  3084,  3088,  3093,  3097,  3101,  3105,  3109,  3114,
    3118,  3122,  3126,  3130,  3134,  3138,  3142,  3146,  3150,  3154,
    3159,  3165,  3171,  3177,  3186,  3192,  3198,  3204,  3210,  3216,
    3223,  3229,  3242,  3254,  3261,  3273,  3281,  3293,  3306,  3318,
    3322,  3329,  3335,  3341,  3347,  3351,  3356,  3362,  3366,  3372,
    3378,  3383,  3400,  3410,  3420,  3429,  3446,  3456,  3466,  3479,
    3485,  3492,  3508,  3522,  3536,  3546,  3562,  3577,  3591,  3608,
    3618,  3628,  3645,  3655,  3666,  3677,  3688,  3699,  3710,  3721,
    3732,  3743,  3756,  3767,  3778,  3789,  3800,  3811,  3822,  3833,
    3845,  3847,  3851,  3855,  3857,  3861,  3874,  3892,  3908,  3923,
    3940,  3978,  3985,  3988,  3990,  3992,  3995,  3997,  4000,  4000,
    4017,  4020,  4025,  4031,  4036,  4042,  4049,  4054,  4061,  4068,
    4075,  4167,  4203,  4209,  4218,  4233,  4250,  4267,  4285,  4289,
    4294,  4302,  4309,  4316,  4330,  4337,  4345,  4495,  4551,  4603,
    4618,  4645,  4662,  4805,  4946,  4952,  4963,  4968,  4975,  5008,
    5041,  5047,  5052,  5064,  5073,  5081,  5114,  5144,  5148,  5160,
    5172,  5178,  5204,  5227,  5250,  5282,  5294,  5439,  5582,  5725,
    5731,  5875,  6019,  6026,  6045,  6066,  6084,  6090,  6119,  6149,
    6178,  6209,  6214,  6221,  6252,  6284,  6291,  6299,  6306,  6314,
    6320,  6328,  6334,  6343,  6349,  6355,  6361,  6365,  6371,  6378,
    6523,  6536,  6543,  6554,  6559,  6563,  6567,  6571,  6575,  6579,
    6583,  6587,  6591,  6595,  6600,  6611
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "BYTE", "SHORT", "INT",
  "LONG", "CHAR", "ELSE", "CATCH", "FINALLY", "INTERFACE", "PLUS",
  "FORWARDSLASH", "MODULO", "IF", "SWITCH", "IntegerLiteral",
  "FloatingPointLiteral", "BooleanLiteral", "CharacterLiteral",
  "StringLiteral", "NullLiteral", "FLOAT", "DOUBLE", "BOOLEAN", "CASE",
  "DEFAULT", "DO", "WHILE", "OPENANGULARBRACKET", "CLOSEANGULARBRACKET",
  "OPENBRACKET", "CLOSEBRACKET", "OPENCURLYBRACKET", "CLOSECURLYBRACKET",
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

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

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
       0,    16,   184,   185,    95,    96,    97,    98,    99,   100,
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

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
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

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
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

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
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


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
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
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
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
# endif
#endif

#ifndef yytnamerr
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
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
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
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
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
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
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
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
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


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  case 2: /* Goal: CompilationUnit  */
#line 885 "parser.y"
                {
  
  
}
#line 3296 "parser.tab.c"
    break;

  case 3: /* Literal: IntegerLiteral  */
#line 890 "parser.y"
               {
  // cout<<"GYO"<<stoi(($1).str)<<'\n';
  dimint=stoi(((yyvsp[0].lex)).str);
  strcpy(((yyval.typ)).tempvar,((yyvsp[0].lex)).str);
  strcpy(((yyval.typ)).type,"int");
  sz = getsz(string((char*)(((yyval.typ)).type)));
}
#line 3308 "parser.tab.c"
    break;

  case 4: /* Literal: FloatingPointLiteral  */
#line 897 "parser.y"
                       {
  strcpy(((yyval.typ)).tempvar,((yyvsp[0].lex)).str);
  strcpy(((yyval.typ)).type,"float");
  sz = getsz(string((char*)(((yyval.typ)).type)));
}
#line 3318 "parser.tab.c"
    break;

  case 5: /* Literal: BooleanLiteral  */
#line 902 "parser.y"
                 {
  strcpy(((yyval.typ)).tempvar,((yyvsp[0].lex)).str);
  strcpy(((yyval.typ)).type,"boolean");
  sz = getsz(string((char*)(((yyval.typ)).type)));
}
#line 3328 "parser.tab.c"
    break;

  case 6: /* Literal: CharacterLiteral  */
#line 907 "parser.y"
                   {
  strcpy(((yyval.typ)).tempvar,((yyvsp[0].lex)).str);
  strcpy(((yyval.typ)).type,"char");
  sz = getsz(string((char*)(((yyval.typ)).type)));
}
#line 3338 "parser.tab.c"
    break;

  case 7: /* Literal: StringLiteral  */
#line 912 "parser.y"
                {
  strcpy(((yyval.typ)).tempvar,((yyvsp[0].lex)).str);
  strcpy(((yyval.typ)).type,"string");
  sz = string((char*)(((yyvsp[0].lex)).str)).length();
}
#line 3348 "parser.tab.c"
    break;

  case 8: /* Literal: NullLiteral  */
#line 917 "parser.y"
              {
  strcpy(((yyval.typ)).tempvar,((yyvsp[0].lex)).str);
  strcpy(((yyval.typ)).type,"null");
}
#line 3357 "parser.tab.c"
    break;

  case 9: /* Type: PrimitiveType  */
#line 923 "parser.y"
               {
  strcpy(((yyval.typ)).tempvar,((yyvsp[0].typ)).tempvar);

  ((yyval.typ)).sz = ((yyvsp[0].typ)).sz;
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
  type = ((yyvsp[0].typ)).type;
  sz = ((yyvsp[0].typ)).sz;
}
#line 3370 "parser.tab.c"
    break;

  case 10: /* Type: ReferenceType  */
#line 931 "parser.y"
               {
  strcpy(((yyval.typ)).tempvar,((yyvsp[0].typ)).tempvar);

  ((yyval.typ)).sz = ((yyvsp[0].typ)).sz;
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
  type = ((yyvsp[0].typ)).type;
  sz = ((yyvsp[0].typ)).sz;
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
#line 3400 "parser.tab.c"
    break;

  case 11: /* PrimitiveType: NumericType  */
#line 958 "parser.y"
            {
  strcpy(((yyval.typ)).tempvar,((yyvsp[0].typ)).tempvar);

  ((yyval.typ)).sz = ((yyvsp[0].typ)).sz;
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
}
#line 3411 "parser.tab.c"
    break;

  case 12: /* PrimitiveType: BOOLEAN  */
#line 964 "parser.y"
         {
  strcpy(((yyval.typ)).tempvar,((yyvsp[0].lex)).str);
  
  ((yyval.typ)).sz = 1;
  strcpy(((yyval.typ)).type, "boolean");
}
#line 3422 "parser.tab.c"
    break;

  case 13: /* NumericType: IntegralType  */
#line 971 "parser.y"
             {
  strcpy(((yyval.typ)).tempvar,((yyvsp[0].typ)).tempvar);

  ((yyval.typ)).sz = ((yyvsp[0].typ)).sz;
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
}
#line 3433 "parser.tab.c"
    break;

  case 14: /* NumericType: FloatingPointType  */
#line 977 "parser.y"
                   {
  strcpy(((yyval.typ)).tempvar,((yyvsp[0].typ)).tempvar);

  ((yyval.typ)).sz = ((yyvsp[0].typ)).sz;
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
}
#line 3444 "parser.tab.c"
    break;

  case 15: /* IntegralType: BYTE  */
#line 984 "parser.y"
     {
  strcpy(((yyval.typ)).tempvar,((yyvsp[0].lex)).str);

  ((yyval.typ)).sz = 1;
  strcpy(((yyval.typ)).type, "byte"); 
}
#line 3455 "parser.tab.c"
    break;

  case 16: /* IntegralType: SHORT  */
#line 990 "parser.y"
        {
  strcpy(((yyval.typ)).tempvar,((yyvsp[0].lex)).str);

  ((yyval.typ)).sz = 2;
  strcpy(((yyval.typ)).type, "short");
}
#line 3466 "parser.tab.c"
    break;

  case 17: /* IntegralType: INT  */
#line 996 "parser.y"
      {
  strcpy(((yyval.typ)).tempvar,((yyvsp[0].lex)).str);

  ((yyval.typ)).sz = 4;
  strcpy(((yyval.typ)).type, "int");
}
#line 3477 "parser.tab.c"
    break;

  case 18: /* IntegralType: LONG  */
#line 1002 "parser.y"
      {
  strcpy(((yyval.typ)).tempvar,((yyvsp[0].lex)).str);

  ((yyval.typ)).sz = 8;
  strcpy(((yyval.typ)).type, "long");
}
#line 3488 "parser.tab.c"
    break;

  case 19: /* IntegralType: CHAR  */
#line 1008 "parser.y"
      {
  strcpy(((yyval.typ)).tempvar,((yyvsp[0].lex)).str);

  ((yyval.typ)).sz = 2;
  strcpy(((yyval.typ)).type, "char");
}
#line 3499 "parser.tab.c"
    break;

  case 20: /* FloatingPointType: FLOAT  */
#line 1016 "parser.y"
      {
  strcpy(((yyval.typ)).tempvar,((yyvsp[0].lex)).str);

  ((yyval.typ)).sz = 4;
  strcpy(((yyval.typ)).type, "float");
}
#line 3510 "parser.tab.c"
    break;

  case 21: /* FloatingPointType: DOUBLE  */
#line 1022 "parser.y"
        {
  strcpy(((yyval.typ)).tempvar,((yyvsp[0].lex)).str);

  ((yyval.typ)).sz = 8;
  strcpy(((yyval.typ)).type, "double");
}
#line 3521 "parser.tab.c"
    break;

  case 22: /* ReferenceType: ClassOrInterfaceType  */
#line 1029 "parser.y"
                     {
  strcpy(((yyval.typ)).tempvar,((yyvsp[0].typ)).tempvar);

  strcpy(((yyval.typ)).type, ((yyvsp[0].typ)).type);
  ((yyval.typ)).sz = ((yyvsp[0].typ)).sz;
}
#line 3532 "parser.tab.c"
    break;

  case 23: /* ReferenceType: ArrayType  */
#line 1035 "parser.y"
           {
  strcpy(((yyval.typ)).tempvar,((yyvsp[0].typ)).tempvar);

  strcpy(((yyval.typ)).type, ((yyvsp[0].typ)).type);
  ((yyval.typ)).sz = ((yyvsp[0].typ)).sz;
}
#line 3543 "parser.tab.c"
    break;

  case 24: /* ClassOrInterfaceType: Name  */
#line 1042 "parser.y"
     {
  strcpy(((yyval.typ)).tempvar,((yyvsp[0].typ)).tempvar);

  strcpy(((yyval.typ)).type, ((yyvsp[0].typ)).type);
  ((yyval.typ)).sz = PTR_SZ;
}
#line 3554 "parser.tab.c"
    break;

  case 25: /* ClassType: ClassOrInterfaceType  */
#line 1049 "parser.y"
                     {
  strcpy(((yyval.typ)).tempvar,((yyvsp[0].typ)).tempvar);

  strcpy(((yyval.typ)).type, ((yyvsp[0].typ)).type);
  ((yyval.typ)).sz = ((yyvsp[0].typ)).sz;
}
#line 3565 "parser.tab.c"
    break;

  case 26: /* InterfaceType: ClassOrInterfaceType  */
#line 1056 "parser.y"
                     {
  strcpy(((yyval.typ)).tempvar,((yyvsp[0].typ)).tempvar);

  strcpy(((yyval.typ)).type, ((yyvsp[0].typ)).type);
  ((yyval.typ)).sz = ((yyvsp[0].typ)).sz;
}
#line 3576 "parser.tab.c"
    break;

  case 27: /* ArrayType: PrimitiveType OPENSQUAREBRACKET CLOSESQUAREBRACKET  */
#line 1063 "parser.y"
                                                   {

  strcpy(((yyval.typ)).type,strcat(((yyvsp[-2].typ)).type,"[]"));
  strcpy(((yyval.typ)).arrtype, ((yyvsp[-2].typ)).type);
  ((yyval.typ)).ndim = 1;
  ((yyval.typ)).sz = ((yyvsp[-2].typ)).sz*((yyval.typ)).ndim;
}
#line 3588 "parser.tab.c"
    break;

  case 28: /* ArrayType: Name OPENSQUAREBRACKET CLOSESQUAREBRACKET  */
#line 1070 "parser.y"
                                           {
  strcpy(((yyval.typ)).type,strcat(((yyvsp[-2].typ)).type,"[]"));
  strcpy(((yyval.typ)).arrtype, ((yyvsp[-2].typ)).type);
  ((yyval.typ)).ndim =1;
  ((yyval.typ)).sz = ((yyvsp[-2].typ)).sz*((yyval.typ)).ndim;
}
#line 3599 "parser.tab.c"
    break;

  case 29: /* ArrayType: ArrayType OPENSQUAREBRACKET CLOSESQUAREBRACKET  */
#line 1076 "parser.y"
                                                {
  strcpy(((yyval.typ)).type,strcat(((yyvsp[-2].typ)).type,"[]"));
  strcpy(((yyval.typ)).arrtype, ((yyvsp[-2].typ)).type);
  ((yyval.typ)).ndim = ((yyvsp[-2].typ)).ndim+1;
  ((yyval.typ)).sz = ((yyvsp[-2].typ)).sz*((yyval.typ)).ndim;
}
#line 3610 "parser.tab.c"
    break;

  case 30: /* Name: SimpleName  */
#line 1083 "parser.y"
           {
   strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);

   strcpy(((yyval.typ)).type, ((yyvsp[0].typ)).type);
   ((yyval.typ)).sz = ((yyvsp[0].typ)).sz;
}
#line 3621 "parser.tab.c"
    break;

  case 31: /* Name: QualifiedName  */
#line 1089 "parser.y"
               {
  strcpy(((yyval.typ)).tempvar,((yyvsp[0].typ)).tempvar);

  strcpy(((yyval.typ)).type, ((yyvsp[0].typ)).type);
  ((yyval.typ)).sz = ((yyvsp[0].typ)).sz;
}
#line 3632 "parser.tab.c"
    break;

  case 32: /* SimpleName: Identifier  */
#line 1096 "parser.y"
           {
  // cout<<($1).str<<" scope: "<<curr_table->lookup(string((char*)($1).str)).scope_name.substr(0,6)<<'\n';
  // cout<<"KKL"<<curr_scope.substr(0,6).c_str()<<" "<<curr_scope.substr(6,curr_scope.size()-6).c_str()<<'\n';
  if(!strcmp(((yyvsp[0].lex)).str,"System")) issystem=1;
  if(curr_table->lookup(string((char*)((yyvsp[0].lex)).str)).offset==-1)
  {
    if(strcmp(((yyvsp[0].lex)).str,"String"))
    {
      if(!isimport&&!issystem) cout<<"Undeclared variable "<<((yyvsp[0].lex)).str<<" on line "<<yylineno<<'\n';
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
  // string tv8 = newtemp();
  // emit("=", "symtable.lookup(" + string((char*)($1).str) + ")","null" , tv8, -1);
  // strcpy(($$).tempvar, tv8.c_str());
  // objtotemp[string((char*)($1).str)]= tv8 ;
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].lex)).str);
  strcpy(((yyval.typ)).type, ((yyvsp[0].lex)).str);
  ((yyval.typ)).sz = (string((char*)((yyvsp[0].lex)).str)).size();
}
#line 3676 "parser.tab.c"
    break;

  case 33: /* QualifiedName: Name DOT Identifier  */
#line 1137 "parser.y"
                    {
    // cout<<"LJO"<<(char*)($1).type<<'\n';
    string mo=curr_table->lookup(string((char*)((yyvsp[-2].typ)).type)).type;
    string s = string((char*)((yyvsp[-2].typ)).type) + "." + string((char*)((yyvsp[0].lex)).str);
    string s1 = mo + "." + string((char*)((yyvsp[0].lex)).str);
    // cout<<"I was here"<<s1<<endl;
    // string tv8 = newtemp();
    // emit("=", "symtable.lookup(" + s + ")","null" , tv8, -1);
    // strcpy(($$).tempvar, tv8.c_str());
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
      if(!isimport&&!issystem) cout<<"The variable you are trying to reach is currently undefined on line "<<yylineno<<". Please try again later\n";
      // else isimport=0;
    }
    if(checkobj(s1)==1 and isclassaccess==1)
    {
      cout<<"Invalid: Accessing non static variable from static context on line "<<yylineno<<endl;
    }
    isclassaccess=0;
    // issystem=0;
    ((yyval.typ)).sz = ((yyvsp[-2].typ)).sz + 1 + (string((char*)(((yyvsp[0].lex)).str))).size();
    // cout<<"GGG"<<($$).type<<'\n';
}
#line 3723 "parser.tab.c"
    break;

  case 34: /* CompilationUnit: PackageDeclaration ImportDeclarations  */
#line 1180 "parser.y"
                                      {
}
#line 3730 "parser.tab.c"
    break;

  case 35: /* CompilationUnit: ImportDeclarations  */
#line 1182 "parser.y"
                    {
}
#line 3737 "parser.tab.c"
    break;

  case 36: /* CompilationUnit: PackageDeclaration TypeDeclarations  */
#line 1184 "parser.y"
                                     {
}
#line 3744 "parser.tab.c"
    break;

  case 37: /* CompilationUnit: TypeDeclarations  */
#line 1186 "parser.y"
                  {
}
#line 3751 "parser.tab.c"
    break;

  case 38: /* CompilationUnit: PackageDeclaration ImportDeclarations TypeDeclarations  */
#line 1188 "parser.y"
                                                        {
}
#line 3758 "parser.tab.c"
    break;

  case 39: /* CompilationUnit: ImportDeclarations TypeDeclarations  */
#line 1190 "parser.y"
                                     {
}
#line 3765 "parser.tab.c"
    break;

  case 40: /* CompilationUnit: PackageDeclaration  */
#line 1192 "parser.y"
                    { 
}
#line 3772 "parser.tab.c"
    break;

  case 41: /* ImportDeclarations: ImportDeclaration  */
#line 1196 "parser.y"
                  {
  // isimport=0;
}
#line 3780 "parser.tab.c"
    break;

  case 42: /* ImportDeclarations: ImportDeclarations ImportDeclaration  */
#line 1199 "parser.y"
                                      {
  // isimport=0;
}
#line 3788 "parser.tab.c"
    break;

  case 43: /* TypeDeclarations: TypeDeclaration  */
#line 1204 "parser.y"
                {
}
#line 3795 "parser.tab.c"
    break;

  case 44: /* TypeDeclarations: TypeDeclarations TypeDeclaration  */
#line 1206 "parser.y"
                                  {
}
#line 3802 "parser.tab.c"
    break;

  case 45: /* PackageDeclaration: PACKAGE Name SEMICOLON  */
#line 1210 "parser.y"
                       {isclassaccess=0; issystem=0;isfinal=0;     
}
#line 3809 "parser.tab.c"
    break;

  case 46: /* ImportDeclaration: SingleTypeImportDeclaration  */
#line 1213 "parser.y"
                            {
}
#line 3816 "parser.tab.c"
    break;

  case 47: /* ImportDeclaration: TypeImportOnDemandDeclaration  */
#line 1215 "parser.y"
                               {
}
#line 3823 "parser.tab.c"
    break;

  case 48: /* DummyImport: IMPORT  */
#line 1218 "parser.y"
                    {
  isimport = 1;
}
#line 3831 "parser.tab.c"
    break;

  case 49: /* SingleTypeImportDeclaration: DummyImport Name SEMICOLON  */
#line 1223 "parser.y"
                           {isclassaccess=0;issystem=0;isfinal=0;isimport=0;    
}
#line 3838 "parser.tab.c"
    break;

  case 50: /* TypeImportOnDemandDeclaration: DummyImport Name DOT STAR SEMICOLON  */
#line 1226 "parser.y"
                                    {isclassaccess=0;issystem=0;isfinal=0;isimport=0;    
}
#line 3845 "parser.tab.c"
    break;

  case 51: /* TypeDeclaration: ClassDeclaration  */
#line 1229 "parser.y"
                 {
  isimport=0;
}
#line 3853 "parser.tab.c"
    break;

  case 52: /* TypeDeclaration: InterfaceDeclaration  */
#line 1232 "parser.y"
                      {
  isimport=0;
}
#line 3861 "parser.tab.c"
    break;

  case 53: /* TypeDeclaration: SEMICOLON  */
#line 1235 "parser.y"
           {isclassaccess=0;issystem=0;isfinal=0;    
}
#line 3868 "parser.tab.c"
    break;

  case 54: /* Modifiers: Modifier  */
#line 1238 "parser.y"
         {
}
#line 3875 "parser.tab.c"
    break;

  case 55: /* Modifiers: Modifiers Modifier  */
#line 1240 "parser.y"
                    {
}
#line 3882 "parser.tab.c"
    break;

  case 56: /* Modifier: PUBLIC  */
#line 1243 "parser.y"
        {
}
#line 3889 "parser.tab.c"
    break;

  case 57: /* Modifier: PROTECTED  */
#line 1245 "parser.y"
           {
}
#line 3896 "parser.tab.c"
    break;

  case 58: /* Modifier: PRIVATE  */
#line 1247 "parser.y"
         {
  isprivate=1;
  isfieldprivate=1;
}
#line 3905 "parser.tab.c"
    break;

  case 59: /* Modifier: STATIC  */
#line 1251 "parser.y"
        {
  isstatic=1;
}
#line 3913 "parser.tab.c"
    break;

  case 60: /* Modifier: ABSTRACT  */
#line 1254 "parser.y"
          {
}
#line 3920 "parser.tab.c"
    break;

  case 61: /* Modifier: FINAL  */
#line 1256 "parser.y"
        { isfinal=1;
}
#line 3927 "parser.tab.c"
    break;

  case 62: /* Modifier: NATIVE  */
#line 1258 "parser.y"
         {
}
#line 3934 "parser.tab.c"
    break;

  case 63: /* Modifier: SYNCHRONIZED  */
#line 1260 "parser.y"
               {
}
#line 3941 "parser.tab.c"
    break;

  case 64: /* Modifier: TRANSIENT  */
#line 1262 "parser.y"
            {
}
#line 3948 "parser.tab.c"
    break;

  case 65: /* Modifier: VOLATILE  */
#line 1264 "parser.y"
          {
}
#line 3955 "parser.tab.c"
    break;

  case 66: /* $@1: %empty  */
#line 1268 "parser.y"
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
#line 3976 "parser.tab.c"
    break;

  case 67: /* ClassDeclaration: CLASS Identifier Super Interfaces $@1 ClassBody  */
#line 1284 "parser.y"
          {
  curr_table->classwidth = offset;
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  offset = offsets.top(); offsets.pop();
  objects.clear();
  emit("EndClass","","","",-1);
}
#line 3989 "parser.tab.c"
    break;

  case 68: /* $@2: %empty  */
#line 1292 "parser.y"
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
#line 4022 "parser.tab.c"
    break;

  case 69: /* ClassDeclaration: Modifiers CLASS Identifier Interfaces $@2 ClassBody  */
#line 1320 "parser.y"
          {
  curr_table->classwidth = offset;
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  offset = offsets.top(); offsets.pop();
  objects.clear();
  emit("EndClass","","","",-1);
}
#line 4035 "parser.tab.c"
    break;

  case 70: /* $@3: %empty  */
#line 1328 "parser.y"
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
#line 4068 "parser.tab.c"
    break;

  case 71: /* ClassDeclaration: Modifiers CLASS Identifier Super $@3 ClassBody  */
#line 1356 "parser.y"
          {
  curr_table->classwidth = offset;
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  offset = offsets.top(); offsets.pop();
  objects.clear();
  emit("EndClass","","","",-1);
}
#line 4081 "parser.tab.c"
    break;

  case 72: /* $@4: %empty  */
#line 1364 "parser.y"
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
#line 4102 "parser.tab.c"
    break;

  case 73: /* ClassDeclaration: CLASS Identifier Interfaces $@4 ClassBody  */
#line 1380 "parser.y"
          {
  curr_table->classwidth = offset;
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  offset = offsets.top(); offsets.pop();
  objects.clear();
  emit("EndClass","","","",-1);
}
#line 4115 "parser.tab.c"
    break;

  case 74: /* $@5: %empty  */
#line 1388 "parser.y"
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
#line 4136 "parser.tab.c"
    break;

  case 75: /* ClassDeclaration: CLASS Identifier Super $@5 ClassBody  */
#line 1404 "parser.y"
          {
  curr_table->classwidth = offset;
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  offset = offsets.top(); offsets.pop();
  objects.clear();
  emit("EndClass","","","",-1);
}
#line 4149 "parser.tab.c"
    break;

  case 76: /* $@6: %empty  */
#line 1412 "parser.y"
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
#line 4183 "parser.tab.c"
    break;

  case 77: /* ClassDeclaration: Modifiers CLASS Identifier $@6 ClassBody  */
#line 1441 "parser.y"
          {
  curr_table->classwidth = offset;
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  offset = offsets.top(); offsets.pop();
  objects.clear();
  emit("EndClass","","","",-1);
}
#line 4196 "parser.tab.c"
    break;

  case 78: /* $@7: %empty  */
#line 1449 "parser.y"
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
#line 4217 "parser.tab.c"
    break;

  case 79: /* ClassDeclaration: CLASS Identifier $@7 ClassBody  */
#line 1465 "parser.y"
          {
  curr_table->classwidth = offset;
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  offset = offsets.top(); offsets.pop();
  objects.clear();
  emit("EndClass","","","",-1);
}
#line 4230 "parser.tab.c"
    break;

  case 80: /* $@8: %empty  */
#line 1473 "parser.y"
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
#line 4264 "parser.tab.c"
    break;

  case 81: /* ClassDeclaration: Modifiers CLASS Identifier Super Interfaces $@8 ClassBody  */
#line 1502 "parser.y"
          {
  curr_table->classwidth = offset;
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  offset = offsets.top(); offsets.pop();
  objects.clear();
  emit("EndClass","","","",-1);
}
#line 4277 "parser.tab.c"
    break;

  case 82: /* Super: EXTENDS ClassType  */
#line 1511 "parser.y"
                  {
  
  
  
}
#line 4287 "parser.tab.c"
    break;

  case 83: /* Interfaces: IMPLEMENTS InterfaceTypeList  */
#line 1517 "parser.y"
                             {
  
  
  
}
#line 4297 "parser.tab.c"
    break;

  case 84: /* InterfaceTypeList: InterfaceType  */
#line 1523 "parser.y"
              {
  
  
}
#line 4306 "parser.tab.c"
    break;

  case 85: /* InterfaceTypeList: InterfaceTypeList COMMA InterfaceType  */
#line 1527 "parser.y"
                                       {
  
  
  
  
}
#line 4317 "parser.tab.c"
    break;

  case 86: /* ClassBody: OPENCURLYBRACKET ClassBodyDeclarations CLOSECURLYBRACKET  */
#line 1534 "parser.y"
                                                         {
  isprivate=0;
}
#line 4325 "parser.tab.c"
    break;

  case 87: /* ClassBody: OPENCURLYBRACKET CLOSECURLYBRACKET  */
#line 1537 "parser.y"
                                    {
  isprivate=0;
}
#line 4333 "parser.tab.c"
    break;

  case 88: /* ClassBodyDeclarations: ClassBodyDeclaration  */
#line 1541 "parser.y"
                     {
  
  
}
#line 4342 "parser.tab.c"
    break;

  case 89: /* ClassBodyDeclarations: ClassBodyDeclarations ClassBodyDeclaration  */
#line 1545 "parser.y"
                                            {
  
  
  
}
#line 4352 "parser.tab.c"
    break;

  case 90: /* ClassBodyDeclaration: ClassMemberDeclaration  */
#line 1551 "parser.y"
                       {
  
  
}
#line 4361 "parser.tab.c"
    break;

  case 91: /* ClassBodyDeclaration: StaticInitializer  */
#line 1555 "parser.y"
                   {
  isstatic=0;
}
#line 4369 "parser.tab.c"
    break;

  case 92: /* ClassBodyDeclaration: ConstructorDeclaration  */
#line 1558 "parser.y"
                        {
  
  
}
#line 4378 "parser.tab.c"
    break;

  case 93: /* ClassMemberDeclaration: FieldDeclaration  */
#line 1563 "parser.y"
                 {
  
  
}
#line 4387 "parser.tab.c"
    break;

  case 94: /* ClassMemberDeclaration: MethodDeclaration  */
#line 1567 "parser.y"
                   {
  
  
}
#line 4396 "parser.tab.c"
    break;

  case 95: /* FieldDeclaration: Modifiers Type VariableDeclarators SEMICOLON  */
#line 1572 "parser.y"
                                             { 
  newdim.clear();   
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
      // emit("=", "[ebp+" + to_string(offset + 16) + "]", "null", tempparam[i], -1);
      offset += sizeparam[i];
      curr_table->classwidth = offset;
      

      fl = 0;
      // if(isfieldprivate)
      // {
      //   (curr_table->lookup(funcparam[i].first).isprivate)=1;
      //   cout<<"YOOO"<<curr_table->lookup(funcparam[i].first).isprivate<<funcparam[i].first<<'\n';
      // }
    }
    funcargno = -1;
    funcparam.clear();
sizeparam.clear();
tempparam.clear();
  }
  isfieldprivate=0;
  isstatic=0;

}
#line 4451 "parser.tab.c"
    break;

  case 96: /* FieldDeclaration: Type VariableDeclarators SEMICOLON  */
#line 1622 "parser.y"
                                    {   
  newdim.clear(); 
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
      // emit("=", "[ebp+" + to_string(offset + 16) + "]", "null", tempparam[i], -1);
      offset += sizeparam[i];
curr_table->classwidth = offset;


      fl = 0;
    }
    funcargno = -1;
    funcparam.clear();
sizeparam.clear();
tempparam.clear();
  }
  
  
  
}
#line 4500 "parser.tab.c"
    break;

  case 97: /* VariableDeclarators: VariableDeclarator  */
#line 1667 "parser.y"
                   {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);
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
#line 4537 "parser.tab.c"
    break;

  case 98: /* VariableDeclarators: VariableDeclarators COMMA VariableDeclarator  */
#line 1699 "parser.y"
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
#line 4618 "parser.tab.c"
    break;

  case 99: /* VariableDeclarator: VariableDeclaratorId  */
#line 1776 "parser.y"
                     {
  strcpy(((yyval.typ)).tempvar,((yyvsp[0].typ)).tempvar);

  strcpy(((yyval.typ)).type,"Dishay");
//   curr_table->entry(string((char*)($1).type), "Identifier", type, offset, curr_scope, yylineno, -1);
//   offset += sz;
curr_table->classwidth = offset;

  funcparam.push_back({string((char*)((yyvsp[0].typ)).type), {type, -1}});
  sizeparam.push_back(sz);
  tempparam.push_back(string((char*)(((yyvsp[0].typ)).tempvar)));
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
#line 4674 "parser.tab.c"
    break;

  case 100: /* VariableDeclarator: VariableDeclaratorId EQUAL VariableInitializer  */
#line 1828 "parser.y"
                                                {  
  // cout<<"I was here"<<($1).type<<endl;
//   curr_table->entry(string((char*)($1).type), "Identifier", type, offset, curr_scope, yylineno, -1);
//   offset += sz;
curr_table->classwidth = offset;
 string tv5 = string((char*)(((yyvsp[0].typ)).type));
 string tv6 = "";
 int fla = 0;
 for(auto it : tv5){
  if(it == '['){
    fla = 1;
    break;
  }
  tv6.push_back(it);
 }
 if(fla == 1){
    string tv4 = newtemp();
    auto it = curr_table->lookup(string((char*)(((yyvsp[-2].typ)).type))).dims;
    int sizealloc = 1;
    for(auto ent : it){
      sizealloc *= ent;
    }
    sizealloc  = sizealloc*getsz(tv6);
    emit("=", to_string(sizealloc), "null", tv4, -1);
    emit("param",tv4,"","",-1);
    // emit("stackpointer","+" + to_string(sizealloc),"","",-1);
    emit("add", "esp", to_string(sizealloc), "", -1);
    emit("call","allocmem","1","",-1);
    // emit("stackpointer","-" + to_string(sizealloc),"","",-1);
    emit("sub", "esp", to_string(sizealloc), "", -1);
    string tv2 = newtemp();
    emit("=", "popparam", "null", tv2, -1);
    strcpy(((yyval.typ)).tempvar, tv2.c_str());
    objtotemp[string((char*)(((yyvsp[-2].typ)).type))] = tv2;;
 }
  else{
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);
  objtotemp[string((char*)(((yyvsp[-2].typ)).type))] = string((char*)(((yyvsp[0].typ)).tempvar));
  }
  // arrname=($1).type;
  // cout<<"YYYY"<<($1).type<<($3).type<<'\n';
  // emit(">=",($1).tempvar,($3).tempvar,($$).tempvar, -1);
  if(arrinit)
  {
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
    // offset = offset + addoff*getsz(tp1);
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
  sizeparam.push_back(sz);
  // cout<<($1).type<<" "<<sz<<endl;
  tempparam.push_back(string((char*)(((yyval.typ)).tempvar)));

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
#line 4804 "parser.tab.c"
    break;

  case 101: /* VariableDeclaratorId: Identifier  */
#line 1954 "parser.y"
           {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].lex)).str);

  strcpy(((yyval.typ)).type,((yyvsp[0].lex)).str);
  ndim=0;
}
#line 4815 "parser.tab.c"
    break;

  case 102: /* $@9: %empty  */
#line 1960 "parser.y"
                      {
  type  = type + "[]";
  ndim=ndim+1;
  // type = "Array";
}
#line 4825 "parser.tab.c"
    break;

  case 103: /* VariableDeclaratorId: VariableDeclaratorId $@9 OPENSQUAREBRACKET CLOSESQUAREBRACKET  */
#line 1964 "parser.y"
                                       {
  
  // ($$).ndim=ndim;
}
#line 4834 "parser.tab.c"
    break;

  case 104: /* VariableInitializer: Expression  */
#line 1970 "parser.y"
           {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);

  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
  if(!flagyo) ((yyval.typ)).ndim=0;
  else ((yyval.typ)).ndim=((yyvsp[0].typ)).ndim;
  // cout<<"YO"<<($$).ndim<<'\n';

}
#line 4848 "parser.tab.c"
    break;

  case 105: /* VariableInitializer: ArrayInitializer  */
#line 1979 "parser.y"
                  {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);

  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
  ((yyval.typ)).ndim=((yyvsp[0].typ)).ndim;
}
#line 4859 "parser.tab.c"
    break;

  case 106: /* MethodDeclaration: MethodHeader MethodBody  */
#line 1987 "parser.y"
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
#line 4878 "parser.tab.c"
    break;

  case 107: /* MethodDeclaration: MethodBody  */
#line 2001 "parser.y"
            {
  currfunc.pop();
  curr_table->classwidth = offset;
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
#line 4899 "parser.tab.c"
    break;

  case 108: /* MethodHeader: Modifiers Type MethodDeclarator Throws  */
#line 2020 "parser.y"
                                       {
// emit("BeginFunc","","","",-1);
// emit("push","ebp","","",-1);
// emit("=", "esp", "null", "ebp", -1);
  currfunc.push(string((char*)(((yyvsp[-1].typ)).type)));
    if(isvoid)
  {
    cout<<"Main function should be void return type\n";
  }
  if(ismainstatic&&!isstatic)
  {
    cout<<"Main function should be static\n";
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
      // emit("sub","esp",to_string(sizeparam[i]),"",-1);
      emit("sub", "esp", to_string(sizeparam[i]), "", -1);
totalstack += sizeparam[i];
      emit("=", "[ebp+" + to_string(offset + 16) + "]", "null", tempparam[i], -1);
      offset += sizeparam[i];
curr_table->classwidth = offset;
      fl = 0;
    }
    funcargno = -1;
    funcparam.clear();
sizeparam.clear();
tempparam.clear();
  }
  isfieldprivate=0;
  isstatic=0;

}
#line 4963 "parser.tab.c"
    break;

  case 109: /* MethodHeader: Modifiers Type MethodDeclarator  */
#line 2079 "parser.y"
                                  { 
  currfunc.push(string((char*)(((yyvsp[0].typ)).type)));
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
      // emit("sub","esp",to_string(sizeparam[i]),"",-1);
      emit("sub", "esp", to_string(sizeparam[i]), "", -1);

totalstack += sizeparam[i];
      emit("=", "[ebp+" + to_string(offset + 16) + "]", "null", tempparam[i], -1);
      offset += sizeparam[i];
curr_table->classwidth = offset;

      fl = 0;
    }
    funcargno = -1;
    funcparam.clear();
sizeparam.clear();
tempparam.clear();
  }
  isfieldprivate=0;
  isstatic=0;

}
#line 5026 "parser.tab.c"
    break;

  case 110: /* MethodHeader: Type MethodDeclarator Throws  */
#line 2137 "parser.y"
                              {
  currfunc.push(string((char*)(((yyvsp[-1].typ)).type)));
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
      // emit("sub","esp",to_string(sizeparam[i]),"",-1);
      emit("sub", "esp", to_string(sizeparam[i]), "", -1);
totalstack += sizeparam[i];
      emit("=", "[ebp+" + to_string(offset + 16) + "]", "null", tempparam[i], -1);
      offset += sizeparam[i];
curr_table->classwidth = offset;

      fl = 0;
    }
    funcargno = -1;
    funcparam.clear();
sizeparam.clear();
tempparam.clear();
  }
  
}
#line 5085 "parser.tab.c"
    break;

  case 111: /* MethodHeader: Type MethodDeclarator  */
#line 2191 "parser.y"
                       {
  currfunc.push(string((char*)(((yyvsp[0].typ)).type)));
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
      // emit("sub","esp",to_string(sizeparam[i]),"",-1);
      emit("sub", "esp", to_string(sizeparam[i]), "", -1);
totalstack += sizeparam[i];
      emit("=", "[ebp+" + to_string(offset + 16) + "]", "null", tempparam[i], -1);
      offset += sizeparam[i];
      curr_table->classwidth = offset;

      fl = 0;
    }
    funcargno = -1;
    funcparam.clear();
sizeparam.clear();
tempparam.clear();
  }
}
#line 5143 "parser.tab.c"
    break;

  case 112: /* MethodHeader: Modifiers VOID MethodDeclarator Throws  */
#line 2244 "parser.y"
                                        {
  currfunc.push(string((char*)(((yyvsp[-1].typ)).type)));
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
      // emit("sub","esp",to_string(sizeparam[i]),"",-1);
      emit("sub", "esp", to_string(sizeparam[i]), "", -1);
totalstack += sizeparam[i];
      emit("=", "[ebp+" + to_string(offset + 16) + "]", "null", tempparam[i], -1);
      offset += sizeparam[i];
curr_table->classwidth = offset;

      fl = 0;
    }
    funcargno = -1;
    funcparam.clear();
sizeparam.clear();
tempparam.clear();
  }
  isfieldprivate=0;
}
#line 5199 "parser.tab.c"
    break;

  case 113: /* MethodHeader: VOID MethodDeclarator Throws  */
#line 2295 "parser.y"
                              {
  currfunc.push(string((char*)(((yyvsp[-1].typ)).type)));
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
      // emit("sub","esp",to_string(sizeparam[i]),"",-1);
      emit("sub", "esp", to_string(sizeparam[i]), "", -1);
totalstack += sizeparam[i];
      emit("=", "[ebp+" + to_string(offset + 16) + "]", "null", tempparam[i], -1);
      offset += sizeparam[i];
curr_table->classwidth = offset;

      fl = 0;
    }
    funcargno = -1;
    funcparam.clear();
sizeparam.clear();
tempparam.clear();
  }
}
#line 5254 "parser.tab.c"
    break;

  case 114: /* MethodHeader: Modifiers VOID MethodDeclarator  */
#line 2345 "parser.y"
                                  {
  currfunc.push(string((char*)(((yyvsp[0].typ)).type)));
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
      // emit("sub","esp",to_string(sizeparam[i]),"",-1);
      emit("sub", "esp", to_string(sizeparam[i]), "", -1);
totalstack += sizeparam[i];
      emit("=", "[ebp+" + to_string(offset + 16) + "]", "null", tempparam[i], -1);
      offset += sizeparam[i];
curr_table->classwidth = offset;

      fl = 0;
    }
    funcargno = -1;
    funcparam.clear();
sizeparam.clear();
tempparam.clear();
  }
  isfieldprivate=0;
  isstatic=0;

}
#line 5313 "parser.tab.c"
    break;

  case 115: /* MethodHeader: VOID MethodDeclarator  */
#line 2399 "parser.y"
                       {
  currfunc.push(string((char*)(((yyvsp[0].typ)).type)));
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
      // emit("sub","esp",to_string(sizeparam[i]),"",-1);
      emit("sub", "esp", to_string(sizeparam[i]), "", -1);
totalstack += sizeparam[i];
      emit("=", "[ebp+" + to_string(offset + 16) + "]", "null", tempparam[i], -1);
      offset += sizeparam[i];
curr_table->classwidth = offset;

      fl = 0;
    }
    funcargno = -1;
    funcparam.clear();
sizeparam.clear();
tempparam.clear();
  }
}
#line 5368 "parser.tab.c"
    break;

  case 116: /* MethodDeclarator: Identifier OPENBRACKET CLOSEBRACKET  */
#line 2451 "parser.y"
                                    {
  emit(((yyvsp[-2].lex)).str,":","","",-1);
  emit("BeginFunc","","","",-1);
  //emit("BeginFunc",to_string(getfuncwidth(string((char*)($1).type))),"","",-1);
  emit("push","ebp","","",-1);
  emit("=", "esp", "null", "ebp", -1);
  strcpy(((yyval.typ)).type,((yyvsp[-2].lex)).str);
  ((yyval.typ)).nelem=0;
  if(!strcmp(((yyvsp[-2].lex)).str,"main"))
  {
    ismainstatic=1;
    isvoid=1;
  }
}
#line 5387 "parser.tab.c"
    break;

  case 117: /* MethodDeclarator: Identifier OPENBRACKET FormalParameterList CLOSEBRACKET  */
#line 2465 "parser.y"
                                                         {
  emit(((yyvsp[-3].lex)).str,":","","",-1);

  emit("BeginFunc","","","",-1);
  emit("push","ebp","","",-1);
  emit("=", "esp", "null", "ebp", -1);

  strcpy(((yyval.typ)).type,((yyvsp[-3].lex)).str);
  ((yyval.typ)).nelem=((yyvsp[-1].typ)).nelem;
  if(!strcmp(((yyvsp[-3].lex)).str,"main"))
  {
    ismainstatic=1;
    isvoid=1;
  }
}
#line 5407 "parser.tab.c"
    break;

  case 118: /* MethodDeclarator: MethodDeclarator OPENSQUAREBRACKET CLOSESQUAREBRACKET  */
#line 2480 "parser.y"
                                                       {

}
#line 5415 "parser.tab.c"
    break;

  case 119: /* FormalParameterList: FormalParameter  */
#line 2484 "parser.y"
                {
  ((yyval.typ)).nelem=1;
}
#line 5423 "parser.tab.c"
    break;

  case 120: /* FormalParameterList: FormalParameterList COMMA FormalParameter  */
#line 2487 "parser.y"
                                           {
  ((yyval.typ)).nelem=((yyvsp[-2].typ)).nelem+1;
}
#line 5431 "parser.tab.c"
    break;

  case 121: /* FormalParameter: Type VariableDeclaratorId  */
#line 2491 "parser.y"
                          {
  strcpy(((yyval.typ)).tempvar,((yyvsp[0].typ)).tempvar);
  ((yyval.typ)).ndim=ndim;
  ndim=0;
//   curr_table->entry(string((char*)($2).type), "Identifier", type, offset, curr_scope, yylineno, -1);
//   offset += sz;
  // cout<<"Type: "<<type<<'\n';
  if(funcargno == -1){
    funcargno = 1;
  }
  else{
    funcargno++;
  }
//   cout<<"Funcarg: "<<funcargno<<' '<<endl;
  funcparam.push_back({string((char*)((yyvsp[0].typ)).type), {type, funcargno}});
  sizeparam.push_back(sz);
  tempparam.push_back(string((char*)(((yyvsp[0].typ)).tempvar)));
}
#line 5454 "parser.tab.c"
    break;

  case 122: /* Throws: THROWS ClassTypeList  */
#line 2510 "parser.y"
                     {
}
#line 5461 "parser.tab.c"
    break;

  case 123: /* ClassTypeList: ClassType  */
#line 2513 "parser.y"
           {
}
#line 5468 "parser.tab.c"
    break;

  case 124: /* ClassTypeList: ClassTypeList COMMA ClassType  */
#line 2515 "parser.y"
                               {
}
#line 5475 "parser.tab.c"
    break;

  case 125: /* MethodBody: Block  */
#line 2519 "parser.y"
       {
    if(ispopped == 1){
    if(totalstack != 0){ emit("add", "esp", to_string(totalstack), "", -1); ;}
emit("pop","ebp","","",-1);
    ispopped = 0;totalstack = 0;
emit("ret","","","",-1);
  }
  emit("EndFunc","","","",-1);
  ispopped = 1;
  
  infunction=1;
}
#line 5492 "parser.tab.c"
    break;

  case 126: /* MethodBody: SEMICOLON  */
#line 2531 "parser.y"
           {   
  newdim.clear(); 
    if(ispopped == 1){
    if(totalstack != 0){ emit("add", "esp", to_string(totalstack), "", -1); ;}
emit("pop","ebp","","",-1);
    ispopped = 0;totalstack = 0;
emit("ret","","","",-1);
  }
  emit("EndFunc","","","",-1);
  ispopped = 1;
  
  infunction=1;
  isclassaccess=0;
  isfinal=0;
  issystem=0;
}
#line 5513 "parser.tab.c"
    break;

  case 127: /* $@10: %empty  */
#line 2548 "parser.y"
       {isstatic=1;}
#line 5519 "parser.tab.c"
    break;

  case 128: /* StaticInitializer: STATIC $@10 Block  */
#line 2548 "parser.y"
                           {
  // cout<<"YIS"<<isstatic<<'\n';
}
#line 5527 "parser.tab.c"
    break;

  case 129: /* ConstructorDeclaration: Modifiers ConstructorDeclarator Throws ConstructorBody  */
#line 2552 "parser.y"
                                                       {
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  offset = offsets.top(); offsets.pop();
  isfieldprivate=0;
  nelem=0;
  
}
#line 5540 "parser.tab.c"
    break;

  case 130: /* ConstructorDeclaration: Modifiers ConstructorDeclarator ConstructorBody  */
#line 2560 "parser.y"
                                                 {
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  offset = offsets.top(); offsets.pop();
  isfieldprivate=0;
  nelem=0;
  
}
#line 5553 "parser.tab.c"
    break;

  case 131: /* ConstructorDeclaration: ConstructorDeclarator Throws ConstructorBody  */
#line 2568 "parser.y"
                                              {
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  offset = offsets.top(); offsets.pop();
  nelem=0;
  
}
#line 5565 "parser.tab.c"
    break;

  case 132: /* ConstructorDeclaration: ConstructorDeclarator ConstructorBody  */
#line 2575 "parser.y"
                                       {
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  offset = offsets.top(); offsets.pop();
  nelem=0;
  
}
#line 5577 "parser.tab.c"
    break;

  case 133: /* ConstructorHeader: SimpleName OPENBRACKET  */
#line 2583 "parser.y"
                                         {
  emit("BeginCtor","","","",-1);
}
#line 5585 "parser.tab.c"
    break;

  case 134: /* ConstructorDeclarator: ConstructorHeader FormalParameterList CLOSEBRACKET  */
#line 2588 "parser.y"
                                                   {
  emit("push","ebp","","",-1);
  emit("=", "esp", "null", "ebp", -1);
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
      emit("sub","esp",to_string(sizeparam[i]),"",-1);
      totalstack += sizeparam[i];
      emit("=", "[ebp+" + to_string(offset + 16) + "]", "null", tempparam[i], -1);
      offset += sizeparam[i];
      curr_table->classwidth = offset;

      fl = 0;
    }
    funcargno = -1;
    funcparam.clear();
sizeparam.clear();
tempparam.clear();
  }
  nelem=0;
}
#line 5640 "parser.tab.c"
    break;

  case 135: /* $@11: %empty  */
#line 2638 "parser.y"
                        {
  emit("BeginCtor","","","",-1);
  emit("push","ebp","","",-1);
  emit("=", "esp", "null", "ebp", -1);
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
#line 5661 "parser.tab.c"
    break;

  case 136: /* ConstructorDeclarator: SimpleName OPENBRACKET $@11 CLOSEBRACKET  */
#line 2654 "parser.y"
             {
  
  
  
  
}
#line 5672 "parser.tab.c"
    break;

  case 137: /* ConstructorBody: OPENCURLYBRACKET ExplicitConstructorInvocation BlockStatements CLOSECURLYBRACKET  */
#line 2662 "parser.y"
                                                                                 {
  
  if(ispopped == 1){
    if(totalstack != 0){ emit("add", "esp", to_string(totalstack), "", -1); ;}
emit("pop","ebp","","",-1);
    ispopped = 0;totalstack = 0;
emit("ret","","","",-1);
  }
  emit("EndCtor","","","",-1);
  ispopped = 1;
  
  
  
  
}
#line 5692 "parser.tab.c"
    break;

  case 138: /* ConstructorBody: OPENCURLYBRACKET BlockStatements CLOSECURLYBRACKET  */
#line 2677 "parser.y"
                                                    {
  
  if(ispopped == 1){
    if(totalstack != 0){ emit("add", "esp", to_string(totalstack), "", -1); ;}
emit("pop","ebp","","",-1);
    ispopped = 0;totalstack = 0;
emit("ret","","","",-1);
  }
  emit("EndCtor","","","",-1);
  ispopped = 1;
  
  
}
#line 5710 "parser.tab.c"
    break;

  case 139: /* ConstructorBody: OPENCURLYBRACKET ExplicitConstructorInvocation CLOSECURLYBRACKET  */
#line 2690 "parser.y"
                                                                  {
  
  if(ispopped == 1){
    if(totalstack != 0){ emit("add", "esp", to_string(totalstack), "", -1); ;}
emit("pop","ebp","","",-1);
    ispopped = 0;totalstack = 0;
emit("ret","","","",-1);
  }
  emit("EndCtor","","","",-1);
  ispopped = 1;
  
}
#line 5727 "parser.tab.c"
    break;

  case 140: /* ConstructorBody: OPENCURLYBRACKET CLOSECURLYBRACKET  */
#line 2702 "parser.y"
                                    {
  
  if(ispopped == 1){
    if(totalstack != 0){ emit("add", "esp", to_string(totalstack), "", -1); ;}
emit("pop","ebp","","",-1);
    ispopped = 0;totalstack = 0;
emit("ret","","","",-1);
  }
  emit("EndCtor","","","",-1);
  ispopped = 1;
}
#line 5743 "parser.tab.c"
    break;

  case 141: /* ExplicitConstructorInvocation: THIS OPENBRACKET ArgumentList CLOSEBRACKET SEMICOLON  */
#line 2714 "parser.y"
                                                     {    
  newdim.clear();
  isclassaccess=0;
  isfinal=0;
  issystem=0;
  
  
  
  
}
#line 5758 "parser.tab.c"
    break;

  case 142: /* ExplicitConstructorInvocation: THIS OPENBRACKET CLOSEBRACKET SEMICOLON  */
#line 2724 "parser.y"
                                         {    
  isclassaccess=0;
  newdim.clear();
  isfinal=0;
  issystem=0;
  
  
}
#line 5771 "parser.tab.c"
    break;

  case 143: /* ExplicitConstructorInvocation: SUPER OPENBRACKET ArgumentList CLOSEBRACKET SEMICOLON  */
#line 2732 "parser.y"
                                                       {    
    isclassaccess=0;
  issystem=0;
  newdim.clear();
  
  isfinal=0;
  
}
#line 5784 "parser.tab.c"
    break;

  case 144: /* ExplicitConstructorInvocation: SUPER OPENBRACKET CLOSEBRACKET SEMICOLON  */
#line 2740 "parser.y"
                                          {    
    isclassaccess=0;
  issystem=0;
  newdim.clear();
  isfinal=0;
  
}
#line 5796 "parser.tab.c"
    break;

  case 145: /* $@12: %empty  */
#line 2748 "parser.y"
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
#line 5814 "parser.tab.c"
    break;

  case 146: /* InterfaceDeclaration: Modifiers INTERFACE Identifier ExtendsInterfaces $@12 InterfaceBody  */
#line 2761 "parser.y"
              {
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  offset = offsets.top(); offsets.pop();
  
  
  
  
  
  
}
#line 5830 "parser.tab.c"
    break;

  case 147: /* $@13: %empty  */
#line 2772 "parser.y"
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
#line 5847 "parser.tab.c"
    break;

  case 148: /* InterfaceDeclaration: INTERFACE Identifier ExtendsInterfaces $@13 InterfaceBody  */
#line 2784 "parser.y"
              {
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  offset = offsets.top(); offsets.pop();
  
  
  
  
  
}
#line 5862 "parser.tab.c"
    break;

  case 149: /* $@14: %empty  */
#line 2794 "parser.y"
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
#line 5880 "parser.tab.c"
    break;

  case 150: /* InterfaceDeclaration: Modifiers INTERFACE Identifier $@14 InterfaceBody  */
#line 2807 "parser.y"
              {
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  offset = offsets.top(); offsets.pop();
}
#line 5890 "parser.tab.c"
    break;

  case 151: /* $@15: %empty  */
#line 2812 "parser.y"
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
#line 5907 "parser.tab.c"
    break;

  case 152: /* InterfaceDeclaration: INTERFACE Identifier $@15 InterfaceBody  */
#line 2824 "parser.y"
              {
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  offset = offsets.top(); offsets.pop();
  
  
  
  
}
#line 5921 "parser.tab.c"
    break;

  case 153: /* ExtendsInterfaces: EXTENDS InterfaceType  */
#line 2834 "parser.y"
                      {
  
  
  
  }
#line 5931 "parser.tab.c"
    break;

  case 154: /* ExtendsInterfaces: ExtendsInterfaces COMMA InterfaceType  */
#line 2839 "parser.y"
                                       {
  
  
  
  
  }
#line 5942 "parser.tab.c"
    break;

  case 155: /* InterfaceBody: OPENCURLYBRACKET CLOSECURLYBRACKET  */
#line 2846 "parser.y"
                                   {
  
  
  
  }
#line 5952 "parser.tab.c"
    break;

  case 156: /* InterfaceBody: OPENCURLYBRACKET InterfaceMemberDeclarations CLOSECURLYBRACKET  */
#line 2851 "parser.y"
                                                                {
  
  
  
  
  }
#line 5963 "parser.tab.c"
    break;

  case 157: /* InterfaceMemberDeclarations: InterfaceMemberDeclaration  */
#line 2858 "parser.y"
                           {
  
  
  }
#line 5972 "parser.tab.c"
    break;

  case 158: /* InterfaceMemberDeclarations: InterfaceMemberDeclarations InterfaceMemberDeclaration  */
#line 2862 "parser.y"
                                                        {
  
  
  
  }
#line 5982 "parser.tab.c"
    break;

  case 159: /* InterfaceMemberDeclaration: ConstantDeclaration  */
#line 2868 "parser.y"
                    {
  
  
  }
#line 5991 "parser.tab.c"
    break;

  case 160: /* InterfaceMemberDeclaration: AbstractMethodDeclaration  */
#line 2872 "parser.y"
                           {
  
  
  }
#line 6000 "parser.tab.c"
    break;

  case 161: /* ConstantDeclaration: FieldDeclaration  */
#line 2877 "parser.y"
                 {
  
  
  }
#line 6009 "parser.tab.c"
    break;

  case 162: /* AbstractMethodDeclaration: MethodHeader SEMICOLON  */
#line 2882 "parser.y"
                       {    
  newdim.clear();
  isfinal=0;
  isclassaccess=0;
    issystem=0;
}
#line 6020 "parser.tab.c"
    break;

  case 163: /* ArrayInitializer: OPENCURLYBRACKET VariableInitializers COMMA CLOSECURLYBRACKET  */
#line 2890 "parser.y"
                                                              {
  strcpy(((yyval.typ)).tempvar, strcat(((yyvsp[-3].lex)).str, strcat(((yyvsp[-2].typ)).tempvar, strcat(((yyvsp[-1].lex)).str, ((yyvsp[0].lex)).str))));
  arrinit=1;
  strcpy(((yyval.typ)).type,((yyvsp[-2].typ)).type);
  // ($$).nelem=($2).nelem;
  ((yyval.typ)).ndim=((yyvsp[-2].typ)).ndim+1;
  shape[((yyval.typ)).ndim].push_back(((yyvsp[-2].typ)).nelem);
  // cout<<($$).ndim<<'\n';
}
#line 6034 "parser.tab.c"
    break;

  case 164: /* ArrayInitializer: OPENCURLYBRACKET COMMA CLOSECURLYBRACKET  */
#line 2899 "parser.y"
                                          {
  strcpy(((yyval.typ)).tempvar, strcat(((yyvsp[-2].lex)).str, strcat(((yyvsp[-1].lex)).str, ((yyvsp[0].lex)).str)));
  arrinit=1;
  strcpy(((yyval.typ)).type,"Dishay");
  // ($$).nelem=0;
  ((yyval.typ)).ndim=1;
  shape[((yyval.typ)).ndim].push_back(0);
  // cout<<($$).ndim<<'\n';
  
  }
#line 6049 "parser.tab.c"
    break;

  case 165: /* ArrayInitializer: OPENCURLYBRACKET VariableInitializers CLOSECURLYBRACKET  */
#line 2909 "parser.y"
                                                         {
  strcpy(((yyval.typ)).tempvar, strcat(((yyvsp[-2].lex)).str, strcat(((yyvsp[-1].typ)).tempvar, ((yyvsp[0].lex)).str)));
  arrinit=1;
  strcpy(((yyval.typ)).type,((yyvsp[-1].typ)).type);
  // ($$).nelem=($2).nelem;
  ((yyval.typ)).ndim=((yyvsp[-1].typ)).ndim+1;
  shape[((yyval.typ)).ndim].push_back(((yyvsp[-1].typ)).nelem);
  }
#line 6062 "parser.tab.c"
    break;

  case 166: /* ArrayInitializer: OPENCURLYBRACKET CLOSECURLYBRACKET  */
#line 2917 "parser.y"
                                    {
  strcpy(((yyval.typ)).tempvar, strcat(((yyvsp[-1].lex)).str, ((yyvsp[0].lex)).str));
  arrinit=1;
  strcpy(((yyval.typ)).type,"Dishay");
  // ($$).nelem=0;
  ((yyval.typ)).ndim=1;
  shape[((yyval.typ)).ndim].push_back(0);
  // cout<<"OPENCURLYBRACKET CLOSECURLYBRACKET"<<($$).ndim<<'\n';
  
  
  }
#line 6078 "parser.tab.c"
    break;

  case 167: /* VariableInitializers: VariableInitializer  */
#line 2929 "parser.y"
                    {
  strcpy(((yyval.typ)).tempvar,((yyvsp[0].typ)).tempvar);
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
  ((yyval.typ)).ndim=((yyvsp[0].typ)).ndim;
  // shape[($1).ndim+1].back()+=1;
  ((yyval.typ)).nelem=1;
  
  }
#line 6091 "parser.tab.c"
    break;

  case 168: /* VariableInitializers: VariableInitializers COMMA VariableInitializer  */
#line 2937 "parser.y"
                                                {
  strcpy(((yyval.typ)).tempvar, strcat(strcat(((yyvsp[-2].typ)).tempvar,","),((yyvsp[0].typ)).tempvar));
  strcpy(((yyval.typ)).type,getorder(((yyvsp[-2].typ)).type,((yyvsp[0].typ)).type,1).c_str());
  ((yyval.typ)).ndim=((yyvsp[-2].typ)).ndim;
  // shape[($1).ndim+1].back()+=1;
  ((yyval.typ)).nelem=((yyvsp[-2].typ)).nelem+1;
  // cout<<"types "<<($1).type<<" "<<($3).type<<" "<<($$).type<<'\n';
  
  }
#line 6105 "parser.tab.c"
    break;

  case 169: /* Block: OPENCURLYBRACKET BlockStatements CLOSECURLYBRACKET  */
#line 2947 "parser.y"
                                                   {
  
  
  
  
  }
#line 6116 "parser.tab.c"
    break;

  case 170: /* Block: OPENCURLYBRACKET CLOSECURLYBRACKET  */
#line 2953 "parser.y"
                                    {
  
  
  
  }
#line 6126 "parser.tab.c"
    break;

  case 171: /* BlockStatements: BlockStatement  */
#line 2959 "parser.y"
               {
  
  
  }
#line 6135 "parser.tab.c"
    break;

  case 172: /* BlockStatements: BlockStatements BlockStatement  */
#line 2963 "parser.y"
                                {
  
  
  
  }
#line 6145 "parser.tab.c"
    break;

  case 173: /* BlockStatement: LocalVariableDeclarationStatement  */
#line 2969 "parser.y"
                                  {
  
  
  }
#line 6154 "parser.tab.c"
    break;

  case 174: /* BlockStatement: Statement  */
#line 2973 "parser.y"
           {
  
  
  }
#line 6163 "parser.tab.c"
    break;

  case 175: /* LocalVariableDeclarationStatement: LocalVariableDeclaration SEMICOLON  */
#line 2978 "parser.y"
                                   {    
  newdim.clear();
  isclassaccess=0;
  type="";
    issystem=0;
  }
#line 6174 "parser.tab.c"
    break;

  case 176: /* LocalVariableDeclarationStatement: FINAL LocalVariableDeclaration SEMICOLON  */
#line 2985 "parser.y"
{    
  newdim.clear();
   isclassaccess=0;
  type="";
    issystem=0;
    isfinal=0;
}
#line 6186 "parser.tab.c"
    break;

  case 177: /* LocalVariableDeclaration: Type VariableDeclarators  */
#line 2994 "parser.y"
                         {
  // cout<<($1).type<<($2).type<<'\n';
  // cout<<"GHF"<<isstatic<<'\n';
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);
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
      // cout<<funcparam[i].first<<endl;
      if(fl == 0)
      curr_table->entry(funcparam[i].first, "Identifier", funcparam[i].second.first, offset, curr_scope, yylineno, funcparam[i].second.second);
      else 
      curr_table->entry(funcparam[i].first, "Array", funcparam[i].second.first, offset, curr_scope, yylineno, funcparam[i].second.second);
      emit("sub","esp",to_string(sizeparam[i]),"",-1);
totalstack += sizeparam[i];
      if(-(offset - funcargtypesz(1, currfunc.top())) - 4 < 0)
      emit("=", tempparam[i] , "null",  "[ebp" + to_string(-(offset - funcargtypesz(1, currfunc.top())) - 4) + "]" , -1);
      else{
        emit("=", tempparam[i] , "null",  "[ebp+" + to_string(-(offset - funcargtypesz(1, currfunc.top())) - 4) + "]" , -1);
      }

      offset += sizeparam[i];
      // cout<<"fbrfgruifhriufg "<<offset - funcargtypesz(1, currfunc.top()) - 4<<endl;
      curr_table->classwidth = offset;
      if(newhandle != "null"){
        offset = offset - getsz(newhandle) + PTR_SZ;
        newhandle = "null";
      }

      fl = 0;
    }
    funcargno = -1;
    funcparam.clear();
sizeparam.clear();
tempparam.clear();
  }
  }
#line 6264 "parser.tab.c"
    break;

  case 178: /* Statement: StatementWithoutTrailingSubstatement  */
#line 3068 "parser.y"
                                     {
  
  
  }
#line 6273 "parser.tab.c"
    break;

  case 179: /* Statement: LabeledStatement  */
#line 3072 "parser.y"
                  {
  
  
  }
#line 6282 "parser.tab.c"
    break;

  case 180: /* Statement: IfThenStatement  */
#line 3076 "parser.y"
                 {
  
  
  }
#line 6291 "parser.tab.c"
    break;

  case 181: /* Statement: IfThenElseStatement  */
#line 3080 "parser.y"
                     {
  
  
  }
#line 6300 "parser.tab.c"
    break;

  case 182: /* Statement: WhileStatement  */
#line 3084 "parser.y"
                {
  
  
  }
#line 6309 "parser.tab.c"
    break;

  case 183: /* Statement: ForStatement  */
#line 3088 "parser.y"
              {
  
  
  }
#line 6318 "parser.tab.c"
    break;

  case 184: /* StatementNoShortIf: StatementWithoutTrailingSubstatement  */
#line 3093 "parser.y"
                                     {
  
  
  }
#line 6327 "parser.tab.c"
    break;

  case 185: /* StatementNoShortIf: LabeledStatementNoShortIf  */
#line 3097 "parser.y"
                           {
  
  
  }
#line 6336 "parser.tab.c"
    break;

  case 186: /* StatementNoShortIf: IfThenElseStatementNoShortIf  */
#line 3101 "parser.y"
                              {
  
  
  }
#line 6345 "parser.tab.c"
    break;

  case 187: /* StatementNoShortIf: WhileStatementNoShortIf  */
#line 3105 "parser.y"
                         {
  
  
  }
#line 6354 "parser.tab.c"
    break;

  case 188: /* StatementNoShortIf: ForStatementNoShortIf  */
#line 3109 "parser.y"
                       {
  
  
  }
#line 6363 "parser.tab.c"
    break;

  case 189: /* StatementWithoutTrailingSubstatement: Block  */
#line 3114 "parser.y"
      {
  
  
  }
#line 6372 "parser.tab.c"
    break;

  case 190: /* StatementWithoutTrailingSubstatement: EmptyStatement  */
#line 3118 "parser.y"
                {
  
  
  }
#line 6381 "parser.tab.c"
    break;

  case 191: /* StatementWithoutTrailingSubstatement: ExpressionStatement  */
#line 3122 "parser.y"
                     {
  
  
  }
#line 6390 "parser.tab.c"
    break;

  case 192: /* StatementWithoutTrailingSubstatement: SwitchStatement  */
#line 3126 "parser.y"
                 {
  
  
  }
#line 6399 "parser.tab.c"
    break;

  case 193: /* StatementWithoutTrailingSubstatement: DoStatement  */
#line 3130 "parser.y"
             {
  
  
  }
#line 6408 "parser.tab.c"
    break;

  case 194: /* StatementWithoutTrailingSubstatement: BreakStatement  */
#line 3134 "parser.y"
                {
  
  
  }
#line 6417 "parser.tab.c"
    break;

  case 195: /* StatementWithoutTrailingSubstatement: ContinueStatement  */
#line 3138 "parser.y"
                   {
  
  
  }
#line 6426 "parser.tab.c"
    break;

  case 196: /* StatementWithoutTrailingSubstatement: ReturnStatement  */
#line 3142 "parser.y"
                 {
  
  
  }
#line 6435 "parser.tab.c"
    break;

  case 197: /* StatementWithoutTrailingSubstatement: SynchronizedStatement  */
#line 3146 "parser.y"
                       {
  
  
  }
#line 6444 "parser.tab.c"
    break;

  case 198: /* StatementWithoutTrailingSubstatement: ThrowStatement  */
#line 3150 "parser.y"
                {
  
  
  }
#line 6453 "parser.tab.c"
    break;

  case 199: /* StatementWithoutTrailingSubstatement: TryStatement  */
#line 3154 "parser.y"
              {
  
  
  }
#line 6462 "parser.tab.c"
    break;

  case 200: /* EmptyStatement: SEMICOLON  */
#line 3159 "parser.y"
          {    
    issystem=0;
  isclassaccess=0;
  isfinal=0;
}
#line 6472 "parser.tab.c"
    break;

  case 201: /* LabeledStatement: Identifier COLON Statement  */
#line 3165 "parser.y"
                           {
  if(curr_table->lookup(string((char*)((yyvsp[-2].lex)).str)).offset == -1  && checkobj(string((char*)((yyvsp[-2].lex)).str)) == 0){
    cout<<"Undeclared variable on line "<< yylineno<<"\n";
  }
}
#line 6482 "parser.tab.c"
    break;

  case 202: /* LabeledStatementNoShortIf: Identifier COLON StatementNoShortIf  */
#line 3171 "parser.y"
                                    {
  if(curr_table->lookup(string((char*)((yyvsp[-2].lex)).str)).offset == -1 && checkobj(string((char*)((yyvsp[-2].lex)).str)) == 0){
    cout<<"Undeclared variable on line "<< yylineno<<"\n";
  }
  }
#line 6492 "parser.tab.c"
    break;

  case 203: /* ExpressionStatement: StatementExpression SEMICOLON  */
#line 3177 "parser.y"
                              {    
  newdim.clear();
  strcpy(((yyval.typ)).type,((yyvsp[-1].typ)).type);
  strcpy(((yyval.typ)).tempvar, ((yyvsp[-1].typ)).tempvar);
    issystem=0;
  isclassaccess=0;
  isfinal=0;
  }
#line 6505 "parser.tab.c"
    break;

  case 204: /* StatementExpression: Assignment  */
#line 3186 "parser.y"
           {
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);
  
  
  }
#line 6516 "parser.tab.c"
    break;

  case 205: /* StatementExpression: PreIncrementExpression  */
#line 3192 "parser.y"
                        {
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);
  
  
  }
#line 6527 "parser.tab.c"
    break;

  case 206: /* StatementExpression: PreDecrementExpression  */
#line 3198 "parser.y"
                        {
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);
  
  
  }
#line 6538 "parser.tab.c"
    break;

  case 207: /* StatementExpression: PostIncrementExpression  */
#line 3204 "parser.y"
                         {
  
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);
  
  }
#line 6549 "parser.tab.c"
    break;

  case 208: /* StatementExpression: PostDecrementExpression  */
#line 3210 "parser.y"
                         {
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);
  
  
  }
#line 6560 "parser.tab.c"
    break;

  case 209: /* StatementExpression: MethodInvocation  */
#line 3216 "parser.y"
                  {
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);
  

  
  }
#line 6572 "parser.tab.c"
    break;

  case 210: /* StatementExpression: ClassInstanceCreationExpression  */
#line 3223 "parser.y"
                                 {
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);
  
  
  }
#line 6583 "parser.tab.c"
    break;

  case 211: /* DummyIfStatement: IF OPENBRACKET  */
#line 3229 "parser.y"
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
#line 6600 "parser.tab.c"
    break;

  case 212: /* DummyElseStatement: ELSE  */
#line 3242 "parser.y"
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
#line 6616 "parser.tab.c"
    break;

  case 213: /* DummyIfStatement1: DummyIfStatement Expression  */
#line 3254 "parser.y"
                                               {
  string a = newLabel();
  emit("Goto", ((yyvsp[0].typ)).tempvar, a, "Ifz", -1);
  strcpy(((yyval.typ)).gotoname,a.c_str());
}
#line 6626 "parser.tab.c"
    break;

  case 214: /* IfThenStatement: DummyIfStatement1 CLOSEBRACKET Statement  */
#line 3261 "parser.y"
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
#line 6642 "parser.tab.c"
    break;

  case 215: /* DummyIfStatement2: DummyIfStatement1 CLOSEBRACKET StatementNoShortIf  */
#line 3273 "parser.y"
                                                                     {
  string a = newLabel();
  emit("Goto", "", a, "", -1);
  emit(((yyvsp[-2].typ)).gotoname, ":", "", "", -1);
  strcpy(((yyval.typ)).gotoname,a.c_str());
}
#line 6653 "parser.tab.c"
    break;

  case 216: /* IfThenElseStatement: DummyIfStatement2 DummyElseStatement Statement  */
#line 3281 "parser.y"
                                               {
  emit(((yyvsp[-2].typ)).gotoname, ":", "", "", -1);

  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  offset = offsets.top(); offsets.pop();
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  offset = offsets.top(); offsets.pop();
  
  }
#line 6669 "parser.tab.c"
    break;

  case 217: /* IfThenElseStatementNoShortIf: DummyIfStatement2 DummyElseStatement StatementNoShortIf  */
#line 3293 "parser.y"
                                                        {
  emit(((yyvsp[-2].typ)).gotoname, ":", "", "", -1);

  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  offset = offsets.top(); offsets.pop();
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  offset = offsets.top(); offsets.pop();
  }
#line 6684 "parser.tab.c"
    break;

  case 218: /* DummySwitchStatement: SWITCH  */
#line 3306 "parser.y"
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
#line 6700 "parser.tab.c"
    break;

  case 219: /* SwitchStatement: DummySwitchStatement OPENBRACKET Expression CLOSEBRACKET SwitchBlock  */
#line 3318 "parser.y"
                                                                     {

  }
#line 6708 "parser.tab.c"
    break;

  case 220: /* SwitchBlock: OPENCURLYBRACKET SwitchBlockStatementGroups SwitchLabels CLOSECURLYBRACKET  */
#line 3322 "parser.y"
                                                                           {
  
  
  
  
  
  }
#line 6720 "parser.tab.c"
    break;

  case 221: /* SwitchBlock: OPENCURLYBRACKET SwitchLabels CLOSECURLYBRACKET  */
#line 3329 "parser.y"
                                                 {
  
  
  
  
  }
#line 6731 "parser.tab.c"
    break;

  case 222: /* SwitchBlock: OPENCURLYBRACKET SwitchBlockStatementGroups CLOSECURLYBRACKET  */
#line 3335 "parser.y"
                                                               {
  
  
  
  
  }
#line 6742 "parser.tab.c"
    break;

  case 223: /* SwitchBlock: OPENCURLYBRACKET CLOSECURLYBRACKET  */
#line 3341 "parser.y"
                                    {
  
  
  
  }
#line 6752 "parser.tab.c"
    break;

  case 224: /* SwitchBlockStatementGroups: SwitchBlockStatementGroup  */
#line 3347 "parser.y"
                          {
  
  
  }
#line 6761 "parser.tab.c"
    break;

  case 225: /* SwitchBlockStatementGroups: SwitchBlockStatementGroups SwitchBlockStatementGroup  */
#line 3351 "parser.y"
                                                      {

  
  }
#line 6770 "parser.tab.c"
    break;

  case 226: /* SwitchBlockStatementGroup: SwitchLabels BlockStatements  */
#line 3356 "parser.y"
                             {
  
  
  
  }
#line 6780 "parser.tab.c"
    break;

  case 227: /* SwitchLabels: SwitchLabel  */
#line 3362 "parser.y"
             {
  
  
  }
#line 6789 "parser.tab.c"
    break;

  case 228: /* SwitchLabels: SwitchLabels SwitchLabel  */
#line 3366 "parser.y"
                          {
  
  
  
  }
#line 6799 "parser.tab.c"
    break;

  case 229: /* SwitchLabel: CASE ConstantExpression COLON  */
#line 3372 "parser.y"
                              {
  
  
  
  
  }
#line 6810 "parser.tab.c"
    break;

  case 230: /* SwitchLabel: DEFAULT COLON  */
#line 3378 "parser.y"
               {
  
  
  
  }
#line 6820 "parser.tab.c"
    break;

  case 231: /* DummyWhileStatement: WHILE  */
#line 3383 "parser.y"
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
#line 6841 "parser.tab.c"
    break;

  case 232: /* DummyWhileStatement1: DummyWhileStatement OPENBRACKET Expression  */
#line 3400 "parser.y"
                                                                 {
  string a = newLabel();
  emit("Goto", ((yyvsp[0].typ)).tempvar, a, "Ifz", -1);
  strcpy(((yyval.typ)).gotoname,a.c_str());
  strcpy(((yyval.typ)).nextgoto,((yyvsp[-2].typ)).gotoname);
  // emit(($1).gotoname, ":", "", "", -1);
  breaklabels.push(a);
}
#line 6854 "parser.tab.c"
    break;

  case 233: /* WhileStatement: DummyWhileStatement1 CLOSEBRACKET Statement  */
#line 3410 "parser.y"
                                            {
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  offset = offsets.top(); offsets.pop();
  inloop=0;
  emit("Goto", ((yyvsp[-2].typ)).nextgoto, "", "", -1);
  emit(((yyvsp[-2].typ)).gotoname, ":", "", "", -1);
  }
#line 6867 "parser.tab.c"
    break;

  case 234: /* WhileStatementNoShortIf: DummyWhileStatement1 CLOSEBRACKET StatementNoShortIf  */
#line 3420 "parser.y"
                                                     {
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  offset = offsets.top(); offsets.pop();
  inloop=0;
  emit("Goto", ((yyvsp[-2].typ)).nextgoto, "", "", -1);
  emit(((yyvsp[-2].typ)).gotoname, ":", "", "", -1);
  }
#line 6880 "parser.tab.c"
    break;

  case 235: /* DummyDoStatement: DO  */
#line 3429 "parser.y"
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
#line 6901 "parser.tab.c"
    break;

  case 236: /* DummyDoStatement1: DummyDoStatement Statement WHILE OPENBRACKET Expression  */
#line 3446 "parser.y"
                                                                           {
  string a = newLabel();
  emit("Goto", ((yyvsp[0].typ)).tempvar, a, "Ifz", -1);
  emit("Goto", ((yyvsp[-4].typ)).gotoname, "", "", -1);
  emit(a, ":", "", "", -1);
  strcpy(((yyval.typ)).gotoname,a.c_str());
  breaklabels.push(a);
}
#line 6914 "parser.tab.c"
    break;

  case 237: /* DoStatement: DummyDoStatement1 CLOSEBRACKET SEMICOLON  */
#line 3456 "parser.y"
                                         {    
  newdim.clear();
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  offset = offsets.top(); offsets.pop();
  inloop=0;
  isclassaccess=0;
    issystem=0;
    isfinal=0;
  }
#line 6929 "parser.tab.c"
    break;

  case 238: /* DummyForStatement: FOR  */
#line 3466 "parser.y"
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
#line 6946 "parser.tab.c"
    break;

  case 239: /* DummyForStatement1: DummyForStatement OPENBRACKET ForInit  */
#line 3479 "parser.y"
                                                         {
  string a = newLabel();
  emit(a, ":", "", "", -1);
  strcpy(((yyval.typ)).gotoname,a.c_str());
}
#line 6956 "parser.tab.c"
    break;

  case 240: /* DummyForStatement14: DummyForStatement1 SEMICOLON  */
#line 3485 "parser.y"
                                                  {    
  newdim.clear();
 isclassaccess=0;
    issystem=0;
    isfinal=0;
}
#line 6967 "parser.tab.c"
    break;

  case 241: /* DummyForStatement2: DummyForStatement14 Expression  */
#line 3492 "parser.y"
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
#line 6987 "parser.tab.c"
    break;

  case 242: /* DummyForStatement3: DummyForStatement2 SEMICOLON ForUpdate  */
#line 3508 "parser.y"
                                                           {    
  newdim.clear();
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
#line 7005 "parser.tab.c"
    break;

  case 243: /* DummyForStatement4: DummyForStatement2 SEMICOLON CLOSEBRACKET  */
#line 3522 "parser.y"
                                                             {   
  newdim.clear(); 
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
#line 7023 "parser.tab.c"
    break;

  case 244: /* DummyForStatement15: DummyForStatement OPENBRACKET SEMICOLON  */
#line 3536 "parser.y"
                                                             {    
  newdim.clear();
  string a = newLabel();
  emit(a, ":", "", "", -1);
  strcpy(((yyval.typ)).gotoname,a.c_str());
  isclassaccess=0;
    issystem=0;
    isfinal=0;
}
#line 7037 "parser.tab.c"
    break;

  case 245: /* DummyForStatement5: DummyForStatement15 Expression  */
#line 3546 "parser.y"
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
#line 7057 "parser.tab.c"
    break;

  case 246: /* DummyForStatement6: DummyForStatement5 SEMICOLON ForUpdate  */
#line 3562 "parser.y"
                                                           {
  newdim.clear();
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
#line 7076 "parser.tab.c"
    break;

  case 247: /* DummyForStatement7: DummyForStatement5 SEMICOLON CLOSEBRACKET  */
#line 3577 "parser.y"
                                                              {
      newdim.clear();
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
#line 7094 "parser.tab.c"
    break;

  case 248: /* DummyForStatement8: DummyForStatement1 SEMICOLON SEMICOLON  */
#line 3591 "parser.y"
                                                           {
      newdim.clear();
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
#line 7115 "parser.tab.c"
    break;

  case 249: /* DummyForStatement9: DummyForStatement8 ForUpdate  */
#line 3608 "parser.y"
                                                 {
  emit("Goto", ((yyvsp[-1].typ)).gotoname, "", "", -1);
  emit(((yyvsp[-1].typ)).nextgoto1, ":", "", "", -1);
  strcpy(((yyval.typ)).gotoname,((yyvsp[-1].typ)).gotoname);
  strcpy(((yyval.typ)).nextgoto,((yyvsp[-1].typ)).nextgoto);
  strcpy(((yyval.typ)).nextgoto1,((yyvsp[-1].typ)).nextgoto1);
  strcpy(((yyval.typ)).nextgoto2,((yyvsp[-1].typ)).nextgoto2);
  breaklabels.push(string((char*)(((yyvsp[-1].typ)).nextgoto)));
}
#line 7129 "parser.tab.c"
    break;

  case 250: /* DummyForStatement10: DummyForStatement8 CLOSEBRACKET  */
#line 3618 "parser.y"
                                                     {
  emit("Goto", ((yyvsp[-1].typ)).gotoname, "", "", -1);
  emit(((yyvsp[-1].typ)).nextgoto1, ":", "", "", -1);
  strcpy(((yyval.typ)).gotoname,((yyvsp[-1].typ)).gotoname);
  strcpy(((yyval.typ)).nextgoto,((yyvsp[-1].typ)).nextgoto);
  strcpy(((yyval.typ)).nextgoto1,((yyvsp[-1].typ)).nextgoto1);
  strcpy(((yyval.typ)).nextgoto2,((yyvsp[-1].typ)).nextgoto2);
  breaklabels.push(string((char*)(((yyvsp[-1].typ)).nextgoto)));
}
#line 7143 "parser.tab.c"
    break;

  case 251: /* DummyForStatement11: DummyForStatement15 SEMICOLON  */
#line 3628 "parser.y"
                                                   {
      newdim.clear();
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
#line 7164 "parser.tab.c"
    break;

  case 252: /* DummyForStatement12: DummyForStatement11 ForUpdate  */
#line 3645 "parser.y"
                                                   {
  emit("Goto", ((yyvsp[-1].typ)).gotoname, "", "", -1);
  emit(((yyvsp[-1].typ)).nextgoto1, ":", "", "", -1);
  strcpy(((yyval.typ)).gotoname,((yyvsp[-1].typ)).gotoname);
  strcpy(((yyval.typ)).nextgoto,((yyvsp[-1].typ)).nextgoto);
  strcpy(((yyval.typ)).nextgoto1,((yyvsp[-1].typ)).nextgoto1);
  strcpy(((yyval.typ)).nextgoto2,((yyvsp[-1].typ)).nextgoto2);
  breaklabels.push(string((char*)(((yyvsp[-1].typ)).nextgoto)));
}
#line 7178 "parser.tab.c"
    break;

  case 253: /* DummyForStatement13: DummyForStatement11 CLOSEBRACKET  */
#line 3655 "parser.y"
                                                      {
  emit("Goto", ((yyvsp[-1].typ)).gotoname, "", "", -1);
  emit(((yyvsp[-1].typ)).nextgoto1, ":", "", "", -1);
  strcpy(((yyval.typ)).gotoname,((yyvsp[-1].typ)).gotoname);
  strcpy(((yyval.typ)).nextgoto,((yyvsp[-1].typ)).nextgoto);
  strcpy(((yyval.typ)).nextgoto1,((yyvsp[-1].typ)).nextgoto1);
  strcpy(((yyval.typ)).nextgoto2,((yyvsp[-1].typ)).nextgoto2);
  breaklabels.push(string((char*)(((yyvsp[-1].typ)).nextgoto)));
}
#line 7192 "parser.tab.c"
    break;

  case 254: /* ForStatement: DummyForStatement6 CLOSEBRACKET Statement  */
#line 3666 "parser.y"
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
#line 7208 "parser.tab.c"
    break;

  case 255: /* ForStatement: DummyForStatement9 CLOSEBRACKET Statement  */
#line 3677 "parser.y"
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
#line 7224 "parser.tab.c"
    break;

  case 256: /* ForStatement: DummyForStatement4 Statement  */
#line 3688 "parser.y"
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
#line 7240 "parser.tab.c"
    break;

  case 257: /* ForStatement: DummyForStatement12 CLOSEBRACKET Statement  */
#line 3699 "parser.y"
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
#line 7256 "parser.tab.c"
    break;

  case 258: /* ForStatement: DummyForStatement10 Statement  */
#line 3710 "parser.y"
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
#line 7272 "parser.tab.c"
    break;

  case 259: /* ForStatement: DummyForStatement7 Statement  */
#line 3721 "parser.y"
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
#line 7288 "parser.tab.c"
    break;

  case 260: /* ForStatement: DummyForStatement13 Statement  */
#line 3732 "parser.y"
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
#line 7304 "parser.tab.c"
    break;

  case 261: /* ForStatement: DummyForStatement3 CLOSEBRACKET Statement  */
#line 3743 "parser.y"
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
#line 7320 "parser.tab.c"
    break;

  case 262: /* ForStatementNoShortIf: DummyForStatement6 CLOSEBRACKET StatementNoShortIf  */
#line 3756 "parser.y"
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
#line 7336 "parser.tab.c"
    break;

  case 263: /* ForStatementNoShortIf: DummyForStatement9 CLOSEBRACKET StatementNoShortIf  */
#line 3767 "parser.y"
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
#line 7352 "parser.tab.c"
    break;

  case 264: /* ForStatementNoShortIf: DummyForStatement4 StatementNoShortIf  */
#line 3778 "parser.y"
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
#line 7368 "parser.tab.c"
    break;

  case 265: /* ForStatementNoShortIf: DummyForStatement12 CLOSEBRACKET StatementNoShortIf  */
#line 3789 "parser.y"
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
#line 7384 "parser.tab.c"
    break;

  case 266: /* ForStatementNoShortIf: DummyForStatement10 StatementNoShortIf  */
#line 3800 "parser.y"
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
#line 7400 "parser.tab.c"
    break;

  case 267: /* ForStatementNoShortIf: DummyForStatement7 StatementNoShortIf  */
#line 3811 "parser.y"
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
#line 7416 "parser.tab.c"
    break;

  case 268: /* ForStatementNoShortIf: DummyForStatement13 StatementNoShortIf  */
#line 3822 "parser.y"
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
#line 7432 "parser.tab.c"
    break;

  case 269: /* ForStatementNoShortIf: DummyForStatement3 CLOSEBRACKET StatementNoShortIf  */
#line 3833 "parser.y"
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
#line 7448 "parser.tab.c"
    break;

  case 270: /* ForInit: StatementExpressionList  */
#line 3845 "parser.y"
                        {
}
#line 7455 "parser.tab.c"
    break;

  case 271: /* ForInit: LocalVariableDeclaration  */
#line 3847 "parser.y"
                          {
}
#line 7462 "parser.tab.c"
    break;

  case 272: /* ForUpdate: StatementExpressionList  */
#line 3851 "parser.y"
                        {
}
#line 7469 "parser.tab.c"
    break;

  case 273: /* StatementExpressionList: StatementExpression  */
#line 3855 "parser.y"
                    {
}
#line 7476 "parser.tab.c"
    break;

  case 274: /* StatementExpressionList: StatementExpressionList COMMA StatementExpression  */
#line 3857 "parser.y"
                                                   {
}
#line 7483 "parser.tab.c"
    break;

  case 275: /* BreakStatement: BREAK SEMICOLON  */
#line 3861 "parser.y"
                {
      newdim.clear();
  isclassaccess=0;
   isfinal=0;
  if(!inloop)
  {
    cout<<"Invalid use of break on line "<<yylineno<<'\n';
  }
    issystem=0;
  // cout<<"sz "<<breaklabels.size()<<'\n';
  if(breaklabels.size())
  emit("Goto", breaklabels.top(), "", "", -1);
}
#line 7501 "parser.tab.c"
    break;

  case 276: /* BreakStatement: BREAK Identifier SEMICOLON  */
#line 3874 "parser.y"
                            {
  newdim.clear();
      
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
#line 7522 "parser.tab.c"
    break;

  case 277: /* ContinueStatement: CONTINUE Identifier SEMICOLON  */
#line 3892 "parser.y"
                              {
  newdim.clear();
      
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
#line 7543 "parser.tab.c"
    break;

  case 278: /* ContinueStatement: CONTINUE SEMICOLON  */
#line 3908 "parser.y"
                    {    
  newdim.clear();
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
#line 7560 "parser.tab.c"
    break;

  case 279: /* ReturnStatement: RETURN SEMICOLON  */
#line 3923 "parser.y"
                 {   
  newdim.clear(); 
  if(!infunction)
  {
    cout<<"Invalid return on line "<<yylineno<<'\n';
  }
  isclassaccess=0;
    issystem=0;
    if(ispopped == 1){
    if(totalstack != 0){ emit("add", "esp", to_string(totalstack), "", -1); ;}
emit("pop","ebp","","",-1);
    ispopped = 0;totalstack = 0;
    emit("ret", "", "", "", -1);
  }
    ispopped = 0;
  
}
#line 7582 "parser.tab.c"
    break;

  case 280: /* ReturnStatement: RETURN Expression SEMICOLON  */
#line 3940 "parser.y"
                             {    
  newdim.clear();
  string p = string((char*)((yyvsp[-1].typ)).tempvar);
    string o = p.substr(0, p.find('.'));
    if(p != o){
      string v = p.substr(p.find('.')+1, p.size());
      int tp2 = curr_table->lookup(v).offset;
      string tp3 = "*(" + o + "+" + to_string(tp2) + ")";
      strcpy(((yyvsp[-1].typ)).tempvar, tp3.c_str());
    }
    if(ispopped == 1){
    if(totalstack != 0){ emit("add", "esp", to_string(totalstack), "", -1); ;}
emit("pop","ebp","","",-1);
    ispopped = 0;totalstack = 0;
    emit("push", ((yyvsp[-1].typ)).tempvar, "", "", -1);
    emit("ret", "" , "", "", -1);
  }
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
#line 7622 "parser.tab.c"
    break;

  case 281: /* ThrowStatement: THROW Expression SEMICOLON  */
#line 3978 "parser.y"
                           {    
  newdim.clear();
  isclassaccess=0;
    issystem=0;
     isfinal=0;
}
#line 7633 "parser.tab.c"
    break;

  case 282: /* SynchronizedStatement: SYNCHRONIZED OPENBRACKET Expression CLOSEBRACKET Block  */
#line 3985 "parser.y"
                                                       {
}
#line 7640 "parser.tab.c"
    break;

  case 283: /* TryStatement: TRY Block Catches  */
#line 3988 "parser.y"
                  {
}
#line 7647 "parser.tab.c"
    break;

  case 284: /* TryStatement: TRY Block Catches Finally  */
#line 3990 "parser.y"
                           {
}
#line 7654 "parser.tab.c"
    break;

  case 285: /* TryStatement: TRY Block Finally  */
#line 3992 "parser.y"
                   {
}
#line 7661 "parser.tab.c"
    break;

  case 286: /* Catches: CatchClause  */
#line 3995 "parser.y"
            {
}
#line 7668 "parser.tab.c"
    break;

  case 287: /* Catches: Catches CatchClause  */
#line 3997 "parser.y"
                     {
}
#line 7675 "parser.tab.c"
    break;

  case 288: /* $@16: %empty  */
#line 4000 "parser.y"
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
#line 7691 "parser.tab.c"
    break;

  case 289: /* CatchClause: CATCH $@16 OPENBRACKET FormalParameter CLOSEBRACKET Block  */
#line 4011 "parser.y"
                                               {
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  offset = offsets.top(); offsets.pop();
}
#line 7701 "parser.tab.c"
    break;

  case 290: /* Finally: FINALLY Block  */
#line 4017 "parser.y"
              {
}
#line 7708 "parser.tab.c"
    break;

  case 291: /* Primary: PrimaryNoNewArray  */
#line 4020 "parser.y"
                  {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
  ((yyval.typ)).ndim=((yyvsp[0].typ)).ndim;
}
#line 7718 "parser.tab.c"
    break;

  case 292: /* Primary: ArrayCreationExpression  */
#line 4025 "parser.y"
                         {
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);
}
#line 7727 "parser.tab.c"
    break;

  case 293: /* PrimaryNoNewArray: Literal  */
#line 4031 "parser.y"
        {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);

  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
}
#line 7737 "parser.tab.c"
    break;

  case 294: /* PrimaryNoNewArray: THIS  */
#line 4036 "parser.y"
      {
  string s = newtemp();
  emit("=", "[ebp+8]", "null", s, -1);
  strcpy(((yyval.typ)).tempvar, s.c_str());
  strcpy(((yyval.typ)).type,((yyvsp[0].lex)).str);
}
#line 7748 "parser.tab.c"
    break;

  case 295: /* PrimaryNoNewArray: OPENBRACKET Expression CLOSEBRACKET  */
#line 4042 "parser.y"
                                     {

  strcpy(((yyval.typ)).tempvar, strcat(((yyvsp[-2].lex)).str, strcat(((yyvsp[-1].typ)).tempvar, ((yyvsp[0].lex)).str)));
  
  strcpy(((yyval.typ)).type,((yyvsp[-1].typ)).type);
  
}
#line 7760 "parser.tab.c"
    break;

  case 296: /* PrimaryNoNewArray: ClassInstanceCreationExpression  */
#line 4049 "parser.y"
                                 {
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
  
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);
}
#line 7770 "parser.tab.c"
    break;

  case 297: /* PrimaryNoNewArray: FieldAccess  */
#line 4054 "parser.y"
             {

  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);
  
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
  
}
#line 7782 "parser.tab.c"
    break;

  case 298: /* PrimaryNoNewArray: MethodInvocation  */
#line 4061 "parser.y"
                  {

  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);
  
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
  
}
#line 7794 "parser.tab.c"
    break;

  case 299: /* PrimaryNoNewArray: ArrayAccess  */
#line 4068 "parser.y"
             {
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
  
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);
}
#line 7804 "parser.tab.c"
    break;

  case 300: /* ClassInstanceCreationExpression: NEW ClassType OPENBRACKET ArgumentList CLOSEBRACKET  */
#line 4075 "parser.y"
                                                    {
  string tv1 = newtemp();
  emit("=", to_string(getclasswidth(string((char*)((yyvsp[-3].typ)).type))), "null", tv1, -1);
  emit("param",tv1,"","",-1);
  // emit("sub","esp","8","",-1);
  emit("sub","esp","8","",-1);
  emit("call","allocmem","1","",-1);
  // emit("add","esp","8","",-1);
  emit("add","esp","8","",-1);
  string tv2 = newtemp();
  emit("=", "popparam", "null", tv2, -1);

  int pops = 0;
  string ar = "";
  stack<string> args2;
  while(!args.empty())
  {
    auto arg = args.top();
    args2.push(arg.first);
    emit("param",arg.first,"","",-1);
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
  emit("param",tv2,"","",-1);
  emit("sub", "esp", to_string(8 + pops),"", -1);
  emit("call",string((char*)(((yyvsp[-3].typ)).type)), "","",-1);
  emit("add", "esp", to_string(8 + pops),"", -1);
  strcpy(((yyval.typ)).tempvar, tv2.c_str());

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
    if(curr_table->lookup(string((char*)((yyvsp[-3].typ)).type)).narg != ((yyvsp[-1].typ)).nelem&&strcmp(curr_table->lookup(string((char*)((yyvsp[-3].typ)).type)).scope_name.c_str(),"Global"))
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
#line 7901 "parser.tab.c"
    break;

  case 301: /* ClassInstanceCreationExpression: NEW ClassType OPENBRACKET CLOSEBRACKET  */
#line 4167 "parser.y"
                                        {
  // string a = newtemp();
  // strcpy(($$).tempvar, a.c_str());
  string tv1 = newtemp();
  emit("=", to_string(getclasswidth(string((char*)((yyvsp[-2].typ)).type))), "null", tv1, -1);
  emit("param",tv1,"","",-1);
  emit("sub","esp","8","",-1);
  emit("call","allocmem","1","",-1);
  emit("add","esp","8","",-1);
  string tv2 = newtemp();
  emit("=", "popparam", "null", tv2, -1);
  emit("param",tv2,"","",-1);
  emit("call",string((char*)(((yyvsp[-2].typ)).type)), "","",-1);
  strcpy(((yyval.typ)).tempvar, tv2.c_str());

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
#line 7940 "parser.tab.c"
    break;

  case 302: /* ArgumentList: Expression  */
#line 4203 "parser.y"
           {
  args.push({string((char*)((yyvsp[0].typ)).tempvar), sz});
  strcpy(((yyval.typ)).argstring, ((yyvsp[0].typ)).type);
  // cout<<"XXX"<<($$).argstring<<'\n';
  ((yyval.typ)).nelem=1;
}
#line 7951 "parser.tab.c"
    break;

  case 303: /* ArgumentList: ArgumentList COMMA Expression  */
#line 4209 "parser.y"
                               {
  args.push({string((char*)((yyvsp[0].typ)).tempvar), sz});
  strcat(((yyval.typ)).argstring, "$");
  strcat(((yyval.typ)).argstring, ((yyvsp[0].typ)).type);
  // cout<<"XXX"<<($$).argstring<<'\n';
  ((yyval.typ)).nelem=((yyvsp[-2].typ)).nelem+1;
}
#line 7963 "parser.tab.c"
    break;

  case 304: /* ArrayCreationExpression: NEW PrimitiveType DimExprs Dims  */
#line 4218 "parser.y"
                                {
  newhandle = string((char*)(((yyvsp[-2].typ)).type));
  // strcpy(($$).tempvar, newtemp().c_str());
  // emit("=", "new", string((char*)($2).tempvar) + string((char*)($3).tempvar) + string((char*)($4).tempvar), ($$).tempvar, -1);
  flagyo=1;
  strcpy(((yyval.typ)).arrtype,((yyvsp[-2].typ)).type);
  ((yyval.typ)).ndim = ((yyvsp[-1].typ)).ndim + ((yyvsp[0].typ)).ndim;
  strcpy(((yyval.typ)).type,((yyvsp[-2].typ)).type);
  for(int i=0;i<((yyval.typ)).ndim;i++)
  {
    strcat(((yyval.typ)).type,"[]");
  }
  // print_dims();
    
}
#line 7983 "parser.tab.c"
    break;

  case 305: /* ArrayCreationExpression: NEW PrimitiveType DimExprs  */
#line 4233 "parser.y"
                            {
  newhandle = string((char*)(((yyvsp[-1].typ)).type));
  // strcpy(($$).tempvar, newtemp().c_str());
  // emit("=", "new", string((char*)($2).tempvar) + string((char*)($3).tempvar), ($$).tempvar, -1);

  flagyo=1;
  strcpy(((yyval.typ)).type,"array");
  strcpy(((yyval.typ)).arrtype,((yyvsp[-1].typ)).type);
  ((yyval.typ)).ndim = ((yyvsp[0].typ)).ndim;  
  strcpy(((yyval.typ)).type,((yyvsp[-1].typ)).type);
  for(int i=0;i<((yyval.typ)).ndim;i++)
  {
    strcat(((yyval.typ)).type,"[]");
  }
  // print_dims();
    
}
#line 8005 "parser.tab.c"
    break;

  case 306: /* ArrayCreationExpression: NEW ClassOrInterfaceType DimExprs Dims  */
#line 4250 "parser.y"
                                        {
  newhandle = string((char*)(((yyvsp[-2].typ)).type));
  // strcpy(($$).tempvar, newtemp().c_str());
  // emit("=", "new", string((char*)($2).tempvar) + string((char*)($3).tempvar) + string((char*)($4).tempvar), ($$).tempvar, -1);
  flagyo=1;
  strcpy(((yyval.typ)).type,"array");
  strcpy(((yyval.typ)).arrtype,((yyvsp[-2].typ)).type);
  ((yyval.typ)).ndim = ((yyvsp[-1].typ)).ndim + ((yyvsp[0].typ)).ndim;
  strcpy(((yyval.typ)).type,((yyvsp[-2].typ)).type);
  for(int i=0;i<((yyval.typ)).ndim;i++)
  {
    strcat(((yyval.typ)).type,"[]");
  }
  // print_dims();
    
  
}
#line 8027 "parser.tab.c"
    break;

  case 307: /* ArrayCreationExpression: NEW ClassOrInterfaceType DimExprs  */
#line 4267 "parser.y"
                                   {
  // strcpy(($$).tempvar, newtemp().c_str());
  // emit("=", "new", string((char*)($2).tempvar) + string((char*)($3).tempvar), ($$).tempvar, -1);
  flagyo=1;
  strcpy(((yyval.typ)).type,"array");
  strcpy(((yyval.typ)).arrtype,((yyvsp[-1].typ)).type);
  ((yyval.typ)).ndim = ((yyvsp[0].typ)).ndim;
  strcpy(((yyval.typ)).type,((yyvsp[-1].typ)).type);
  for(int i=0;i<((yyval.typ)).ndim;i++)
  {
    strcat(((yyval.typ)).type,"[]");
  }
  // print_dims();
    
  
  
}
#line 8049 "parser.tab.c"
    break;

  case 308: /* DimExprs: DimExpr  */
#line 4285 "parser.y"
        {
  ((yyval.typ)).ndim=1;
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);
}
#line 8058 "parser.tab.c"
    break;

  case 309: /* DimExprs: DimExprs DimExpr  */
#line 4289 "parser.y"
                  {
  ((yyval.typ)).ndim = ((yyvsp[-1].typ)).ndim + 1;
  strcpy(((yyval.typ)).tempvar, strcat(((yyvsp[-1].typ)).tempvar, ((yyvsp[0].typ)).tempvar));
}
#line 8067 "parser.tab.c"
    break;

  case 310: /* DimExpr: OPENSQUAREBRACKET Expression CLOSESQUAREBRACKET  */
#line 4294 "parser.y"
                                                {
  strcpy(((yyval.typ)).tempvar, strcat(((yyvsp[-2].lex)).str, strcat(((yyvsp[-1].typ)).tempvar, ((yyvsp[0].lex)).str)));
  ((yyval.typ)).ndim=1;
  newdim.push_back(dimint);
  
}
#line 8078 "parser.tab.c"
    break;

  case 311: /* Dims: OPENSQUAREBRACKET CLOSESQUAREBRACKET  */
#line 4302 "parser.y"
                                     {
  strcpy(((yyval.typ)).tempvar, strcat(((yyvsp[-1].lex)).str, ((yyvsp[0].lex)).str));
  strcpy(((yyval.typ)).tempvar, strcat(((yyvsp[-1].lex)).str, ((yyvsp[0].lex)).str));
  ((yyval.typ)).ndim=1;
  newdim.push_back(0);
  
}
#line 8090 "parser.tab.c"
    break;

  case 312: /* Dims: Dims OPENSQUAREBRACKET CLOSESQUAREBRACKET  */
#line 4309 "parser.y"
                                           {
  strcpy(((yyval.typ)).tempvar, strcat(((yyvsp[-2].typ)).tempvar, strcat(((yyvsp[-1].lex)).str, ((yyvsp[0].lex)).str)));
  ((yyval.typ)).ndim = ((yyvsp[-2].typ)).ndim + 1;
  newdim.push_back(0);
}
#line 8100 "parser.tab.c"
    break;

  case 313: /* FieldAccess: Primary DOT Identifier  */
#line 4316 "parser.y"
                       {
  // strcpy(($$).tempvar, strcat(($1).tempvar, strcat(($2).str, ($3).str)));
  if(curr_table->lookup(string((char*)((yyvsp[0].lex)).str)).offset == -1 && checkobj(string((char*)((yyvsp[0].lex)).str)) == 0){
    cout<<"Undeclared variable on line "<< yylineno<<"\n";
  }
  if(strcmp(((yyvsp[-2].typ)).type,"this")==0)
  {
    string s = newtemp();
    emit("=", string((char*)(((yyvsp[-2].typ)).tempvar)) + " + " + to_string(curr_table->lookup(string((char*)((yyvsp[0].lex)).str)).offset), "null", s, -1);
    s = "*" + s;
    strcpy(((yyval.typ)).tempvar, s.c_str());
    strcpy(((yyval.typ)).type,curr_table->thislookup(((yyvsp[0].lex)).str).c_str());
  }
}
#line 8119 "parser.tab.c"
    break;

  case 314: /* FieldAccess: SUPER DOT Identifier  */
#line 4330 "parser.y"
                      {
  strcpy(((yyval.typ)).tempvar, strcat(((yyvsp[-2].lex)).str, strcat(((yyvsp[-1].lex)).str, ((yyvsp[0].lex)).str)));
  if(curr_table->lookup(string((char*)((yyvsp[0].lex)).str)).offset == -1 && checkobj(string((char*)((yyvsp[0].lex)).str)) == 0){
    cout<<"Undeclared variable on line "<< yylineno<<"\n";
  }
}
#line 8130 "parser.tab.c"
    break;

  case 315: /* DummyMethodInvocation: Name  */
#line 4337 "parser.y"
                            {
  //emit(string((char*)($1).type),"","","",-1);
  //emit("BeginFunc","","","",-1);
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
  strcpy(((yyval.typ)).tempvar,((yyvsp[0].typ)).tempvar);
}
#line 8141 "parser.tab.c"
    break;

  case 316: /* MethodInvocation: DummyMethodInvocation OPENBRACKET ArgumentList CLOSEBRACKET  */
#line 4345 "parser.y"
                                                            {
  int pops = 0;
  string ar = "";
  stack<string> args2;
  while(!args.empty())
  {
    auto arg = args.top();
    args2.push(arg.first);
    emit("param",arg.first,"","",-1);
    pops += arg.second;
    args.pop();
  }
  int funcargtypesz1 = funcargtypesz(1, string((char*)(((yyvsp[-3].typ)).type)));
  // emit("stackpointer", "+" + to_string(funcargtypesz1), "", "", -1);

  if(!strcmp(string((char*)(((yyvsp[-3].typ)).tempvar)).c_str(),"System.println"))
  {
    emit("call", "print 1", "", "", -1);
  }
  else{
    string tv9 = string((char*)(((yyvsp[-3].typ)).tempvar));
    string oname = tv9.substr(0, tv9.find('.'));
    string cname = curr_table->lookup(oname).type;
    if(checkclass(cname)){
      string mname = tv9.substr(tv9.find('.')+1, tv9.size());
      funcargtypesz1 = funcargtypesz(1, mname) + 8;
      emit("param", oname, "", "", -1);
      emit("sub","esp",to_string(funcargtypesz1),"",-1);
      emit("call", cname + "." + mname, "", "", -1);

    }
    else{
      emit("sub","esp",to_string(funcargtypesz1),"",-1);
      emit("call", string((char*)(((yyvsp[-3].typ)).tempvar)),"", "", -1);
    }
  }
  // emit("stackpointer", "-" + to_string(funcargtypesz1), "", "", -1);
  emit("add","esp",to_string(funcargtypesz1),"",-1);
  string tv3 = newtemp();
  emit("=", "popparam", "null", tv3.c_str(), -1);
  emit("add", "esp", to_string(8), "", -1);
  strcpy(((yyval.typ)).tempvar, tv3.c_str());
  //emit("EndFunc","","","",-1)

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
#line 8296 "parser.tab.c"
    break;

  case 317: /* MethodInvocation: DummyMethodInvocation OPENBRACKET CLOSEBRACKET  */
#line 4495 "parser.y"
                                                {
  if(!strcmp(string((char*)(((yyvsp[-2].typ)).tempvar)).c_str(),"System.println"))
  {
    emit("call", "print 1", "", "", -1);
  }
  else{
    string tv9 = string((char*)(((yyvsp[-2].typ)).tempvar));
    string oname = tv9.substr(0, tv9.find('.'));
    string cname = curr_table->lookup(oname).type;
    if(checkclass(cname)){
      string mname = tv9.substr(tv9.find('.')+1, tv9.size());
      emit("param", oname, "", "", -1);
      emit("call", cname + "." + mname, "", "", -1);

    }
    else{
      emit("call", string((char*)(((yyvsp[-2].typ)).tempvar)),"", "", -1);
    }
  }
  string s = newtemp();
  emit("=", "popparam", "null", s.c_str(), -1);
  emit("add", "esp", to_string(8), "", -1);
  strcpy(((yyval.typ)).tempvar,s.c_str());

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
#line 8357 "parser.tab.c"
    break;

  case 318: /* MethodInvocation: Primary DOT Identifier OPENBRACKET ArgumentList CLOSEBRACKET  */
#line 4551 "parser.y"
                                                              {
  
  int pops = 0;
  string ar = "";
  stack<string> args2;
  while(!args.empty())
  {
    auto arg = args.top();
    args2.push(arg.first);
    emit("param",arg.first,"","",-1);
    pops += arg.second;
    args.pop();
  }
  int funcargtypesz1 = funcargtypesz(1, string((char*)(((yyvsp[-5].typ)).type)));
  // emit("stackpointer", "+" + to_string(funcargtypesz1), "", "", -1);

  if(!strcmp(string((char*)(((yyvsp[-5].typ)).tempvar)).c_str(),"System.println"))
  {
    emit("call", "print 1", "", "", -1);
  }
  else{
    string tv9 = string((char*)(((yyvsp[-5].typ)).tempvar));
    string oname = tv9.substr(0, tv9.find('.'));
    string cname = curr_table->lookup(oname).type;
    if(checkclass(cname)){
      string mname = tv9.substr(tv9.find('.')+1, tv9.size());
      funcargtypesz1 = funcargtypesz(1, mname) + 8;
      emit("param", oname, "", "", -1);
      emit("sub","esp",to_string(funcargtypesz1),"",-1);
      emit("call", cname + "." + mname, "", "", -1);

    }
    else{
      emit("sub","esp",to_string(funcargtypesz1),"",-1);
      emit("call", string((char*)(((yyvsp[-5].typ)).tempvar)),"", "", -1);
    }
  }
  // emit("stackpointer", "-" + to_string(funcargtypesz1), "", "", -1);
  emit("add","esp",to_string(funcargtypesz1),"",-1);
  string tv3 = newtemp();
  emit("=", "popparam", "null", tv3.c_str(), -1);
  emit("add", "esp", to_string(8), "", -1);
  strcpy(((yyval.typ)).tempvar, tv3.c_str());

  if(curr_table->lookup(string((char*)((yyvsp[-3].lex)).str)).offset == -1 && checkobj(string((char*)((yyvsp[-3].lex)).str)) == 0){
    if(!isaccess)
    {
      cout<<"Undeclared variable on line "<< yylineno<<"\n";
    }
  }
  isaccess=0;
}
#line 8414 "parser.tab.c"
    break;

  case 319: /* MethodInvocation: Primary DOT Identifier OPENBRACKET CLOSEBRACKET  */
#line 4603 "parser.y"
                                                 {
  string s = newtemp();
  emit("call",string((char*)((yyvsp[-4].typ)).tempvar) + string((char*)((yyvsp[-3].lex)).str) + string((char*)((yyvsp[-2].lex)).str)   ,"","",-1);
  emit("=", "popparam", "null", s.c_str(), -1);
  emit("add", "esp", to_string(8), "", -1);
  strcpy(((yyval.typ)).tempvar,s.c_str());

  if(curr_table->lookup(string((char*)((yyvsp[-2].lex)).str)).offset == -1 && checkobj(string((char*)((yyvsp[-2].lex)).str)) == 0){
  if(!isaccess)
    {
      cout<<"Undeclared variable on line "<< yylineno<<"\n";
    }
  }
  isaccess=0;
}
#line 8434 "parser.tab.c"
    break;

  case 320: /* MethodInvocation: SUPER DOT Identifier OPENBRACKET ArgumentList CLOSEBRACKET  */
#line 4618 "parser.y"
                                                            {
  int pops = 0;
  string ar = "";
  stack<string> args2;
  while(!args.empty())
  {
    auto arg = args.top();
    args2.push(arg.first);
    emit("param",arg.first,"","",-1);
    pops += arg.second;
    args.pop();
  }

  //Check left
  // int funcargtypesz1 = funcargtypesz(1, string((char*)(($3).type)));
  // emit("stackpointer", "+" + to_string(funcargtypesz1), "", "", -1);
  // emit("call", string((char*)(($3).tempvar)), "", "", -1);
  // emit("stackpointer", "-" + to_string(funcargtypesz1), "", "", -1);

  if(curr_table->lookup(string((char*)((yyvsp[-3].lex)).str)).offset == -1 && checkobj(string((char*)((yyvsp[-3].lex)).str)) == 0){
  if(!isaccess)
    {
      cout<<"Undeclared variable on line "<< yylineno<<"\n";
    }
  }
  isaccess=0;
}
#line 8466 "parser.tab.c"
    break;

  case 321: /* MethodInvocation: SUPER DOT Identifier OPENBRACKET CLOSEBRACKET  */
#line 4645 "parser.y"
                                               {
  string s = newtemp();
  emit("call",string((char*)((yyvsp[-4].lex)).str) + string((char*)((yyvsp[-3].lex)).str) + string((char*)((yyvsp[-2].lex)).str),"","",-1);
  emit("=", "popparam", "null", s.c_str(), -1);
  emit("add", "esp", to_string(8), "", -1);
  strcpy(((yyval.typ)).tempvar,s.c_str());

  if(curr_table->lookup(string((char*)((yyvsp[-2].lex)).str)).offset == -1 && checkobj(string((char*)((yyvsp[-2].lex)).str)) == 0){
  if(!isaccess)
    {
      cout<<"Undeclared variable on line "<< yylineno<<"\n";
    }
  }
  isaccess=0;
}
#line 8486 "parser.tab.c"
    break;

  case 322: /* ArrayAccess: Name OPENSQUAREBRACKET Expression CLOSESQUAREBRACKET  */
#line 4662 "parser.y"
                                                     {
  arrayname=((yyvsp[-3].typ)).type;
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

  string array_len = curr_table->lookup(string((char*)(((yyvsp[-3].typ)).type))).type;
  for(char c: array_len){
    if(c == '['){
      arrayaccesscount ++ ;
    }
  }

  string tp7 = newtemp();
  string tp8 = curr_table->lookup(string((char*)(((yyvsp[-3].typ)).type))).type;
  string arraytypeval = "";
  for(auto it : tp8){
    if(it != '['){
      arraytypeval += it;
    }
    else{
      break;
    }
  }
  int size;
  if(!strcmp(arraytypeval.c_str(),"int")||!strcmp(arraytypeval.c_str(),"float"))
  {
    size=4;
  }
  else if(!strcmp(arraytypeval.c_str(),"char")||!strcmp(arraytypeval.c_str(),"byte"))
  {
    size=1;
  }
  else if(!strcmp(arraytypeval.c_str(),"short"))
  {
    size=2;
  }
  else size=8;
  // cout<<"GGGG"<<arraytypeval<<size<<'\n';
  if(arrayaccesscount != 1){
    vector<int> v = curr_table->lookup(arrayname).dims;
    // cout<<"XMI: ";
    // for(auto yo:v)
    // {
    //   cout<<yo<<" ";
    // }
    int x=1;
    for(long i=v.size()-arrayaccesscount+1;i<v.size();i++)
    {
      // cout<<v[i]<<" ";
      x=x*v[i];
    }
    x=x*size;
    cout<<endl;
    // cout<<"LLL"<<($3).tempvar<<'\n';
    string hello(((yyvsp[-1].typ)).tempvar); 
    stringstream str(hello); 
    int y;  
    str >> y;  
    x=x*y;
    // cout<<"YUI"<<y<<" "<<x<<'\n';
    tp8 = to_string(x);
    arrayaccesscount -- ;
  }
  else{
    tp8 = string((char*)((yyvsp[-1].typ)).tempvar)+ "*" + to_string(getsz(arraytypeval));
    arrayaccesscount --;
  }
  if(objtotemp[tp8] != ""){
    tp8 = objtotemp[tp8];
  }
  if(objtotemp[tp7] != ""){
    tp7 = objtotemp[tp7];
  }
  if(objtotemp[string((char*)(((yyval.typ)).tempvar))] != ""){
    strcpy(((yyval.typ)).tempvar, objtotemp[string((char*)(((yyval.typ)).tempvar))].c_str());
  }
  if(objtotemp[string((char*)(((yyvsp[-3].typ)).tempvar))] != ""){
    strcpy(((yyvsp[-3].typ)).tempvar, objtotemp[string((char*)(((yyvsp[-3].typ)).tempvar))].c_str());
  }
  emit("=",tp8,"null",tp7,-1);
  string tp6 = string((char*)((yyvsp[-3].typ)).tempvar) + "+" + tp7 ;
  if(objtotemp[tp6] != ""){
    tp6 = objtotemp[tp6];
  }
  emit("=",tp6,"null",string((char*)((yyval.typ)).tempvar),-1);

  if(arrayaccesscount == 0){
    string tv7 = string((char*)(((yyval.typ)).tempvar));
    tv7 = "*" + tv7;
    strcpy(((yyval.typ)).tempvar, tv7.c_str());
  }

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
#line 8634 "parser.tab.c"
    break;

  case 323: /* ArrayAccess: PrimaryNoNewArray OPENSQUAREBRACKET Expression CLOSESQUAREBRACKET  */
#line 4805 "parser.y"
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
  string tp8 = string((char*)(((yyvsp[-3].typ)).type));
  string arraytypeval = "";
  for(auto it : tp8){
    if(it != '['){
      arraytypeval += it;
    }
    else{
      break;
    }
  }
  // cout<<"FUCK"<<arraytypeval<<getsz(arraytypeval)<<'\n';
  int size;
  if(!strcmp(arraytypeval.c_str(),"int")||!strcmp(arraytypeval.c_str(),"float"))
  {
    size=4;
  }
  else if(!strcmp(arraytypeval.c_str(),"char")||!strcmp(arraytypeval.c_str(),"byte"))
  {
    size=1;
  }
  else if(!strcmp(arraytypeval.c_str(),"short"))
  {
    size=2;
  }
  else size=8;
  // cout<<"GGGG"<<arrayname<<'\n';
  if(arrayaccesscount != 1){
    vector<int> v = curr_table->lookup(arrayname).dims;
    // cout<<"XMI: ";
    // for(auto yo:v)
    // {
    //   cout<<yo<<" ";
    // }
    int x=1;
    for(long i=v.size()-arrayaccesscount+1;i<v.size();i++)
    {
      // cout<<v[i]<<" ";
      x=x*v[i];
    }
    x=x*size;
    // cout<<endl;
    // cout<<"LLL"<<($3).tempvar<<'\n';
    string hello(((yyvsp[-1].typ)).tempvar); 
    stringstream str(hello); 
    int y;  
    str >> y;  
    x=x*y;
    // cout<<"YUI"<<y<<" "<<x<<'\n';
    tp8 = to_string(x);
    arrayaccesscount -- ;
  }
  else{
    string hello(((yyvsp[-1].typ)).tempvar); 
    stringstream str(hello); 
    int y;  
    str >> y;  
    tp8 = to_string(size*y);
    arrayaccesscount --;
    // tp8 = string((char*)($3).tempvar)+ "*" + to_string(10);
  }

  if(objtotemp[tp8] != ""){
    tp8 = objtotemp[tp8];
  }
  if(objtotemp[tp7] != ""){
    tp7 = objtotemp[tp7];
  }
  if(objtotemp[string((char*)(((yyval.typ)).tempvar))] != ""){
    strcpy(((yyval.typ)).tempvar, objtotemp[string((char*)(((yyval.typ)).tempvar))].c_str());
  }
  if(objtotemp[string((char*)(((yyvsp[-3].typ)).tempvar))] != ""){
    strcpy(((yyvsp[-3].typ)).tempvar, objtotemp[string((char*)(((yyvsp[-3].typ)).tempvar))].c_str());
  }
  emit("=",tp8,"null",tp7,-1);
  string tp6 = string((char*)((yyvsp[-3].typ)).tempvar) + "+" + tp7 ;
  if(objtotemp[tp6] != ""){
    tp6 = objtotemp[tp6];
  }
  emit("=",tp6,"null",string((char*)((yyval.typ)).tempvar),-1);
  arraccess=1;
  if(arrayaccesscount == 0){
    // cout<<($$).tempvar<<endl;
    string tv7 = string((char*)(((yyval.typ)).tempvar));
    tv7 = "*" + tv7;
    strcpy(((yyval.typ)).tempvar, tv7.c_str());
  }
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
#line 8778 "parser.tab.c"
    break;

  case 324: /* PostfixExpression: Primary  */
#line 4946 "parser.y"
        {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);

  ((yyval.typ)).ndim=((yyvsp[0].typ)).ndim;
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
}
#line 8789 "parser.tab.c"
    break;

  case 325: /* PostfixExpression: Name  */
#line 4952 "parser.y"
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
#line 8805 "parser.tab.c"
    break;

  case 326: /* PostfixExpression: PostIncrementExpression  */
#line 4963 "parser.y"
                         {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);
  
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
}
#line 8815 "parser.tab.c"
    break;

  case 327: /* PostfixExpression: PostDecrementExpression  */
#line 4968 "parser.y"
                         {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);

  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
  
}
#line 8826 "parser.tab.c"
    break;

  case 328: /* PostIncrementExpression: PostfixExpression PLUSPLUS  */
#line 4975 "parser.y"
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
#line 8863 "parser.tab.c"
    break;

  case 329: /* PostDecrementExpression: PostfixExpression MINUSMINUS  */
#line 5008 "parser.y"
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
#line 8900 "parser.tab.c"
    break;

  case 330: /* UnaryExpression: PreIncrementExpression  */
#line 5041 "parser.y"
                       {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);

  ((yyval.typ)).ndim=((yyvsp[0].typ)).ndim;
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
}
#line 8911 "parser.tab.c"
    break;

  case 331: /* UnaryExpression: PreDecrementExpression  */
#line 5047 "parser.y"
                        {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);
  
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
}
#line 8921 "parser.tab.c"
    break;

  case 332: /* UnaryExpression: PLUS UnaryExpression  */
#line 5052 "parser.y"
                      {
  strcpy(((yyval.typ)).tempvar, newtemp().c_str());
  emit("plus",((yyvsp[0].typ)).tempvar,"null",((yyval.typ)).tempvar, -1); 
  
 cout<<string((char*)((yyvsp[0].typ)).type)<<endl;
 if(invalidoperator(string((char*)((yyvsp[0].typ)).type),0) || !strcmp(string((char*)((yyvsp[0].typ)).type).c_str() ,"boolean" )){
    cout<<"Invalid Operator on line "<< yylineno<<"\n";
  }
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
  
  
}
#line 8938 "parser.tab.c"
    break;

  case 333: /* UnaryExpression: MINUS UnaryExpression  */
#line 5064 "parser.y"
                       {
strcpy(((yyval.typ)).tempvar, newtemp().c_str());  
  emit("minus",((yyvsp[0].typ)).tempvar,"null",((yyval.typ)).tempvar, -1); 
 if(invalidoperator(string((char*)((yyvsp[0].typ)).type),0) || !strcmp(string((char*)((yyvsp[0].typ)).type).c_str() ,"boolean" )){
    cout<<"Invalid Operator on line "<< yylineno<<"\n";
  }
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
  
}
#line 8952 "parser.tab.c"
    break;

  case 334: /* UnaryExpression: UnaryExpressionNotPlusMinus  */
#line 5073 "parser.y"
                             {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);

  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
  ((yyval.typ)).ndim=((yyvsp[0].typ)).ndim;
}
#line 8963 "parser.tab.c"
    break;

  case 335: /* PreIncrementExpression: PLUSPLUS UnaryExpression  */
#line 5081 "parser.y"
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
#line 9000 "parser.tab.c"
    break;

  case 336: /* PreDecrementExpression: MINUSMINUS UnaryExpression  */
#line 5114 "parser.y"
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
#line 9034 "parser.tab.c"
    break;

  case 337: /* UnaryExpressionNotPlusMinus: PostfixExpression  */
#line 5144 "parser.y"
                  {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
}
#line 9043 "parser.tab.c"
    break;

  case 338: /* UnaryExpressionNotPlusMinus: TILDA UnaryExpression  */
#line 5148 "parser.y"
                       {
  
  if(invalidoperator(curr_table->lookup(string((char*)((yyvsp[0].typ)).type)).type,1) || !strcmp(curr_table->lookup(string((char*)((yyvsp[0].typ)).type)).type.c_str() ,"boolean" )){
    cout<<"Invalid TILDA Operator on line "<< yylineno<<"\n";
  }
  string a=newtemp();
  emit("~",((yyvsp[0].typ)).tempvar,"null",a.c_str(), -1);
  strcpy(((yyval.typ)).tempvar, a.c_str());
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
  
  
}
#line 9060 "parser.tab.c"
    break;

  case 339: /* UnaryExpressionNotPlusMinus: NOT UnaryExpression  */
#line 5160 "parser.y"
                     {
 
   if(strcmp(curr_table->lookup(string((char*)((yyvsp[0].typ)).type)).type.c_str() ,"boolean" )){
    cout<<"Invalid NOT Operator on line "<< yylineno<<"\n";
  }
  string a=newtemp();
  emit("!",((yyvsp[0].typ)).tempvar,"null",((yyval.typ)).tempvar, -1);
   strcpy(((yyval.typ)).tempvar, a.c_str());
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
  
  
}
#line 9077 "parser.tab.c"
    break;

  case 340: /* UnaryExpressionNotPlusMinus: CastExpression  */
#line 5172 "parser.y"
                {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
  
}
#line 9087 "parser.tab.c"
    break;

  case 341: /* CastExpression: OPENBRACKET PrimitiveType Dims CLOSEBRACKET UnaryExpression  */
#line 5178 "parser.y"
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
#line 9118 "parser.tab.c"
    break;

  case 342: /* CastExpression: OPENBRACKET PrimitiveType CLOSEBRACKET UnaryExpression  */
#line 5204 "parser.y"
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
#line 9146 "parser.tab.c"
    break;

  case 343: /* CastExpression: OPENBRACKET Expression CLOSEBRACKET UnaryExpressionNotPlusMinus  */
#line 5227 "parser.y"
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
#line 9174 "parser.tab.c"
    break;

  case 344: /* CastExpression: OPENBRACKET Name Dims CLOSEBRACKET UnaryExpressionNotPlusMinus  */
#line 5250 "parser.y"
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
#line 9210 "parser.tab.c"
    break;

  case 345: /* MultiplicativeExpression: UnaryExpression  */
#line 5282 "parser.y"
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
#line 9227 "parser.tab.c"
    break;

  case 346: /* MultiplicativeExpression: MultiplicativeExpression STAR UnaryExpression  */
#line 5294 "parser.y"
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
#line 9377 "parser.tab.c"
    break;

  case 347: /* MultiplicativeExpression: MultiplicativeExpression FORWARDSLASH UnaryExpression  */
#line 5439 "parser.y"
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
#line 9525 "parser.tab.c"
    break;

  case 348: /* MultiplicativeExpression: MultiplicativeExpression MODULO UnaryExpression  */
#line 5582 "parser.y"
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
#line 9672 "parser.tab.c"
    break;

  case 349: /* AdditiveExpression: MultiplicativeExpression  */
#line 5725 "parser.y"
                         {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);

  ((yyval.typ)).ndim=((yyvsp[0].typ)).ndim;
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
}
#line 9683 "parser.tab.c"
    break;

  case 350: /* AdditiveExpression: AdditiveExpression PLUS MultiplicativeExpression  */
#line 5731 "parser.y"
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
#line 9832 "parser.tab.c"
    break;

  case 351: /* AdditiveExpression: AdditiveExpression MINUS MultiplicativeExpression  */
#line 5875 "parser.y"
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
#line 9979 "parser.tab.c"
    break;

  case 352: /* ShiftExpression: AdditiveExpression  */
#line 6019 "parser.y"
                   {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);

  ((yyval.typ)).ndim=((yyvsp[0].typ)).ndim;
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
  
}
#line 9991 "parser.tab.c"
    break;

  case 353: /* ShiftExpression: ShiftExpression OPENANGULARBRACKETOPENANGULARBRACKET AdditiveExpression  */
#line 6026 "parser.y"
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
#line 10015 "parser.tab.c"
    break;

  case 354: /* ShiftExpression: ShiftExpression CLOSEANGULARBRACKETCLOSEANGULARBRACKET AdditiveExpression  */
#line 6045 "parser.y"
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
#line 10041 "parser.tab.c"
    break;

  case 355: /* ShiftExpression: ShiftExpression CLOSEANGULARBRACKETCLOSEANGULARBRACKETCLOSEANGULARBRACKET AdditiveExpression  */
#line 6066 "parser.y"
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
#line 10063 "parser.tab.c"
    break;

  case 356: /* RelationalExpression: ShiftExpression  */
#line 6084 "parser.y"
                {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);

  ((yyval.typ)).ndim=((yyvsp[0].typ)).ndim;
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
}
#line 10074 "parser.tab.c"
    break;

  case 357: /* RelationalExpression: RelationalExpression OPENANGULARBRACKET ShiftExpression  */
#line 6090 "parser.y"
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
#line 10108 "parser.tab.c"
    break;

  case 358: /* RelationalExpression: RelationalExpression CLOSEANGULARBRACKET ShiftExpression  */
#line 6119 "parser.y"
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
#line 10143 "parser.tab.c"
    break;

  case 359: /* RelationalExpression: RelationalExpression OPENANGULARBRACKETEQUAL ShiftExpression  */
#line 6149 "parser.y"
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
#line 10177 "parser.tab.c"
    break;

  case 360: /* RelationalExpression: RelationalExpression CLOSEANGULARBRACKETEQUAL ShiftExpression  */
#line 6178 "parser.y"
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
#line 10213 "parser.tab.c"
    break;

  case 361: /* RelationalExpression: RelationalExpression INSTANCEOF ReferenceType  */
#line 6209 "parser.y"
                                               {
  
  
}
#line 10222 "parser.tab.c"
    break;

  case 362: /* EqualityExpression: RelationalExpression  */
#line 6214 "parser.y"
                     {
  
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);

  ((yyval.typ)).ndim=((yyvsp[0].typ)).ndim;
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
}
#line 10234 "parser.tab.c"
    break;

  case 363: /* EqualityExpression: EqualityExpression EQUALEQUAL RelationalExpression  */
#line 6221 "parser.y"
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
#line 10270 "parser.tab.c"
    break;

  case 364: /* EqualityExpression: EqualityExpression NOTEQUAL RelationalExpression  */
#line 6252 "parser.y"
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
#line 10306 "parser.tab.c"
    break;

  case 365: /* AndExpression: EqualityExpression  */
#line 6284 "parser.y"
                   {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);

  ((yyval.typ)).ndim=((yyvsp[0].typ)).ndim;
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
  
}
#line 10318 "parser.tab.c"
    break;

  case 366: /* AndExpression: AndExpression AND EqualityExpression  */
#line 6291 "parser.y"
                                      {
  strcpy(((yyval.typ)).tempvar, newtemp().c_str());
  emit("&",((yyvsp[-2].typ)).tempvar,((yyvsp[0].typ)).tempvar,((yyval.typ)).tempvar, -1);
  
 strcpy(((yyval.typ)).type,getorder(((yyvsp[-2].typ)).type,((yyvsp[0].typ)).type,0).c_str());
  
}
#line 10330 "parser.tab.c"
    break;

  case 367: /* ExclusiveOrExpression: AndExpression  */
#line 6299 "parser.y"
              {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);

  ((yyval.typ)).ndim=((yyvsp[0].typ)).ndim;
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
  
}
#line 10342 "parser.tab.c"
    break;

  case 368: /* ExclusiveOrExpression: ExclusiveOrExpression XOR AndExpression  */
#line 6306 "parser.y"
                                         {
  strcpy(((yyval.typ)).tempvar, newtemp().c_str());
  emit("^",((yyvsp[-2].typ)).tempvar,((yyvsp[0].typ)).tempvar,((yyval.typ)).tempvar, -1);
 strcpy(((yyval.typ)).type,getorder(((yyvsp[-2].typ)).type,((yyvsp[0].typ)).type,0).c_str());
  
  
}
#line 10354 "parser.tab.c"
    break;

  case 369: /* InclusiveOrExpression: ExclusiveOrExpression  */
#line 6314 "parser.y"
                      {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);

  ((yyval.typ)).ndim=((yyvsp[0].typ)).ndim;
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
}
#line 10365 "parser.tab.c"
    break;

  case 370: /* InclusiveOrExpression: InclusiveOrExpression OR ExclusiveOrExpression  */
#line 6320 "parser.y"
                                                {
  strcpy(((yyval.typ)).tempvar, newtemp().c_str());
  emit("|",((yyvsp[-2].typ)).tempvar,((yyvsp[0].typ)).tempvar,((yyval.typ)).tempvar, -1);
  
 strcpy(((yyval.typ)).type,getorder(((yyvsp[-2].typ)).type,((yyvsp[0].typ)).type,0).c_str());

}
#line 10377 "parser.tab.c"
    break;

  case 371: /* ConditionalAndExpression: InclusiveOrExpression  */
#line 6328 "parser.y"
                      {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);

  ((yyval.typ)).ndim=((yyvsp[0].typ)).ndim;
   strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
}
#line 10388 "parser.tab.c"
    break;

  case 372: /* ConditionalAndExpression: ConditionalAndExpression ANDAND InclusiveOrExpression  */
#line 6334 "parser.y"
                                                       {
  strcpy(((yyval.typ)).tempvar, newtemp().c_str());
  emit("&&",((yyvsp[-2].typ)).tempvar,((yyvsp[0].typ)).tempvar,((yyval.typ)).tempvar, -1);
  
  strcpy(((yyval.typ)).type,"boolean");
  
  
}
#line 10401 "parser.tab.c"
    break;

  case 373: /* ConditionalOrExpression: ConditionalAndExpression  */
#line 6343 "parser.y"
                         {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);

  ((yyval.typ)).ndim=((yyvsp[0].typ)).ndim;
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
}
#line 10412 "parser.tab.c"
    break;

  case 374: /* ConditionalOrExpression: ConditionalOrExpression OROR ConditionalAndExpression  */
#line 6349 "parser.y"
                                                       {
  strcpy(((yyval.typ)).tempvar, newtemp().c_str());
  emit("||",((yyvsp[-2].typ)).tempvar,((yyvsp[0].typ)).tempvar,((yyval.typ)).tempvar, -1);
  strcpy(((yyval.typ)).type,"boolean");
}
#line 10422 "parser.tab.c"
    break;

  case 375: /* ConditionalExpression: ConditionalOrExpression  */
#line 6355 "parser.y"
                        {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);

  ((yyval.typ)).ndim=((yyvsp[0].typ)).ndim;
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
}
#line 10433 "parser.tab.c"
    break;

  case 376: /* ConditionalExpression: ConditionalOrExpression QUESTION Expression COLON ConditionalExpression  */
#line 6361 "parser.y"
                                                                         {
 strcpy(((yyval.typ)).type,getorder(((yyvsp[-2].typ)).type,((yyvsp[0].typ)).type,1).c_str());
}
#line 10441 "parser.tab.c"
    break;

  case 377: /* AssignmentExpression: ConditionalExpression  */
#line 6365 "parser.y"
                      {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);

  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
  ((yyval.typ)).ndim=((yyvsp[0].typ)).ndim;
}
#line 10452 "parser.tab.c"
    break;

  case 378: /* AssignmentExpression: Assignment  */
#line 6371 "parser.y"
            {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);
  strcpy(((yyval.typ)).type, ((yyvsp[0].typ)).type);
  ((yyval.typ)).sz = ((yyvsp[0].typ)).sz;
}
#line 10462 "parser.tab.c"
    break;

  case 379: /* Assignment: LeftHandSide AssignmentOperator AssignmentExpression  */
#line 6378 "parser.y"
                                                     {
  // cout<<"FFF"<<($1).type<<($3).type<<arrtype<<'\n';
  if(!strcmp(((yyvsp[-1].typ)).tempvar,"="))
  {
    string p = string((char*)((yyvsp[-2].typ)).tempvar);
    string o = p.substr(0, p.find('.'));
    string p1 = string((char*)((yyvsp[0].typ)).tempvar);
    string o1 = p1.substr(0, p1.find('.'));
    if(p != o){
      string v = p.substr(p.find('.')+1, p.size());
      string classname = curr_table->lookup(o).type;
      int tp2 = offsetobj(classname, v);
      string tp3 = "*(" + objtotemp[o] + "+" + to_string(tp2) + ")";
      if(p1 != o1){
        string v1 = p1.substr(p1.find('.')+1, p1.size());
        string classname1 = curr_table->lookup(o1).type;
        int tp21 = offsetobj(classname1, v1);
        string tp31 = "*(" + objtotemp[o1] + "+" + to_string(tp21) + ")";
        emit("=",tp31.c_str(),"null",tp3.c_str(), -1);
      }
      else{
        string tv10 = newtemp();
        emit("=",tv10.c_str(),"null","popparam" , -1);
        int offset1 = curr_table->lookup(string((char*)((yyvsp[0].typ)).tempvar)).offset;
        int offset2 = curr_table->lookup(tp3).offset;
        if(offset1 != -1 && offset2 != -1){
          emit("=",("*(" + tv10 + "+" + to_string(offset1)+ ")").c_str(),"null",("*(" + tv10 + "+" + to_string(offset2)+ ")").c_str(), -1);
        }
        else{
        emit("=",((yyvsp[0].typ)).tempvar,"null",tp3.c_str(), -1);
        }
      }
      strcpy(((yyval.typ)).tempvar, tp3.c_str());
    }
    else{
      string tv10 = newtemp();
        emit("=","popparam","null",tv10.c_str() , -1);
        int offset1 = curr_table->lookup(string((char*)((yyvsp[0].typ)).tempvar)).offset;
        int offset2 = curr_table->lookup(string((char*)((yyvsp[-2].typ)).tempvar)).offset;
        string tv11 = string((char*)((yyvsp[0].typ)).tempvar), tv12 = string((char*)((yyvsp[-2].typ)).tempvar);
        if(offset1 != -1 && curr_table->lookup(tv11).scope_name.substr(0,5) == "Class"){
          tv11 = "*(" + tv10 + "+" + to_string(offset1)+ ")";
        }
        if(offset2 != -1 && curr_table->lookup(tv12).scope_name.substr(0,5) == "Class"){
          tv12 = "*(" + tv10 + "+" + to_string(offset2)+ ")";
        }
        emit("=",tv11.c_str(),"null",tv12.c_str(), -1);
    }
    
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
#line 10611 "parser.tab.c"
    break;

  case 380: /* LeftHandSide: Name  */
#line 6523 "parser.y"
     {
  // cout<<"shrey"<<($1).type<<'\n';
  if(curr_table->lookup(string((char*)((yyvsp[0].typ)).type)).offset == -1 && checkobj(string((char*)((yyvsp[0].typ)).type)) == 0){
    if(!isaccess)
    {
      cout<<"Undeclared variable on line "<< yylineno<<"\n";
    }
  }
  strcpy(((yyval.typ)).type, ((yyvsp[0].typ)).type);
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);
  ((yyval.typ)).sz = ((yyvsp[0].typ)).sz;
  isaccess=0;
}
#line 10629 "parser.tab.c"
    break;

  case 381: /* LeftHandSide: FieldAccess  */
#line 6536 "parser.y"
             {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);
  strcpy(((yyval.typ)).type, ((yyvsp[0].typ)).type);
  // cout<<"shrey"<<($1).type<<'\n';
  ((yyval.typ)).sz = ((yyvsp[0].typ)).sz;
  
}
#line 10641 "parser.tab.c"
    break;

  case 382: /* LeftHandSide: ArrayAccess  */
#line 6543 "parser.y"
             {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);
  // cout<<"shubhan\n";
  // cout<<"SHUBHAN"<<($1).type<<'\n';
  strcpy(((yyval.typ)).type, ((yyvsp[0].typ)).type);
  // cout<<"GGG"<< ($1).type<<'\n';
  ((yyval.typ)).sz = ((yyvsp[0].typ)).sz;
  arrtype="null";
}
#line 10655 "parser.tab.c"
    break;

  case 383: /* AssignmentOperator: EQUAL  */
#line 6554 "parser.y"
      {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].lex)).str);
  
  
}
#line 10665 "parser.tab.c"
    break;

  case 384: /* AssignmentOperator: STAREQUAL  */
#line 6559 "parser.y"
           {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].lex)).str);
  
}
#line 10674 "parser.tab.c"
    break;

  case 385: /* AssignmentOperator: FORWARDSLASHEQUAL  */
#line 6563 "parser.y"
                   {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].lex)).str);
  
}
#line 10683 "parser.tab.c"
    break;

  case 386: /* AssignmentOperator: PLUSEQUAL  */
#line 6567 "parser.y"
           {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].lex)).str);
  
}
#line 10692 "parser.tab.c"
    break;

  case 387: /* AssignmentOperator: MINUSEQUAL  */
#line 6571 "parser.y"
            {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].lex)).str);
  
}
#line 10701 "parser.tab.c"
    break;

  case 388: /* AssignmentOperator: OPENANGULARBRACKETOPENANGULARBRACKETEQUAL  */
#line 6575 "parser.y"
                                           {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].lex)).str);
  
}
#line 10710 "parser.tab.c"
    break;

  case 389: /* AssignmentOperator: CLOSEANGULARBRACKETCLOSEANGULARBRACKETEQUAL  */
#line 6579 "parser.y"
                                             {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].lex)).str);
  
}
#line 10719 "parser.tab.c"
    break;

  case 390: /* AssignmentOperator: CLOSEANGULARBRACKETCLOSEANGULARBRACKETCLOSEANGULARBRACKETEQUAL  */
#line 6583 "parser.y"
                                                                {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].lex)).str);
  
}
#line 10728 "parser.tab.c"
    break;

  case 391: /* AssignmentOperator: ANDEQUAL  */
#line 6587 "parser.y"
          {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].lex)).str);
  
}
#line 10737 "parser.tab.c"
    break;

  case 392: /* AssignmentOperator: XOREQUAL  */
#line 6591 "parser.y"
          {
  
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].lex)).str);
}
#line 10746 "parser.tab.c"
    break;

  case 393: /* AssignmentOperator: OREQUAL  */
#line 6595 "parser.y"
         {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].lex)).str);
  
}
#line 10755 "parser.tab.c"
    break;

  case 394: /* Expression: AssignmentExpression  */
#line 6600 "parser.y"
                     {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);

  ((yyval.typ)).ndim=((yyvsp[0].typ)).ndim;
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
  // strcpy(($1).argstring,($1).type);
    // cout<<"YO"<<($1).argstring<<'\n';

  
}
#line 10770 "parser.tab.c"
    break;

  case 395: /* ConstantExpression: Expression  */
#line 6611 "parser.y"
           {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
  
}
#line 10780 "parser.tab.c"
    break;


#line 10784 "parser.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
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
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 6616 "parser.y"



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

  for(auto it: list_of_Symbol_Tables){
    // cout<<"NEW TABLE"<<'\n';
    it->print_table();
    cout<<"Classwidth: "<<it->classwidth<<endl;
    cout<<'\n';
  }

ofstream fout;
fout.open("TAC.txt");
   for(auto it: code){
   // cout<<it.op<<' '<<it.arg1<<' '<<it.arg2<<' '<<it.res<<'\n';
    if(true)
    {
      if(it.op=="BeginFunc" || it.op=="BeginClass"|| it.op=="EndFunc"|| it.op=="EndClass" || it.op=="BeginCtor" || it.op=="EndCtor")
       {
        
        fout<<'\t'<<it.op<<" "<<it.arg1<<'\n';
        if(it.op=="EndClass") fout<<'\n'; 
        
      }
      else if(it.arg2=="null" && it.res=="null")
      {
        fout<<'\t'<<it.op<<" "<<it.res<<"\n";
      }
      else if(it.op=="Call")
      {
        fout<<'\t'<<it.res<<" = "<<it.op<<" "<<it.arg1<<'\n';
      }
      else if(it.arg2=="null" && it.res!="null")
      {
      if(it.op=="minus"||it.op=="plus"||it.op=="!"||it.op=="~")
        {
      fout<<'\t'<<it.res<<' '<<"= "<<it.op<<' '<<it.arg1<<'\n';
        }
      else 
        {
        fout<<'\t'<<it.res<<' '<<"="<<' '<<it.arg1<<"\n";
        }
      }
      else if(it.op=="param"||it.op=="Popparams"||it.op == "stackpointer"|| it.op == "pop" || it.op == "push")
      {
        fout<<'\t'<<it.op<<" "<<it.arg1<<'\n';
      }
      else if(it.op == "call"|| it.op == "add"||it.op == "sub"){
        fout<<'\t'<<it.op<<" "<<it.arg1<<" "<<it.arg2<<'\n';
      }
      else if(it.res=="Ifz")
      {
        fout<<'\t'<<it.res<<" "<<it.arg1<<" "<<it.op<<" "<<it.arg2<<"\n";
      }
      else if(it.op=="Goto")
      {
        fout<<'\t'<<it.op<<" "<<it.arg1<<it.arg2<<it.res<<"\n";
      }
      else if(it.arg1==":")
      {
        // fout<<'\t';
        fout<<it.op<<it.arg1<<"\n";
      }
      else if(it.arg1=="new")
      {
        fout<<'\t'<<it.res<<" = "<<it.arg1<<" "<<it.arg2<<"\n";
      }
      else if(it.op=="ret")
      {
        fout<<'\t'<<it.op<<" "<<it.arg1<<"\n";
      }
      else if(it.arg1=="cast_to_int"||it.arg1=="cast_to_float"||it.arg1=="cast_to_byte"||it.arg1=="cast_to_boolean"||it.arg1=="cast_to_byte"||it.arg1=="cast_to_short"||it.arg1=="cast_to_long"||it.arg1=="cast_to_double"||it.arg1=="cast_to_string")
      {
        fout<<'\t'<<it.res<<" = "<<it.arg1<<" "<<it.arg2<<"\n";
      }
      else
      {
        fout<<'\t'<<it.res<<" = "<<it.arg1<<" "<<it.op<<" "<<it.arg2<<"\n";
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
