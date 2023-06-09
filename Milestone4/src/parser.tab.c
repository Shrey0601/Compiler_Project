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
    #define PTR_SZ 8
    using namespace std;
    extern FILE* yyin;
    void yyerror(const char * s);
    int yylex();
    int nelem=0;
    int lastfieldcount;
    vector<int> newdim;
    int dimint;
    int ispopped = 1;
    int isvoid;
    int isimport=0;
    string arrayname;
    int issystem=0;
    int isfinal=0;
    int isreturn =0;
    string fielddeclist="";
     string fielddeclistlast="";
    int fieldcount=0;
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
    string curr_func = "";
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
    map<pair<string, string>, string> vartostack;
    map<string, int> funcsize;
    map<string, int> numfuncargs;
    int num_forstatements = 1;
    map<string, vector < pair<string,int> > > classfield;
    vector<pair<string,int>> fieldvar;
    map<string, string> storeobj;
    string currtemp;
    string currobj;
    vector<string> objlist;
    vector<string> templist;
    int isobj = 0;
    string curridf;
    vector<string> accesslist;
    
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
      return 8;
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
    map<string,string> vartottemp;
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

    long long counter = 1;
    long long counter1 = 1;

    string offsetlookup(string s){
      auto it = curr_table->lookup(s);
      if(it.offset < 0){
        string o = s.substr(0, s.find('.'));
        if(o != s){
          string attr = s.substr(s.find('.')+1);
          auto it1 = curr_table->lookup(o);
          if(it1.offset < 0){
            return s;
          }
          else{
            // string cln = it1.type;
            // for(auto it2: list_of_Symbol_Tables){
            //   auto tab = it2->table;
            //   for(auto it3 = tab.begin(); it3 != tab.end(); it3++){
            //       if(it3->second.scope_name == "Class" + cln){
            //           if(it3->first == attr){
            //             emit("load", "[rbp-" + to_string(it1.offset + 8) + "]", "", "%r14", -1);
            //             emit("+", "%r14", to_string(it3->second.offset), "%r14", -1);
            //             return "(%r14)";
            //           }
            //       }
            //       else{
            //           break;
            //       }
            //   }
            // }
            return "@[rbp-" + to_string(it1.offset + 8) + "]@" + it1.type + "@" + attr;
            
          }
        }
        return s;
      }
      else{
        if(it.scope_name.substr(0,5) == "Class"){
          return "!" + to_string(it.offset);
        }
        return "[rbp-" + to_string(it.offset + 8) + "]";
      }
    }

    void emit(string op, string arg1, string arg2, string res, int idx){
        quad temp;
        temp.op = op;
        if(op != "call"){
          arg1 = offsetlookup(arg1);
          arg2 = offsetlookup(arg2);
          res = offsetlookup(res);
        }
        temp.arg1 = arg1;
        temp.arg2 = arg2;
        temp.res = res;
        temp.idx = idx;
        // if(idx < 0) temp.idx = code.size();

        code.push_back(temp);
    }

    string newtemp(){
      string temp_var = "#t"+to_string(counter++);
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

#line 739 "parser.tab.c"

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
#line 672 "parser.y"

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

#line 913 "parser.tab.c"

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
       0,   953,   953,   958,   968,   974,   980,   986,   991,   997,
    1005,  1032,  1038,  1045,  1051,  1058,  1064,  1070,  1076,  1082,
    1090,  1096,  1103,  1109,  1116,  1123,  1130,  1137,  1144,  1150,
    1157,  1163,  1170,  1212,  1256,  1258,  1260,  1262,  1264,  1266,
    1268,  1272,  1275,  1280,  1282,  1286,  1289,  1291,  1294,  1299,
    1302,  1305,  1308,  1311,  1314,  1316,  1319,  1321,  1323,  1327,
    1330,  1332,  1334,  1336,  1338,  1340,  1344,  1344,  1373,  1373,
    1414,  1414,  1455,  1455,  1484,  1484,  1513,  1513,  1555,  1555,
    1584,  1584,  1627,  1633,  1639,  1643,  1650,  1654,  1659,  1663,
    1669,  1673,  1676,  1681,  1687,  1694,  1750,  1801,  1833,  1910,
    1961,  2098,  2105,  2105,  2115,  2124,  2132,  2147,  2167,  2229,
    2290,  2345,  2401,  2455,  2506,  2563,  2618,  2633,  2649,  2653,
    2656,  2660,  2679,  2682,  2684,  2688,  2701,  2719,  2719,  2723,
    2731,  2739,  2746,  2754,  2760,  2815,  2815,  2839,  2854,  2867,
    2879,  2891,  2901,  2909,  2917,  2925,  2925,  2949,  2949,  2971,
    2971,  2989,  2989,  3011,  3016,  3023,  3028,  3035,  3039,  3045,
    3049,  3054,  3059,  3067,  3076,  3086,  3094,  3106,  3114,  3124,
    3130,  3136,  3140,  3146,  3150,  3155,  3161,  3171,  3245,  3249,
    3253,  3257,  3261,  3265,  3270,  3274,  3278,  3282,  3286,  3291,
    3295,  3299,  3303,  3307,  3311,  3315,  3319,  3323,  3327,  3331,
    3336,  3342,  3348,  3354,  3363,  3369,  3375,  3381,  3387,  3393,
    3400,  3406,  3419,  3431,  3438,  3450,  3458,  3467,  3477,  3489,
    3493,  3500,  3506,  3512,  3518,  3522,  3527,  3533,  3537,  3543,
    3549,  3554,  3571,  3581,  3591,  3600,  3617,  3627,  3637,  3650,
    3656,  3663,  3679,  3693,  3707,  3717,  3733,  3748,  3762,  3779,
    3789,  3799,  3816,  3826,  3837,  3848,  3859,  3870,  3881,  3892,
    3903,  3914,  3927,  3938,  3949,  3960,  3971,  3982,  3993,  4004,
    4016,  4018,  4022,  4026,  4028,  4032,  4045,  4063,  4079,  4094,
    4111,  4152,  4159,  4162,  4164,  4166,  4169,  4171,  4174,  4174,
    4191,  4194,  4199,  4205,  4210,  4216,  4223,  4228,  4235,  4242,
    4249,  4347,  4389,  4395,  4404,  4419,  4436,  4453,  4471,  4475,
    4480,  4488,  4495,  4502,  4513,  4520,  4528,  4699,  4762,  4821,
    4840,  4867,  4887,  5038,  5186,  5192,  5203,  5208,  5215,  5248,
    5281,  5287,  5292,  5304,  5313,  5321,  5354,  5384,  5388,  5400,
    5412,  5418,  5444,  5467,  5490,  5522,  5534,  5679,  5822,  5965,
    5971,  6115,  6259,  6266,  6285,  6306,  6324,  6330,  6359,  6389,
    6418,  6449,  6454,  6461,  6492,  6524,  6531,  6539,  6546,  6554,
    6560,  6568,  6574,  6583,  6589,  6595,  6601,  6605,  6611,  6618,
    6765,  6778,  6785,  6796,  6801,  6805,  6809,  6813,  6817,  6821,
    6825,  6829,  6833,  6837,  6843,  6854
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
#line 953 "parser.y"
                {
  
  
}
#line 3186 "parser.tab.c"
    break;

  case 3:
#line 958 "parser.y"
               {
  // cout<<"GYO"<<stoi(($1).str)<<'\n';
  fielddeclist=fielddeclist+((yyvsp[0].lex)).str+"$"+to_string(fieldcount*8)+" ";
  fieldcount++;
  dimint=stoi(((yyvsp[0].lex)).str);
  strcpy(((yyval.typ)).tempvar,((yyvsp[0].lex)).str);
  strcpy(((yyval.typ)).type,"int");
  // sz = getsz(string((char*)(($$).type)));
sz = 8;
}
#line 3201 "parser.tab.c"
    break;

  case 4:
#line 968 "parser.y"
                       {
  strcpy(((yyval.typ)).tempvar,((yyvsp[0].lex)).str);
  strcpy(((yyval.typ)).type,"float");
  // sz = getsz(string((char*)(($$).type)));
sz = 8;
}
#line 3212 "parser.tab.c"
    break;

  case 5:
#line 974 "parser.y"
                 {
  strcpy(((yyval.typ)).tempvar,((yyvsp[0].lex)).str);
  strcpy(((yyval.typ)).type,"boolean");
  // sz = getsz(string((char*)(($$).type)));
sz = 8;
}
#line 3223 "parser.tab.c"
    break;

  case 6:
#line 980 "parser.y"
                   {
  strcpy(((yyval.typ)).tempvar,((yyvsp[0].lex)).str);
  strcpy(((yyval.typ)).type,"char");
  // sz = getsz(string((char*)(($$).type)));
sz = 8;
}
#line 3234 "parser.tab.c"
    break;

  case 7:
#line 986 "parser.y"
                {
  strcpy(((yyval.typ)).tempvar,((yyvsp[0].lex)).str);
  strcpy(((yyval.typ)).type,"string");
  sz = string((char*)(((yyvsp[0].lex)).str)).length();
}
#line 3244 "parser.tab.c"
    break;

  case 8:
#line 991 "parser.y"
              {
  strcpy(((yyval.typ)).tempvar,((yyvsp[0].lex)).str);
  strcpy(((yyval.typ)).type,"null");
}
#line 3253 "parser.tab.c"
    break;

  case 9:
#line 997 "parser.y"
               {
  strcpy(((yyval.typ)).tempvar,((yyvsp[0].typ)).tempvar);

  ((yyval.typ)).sz = ((yyvsp[0].typ)).sz;
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
  type = ((yyvsp[0].typ)).type;
  sz = ((yyvsp[0].typ)).sz;
}
#line 3266 "parser.tab.c"
    break;

  case 10:
#line 1005 "parser.y"
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
#line 3296 "parser.tab.c"
    break;

  case 11:
#line 1032 "parser.y"
            {
  strcpy(((yyval.typ)).tempvar,((yyvsp[0].typ)).tempvar);

  ((yyval.typ)).sz = ((yyvsp[0].typ)).sz;
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
}
#line 3307 "parser.tab.c"
    break;

  case 12:
#line 1038 "parser.y"
         {
  strcpy(((yyval.typ)).tempvar,((yyvsp[0].lex)).str);
  
  ((yyval.typ)).sz = 1;
  strcpy(((yyval.typ)).type, "boolean");
}
#line 3318 "parser.tab.c"
    break;

  case 13:
#line 1045 "parser.y"
             {
  strcpy(((yyval.typ)).tempvar,((yyvsp[0].typ)).tempvar);

  ((yyval.typ)).sz = ((yyvsp[0].typ)).sz;
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
}
#line 3329 "parser.tab.c"
    break;

  case 14:
#line 1051 "parser.y"
                   {
  strcpy(((yyval.typ)).tempvar,((yyvsp[0].typ)).tempvar);

  ((yyval.typ)).sz = ((yyvsp[0].typ)).sz;
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
}
#line 3340 "parser.tab.c"
    break;

  case 15:
#line 1058 "parser.y"
     {
  strcpy(((yyval.typ)).tempvar,((yyvsp[0].lex)).str);

  ((yyval.typ)).sz = 8;
  strcpy(((yyval.typ)).type, "byte"); 
}
#line 3351 "parser.tab.c"
    break;

  case 16:
#line 1064 "parser.y"
        {
  strcpy(((yyval.typ)).tempvar,((yyvsp[0].lex)).str);

  ((yyval.typ)).sz = 8;
  strcpy(((yyval.typ)).type, "short");
}
#line 3362 "parser.tab.c"
    break;

  case 17:
#line 1070 "parser.y"
      {
  strcpy(((yyval.typ)).tempvar,((yyvsp[0].lex)).str);

  ((yyval.typ)).sz = 8;
  strcpy(((yyval.typ)).type, "int");
}
#line 3373 "parser.tab.c"
    break;

  case 18:
#line 1076 "parser.y"
      {
  strcpy(((yyval.typ)).tempvar,((yyvsp[0].lex)).str);

  ((yyval.typ)).sz = 8;
  strcpy(((yyval.typ)).type, "long");
}
#line 3384 "parser.tab.c"
    break;

  case 19:
#line 1082 "parser.y"
      {
  strcpy(((yyval.typ)).tempvar,((yyvsp[0].lex)).str);

  ((yyval.typ)).sz = 8;
  strcpy(((yyval.typ)).type, "char");
}
#line 3395 "parser.tab.c"
    break;

  case 20:
#line 1090 "parser.y"
      {
  strcpy(((yyval.typ)).tempvar,((yyvsp[0].lex)).str);

  ((yyval.typ)).sz = 8;
  strcpy(((yyval.typ)).type, "float");
}
#line 3406 "parser.tab.c"
    break;

  case 21:
#line 1096 "parser.y"
        {
  strcpy(((yyval.typ)).tempvar,((yyvsp[0].lex)).str);

  ((yyval.typ)).sz = 8;
  strcpy(((yyval.typ)).type, "double");
}
#line 3417 "parser.tab.c"
    break;

  case 22:
#line 1103 "parser.y"
                     {
  strcpy(((yyval.typ)).tempvar,((yyvsp[0].typ)).tempvar);

  strcpy(((yyval.typ)).type, ((yyvsp[0].typ)).type);
  ((yyval.typ)).sz = ((yyvsp[0].typ)).sz;
}
#line 3428 "parser.tab.c"
    break;

  case 23:
#line 1109 "parser.y"
           {
  strcpy(((yyval.typ)).tempvar,((yyvsp[0].typ)).tempvar);

  strcpy(((yyval.typ)).type, ((yyvsp[0].typ)).type);
  ((yyval.typ)).sz = ((yyvsp[0].typ)).sz;
}
#line 3439 "parser.tab.c"
    break;

  case 24:
#line 1116 "parser.y"
     {
  strcpy(((yyval.typ)).tempvar,((yyvsp[0].typ)).tempvar);

  strcpy(((yyval.typ)).type, ((yyvsp[0].typ)).type);
  ((yyval.typ)).sz = PTR_SZ;
}
#line 3450 "parser.tab.c"
    break;

  case 25:
#line 1123 "parser.y"
                     {
  strcpy(((yyval.typ)).tempvar,((yyvsp[0].typ)).tempvar);

  strcpy(((yyval.typ)).type, ((yyvsp[0].typ)).type);
  ((yyval.typ)).sz = ((yyvsp[0].typ)).sz;
}
#line 3461 "parser.tab.c"
    break;

  case 26:
#line 1130 "parser.y"
                     {
  strcpy(((yyval.typ)).tempvar,((yyvsp[0].typ)).tempvar);

  strcpy(((yyval.typ)).type, ((yyvsp[0].typ)).type);
  ((yyval.typ)).sz = ((yyvsp[0].typ)).sz;
}
#line 3472 "parser.tab.c"
    break;

  case 27:
#line 1137 "parser.y"
                                                   {

  strcpy(((yyval.typ)).type,strcat(((yyvsp[-2].typ)).type,"[]"));
  strcpy(((yyval.typ)).arrtype, ((yyvsp[-2].typ)).type);
  ((yyval.typ)).ndim = 1;
  ((yyval.typ)).sz = ((yyvsp[-2].typ)).sz*((yyval.typ)).ndim;
}
#line 3484 "parser.tab.c"
    break;

  case 28:
#line 1144 "parser.y"
                                           {
  strcpy(((yyval.typ)).type,strcat(((yyvsp[-2].typ)).type,"[]"));
  strcpy(((yyval.typ)).arrtype, ((yyvsp[-2].typ)).type);
  ((yyval.typ)).ndim =1;
  ((yyval.typ)).sz = ((yyvsp[-2].typ)).sz*((yyval.typ)).ndim;
}
#line 3495 "parser.tab.c"
    break;

  case 29:
#line 1150 "parser.y"
                                                {
  strcpy(((yyval.typ)).type,strcat(((yyvsp[-2].typ)).type,"[]"));
  strcpy(((yyval.typ)).arrtype, ((yyvsp[-2].typ)).type);
  ((yyval.typ)).ndim = ((yyvsp[-2].typ)).ndim+1;
  ((yyval.typ)).sz = ((yyvsp[-2].typ)).sz*((yyval.typ)).ndim;
}
#line 3506 "parser.tab.c"
    break;

  case 30:
#line 1157 "parser.y"
           {
   strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);

   strcpy(((yyval.typ)).type, ((yyvsp[0].typ)).type);
   ((yyval.typ)).sz = ((yyvsp[0].typ)).sz;
}
#line 3517 "parser.tab.c"
    break;

  case 31:
#line 1163 "parser.y"
               {
  strcpy(((yyval.typ)).tempvar,((yyvsp[0].typ)).tempvar);

  strcpy(((yyval.typ)).type, ((yyvsp[0].typ)).type);
  ((yyval.typ)).sz = ((yyvsp[0].typ)).sz;
}
#line 3528 "parser.tab.c"
    break;

  case 32:
#line 1170 "parser.y"
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
  // ($$).sz = (string((char*)($1).str)).size();
  ((yyval.typ)).sz = 8;
}
#line 3573 "parser.tab.c"
    break;

  case 33:
#line 1212 "parser.y"
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
    // ($$).sz = ($1).sz + 1 + (string((char*)(($3).str))).size();
    ((yyval.typ)).sz = 8;
    // cout<<"GGG"<<($$).type<<'\n';
}
#line 3621 "parser.tab.c"
    break;

  case 34:
#line 1256 "parser.y"
                                      {
}
#line 3628 "parser.tab.c"
    break;

  case 35:
#line 1258 "parser.y"
                    {
}
#line 3635 "parser.tab.c"
    break;

  case 36:
#line 1260 "parser.y"
                                     {
}
#line 3642 "parser.tab.c"
    break;

  case 37:
#line 1262 "parser.y"
                  {
}
#line 3649 "parser.tab.c"
    break;

  case 38:
#line 1264 "parser.y"
                                                        {
}
#line 3656 "parser.tab.c"
    break;

  case 39:
#line 1266 "parser.y"
                                     {
}
#line 3663 "parser.tab.c"
    break;

  case 40:
#line 1268 "parser.y"
                    { 
}
#line 3670 "parser.tab.c"
    break;

  case 41:
#line 1272 "parser.y"
                  {
  // isimport=0;
}
#line 3678 "parser.tab.c"
    break;

  case 42:
#line 1275 "parser.y"
                                      {
  // isimport=0;
}
#line 3686 "parser.tab.c"
    break;

  case 43:
#line 1280 "parser.y"
                {
}
#line 3693 "parser.tab.c"
    break;

  case 44:
#line 1282 "parser.y"
                                  {
}
#line 3700 "parser.tab.c"
    break;

  case 45:
#line 1286 "parser.y"
                       {isclassaccess=0; issystem=0;isfinal=0;     
}
#line 3707 "parser.tab.c"
    break;

  case 46:
#line 1289 "parser.y"
                            {
}
#line 3714 "parser.tab.c"
    break;

  case 47:
#line 1291 "parser.y"
                               {
}
#line 3721 "parser.tab.c"
    break;

  case 48:
#line 1294 "parser.y"
                    {
  isimport = 1;
}
#line 3729 "parser.tab.c"
    break;

  case 49:
#line 1299 "parser.y"
                           {isclassaccess=0;issystem=0;isfinal=0;isimport=0;    
}
#line 3736 "parser.tab.c"
    break;

  case 50:
#line 1302 "parser.y"
                                    {isclassaccess=0;issystem=0;isfinal=0;isimport=0;    
}
#line 3743 "parser.tab.c"
    break;

  case 51:
#line 1305 "parser.y"
                 {
  isimport=0;
}
#line 3751 "parser.tab.c"
    break;

  case 52:
#line 1308 "parser.y"
                      {
  isimport=0;
}
#line 3759 "parser.tab.c"
    break;

  case 53:
#line 1311 "parser.y"
           {isclassaccess=0;issystem=0;isfinal=0;    
}
#line 3766 "parser.tab.c"
    break;

  case 54:
#line 1314 "parser.y"
         {
}
#line 3773 "parser.tab.c"
    break;

  case 55:
#line 1316 "parser.y"
                    {
}
#line 3780 "parser.tab.c"
    break;

  case 56:
#line 1319 "parser.y"
        {
}
#line 3787 "parser.tab.c"
    break;

  case 57:
#line 1321 "parser.y"
           {
}
#line 3794 "parser.tab.c"
    break;

  case 58:
#line 1323 "parser.y"
         {
  isprivate=1;
  isfieldprivate=1;
}
#line 3803 "parser.tab.c"
    break;

  case 59:
#line 1327 "parser.y"
        {
  isstatic=1;
}
#line 3811 "parser.tab.c"
    break;

  case 60:
#line 1330 "parser.y"
          {
}
#line 3818 "parser.tab.c"
    break;

  case 61:
#line 1332 "parser.y"
        { isfinal=1;
}
#line 3825 "parser.tab.c"
    break;

  case 62:
#line 1334 "parser.y"
         {
}
#line 3832 "parser.tab.c"
    break;

  case 63:
#line 1336 "parser.y"
               {
}
#line 3839 "parser.tab.c"
    break;

  case 64:
#line 1338 "parser.y"
            {
}
#line 3846 "parser.tab.c"
    break;

  case 65:
#line 1340 "parser.y"
          {
}
#line 3853 "parser.tab.c"
    break;

  case 66:
#line 1344 "parser.y"
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
#line 3874 "parser.tab.c"
    break;

  case 67:
#line 1360 "parser.y"
          {
classfield[curr_class] = fieldvar;
 fieldvar.clear();
  curr_table->classwidth = offset;
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  offset = offsets.top(); offsets.pop();
  objects.clear();
  emit("FLD",fielddeclistlast+"|","","",-1);
  fielddeclistlast="";
  fielddeclist="";
  emit("EndClass","","","",-1);
}
#line 3892 "parser.tab.c"
    break;

  case 68:
#line 1373 "parser.y"
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
#line 3925 "parser.tab.c"
    break;

  case 69:
#line 1401 "parser.y"
          {
classfield[curr_class] = fieldvar;
 fieldvar.clear();
  curr_table->classwidth = offset;
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  offset = offsets.top(); offsets.pop();
  objects.clear();
  emit("FLD",fielddeclistlast+"|","","",-1);
  fielddeclistlast="";
  fielddeclist="";
  emit("EndClass","","","",-1);
}
#line 3943 "parser.tab.c"
    break;

  case 70:
#line 1414 "parser.y"
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
#line 3976 "parser.tab.c"
    break;

  case 71:
#line 1442 "parser.y"
          {
classfield[curr_class] = fieldvar;
 fieldvar.clear();
  curr_table->classwidth = offset;
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  offset = offsets.top(); offsets.pop();
  objects.clear();
  emit("FLD",fielddeclistlast+"|","","",-1);
  fielddeclistlast="";
  fielddeclist="";
  emit("EndClass","","","",-1);
}
#line 3994 "parser.tab.c"
    break;

  case 72:
#line 1455 "parser.y"
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
#line 4015 "parser.tab.c"
    break;

  case 73:
#line 1471 "parser.y"
          {
classfield[curr_class] = fieldvar;
 fieldvar.clear();
  curr_table->classwidth = offset;
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  offset = offsets.top(); offsets.pop();
  objects.clear();
  emit("FLD",fielddeclistlast+"|","","",-1);
  fielddeclistlast="";
  fielddeclist="";
  emit("EndClass","","","",-1);
}
#line 4033 "parser.tab.c"
    break;

  case 74:
#line 1484 "parser.y"
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
#line 4054 "parser.tab.c"
    break;

  case 75:
#line 1500 "parser.y"
          {
classfield[curr_class] = fieldvar;
 fieldvar.clear();
  curr_table->classwidth = offset;
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  offset = offsets.top(); offsets.pop();
  objects.clear();
  emit("FLD",fielddeclistlast+"|","","",-1);
  fielddeclistlast="";
  fielddeclist="";
  emit("EndClass","","","",-1);
}
#line 4072 "parser.tab.c"
    break;

  case 76:
#line 1513 "parser.y"
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
#line 4106 "parser.tab.c"
    break;

  case 77:
#line 1542 "parser.y"
          {
classfield[curr_class] = fieldvar;
 fieldvar.clear();
  curr_table->classwidth = offset;
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  offset = offsets.top(); offsets.pop();
  objects.clear();
  emit("FLD",fielddeclistlast+"|","","",-1);
  fielddeclistlast="";
  fielddeclist="";
  emit("EndClass","","","",-1);
}
#line 4124 "parser.tab.c"
    break;

  case 78:
#line 1555 "parser.y"
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
#line 4145 "parser.tab.c"
    break;

  case 79:
#line 1571 "parser.y"
          {
classfield[curr_class] = fieldvar;
 fieldvar.clear();
  curr_table->classwidth = offset;
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  offset = offsets.top(); offsets.pop();
  objects.clear();
  emit("FLD",fielddeclistlast+"|","","",-1);
  fielddeclistlast="";
  fielddeclist="";
  emit("EndClass","","","",-1);
}
#line 4163 "parser.tab.c"
    break;

  case 80:
#line 1584 "parser.y"
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
#line 4197 "parser.tab.c"
    break;

  case 81:
#line 1613 "parser.y"
          {
classfield[curr_class] = fieldvar;
 fieldvar.clear();
  curr_table->classwidth = offset;
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  offset = offsets.top(); offsets.pop();
  objects.clear();
  emit("FLD",fielddeclistlast+"|","","",-1);
  fielddeclistlast="";
  fielddeclist="";
  emit("EndClass","","","",-1);
}
#line 4215 "parser.tab.c"
    break;

  case 82:
#line 1627 "parser.y"
                  {
  
  
  
}
#line 4225 "parser.tab.c"
    break;

  case 83:
#line 1633 "parser.y"
                             {
  
  
  
}
#line 4235 "parser.tab.c"
    break;

  case 84:
#line 1639 "parser.y"
              {
  
  
}
#line 4244 "parser.tab.c"
    break;

  case 85:
#line 1643 "parser.y"
                                       {
  
  
  
  
}
#line 4255 "parser.tab.c"
    break;

  case 86:
#line 1650 "parser.y"
                                                         {
  isprivate=0;
  fieldcount=0;
}
#line 4264 "parser.tab.c"
    break;

  case 87:
#line 1654 "parser.y"
                                    {
  isprivate=0;
  fieldcount=0;
}
#line 4273 "parser.tab.c"
    break;

  case 88:
#line 1659 "parser.y"
                     {
  
  
}
#line 4282 "parser.tab.c"
    break;

  case 89:
#line 1663 "parser.y"
                                            {
  
  
  
}
#line 4292 "parser.tab.c"
    break;

  case 90:
#line 1669 "parser.y"
                       {
  
  
}
#line 4301 "parser.tab.c"
    break;

  case 91:
#line 1673 "parser.y"
                   {
  isstatic=0;
}
#line 4309 "parser.tab.c"
    break;

  case 92:
#line 1676 "parser.y"
                        {
  
  
}
#line 4318 "parser.tab.c"
    break;

  case 93:
#line 1681 "parser.y"
                 {
  fielddeclist="";
  // fielddeclistlast+=fielddeclist;
  fieldcount=lastfieldcount;
  
}
#line 4329 "parser.tab.c"
    break;

  case 94:
#line 1687 "parser.y"
                   {
  fielddeclist="";
  // fielddeclistlast+=fielddeclist;
  fieldcount=lastfieldcount;
  
}
#line 4340 "parser.tab.c"
    break;

  case 95:
#line 1694 "parser.y"
                                             { 
  // fielddeclist+="#";
  fielddeclistlast+=fielddeclist;
  lastfieldcount=fieldcount;
  fielddeclist="";
  // fieldcount=0;
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
      // emit("=", "[rbp+" + to_string(offset + 16) + "]", "null", tempparam[i], -1);
      fieldvar.push_back({funcparam[i].first, offset});
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
#line 4401 "parser.tab.c"
    break;

  case 96:
#line 1750 "parser.y"
                                    { 
  // fielddeclist+="#";
  fielddeclistlast+=fielddeclist;
  lastfieldcount=fieldcount;
  fielddeclist="";  
  // fieldcount=0;
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
      // emit("=", "[rbp+" + to_string(offset + 16) + "]", "null", tempparam[i], -1);
      fieldvar.push_back({funcparam[i].first, offset});
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
#line 4456 "parser.tab.c"
    break;

  case 97:
#line 1801 "parser.y"
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
#line 4493 "parser.tab.c"
    break;

  case 98:
#line 1833 "parser.y"
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
#line 4574 "parser.tab.c"
    break;

  case 99:
#line 1910 "parser.y"
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
#line 4629 "parser.tab.c"
    break;

  case 100:
#line 1961 "parser.y"
                                                {  
  // cout<<"I was here"<<($1).type<<endl;
//   curr_table->entry(string((char*)($1).type), "Identifier", type, offset, curr_scope, yylineno, -1);
//   offset += sz;
// cout<<($1).tempvar<<" "<<($3).tempvar<<endl;
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
    // cout<<($1).tempvar<<" "<<($3).tempvar<<endl;
    emit("=", to_string(sizealloc), "null", tv4, -1);
    emit("param",tv4,"","",-1);
    // emit("stackpointer","+" + to_string(sizealloc),"","",-1);
    // emit("add", "rsp", to_string(sizealloc), "", -1);
    emit("call","allocmem","1","",-1);
    // emit("stackpointer","-" + to_string(sizealloc),"","",-1);
    // // emit("sub", "rsp", to_string(sizealloc), "", -1);
    string tv2 = newtemp();
    emit("=", "popparam", "null", tv2, -1);
    strcpy(((yyval.typ)).tempvar, tv2.c_str());
    objtotemp[string((char*)(((yyvsp[-2].typ)).type))] = tv2;
 }
  else{
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);
  // cout<<($1).tempvar<<" "<<($3).tempvar<<endl;
  if(vartottemp[string((char*)(((yyvsp[-2].typ)).type))] != ""){
    objtotemp[vartottemp[string((char*)(((yyvsp[-2].typ)).type))]] = string((char*)(((yyvsp[0].typ)).tempvar));
  }
  else{
    objtotemp[string((char*)(((yyvsp[-2].typ)).type))] = string((char*)(((yyvsp[0].typ)).tempvar));
  }
    // emit("=", ($3).tempvar, "null", ($1).tempvar, -1);

  }
  // objtotemp[string((char*)(($1).type))] = string((char*)(($3).tempvar));
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
  funcparam.push_back({string((char*)((yyvsp[-2].typ)).type), {type, -2}});
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
#line 4770 "parser.tab.c"
    break;

  case 101:
#line 2098 "parser.y"
           {
  curridf = string((char*)(((yyvsp[0].lex)).str));
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].lex)).str);

  strcpy(((yyval.typ)).type,((yyvsp[0].lex)).str);
  ndim=0;
}
#line 4782 "parser.tab.c"
    break;

  case 102:
#line 2105 "parser.y"
                      {
  type  = type + "[]";
  ndim=ndim+1;
  // type = "Array";
}
#line 4792 "parser.tab.c"
    break;

  case 103:
#line 2109 "parser.y"
                                       {
  
  // ($$).ndim=ndim;
}
#line 4801 "parser.tab.c"
    break;

  case 104:
#line 2115 "parser.y"
           {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);

  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
  if(!flagyo) ((yyval.typ)).ndim=0;
  else ((yyval.typ)).ndim=((yyvsp[0].typ)).ndim;
  // cout<<"YO"<<($$).ndim<<'\n';

}
#line 4815 "parser.tab.c"
    break;

  case 105:
#line 2124 "parser.y"
                  {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);

  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
  ((yyval.typ)).ndim=((yyvsp[0].typ)).ndim;
}
#line 4826 "parser.tab.c"
    break;

  case 106:
#line 2132 "parser.y"
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
#line 4846 "parser.tab.c"
    break;

  case 107:
#line 2147 "parser.y"
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
#line 4868 "parser.tab.c"
    break;

  case 108:
#line 2167 "parser.y"
                                       {
// emit("BeginFunc","","","",-1);
// emit("push","rbp","","",-1);
// emit("=", "rsp", "null", "rbp", -1);
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
    numfuncargs[curr_class + "_" + curr_func] = funcparam.size();
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
      // // emit("sub","rsp",to_string(sizeparam[i]),"",-1);
      // // emit("sub", "rsp", to_string(sizeparam[i]), "", -1);
totalstack += sizeparam[i];
      // emit("=", "[rbp+" + to_string(offset + 16) + "]", "null", tempparam[i], -1);
      vartottemp[tempparam[i]] =  "[rbp-" + to_string(offset + 8) + "]";
      vartostack[{tempparam[i], curr_class + "_" + curr_func}] =   "[rbp-" + to_string(offset + 8) + "]";
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
#line 4935 "parser.tab.c"
    break;

  case 109:
#line 2229 "parser.y"
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
    numfuncargs[curr_class + "_" + curr_func] = funcparam.size();
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
      // // emit("sub","rsp",to_string(sizeparam[i]),"",-1);
      // // emit("sub", "rsp", to_string(sizeparam[i]), "", -1);

totalstack += sizeparam[i];
      // emit("=", "[rbp+" + to_string(offset + 16) + "]", "null", tempparam[i], -1);
      vartottemp[tempparam[i]] =  "[rbp-" + to_string(offset + 8) + "]";
      vartostack[{tempparam[i], curr_class + "_" + curr_func}] =   "[rbp-" + to_string(offset + 8) + "]";
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
#line 5001 "parser.tab.c"
    break;

  case 110:
#line 2290 "parser.y"
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
    numfuncargs[curr_class + "_" + curr_func] = funcparam.size();
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
      // // emit("sub","rsp",to_string(sizeparam[i]),"",-1);
      // // emit("sub", "rsp", to_string(sizeparam[i]), "", -1);
totalstack += sizeparam[i];
      // emit("=", "[rbp+" + to_string(offset + 16) + "]", "null", tempparam[i], -1);
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
#line 5061 "parser.tab.c"
    break;

  case 111:
#line 2345 "parser.y"
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
    numfuncargs[curr_class + "_" + curr_func] = funcparam.size();
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
      // // emit("sub","rsp",to_string(sizeparam[i]),"",-1);
      // // emit("sub", "rsp", to_string(sizeparam[i]), "", -1);
totalstack += sizeparam[i];
      // emit("=", "[rbp+" + to_string(offset + 16) + "]", "null", tempparam[i], -1);
      vartottemp[tempparam[i]] =  "[rbp-" + to_string(offset + 8) + "]";
      vartostack[{tempparam[i], curr_class + "_" + curr_func}] =   "[rbp-" + to_string(offset + 8) + "]";
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
#line 5122 "parser.tab.c"
    break;

  case 112:
#line 2401 "parser.y"
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
    numfuncargs[curr_class + "_" + curr_func] = funcparam.size();
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
      // // emit("sub","rsp",to_string(sizeparam[i]),"",-1);
      // // emit("sub", "rsp", to_string(sizeparam[i]), "", -1);
totalstack += sizeparam[i];
      // emit("=", "[rbp+" + to_string(offset + 16) + "]", "null", tempparam[i], -1);
      vartottemp[tempparam[i]] =  "[rbp-" + to_string(offset + 8) + "]";
      vartostack[{tempparam[i], curr_class + "_" + curr_func}] =   "[rbp-" + to_string(offset + 8) + "]";
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
#line 5181 "parser.tab.c"
    break;

  case 113:
#line 2455 "parser.y"
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
    numfuncargs[curr_class + "_" + curr_func] = funcparam.size();
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
      // // emit("sub","rsp",to_string(sizeparam[i]),"",-1);
      // emit("sub", "rsp", to_string(sizeparam[i]), "", -1);
totalstack += sizeparam[i];
      // emit("=", "[rbp+" + to_string(offset + 16) + "]", "null", tempparam[i], -1);
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
#line 5237 "parser.tab.c"
    break;

  case 114:
#line 2506 "parser.y"
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
    numfuncargs[curr_class + "_" + curr_func] = funcparam.size();
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
      // // emit("sub","rsp",to_string(sizeparam[i]),"",-1);
      // emit("sub", "rsp", to_string(sizeparam[i]), "", -1);
totalstack += sizeparam[i];
      // emit("=", "[rbp+" + to_string(offset + 16) + "]", "null", tempparam[i], -1);
      vartottemp[tempparam[i]] =  "[rbp-" + to_string(offset + 8) + "]";
      vartostack[{tempparam[i], curr_class + "_" + curr_func}] =   "[rbp-" + to_string(offset + 8) + "]";
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
#line 5299 "parser.tab.c"
    break;

  case 115:
#line 2563 "parser.y"
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
    numfuncargs[curr_class + "_" + curr_func] = funcparam.size();
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
      // // emit("sub","rsp",to_string(sizeparam[i]),"",-1);
      // emit("sub", "rsp", to_string(sizeparam[i]), "", -1);
totalstack += sizeparam[i];
      // emit("=", "[rbp+" + to_string(offset + 16) + "]", "null", tempparam[i], -1);
      vartottemp[tempparam[i]] =  "[rbp-" + to_string(offset + 8) + "]";
      vartostack[{tempparam[i], curr_class + "_" + curr_func}] =   "[rbp-" + to_string(offset + 8) + "]";
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
#line 5357 "parser.tab.c"
    break;

  case 116:
#line 2618 "parser.y"
                                    {
  emit(((yyvsp[-2].lex)).str,":","","",-1);
  emit("BeginFunc","","","",-1);
  //emit("BeginFunc",to_string(getfuncwidth(string((char*)($1).type))),"","",-1);
  emit("push","rbp","","",-1);
  emit("=", "rsp", "null", "rbp", -1);
  strcpy(((yyval.typ)).type,((yyvsp[-2].lex)).str);
  ((yyval.typ)).nelem=0;
  if(!strcmp(((yyvsp[-2].lex)).str,"main"))
  {
    ismainstatic=1;
    isvoid=1;
  }
  curr_func = string((char*)((yyvsp[-2].lex)).str);
}
#line 5377 "parser.tab.c"
    break;

  case 117:
#line 2633 "parser.y"
                                                         {
  emit(((yyvsp[-3].lex)).str,":","","",-1);

  emit("BeginFunc","","","",-1);
  emit("push","rbp","","",-1);
  emit("=", "rsp", "null", "rbp", -1);

  strcpy(((yyval.typ)).type,((yyvsp[-3].lex)).str);
  ((yyval.typ)).nelem=((yyvsp[-1].typ)).nelem;
  if(!strcmp(((yyvsp[-3].lex)).str,"main"))
  {
    ismainstatic=1;
    isvoid=1;
  }
  curr_func = string((char*)((yyvsp[-3].lex)).str);
}
#line 5398 "parser.tab.c"
    break;

  case 118:
#line 2649 "parser.y"
                                                       {

}
#line 5406 "parser.tab.c"
    break;

  case 119:
#line 2653 "parser.y"
                {
  ((yyval.typ)).nelem=1;
}
#line 5414 "parser.tab.c"
    break;

  case 120:
#line 2656 "parser.y"
                                           {
  ((yyval.typ)).nelem=((yyvsp[-2].typ)).nelem+1;
}
#line 5422 "parser.tab.c"
    break;

  case 121:
#line 2660 "parser.y"
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
#line 5445 "parser.tab.c"
    break;

  case 122:
#line 2679 "parser.y"
                     {
}
#line 5452 "parser.tab.c"
    break;

  case 123:
#line 2682 "parser.y"
           {
}
#line 5459 "parser.tab.c"
    break;

  case 124:
#line 2684 "parser.y"
                               {
}
#line 5466 "parser.tab.c"
    break;

  case 125:
#line 2688 "parser.y"
       {
    if(ispopped == 1){
    if(totalstack != 0){  ;}
emit("pop","rbp","","",-1);
    ispopped = 0;totalstack = 0;
emit("ret","","","",-1);
  }
  funcsize[curr_class + "_"  + curr_func] = offset;
  emit("EndFunc","","","",-1);
  ispopped = 1;
  
  infunction=1;
}
#line 5484 "parser.tab.c"
    break;

  case 126:
#line 2701 "parser.y"
           {   
  newdim.clear(); 
    if(ispopped == 1){
    if(totalstack != 0){ emit("add", "rsp", to_string(totalstack), "", -1); ;}
emit("pop","rbp","","",-1);
    ispopped = 0;totalstack = 0;
emit("ret","","","",-1);
  }
  emit("EndFunc","","","",-1);
  funcsize[curr_class + "_"  + curr_func] = offset;
  ispopped = 1;
  
  infunction=1;
  isclassaccess=0;
  isfinal=0;
  issystem=0;
}
#line 5506 "parser.tab.c"
    break;

  case 127:
#line 2719 "parser.y"
       {isstatic=1;}
#line 5512 "parser.tab.c"
    break;

  case 128:
#line 2719 "parser.y"
                           {
  // cout<<"YIS"<<isstatic<<'\n';
}
#line 5520 "parser.tab.c"
    break;

  case 129:
#line 2723 "parser.y"
                                                       {
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  offset = offsets.top(); offsets.pop();
  isfieldprivate=0;
  nelem=0;
  
}
#line 5533 "parser.tab.c"
    break;

  case 130:
#line 2731 "parser.y"
                                                 {
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  offset = offsets.top(); offsets.pop();
  isfieldprivate=0;
  nelem=0;
  
}
#line 5546 "parser.tab.c"
    break;

  case 131:
#line 2739 "parser.y"
                                              {
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  offset = offsets.top(); offsets.pop();
  nelem=0;
  
}
#line 5558 "parser.tab.c"
    break;

  case 132:
#line 2746 "parser.y"
                                       {
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  offset = offsets.top(); offsets.pop();
  nelem=0;
  
}
#line 5570 "parser.tab.c"
    break;

  case 133:
#line 2754 "parser.y"
                                         {
  emit("BeginCtor","","","",-1);
  curr_func = string((char*)(((yyvsp[-1].typ)).type));
}
#line 5579 "parser.tab.c"
    break;

  case 134:
#line 2760 "parser.y"
                                                   {
  emit("push","rbp","","",-1);
  emit("=", "rsp", "null", "rbp", -1);
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
    numfuncargs[curr_class + "_" + curr_func] = funcparam.size();
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
      // // emit("sub","rsp",to_string(sizeparam[i]),"",-1);
      totalstack += sizeparam[i];
      // emit("=", "[rbp+" + to_string(offset + 16) + "]", "null", tempparam[i], -1);
      // offset += sizeparam[i];
      // curr_table->classwidth = offset;
       vartottemp[tempparam[i]] =  "[rbp-" + to_string(offset + 8) + "]";
      vartostack[{tempparam[i], curr_class + "_" + curr_func}] =   "[rbp-" + to_string(offset + 8) + "]";
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
#line 5639 "parser.tab.c"
    break;

  case 135:
#line 2815 "parser.y"
                        {
  emit("BeginCtor","","","",-1);
  emit("push","rbp","","",-1);
  emit("=", "rsp", "null", "rbp", -1);
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
#line 5660 "parser.tab.c"
    break;

  case 136:
#line 2831 "parser.y"
             {
  
  
  
  
}
#line 5671 "parser.tab.c"
    break;

  case 137:
#line 2839 "parser.y"
                                                                                 {
  
  if(ispopped == 1){
    if(totalstack != 0){ ;}
emit("pop","rbp","","",-1);
    ispopped = 0;totalstack = 0;
emit("ret","","","",-1);
  }
  emit("EndCtor","","","",-1);
  ispopped = 1;
  
  
  
  
}
#line 5691 "parser.tab.c"
    break;

  case 138:
#line 2854 "parser.y"
                                                    {
  
  if(ispopped == 1){
    if(totalstack != 0){ emit("add", "rsp", to_string(totalstack), "", -1); ;}
emit("pop","rbp","","",-1);
    ispopped = 0;totalstack = 0;
emit("ret","","","",-1);
  }
  emit("EndCtor","","","",-1);
  ispopped = 1;
  
  
}
#line 5709 "parser.tab.c"
    break;

  case 139:
#line 2867 "parser.y"
                                                                  {
  
  if(ispopped == 1){
    if(totalstack != 0){ emit("add", "rsp", to_string(totalstack), "", -1); ;}
emit("pop","rbp","","",-1);
    ispopped = 0;totalstack = 0;
emit("ret","","","",-1);
  }
  emit("EndCtor","","","",-1);
  ispopped = 1;
  
}
#line 5726 "parser.tab.c"
    break;

  case 140:
#line 2879 "parser.y"
                                    {
  
  if(ispopped == 1){
    if(totalstack != 0){ emit("add", "rsp", to_string(totalstack), "", -1); ;}
emit("pop","rbp","","",-1);
    ispopped = 0;totalstack = 0;
emit("ret","","","",-1);
  }
  emit("EndCtor","","","",-1);
  ispopped = 1;
}
#line 5742 "parser.tab.c"
    break;

  case 141:
#line 2891 "parser.y"
                                                     {    
  newdim.clear();
  isclassaccess=0;
  isfinal=0;
  issystem=0;
  
  
  
  
}
#line 5757 "parser.tab.c"
    break;

  case 142:
#line 2901 "parser.y"
                                         {    
  isclassaccess=0;
  newdim.clear();
  isfinal=0;
  issystem=0;
  
  
}
#line 5770 "parser.tab.c"
    break;

  case 143:
#line 2909 "parser.y"
                                                       {    
    isclassaccess=0;
  issystem=0;
  newdim.clear();
  
  isfinal=0;
  
}
#line 5783 "parser.tab.c"
    break;

  case 144:
#line 2917 "parser.y"
                                          {    
    isclassaccess=0;
  issystem=0;
  newdim.clear();
  isfinal=0;
  
}
#line 5795 "parser.tab.c"
    break;

  case 145:
#line 2925 "parser.y"
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
#line 5813 "parser.tab.c"
    break;

  case 146:
#line 2938 "parser.y"
              {
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  offset = offsets.top(); offsets.pop();
  
  
  
  
  
  
}
#line 5829 "parser.tab.c"
    break;

  case 147:
#line 2949 "parser.y"
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
#line 5846 "parser.tab.c"
    break;

  case 148:
#line 2961 "parser.y"
              {
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  offset = offsets.top(); offsets.pop();
  
  
  
  
  
}
#line 5861 "parser.tab.c"
    break;

  case 149:
#line 2971 "parser.y"
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
#line 5879 "parser.tab.c"
    break;

  case 150:
#line 2984 "parser.y"
              {
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  offset = offsets.top(); offsets.pop();
}
#line 5889 "parser.tab.c"
    break;

  case 151:
#line 2989 "parser.y"
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
#line 5906 "parser.tab.c"
    break;

  case 152:
#line 3001 "parser.y"
              {
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  offset = offsets.top(); offsets.pop();
  
  
  
  
}
#line 5920 "parser.tab.c"
    break;

  case 153:
#line 3011 "parser.y"
                      {
  
  
  
  }
#line 5930 "parser.tab.c"
    break;

  case 154:
#line 3016 "parser.y"
                                       {
  
  
  
  
  }
#line 5941 "parser.tab.c"
    break;

  case 155:
#line 3023 "parser.y"
                                   {
  
  
  
  }
#line 5951 "parser.tab.c"
    break;

  case 156:
#line 3028 "parser.y"
                                                                {
  
  
  
  
  }
#line 5962 "parser.tab.c"
    break;

  case 157:
#line 3035 "parser.y"
                           {
  
  
  }
#line 5971 "parser.tab.c"
    break;

  case 158:
#line 3039 "parser.y"
                                                        {
  
  
  
  }
#line 5981 "parser.tab.c"
    break;

  case 159:
#line 3045 "parser.y"
                    {
  
  
  }
#line 5990 "parser.tab.c"
    break;

  case 160:
#line 3049 "parser.y"
                           {
  
  
  }
#line 5999 "parser.tab.c"
    break;

  case 161:
#line 3054 "parser.y"
                 {
  
  
  }
#line 6008 "parser.tab.c"
    break;

  case 162:
#line 3059 "parser.y"
                       {    
  newdim.clear();
  isfinal=0;
  isclassaccess=0;
    issystem=0;
}
#line 6019 "parser.tab.c"
    break;

  case 163:
#line 3067 "parser.y"
                                                              {
  strcpy(((yyval.typ)).tempvar, strcat(((yyvsp[-3].lex)).str, strcat(((yyvsp[-2].typ)).tempvar, strcat(((yyvsp[-1].lex)).str, ((yyvsp[0].lex)).str))));
  arrinit=1;
  strcpy(((yyval.typ)).type,((yyvsp[-2].typ)).type);
  // ($$).nelem=($2).nelem;
  ((yyval.typ)).ndim=((yyvsp[-2].typ)).ndim+1;
  shape[((yyval.typ)).ndim].push_back(((yyvsp[-2].typ)).nelem);
  // cout<<($$).ndim<<'\n';
}
#line 6033 "parser.tab.c"
    break;

  case 164:
#line 3076 "parser.y"
                                          {
  strcpy(((yyval.typ)).tempvar, strcat(((yyvsp[-2].lex)).str, strcat(((yyvsp[-1].lex)).str, ((yyvsp[0].lex)).str)));
  arrinit=1;
  strcpy(((yyval.typ)).type,"Dishay");
  // ($$).nelem=0;
  ((yyval.typ)).ndim=1;
  shape[((yyval.typ)).ndim].push_back(0);
  // cout<<($$).ndim<<'\n';
  
  }
#line 6048 "parser.tab.c"
    break;

  case 165:
#line 3086 "parser.y"
                                                         {
  strcpy(((yyval.typ)).tempvar, strcat(((yyvsp[-2].lex)).str, strcat(((yyvsp[-1].typ)).tempvar, ((yyvsp[0].lex)).str)));
  arrinit=1;
  strcpy(((yyval.typ)).type,((yyvsp[-1].typ)).type);
  // ($$).nelem=($2).nelem;
  ((yyval.typ)).ndim=((yyvsp[-1].typ)).ndim+1;
  shape[((yyval.typ)).ndim].push_back(((yyvsp[-1].typ)).nelem);
  }
#line 6061 "parser.tab.c"
    break;

  case 166:
#line 3094 "parser.y"
                                    {
  strcpy(((yyval.typ)).tempvar, strcat(((yyvsp[-1].lex)).str, ((yyvsp[0].lex)).str));
  arrinit=1;
  strcpy(((yyval.typ)).type,"Dishay");
  // ($$).nelem=0;
  ((yyval.typ)).ndim=1;
  shape[((yyval.typ)).ndim].push_back(0);
  // cout<<"OPENCURLYBRACKET CLOSECURLYBRACKET"<<($$).ndim<<'\n';
  
  
  }
#line 6077 "parser.tab.c"
    break;

  case 167:
#line 3106 "parser.y"
                    {
  strcpy(((yyval.typ)).tempvar,((yyvsp[0].typ)).tempvar);
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
  ((yyval.typ)).ndim=((yyvsp[0].typ)).ndim;
  // shape[($1).ndim+1].back()+=1;
  ((yyval.typ)).nelem=1;
  
  }
#line 6090 "parser.tab.c"
    break;

  case 168:
#line 3114 "parser.y"
                                                {
  strcpy(((yyval.typ)).tempvar, strcat(strcat(((yyvsp[-2].typ)).tempvar,","),((yyvsp[0].typ)).tempvar));
  strcpy(((yyval.typ)).type,getorder(((yyvsp[-2].typ)).type,((yyvsp[0].typ)).type,1).c_str());
  ((yyval.typ)).ndim=((yyvsp[-2].typ)).ndim;
  // shape[($1).ndim+1].back()+=1;
  ((yyval.typ)).nelem=((yyvsp[-2].typ)).nelem+1;
  // cout<<"types "<<($1).type<<" "<<($3).type<<" "<<($$).type<<'\n';
  
  }
#line 6104 "parser.tab.c"
    break;

  case 169:
#line 3124 "parser.y"
                                                   {
  
  
  
  
  }
#line 6115 "parser.tab.c"
    break;

  case 170:
#line 3130 "parser.y"
                                    {
  
  
  
  }
#line 6125 "parser.tab.c"
    break;

  case 171:
#line 3136 "parser.y"
               {
  
  
  }
#line 6134 "parser.tab.c"
    break;

  case 172:
#line 3140 "parser.y"
                                {
  
  
  
  }
#line 6144 "parser.tab.c"
    break;

  case 173:
#line 3146 "parser.y"
                                  {
  
  
  }
#line 6153 "parser.tab.c"
    break;

  case 174:
#line 3150 "parser.y"
           {
  
  
  }
#line 6162 "parser.tab.c"
    break;

  case 175:
#line 3155 "parser.y"
                                   {    
  newdim.clear();
  isclassaccess=0;
  type="";
    issystem=0;
  }
#line 6173 "parser.tab.c"
    break;

  case 176:
#line 3162 "parser.y"
{    
  newdim.clear();
   isclassaccess=0;
  type="";
    issystem=0;
    isfinal=0;
}
#line 6185 "parser.tab.c"
    break;

  case 177:
#line 3171 "parser.y"
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
      totalstack += sizeparam[i];
      if(funcparam[i].second.second!=-1){
          // // emit("sub","rsp",to_string(sizeparam[i]),"",-1);
          // cout<<tempparam[i]<<" HEYA"<<endl;
          emit("=", tempparam[i] , "null",  "[rbp" + to_string(-(offset + 8)) + "]" , -1);
      }
      vartostack[{funcparam[i].first, curr_class + "_" + curr_func}] =   "[rbp" + to_string(-(offset + 8)) + "]";
      vartottemp[funcparam[i].first] = "[rbp-" + to_string(offset + 8) + "]";
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
#line 6263 "parser.tab.c"
    break;

  case 178:
#line 3245 "parser.y"
                                     {
  
  
  }
#line 6272 "parser.tab.c"
    break;

  case 179:
#line 3249 "parser.y"
                  {
  
  
  }
#line 6281 "parser.tab.c"
    break;

  case 180:
#line 3253 "parser.y"
                 {
  
  
  }
#line 6290 "parser.tab.c"
    break;

  case 181:
#line 3257 "parser.y"
                     {
  
  
  }
#line 6299 "parser.tab.c"
    break;

  case 182:
#line 3261 "parser.y"
                {
  
  
  }
#line 6308 "parser.tab.c"
    break;

  case 183:
#line 3265 "parser.y"
              {
  
  
  }
#line 6317 "parser.tab.c"
    break;

  case 184:
#line 3270 "parser.y"
                                     {
  
  
  }
#line 6326 "parser.tab.c"
    break;

  case 185:
#line 3274 "parser.y"
                           {
  
  
  }
#line 6335 "parser.tab.c"
    break;

  case 186:
#line 3278 "parser.y"
                              {
  
  
  }
#line 6344 "parser.tab.c"
    break;

  case 187:
#line 3282 "parser.y"
                         {
  
  
  }
#line 6353 "parser.tab.c"
    break;

  case 188:
#line 3286 "parser.y"
                       {
  
  
  }
#line 6362 "parser.tab.c"
    break;

  case 189:
#line 3291 "parser.y"
      {
  
  
  }
#line 6371 "parser.tab.c"
    break;

  case 190:
#line 3295 "parser.y"
                {
  
  
  }
#line 6380 "parser.tab.c"
    break;

  case 191:
#line 3299 "parser.y"
                     {
  
  
  }
#line 6389 "parser.tab.c"
    break;

  case 192:
#line 3303 "parser.y"
                 {
  
  
  }
#line 6398 "parser.tab.c"
    break;

  case 193:
#line 3307 "parser.y"
             {
  
  
  }
#line 6407 "parser.tab.c"
    break;

  case 194:
#line 3311 "parser.y"
                {
  
  
  }
#line 6416 "parser.tab.c"
    break;

  case 195:
#line 3315 "parser.y"
                   {
  
  
  }
#line 6425 "parser.tab.c"
    break;

  case 196:
#line 3319 "parser.y"
                 {
  
  
  }
#line 6434 "parser.tab.c"
    break;

  case 197:
#line 3323 "parser.y"
                       {
  
  
  }
#line 6443 "parser.tab.c"
    break;

  case 198:
#line 3327 "parser.y"
                {
  
  
  }
#line 6452 "parser.tab.c"
    break;

  case 199:
#line 3331 "parser.y"
              {
  
  
  }
#line 6461 "parser.tab.c"
    break;

  case 200:
#line 3336 "parser.y"
          {    
    issystem=0;
  isclassaccess=0;
  isfinal=0;
}
#line 6471 "parser.tab.c"
    break;

  case 201:
#line 3342 "parser.y"
                           {
  if(curr_table->lookup(string((char*)((yyvsp[-2].lex)).str)).offset == -1  && checkobj(string((char*)((yyvsp[-2].lex)).str)) == 0){
    cout<<"Undeclared variable on line "<< yylineno<<"\n";
  }
}
#line 6481 "parser.tab.c"
    break;

  case 202:
#line 3348 "parser.y"
                                    {
  if(curr_table->lookup(string((char*)((yyvsp[-2].lex)).str)).offset == -1 && checkobj(string((char*)((yyvsp[-2].lex)).str)) == 0){
    cout<<"Undeclared variable on line "<< yylineno<<"\n";
  }
  }
#line 6491 "parser.tab.c"
    break;

  case 203:
#line 3354 "parser.y"
                              {    
  newdim.clear();
  strcpy(((yyval.typ)).type,((yyvsp[-1].typ)).type);
  strcpy(((yyval.typ)).tempvar, ((yyvsp[-1].typ)).tempvar);
    issystem=0;
  isclassaccess=0;
  isfinal=0;
  }
#line 6504 "parser.tab.c"
    break;

  case 204:
#line 3363 "parser.y"
           {
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);
  
  
  }
#line 6515 "parser.tab.c"
    break;

  case 205:
#line 3369 "parser.y"
                        {
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);
  
  
  }
#line 6526 "parser.tab.c"
    break;

  case 206:
#line 3375 "parser.y"
                        {
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);
  
  
  }
#line 6537 "parser.tab.c"
    break;

  case 207:
#line 3381 "parser.y"
                         {
  
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);
  
  }
#line 6548 "parser.tab.c"
    break;

  case 208:
#line 3387 "parser.y"
                         {
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);
  
  
  }
#line 6559 "parser.tab.c"
    break;

  case 209:
#line 3393 "parser.y"
                  {
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);
  

  
  }
#line 6571 "parser.tab.c"
    break;

  case 210:
#line 3400 "parser.y"
                                 {
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);
  
  
  }
#line 6582 "parser.tab.c"
    break;

  case 211:
#line 3406 "parser.y"
                                 {

  tables.push(curr_table);
  curr_table = new Sym_Table(curr_table);
  list_of_Symbol_Tables.push_back(curr_table);
  scope_names.push(curr_scope);
  string new_scope = "IfStatement";
  curr_scope = new_scope;
  // offsets.push(offset);
  // int new_offset = 0;
  // offset = new_offset;
}
#line 6599 "parser.tab.c"
    break;

  case 212:
#line 3419 "parser.y"
                         {
  tables.push(curr_table);
  curr_table = new Sym_Table(curr_table);
  list_of_Symbol_Tables.push_back(curr_table);
  scope_names.push(curr_scope);
  string new_scope = "ElseStatement";
  curr_scope = new_scope;
  // offsets.push(offset);
  // int new_offset = 0;
  // offset = new_offset;
}
#line 6615 "parser.tab.c"
    break;

  case 213:
#line 3431 "parser.y"
                                               {
  string a = newLabel();
  emit("Goto", ((yyvsp[0].typ)).tempvar, a, "Ifz", -1);
  strcpy(((yyval.typ)).gotoname,a.c_str());
}
#line 6625 "parser.tab.c"
    break;

  case 214:
#line 3438 "parser.y"
                                         {
  
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  // offset = offsets.top(); offsets.pop();
  string a = newLabel();
  emit("Goto", "", a, "", -1);
  // strcpy(($$).gotoname,a.c_str());
  emit(((yyvsp[-2].typ)).gotoname, ":", "", "", -1);
  emit(a, ":", "", "", -1);
}
#line 6641 "parser.tab.c"
    break;

  case 215:
#line 3450 "parser.y"
                                                                     {
  string a = newLabel();
  emit("Goto", "", a, "", -1);
  emit(((yyvsp[-2].typ)).gotoname, ":", "", "", -1);
  strcpy(((yyval.typ)).gotoname,a.c_str());
}
#line 6652 "parser.tab.c"
    break;

  case 216:
#line 3458 "parser.y"
                                               {
  emit(((yyvsp[-2].typ)).gotoname, ":", "", "", -1);

  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  // offset = offsets.top(); offsets.pop();
  
  }
#line 6665 "parser.tab.c"
    break;

  case 217:
#line 3467 "parser.y"
                                                        {
  emit(((yyvsp[-2].typ)).gotoname, ":", "", "", -1);

  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  offset = offsets.top(); offsets.pop();
  }
#line 6677 "parser.tab.c"
    break;

  case 218:
#line 3477 "parser.y"
                             {
  tables.push(curr_table);
  curr_table = new Sym_Table(curr_table);
  list_of_Symbol_Tables.push_back(curr_table);
  scope_names.push(curr_scope);
  string new_scope = "SwitchStatement";
  curr_scope = new_scope;
  // offsets.push(offset);
  // int new_offset = 0;
  // offset = new_offset;
}
#line 6693 "parser.tab.c"
    break;

  case 219:
#line 3489 "parser.y"
                                                                     {

  }
#line 6701 "parser.tab.c"
    break;

  case 220:
#line 3493 "parser.y"
                                                                           {
  
  
  
  
  
  }
#line 6713 "parser.tab.c"
    break;

  case 221:
#line 3500 "parser.y"
                                                 {
  
  
  
  
  }
#line 6724 "parser.tab.c"
    break;

  case 222:
#line 3506 "parser.y"
                                                               {
  
  
  
  
  }
#line 6735 "parser.tab.c"
    break;

  case 223:
#line 3512 "parser.y"
                                    {
  
  
  
  }
#line 6745 "parser.tab.c"
    break;

  case 224:
#line 3518 "parser.y"
                          {
  
  
  }
#line 6754 "parser.tab.c"
    break;

  case 225:
#line 3522 "parser.y"
                                                      {

  
  }
#line 6763 "parser.tab.c"
    break;

  case 226:
#line 3527 "parser.y"
                             {
  
  
  
  }
#line 6773 "parser.tab.c"
    break;

  case 227:
#line 3533 "parser.y"
             {
  
  
  }
#line 6782 "parser.tab.c"
    break;

  case 228:
#line 3537 "parser.y"
                          {
  
  
  
  }
#line 6792 "parser.tab.c"
    break;

  case 229:
#line 3543 "parser.y"
                              {
  
  
  
  
  }
#line 6803 "parser.tab.c"
    break;

  case 230:
#line 3549 "parser.y"
               {
  
  
  
  }
#line 6813 "parser.tab.c"
    break;

  case 231:
#line 3554 "parser.y"
                            {
  inloop=1;
  tables.push(curr_table);
  curr_table = new Sym_Table(curr_table);
  list_of_Symbol_Tables.push_back(curr_table);
  scope_names.push(curr_scope);
  string new_scope = "WhileStatement";
  curr_scope = new_scope;
  // offsets.push(offset);
  // int new_offset = 0;
  // offset = new_offset;
  string a = newLabel();
  emit(a, ":", "", "", -1);
  strcpy(((yyval.typ)).gotoname,a.c_str());
  continuelabels.push(a);
}
#line 6834 "parser.tab.c"
    break;

  case 232:
#line 3571 "parser.y"
                                                                 {
  string a = newLabel();
  emit("Goto", ((yyvsp[0].typ)).tempvar, a, "Ifz", -1);
  strcpy(((yyval.typ)).gotoname,a.c_str());
  strcpy(((yyval.typ)).nextgoto,((yyvsp[-2].typ)).gotoname);
  // emit(($1).gotoname, ":", "", "", -1);
  breaklabels.push(a);
}
#line 6847 "parser.tab.c"
    break;

  case 233:
#line 3581 "parser.y"
                                            {
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  // offset = offsets.top(); offsets.pop();
  inloop=0;
  emit("Goto", ((yyvsp[-2].typ)).nextgoto, "", "", -1);
  emit(((yyvsp[-2].typ)).gotoname, ":", "", "", -1);
  }
#line 6860 "parser.tab.c"
    break;

  case 234:
#line 3591 "parser.y"
                                                     {
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  // offset = offsets.top(); offsets.pop();
  inloop=0;
  emit("Goto", ((yyvsp[-2].typ)).nextgoto, "", "", -1);
  emit(((yyvsp[-2].typ)).gotoname, ":", "", "", -1);
  }
#line 6873 "parser.tab.c"
    break;

  case 235:
#line 3600 "parser.y"
                     {
  inloop=1;
  tables.push(curr_table);
  curr_table = new Sym_Table(curr_table);
  list_of_Symbol_Tables.push_back(curr_table);
  scope_names.push(curr_scope);
  string new_scope = "DoStatement";
  curr_scope = new_scope;
  // offsets.push(offset);
  // int new_offset = 0;
  // offset = new_offset;
  string a = newLabel();
  emit(a, ":", "", "", -1);
  strcpy(((yyval.typ)).gotoname,a.c_str());
  continuelabels.push(a);
}
#line 6894 "parser.tab.c"
    break;

  case 236:
#line 3617 "parser.y"
                                                                           {
  string a = newLabel();
  emit("Goto", ((yyvsp[0].typ)).tempvar, a, "Ifz", -1);
  emit("Goto", ((yyvsp[-4].typ)).gotoname, "", "", -1);
  emit(a, ":", "", "", -1);
  strcpy(((yyval.typ)).gotoname,a.c_str());
  breaklabels.push(a);
}
#line 6907 "parser.tab.c"
    break;

  case 237:
#line 3627 "parser.y"
                                         {    
  newdim.clear();
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  // offset = offsets.top(); offsets.pop();
  inloop=0;
  isclassaccess=0;
    issystem=0;
    isfinal=0;
  }
#line 6922 "parser.tab.c"
    break;

  case 238:
#line 3637 "parser.y"
                        {
  inloop=1;
  tables.push(curr_table);
  curr_table = new Sym_Table(curr_table);
  list_of_Symbol_Tables.push_back(curr_table);
  scope_names.push(curr_scope);
  string new_scope = "ForStatement";
  curr_scope = new_scope;
  // offsets.push(offset);
  // int new_offset = 0;
  // offset = new_offset;
}
#line 6939 "parser.tab.c"
    break;

  case 239:
#line 3650 "parser.y"
                                                         {
  string a = newLabel();
  emit(a, ":", "", "", -1);
  strcpy(((yyval.typ)).gotoname,a.c_str());
}
#line 6949 "parser.tab.c"
    break;

  case 240:
#line 3656 "parser.y"
                                                  {    
  newdim.clear();
 isclassaccess=0;
    issystem=0;
    isfinal=0;
}
#line 6960 "parser.tab.c"
    break;

  case 241:
#line 3663 "parser.y"
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
#line 6980 "parser.tab.c"
    break;

  case 242:
#line 3679 "parser.y"
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
#line 6998 "parser.tab.c"
    break;

  case 243:
#line 3693 "parser.y"
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
#line 7016 "parser.tab.c"
    break;

  case 244:
#line 3707 "parser.y"
                                                             {    
  newdim.clear();
  string a = newLabel();
  emit(a, ":", "", "", -1);
  strcpy(((yyval.typ)).gotoname,a.c_str());
  isclassaccess=0;
    issystem=0;
    isfinal=0;
}
#line 7030 "parser.tab.c"
    break;

  case 245:
#line 3717 "parser.y"
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
#line 7050 "parser.tab.c"
    break;

  case 246:
#line 3733 "parser.y"
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
#line 7069 "parser.tab.c"
    break;

  case 247:
#line 3748 "parser.y"
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
#line 7087 "parser.tab.c"
    break;

  case 248:
#line 3762 "parser.y"
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
#line 7108 "parser.tab.c"
    break;

  case 249:
#line 3779 "parser.y"
                                                 {
  emit("Goto", ((yyvsp[-1].typ)).gotoname, "", "", -1);
  emit(((yyvsp[-1].typ)).nextgoto1, ":", "", "", -1);
  strcpy(((yyval.typ)).gotoname,((yyvsp[-1].typ)).gotoname);
  strcpy(((yyval.typ)).nextgoto,((yyvsp[-1].typ)).nextgoto);
  strcpy(((yyval.typ)).nextgoto1,((yyvsp[-1].typ)).nextgoto1);
  strcpy(((yyval.typ)).nextgoto2,((yyvsp[-1].typ)).nextgoto2);
  breaklabels.push(string((char*)(((yyvsp[-1].typ)).nextgoto)));
}
#line 7122 "parser.tab.c"
    break;

  case 250:
#line 3789 "parser.y"
                                                     {
  emit("Goto", ((yyvsp[-1].typ)).gotoname, "", "", -1);
  emit(((yyvsp[-1].typ)).nextgoto1, ":", "", "", -1);
  strcpy(((yyval.typ)).gotoname,((yyvsp[-1].typ)).gotoname);
  strcpy(((yyval.typ)).nextgoto,((yyvsp[-1].typ)).nextgoto);
  strcpy(((yyval.typ)).nextgoto1,((yyvsp[-1].typ)).nextgoto1);
  strcpy(((yyval.typ)).nextgoto2,((yyvsp[-1].typ)).nextgoto2);
  breaklabels.push(string((char*)(((yyvsp[-1].typ)).nextgoto)));
}
#line 7136 "parser.tab.c"
    break;

  case 251:
#line 3799 "parser.y"
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
#line 7157 "parser.tab.c"
    break;

  case 252:
#line 3816 "parser.y"
                                                   {
  emit("Goto", ((yyvsp[-1].typ)).gotoname, "", "", -1);
  emit(((yyvsp[-1].typ)).nextgoto1, ":", "", "", -1);
  strcpy(((yyval.typ)).gotoname,((yyvsp[-1].typ)).gotoname);
  strcpy(((yyval.typ)).nextgoto,((yyvsp[-1].typ)).nextgoto);
  strcpy(((yyval.typ)).nextgoto1,((yyvsp[-1].typ)).nextgoto1);
  strcpy(((yyval.typ)).nextgoto2,((yyvsp[-1].typ)).nextgoto2);
  breaklabels.push(string((char*)(((yyvsp[-1].typ)).nextgoto)));
}
#line 7171 "parser.tab.c"
    break;

  case 253:
#line 3826 "parser.y"
                                                      {
  emit("Goto", ((yyvsp[-1].typ)).gotoname, "", "", -1);
  emit(((yyvsp[-1].typ)).nextgoto1, ":", "", "", -1);
  strcpy(((yyval.typ)).gotoname,((yyvsp[-1].typ)).gotoname);
  strcpy(((yyval.typ)).nextgoto,((yyvsp[-1].typ)).nextgoto);
  strcpy(((yyval.typ)).nextgoto1,((yyvsp[-1].typ)).nextgoto1);
  strcpy(((yyval.typ)).nextgoto2,((yyvsp[-1].typ)).nextgoto2);
  breaklabels.push(string((char*)(((yyvsp[-1].typ)).nextgoto)));
}
#line 7185 "parser.tab.c"
    break;

  case 254:
#line 3837 "parser.y"
                                          {
  // breaklabels.push(string((char*)(($1).nextgoto)));
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  // offset = offsets.top(); offsets.pop();
  inloop=0;
  emit("Goto", ((yyvsp[-2].typ)).nextgoto2, "", "", -1);
  emit(((yyvsp[-2].typ)).nextgoto, ":", "", "", -1);
  continuelabels.pop();
  breaklabels.pop();
  }
#line 7201 "parser.tab.c"
    break;

  case 255:
#line 3848 "parser.y"
                                           {
  // breaklabels.push(string((char*)(($1).nextgoto)));
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  // offset = offsets.top(); offsets.pop(); 
  inloop=0;
  emit("Goto", ((yyvsp[-2].typ)).nextgoto2, "", "", -1);
  emit(((yyvsp[-2].typ)).nextgoto, ":", "", "", -1);
  continuelabels.pop();
  breaklabels.pop();
  }
#line 7217 "parser.tab.c"
    break;

  case 256:
#line 3859 "parser.y"
                              {
  // breaklabels.push(string((char*)(($1).nextgoto)));
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  // offset = offsets.top(); offsets.pop();
  inloop=0;
  emit("Goto", ((yyvsp[-1].typ)).nextgoto2, "", "", -1);
  emit(((yyvsp[-1].typ)).nextgoto, ":", "", "", -1);
  continuelabels.pop();
  breaklabels.pop();
  }
#line 7233 "parser.tab.c"
    break;

  case 257:
#line 3870 "parser.y"
                                            {
  // breaklabels.push(string((char*)(($1).nextgoto)));
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  // offset = offsets.top(); offsets.pop();
  inloop=0;
  emit("Goto", ((yyvsp[-2].typ)).nextgoto2, "", "", -1);
  emit(((yyvsp[-2].typ)).nextgoto, ":", "", "", -1);
  continuelabels.pop();
  breaklabels.pop();
  }
#line 7249 "parser.tab.c"
    break;

  case 258:
#line 3881 "parser.y"
                               {
  // breaklabels.push(string((char*)(($1).nextgoto)));
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  // offset = offsets.top(); offsets.pop();
  inloop=0;
  emit("Goto", ((yyvsp[-1].typ)).nextgoto2, "", "", -1);
  emit(((yyvsp[-1].typ)).nextgoto, ":", "", "", -1);
  continuelabels.pop();
  breaklabels.pop();
  }
#line 7265 "parser.tab.c"
    break;

  case 259:
#line 3892 "parser.y"
                              {
  // breaklabels.push(string((char*)(($1).nextgoto)));
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  // offset = offsets.top(); offsets.pop();
  inloop=0;
  emit("Goto", ((yyvsp[-1].typ)).nextgoto2, "", "", -1);
  emit(((yyvsp[-1].typ)).nextgoto, ":", "", "", -1);
  continuelabels.pop();
  breaklabels.pop();
  }
#line 7281 "parser.tab.c"
    break;

  case 260:
#line 3903 "parser.y"
                               {
  // breaklabels.push(string((char*)(($1).nextgoto)));
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  // offset = offsets.top(); offsets.pop();
  inloop=0;
  emit("Goto", ((yyvsp[-1].typ)).nextgoto2, "", "", -1);
  emit(((yyvsp[-1].typ)).nextgoto, ":", "", "", -1);
  continuelabels.pop();
  breaklabels.pop();
  }
#line 7297 "parser.tab.c"
    break;

  case 261:
#line 3914 "parser.y"
                                           {
  // breaklabels.push(string((char*)(($1).nextgoto)));
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  // offset = offsets.top(); offsets.pop();
  inloop=0;
  emit("Goto", ((yyvsp[-2].typ)).nextgoto2, "", "", -1);
  emit(((yyvsp[-2].typ)).nextgoto, ":", "", "", -1);
  continuelabels.pop();
  breaklabels.pop();
  }
#line 7313 "parser.tab.c"
    break;

  case 262:
#line 3927 "parser.y"
                                                   {
  // breaklabels.push(string((char*)(($1).nextgoto)));
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  // offset = offsets.top(); offsets.pop();
  inloop=0;
  emit("Goto", ((yyvsp[-2].typ)).nextgoto2, "", "", -1);
  emit(((yyvsp[-2].typ)).nextgoto, ":", "", "", -1);
  continuelabels.pop();
  breaklabels.pop();
  }
#line 7329 "parser.tab.c"
    break;

  case 263:
#line 3938 "parser.y"
                                                    {
  // breaklabels.push(string((char*)(($1).nextgoto)));
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  // offset = offsets.top(); offsets.pop();
  inloop=0;
  emit("Goto", ((yyvsp[-2].typ)).nextgoto2, "", "", -1);
  emit(((yyvsp[-2].typ)).nextgoto, ":", "", "", -1);
  continuelabels.pop();
  breaklabels.pop();
  }
#line 7345 "parser.tab.c"
    break;

  case 264:
#line 3949 "parser.y"
                                       {
  // breaklabels.push(string((char*)(($1).nextgoto)));
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  // offset = offsets.top(); offsets.pop();
  inloop=0;
  emit("Goto", ((yyvsp[-1].typ)).nextgoto2, "", "", -1);
  emit(((yyvsp[-1].typ)).nextgoto, ":", "", "", -1);
  continuelabels.pop();
  breaklabels.pop();
  }
#line 7361 "parser.tab.c"
    break;

  case 265:
#line 3960 "parser.y"
                                                     {
  // breaklabels.push(string((char*)(($1).nextgoto)));
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  // offset = offsets.top(); offsets.pop();
  inloop=0;
  emit("Goto", ((yyvsp[-2].typ)).nextgoto2, "", "", -1);
  emit(((yyvsp[-2].typ)).nextgoto, ":", "", "", -1);
  continuelabels.pop();
  breaklabels.pop();
  }
#line 7377 "parser.tab.c"
    break;

  case 266:
#line 3971 "parser.y"
                                        {
  // breaklabels.push(string((char*)(($1).nextgoto)));
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  // offset = offsets.top(); offsets.pop();
  inloop=0;
  emit("Goto", ((yyvsp[-1].typ)).nextgoto2, "", "", -1);
  emit(((yyvsp[-1].typ)).nextgoto, ":", "", "", -1);
  continuelabels.pop();
  breaklabels.pop();
  }
#line 7393 "parser.tab.c"
    break;

  case 267:
#line 3982 "parser.y"
                                       {
  // breaklabels.push(string((char*)(($1).nextgoto)));
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  // offset = offsets.top(); offsets.pop();
  inloop=0;
  emit("Goto", ((yyvsp[-1].typ)).nextgoto2, "", "", -1);
  emit(((yyvsp[-1].typ)).nextgoto, ":", "", "", -1);
  continuelabels.pop();
  breaklabels.pop();
  }
#line 7409 "parser.tab.c"
    break;

  case 268:
#line 3993 "parser.y"
                                        {
  // breaklabels.push(string((char*)(($1).nextgoto)));
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  // offset = offsets.top(); offsets.pop();
  inloop=0;
  emit("Goto", ((yyvsp[-1].typ)).nextgoto2, "", "", -1);
  emit(((yyvsp[-1].typ)).nextgoto, ":", "", "", -1);
  continuelabels.pop();
  breaklabels.pop();
  }
#line 7425 "parser.tab.c"
    break;

  case 269:
#line 4004 "parser.y"
                                                    {
  // breaklabels.push(string((char*)(($1).nextgoto)));
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  // offset = offsets.top(); offsets.pop();
  inloop=0;
  emit("Goto", ((yyvsp[-2].typ)).nextgoto2, "", "", -1);
  emit(((yyvsp[-2].typ)).nextgoto, ":", "", "", -1);
  continuelabels.pop();
  breaklabels.pop();
  }
#line 7441 "parser.tab.c"
    break;

  case 270:
#line 4016 "parser.y"
                        {
}
#line 7448 "parser.tab.c"
    break;

  case 271:
#line 4018 "parser.y"
                          {
}
#line 7455 "parser.tab.c"
    break;

  case 272:
#line 4022 "parser.y"
                        {
}
#line 7462 "parser.tab.c"
    break;

  case 273:
#line 4026 "parser.y"
                    {
}
#line 7469 "parser.tab.c"
    break;

  case 274:
#line 4028 "parser.y"
                                                   {
}
#line 7476 "parser.tab.c"
    break;

  case 275:
#line 4032 "parser.y"
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
#line 7494 "parser.tab.c"
    break;

  case 276:
#line 4045 "parser.y"
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
#line 7515 "parser.tab.c"
    break;

  case 277:
#line 4063 "parser.y"
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
#line 7536 "parser.tab.c"
    break;

  case 278:
#line 4079 "parser.y"
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
#line 7553 "parser.tab.c"
    break;

  case 279:
#line 4094 "parser.y"
                 {   
  newdim.clear(); 
  if(!infunction)
  {
    cout<<"Invalid return on line "<<yylineno<<'\n';
  }
  isclassaccess=0;
    issystem=0;
    if(ispopped == 1){
    if(totalstack != 0){ emit("add", "rsp", to_string(totalstack), "", -1); ;}
emit("pop","rbp","","",-1);
    ispopped = 0;totalstack = 0;
    emit("ret", "", "", "", -1);
  }
    ispopped = 0;
  
}
#line 7575 "parser.tab.c"
    break;

  case 280:
#line 4111 "parser.y"
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
    if(totalstack != 0){ emit("add", "rsp", to_string(totalstack), "", -1); ;}
    emit("pop","rbp","","",-1);
    ispopped = 0;totalstack = 0;
    //cout<<"FUCK\n"; 
    
  }
  emit("addretval", ((yyvsp[-1].typ)).tempvar, "", "", -1);
  emit("ret", "" , "", "", -1);
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
#line 7618 "parser.tab.c"
    break;

  case 281:
#line 4152 "parser.y"
                           {    
  newdim.clear();
  isclassaccess=0;
    issystem=0;
     isfinal=0;
}
#line 7629 "parser.tab.c"
    break;

  case 282:
#line 4159 "parser.y"
                                                       {
}
#line 7636 "parser.tab.c"
    break;

  case 283:
#line 4162 "parser.y"
                  {
}
#line 7643 "parser.tab.c"
    break;

  case 284:
#line 4164 "parser.y"
                           {
}
#line 7650 "parser.tab.c"
    break;

  case 285:
#line 4166 "parser.y"
                   {
}
#line 7657 "parser.tab.c"
    break;

  case 286:
#line 4169 "parser.y"
            {
}
#line 7664 "parser.tab.c"
    break;

  case 287:
#line 4171 "parser.y"
                     {
}
#line 7671 "parser.tab.c"
    break;

  case 288:
#line 4174 "parser.y"
      {
  tables.push(curr_table);
  curr_table = new Sym_Table(curr_table);
  list_of_Symbol_Tables.push_back(curr_table);
  scope_names.push(curr_scope);
  string new_scope = "CatchStatement";
  curr_scope = new_scope;
  // offsets.push(offset);
  // int new_offset = 0;
  // offset = new_offset;
}
#line 7687 "parser.tab.c"
    break;

  case 289:
#line 4185 "parser.y"
                                               {
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  // offset = offsets.top(); offsets.pop();
}
#line 7697 "parser.tab.c"
    break;

  case 290:
#line 4191 "parser.y"
              {
}
#line 7704 "parser.tab.c"
    break;

  case 291:
#line 4194 "parser.y"
                  {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
  ((yyval.typ)).ndim=((yyvsp[0].typ)).ndim;
}
#line 7714 "parser.tab.c"
    break;

  case 292:
#line 4199 "parser.y"
                         {
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);
}
#line 7723 "parser.tab.c"
    break;

  case 293:
#line 4205 "parser.y"
        {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);

  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
}
#line 7733 "parser.tab.c"
    break;

  case 294:
#line 4210 "parser.y"
      {
  string s = newtemp();
  // emit("=", "[rbp+8]", "null", s, -1);
  strcpy(((yyval.typ)).tempvar, s.c_str());
  strcpy(((yyval.typ)).type,((yyvsp[0].lex)).str);
}
#line 7744 "parser.tab.c"
    break;

  case 295:
#line 4216 "parser.y"
                                     {

  strcpy(((yyval.typ)).tempvar, ((yyvsp[-1].typ)).tempvar);
  
  strcpy(((yyval.typ)).type,((yyvsp[-1].typ)).type);
  
}
#line 7756 "parser.tab.c"
    break;

  case 296:
#line 4223 "parser.y"
                                 {
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
  
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);
}
#line 7766 "parser.tab.c"
    break;

  case 297:
#line 4228 "parser.y"
             {

  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);
  
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
  
}
#line 7778 "parser.tab.c"
    break;

  case 298:
#line 4235 "parser.y"
                  {

  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);
  
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
  
}
#line 7790 "parser.tab.c"
    break;

  case 299:
#line 4242 "parser.y"
             {
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
  
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);
}
#line 7800 "parser.tab.c"
    break;

  case 300:
#line 4249 "parser.y"
                                                    {
  objlist.push_back(curridf);
  isobj = 1;
  string tv1 = newtemp();
  emit("=", to_string(getclasswidth(string((char*)((yyvsp[-3].typ)).type))), "null", tv1, -1);
  emit("param",tv1,"","",-1);
  // // emit("sub","rsp","8","",-1);
  // // emit("sub","rsp","8","",-1);
  emit("call","allocmem","1","",-1);
  // emit("add","rsp","8","",-1);
  // emit("add","rsp","8","",-1);
  string tv2 = newtemp();
  emit("=", "popparam", "null", tv2, -1);
  currtemp = tv2;
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
  // emit("sub", "rsp", to_string(8 + pops),"", -1);

  string o2 = newtemp();
  emit("=", "shiftreg", "null", o2, -1);
  emit("call",string((char*)(((yyvsp[-3].typ)).type)), "","",-1);
  emit("=", o2, "null", "shiftreg", -1);
  emit("add", "rsp", to_string(8 + pops),"", -1);
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
#line 7903 "parser.tab.c"
    break;

  case 301:
#line 4347 "parser.y"
                                        {
  objlist.push_back(curridf);
  isobj = 1;
  // string a = newtemp();
  // strcpy(($$).tempvar, a.c_str());
  string tv1 = newtemp();
  emit("=", to_string(getclasswidth(string((char*)((yyvsp[-2].typ)).type))), "null", tv1, -1);
  emit("param",tv1,"","",-1);
  // // emit("sub","rsp","8","",-1);
  emit("call","allocmem","1","",-1);
  emit("add","rsp","8","",-1);
  string tv2 = newtemp();
  emit("=", "popparam", "null", tv2, -1);
  emit("param",tv2,"","",-1);
  string o2 = newtemp();
  emit("=", "shiftreg", "null", o2, -1);
  emit("call",string((char*)(((yyvsp[-2].typ)).type)), "","",-1);
  emit("=", o2, "null", "shiftreg", -1);
  strcpy(((yyval.typ)).tempvar, tv2.c_str());
  currtemp = tv2;

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
#line 7948 "parser.tab.c"
    break;

  case 302:
#line 4389 "parser.y"
           {
  args.push({string((char*)((yyvsp[0].typ)).tempvar), sz});
  strcpy(((yyval.typ)).argstring, ((yyvsp[0].typ)).type);
  // cout<<"XXX"<<($$).argstring<<'\n';
  ((yyval.typ)).nelem=1;
}
#line 7959 "parser.tab.c"
    break;

  case 303:
#line 4395 "parser.y"
                               {
  args.push({string((char*)((yyvsp[0].typ)).tempvar), sz});
  strcat(((yyval.typ)).argstring, "$");
  strcat(((yyval.typ)).argstring, ((yyvsp[0].typ)).type);
  // cout<<"XXX"<<($$).argstring<<'\n';
  ((yyval.typ)).nelem=((yyvsp[-2].typ)).nelem+1;
}
#line 7971 "parser.tab.c"
    break;

  case 304:
#line 4404 "parser.y"
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
#line 7991 "parser.tab.c"
    break;

  case 305:
#line 4419 "parser.y"
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
#line 8013 "parser.tab.c"
    break;

  case 306:
#line 4436 "parser.y"
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
#line 8035 "parser.tab.c"
    break;

  case 307:
#line 4453 "parser.y"
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
#line 8057 "parser.tab.c"
    break;

  case 308:
#line 4471 "parser.y"
        {
  ((yyval.typ)).ndim=1;
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);
}
#line 8066 "parser.tab.c"
    break;

  case 309:
#line 4475 "parser.y"
                  {
  ((yyval.typ)).ndim = ((yyvsp[-1].typ)).ndim + 1;
  strcpy(((yyval.typ)).tempvar, strcat(((yyvsp[-1].typ)).tempvar, ((yyvsp[0].typ)).tempvar));
}
#line 8075 "parser.tab.c"
    break;

  case 310:
#line 4480 "parser.y"
                                                {
  strcpy(((yyval.typ)).tempvar, strcat(((yyvsp[-2].lex)).str, strcat(((yyvsp[-1].typ)).tempvar, ((yyvsp[0].lex)).str)));
  ((yyval.typ)).ndim=1;
  newdim.push_back(dimint);
  
}
#line 8086 "parser.tab.c"
    break;

  case 311:
#line 4488 "parser.y"
                                     {
  strcpy(((yyval.typ)).tempvar, strcat(((yyvsp[-1].lex)).str, ((yyvsp[0].lex)).str));
  strcpy(((yyval.typ)).tempvar, strcat(((yyvsp[-1].lex)).str, ((yyvsp[0].lex)).str));
  ((yyval.typ)).ndim=1;
  newdim.push_back(0);
  
}
#line 8098 "parser.tab.c"
    break;

  case 312:
#line 4495 "parser.y"
                                           {
  strcpy(((yyval.typ)).tempvar, strcat(((yyvsp[-2].typ)).tempvar, strcat(((yyvsp[-1].lex)).str, ((yyvsp[0].lex)).str)));
  ((yyval.typ)).ndim = ((yyvsp[-2].typ)).ndim + 1;
  newdim.push_back(0);
}
#line 8108 "parser.tab.c"
    break;

  case 313:
#line 4502 "parser.y"
                       {
  // strcpy(($$).tempvar, strcat(($1).tempvar, strcat(($2).str, ($3).str)));
  if(curr_table->lookup(string((char*)((yyvsp[0].lex)).str)).offset == -1 && checkobj(string((char*)((yyvsp[0].lex)).str)) == 0){
    cout<<"Undeclared variable on line "<< yylineno<<"\n";
  }
  if(strcmp(((yyvsp[-2].typ)).type,"this")==0)
  {
    strcpy(((yyval.typ)).tempvar, (string((char*)(((yyvsp[0].lex)).str)) + "!").c_str());
    strcpy(((yyval.typ)).type,curr_table->thislookup(((yyvsp[0].lex)).str).c_str());
  }
}
#line 8124 "parser.tab.c"
    break;

  case 314:
#line 4513 "parser.y"
                      {
  strcpy(((yyval.typ)).tempvar, strcat(((yyvsp[-2].lex)).str, strcat(((yyvsp[-1].lex)).str, ((yyvsp[0].lex)).str)));
  if(curr_table->lookup(string((char*)((yyvsp[0].lex)).str)).offset == -1 && checkobj(string((char*)((yyvsp[0].lex)).str)) == 0){
    cout<<"Undeclared variable on line "<< yylineno<<"\n";
  }
}
#line 8135 "parser.tab.c"
    break;

  case 315:
#line 4520 "parser.y"
                            {
  //emit(string((char*)($1).type),"","","",-1);
  //emit("BeginFunc","","","",-1);
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
  strcpy(((yyval.typ)).tempvar,((yyvsp[0].typ)).tempvar);
}
#line 8146 "parser.tab.c"
    break;

  case 316:
#line 4528 "parser.y"
                                                            {
  int pops = 0;
  string ar = "";
  stack<string> args2;
  
  int funcargtypesz1 = funcargtypesz(1, string((char*)(((yyvsp[-3].typ)).type)));
  // emit("stackpointer", "+" + to_string(funcargtypesz1), "", "", -1);

  if(!strcmp(string((char*)(((yyvsp[-3].typ)).tempvar)).c_str(),"System.println"))
  {
    if(args.top().first == args.top().first.substr(0, args.top().first.find('.')))
    {
      emit("call", "print 1", args.top().first, "", -1);
    }
    else{
      int offobj = curr_table->lookup(args.top().first.substr(0, args.top().first.find('.'))).offset;
      string tv = newtemp();
      emit("=", objtotemp[args.top().first.substr(0, args.top().first.find('.'))], "null", tv, -1);
      emit("call", "print 1", "." + tv , args.top().first, -1);
    }
    // emit("call", "print 1", args.top().first, "", -1);
    args.pop();
  }
  else{
    while(!args.empty())
  {
    auto arg = args.top();
    args2.push(arg.first);
    emit("param",arg.first,"","",-1);
    pops += arg.second;
    args.pop();
  }

    string tv9 = string((char*)(((yyvsp[-3].typ)).tempvar));
    string oname = tv9.substr(0, tv9.find('.'));
    string cname = curr_table->lookup(oname).type;
    if(checkclass(cname)){
      string mname = tv9.substr(tv9.find('.')+1, tv9.size());
      funcargtypesz1 = funcargtypesz(1, mname) + 8;
      emit("param", oname, "", "", -1);
      // emit("sub","rsp",to_string(funcargtypesz1),"",-1);
      string o2 = newtemp();
      emit("=", "shiftreg", "null", o2, -1);
      emit("call", cname + "." + mname, "", "", -1);
      emit("=", o2, "null", "shiftreg", -1);

    }
    else{
      // emit("sub","rsp",to_string(funcargtypesz1),"",-1);
      string o2 = newtemp();
      emit("param", "obj", "", "", -1);
      emit("=", "shiftreg", "null", o2, -1);
      emit("call", string((char*)(((yyvsp[-3].typ)).tempvar)),"", "", -1);
      emit("=", o2, "null", "shiftreg", -1);
    }
  
  // emit("stackpointer", "-" + to_string(funcargtypesz1), "", "", -1);
  emit("add","rsp",to_string(funcargtypesz1),"",-1);
  string tv3 = newtemp();
  emit("=", "popparam", "null", tv3.c_str(), -1);
  emit("add", "rsp", to_string(8), "", -1);
  strcpy(((yyval.typ)).tempvar, tv3.c_str());
  }
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
#line 8322 "parser.tab.c"
    break;

  case 317:
#line 4699 "parser.y"
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
      string o2 = newtemp();
      emit("=", "shiftreg", "null", o2, -1);
      emit("call", cname + "." + mname, "", "", -1);
      emit("=", o2, "null", "shiftreg", -1);

    }
    else{
      string o2 = newtemp();
      emit("param", "obj", "", "", -1);
      emit("=", "shiftreg", "null", o2, -1);
      emit("call", string((char*)(((yyvsp[-2].typ)).tempvar)),"", "", -1);
      emit("=", o2, "null", "shiftreg", -1);
    }
  }
  string s = newtemp();
  emit("=", "popparam", "null", s.c_str(), -1);
  emit("add", "rsp", to_string(8), "", -1);
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
#line 8390 "parser.tab.c"
    break;

  case 318:
#line 4762 "parser.y"
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
      // emit("sub","rsp",to_string(funcargtypesz1),"",-1);
      string o2 = newtemp();
      emit("=", "shiftreg", "null", o2, -1);
      emit("call", cname + "." + mname, "", "", -1);
      emit("=", o2, "null", "shiftreg", -1);

    }
    else{
      // emit("sub","rsp",to_string(funcargtypesz1),"",-1);
      string o2 = newtemp();
      emit("param", "obj", "", "", -1);
  emit("=", "shiftreg", "null", o2, -1);
      emit("call", string((char*)(((yyvsp[-5].typ)).tempvar)),"", "", -1);
      emit("=", o2, "null", "shiftreg", -1);
    }
  }
  // emit("stackpointer", "-" + to_string(funcargtypesz1), "", "", -1);
  emit("add","rsp",to_string(funcargtypesz1),"",-1);
  string tv3 = newtemp();
  emit("=", "popparam", "null", tv3.c_str(), -1);
  emit("add", "rsp", to_string(8), "", -1);
  strcpy(((yyval.typ)).tempvar, tv3.c_str());

  if(curr_table->lookup(string((char*)((yyvsp[-3].lex)).str)).offset == -1 && checkobj(string((char*)((yyvsp[-3].lex)).str)) == 0){
    if(!isaccess)
    {
      cout<<"Undeclared variable on line "<< yylineno<<"\n";
    }
  }
  isaccess=0;
}
#line 8454 "parser.tab.c"
    break;

  case 319:
#line 4821 "parser.y"
                                                 {
  string s = newtemp();
  string o2 = newtemp();
  emit("param", "obj", "", "", -1);
  emit("=", "shiftreg", "null", o2, -1);
  emit("call",string((char*)((yyvsp[-4].typ)).tempvar) + string((char*)((yyvsp[-3].lex)).str) + string((char*)((yyvsp[-2].lex)).str)   ,"","",-1);
  emit("=", o2, "null", "shiftreg", -1);
  emit("=", "popparam", "null", s.c_str(), -1);
  emit("add", "rsp", to_string(8), "", -1);
  strcpy(((yyval.typ)).tempvar, s.c_str());

  if(curr_table->lookup(string((char*)((yyvsp[-2].lex)).str)).offset == -1 && checkobj(string((char*)((yyvsp[-2].lex)).str)) == 0){
  if(!isaccess)
    {
      cout<<"Undeclared variable on line "<< yylineno<<"\n";
    }
  }
  isaccess=0;
}
#line 8478 "parser.tab.c"
    break;

  case 320:
#line 4840 "parser.y"
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
#line 8510 "parser.tab.c"
    break;

  case 321:
#line 4867 "parser.y"
                                               {
  string s = newtemp();
  string o2 = newtemp();
  emit("=", "shiftreg", "null", o2, -1);
  emit("call",string((char*)((yyvsp[-4].lex)).str) + string((char*)((yyvsp[-3].lex)).str) + string((char*)((yyvsp[-2].lex)).str),"","",-1);
  emit("=", o2, "", "shiftreg", -1);
  emit("=", "popparam", "null", s.c_str(), -1);
  emit("add", "rsp", to_string(8), "", -1);
  strcpy(((yyval.typ)).tempvar,s.c_str());

  if(curr_table->lookup(string((char*)((yyvsp[-2].lex)).str)).offset == -1 && checkobj(string((char*)((yyvsp[-2].lex)).str)) == 0){
  if(!isaccess)
    {
      cout<<"Undeclared variable on line "<< yylineno<<"\n";
    }
  }
  isaccess=0;
}
#line 8533 "parser.tab.c"
    break;

  case 322:
#line 4887 "parser.y"
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
  // string tp8 = curr_table->lookup(string((char*)(($1).type))).type;
  string tp8 = newtemp();
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
  size=8;
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
    // string hello(($3).tempvar); 
    // stringstream str(hello); 
    // int y;  
    // str >> y;  
    // x=x*y;
    emit("*", to_string(x), string((char*)(((yyvsp[-1].typ)).tempvar)), tp8, -1);
    // cout<<"YUI"<<y<<" "<<x<<'\n';
    // tp8 = to_string(x);
    arrayaccesscount -- ;
  }
  else{
    // string tv13 = newtemp();
    emit("*",string((char*)((yyvsp[-1].typ)).tempvar), "8" , tp8 , -1);
    // tp8 = string((char*)($3).tempvar)+ "*" + to_string(getsz(arraytypeval));
    // tp8 = tv13;
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
  string tv14 = newtemp();
  emit("+",string((char*)((yyvsp[-3].typ)).tempvar), tp7 , tv14 , -1);
  string tp6 = tv14;
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
#line 8689 "parser.tab.c"
    break;

  case 323:
#line 5038 "parser.y"
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
  // string tp8 = string((char*)(($1).type));
  string tp8 = newtemp();
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
  size=8;
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
    // string hello(($3).tempvar); 
    // stringstream str(hello); 
    // int y;  
    // str >> y;  
    // string newt = newtemp();
    emit("*", to_string(x), string((char*)(((yyvsp[-1].typ)).tempvar)), tp8, -1);
    // x=x*y;
    // cout<<"YUI"<<y<<" "<<x<<'\n';
    // tp8 = to_string(x);
    arrayaccesscount -- ;
  }
  else{
    // string hello(($3).tempvar); 
    // stringstream str(hello); 
    // int y;  
    // str >> y;  
    // tp8 = to_string(size*y);
    emit("*", to_string(8), string((char*)(((yyvsp[-1].typ)).tempvar)), tp8, -1);
    arrayaccesscount --;
    // tp8 = string((char*)($3).tempvar)+ "*" + to_string(10);
  }
  // cout<<"HEYAAAAAAAAAAAA "<<tp8<<endl;

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
  string tv14 = newtemp();
  emit("+",string((char*)((yyvsp[-3].typ)).tempvar), tp7 , tv14 , -1);
  string tp6 = tv14;
  if(objtotemp[tp6] != ""){
    tp6 = objtotemp[tp6];
  }
  emit("=",tp6,"null",string((char*)((yyval.typ)).tempvar),-1);

  if(arrayaccesscount == 0){
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
#line 8840 "parser.tab.c"
    break;

  case 324:
#line 5186 "parser.y"
        {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);

  ((yyval.typ)).ndim=((yyvsp[0].typ)).ndim;
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
}
#line 8851 "parser.tab.c"
    break;

  case 325:
#line 5192 "parser.y"
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
#line 8867 "parser.tab.c"
    break;

  case 326:
#line 5203 "parser.y"
                         {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);
  
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
}
#line 8877 "parser.tab.c"
    break;

  case 327:
#line 5208 "parser.y"
                         {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);

  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
  
}
#line 8888 "parser.tab.c"
    break;

  case 328:
#line 5215 "parser.y"
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
#line 8925 "parser.tab.c"
    break;

  case 329:
#line 5248 "parser.y"
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
#line 8962 "parser.tab.c"
    break;

  case 330:
#line 5281 "parser.y"
                       {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);

  ((yyval.typ)).ndim=((yyvsp[0].typ)).ndim;
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
}
#line 8973 "parser.tab.c"
    break;

  case 331:
#line 5287 "parser.y"
                        {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);
  
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
}
#line 8983 "parser.tab.c"
    break;

  case 332:
#line 5292 "parser.y"
                      {
  strcpy(((yyval.typ)).tempvar, newtemp().c_str());
  emit("plus",((yyvsp[0].typ)).tempvar,"null",((yyval.typ)).tempvar, -1); 
  
 cout<<string((char*)((yyvsp[0].typ)).type)<<endl;
 if(invalidoperator(string((char*)((yyvsp[0].typ)).type),0) || !strcmp(string((char*)((yyvsp[0].typ)).type).c_str() ,"boolean" )){
    cout<<"Invalid Operator on line "<< yylineno<<"\n";
  }
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
  
  
}
#line 9000 "parser.tab.c"
    break;

  case 333:
#line 5304 "parser.y"
                       {
strcpy(((yyval.typ)).tempvar, newtemp().c_str());  
  emit("minus",((yyvsp[0].typ)).tempvar,"null",((yyval.typ)).tempvar, -1); 
 if(invalidoperator(string((char*)((yyvsp[0].typ)).type),0) || !strcmp(string((char*)((yyvsp[0].typ)).type).c_str() ,"boolean" )){
    cout<<"Invalid Operator on line "<< yylineno<<"\n";
  }
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
  
}
#line 9014 "parser.tab.c"
    break;

  case 334:
#line 5313 "parser.y"
                             {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);

  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
  ((yyval.typ)).ndim=((yyvsp[0].typ)).ndim;
}
#line 9025 "parser.tab.c"
    break;

  case 335:
#line 5321 "parser.y"
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
#line 9062 "parser.tab.c"
    break;

  case 336:
#line 5354 "parser.y"
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
#line 9096 "parser.tab.c"
    break;

  case 337:
#line 5384 "parser.y"
                  {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
}
#line 9105 "parser.tab.c"
    break;

  case 338:
#line 5388 "parser.y"
                       {
  
  if(invalidoperator(curr_table->lookup(string((char*)((yyvsp[0].typ)).type)).type,1) || !strcmp(curr_table->lookup(string((char*)((yyvsp[0].typ)).type)).type.c_str() ,"boolean" )){
    cout<<"Invalid TILDA Operator on line "<< yylineno<<"\n";
  }
  string a=newtemp();
  emit("~",((yyvsp[0].typ)).tempvar,"null",a.c_str(), -1);
  strcpy(((yyval.typ)).tempvar, a.c_str());
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
  
  
}
#line 9122 "parser.tab.c"
    break;

  case 339:
#line 5400 "parser.y"
                     {
 
   if(strcmp(curr_table->lookup(string((char*)((yyvsp[0].typ)).type)).type.c_str() ,"boolean" )){
    cout<<"Invalid NOT Operator on line "<< yylineno<<"\n";
  }
  string a=newtemp();
  emit("!",((yyvsp[0].typ)).tempvar,"null",((yyval.typ)).tempvar, -1);
   strcpy(((yyval.typ)).tempvar, a.c_str());
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
  
  
}
#line 9139 "parser.tab.c"
    break;

  case 340:
#line 5412 "parser.y"
                {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
  
}
#line 9149 "parser.tab.c"
    break;

  case 341:
#line 5418 "parser.y"
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
#line 9180 "parser.tab.c"
    break;

  case 342:
#line 5444 "parser.y"
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
#line 9208 "parser.tab.c"
    break;

  case 343:
#line 5467 "parser.y"
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
#line 9236 "parser.tab.c"
    break;

  case 344:
#line 5490 "parser.y"
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
#line 9272 "parser.tab.c"
    break;

  case 345:
#line 5522 "parser.y"
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
#line 9289 "parser.tab.c"
    break;

  case 346:
#line 5534 "parser.y"
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
#line 9439 "parser.tab.c"
    break;

  case 347:
#line 5679 "parser.y"
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
#line 9587 "parser.tab.c"
    break;

  case 348:
#line 5822 "parser.y"
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
#line 9734 "parser.tab.c"
    break;

  case 349:
#line 5965 "parser.y"
                         {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);

  ((yyval.typ)).ndim=((yyvsp[0].typ)).ndim;
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
}
#line 9745 "parser.tab.c"
    break;

  case 350:
#line 5971 "parser.y"
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
#line 9894 "parser.tab.c"
    break;

  case 351:
#line 6115 "parser.y"
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
#line 10041 "parser.tab.c"
    break;

  case 352:
#line 6259 "parser.y"
                   {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);

  ((yyval.typ)).ndim=((yyvsp[0].typ)).ndim;
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
  
}
#line 10053 "parser.tab.c"
    break;

  case 353:
#line 6266 "parser.y"
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
#line 10077 "parser.tab.c"
    break;

  case 354:
#line 6285 "parser.y"
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
#line 10103 "parser.tab.c"
    break;

  case 355:
#line 6306 "parser.y"
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
#line 10125 "parser.tab.c"
    break;

  case 356:
#line 6324 "parser.y"
                {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);

  ((yyval.typ)).ndim=((yyvsp[0].typ)).ndim;
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
}
#line 10136 "parser.tab.c"
    break;

  case 357:
#line 6330 "parser.y"
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
#line 10170 "parser.tab.c"
    break;

  case 358:
#line 6359 "parser.y"
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
#line 10205 "parser.tab.c"
    break;

  case 359:
#line 6389 "parser.y"
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
#line 10239 "parser.tab.c"
    break;

  case 360:
#line 6418 "parser.y"
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
#line 10275 "parser.tab.c"
    break;

  case 361:
#line 6449 "parser.y"
                                               {
  
  
}
#line 10284 "parser.tab.c"
    break;

  case 362:
#line 6454 "parser.y"
                     {
  
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);

  ((yyval.typ)).ndim=((yyvsp[0].typ)).ndim;
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
}
#line 10296 "parser.tab.c"
    break;

  case 363:
#line 6461 "parser.y"
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
#line 10332 "parser.tab.c"
    break;

  case 364:
#line 6492 "parser.y"
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
#line 10368 "parser.tab.c"
    break;

  case 365:
#line 6524 "parser.y"
                   {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);

  ((yyval.typ)).ndim=((yyvsp[0].typ)).ndim;
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
  
}
#line 10380 "parser.tab.c"
    break;

  case 366:
#line 6531 "parser.y"
                                      {
  strcpy(((yyval.typ)).tempvar, newtemp().c_str());
  emit("&",((yyvsp[-2].typ)).tempvar,((yyvsp[0].typ)).tempvar,((yyval.typ)).tempvar, -1);
  
 strcpy(((yyval.typ)).type,getorder(((yyvsp[-2].typ)).type,((yyvsp[0].typ)).type,0).c_str());
  
}
#line 10392 "parser.tab.c"
    break;

  case 367:
#line 6539 "parser.y"
              {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);

  ((yyval.typ)).ndim=((yyvsp[0].typ)).ndim;
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
  
}
#line 10404 "parser.tab.c"
    break;

  case 368:
#line 6546 "parser.y"
                                         {
  strcpy(((yyval.typ)).tempvar, newtemp().c_str());
  emit("^",((yyvsp[-2].typ)).tempvar,((yyvsp[0].typ)).tempvar,((yyval.typ)).tempvar, -1);
 strcpy(((yyval.typ)).type,getorder(((yyvsp[-2].typ)).type,((yyvsp[0].typ)).type,0).c_str());
  
  
}
#line 10416 "parser.tab.c"
    break;

  case 369:
#line 6554 "parser.y"
                      {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);

  ((yyval.typ)).ndim=((yyvsp[0].typ)).ndim;
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
}
#line 10427 "parser.tab.c"
    break;

  case 370:
#line 6560 "parser.y"
                                                {
  strcpy(((yyval.typ)).tempvar, newtemp().c_str());
  emit("|",((yyvsp[-2].typ)).tempvar,((yyvsp[0].typ)).tempvar,((yyval.typ)).tempvar, -1);
  
 strcpy(((yyval.typ)).type,getorder(((yyvsp[-2].typ)).type,((yyvsp[0].typ)).type,0).c_str());

}
#line 10439 "parser.tab.c"
    break;

  case 371:
#line 6568 "parser.y"
                      {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);

  ((yyval.typ)).ndim=((yyvsp[0].typ)).ndim;
   strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
}
#line 10450 "parser.tab.c"
    break;

  case 372:
#line 6574 "parser.y"
                                                       {
  strcpy(((yyval.typ)).tempvar, newtemp().c_str());
  emit("&&",((yyvsp[-2].typ)).tempvar,((yyvsp[0].typ)).tempvar,((yyval.typ)).tempvar, -1);
  
  strcpy(((yyval.typ)).type,"boolean");
  
  
}
#line 10463 "parser.tab.c"
    break;

  case 373:
#line 6583 "parser.y"
                         {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);

  ((yyval.typ)).ndim=((yyvsp[0].typ)).ndim;
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
}
#line 10474 "parser.tab.c"
    break;

  case 374:
#line 6589 "parser.y"
                                                       {
  strcpy(((yyval.typ)).tempvar, newtemp().c_str());
  emit("||",((yyvsp[-2].typ)).tempvar,((yyvsp[0].typ)).tempvar,((yyval.typ)).tempvar, -1);
  strcpy(((yyval.typ)).type,"boolean");
}
#line 10484 "parser.tab.c"
    break;

  case 375:
#line 6595 "parser.y"
                        {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);

  ((yyval.typ)).ndim=((yyvsp[0].typ)).ndim;
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
}
#line 10495 "parser.tab.c"
    break;

  case 376:
#line 6601 "parser.y"
                                                                         {
 strcpy(((yyval.typ)).type,getorder(((yyvsp[-2].typ)).type,((yyvsp[0].typ)).type,1).c_str());
}
#line 10503 "parser.tab.c"
    break;

  case 377:
#line 6605 "parser.y"
                      {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);

  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
  ((yyval.typ)).ndim=((yyvsp[0].typ)).ndim;
}
#line 10514 "parser.tab.c"
    break;

  case 378:
#line 6611 "parser.y"
            {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);
  strcpy(((yyval.typ)).type, ((yyvsp[0].typ)).type);
  ((yyval.typ)).sz = ((yyvsp[0].typ)).sz;
}
#line 10524 "parser.tab.c"
    break;

  case 379:
#line 6618 "parser.y"
                                                     {
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
      string tv5 = newtemp();
      emit("+", objtotemp[o], to_string(tp2), tv5, -1);
      string tp3 = "*(" + tv5 + ")";
      if(p1 != o1){
        string v1 = p1.substr(p1.find('.')+1, p1.size());
        string classname1 = curr_table->lookup(o1).type;
        int tp21 = offsetobj(classname1, v1);
        string tv7 = newtemp();
        emit("+", objtotemp[o1], to_string(tp21), tv7, -1);
        string tp31 = "*(" + tv7 + ")";
        emit("=",tp31.c_str(),"null",tp3.c_str(), -2);
      }
      else{
        string tv10 = newtemp();
        emit("=",tv10.c_str(),"null","popparam" , -1);
        int offset1 = curr_table->lookup(string((char*)((yyvsp[0].typ)).tempvar)).offset;
        int offset2 = curr_table->lookup(tp3).offset;
        if(offset1 != -1 && offset2 != -1){
          string tv5 = newtemp(), tv6 = newtemp();
          emit("+", tv10, to_string(offset1), tv5, -1);
          emit("+", tv10, to_string(offset2), tv6, -1);
          emit("=",("*(" + tv5 + ")").c_str(),"null",("*(" + tv10 + tv6 + ")").c_str(), -2);
        }
        else{
          storeobj[currtemp] = string((char*)(((yyvsp[-2].typ)).tempvar));
        emit("=",((yyvsp[0].typ)).tempvar,"null",tp3.c_str(), -2);
        }
      }
      strcpy(((yyval.typ)).tempvar, tp3.c_str());
    }
    else{
        string tv11 = string((char*)((yyvsp[0].typ)).tempvar), tv12 = string((char*)((yyvsp[-2].typ)).tempvar);
        if(vartottemp[tv11] != "")
          tv11 = vartottemp[tv11];
        if(vartottemp[tv12] != "")
          tv12 = vartottemp[tv12];
        // cout<<tv11<<" "<<tv12<<" HEYA"<<endl;
        emit("=",tv11.c_str(),"null",tv12.c_str(), -2);
    }
    
    //emit(($2).tempvar,($$).tempvar,"null",($1).tempvar, -1); This is an optimization
  }
  else
  {
    strcpy(((yyval.typ)).tempvar, newtemp().c_str());
    string a=((yyvsp[-1].typ)).tempvar;
    a=a.substr(0,a.size()-1);
    emit(a,((yyvsp[-2].typ)).tempvar,((yyvsp[0].typ)).tempvar,((yyval.typ)).tempvar, -1);
    emit("=",((yyval.typ)).tempvar,"null",((yyvsp[-2].typ)).tempvar, -2);
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
#line 10675 "parser.tab.c"
    break;

  case 380:
#line 6765 "parser.y"
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
#line 10693 "parser.tab.c"
    break;

  case 381:
#line 6778 "parser.y"
             {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);
  strcpy(((yyval.typ)).type, ((yyvsp[0].typ)).type);
  // cout<<"shrey"<<($1).type<<'\n';
  ((yyval.typ)).sz = ((yyvsp[0].typ)).sz;
  
}
#line 10705 "parser.tab.c"
    break;

  case 382:
#line 6785 "parser.y"
             {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);
  // cout<<"shubhan\n";
  // cout<<"SHUBHAN"<<($1).type<<'\n';
  strcpy(((yyval.typ)).type, ((yyvsp[0].typ)).type);
  // cout<<"GGG"<< ($1).type<<'\n';
  ((yyval.typ)).sz = ((yyvsp[0].typ)).sz;
  arrtype="null";
}
#line 10719 "parser.tab.c"
    break;

  case 383:
#line 6796 "parser.y"
      {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].lex)).str);
  
  
}
#line 10729 "parser.tab.c"
    break;

  case 384:
#line 6801 "parser.y"
           {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].lex)).str);
  
}
#line 10738 "parser.tab.c"
    break;

  case 385:
#line 6805 "parser.y"
                   {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].lex)).str);
  
}
#line 10747 "parser.tab.c"
    break;

  case 386:
#line 6809 "parser.y"
           {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].lex)).str);
  
}
#line 10756 "parser.tab.c"
    break;

  case 387:
#line 6813 "parser.y"
            {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].lex)).str);
  
}
#line 10765 "parser.tab.c"
    break;

  case 388:
#line 6817 "parser.y"
                                           {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].lex)).str);
  
}
#line 10774 "parser.tab.c"
    break;

  case 389:
#line 6821 "parser.y"
                                             {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].lex)).str);
  
}
#line 10783 "parser.tab.c"
    break;

  case 390:
#line 6825 "parser.y"
                                                                {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].lex)).str);
  
}
#line 10792 "parser.tab.c"
    break;

  case 391:
#line 6829 "parser.y"
          {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].lex)).str);
  
}
#line 10801 "parser.tab.c"
    break;

  case 392:
#line 6833 "parser.y"
          {
  
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].lex)).str);
}
#line 10810 "parser.tab.c"
    break;

  case 393:
#line 6837 "parser.y"
         {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].lex)).str);
  
}
#line 10819 "parser.tab.c"
    break;

  case 394:
#line 6843 "parser.y"
                     {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);

  ((yyval.typ)).ndim=((yyvsp[0].typ)).ndim;
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
  // strcpy(($1).argstring,($1).type);
    // cout<<"YO"<<($1).argstring<<'\n';

  
}
#line 10834 "parser.tab.c"
    break;

  case 395:
#line 6854 "parser.y"
           {
  strcpy(((yyval.typ)).tempvar, ((yyvsp[0].typ)).tempvar);
  strcpy(((yyval.typ)).type,((yyvsp[0].typ)).type);
  
}
#line 10844 "parser.tab.c"
    break;


#line 10848 "parser.tab.c"

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
#line 6859 "parser.y"


// Begin Declarations

string classcode;
string funccode;

typedef struct x86_code{
  string classn;
  string func;
  string arg1;
  string arg2;
} x86_code;

vector<x86_code> asmcode;

int inassign = 1;
string newblock;
int isret = 0;
int curracces = 0;
int mainwidth = 0;



// End Declarations

// Codegen functions

vector<string> registers = {"rax", "rbx", "rcx", "rdx", "r8b", "r9b", "r10b", "r11b", "r12b", "r13b", "r14b", "r15b"};

int last_reg_used = 0;

void update_reg(){
  last_reg_used ++ ;
  last_reg_used %= 12;
  return;
}

map<pair<string,string>, string> reg_map;

bool isliteral(string s){  // Returns true if it is a literal and false in case of var names
  if(s.size() == 0) return false;
  for(auto it: s){
    if( it < '0' || it > '9') return false;
  }
  return true;
}

string dectohex(string dec){
  int num = stoi(dec);
  string hex = "";
  while(num){
    int rem = num % 16;
    if(rem < 10) hex += (char)(rem + '0');
    else hex += (char)(rem - 10 + 'a');
    num /= 16;
  }
  reverse(hex.begin(), hex.end());
  hex = "0x" + hex ;
  return hex;
}


vector<int> objpushed;
int x86ind=5;

void addtox86(string classn,string func, string arg1, string arg2){
        x86ind ++ ;
        x86_code temp;
        temp.classn = classn;
        temp.func = func;
        temp.arg1 = arg1;
        temp.arg2 = arg2;
        asmcode.push_back(temp);
}

string optofunc(string op){
  string ans = "";
  if(op[0] == '+'){
    ans = "addq";
  }
  else if(op[0] == '*'){
    ans = "imulq";
  }
  else if(op[0] == '-'){
    ans = "subq";
  }
  return ans;
}

string temptoaddr(string arg, int lasize){
  if(arg[0] == '#'){
    int tempno = 0;
    string temp = arg.substr(2, arg.size()-1);
    arg = to_string(-(lasize + 8*stoi(temp)));
    arg = arg + "(%rbp)";
  }
  return arg;
}

string baseptr(string boxrep){
  if(boxrep[0] == '['){
    string off;
    int i = 4;
    while(boxrep[i]!=']'){
      off.push_back(boxrep[i]);
      i++;
    }
    boxrep = off + "(%" + boxrep.substr(1, 3) + ")";
    return boxrep;
  }
  else return boxrep;
}

int regalloc = 0;

string objtoattr(string s){
  if(s[0] == '@'){
    string addr;
    int ind = 1;
    while(s[ind] != ']'){
      addr.push_back(s[ind]);
      ind ++;
    }
    addr.push_back(']');
    addr = baseptr(addr);

    string cln;
    ind += 2 ;

    while(s[ind] != '@'){
      cln.push_back(s[ind]);
      ind ++ ;
    }

    string attr;
    ind ++ ;

    while(ind < s.length()){
      attr.push_back(s[ind]);
      ind ++ ;
    }

    for(auto it2: list_of_Symbol_Tables){
      auto tab = it2->table;
      for(auto it3 = tab.begin(); it3 != tab.end(); it3++){
          if(it3->second.scope_name == "Class" + cln){
              if(it3->first == attr){
                if(regalloc == 0){
                  addtox86("","movq", addr, "%r9");
                  addtox86("","addq", "$" + to_string(it3->second.offset), "%r9");
                  regalloc = (regalloc + 1)%3;
                  return "(%r9)";
                }
                else if(regalloc == 1){
                  addtox86("","movq", addr, "%r10");
                  addtox86("","addq", "$" + to_string(it3->second.offset), "%r10");
                  regalloc = (regalloc + 1)%3;
                  return "(%r10)";
                }
                else{
                  addtox86("","movq", addr, "%r11");
                  addtox86("","addq", "$" + to_string(it3->second.offset), "%r11");
                  regalloc = (regalloc + 1)%3;
                  return "(%r11)";
                }
              }
          }
          else{
              break;
          }
      }
    }

  }
  else{
    return s; 
  }
}

void opt(quad q, int lasize)  // lasize stores sum of sizes of locals and params
{
  string arg1, arg2, op, res;
  if(q.arg2[0] == '#'){
    int tempno = 0;
    string temp = q.arg2.substr(2, q.arg2.size()-1);
    arg2 = to_string(-(lasize + 8*stoi(temp)));
    arg2 = arg2 + "(%rbp)";
  }
  else{
    arg2 = q.arg2;
  }

  if(q.arg1[0] == '#'){
    int tempno = 0;
    string temp = q.arg1.substr(2, q.arg1.size()-1);
    arg1 = to_string(-(lasize + 8*stoi(temp)));
    arg1 = arg1 + "(%rbp)";
  }
  else{
    arg1 = q.arg1;
  }

  if(q.res[0] == '#'){
    int tempno = 0;
    string temp = q.res.substr(2, q.res.size()-1);
    res = to_string(-(lasize + 8*stoi(temp)));
    res = res + "(%rbp)";
  }
  else{
    res = q.res;
  }

  if(isliteral(arg1)){
    arg1 = "$" + arg1;
  }
  if(isliteral(arg2)){
    arg2 = "$" + arg2;
  }


  arg1 = baseptr(arg1);
  arg2 = baseptr(arg2);
  res = baseptr(res);

  // Shift Expressions
  if( q.op == "<<"){
    addtox86("","movq", arg2, "%rax");
    addtox86("","movq", arg1, "%rdx");
    addtox86("","movq", "%rax", "%rcx");
    addtox86("","salq", "%rcx", "%rdx");
    addtox86("","movq", "%rdx", "%rax");
    addtox86("","movq", "%rax", res);
    return;
  }
  else if( q.op == ">>"){
    addtox86("","movq", arg2, "%rax");
    addtox86("","movq", arg1, "%rdx");
    addtox86("","movq", "%rax", "%rcx");
    addtox86("","sarq", "%rcx", "%rdx");
    addtox86("","movq", "%rdx", "%rax");
    addtox86("","movq", "%rax", res);
  } 
  else if( q.op == ">>>"){
    addtox86("","movq", arg2, "%rax");
    addtox86("","movq", arg1, "%rdx");
    addtox86("","movq", "%rax", "%rcx");
    addtox86("","sarq", "%rcx", "%rdx");
    addtox86("","movq", "%rdx", "%rax");
    addtox86("","movq", "%rax", res);
  } 

  if(q.op == "&"){
    addtox86("","movq", arg1, "%rax");
    addtox86("","movq", arg2, "%rcx");
    addtox86("","and", "%rcx", "%rax");
    addtox86("","movq", "%rax", res);
  }
  else if(q.op == "|"){
    addtox86("","movq", arg1, "%rax");
    addtox86("","movq", arg2, "%rcx");
    addtox86("","or", "%rcx", "%rax");
    addtox86("","movq", "%rax", res);
  }
  else if(q.op == "~"){
    addtox86("","movq", arg1, "%rax");
    addtox86("","movq", arg2, "%rcx");
    addtox86("","not", "%rcx", "%rax");
    addtox86("","movq", "%rax", res);
  }


  // Division Expression
  if(q.op[0] == '/'){
    if(arg1[0] == '$' && arg2[0] == '$'){
        string temploc = "-8(%rbp)";
        addtox86("","movq", temploc, "%rcx");
        addtox86("","movq", arg1, "%rax");
        addtox86("","movq", arg2, temploc);
        addtox86("","cltd","", "");
        addtox86("","idivq", temploc, "");
        addtox86("","movq", "%rax", res);
        addtox86("","movq", "%rcx", temploc);
    }
    else if(arg1[0] == '$'){
        addtox86("","movq", arg1, "%rax");
        addtox86("","cltd", "", "");
        addtox86("","idivq", arg2, "");
        addtox86("","movq", "%rax", res);
    }
    else if(arg2[0] == '$'){
        addtox86("","movq", arg1, "%rax");
        addtox86("","movq", arg1, "%rcx");
        addtox86("","movq", arg2, arg1);
        addtox86("","cltd", "", "");
        addtox86("","idivq", arg1, "");
        addtox86("","movq", "%rax", res);
        addtox86("","movq", "%rcx", arg1);
    }
    else{
        addtox86("","movq", arg1, "%rax");
        addtox86("","cltd", "", "");
        addtox86("","idivq", arg2, "");
        addtox86("","movq", "%rax", res);
    }
  }

  //Modulo Expression
    if(q.op[0] == '%'){
    if(arg1[0] == '$' && arg2[0] == '$'){
        string temploc = "-8(%rbp)";
        addtox86("","movq", temploc, "%rcx");
        addtox86("","movq", arg1, "%rax");
        addtox86("","movq", arg2, temploc);
        addtox86("","cltd","", "");
        addtox86("","idivq", temploc, "");
        addtox86("","movq", "%rdx", res);
        addtox86("","movq", "%rcx", temploc);
    }
    else if(arg1[0] == '$'){
        addtox86("","movq", arg1, "%rax");
        addtox86("","cltd", "", "");
        addtox86("","idivq", arg2, "");
        addtox86("","movq", "%rdx", res);
    }
    else if(arg2[0] == '$'){
        addtox86("","movq", arg1, "%rax");
        addtox86("","movq", arg1, "%rcx");
        addtox86("","movq", arg2, arg1);
        addtox86("","cltd", "", "");
        addtox86("","idivq", arg1, "");
        addtox86("","movq", "%rdx", res);
        addtox86("","movq", "%rcx", arg1);
    }
    else{
        addtox86("","movq", arg1, "%rax");
        addtox86("","cltd", "", "");
        addtox86("","idivq", arg2, "");
        addtox86("","movq", "%rdx", res);
    }
  }
  
  // Comparision Operators

  if(q.op == "=="){
    addtox86("","movq", arg1, "%rax");
    addtox86("","movq", arg2, "%rcx");
    addtox86("","cmp", "%rax", "%rcx");
    addtox86("","sete", "%al", "");
    addtox86("","movzbq", "%al", "%rbx");
    addtox86("","movq", "%rbx", res);
  }
  else if(q.op == "!="){
    addtox86("","movq", arg1, "%rax");
    addtox86("","movq", arg2, "%rcx");
    addtox86("","cmp", "%rax", "%rcx");
    addtox86("","setne", "%al", "");
    addtox86("","movzbq", "%al", "%rbx");
    addtox86("","movq", "%rbx", res);
  }
  else if(q.op == "||"){
    addtox86("","movq", arg1, "%rax");
    addtox86("","movq", arg2, "%rcx");
    addtox86("","cmp", "%rax", "$1");
    addtox86("","sete", "%al", "");
    addtox86("","cmp", "%rcx", "$1");
    addtox86("","sete", "%al", "");
    addtox86("","movzbq", "%al", "%rbx");
    addtox86("","movq", "%rbx", res);
  }
  else if(q.op == "&&"){
    addtox86("","movq", arg1, "%rax");
    addtox86("","movq", arg2, "%rcx");
    addtox86("","cmp", "%rax", "%rcx");
    addtox86("","sete", "%al", "");
    addtox86("","movzbq", "%al", "%rbx");
    addtox86("","movq", "%rbx", res);
  }
  else if(q.op == ">="){
    addtox86("","movq", arg1, "%rax");
    addtox86("","movq", arg2, "%rcx");
    addtox86("","cmp", "%rax", "%rcx");
    addtox86("","setle", "%al", "");
    addtox86("","movzbq", "%al", "%rbx");
    addtox86("","movq", "%rbx", res);
  }
  else if(q.op == "<="){
    addtox86("","movq", arg1, "%rax");
    addtox86("","movq", arg2, "%rcx");
    addtox86("","cmp", "%rax", "%rcx");
    addtox86("","setge", "%al", "");
    addtox86("","movzbq", "%al", "%rbx");
    addtox86("","movq", "%rbx", res);
  }
  else if(q.op == "<"){
    addtox86("","movq", arg1, "%rax");
    addtox86("","movq", arg2, "%rcx");
    addtox86("","cmp", "%rax", "%rcx");
    addtox86("","setg", "%al", "");
    addtox86("","movzbq", "%al", "%rbx");
    addtox86("","movq", "%rbx", res);
  }
  else if(q.op == ">"){
    addtox86("","movq", arg1, "%rax");
    addtox86("","movq", arg2, "%rcx");
    addtox86("","cmp", "%rax", "%rcx");
    addtox86("","setl", "%al", "");
    addtox86("","movzbq", "%al", "%rbx");
    addtox86("","movq", "%rbx", res);
  }
  else if(q.op == "^"){
    addtox86("","movq", arg1, "%rax");
    addtox86("","movq", arg2, "%rcx");
    addtox86("","xorq", "%rcx", "%rax");
    addtox86("","movq", "%rax", res);
  }

  op = optofunc(q.op);

  // Add Mul Sub Expressions
  if(op != ""){
    addtox86("","movq", arg1, "%rax");
    addtox86("","movq", arg2, "%rdx");
    addtox86("",op, "%rax", "%rdx");
    if(op == "subq")
      addtox86("","neg", "%rdx", "");
    addtox86("","movq", "%rdx", res);
  }

}

string search_in_stack(string var){
  for(auto it: vartostack){
    if(it.first.first == var && it.first.second == ("Class" + curr_class + "_" + curr_func)){
      return it.second;
    }
  }
  return "Not Found";
}

int nextPowerOf2(int n) {
    if (n == 0) {
        return 1;
    } else {
        n--;
        n |= n >> 1;
        n |= n >> 2;
        n |= n >> 4;
        n |= n >> 8;
        n |= n >> 16;
        return n + 1;
    }
}

map<string, int> classconstructor;   // Stores 1 if class has constructor, else 0

void init_constructor(){
  for(auto it : list_of_Symbol_Tables){
    auto tab = it->table;
    for(auto it2 : tab){
      string scope = it2.second.scope_name;
      if(scope.substr(0,5) == "Class" && scope.substr(5) == it2.first && it2.second.token == "Constructor"){
        classconstructor[it2.first] = 1;
      }
    }
  }
}

int ctr=0;
string checkarray(string arg, string cl, string fn){
  if(arg[0] == '*' && arg[1] != '('){
    // cout<<arg<<endl;
    arg = arg.substr(1);
    arg = baseptr(arg);
    arg = temptoaddr(arg, funcsize["Class" + cl + "_" + fn]); 
    if(ctr)
    {
    string next = "%r12";
    addtox86("","movq", arg, next);
    arg = "(%r12)";
    ctr=0;
    }
    else{
      string next = "%r13";
    addtox86("","movq", arg, next);
    arg = "(%r13)";
    ctr=1;
    }
    return arg;
  }
  else if(arg[0] == '*' && arg[1] == '('){
    arg = arg.substr(2);
    arg = baseptr(arg);
    arg = temptoaddr(arg, funcsize["Class" + cl + "_" + fn]); 
    if(ctr)
    {
    string next = "%r12";
    addtox86("","movq", arg, next);
    arg = "(%r12)";
    ctr=0;
    }
    else{
      string next = "%r13";
    addtox86("","movq", arg, next);
    arg = "(%r13)";
    ctr=1;
    }
    return arg;
  }
  else{
    return arg;
  }
}

int objreg = 0;

string fieldacc(string s){
  if(s[0] == '!'){
    if(objreg == 0){
      addtox86("","movq", "%r14", "%r8");
      addtox86("","addq", "$" + s.substr(1), "%r8");
      objreg ++ ;
      objreg %= 3;
      return "(%r8)";
    }
    else if(objreg == 1){
      addtox86("","movq", "%r14", "%r10");
      addtox86("","addq", "$" + s.substr(1), "%r10");
      objreg ++ ;
      objreg %= 3;
      return "(%r10)";
    }
    else{
      addtox86("","movq", "%r14", "%r9");
      addtox86("","addq", "$" + s.substr(1), "%r9");
      objreg ++ ;
      objreg %= 3;
      return "(%r9)";
    }
  }
  else{
    return s;
  }
}

string thisptr(string s, string cln, string fn){
  if(s.substr(0,4) == "this"){
    if(objreg == 0){
      // addtox86("","movq", "%r14", "%r8");
      if(s[5] == '#'){
        string temp = s.substr(6, s.size()-1);
        addtox86("","addq", "$" + to_string(funcsize["Class" + cln + "_" + fn] +  8*stoi(temp)), "%r8");
      }
      objreg ++ ;
      objreg %= 3;
      return "%r8";
    }
    else if(objreg == 1){
      // addtox86("","movq", "%r14", "%r8");
      if(s[5] == '#'){
        string temp = s.substr(6, s.size()-1);
        addtox86("","addq", "$" + to_string(funcsize["Class" + cln + "_" + fn] +  8*stoi(temp)), "%r10");
      }
      objreg ++ ;
      objreg %= 3;
      return "%r10";
    }
    else{
    //   // addtox86("","movq", "%r14", "%r9");
      if(s[5] == '#'){
        string temp = s.substr(6, s.size()-1);
        addtox86("","addq", "$" + to_string(funcsize["Class" + cln + "_" + fn] +  8*stoi(temp)), "%r9");
      }
      objreg ++; 
      objreg %= 3;
      return "%r9";
    }
  }
  else{
    return s;
  }
}

int isvar(string s){
  if(isliteral(s)){
    return 0;
  }
  else{
    if(s[0] >= 'a' && s[0] <= 'z'){
      return 1;
    }
    else if(s[0] >= 'A' && s[0] <= 'Z'){
      return 1;
    }
    else if(s[0] == '_'){
      return 1;
    }
  }
}

int thisreg = 0;

string checkifglobal(string s, string cln){
  if(s[s.size() - 1] == '!'){
    s = s.substr(0, s.size()-1);
    string next;
    if(thisreg == 0){
      next = "%r11";
    }
    else if(thisreg == 1){
      next = "%r12";
    }
    else{
      next = "%r13";
    }

    thisreg ++;
    thisreg %= 3;

    for(auto it: classfield["Class" + cln]){
      if(it.first == s){
        addtox86("","movq", "%r14", next);
        addtox86("","addq", "$" + to_string(it.second), next);
        return "(" + next + ")";
      }
    }
    return s;
  }
  else{
    return s;
  }
}

int clnreg = 0;
string currobj1 = "main";
int ifclass(string s, string cln){
  string o = s.substr(0, s.find('.'));
  if(o == s){
    return 0;
  }
  else{
    return 1;
  }
}

// End Codegen

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

  // for(auto it: list_of_Symbol_Tables){
  //   // cout<<"NEW TABLE"<<'\n';
  //   it->print_table();
  //   cout<<"Classwidth: "<<it->classwidth<<endl;
  //   cout<<'\n';
  // }

  // for(auto it: funcsize){
  //   cout<<it.first<<" "<<it.second<<'\n';
  //   string cl = it.first.substr(it.first.find("_") + 1);
  //   if(cl == "main"){
  //     mainwidth = it.second;
  //   }
  // }

  // for(auto it: vartostack){
  //   cout<<it.first.first<<" "<<it.first.second<<" "<<it.second<<'\n';
  // }

  // for(auto it: numfuncargs){
  //   cout<<it.first<<" "<<it.second<<endl;
  // }

  // init_constructor();
  // for(auto it: classconstructor){
  //   cout<<it.first<<" "<<it.second<<endl;
  // }

  // for(auto it: classfield){
  //   cout<<it.first<<'\n';
  //   for(auto it1 : it.second){
  //     cout<<it1.first<<' '<<it1.second<<'\n';
  //   }
  // }

  // for(auto it: storeobj){
  //   cout<<it.first<<"// "<<it.second<<endl;
  // }
/* ofstream x;
x.open("TAC.txt");
   for(auto it: code){
    if(it.op=="FLD")
    {
      fielddeclist+=it.arg1;
    }
   }
cout<<fielddeclist<<"\n"; */
  // for(auto it: numfuncargs){
  //   cout<<it.first<<" "<<it.second<<endl;
  // }

  // for(auto it: classconstructor){
  //   cout<<it.first<<" "<<it.second<<endl;
  // }

  // for(auto it: classfield){
  //   cout<<it.first<<'\n';
  //   for(auto it1 : it.second){
  //     cout<<it1.first<<' '<<it1.second<<'\n';
  //   }
  // }

  // for(auto it: storeobj){
  //   cout<<it.first<<"// "<<it.second<<endl;
  // }

  // for(auto it: objlist){
  //   cout<<it<<endl;
  // }


init_constructor();
map<string,string> store;
map<pair<string,string>,string> store1;
ofstream fout;
fout.open("TAC.txt");
   for(auto it: code){
    curracces ++ ;
    if(it.arg1 == "obj" && it.op == "param"){
          addtox86("","pushq", "obj", "");
          objpushed.push_back(x86ind);
          continue;
    }
    // fout<<it.op<<' '<<it.arg1<<' '<<it.arg2<<' '<<it.res<<endl;
    if(it.arg1 == "shiftreg"){
      it.res = temptoaddr(it.res, funcsize["Class" + curr_class + "_" + curr_func]);
      addtox86("","movq", "%r14", it.res);
      if(curracces >= 2 && code[curracces-2].op == "param" && isliteral(code[curracces-2].arg1) == 0 && code[curracces-2].arg1 != "obj"){
        addtox86("","movq", temptoaddr(baseptr(code[curracces-2].arg1), funcsize["Class" + curr_class + "_" + curr_func]), "%r14");
        objpushed.push_back(x86ind - 2);
      }
      continue;
    }
    if(it.res == "shiftreg"){
      it.arg1 = temptoaddr(it.arg1, funcsize["Class" + curr_class + "_" + curr_func]);
      addtox86("","movq",  it.arg1, "%r14");
      continue;
    }

   if(search_in_stack(it.arg1) != "Not Found"){
    it.arg1 = search_in_stack(it.arg1);
   }
   if(search_in_stack(it.arg2) != "Not Found"){
    it.arg2 = search_in_stack(it.arg2);
   }
   if(search_in_stack(it.res) != "Not Found"){
    it.res = search_in_stack(it.res);
   }

   it.arg1 = thisptr(it.arg1, curr_class, curr_func);
   it.arg2 = thisptr(it.arg2, curr_class, curr_func);
   it.res = thisptr(it.res, curr_class, curr_func);

   it.arg1 = fieldacc(it.arg1);
   it.arg2 = fieldacc(it.arg2);
   it.res = fieldacc(it.res);

   if(isliteral(it.arg1)) it.arg1 = "$" + it.arg1;
   if(isliteral(it.arg2)) it.arg2 = "$" + it.arg2;
   if(isliteral(it.res)) it.res = "$" + it.res;


   it.arg1 = checkarray(it.arg1, curr_class, curr_func);
   it.arg2 = checkarray(it.arg2, curr_class, curr_func);
   it.res = checkarray(it.res, curr_class, curr_func);

   it.arg1 = baseptr(it.arg1);
   it.arg2 = baseptr(it.arg2);
   it.res = baseptr(it.res);

   it.arg1 = temptoaddr(it.arg1, funcsize["Class" + curr_class + "_" + curr_func]);
   it.arg2 = temptoaddr(it.arg2, funcsize["Class" + curr_class + "_" + curr_func]);
   it.res = temptoaddr(it.res, funcsize["Class" + curr_class + "_" + curr_func]);

   it.arg1 = checkifglobal(it.arg1, curr_class);
   it.arg2 = checkifglobal(it.arg2, curr_class);
   it.res = checkifglobal(it.res, curr_class);

   it.arg1 = objtoattr(it.arg1);
   it.arg2 = objtoattr(it.arg2);
   it.res = objtoattr(it.res);   

  if(it.arg1[0] == '+') it.arg1 = it.arg1.substr(1);
   if(it.arg2[0] == '+') it.arg2 = it.arg2.substr(1);
   if(it.res[0] == '+') it.arg1 = it.res.substr(1); 

    if(true)
    {
      /* if(it.op=="FLD")
      {
        string temp=it.arg1;
        int last=0;
        string yo="";
        for(int i=0;;i++)
        {
          if(temp[i]=='#') break;
          if(temp[i]=='$')
          {
            yo=temp.substr(last,i-last);
            last=i+1;
          }
          if(temp[i]==' ')
          {
            addtox86("","movq","%r14","%r9");
            addtox86("","movq","$"+temp.substr(last,i-last),"%r8");
            addtox86("","addq","%r8","%r9");
            addtox86("","movq","$"+yo,"(%r9)");
            yo="";
            last=i+1;
          }
        }
      } */
      if(it.op == "addretval"){
        fout<<'\t'<<it.op<<" "<<it.arg1<<'\n';
        it.arg1 = baseptr(it.arg1);
        it.arg1 = temptoaddr(it.arg1, funcsize["Class" + curr_class + "_" + curr_func]);
        if(isliteral(it.arg1)){
          it.arg1 = "$" + it.arg1;
        }
        addtox86("","movq", it.arg1, "%rax");
        addtox86("","leave","", "");
        addtox86("","ret","", "");
        isret = 1;
      }
      else if(it.op == "BeginClass"){
        inassign = 1;
        fout<<'\t'<<it.op<<" "<<it.arg1<<'\n';
        curr_class = newblock;
        if(classconstructor[curr_class] == 0){
          addtox86("","pushq", "%rbp", "");
          addtox86("","movq", "%rsp", "%rbp");
          int sh=curracces;
          for(sh;;sh++)
          {
            if(code[sh].op=="EndClass") break;
            else if(code[sh].op=="FLD")
            {
              string temp=code[sh].arg1;
              int last=0;
              string yo="";
              for(int i=0;;i++)
              {
                if(temp[i]=='|') break;
                if(temp[i]=='$')
                {
                   if(i==last)
                    break;
                  yo=temp.substr(last,i-last);
                  last=i+1;
                }
                if(temp[i]==' ')
                {
                  addtox86("","movq","%r14","%r9");
                  addtox86("","movq","$"+temp.substr(last,i-last),"%r8");
                  addtox86("","addq","%r8","%r9");
                  addtox86("","movq","$"+yo,"(%r9)");
                  yo="";
                  last=i+1;
                }
              }
            }
          }
          addtox86("","movq", "$0", "%rax");
          addtox86("","leave", "", "");
          addtox86("","ret", "", "");
        }
        if(classconstructor[curr_class] == 0){
          addtox86("","pushq", "%rbp", "");
          addtox86("","movq", "%rsp", "%rbp");
          addtox86("","movq", "$0", "%rax");
          addtox86("","leave", "", "");
          addtox86("","ret", "", "");
        }
        store[curr_class]=curr_class;
      }
      else if(it.op == "BeginFunc" || it.op == "BeginCtor"){
        isret = 0;
        inassign = 1;
        fout<<'\t'<<it.op<<" "<<it.arg1<<'\n';
        curr_func = newblock;
        string a;
        if(!(!strcmp(curr_func.c_str(),curr_class.c_str()) || !strcmp(curr_func.c_str(),"main")))
        {   
          a=curr_class+"."+curr_func;
        }
        else
        {
        a=curr_func;
        }
        store[curr_func]=a;
        store1[make_pair(curr_class,curr_func)]=a;
      }
      else if(it.op=="EndFunc" || it.op=="EndClass" || it.op=="EndCtor")
       {
        if(it.op=="EndFunc" ||it.op=="EndCtor"){
          addtox86("","leave","","");
          addtox86("","ret","","");
        }
        fout<<'\t'<<it.op<<" "<<it.arg1<<'\n';
        if(it.op=="EndClass"){
          fout<<'\n';
        }
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
      if(it.res == "%r8") it.res = "(%r8)";
      else if(it.res == "%r9") it.res = "(%r9)";
      if(it.arg1 == "%r8") it.arg1 = "(%r8)";
      else if(it.arg1 == "%r9") it.arg1 = "(%r9)";

      if(it.op=="minus"||it.op=="plus"||it.op=="!"||it.op=="~")
        {
            fout<<'\t'<<it.res<<' '<<"= "<<it.op<<' '<<it.arg1<<'\n';
        }
      else 
        {
        fout<<'\t'<<it.res<<' '<<"="<<" "<<it.arg1<<'\n';
        if(it.arg1 == "rbp" || it.arg1 == "rsp" ){
          addtox86("","movq", "%" + it.arg1, "%" + it.res);
          if(curr_func==curr_class)
          {
            int sh=curracces;
            for(sh;;sh++)
            {
              if(code[sh].op=="EndClass") break;
              else if(code[sh].op=="FLD")
              {
                string temp=code[sh].arg1;
                int last=0;
                string yo="";
                for(int i=0;;i++)
                {
                  if(temp[i]=='|') break;
                  if(temp[i]=='$')
                  {
                    if(i==last)
                    break;
                    yo=temp.substr(last,i-last);
                    last=i+1;
                  }
                  if(temp[i]==' ')
                  {
                    addtox86("","movq","%r14","%r9");
                    addtox86("","movq","$"+temp.substr(last,i-last),"%r8");
                    addtox86("","addq","%r8","%r9");
                    addtox86("","movq","$"+yo,"(%r9)");
                    yo="";
                    last=i+1;
                  }
                }
              }
            }
          }
          if(it.arg1 == "rsp" && it.res == "rbp"){
            for(int i =0; i<numfuncargs["Class" + curr_class + "_" + curr_func]; ++i){
              addtox86("","movq", to_string(16 + i*8) + "(%rbp)", "%rdx");
              addtox86("","movq", "%rdx", to_string(-8 - i*8) + "(%rbp)");
            }
          }
          if(curr_func == "main"){
            addtox86("","movq", "$" + to_string(mainwidth), "%rdi");
            addtox86("","call", "malloc@PLT", "");
            addtox86("","movq", "%rax", "%r15");
            addtox86("","movq", "%rax", "%r14");
          }
          int subesp = funcsize["Class" + curr_class + "_" + curr_func] + 8*counter;
          subesp = nextPowerOf2(subesp);
          addtox86("","subq", "$" + to_string(subesp), "%rsp");   // Changes the stack pointer to accomodate the function local variables and parameters
        }
        else if(it.arg1 == "popparam"){
          it.res = baseptr(it.res);
          it.res = temptoaddr(it.res, funcsize["Class" + curr_class + "_" + curr_func]);
          addtox86("","movq", "%rax", it.res);
        }
        else if(it.res == "popparam"){
          continue;
        }
        else{
          if(isliteral(it.arg1)){
            it.arg1 = "$" + it.arg1;
          }
          
          it.res = baseptr(it.res);
          it.arg1 = baseptr(it.arg1);
          it.res = temptoaddr(it.res, funcsize["Class" + curr_class + "_" + curr_func]);
          it.arg1 = temptoaddr(it.arg1, funcsize["Class" + curr_class + "_" + curr_func]);
          if(it.arg1[0] == '$'){
            addtox86("","movq", it.arg1, it.res);
          }
          else{
            addtox86("","movq", it.arg1, "%rax");
            addtox86("","movq", "%rax", it.res);
          }
        }
        }
        if(it.idx == -2){
          inassign = 1;
        }
        
      }
      else if(it.op == "push" && it.arg1 == "rbp"){
        fout<<'\t'<<it.op<<" "<<it.arg1<<'\n';
        addtox86("","pushq", "%rbp", "");
      }
      else if(it.op == "pop" && it.arg1 == "rbp"){
        fout<<'\t'<<it.op<<" "<<it.arg1<<'\n';
        // addtox86("","popq", "%rbp", "");
      }
      else if(it.op == "param"){
        fout<<'\t'<<it.op<<" "<<it.arg1<<'\n';
        it.arg1 = baseptr(it.arg1);
        it.arg1 = temptoaddr(it.arg1, funcsize["Class" + curr_class + "_" + curr_func]);
        if(isliteral(it.arg1)){
          it.arg1 = "$" + it.arg1;
        }
        if(code[curracces].arg1 == "allocmem"){
          addtox86("","movq", it.arg1, "%rdi");
        }
        else
          addtox86("","pushq", it.arg1, "");
      }
      else if(it.op=="Popparams"||it.op == "stackpointer"|| it.op == "pop" ||it.op == "push")
      {
        fout<<'\t'<<it.op<<" "<<it.arg1<<'\n';
      }
      else if (it.op == "call" && it.arg1 == "print 1"){
        fout<<'\t'<<it.op<<" "<<it.arg1<<" "<<it.arg2<<'\n';
        if(it.arg2[0] == '.'){
          it.arg2 = it.arg2.substr(1);
          it.arg2 = baseptr(it.arg2);
          it.arg2 = temptoaddr(it.arg2, funcsize["Class" + curr_class + "_" + curr_func]);
          string o = it.res.substr(0, it.res.find('.'));
          string attr = it.res.substr(it.res.find('.') + 1);
          int offattr = 0;
          for(auto it: classfield["Class" + curr_class]){
            if(it.first == attr){
              offattr = it.second;
              break;
            }
          }
            addtox86("","movq", it.arg2, "%r8");
            addtox86("","addq", "$" + to_string(offattr), "%r8");
            it.arg2 = "(%r8)";
          
        }
        else if(isvar(it.arg2)){
          for(auto it1 : classfield["Class" + curr_class]){
            
            if(it1.first == it.arg2){
              addtox86("","movq", "%r14", "%rbx");
              addtox86("","addq", "$" + to_string(it1.second), "%rbx");
              it.arg2 = "(%rbx)";
              break;
            }
          }
          if(it.arg2 != "(%rbx)"){
            it.arg2 = "(%r8)";
          }
        }
        else if(it.arg2[0] == '*'){
          it.arg2 = it.arg2.substr(1);
          it.arg2 = baseptr(it.arg2);
          it.arg2 = temptoaddr(it.arg2, funcsize["Class" + curr_class + "_" + curr_func]);
          addtox86("","movq", it.arg2, "%rax");
          it.arg2 = "(%rax)";
        }
        it.arg2 = baseptr(it.arg2);
        it.arg2 = temptoaddr(it.arg2, funcsize["Class" + curr_class + "_" + curr_func]);
        addtox86("","movq", it.arg2, "%rax");
        addtox86("","movq", "%rax", "%rsi");
        addtox86("","leaq", ".LC0(%rip)", "%rax");
        addtox86("","movq", "%rax", "%rdi");
        addtox86("","movq", "$0", "%rax");
        addtox86("","call", "printf@PLT", "");
      }
      else if(it.op == "call"){
        fout<<'\t'<<it.op<<" "<<it.arg1<<" "<<it.arg2<<'\n';
        
        if(it.arg1 == "allocmem"){
          addtox86("","call", "malloc@PLT", "");
        }
        else{
          if(store[it.arg1] != "") it.arg1 = store[it.arg1];
          if(store[it.arg2] != "") it.arg2 = store[it.arg2];
          addtox86("","call", it.arg1, it.arg2);
        }
      }
      else if(it.op == "add"||it.op == "sub"){
        fout<<'\t'<<it.op<<" "<<it.arg1<<" "<<it.arg2<<'\n';
      }
      else if(it.res=="Ifz")
      {
        fout<<'\t'<<it.res<<" "<<it.arg1<<" "<<it.op<<" "<<it.arg2<<"\n";
        it.arg1 = baseptr(it.arg1);
        it.arg1 = temptoaddr(it.arg1, funcsize["Class" + curr_class + "_" + curr_func]);
        if(isliteral(it.arg1)){
          it.arg1 = "$" + it.arg1;
        }
        addtox86("","movq", it.arg1, "%rax");
        addtox86("","cmp", "$0", "%rax");
        addtox86("","je", it.arg2, "");
      }
      else if(it.op=="Goto")
      {
        fout<<'\t'<<it.op<<" "<<it.arg1<<it.arg2<<it.res<<"\n";
        if(it.arg1 == "")
          addtox86("","jmp", it.arg2, "");
        else
           addtox86("","jmp", it.arg1, "");
      }
      else if(it.arg1==":")
      {
        // fout<<'\t';
        // fout<<'\t';
        //cout<<curr_class<<"HI"<<it.op<<it.arg1<<"Hi\n";
        fout<<it.op<<it.arg1<<"\n";
        addtox86(curr_class,it.op, it.arg1, "");
        newblock = it.op;
        // fout<<it.op<<it.arg1<<"\n";
        // addtox86("",it.op, it.arg1, "");
        // newblock = it.op;
      }
      else if(it.arg1=="new")
      {
        fout<<'\t'<<it.res<<" = "<<it.arg1<<" "<<it.arg2<<"\n";
      }
      else if(it.op=="ret")
      {
        if(code[curracces].op=="Goto")
        {
          if(code[curracces].arg1=="")
            addtox86("","jmp", code[curracces].arg2, "");
          else
            addtox86("","jmp", code[curracces].arg1, "");
          // addtox86("","jmp", code[curracces].arg2, "");
        }
        /* cout<<"GHF "<<code[curracces].op<<code[curracces].arg1<<code[curracces].arg2<<'\n'; */
        fout<<'\t'<<it.op<<" "<<it.arg1<<"\n";
        if(isret == 0)
          addtox86("","movq", "$0", "%rax");  // Harcoding the return value
        /* addtox86("","leave", "", "");
        addtox86("",it.op, "", ""); */
        /* cout<<"SHU "<<it.op<<'\n';
         */
      }
      else if(it.arg1=="cast_to_int"||it.arg1=="cast_to_float"||it.arg1=="cast_to_byte"||it.arg1=="cast_to_boolean"||it.arg1=="cast_to_byte"||it.arg1=="cast_to_short"||it.arg1=="cast_to_long"||it.arg1=="cast_to_double"||it.arg1=="cast_to_string")
      {
        addtox86("","movq", it.arg2, "%rax");
        addtox86("","movq", "%rax", it.res);
        fout<<'\t'<<it.res<<" = "<<it.arg1<<" "<<it.arg2<<"\n";
      }
      else
      { 
        string op;
        op.push_back(it.op[0]);
        if(find(ops.begin(), ops.end(), op) != ops.end()){
          opt(it, funcsize["Class" + curr_class + "_" + curr_func]);
        }
        fout<<'\t'<<it.res<<" = "<<it.arg1<<" "<<it.op<<" "<<it.arg2<<"\n";
      }

      }
    }
  
    //for(auto it: objpushed) cout<<"Not to print "<<it<<endl;

    x86ind = 5;
    int length = objpushed.size();
    int i = 0;

    fout.close();
    fout.open("x86code.s");

    fout << "\t.section    .rodata" << '\n';
    fout<<".LC0:" << '\n';
    fout<< "\t.string    \"%ld\\n\""<<'\n';
    fout<<"\t.text"<<'\n';
    fout<<"\t.globl    main"<<'\n';

    for(auto it: asmcode){
      x86ind ++ ;
      if(i<length && x86ind == objpushed[i]){
        i ++ ;
        continue;
      }
      if(it.arg1 == ":" ){
      if(it.func[0]=='L')
      {
      cout<<it.func<<' '<<it.arg1<<' '<<it.arg2<<'\n';
      fout<<it.func<<' '<<it.arg1<<' '<<it.arg2<<'\n';
      } 
      else if(store1[make_pair(it.classn,it.func)]!="")
      {
      cout<<store1[make_pair(it.classn,it.func)]<<' '<<it.arg1<<' '<<it.arg2<<'\n';
      fout<<store1[make_pair(it.classn,it.func)]<<' '<<it.arg1<<' '<<it.arg2<<'\n';
      }
      else
      {
      cout<<store[it.func]<<' '<<it.arg1<<' '<<it.arg2<<'\n';
      fout<<store[it.func]<<' '<<it.arg1<<' '<<it.arg2<<'\n';
      }
      }
      else{
        if(it.arg2 != ""){
          cout<<'\t'<<it.func<<' '<<it.arg1<<", "<<it.arg2<<'\n';
          fout<<'\t'<<it.func<<' '<<it.arg1<<", "<<it.arg2<<'\n';
        }
        else{
          cout<<'\t'<<it.func<<' '<<it.arg1<<'\n';
          fout<<'\t'<<it.func<<' '<<it.arg1<<'\n';
        }
      }
    }
    // for(auto i:store1)
    // {
    //   cout<<i.first.first<<" "<<i.first.second<<" "<<i.second<<'\n';
    // }

  return 0;
}

void yyerror(const char * s)
{
  cout<<"Error in line " << yylineno << " : " << s << endl;
  exit(0);
}
