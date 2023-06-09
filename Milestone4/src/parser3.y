%{
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
%}

%define parse.error verbose

%union {
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
}

%type<typ> DummyMethodInvocation
%type<typ> ConstructorHeader 
%type<typ> Goal
%type<typ> Literal
%type<typ> Type
%type<typ> PrimitiveType
%type<typ> NumericType
%type<typ> IntegralType
%type<typ> FloatingPointType
%type<typ> ReferenceType
%type<typ> ClassOrInterfaceType
%type<typ> ClassType
%type<typ> InterfaceType
%type<typ> ArrayType
%type<typ> Name
%type<typ> SimpleName
%type<typ> QualifiedName
%type<typ> CompilationUnit
%type<typ> ImportDeclarations
%type<typ> TypeDeclarations
%type<typ> PackageDeclaration
%type<typ> ImportDeclaration
%type<typ> SingleTypeImportDeclaration
%type<typ> TypeImportOnDemandDeclaration
%type<typ> TypeDeclaration
%type<typ> Modifiers
%type<typ> Modifier
%type<typ> ClassDeclaration
%type<typ> Super 
%type<typ> Interfaces
%type<typ> InterfaceTypeList
%type<typ> ClassBody
%type<typ> ClassBodyDeclarations
%type<typ> ClassBodyDeclaration
%type<typ> ClassMemberDeclaration
%type<typ> FieldDeclaration
%type<typ> VariableDeclarators
%type<typ> VariableDeclarator
%type<typ> VariableDeclaratorId
%type<typ> VariableInitializer
%type<typ> MethodDeclaration
%type<typ> MethodHeader
%type<typ> MethodDeclarator
%type<typ> FormalParameterList
%type<typ> FormalParameter
%type<typ> Throws
%type<typ> ClassTypeList
%type<typ> MethodBody
%type<typ> StaticInitializer
%type<typ> ConstructorDeclaration
%type<typ> ConstructorDeclarator
%type<typ> ConstructorBody
%type<typ> ExplicitConstructorInvocation
%type<typ> InterfaceDeclaration
%type<typ> ExtendsInterfaces
%type<typ> InterfaceBody
%type<typ> InterfaceMemberDeclarations
%type<typ> InterfaceMemberDeclaration
%type<typ> ConstantDeclaration
%type<typ> AbstractMethodDeclaration
%type<typ> ArrayInitializer
%type<typ> VariableInitializers
%type<typ> Block
%type<typ> BlockStatements
%type<typ> BlockStatement
%type<typ> LocalVariableDeclarationStatement
%type<typ> LocalVariableDeclaration
%type<typ> Statement
%type<typ> StatementNoShortIf
%type<typ> StatementWithoutTrailingSubstatement
%type<typ> EmptyStatement
%type<typ> LabeledStatement
%type<typ> LabeledStatementNoShortIf
%type<typ> ExpressionStatement
%type<typ> StatementExpression
%type<typ> IfThenStatement
%type<typ> IfThenElseStatement
%type<typ> IfThenElseStatementNoShortIf
%type<typ> SwitchStatement
%type<typ> SwitchBlock
%type<typ> SwitchBlockStatementGroups
%type<typ> SwitchBlockStatementGroup
%type<typ> SwitchLabels
%type<typ> SwitchLabel
%type<typ> WhileStatement
%type<typ> WhileStatementNoShortIf
%type<typ> DoStatement
%type<typ> ForStatement
%type<typ> ForStatementNoShortIf
%type<typ> ForInit
%type<typ> ForUpdate
%type<typ> StatementExpressionList
%type<typ> BreakStatement
%type<typ> ContinueStatement
%type<typ> ReturnStatement
%type<typ> ThrowStatement
%type<typ> SynchronizedStatement
%type<typ> TryStatement
%type<typ> Catches
%type<typ> CatchClause
%type<typ> Finally
%type<typ> Primary
%type<typ> PrimaryNoNewArray
%type<typ> ClassInstanceCreationExpression
%type<typ> ArgumentList
%type<typ> ArrayCreationExpression
%type<typ> DimExprs
%type<typ> DimExpr
%type<typ> Dims
%type<typ> FieldAccess
%type<typ> MethodInvocation
%type<typ> ArrayAccess
%type<typ> PostfixExpression
%type<typ> PostIncrementExpression
%type<typ> PostDecrementExpression
%type<typ> UnaryExpression
%type<typ> PreIncrementExpression
%type<typ> PreDecrementExpression
%type<typ> UnaryExpressionNotPlusMinus
%type<typ> CastExpression
%type<typ> MultiplicativeExpression
%type<typ> AdditiveExpression
%type<typ> ShiftExpression
%type<typ> RelationalExpression
%type<typ> EqualityExpression
%type<typ> AndExpression
%type<typ> ExclusiveOrExpression
%type<typ> InclusiveOrExpression
%type<typ> ConditionalAndExpression
%type<typ> ConditionalOrExpression
%type<typ> ConditionalExpression
%type<typ> AssignmentExpression
%type<typ> Assignment
%type<typ> LeftHandSide
%type<typ> AssignmentOperator
%type<typ> Expression
%type<typ> ConstantExpression
%type<typ> DummyIfStatement1
%type<typ> DummyIfStatement2
%type<typ> DummyWhileStatement
%type<typ> DummyWhileStatement1
%type<typ> DummyDoStatement
%type<typ> DummyDoStatement1
%type<typ> DummyForStatement
%type<typ> DummyForStatement1
%type<typ> DummyForStatement2
%type<typ> DummyForStatement3
%type<typ> DummyForStatement4
%type<typ> DummyForStatement5
%type<typ> DummyForStatement6
%type<typ> DummyForStatement7
%type<typ> DummyForStatement8
%type<typ> DummyForStatement9
%type<typ> DummyForStatement10
%type<typ> DummyForStatement11
%type<typ> DummyForStatement12
%type<typ> DummyForStatement13
%type<typ> DummyForStatement14
%type<typ> DummyForStatement15
%type<typ> DummyImport
%token<lex> BYTE
%token<lex> SHORT 
%token<lex> INT
%token<lex> LONG 
%token<lex> CHAR
%token<lex> ELSE
%token<lex> CATCH
%token<lex> FINALLY
%token<lex> INTERFACE
%token<lex> PLUS
%token<lex> FORWARDSLASH
%token<lex> MODULO
%token<lex> IF 
%token<lex> SWITCH
%token<lex> IntegerLiteral
%token<lex> FloatingPointLiteral
%token<lex> BooleanLiteral
%token<lex> CharacterLiteral
%token<lex> StringLiteral
%token<lex> NullLiteral
%token<lex> FLOAT
%token<lex> DOUBLE
%token<lex> BOOLEAN
%token<lex> CASE
%token<lex> DEFAULT
%token<lex> DO
%token<lex> WHILE
%token<lex> OPENANGULARBRACKET
%token<lex> CLOSEANGULARBRACKET
%token<lex> OPENBRACKET
%token<lex> CLOSEBRACKET
%token<lex> OPENCURLYBRACKET
%token<lex> CLOSECURLYBRACKET
%token<lex> OPENSQUAREBRACKET
%token<lex> CLOSESQUAREBRACKET
%token<lex> EQUAL
%token<lex> STAREQUAL
%token<lex> FORWARDSLASHEQUAL
%token<lex> PLUSEQUAL
%token<lex> MINUSEQUAL
%token<lex> OPENANGULARBRACKETOPENANGULARBRACKETEQUAL
%token<lex> CLOSEANGULARBRACKETCLOSEANGULARBRACKETEQUAL
%token<lex> CLOSEANGULARBRACKETCLOSEANGULARBRACKETCLOSEANGULARBRACKETEQUAL
%token<lex> ANDEQUAL
%token<lex> XOREQUAL
%token<lex> OREQUAL
%token<lex> DOT
%token<lex> COMMA
%token<lex> SEMICOLON
%token<lex> COLON
%token<lex> INSTANCEOF
%token<lex> Identifier
%token<lex> PUBLIC 
%token<lex> PROTECTED 
%token<lex> PRIVATE
%token<lex> STATIC
%token<lex> ABSTRACT 
%token<lex> FINAL 
%token<lex> NATIVE 
%token<lex> SYNCHRONIZED 
%token<lex> TRANSIENT 
%token<lex> VOLATILE
%token<lex> PACKAGE
%token<lex> IMPORT 
%token<lex> STAR
%token<lex> CLASS
%token<lex> EXTENDS
%token<lex> IMPLEMENTS
%token<lex> VOID
%token<lex> THIS 
%token<lex> SUPER
%token<lex> BREAK
%token<lex> RETURN
%token<lex> FOR
%token<lex> TRY
%token<lex> THROWS
%token<lex> THROW
%token<lex> CONTINUE
%token<lex> NEW
%token<lex> PLUSPLUS
%token<lex> MINUSMINUS
%token<lex> TILDA
%token<lex> NOT
%token<lex> AND
%token<lex> OR
%token<lex> OROR
%token<lex> ANDAND
%token<lex> NOTEQUAL
%token<lex> MINUS
%token<lex> OPENANGULARBRACKETOPENANGULARBRACKET
%token<lex> CLOSEANGULARBRACKETCLOSEANGULARBRACKET
%token<lex> CLOSEANGULARBRACKETCLOSEANGULARBRACKETCLOSEANGULARBRACKET
%token<lex> QUESTION
%token<lex> XOR
%token<lex> EQUALEQUAL
%token<lex> OPENANGULARBRACKETEQUAL
%token<lex> CLOSEANGULARBRACKETEQUAL
%%
Goal:
CompilationUnit {
  
  
};
Literal:
IntegerLiteral {
  // cout<<"GYO"<<stoi(($1).str)<<'\n';
  fielddeclist=fielddeclist+($1).str+"$"+to_string(fieldcount*8)+" ";
  fieldcount++;
  dimint=stoi(($1).str);
  strcpy(($$).tempvar,($1).str);
  strcpy(($$).type,"int");
  // sz = getsz(string((char*)(($$).type)));
sz = 8;
}
|FloatingPointLiteral  {
  strcpy(($$).tempvar,($1).str);
  strcpy(($$).type,"float");
  // sz = getsz(string((char*)(($$).type)));
sz = 8;
}
|BooleanLiteral  {
  strcpy(($$).tempvar,($1).str);
  strcpy(($$).type,"boolean");
  // sz = getsz(string((char*)(($$).type)));
sz = 8;
}
|CharacterLiteral  {
  strcpy(($$).tempvar,($1).str);
  strcpy(($$).type,"char");
  // sz = getsz(string((char*)(($$).type)));
sz = 8;
}
|StringLiteral  {
  strcpy(($$).tempvar,($1).str);
  strcpy(($$).type,"string");
  sz = string((char*)(($1).str)).length();
}
|NullLiteral  {
  strcpy(($$).tempvar,($1).str);
  strcpy(($$).type,"null");
};

Type:
PrimitiveType  {
  strcpy(($$).tempvar,($1).tempvar);

  ($$).sz = ($1).sz;
  strcpy(($$).type,($1).type);
  type = ($1).type;
  sz = ($1).sz;
}
|ReferenceType {
  strcpy(($$).tempvar,($1).tempvar);

  ($$).sz = ($1).sz;
  strcpy(($$).type,($1).type);
  type = ($1).type;
  sz = ($1).sz;
  // cout<<"RRS"<<($1).type;
  if(curr_table->lookup(string((char*)($1).type)).offset == -1 && checkobj(string((char*)($1).type)) == 0){
      string s=($1).type;
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
      cout<<"Undeclared variable on line "<<($1).type<< yylineno<<"\n";
    }
  }
};

PrimitiveType:
NumericType {
  strcpy(($$).tempvar,($1).tempvar);

  ($$).sz = ($1).sz;
  strcpy(($$).type,($1).type);
}
|BOOLEAN {
  strcpy(($$).tempvar,($1).str);
  
  ($$).sz = 1;
  strcpy(($$).type, "boolean");
};
NumericType:
IntegralType {
  strcpy(($$).tempvar,($1).tempvar);

  ($$).sz = ($1).sz;
  strcpy(($$).type,($1).type);
}
|FloatingPointType {
  strcpy(($$).tempvar,($1).tempvar);

  ($$).sz = ($1).sz;
  strcpy(($$).type,($1).type);
};
IntegralType:
BYTE {
  strcpy(($$).tempvar,($1).str);

  ($$).sz = 8;
  strcpy(($$).type, "byte"); 
}
|SHORT  {
  strcpy(($$).tempvar,($1).str);

  ($$).sz = 8;
  strcpy(($$).type, "short");
}
|INT  {
  strcpy(($$).tempvar,($1).str);

  ($$).sz = 8;
  strcpy(($$).type, "int");
}
|LONG {
  strcpy(($$).tempvar,($1).str);

  ($$).sz = 8;
  strcpy(($$).type, "long");
}
|CHAR {
  strcpy(($$).tempvar,($1).str);

  ($$).sz = 8;
  strcpy(($$).type, "char");
};

FloatingPointType: 
FLOAT {
  strcpy(($$).tempvar,($1).str);

  ($$).sz = 8;
  strcpy(($$).type, "float");
}
|DOUBLE {
  strcpy(($$).tempvar,($1).str);

  ($$).sz = 8;
  strcpy(($$).type, "double");
};
ReferenceType:
ClassOrInterfaceType {
  strcpy(($$).tempvar,($1).tempvar);

  strcpy(($$).type, ($1).type);
  ($$).sz = ($1).sz;
}
|ArrayType {
  strcpy(($$).tempvar,($1).tempvar);

  strcpy(($$).type, ($1).type);
  ($$).sz = ($1).sz;
};
ClassOrInterfaceType:
Name {
  strcpy(($$).tempvar,($1).tempvar);

  strcpy(($$).type, ($1).type);
  ($$).sz = PTR_SZ;
};
ClassType:
ClassOrInterfaceType {
  strcpy(($$).tempvar,($1).tempvar);

  strcpy(($$).type, ($1).type);
  ($$).sz = ($1).sz;
};
InterfaceType:
ClassOrInterfaceType {
  strcpy(($$).tempvar,($1).tempvar);

  strcpy(($$).type, ($1).type);
  ($$).sz = ($1).sz;
};
ArrayType:
PrimitiveType OPENSQUAREBRACKET CLOSESQUAREBRACKET {

  strcpy(($$).type,strcat(($1).type,"[]"));
  strcpy(($$).arrtype, ($1).type);
  ($$).ndim = 1;
  ($$).sz = ($1).sz*($$).ndim;
}
|Name OPENSQUAREBRACKET CLOSESQUAREBRACKET {
  strcpy(($$).type,strcat(($1).type,"[]"));
  strcpy(($$).arrtype, ($1).type);
  ($$).ndim =1;
  ($$).sz = ($1).sz*($$).ndim;
}
|ArrayType OPENSQUAREBRACKET CLOSESQUAREBRACKET {
  strcpy(($$).type,strcat(($1).type,"[]"));
  strcpy(($$).arrtype, ($1).type);
  ($$).ndim = ($1).ndim+1;
  ($$).sz = ($1).sz*($$).ndim;
};
Name:
SimpleName {
   strcpy(($$).tempvar, ($1).tempvar);

   strcpy(($$).type, ($1).type);
   ($$).sz = ($1).sz;
}
|QualifiedName {
  strcpy(($$).tempvar,($1).tempvar);

  strcpy(($$).type, ($1).type);
  ($$).sz = ($1).sz;
};
SimpleName:
Identifier {
  // cout<<($1).str<<" scope: "<<curr_table->lookup(string((char*)($1).str)).scope_name.substr(0,6)<<'\n';
  // cout<<"KKL"<<curr_scope.substr(0,6).c_str()<<" "<<curr_scope.substr(6,curr_scope.size()-6).c_str()<<'\n';
  if(!strcmp(($1).str,"System")) issystem=1;
  if(curr_table->lookup(string((char*)($1).str)).offset==-1)
  {
    if(strcmp(($1).str,"String"))
    {
      if(!isimport&&!issystem) cout<<"Undeclared variable "<<($1).str<<" on line "<<yylineno<<'\n';
      // else isimport=0;
    }
  }
  else
  {
    if(strcmp(curr_table->lookup(string((char*)($1).str)).scope_name.substr(0,6).c_str(),"Method"))
    {
      if(!strcmp(curr_scope.substr(0,6).c_str(),"Method")&&curr_table->lookup(curr_scope.substr(6,curr_scope.size()-6).c_str()).isitstatic)
      {
        if(curr_table->lookup(string((char*)($1).str)).isitstatic==0)
        {
          if(strcmp(curr_table->lookup(string((char*)($1).str)).token.c_str(),"Class")) cout<<"Cannot access non static variable "<<($1).str<<" in static function on line "<<yylineno<<'\n';
        }
      }
    }
    if(!strcmp(curr_table->lookup(string((char*)($1).str)).token.c_str(),"Class"))
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
  strcpy(($$).tempvar, ($1).str);
  strcpy(($$).type, ($1).str);
  // ($$).sz = (string((char*)($1).str)).size();
  ($$).sz = 8;
};

QualifiedName:
Name DOT Identifier {
    // cout<<"LJO"<<(char*)($1).type<<'\n';
    string mo=curr_table->lookup(string((char*)($1).type)).type;
    string s = string((char*)($1).type) + "." + string((char*)($3).str);
    string s1 = mo + "." + string((char*)($3).str);
    // cout<<"I was here"<<s1<<endl;
    // string tv8 = newtemp();
    // emit("=", "symtable.lookup(" + s + ")","null" , tv8, -1);
    // strcpy(($$).tempvar, tv8.c_str());
    strcpy(($$).tempvar, s.c_str());
    isaccess=1;
    fullname=s;
    classname=mo;
    // auto it = checkobjentry(s, 1, mo);
    // cout<<"AAA\n";
    // cout<<"LJKK"<<checkobj(s1)<<endl;
    if(checkobj(s1)){
      strcpy(($$).type, (typeobj(s)).c_str());
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
    ($$).sz = 8;
    // cout<<"GGG"<<($$).type<<'\n';
};
CompilationUnit:
PackageDeclaration ImportDeclarations {
}
|ImportDeclarations {
}
|PackageDeclaration TypeDeclarations {
}
|TypeDeclarations {
}
|PackageDeclaration ImportDeclarations TypeDeclarations {
}
|ImportDeclarations TypeDeclarations {
}
|PackageDeclaration { 
}
;
ImportDeclarations:
ImportDeclaration {
  // isimport=0;
}
|ImportDeclarations ImportDeclaration {
  // isimport=0;
}
;
TypeDeclarations:
TypeDeclaration {
}
|TypeDeclarations TypeDeclaration {
}
;
PackageDeclaration:
PACKAGE Name SEMICOLON {isclassaccess=0; issystem=0;isfinal=0;     
};
ImportDeclaration:
SingleTypeImportDeclaration {
}
|TypeImportOnDemandDeclaration {
};

DummyImport: IMPORT {
  isimport = 1;
}

SingleTypeImportDeclaration:
DummyImport Name SEMICOLON {isclassaccess=0;issystem=0;isfinal=0;isimport=0;    
};
TypeImportOnDemandDeclaration:
DummyImport Name DOT STAR SEMICOLON {isclassaccess=0;issystem=0;isfinal=0;isimport=0;    
};
TypeDeclaration:
ClassDeclaration {
  isimport=0;
}
|InterfaceDeclaration {
  isimport=0;
};
|SEMICOLON {isclassaccess=0;issystem=0;isfinal=0;    
};
Modifiers:
Modifier {
}
|Modifiers Modifier {
};
Modifier:
PUBLIC  {
}
|PROTECTED {
} 
|PRIVATE {
  isprivate=1;
  isfieldprivate=1;
}
|STATIC {
  isstatic=1;
}
|ABSTRACT {
} 
|FINAL  { isfinal=1;
}
|NATIVE  {
}
|SYNCHRONIZED  {
}
|TRANSIENT  {
}
|VOLATILE {
};

ClassDeclaration:
CLASS Identifier Super Interfaces {
  emit(($2).str,":","","",-1);
  emit("BeginClass","","","",-1);
  // code.push_back("Begin" + string((char*)($2).str));
  curr_table->entry(string((char*)($2).str),"Class", string((char*)($2).str), offset, curr_scope, yylineno, -1);
  tables.push(curr_table);
  curr_table = new Sym_Table(curr_table);
  list_of_Symbol_Tables.push_back(curr_table);
  scope_names.push(curr_scope);
  string new_scope = "Class" + string((char*)($2).str);
  curr_scope = new_scope;
  curr_class=new_scope;
  offsets.push(offset);
  int new_offset = 0;
  offset = new_offset; 
}
ClassBody {
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
|Modifiers CLASS Identifier Interfaces {
  emit(($3).str,":","","",-1);
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
  curr_table->entry(string((char*)($3).str),"Class", string((char*)($3).str), offset, curr_scope, yylineno, -1);
  tables.push(curr_table);
  curr_table = new Sym_Table(curr_table);
  list_of_Symbol_Tables.push_back(curr_table);
  scope_names.push(curr_scope);
  string new_scope = "Class" + string((char*)($3).str);
  curr_scope = new_scope;
  curr_class=new_scope;
  offsets.push(offset);
  int new_offset = 0;
  offset = new_offset; 
  isprivate=0;
  isfieldprivate=0;
}
ClassBody {
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
|Modifiers CLASS Identifier Super {
  emit(($3).str,":","","",-1);
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
  curr_table->entry(string((char*)($3).str),"Class", string((char*)($3).str), offset, curr_scope, yylineno, -1);
  tables.push(curr_table);
  curr_table = new Sym_Table(curr_table);
  list_of_Symbol_Tables.push_back(curr_table);
  scope_names.push(curr_scope);
  string new_scope = "Class" + string((char*)($3).str);
  curr_scope = new_scope;
  curr_class=new_scope;
  offsets.push(offset);
  int new_offset = 0;
  offset = new_offset;
  isfieldprivate=0;
}
ClassBody {
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
|CLASS Identifier Interfaces {
  // code.push_back("Begin" + string((char*)($2).str));
  emit(($2).str,":","","",-1);
  emit("BeginClass","","","",-1);
  curr_table->entry(string((char*)($2).str),"Class", string((char*)($2).str), offset, curr_scope, yylineno, -1);
  tables.push(curr_table);
  curr_table = new Sym_Table(curr_table);
  list_of_Symbol_Tables.push_back(curr_table);
  scope_names.push(curr_scope);
  string new_scope = "Class" + string((char*)($2).str);
  curr_scope = new_scope;
  curr_class=new_scope;
  offsets.push(offset);
  int new_offset = 0;
  offset = new_offset;
} 
ClassBody {
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
|CLASS Identifier Super {
  // code.push_back("Begin" + string((char*)($2).str));
  emit(($2).str,":","","",-1);
  emit("BeginClass","","","",-1);
  curr_table->entry(string((char*)($2).str),"Class", string((char*)($2).str), offset, curr_scope, yylineno, -1);
  tables.push(curr_table);
  curr_table = new Sym_Table(curr_table);
  list_of_Symbol_Tables.push_back(curr_table);
  scope_names.push(curr_scope);
  string new_scope = "Class" + string((char*)($2).str);
  curr_scope = new_scope;
  curr_class=new_scope;
  offsets.push(offset);
  int new_offset = 0;
  offset = new_offset;
}
ClassBody {
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
|Modifiers CLASS Identifier {
  emit(($3).str,":","","",-1);
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

  curr_table->entry(string((char*)($3).str),"Class", string((char*)($3).str), offset, curr_scope, yylineno, -1);
  tables.push(curr_table);
  curr_table = new Sym_Table(curr_table);
  list_of_Symbol_Tables.push_back(curr_table);
  scope_names.push(curr_scope);
  string new_scope = "Class" + string((char*)($3).str);
  curr_scope = new_scope;
  curr_class=new_scope;
  offsets.push(offset);
  int new_offset = 0;
  offset = new_offset;
  isfieldprivate=0;
} 
ClassBody {
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
|CLASS Identifier {
  // code.push_back("Begin" + string((char*)($2).str));
  emit(($2).str,":","","",-1);
  emit("BeginClass","","","",-1);
  curr_table->entry(string((char*)($2).str),"Class", string((char*)($2).str), offset, curr_scope, yylineno, -1);
  tables.push(curr_table);
  curr_table = new Sym_Table(curr_table);
  list_of_Symbol_Tables.push_back(curr_table);
  scope_names.push(curr_scope);
  string new_scope = "Class" + string((char*)($2).str);
  curr_scope = new_scope;
  curr_class=new_scope;
  offsets.push(offset);
  int new_offset = 0;
  offset = new_offset;
}
ClassBody {
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
|Modifiers CLASS Identifier Super Interfaces {
  emit(($3).str,":","","",-1);
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

  curr_table->entry(string((char*)($3).str),"Class", string((char*)($3).str), offset, curr_scope, yylineno, -1);
  tables.push(curr_table);
  curr_table = new Sym_Table(curr_table);
  list_of_Symbol_Tables.push_back(curr_table);
  scope_names.push(curr_scope);
  string new_scope = "Class" + string((char*)($3).str);
  curr_scope = new_scope;
  curr_class=new_scope;
  offsets.push(offset);
  int new_offset = 0;
  offset = new_offset;
  isfieldprivate=0;
}
ClassBody {
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
};
Super:
EXTENDS ClassType {
  
  
  
};
Interfaces:
IMPLEMENTS InterfaceTypeList {
  
  
  
};
InterfaceTypeList:
InterfaceType {
  
  
}
|InterfaceTypeList COMMA InterfaceType {
  
  
  
  
};
ClassBody:
OPENCURLYBRACKET ClassBodyDeclarations CLOSECURLYBRACKET {
  isprivate=0;
  fieldcount=0;
}
|OPENCURLYBRACKET CLOSECURLYBRACKET {
  isprivate=0;
  fieldcount=0;
};
ClassBodyDeclarations:
ClassBodyDeclaration {
  
  
}
|ClassBodyDeclarations ClassBodyDeclaration {
  
  
  
};
ClassBodyDeclaration:
ClassMemberDeclaration {
  
  
}
|StaticInitializer {
  isstatic=0;
}
|ConstructorDeclaration {
  
  
};
ClassMemberDeclaration:
FieldDeclaration {
  fielddeclist="";
  // fielddeclistlast+=fielddeclist;
  fieldcount=lastfieldcount;
  
}
|MethodDeclaration {
  fielddeclist="";
  // fielddeclistlast+=fielddeclist;
  fieldcount=lastfieldcount;
  
};
FieldDeclaration:
Modifiers Type VariableDeclarators SEMICOLON { 
  // fielddeclist+="#";
  fielddeclistlast+=fielddeclist;
  lastfieldcount=fieldcount;
  fielddeclist="";
  // fieldcount=0;
  newdim.clear();   
  isfinal=0;
  isclassaccess=0;
  issystem=0;
  if(strcmp(($3).type,"Dishay"))
  {
    if(strcmp(($2).type,($3).type))
    {
      cout<<($2).type<<" "<<($3).type<<" "<<"Invalid operator on line "<< yylineno<<"\n";
    }
    else
    {
      strcpy(($$).type,($2).type);
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
|Type VariableDeclarators SEMICOLON { 
  // fielddeclist+="#";
  fielddeclistlast+=fielddeclist;
  lastfieldcount=fieldcount;
  fielddeclist="";  
  // fieldcount=0;
  newdim.clear(); 
  strcpy(($$).tempvar, ($1).tempvar);
  isclassaccess=0;
issystem=0;
  if(strcmp(($2).type,"Dishay"))
  {
    if(strcmp(($1).type,($2).type))
    {
      cout<<($1).type<<" "<<($2).type<<" "<<"Invalid operator on line "<< yylineno<<"\n";
    }
    else
    {
      strcpy(($$).type,($1).type);
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
  
  
  
};
VariableDeclarators:
VariableDeclarator {
  strcpy(($$).tempvar, ($1).tempvar);
  string s="";
  if(strcmp(type.c_str(),"")) s=type;
  else s=($1).type;
  string yo="";
  for(int i=0;i<(int)s.size();i++)
  {
    if(s[i]=='[')
    {
      break;
    }
    yo+=string(1,s[i]);
  }
  strcpy(($$).tempvar, ($1).tempvar);
  strcpy(($$).type,($1).type);
  if(!boolgetorder(yo.c_str(),($1).type,1))
  {
    if(strcmp(yo.c_str(),($1).type))
    {
      if(!strcmp(yo.c_str(),"String")&&!strcmp(($1).type,"string"))
      {
        
      }
      else if(strcmp(($1).type,"Dishay"))cout<<"Invalid variable declaration between "<<yo<<" and "<<($1).type<<" on line "<<yylineno<<'\n';
    }
  }
  type=yo;
  // cout<<"SSS"<<($1).type<<'\n';

  strcpy(($$).type,yo.c_str());
}
|VariableDeclarators COMMA VariableDeclarator {
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
  if(strcmp(($1).type,"Dishay") && strcmp(($3).type,"Dishay"))
  {
      // cout<<"1"<<($1).type<<($3).type<<"\n";
      string s=($1).type;
      string yo="";
      for(int i=0;i<(int)s.size();i++)
      {
        if(s[i]=='[')
        {
          break;
        }
        yo+=string(1,s[i]);
      }
      string s1=($3).type;
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
      strcpy(($$).type,getorder(yo.c_str(),yo1.c_str(),1).c_str());
  }
  else if(!strcmp(($1).type,"Dishay") && strcmp(($3).type,"Dishay"))
  {
    // cout<<"2\n";
      string s=($3).type;
      string yo="";
      for(int i=0;i<(int)s.size();i++)
      {
        if(s[i]=='[')
        {
          break;
        }
        yo+=string(1,s[i]);
      }
      strcpy(($$).type,yo.c_str());
  }
  else if(strcmp(($1).type,"Dishay") && !strcmp(($3).type,"Dishay"))
  {
    // cout<<"3\n";
      string s=($1).type;
      string yo="";
      for(int i=0;i<(int)s.size();i++)
      {
        if(s[i]=='[')
        {
          break;
        }
        yo+=string(1,s[i]);
      }
      strcpy(($$).type,yo.c_str());
  }
  else
  {
    // cout<<"4\n";
    strcpy(($$).type,"Dishay");
  }
  // cout<<($3).type<<'\n';
};
VariableDeclarator:
VariableDeclaratorId {
  strcpy(($$).tempvar,($1).tempvar);
  strcpy(($$).type,"Dishay");
//   curr_table->entry(string((char*)($1).type), "Identifier", type, offset, curr_scope, yylineno, -1);
//   offset += sz;
curr_table->classwidth = offset;

  funcparam.push_back({string((char*)($1).type), {type, -1}});
  sizeparam.push_back(sz);
  tempparam.push_back(string((char*)(($1).tempvar)));
//   cout<< "VariableDeclaratorId " << string((char*)($1).type) << " " << type << " " << offset << " " << curr_scope << " " << yylineno << "\n";
  string s=curr_table->lookup(string((char*)($1).type)).type;
  // cout<<"LKS"<<s<<'\n';
  if(strcmp(s.c_str(),"null"))
  {
    if(!strcmp(curr_table->lookup(string((char*)($1).type)).scope_name.c_str(),curr_scope.c_str()))
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
      strcpy(($$).type,type.c_str());
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
    strcpy(($$).type,yo.c_str());
  }
  ndim=0;
  // cout<<"SSS"<<s<<'\n';
  
}

|VariableDeclaratorId EQUAL VariableInitializer {  
  // cout<<"I was here"<<($1).type<<endl;
//   curr_table->entry(string((char*)($1).type), "Identifier", type, offset, curr_scope, yylineno, -1);
//   offset += sz;
// cout<<($1).tempvar<<" "<<($3).tempvar<<endl;
curr_table->classwidth = offset;
 string tv5 = string((char*)(($3).type));
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
    auto it = curr_table->lookup(string((char*)(($1).type))).dims;
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
    strcpy(($$).tempvar, tv2.c_str());
    objtotemp[string((char*)(($1).type))] = tv2;
 }
  else{
  strcpy(($$).tempvar, ($3).tempvar);
  // cout<<($1).tempvar<<" "<<($3).tempvar<<endl;
  if(vartottemp[string((char*)(($1).type))] != ""){
    objtotemp[vartottemp[string((char*)(($1).type))]] = string((char*)(($3).tempvar));
  }
  else{
    objtotemp[string((char*)(($1).type))] = string((char*)(($3).tempvar));
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

  if(ndim!=($3).ndim)
  {
    cout<<"Invalid assignment: Array dimensions "<<ndim<<" and "<<($3).ndim<<" don't match in line "<<yylineno<<'\n';
    ndim=0;
  }
  else ndim=0;
  funcparam.push_back({string((char*)($1).type), {type, -2}});
  sizeparam.push_back(sz);
  // cout<<($1).type<<" "<<sz<<endl;
  tempparam.push_back(string((char*)(($$).tempvar)));

  if(curr_table->lookup(string((char*)($1).type)).offset != -1)
  {
    if(curr_table->lookup(string((char*)($3).type)).offset == -1)
    {
  
      if(!boolgetorder(curr_table->lookup(string((char*)($1).type)).type.c_str(),($3).type,1)&&!strcmp(curr_table->lookup(string((char*)($1).type)).scope_name.c_str(),curr_scope.c_str()))
      {
        cout<<curr_table->lookup(string((char*)($1).type)).type<<" "<<($3).type<<" "<<"Invalid VariableDeclarator on line "<< yylineno<<"\n";
      }
      else
      {
        strcpy(($$).type,($3).type);
      }
    }
    else
    {
      if(!boolgetorder(curr_table->lookup(string((char*)($1).type)).type.c_str(),curr_table->lookup(string((char*)($3).type)).type.c_str(),1))
      {
        if(strcmp(curr_table->lookup(string((char*)($1).type)).type.c_str(),curr_table->lookup(string((char*)($3).type)).type.c_str()))
        {
          cout<<curr_table->lookup(string((char*)($1).type)).type<<" "<<($3).type<<" "<<"Invalid VariableDeclarator on line "<< yylineno<<"\n";
        }
      }
      else
      {
        strcpy(($$).type,curr_table->lookup(string((char*)($3).type)).type.c_str());
      }
    }
  }
  else
  {
    // cout<<"yo"<<($3).type<<"\n";
    strcpy(($$).type,($3).type);
  }
  string s=($$).type;
  string yo="";
  for(int i=0;i<(int)s.size();i++)
  {
    if(s[i]=='[')
    {
      break;
    }
    yo+=string(1,s[i]);
  }
  strcpy(($$).type,yo.c_str());
  // cout<<"TYO"<<yo<<'\n';
  ndim=0;
  if(checkclass(($3).type)){
    objects.push_back(string((char*)($1).type));
  }
  // cout<<"GGG"<<($$).type<<'\n';
};
VariableDeclaratorId:
Identifier {
  curridf = string((char*)(($1).str));
  strcpy(($$).tempvar, ($1).str);

  strcpy(($$).type,($1).str);
  ndim=0;
}
|VariableDeclaratorId {
  type  = type + "[]";
  ndim=ndim+1;
  // type = "Array";
} OPENSQUAREBRACKET CLOSESQUAREBRACKET {
  
  // ($$).ndim=ndim;
};

VariableInitializer:
Expression {
  strcpy(($$).tempvar, ($1).tempvar);

  strcpy(($$).type,($1).type);
  if(!flagyo) ($$).ndim=0;
  else ($$).ndim=($1).ndim;
  // cout<<"YO"<<($$).ndim<<'\n';

}
|ArrayInitializer {
  strcpy(($$).tempvar, ($1).tempvar);

  strcpy(($$).type,($1).type);
  ($$).ndim=($1).ndim;
};

MethodDeclaration:
MethodHeader MethodBody {
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
|MethodBody {
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

};


MethodHeader:
Modifiers Type MethodDeclarator Throws {
// emit("BeginFunc","","","",-1);
// emit("push","rbp","","",-1);
// emit("=", "rsp", "null", "rbp", -1);
  currfunc.push(string((char*)(($3).type)));
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
  functype=($2).type;
  infunction=1;
  nelem=($3).nelem;
  // cout<<"FFF"<<isstatic<<'\n';
  curr_table->entry(string((char*)($3).type), "Method", string((char*)($2).type), offset, curr_scope, yylineno, -1);
  tables.push(curr_table);
  curr_table = new Sym_Table(curr_table);
  list_of_Symbol_Tables.push_back(curr_table);
  scope_names.push(curr_scope);
  string new_scope = "Method" + string((char*)($3).type);
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
|Modifiers Type MethodDeclarator  { 
  currfunc.push(string((char*)(($3).type)));
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
  functype=($2).type;
  infunction=1;
  nelem=($3).nelem;
  // cout<<"FFF"<<isstatic<<'\n';
  curr_table->entry(string((char*)($3).type), "Method", string((char*)($2).type), offset, curr_scope, yylineno, -1);
  tables.push(curr_table);
  curr_table = new Sym_Table(curr_table);
  list_of_Symbol_Tables.push_back(curr_table);
  scope_names.push(curr_scope);
  string new_scope = "Method" + string((char*)($3).type);
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
|Type MethodDeclarator Throws {
  currfunc.push(string((char*)(($2).type)));
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
  functype=($1).type;
  infunction=1;
  nelem=($2).nelem;
  curr_table->entry(string((char*)($2).type), "Method", string((char*)($1).type), offset, curr_scope, yylineno, -1);
  tables.push(curr_table);
  curr_table = new Sym_Table(curr_table);
  list_of_Symbol_Tables.push_back(curr_table);
  scope_names.push(curr_scope);
  string new_scope = "Method" + string((char*)($2).type);
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
|Type MethodDeclarator {
  currfunc.push(string((char*)(($2).type)));
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
  functype=($1).type;
  infunction=1;
  nelem=($2).nelem;
  curr_table->entry(string((char*)($2).type), "Method", string((char*)($1).type), offset, curr_scope, yylineno, -1);
  tables.push(curr_table);
  curr_table = new Sym_Table(curr_table);
  list_of_Symbol_Tables.push_back(curr_table);
  scope_names.push(curr_scope);
  string new_scope = "Method" + string((char*)($2).type);
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
|Modifiers VOID MethodDeclarator Throws {
  currfunc.push(string((char*)(($3).type)));
  functype="void";
  infunction=1;
  nelem=($3).nelem;
  if(ismainstatic&&!isstatic)
  {
    cout<<"Main function should be satic\n";
  }
  ismainstatic=0;
  isvoid=0;
  // cout<<"FFF"<<isstatic<<'\n';
  curr_table->entry(string((char*)($3).type), "Method", string((char*)($2).str), offset, curr_scope, yylineno, -1);
  tables.push(curr_table);
  curr_table = new Sym_Table(curr_table);
  list_of_Symbol_Tables.push_back(curr_table);
  scope_names.push(curr_scope);
  string new_scope = "Method" + string((char*)($3).type);
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
|VOID MethodDeclarator Throws {
  currfunc.push(string((char*)(($2).type)));
  if(ismainstatic&&!isstatic)
  {
    cout<<"Main function should be satic\n";
  }
  ismainstatic=0;
  isvoid=0;
  ismainstatic=0;
  functype="void";
  infunction=1;
  nelem=($2).nelem;
  curr_table->entry(string((char*)($2).type), "Method", string((char*)($1).str), offset, curr_scope, yylineno, -1);
  tables.push(curr_table);
  curr_table = new Sym_Table(curr_table);
  list_of_Symbol_Tables.push_back(curr_table);
  scope_names.push(curr_scope);
  string new_scope = "Method" + string((char*)($2).type);
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
|Modifiers VOID MethodDeclarator  {
  currfunc.push(string((char*)(($3).type)));
  if(ismainstatic&&!isstatic)
  {
    cout<<"Main function should be satic\n";
  }
  ismainstatic=0;
  isvoid=0;

  functype="void";
  infunction=1;
  nelem=($3).nelem;
  // cout<<"FFF"<<isstatic<<'\n';
  curr_table->entry(string((char*)($3).type), "Method", string((char*)($2).str), offset, curr_scope, yylineno, -1);
  tables.push(curr_table);
  curr_table = new Sym_Table(curr_table);
  list_of_Symbol_Tables.push_back(curr_table);
  scope_names.push(curr_scope);
  string new_scope = "Method" + string((char*)($3).type);
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
|VOID MethodDeclarator {
  currfunc.push(string((char*)(($2).type)));
  if(ismainstatic&&!isstatic)
  {
    cout<<"Main function should be satic\n";
  }
  ismainstatic=0;
  isvoid=0;

  functype="void";
  infunction=1;
  nelem=($2).nelem;
  curr_table->entry(string((char*)($2).type), "Method", string((char*)($1).str), offset, curr_scope, yylineno, -1);
  tables.push(curr_table);
  curr_table = new Sym_Table(curr_table);
  list_of_Symbol_Tables.push_back(curr_table);
  scope_names.push(curr_scope);
  string new_scope = "Method" + string((char*)($2).type);
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
};

MethodDeclarator:
Identifier OPENBRACKET CLOSEBRACKET {
  emit(($1).str,":","","",-1);
  emit("BeginFunc","","","",-1);
  //emit("BeginFunc",to_string(getfuncwidth(string((char*)($1).type))),"","",-1);
  emit("push","rbp","","",-1);
  emit("=", "rsp", "null", "rbp", -1);
  strcpy(($$).type,($1).str);
  ($$).nelem=0;
  if(!strcmp(($1).str,"main"))
  {
    ismainstatic=1;
    isvoid=1;
  }
  curr_func = string((char*)($1).str);
}
|Identifier OPENBRACKET FormalParameterList CLOSEBRACKET {
  emit(($1).str,":","","",-1);

  emit("BeginFunc","","","",-1);
  emit("push","rbp","","",-1);
  emit("=", "rsp", "null", "rbp", -1);

  strcpy(($$).type,($1).str);
  ($$).nelem=($3).nelem;
  if(!strcmp(($1).str,"main"))
  {
    ismainstatic=1;
    isvoid=1;
  }
  curr_func = string((char*)($1).str);
}
|MethodDeclarator OPENSQUAREBRACKET CLOSESQUAREBRACKET {

};
FormalParameterList:
FormalParameter {
  ($$).nelem=1;
}
|FormalParameterList COMMA FormalParameter {
  ($$).nelem=($1).nelem+1;
};
FormalParameter:
Type VariableDeclaratorId {
  strcpy(($$).tempvar,($2).tempvar);
  ($$).ndim=ndim;
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
  funcparam.push_back({string((char*)($2).type), {type, funcargno}});
  sizeparam.push_back(sz);
  tempparam.push_back(string((char*)(($2).tempvar)));
};
Throws:
THROWS ClassTypeList {
};
ClassTypeList:
ClassType  {
}
|ClassTypeList COMMA ClassType {
};

MethodBody:
Block  {
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
|SEMICOLON {   
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
};
StaticInitializer:
STATIC {isstatic=1;} Block {
  // cout<<"YIS"<<isstatic<<'\n';
};
ConstructorDeclaration:
Modifiers ConstructorDeclarator Throws ConstructorBody {
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  offset = offsets.top(); offsets.pop();
  isfieldprivate=0;
  nelem=0;
  
}
|Modifiers ConstructorDeclarator ConstructorBody {
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  offset = offsets.top(); offsets.pop();
  isfieldprivate=0;
  nelem=0;
  
}
|ConstructorDeclarator Throws ConstructorBody {
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  offset = offsets.top(); offsets.pop();
  nelem=0;
  
}
|ConstructorDeclarator ConstructorBody {
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  offset = offsets.top(); offsets.pop();
  nelem=0;
  
}

ConstructorHeader: SimpleName OPENBRACKET{
  emit("BeginCtor","","","",-1);
  curr_func = string((char*)(($1).type));
}

ConstructorDeclarator:
ConstructorHeader FormalParameterList CLOSEBRACKET {
  emit("push","rbp","","",-1);
  emit("=", "rsp", "null", "rbp", -1);
  nelem=($2).nelem;
  // cout<<"YO "<<constpass<<endl;
 
  // auto& it = curr_table->lookup(constpass);
  // cout<<it.token<<endl;
  // it.narg = nelem;

  curr_table->entry(string((char*)(($1).type)), "Constructor", string((char*)(($1).type)), offset, curr_scope, yylineno, -1);
  tables.push(curr_table);
  curr_table = new Sym_Table(curr_table);
  list_of_Symbol_Tables.push_back(curr_table);
  scope_names.push(curr_scope);
  string new_scope = "Constructor" + string((char*)(($1).type));
  curr_scope = new_scope;
  // cout<<"cscope "<< curr_scope<<'\n';
  offsets.push(offset);
  int new_offset = 0;
  offset = new_offset;
  constpass = string((char*)(($1).type));

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
      // // emit("sub","rsp",to_string(sizeparam[i]),"",-1);
      totalstack += sizeparam[i];
      emit("=", "[rbp+" + to_string(offset + 16) + "]", "null", tempparam[i], -1);
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
|SimpleName OPENBRACKET {
  emit("BeginCtor","","","",-1);
  emit("push","rbp","","",-1);
  emit("=", "rsp", "null", "rbp", -1);
  nelem=0;
  curr_table->entry(string((char*)(($1).type)), "Constructor", string((char*)(($1).type)), offset, curr_scope, yylineno, -1);
  tables.push(curr_table);
  curr_table = new Sym_Table(curr_table);
  list_of_Symbol_Tables.push_back(curr_table);
  scope_names.push(curr_scope);
  string new_scope = "Constructor" + string((char*)(($1).type));
  curr_scope = new_scope;
  offsets.push(offset);
  int new_offset = 0;
  offset = new_offset;
}
CLOSEBRACKET {
  
  
  
  
};

ConstructorBody:
OPENCURLYBRACKET ExplicitConstructorInvocation BlockStatements CLOSECURLYBRACKET {
  
  if(ispopped == 1){
    if(totalstack != 0){ ;}
emit("pop","rbp","","",-1);
    ispopped = 0;totalstack = 0;
emit("ret","","","",-1);
  }
  emit("EndCtor","","","",-1);
  ispopped = 1;
  
  
  
  
}
|OPENCURLYBRACKET BlockStatements CLOSECURLYBRACKET {
  
  if(ispopped == 1){
    if(totalstack != 0){ emit("add", "rsp", to_string(totalstack), "", -1); ;}
emit("pop","rbp","","",-1);
    ispopped = 0;totalstack = 0;
emit("ret","","","",-1);
  }
  emit("EndCtor","","","",-1);
  ispopped = 1;
  
  
}
|OPENCURLYBRACKET ExplicitConstructorInvocation CLOSECURLYBRACKET {
  
  if(ispopped == 1){
    if(totalstack != 0){ emit("add", "rsp", to_string(totalstack), "", -1); ;}
emit("pop","rbp","","",-1);
    ispopped = 0;totalstack = 0;
emit("ret","","","",-1);
  }
  emit("EndCtor","","","",-1);
  ispopped = 1;
  
}
|OPENCURLYBRACKET CLOSECURLYBRACKET {
  
  if(ispopped == 1){
    if(totalstack != 0){ emit("add", "rsp", to_string(totalstack), "", -1); ;}
emit("pop","rbp","","",-1);
    ispopped = 0;totalstack = 0;
emit("ret","","","",-1);
  }
  emit("EndCtor","","","",-1);
  ispopped = 1;
};
ExplicitConstructorInvocation:
THIS OPENBRACKET ArgumentList CLOSEBRACKET SEMICOLON {    
  newdim.clear();
  isclassaccess=0;
  isfinal=0;
  issystem=0;
  
  
  
  
}
|THIS OPENBRACKET CLOSEBRACKET SEMICOLON {    
  isclassaccess=0;
  newdim.clear();
  isfinal=0;
  issystem=0;
  
  
}
|SUPER OPENBRACKET ArgumentList CLOSEBRACKET SEMICOLON {    
    isclassaccess=0;
  issystem=0;
  newdim.clear();
  
  isfinal=0;
  
}
|SUPER OPENBRACKET CLOSEBRACKET SEMICOLON {    
    isclassaccess=0;
  issystem=0;
  newdim.clear();
  isfinal=0;
  
};
InterfaceDeclaration:
Modifiers INTERFACE Identifier ExtendsInterfaces {
  curr_table->entry(string((char*)($3).str), "Identifier", "Interface", offset, curr_scope, yylineno, -1);
  tables.push(curr_table);
  curr_table = new Sym_Table(curr_table);
  list_of_Symbol_Tables.push_back(curr_table);
  scope_names.push(curr_scope);
  string new_scope = "Interface" + string((char*)($3).str);
  curr_scope = new_scope;
  offsets.push(offset);
  int new_offset = 0;
  offset = new_offset;
  isfieldprivate=0;
}
InterfaceBody {
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  offset = offsets.top(); offsets.pop();
  
  
  
  
  
  
}
|INTERFACE Identifier ExtendsInterfaces {
  curr_table->entry(string((char*)($2).str), "Identifier", "Interface", offset, curr_scope, yylineno, -1);
  tables.push(curr_table);
  curr_table = new Sym_Table(curr_table);
  list_of_Symbol_Tables.push_back(curr_table);
  scope_names.push(curr_scope);
  string new_scope = "Interface" + string((char*)($2).str);
  curr_scope = new_scope;
  offsets.push(offset);
  int new_offset = 0;
  offset = new_offset;
}
InterfaceBody {
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  offset = offsets.top(); offsets.pop();
  
  
  
  
  
}
|Modifiers INTERFACE Identifier {
  curr_table->entry(string((char*)($3).str), "Identifier", "Interface", offset, curr_scope, yylineno, -1);
  tables.push(curr_table);
  curr_table = new Sym_Table(curr_table);
  list_of_Symbol_Tables.push_back(curr_table);
  scope_names.push(curr_scope);
  string new_scope = "Interface" + string((char*)($3).str);
  curr_scope = new_scope;
  offsets.push(offset);
  int new_offset = 0;
  offset = new_offset;
  isfieldprivate=0;
}
InterfaceBody {
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  offset = offsets.top(); offsets.pop();
}
|INTERFACE Identifier {
  curr_table->entry(string((char*)($2).str), "Identifier", "Interface", offset, curr_scope, yylineno, -1);
  tables.push(curr_table);
  curr_table = new Sym_Table(curr_table);
  list_of_Symbol_Tables.push_back(curr_table);
  scope_names.push(curr_scope);
  string new_scope = "Interface" + string((char*)($2).str);
  curr_scope = new_scope;
  offsets.push(offset);
  int new_offset = 0;
  offset = new_offset;
}
InterfaceBody {
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  offset = offsets.top(); offsets.pop();
  
  
  
  
};
ExtendsInterfaces:
EXTENDS InterfaceType {
  
  
  
  }
|ExtendsInterfaces COMMA InterfaceType {
  
  
  
  
  };
InterfaceBody:
OPENCURLYBRACKET CLOSECURLYBRACKET {
  
  
  
  }
|OPENCURLYBRACKET InterfaceMemberDeclarations CLOSECURLYBRACKET {
  
  
  
  
  }
InterfaceMemberDeclarations:
InterfaceMemberDeclaration {
  
  
  }
|InterfaceMemberDeclarations InterfaceMemberDeclaration {
  
  
  
  };
InterfaceMemberDeclaration:
ConstantDeclaration {
  
  
  }
|AbstractMethodDeclaration {
  
  
  };
ConstantDeclaration:
FieldDeclaration {
  
  
  };
AbstractMethodDeclaration:
MethodHeader SEMICOLON {    
  newdim.clear();
  isfinal=0;
  isclassaccess=0;
    issystem=0;
};

ArrayInitializer:
OPENCURLYBRACKET VariableInitializers COMMA CLOSECURLYBRACKET {
  strcpy(($$).tempvar, strcat(($1).str, strcat(($2).tempvar, strcat(($3).str, ($4).str))));
  arrinit=1;
  strcpy(($$).type,($2).type);
  // ($$).nelem=($2).nelem;
  ($$).ndim=($2).ndim+1;
  shape[($$).ndim].push_back(($2).nelem);
  // cout<<($$).ndim<<'\n';
}
|OPENCURLYBRACKET COMMA CLOSECURLYBRACKET {
  strcpy(($$).tempvar, strcat(($1).str, strcat(($2).str, ($3).str)));
  arrinit=1;
  strcpy(($$).type,"Dishay");
  // ($$).nelem=0;
  ($$).ndim=1;
  shape[($$).ndim].push_back(0);
  // cout<<($$).ndim<<'\n';
  
  }
|OPENCURLYBRACKET VariableInitializers CLOSECURLYBRACKET {
  strcpy(($$).tempvar, strcat(($1).str, strcat(($2).tempvar, ($3).str)));
  arrinit=1;
  strcpy(($$).type,($2).type);
  // ($$).nelem=($2).nelem;
  ($$).ndim=($2).ndim+1;
  shape[($$).ndim].push_back(($2).nelem);
  }
|OPENCURLYBRACKET CLOSECURLYBRACKET {
  strcpy(($$).tempvar, strcat(($1).str, ($2).str));
  arrinit=1;
  strcpy(($$).type,"Dishay");
  // ($$).nelem=0;
  ($$).ndim=1;
  shape[($$).ndim].push_back(0);
  // cout<<"OPENCURLYBRACKET CLOSECURLYBRACKET"<<($$).ndim<<'\n';
  
  
  };
VariableInitializers:
VariableInitializer {
  strcpy(($$).tempvar,($1).tempvar);
  strcpy(($$).type,($1).type);
  ($$).ndim=($1).ndim;
  // shape[($1).ndim+1].back()+=1;
  ($$).nelem=1;
  
  }
|VariableInitializers COMMA VariableInitializer {
  strcpy(($$).tempvar, strcat(strcat(($1).tempvar,","),($3).tempvar));
  strcpy(($$).type,getorder(($1).type,($3).type,1).c_str());
  ($$).ndim=($1).ndim;
  // shape[($1).ndim+1].back()+=1;
  ($$).nelem=($1).nelem+1;
  // cout<<"types "<<($1).type<<" "<<($3).type<<" "<<($$).type<<'\n';
  
  };
Block:
OPENCURLYBRACKET BlockStatements CLOSECURLYBRACKET {
  
  
  
  
  }
|OPENCURLYBRACKET CLOSECURLYBRACKET {
  
  
  
  };
BlockStatements:
BlockStatement {
  
  
  }
|BlockStatements BlockStatement {
  
  
  
  };
BlockStatement:
LocalVariableDeclarationStatement {
  
  
  }
|Statement {
  
  
  };
LocalVariableDeclarationStatement:
LocalVariableDeclaration SEMICOLON {    
  newdim.clear();
  isclassaccess=0;
  type="";
    issystem=0;
  }
|FINAL LocalVariableDeclaration SEMICOLON
{    
  newdim.clear();
   isclassaccess=0;
  type="";
    issystem=0;
    isfinal=0;
};

LocalVariableDeclaration:
Type VariableDeclarators {
  // cout<<($1).type<<($2).type<<'\n';
  // cout<<"GHF"<<isstatic<<'\n';
  strcpy(($$).tempvar, ($2).tempvar);
  if(strcmp(($2).type,"Dishay"))
  {
      if(!flagyo)
      {
        if(!boolgetorder(($1).type,($2).type,1))
        { 
          if(strcmp(($1).type,($2).type))
          {
            cout<<($1).type<<" "<<($2).type<<" "<<"Invalid LocalVariableDeclaration operator on line "<< yylineno<<"\n";
          }
          else strcpy(($$).type,($1).type);
        }
        else
        {
          strcpy(($$).type,($1).type);
        }
      }
      else
      {
        if(strcmp(($1).type,($2).type))
        {
          cout<<($1).type<<" "<<($2).type<<" "<<"Invalid LocalVariableDeclaration operator on line "<< yylineno<<"\n";
        }
        else
        {
          strcpy(($$).type,($1).type);
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
  };
Statement:
StatementWithoutTrailingSubstatement {
  
  
  }
|LabeledStatement {
  
  
  }
|IfThenStatement {
  
  
  }
|IfThenElseStatement {
  
  
  }
|WhileStatement {
  
  
  }
|ForStatement {
  
  
  };
StatementNoShortIf:
StatementWithoutTrailingSubstatement {
  
  
  }
|LabeledStatementNoShortIf {
  
  
  }
|IfThenElseStatementNoShortIf {
  
  
  }
|WhileStatementNoShortIf {
  
  
  }
|ForStatementNoShortIf {
  
  
  };
StatementWithoutTrailingSubstatement:
Block {
  
  
  }
|EmptyStatement {
  
  
  }
|ExpressionStatement {
  
  
  }
|SwitchStatement {
  
  
  }
|DoStatement {
  
  
  }
|BreakStatement {
  
  
  }
|ContinueStatement {
  
  
  }
|ReturnStatement {
  
  
  }
|SynchronizedStatement {
  
  
  }
|ThrowStatement {
  
  
  }
|TryStatement {
  
  
  };
EmptyStatement:
SEMICOLON {    
    issystem=0;
  isclassaccess=0;
  isfinal=0;
};
LabeledStatement:
Identifier COLON Statement {
  if(curr_table->lookup(string((char*)($1).str)).offset == -1  && checkobj(string((char*)($1).str)) == 0){
    cout<<"Undeclared variable on line "<< yylineno<<"\n";
  }
};
LabeledStatementNoShortIf:
Identifier COLON StatementNoShortIf {
  if(curr_table->lookup(string((char*)($1).str)).offset == -1 && checkobj(string((char*)($1).str)) == 0){
    cout<<"Undeclared variable on line "<< yylineno<<"\n";
  }
  };
ExpressionStatement:
StatementExpression SEMICOLON {    
  newdim.clear();
  strcpy(($$).type,($1).type);
  strcpy(($$).tempvar, ($1).tempvar);
    issystem=0;
  isclassaccess=0;
  isfinal=0;
  };
StatementExpression:
Assignment {
  strcpy(($$).type,($1).type);
  strcpy(($$).tempvar, ($1).tempvar);
  
  
  }
|PreIncrementExpression {
  strcpy(($$).type,($1).type);
  strcpy(($$).tempvar, ($1).tempvar);
  
  
  }
|PreDecrementExpression {
  strcpy(($$).type,($1).type);
  strcpy(($$).tempvar, ($1).tempvar);
  
  
  }
|PostIncrementExpression {
  
  strcpy(($$).type,($1).type);
  strcpy(($$).tempvar, ($1).tempvar);
  
  }
|PostDecrementExpression {
  strcpy(($$).type,($1).type);
  strcpy(($$).tempvar, ($1).tempvar);
  
  
  }
|MethodInvocation {
  strcpy(($$).type,($1).type);
  strcpy(($$).tempvar, ($1).tempvar);
  

  
  }
|ClassInstanceCreationExpression {
  strcpy(($$).type,($1).type);
  strcpy(($$).tempvar, ($1).tempvar);
  
  
  };
DummyIfStatement: IF OPENBRACKET {

  tables.push(curr_table);
  curr_table = new Sym_Table(curr_table);
  list_of_Symbol_Tables.push_back(curr_table);
  scope_names.push(curr_scope);
  string new_scope = "IfStatement";
  curr_scope = new_scope;
  // offsets.push(offset);
  // int new_offset = 0;
  // offset = new_offset;
};

DummyElseStatement: ELSE {
  tables.push(curr_table);
  curr_table = new Sym_Table(curr_table);
  list_of_Symbol_Tables.push_back(curr_table);
  scope_names.push(curr_scope);
  string new_scope = "ElseStatement";
  curr_scope = new_scope;
  // offsets.push(offset);
  // int new_offset = 0;
  // offset = new_offset;
};

DummyIfStatement1: DummyIfStatement Expression {
  string a = newLabel();
  emit("Goto", ($2).tempvar, a, "Ifz", -1);
  strcpy(($$).gotoname,a.c_str());
}

IfThenStatement:
DummyIfStatement1 CLOSEBRACKET Statement {
  
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  // offset = offsets.top(); offsets.pop();
  string a = newLabel();
  emit("Goto", "", a, "", -1);
  // strcpy(($$).gotoname,a.c_str());
  emit(($1).gotoname, ":", "", "", -1);
  emit(a, ":", "", "", -1);
};

DummyIfStatement2: DummyIfStatement1 CLOSEBRACKET StatementNoShortIf {
  string a = newLabel();
  emit("Goto", "", a, "", -1);
  emit(($1).gotoname, ":", "", "", -1);
  strcpy(($$).gotoname,a.c_str());
}

IfThenElseStatement:
DummyIfStatement2 DummyElseStatement Statement {
  emit(($1).gotoname, ":", "", "", -1);

  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  // offset = offsets.top(); offsets.pop();
  
  };
IfThenElseStatementNoShortIf:
DummyIfStatement2 DummyElseStatement StatementNoShortIf {
  emit(($1).gotoname, ":", "", "", -1);

  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  offset = offsets.top(); offsets.pop();
  };



DummySwitchStatement: SWITCH {
  tables.push(curr_table);
  curr_table = new Sym_Table(curr_table);
  list_of_Symbol_Tables.push_back(curr_table);
  scope_names.push(curr_scope);
  string new_scope = "SwitchStatement";
  curr_scope = new_scope;
  // offsets.push(offset);
  // int new_offset = 0;
  // offset = new_offset;
};
SwitchStatement:
DummySwitchStatement OPENBRACKET Expression CLOSEBRACKET SwitchBlock {

  };
SwitchBlock:
OPENCURLYBRACKET SwitchBlockStatementGroups SwitchLabels CLOSECURLYBRACKET {
  
  
  
  
  
  }
|OPENCURLYBRACKET SwitchLabels CLOSECURLYBRACKET {
  
  
  
  
  }
|OPENCURLYBRACKET SwitchBlockStatementGroups CLOSECURLYBRACKET {
  
  
  
  
  }
|OPENCURLYBRACKET CLOSECURLYBRACKET {
  
  
  
  };
SwitchBlockStatementGroups:
SwitchBlockStatementGroup {
  
  
  }
|SwitchBlockStatementGroups SwitchBlockStatementGroup {

  
  }
SwitchBlockStatementGroup:
SwitchLabels BlockStatements {
  
  
  
  };
SwitchLabels:
SwitchLabel  {
  
  
  }
|SwitchLabels SwitchLabel {
  
  
  
  };
SwitchLabel:
CASE ConstantExpression COLON {
  
  
  
  
  }
|DEFAULT COLON {
  
  
  
  };
DummyWhileStatement : WHILE {
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
  strcpy(($$).gotoname,a.c_str());
  continuelabels.push(a);
};

DummyWhileStatement1: DummyWhileStatement OPENBRACKET Expression {
  string a = newLabel();
  emit("Goto", ($3).tempvar, a, "Ifz", -1);
  strcpy(($$).gotoname,a.c_str());
  strcpy(($$).nextgoto,($1).gotoname);
  // emit(($1).gotoname, ":", "", "", -1);
  breaklabels.push(a);
}

WhileStatement:
DummyWhileStatement1 CLOSEBRACKET Statement {
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  // offset = offsets.top(); offsets.pop();
  inloop=0;
  emit("Goto", ($1).nextgoto, "", "", -1);
  emit(($1).gotoname, ":", "", "", -1);
  };

WhileStatementNoShortIf:
DummyWhileStatement1 CLOSEBRACKET StatementNoShortIf {
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  // offset = offsets.top(); offsets.pop();
  inloop=0;
  emit("Goto", ($1).nextgoto, "", "", -1);
  emit(($1).gotoname, ":", "", "", -1);
  };

DummyDoStatement: DO {
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
  strcpy(($$).gotoname,a.c_str());
  continuelabels.push(a);
}

DummyDoStatement1: DummyDoStatement Statement WHILE OPENBRACKET Expression {
  string a = newLabel();
  emit("Goto", ($5).tempvar, a, "Ifz", -1);
  emit("Goto", ($1).gotoname, "", "", -1);
  emit(a, ":", "", "", -1);
  strcpy(($$).gotoname,a.c_str());
  breaklabels.push(a);
}

DoStatement:
DummyDoStatement1 CLOSEBRACKET SEMICOLON {    
  newdim.clear();
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  // offset = offsets.top(); offsets.pop();
  inloop=0;
  isclassaccess=0;
    issystem=0;
    isfinal=0;
  };
DummyForStatement : FOR {
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

DummyForStatement1: DummyForStatement OPENBRACKET ForInit{
  string a = newLabel();
  emit(a, ":", "", "", -1);
  strcpy(($$).gotoname,a.c_str());
};

DummyForStatement14: DummyForStatement1 SEMICOLON {    
  newdim.clear();
 isclassaccess=0;
    issystem=0;
    isfinal=0;
};

DummyForStatement2: DummyForStatement14 Expression {
  string a = newLabel();
  emit("Goto", ($2).tempvar, a, "Ifz", -1);
  string b = newLabel();
  emit("Goto", b, "", "", -1);
  strcpy(($$).gotoname,($1).gotoname);
  strcpy(($$).nextgoto,a.c_str());
  strcpy(($$).nextgoto1,b.c_str());
  string c = newLabel();
  emit(c, ":", "", "", -1);
  strcpy(($$).nextgoto2,c.c_str());
  isclassaccess=0;
    issystem=0;
  continuelabels.push(c);
};

DummyForStatement3: DummyForStatement2 SEMICOLON ForUpdate {    
  newdim.clear();
  emit("Goto", ($1).gotoname, "", "", -1);
  emit(($1).nextgoto1, ":", "", "", -1);
  strcpy(($$).gotoname,($1).gotoname);
  strcpy(($$).nextgoto,($1).nextgoto);
  strcpy(($$).nextgoto1,($1).nextgoto1);
  strcpy(($$).nextgoto2,($1).nextgoto2);
  isclassaccess=0;
    issystem=0;
    isfinal=0;
  breaklabels.push(string((char*)(($1).nextgoto)));
}

DummyForStatement4: DummyForStatement2 SEMICOLON CLOSEBRACKET{   
  newdim.clear(); 
  emit("Goto", ($1).gotoname, "", "", -1);
  emit(($1).nextgoto1, ":", "", "", -1);
  strcpy(($$).gotoname,($1).gotoname);
  strcpy(($$).nextgoto,($1).nextgoto);
  strcpy(($$).nextgoto1,($1).nextgoto1);
  strcpy(($$).nextgoto2,($1).nextgoto2);
  isclassaccess=0;
    issystem=0;
    isfinal=0;
  breaklabels.push(string((char*)(($1).nextgoto)));
}

DummyForStatement15: DummyForStatement OPENBRACKET SEMICOLON {    
  newdim.clear();
  string a = newLabel();
  emit(a, ":", "", "", -1);
  strcpy(($$).gotoname,a.c_str());
  isclassaccess=0;
    issystem=0;
    isfinal=0;
}

DummyForStatement5: DummyForStatement15 Expression {
  string a = newLabel();
  emit("Goto", ($2).tempvar, a, "Ifz", -1);
  string b = newLabel();
  emit("Goto", b, "", "", -1);
  strcpy(($$).gotoname,($1).gotoname);
  strcpy(($$).nextgoto,a.c_str());
  strcpy(($$).nextgoto1,b.c_str());
  string c = newLabel();
  emit(c, ":", "", "", -1);
  strcpy(($$).nextgoto2,c.c_str());
  isclassaccess=0;
    issystem=0;
  continuelabels.push(c);
}

DummyForStatement6: DummyForStatement5 SEMICOLON ForUpdate {
  newdim.clear();
  emit("Goto", ($1).gotoname, "", "", -1);
  emit(($1).nextgoto1, ":", "", "", -1);
  strcpy(($$).gotoname,($1).gotoname);
  strcpy(($$).nextgoto,($1).nextgoto);
  strcpy(($$).nextgoto1,($1).nextgoto1);
  strcpy(($$).nextgoto2,($1).nextgoto2);
  isclassaccess=0;
    issystem=0;
    isfinal=0;
        
  breaklabels.push(string((char*)(($1).nextgoto)));
}

DummyForStatement7: DummyForStatement5 SEMICOLON CLOSEBRACKET {
      newdim.clear();
  emit("Goto", ($1).gotoname, "", "", -1);
  emit(($1).nextgoto1, ":", "", "", -1);
  strcpy(($$).gotoname,($1).gotoname);
  strcpy(($$).nextgoto,($1).nextgoto);
  strcpy(($$).nextgoto1,($1).nextgoto1);
  strcpy(($$).nextgoto2,($1).nextgoto2);
  isclassaccess=0;
    issystem=0;
    isfinal=0;
  breaklabels.push(string((char*)(($1).nextgoto)));
}

DummyForStatement8: DummyForStatement1 SEMICOLON SEMICOLON {
      newdim.clear();
  string a = newLabel();
  string b = newLabel();
  emit("Goto", b, "", "", -1);
  strcpy(($$).gotoname,($1).gotoname);
  strcpy(($$).nextgoto,a.c_str());
  strcpy(($$).nextgoto1,b.c_str());
  string c = newLabel();
  emit(c, ":", "", "", -1);
  strcpy(($$).nextgoto2,c.c_str());
  isclassaccess=0;
    issystem=0;
     isfinal=0;
  continuelabels.push(c);
}

DummyForStatement9: DummyForStatement8 ForUpdate {
  emit("Goto", ($1).gotoname, "", "", -1);
  emit(($1).nextgoto1, ":", "", "", -1);
  strcpy(($$).gotoname,($1).gotoname);
  strcpy(($$).nextgoto,($1).nextgoto);
  strcpy(($$).nextgoto1,($1).nextgoto1);
  strcpy(($$).nextgoto2,($1).nextgoto2);
  breaklabels.push(string((char*)(($1).nextgoto)));
}

DummyForStatement10: DummyForStatement8 CLOSEBRACKET {
  emit("Goto", ($1).gotoname, "", "", -1);
  emit(($1).nextgoto1, ":", "", "", -1);
  strcpy(($$).gotoname,($1).gotoname);
  strcpy(($$).nextgoto,($1).nextgoto);
  strcpy(($$).nextgoto1,($1).nextgoto1);
  strcpy(($$).nextgoto2,($1).nextgoto2);
  breaklabels.push(string((char*)(($1).nextgoto)));
}

DummyForStatement11: DummyForStatement15 SEMICOLON {
      newdim.clear();
  string a = newLabel();
  string b = newLabel();
  emit("Goto", b, "", "", -1);
  strcpy(($$).gotoname,($1).gotoname);
  strcpy(($$).nextgoto,a.c_str());
  strcpy(($$).nextgoto1,b.c_str());
  string c = newLabel();
  emit(c, ":", "", "", -1);
  strcpy(($$).nextgoto2,c.c_str());
  isclassaccess=0;
    issystem=0;
     isfinal=0;
  continuelabels.push(c);
}

DummyForStatement12: DummyForStatement11 ForUpdate {
  emit("Goto", ($1).gotoname, "", "", -1);
  emit(($1).nextgoto1, ":", "", "", -1);
  strcpy(($$).gotoname,($1).gotoname);
  strcpy(($$).nextgoto,($1).nextgoto);
  strcpy(($$).nextgoto1,($1).nextgoto1);
  strcpy(($$).nextgoto2,($1).nextgoto2);
  breaklabels.push(string((char*)(($1).nextgoto)));
}

DummyForStatement13: DummyForStatement11 CLOSEBRACKET {
  emit("Goto", ($1).gotoname, "", "", -1);
  emit(($1).nextgoto1, ":", "", "", -1);
  strcpy(($$).gotoname,($1).gotoname);
  strcpy(($$).nextgoto,($1).nextgoto);
  strcpy(($$).nextgoto1,($1).nextgoto1);
  strcpy(($$).nextgoto2,($1).nextgoto2);
  breaklabels.push(string((char*)(($1).nextgoto)));
}

ForStatement:
DummyForStatement6 CLOSEBRACKET Statement {
  // breaklabels.push(string((char*)(($1).nextgoto)));
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  // offset = offsets.top(); offsets.pop();
  inloop=0;
  emit("Goto", ($1).nextgoto2, "", "", -1);
  emit(($1).nextgoto, ":", "", "", -1);
  continuelabels.pop();
  breaklabels.pop();
  }
|DummyForStatement9 CLOSEBRACKET Statement {
  // breaklabels.push(string((char*)(($1).nextgoto)));
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  // offset = offsets.top(); offsets.pop(); 
  inloop=0;
  emit("Goto", ($1).nextgoto2, "", "", -1);
  emit(($1).nextgoto, ":", "", "", -1);
  continuelabels.pop();
  breaklabels.pop();
  }
|DummyForStatement4 Statement {
  // breaklabels.push(string((char*)(($1).nextgoto)));
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  // offset = offsets.top(); offsets.pop();
  inloop=0;
  emit("Goto", ($1).nextgoto2, "", "", -1);
  emit(($1).nextgoto, ":", "", "", -1);
  continuelabels.pop();
  breaklabels.pop();
  }
|DummyForStatement12 CLOSEBRACKET Statement {
  // breaklabels.push(string((char*)(($1).nextgoto)));
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  // offset = offsets.top(); offsets.pop();
  inloop=0;
  emit("Goto", ($1).nextgoto2, "", "", -1);
  emit(($1).nextgoto, ":", "", "", -1);
  continuelabels.pop();
  breaklabels.pop();
  }
|DummyForStatement10 Statement {
  // breaklabels.push(string((char*)(($1).nextgoto)));
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  // offset = offsets.top(); offsets.pop();
  inloop=0;
  emit("Goto", ($1).nextgoto2, "", "", -1);
  emit(($1).nextgoto, ":", "", "", -1);
  continuelabels.pop();
  breaklabels.pop();
  }
|DummyForStatement7 Statement {
  // breaklabels.push(string((char*)(($1).nextgoto)));
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  // offset = offsets.top(); offsets.pop();
  inloop=0;
  emit("Goto", ($1).nextgoto2, "", "", -1);
  emit(($1).nextgoto, ":", "", "", -1);
  continuelabels.pop();
  breaklabels.pop();
  }
|DummyForStatement13 Statement {
  // breaklabels.push(string((char*)(($1).nextgoto)));
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  // offset = offsets.top(); offsets.pop();
  inloop=0;
  emit("Goto", ($1).nextgoto2, "", "", -1);
  emit(($1).nextgoto, ":", "", "", -1);
  continuelabels.pop();
  breaklabels.pop();
  }
|DummyForStatement3 CLOSEBRACKET Statement {
  // breaklabels.push(string((char*)(($1).nextgoto)));
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  // offset = offsets.top(); offsets.pop();
  inloop=0;
  emit("Goto", ($1).nextgoto2, "", "", -1);
  emit(($1).nextgoto, ":", "", "", -1);
  continuelabels.pop();
  breaklabels.pop();
  };

ForStatementNoShortIf:
DummyForStatement6 CLOSEBRACKET StatementNoShortIf {
  // breaklabels.push(string((char*)(($1).nextgoto)));
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  // offset = offsets.top(); offsets.pop();
  inloop=0;
  emit("Goto", ($1).nextgoto2, "", "", -1);
  emit(($1).nextgoto, ":", "", "", -1);
  continuelabels.pop();
  breaklabels.pop();
  }
|DummyForStatement9 CLOSEBRACKET StatementNoShortIf {
  // breaklabels.push(string((char*)(($1).nextgoto)));
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  // offset = offsets.top(); offsets.pop();
  inloop=0;
  emit("Goto", ($1).nextgoto2, "", "", -1);
  emit(($1).nextgoto, ":", "", "", -1);
  continuelabels.pop();
  breaklabels.pop();
  }
|DummyForStatement4 StatementNoShortIf {
  // breaklabels.push(string((char*)(($1).nextgoto)));
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  // offset = offsets.top(); offsets.pop();
  inloop=0;
  emit("Goto", ($1).nextgoto2, "", "", -1);
  emit(($1).nextgoto, ":", "", "", -1);
  continuelabels.pop();
  breaklabels.pop();
  }
|DummyForStatement12 CLOSEBRACKET StatementNoShortIf {
  // breaklabels.push(string((char*)(($1).nextgoto)));
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  // offset = offsets.top(); offsets.pop();
  inloop=0;
  emit("Goto", ($1).nextgoto2, "", "", -1);
  emit(($1).nextgoto, ":", "", "", -1);
  continuelabels.pop();
  breaklabels.pop();
  }
|DummyForStatement10 StatementNoShortIf {
  // breaklabels.push(string((char*)(($1).nextgoto)));
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  // offset = offsets.top(); offsets.pop();
  inloop=0;
  emit("Goto", ($1).nextgoto2, "", "", -1);
  emit(($1).nextgoto, ":", "", "", -1);
  continuelabels.pop();
  breaklabels.pop();
  }
|DummyForStatement7 StatementNoShortIf {
  // breaklabels.push(string((char*)(($1).nextgoto)));
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  // offset = offsets.top(); offsets.pop();
  inloop=0;
  emit("Goto", ($1).nextgoto2, "", "", -1);
  emit(($1).nextgoto, ":", "", "", -1);
  continuelabels.pop();
  breaklabels.pop();
  }
|DummyForStatement13 StatementNoShortIf {
  // breaklabels.push(string((char*)(($1).nextgoto)));
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  // offset = offsets.top(); offsets.pop();
  inloop=0;
  emit("Goto", ($1).nextgoto2, "", "", -1);
  emit(($1).nextgoto, ":", "", "", -1);
  continuelabels.pop();
  breaklabels.pop();
  }
|DummyForStatement3 CLOSEBRACKET StatementNoShortIf {
  // breaklabels.push(string((char*)(($1).nextgoto)));
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  // offset = offsets.top(); offsets.pop();
  inloop=0;
  emit("Goto", ($1).nextgoto2, "", "", -1);
  emit(($1).nextgoto, ":", "", "", -1);
  continuelabels.pop();
  breaklabels.pop();
  };
ForInit:
StatementExpressionList {
}
|LocalVariableDeclaration {
};

ForUpdate:
StatementExpressionList {
};

StatementExpressionList:
StatementExpression {
}
|StatementExpressionList COMMA StatementExpression {
};

BreakStatement:
BREAK SEMICOLON {
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
|BREAK Identifier SEMICOLON {
  newdim.clear();
      
  if(curr_table->lookup(string((char*)($1).str)).offset == -1 && checkobj(string((char*)($1).str)) == 0){
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
};

ContinueStatement:
CONTINUE Identifier SEMICOLON {
  newdim.clear();
      
  if(curr_table->lookup(string((char*)($1).str)).offset == -1 && checkobj(string((char*)($1).str)) == 0){
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
|CONTINUE SEMICOLON {    
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
};


ReturnStatement:
RETURN SEMICOLON {   
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
|RETURN Expression SEMICOLON {   
  
  newdim.clear();
  string p = string((char*)($2).tempvar);
    string o = p.substr(0, p.find('.'));
    if(p != o){
      string v = p.substr(p.find('.')+1, p.size());
      int tp2 = curr_table->lookup(v).offset;
      string tp3 = "*(" + o + "+" + to_string(tp2) + ")";
      strcpy(($2).tempvar, tp3.c_str());
    }
    if(ispopped == 1){
    if(totalstack != 0){ emit("add", "rsp", to_string(totalstack), "", -1); ;}
    emit("pop","rbp","","",-1);
    ispopped = 0;totalstack = 0;
    cout<<"FUCK\n"; 
    
  }
  emit("addretval", ($2).tempvar, "", "", -1);
  emit("ret", "" , "", "", -1);
  if(!infunction)
  {
    cout<<"Invalid return on line "<<yylineno<<'\n';
  }
  else
  {
    isreturn=1;
    if(!boolgetorder(functype.c_str(),($2).type,1))
    {
      if(strcmp(functype.c_str(),($2).type))
      {
        cout<<"Return type mismatch on line "<<yylineno<<'\n';
      }
    }
  }
  isclassaccess=0;
    issystem=0;
};


ThrowStatement:
THROW Expression SEMICOLON {    
  newdim.clear();
  isclassaccess=0;
    issystem=0;
     isfinal=0;
};
SynchronizedStatement:
SYNCHRONIZED OPENBRACKET Expression CLOSEBRACKET Block {
};
TryStatement:
TRY Block Catches {
}
|TRY Block Catches Finally {
}
|TRY Block Finally {
};
Catches:
CatchClause {
}
|Catches CatchClause {
};
CatchClause:
CATCH {
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
OPENBRACKET FormalParameter CLOSEBRACKET Block {
  curr_table = tables.top(); tables.pop();
  curr_scope = scope_names.top(); scope_names.pop();
  // offset = offsets.top(); offsets.pop();
};
Finally:
FINALLY Block {
};
Primary:
PrimaryNoNewArray {
  strcpy(($$).tempvar, ($1).tempvar);
  strcpy(($$).type,($1).type);
  ($$).ndim=($1).ndim;
}
|ArrayCreationExpression {
  strcpy(($$).type,($1).type);
  strcpy(($$).tempvar, ($1).tempvar);
};

PrimaryNoNewArray:
Literal {
  strcpy(($$).tempvar, ($1).tempvar);

  strcpy(($$).type,($1).type);
}
|THIS {
  string s = newtemp();
  emit("=", "[rbp+8]", "null", s, -1);
  strcpy(($$).tempvar, s.c_str());
  strcpy(($$).type,($1).str);
}
|OPENBRACKET Expression CLOSEBRACKET {

  strcpy(($$).tempvar, ($2).tempvar);
  
  strcpy(($$).type,($2).type);
  
}
|ClassInstanceCreationExpression {
  strcpy(($$).type,($1).type);
  
  strcpy(($$).tempvar, ($1).tempvar);
}
|FieldAccess {

  strcpy(($$).tempvar, ($1).tempvar);
  
  strcpy(($$).type,($1).type);
  
}
|MethodInvocation {

  strcpy(($$).tempvar, ($1).tempvar);
  
  strcpy(($$).type,($1).type);
  
}
|ArrayAccess {
  strcpy(($$).type,($1).type);
  
  strcpy(($$).tempvar, ($1).tempvar);
};

ClassInstanceCreationExpression:
NEW ClassType OPENBRACKET ArgumentList CLOSEBRACKET {
  objlist.push_back(curridf);
  isobj = 1;
  string tv1 = newtemp();
  emit("=", to_string(getclasswidth(string((char*)($2).type))), "null", tv1, -1);
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
  emit("call",string((char*)(($2).type)), "","",-1);
  emit("=", o2, "null", "shiftreg", -1);
  emit("add", "rsp", to_string(8 + pops),"", -1);
  strcpy(($$).tempvar, tv2.c_str());

  strcpy(($$).type,($2).type);
  // cout<<"LLL"<<($$).type<<'\n';
  if((curr_table->lookup(string((char*)($2).type)).offset == -1)&& checkobj(string((char*)($2).type)) == 0){
    if(strcmp(($2).type,"System")&&!isaccess) 
    {
      cout<<"Undeclared variable "<<($2).type<<" on line "<< yylineno<<"\n";
      // cout<<"KKK"<<($1).type<<'\n';
    }  
  }
  else
  {
    if(curr_table->lookup(string((char*)($2).type)).narg != ($4).nelem&&strcmp(curr_table->lookup(string((char*)($2).type)).scope_name.c_str(),"Global"))
    {
      cout<<"Incorrect number of arguments passed to Constructor on line "<< yylineno<<"\n";
      // cout<<"LLL"<<curr_table->lookup(string((char*)($1).type)).narg<<($3).nelem<<'\n';
    }
    else
    {
      strcat(($4).argstring,"#");
      // cout<<($4).argstring<<'\n';
      int j=0;
      string yo="";
      string shubhan="Constructor"+string((char*)($2).type);
      // cout<<shubhan<<'\n';
      for(int i=0;i<($4).nelem;i++)
      {
        for(;;)
        {
          if(($4).argstring[j]=='$'||($4).argstring[j]=='#') 
          {
            j++;
            break;
          }
          yo+=($4).argstring[j];
          j++;
        }
        // cout<<yo<<'\n';
        auto it = lookup1(shubhan, i+1);
        // cout<<it.type<<'\n';
        if(!boolgetorder(it.type.c_str(),yo.c_str(),1)&&strcmp(it.type.c_str(),yo.c_str()))
        {
          cout<<"Argument "<<i+1<<" does not match Constructor definiton of "<<($2).type<<" on line "<<yylineno<<'\n';
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
|NEW ClassType OPENBRACKET CLOSEBRACKET {
  objlist.push_back(curridf);
  isobj = 1;
  // string a = newtemp();
  // strcpy(($$).tempvar, a.c_str());
  string tv1 = newtemp();
  emit("=", to_string(getclasswidth(string((char*)($2).type))), "null", tv1, -1);
  emit("param",tv1,"","",-1);
  // // emit("sub","rsp","8","",-1);
  emit("call","allocmem","1","",-1);
  emit("add","rsp","8","",-1);
  string tv2 = newtemp();
  emit("=", "popparam", "null", tv2, -1);
  emit("param",tv2,"","",-1);
  string o2 = newtemp();
  emit("=", "shiftreg", "null", o2, -1);
  emit("call",string((char*)(($2).type)), "","",-1);
  emit("=", o2, "null", "shiftreg", -1);
  strcpy(($$).tempvar, tv2.c_str());
  currtemp = tv2;

  strcpy(($$).type,($2).type);
  if((curr_table->lookup(string((char*)($2).type)).offset == -1)&& checkobj(string((char*)($2).type)) == 0){
    if(strcmp(($2).type,"System")&&!isaccess) 
    {
      cout<<"Undeclared variable "<<($2).type<<" on line "<< yylineno<<"\n";
      // cout<<"KKK"<<($1).type<<'\n';
    }  
  }
  else
  {
    if(curr_table->lookup(string((char*)($2).type)).narg != 0)
    {
      cout<<"Incorrect number of arguments passed to Constructor on line "<< yylineno<<"\n";
      // cout<<"LLL"<<curr_table->lookup(string((char*)($1).type)).narg<<($3).nelem<<'\n';
    }
  }
  isaccess=0;
  // cout<<($2).type<<'\n';
};

ArgumentList:
Expression {
  args.push({string((char*)($1).tempvar), sz});
  strcpy(($$).argstring, ($1).type);
  // cout<<"XXX"<<($$).argstring<<'\n';
  ($$).nelem=1;
}
|ArgumentList COMMA Expression {
  args.push({string((char*)($3).tempvar), sz});
  strcat(($$).argstring, "$");
  strcat(($$).argstring, ($3).type);
  // cout<<"XXX"<<($$).argstring<<'\n';
  ($$).nelem=($1).nelem+1;
};

ArrayCreationExpression:
NEW PrimitiveType DimExprs Dims {
  newhandle = string((char*)(($2).type));
  // strcpy(($$).tempvar, newtemp().c_str());
  // emit("=", "new", string((char*)($2).tempvar) + string((char*)($3).tempvar) + string((char*)($4).tempvar), ($$).tempvar, -1);
  flagyo=1;
  strcpy(($$).arrtype,($2).type);
  ($$).ndim = ($3).ndim + ($4).ndim;
  strcpy(($$).type,($2).type);
  for(int i=0;i<($$).ndim;i++)
  {
    strcat(($$).type,"[]");
  }
  // print_dims();
    
}
|NEW PrimitiveType DimExprs {
  newhandle = string((char*)(($2).type));
  // strcpy(($$).tempvar, newtemp().c_str());
  // emit("=", "new", string((char*)($2).tempvar) + string((char*)($3).tempvar), ($$).tempvar, -1);

  flagyo=1;
  strcpy(($$).type,"array");
  strcpy(($$).arrtype,($2).type);
  ($$).ndim = ($3).ndim;  
  strcpy(($$).type,($2).type);
  for(int i=0;i<($$).ndim;i++)
  {
    strcat(($$).type,"[]");
  }
  // print_dims();
    
}
|NEW ClassOrInterfaceType DimExprs Dims {
  newhandle = string((char*)(($2).type));
  // strcpy(($$).tempvar, newtemp().c_str());
  // emit("=", "new", string((char*)($2).tempvar) + string((char*)($3).tempvar) + string((char*)($4).tempvar), ($$).tempvar, -1);
  flagyo=1;
  strcpy(($$).type,"array");
  strcpy(($$).arrtype,($2).type);
  ($$).ndim = ($3).ndim + ($4).ndim;
  strcpy(($$).type,($2).type);
  for(int i=0;i<($$).ndim;i++)
  {
    strcat(($$).type,"[]");
  }
  // print_dims();
    
  
}
|NEW ClassOrInterfaceType DimExprs {
  // strcpy(($$).tempvar, newtemp().c_str());
  // emit("=", "new", string((char*)($2).tempvar) + string((char*)($3).tempvar), ($$).tempvar, -1);
  flagyo=1;
  strcpy(($$).type,"array");
  strcpy(($$).arrtype,($2).type);
  ($$).ndim = ($3).ndim;
  strcpy(($$).type,($2).type);
  for(int i=0;i<($$).ndim;i++)
  {
    strcat(($$).type,"[]");
  }
  // print_dims();
    
  
  
};
DimExprs:
DimExpr {
  ($$).ndim=1;
  strcpy(($$).tempvar, ($1).tempvar);
}
|DimExprs DimExpr {
  ($$).ndim = ($1).ndim + 1;
  strcpy(($$).tempvar, strcat(($1).tempvar, ($2).tempvar));
};
DimExpr:
OPENSQUAREBRACKET Expression CLOSESQUAREBRACKET {
  strcpy(($$).tempvar, strcat(($1).str, strcat(($2).tempvar, ($3).str)));
  ($$).ndim=1;
  newdim.push_back(dimint);
  
};

Dims:
OPENSQUAREBRACKET CLOSESQUAREBRACKET {
  strcpy(($$).tempvar, strcat(($1).str, ($2).str));
  strcpy(($$).tempvar, strcat(($1).str, ($2).str));
  ($$).ndim=1;
  newdim.push_back(0);
  
}
|Dims OPENSQUAREBRACKET CLOSESQUAREBRACKET {
  strcpy(($$).tempvar, strcat(($1).tempvar, strcat(($2).str, ($3).str)));
  ($$).ndim = ($1).ndim + 1;
  newdim.push_back(0);
};

FieldAccess:
Primary DOT Identifier {
  // strcpy(($$).tempvar, strcat(($1).tempvar, strcat(($2).str, ($3).str)));
  if(curr_table->lookup(string((char*)($3).str)).offset == -1 && checkobj(string((char*)($3).str)) == 0){
    cout<<"Undeclared variable on line "<< yylineno<<"\n";
  }
  if(strcmp(($1).type,"this")==0)
  {
    strcpy(($$).tempvar, (string((char*)(($3).str)) + "!").c_str());
    strcpy(($$).type,curr_table->thislookup(($3).str).c_str());
  }
}
|SUPER DOT Identifier {
  strcpy(($$).tempvar, strcat(($1).str, strcat(($2).str, ($3).str)));
  if(curr_table->lookup(string((char*)($3).str)).offset == -1 && checkobj(string((char*)($3).str)) == 0){
    cout<<"Undeclared variable on line "<< yylineno<<"\n";
  }
};

DummyMethodInvocation: Name {
  //emit(string((char*)($1).type),"","","",-1);
  //emit("BeginFunc","","","",-1);
  strcpy(($$).type,($1).type);
  strcpy(($$).tempvar,($1).tempvar);
}

MethodInvocation:
DummyMethodInvocation OPENBRACKET ArgumentList CLOSEBRACKET {
  int pops = 0;
  string ar = "";
  stack<string> args2;
  
  int funcargtypesz1 = funcargtypesz(1, string((char*)(($1).type)));
  // emit("stackpointer", "+" + to_string(funcargtypesz1), "", "", -1);

  if(!strcmp(string((char*)(($1).tempvar)).c_str(),"System.println"))
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

    string tv9 = string((char*)(($1).tempvar));
    string oname = tv9.substr(0, tv9.find('.'));
    string cname = curr_table->lookup(oname).type;
    if(checkclass(cname)){
      string mname = tv9.substr(tv9.find('.')+1, tv9.size());
      funcargtypesz1 = funcargtypesz(1, mname) + 8;
      // emit("param", oname, "", "", -1);
      // emit("sub","rsp",to_string(funcargtypesz1),"",-1);
      string o2 = newtemp();
      emit("=", "shiftreg", "null", o2, -1);
      emit("call", cname + "." + mname, "", "", -1);
      emit("=", o2, "null", "shiftreg", -1);

    }
    else{
      // emit("sub","rsp",to_string(funcargtypesz1),"",-1);
      string o2 = newtemp();
      emit("=", "shiftreg", "null", o2, -1);
      emit("call", string((char*)(($1).tempvar)),"", "", -1);
      emit("=", o2, "null", "shiftreg", -1);
    }
  
  // emit("stackpointer", "-" + to_string(funcargtypesz1), "", "", -1);
  emit("add","rsp",to_string(funcargtypesz1),"",-1);
  string tv3 = newtemp();
  emit("=", "popparam", "null", tv3.c_str(), -1);
  emit("add", "rsp", to_string(8), "", -1);
  strcpy(($$).tempvar, tv3.c_str());
  }
  //emit("EndFunc","","","",-1)

  // if(curr_table->lookup(string((char*)($1).type))->offset == -1){
  //   cout<<"Undeclared variable on line "<< yylineno<<"\n";
  // }
  // cout<<isaccess<<'\n';
  if((curr_table->lookup(string((char*)($1).type)).offset == -1)&& checkobj(string((char*)($1).type)) == 0){
    if(strcmp(($1).type,"System")&&!isaccess) 
    {
      cout<<"Undeclared variable "<<($1).type<<" on line "<< yylineno<<"\n";
      // cout<<"KKK"<<($1).type<<'\n';
    }  
  }
  if(!isaccess)
  {
    if(curr_table->lookup(string((char*)($1).type)).narg != ($3).nelem)
    {
      cout<<"Incorrect number of arguments passed to function on line "<< yylineno<<"\n";
      // cout<<"LLL"<<curr_table->lookup(string((char*)($1).type)).narg<<($3).nelem<<'\n';
    }
    else
    {
      strcat(($3).argstring,"#");
      // cout<<($3).argstring<<'\n';
      int j=0;
      string yo="";
      string shubhan="Method"+string((char*)($1).type);
      // cout<<shubhan<<'\n';
      for(int i=0;i<($3).nelem;i++)
      {
        for(;;)
        {
          if(($3).argstring[j]=='$'||($3).argstring[j]=='#') 
          {
            j++;
            break;
          }
          yo+=($3).argstring[j];
          j++;
        }
        // cout<<yo<<'\n';
        auto it = lookup1(shubhan, i+1);
        // cout<<it.type<<'\n';
        if(!boolgetorder(it.type.c_str(),yo.c_str(),1)&&strcmp(it.type.c_str(),yo.c_str()))
        {
          cout<<"Argument "<<i+1<<" does not match function definiton of "<<($1).type<<" on line "<<yylineno<<'\n';
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
    if(checknarg(fullname, 0, classname)!=($3).nelem)
    {
      // cout<<classname<<'\n';
      // cout<<"YOOOOO"<<checknarg(fullname,0, classname)<<'\n';
      if(strcmp(classname.c_str(),"null")&&!issystem)cout<<"Incorrect number of arguments passed to function on line "<< yylineno<<"\n";
      // cout<<"LLL"<<curr_table->lookup(string((char*)($1).type)).narg<<($3).nelem<<'\n';
    }
    else
    {
      strcat(($3).argstring,"#");
      // cout<<($3).argstring<<'\n';
      int j=0;
      string yo="";
      string shubhan="Method"+string((char*)($1).type);
      // cout<<shubhan<<'\n';
      for(int i=0;i<($3).nelem;i++)
      {
        for(;;)
        {
          if(($3).argstring[j]=='$'||($3).argstring[j]=='#') 
          {
            j++;
            break;
          }
          yo+=($3).argstring[j];
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
|DummyMethodInvocation OPENBRACKET CLOSEBRACKET {
  if(!strcmp(string((char*)(($1).tempvar)).c_str(),"System.println"))
  {
    emit("call", "print 1", "", "", -1);
  }
  else{
    string tv9 = string((char*)(($1).tempvar));
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
      emit("=", "shiftreg", "null", o2, -1);
      emit("call", string((char*)(($1).tempvar)),"", "", -1);
      emit("=", o2, "null", "shiftreg", -1);
    }
  }
  string s = newtemp();
  emit("=", "popparam", "null", s.c_str(), -1);
  emit("add", "rsp", to_string(8), "", -1);
  strcpy(($$).tempvar,s.c_str());

    if((curr_table->lookup(string((char*)($1).type)).offset == -1)&& checkobj(string((char*)($1).type)) == 0){
    if(strcmp(($1).type,"System")&&!isaccess) 
    {
      cout<<"Undeclared variable "<<($1).type<<" on line "<< yylineno<<"\n";
      // cout<<"KKK"<<($1).type<<'\n';
    }  
  }
  if(!isaccess)
  {
    if(curr_table->lookup(string((char*)($1).type)).narg != 0)
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
|Primary DOT Identifier OPENBRACKET ArgumentList CLOSEBRACKET {
  
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
  int funcargtypesz1 = funcargtypesz(1, string((char*)(($1).type)));
  // emit("stackpointer", "+" + to_string(funcargtypesz1), "", "", -1);

  if(!strcmp(string((char*)(($1).tempvar)).c_str(),"System.println"))
  {
    emit("call", "print 1", "", "", -1);
  }
  else{
    string tv9 = string((char*)(($1).tempvar));
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
  emit("=", "shiftreg", "null", o2, -1);
      emit("call", string((char*)(($1).tempvar)),"", "", -1);
      emit("=", o2, "null", "shiftreg", -1);
    }
  }
  // emit("stackpointer", "-" + to_string(funcargtypesz1), "", "", -1);
  emit("add","rsp",to_string(funcargtypesz1),"",-1);
  string tv3 = newtemp();
  emit("=", "popparam", "null", tv3.c_str(), -1);
  emit("add", "rsp", to_string(8), "", -1);
  strcpy(($$).tempvar, tv3.c_str());

  if(curr_table->lookup(string((char*)($3).str)).offset == -1 && checkobj(string((char*)($3).str)) == 0){
    if(!isaccess)
    {
      cout<<"Undeclared variable on line "<< yylineno<<"\n";
    }
  }
  isaccess=0;
}
|Primary DOT Identifier OPENBRACKET CLOSEBRACKET {
  string s = newtemp();
  string o2 = newtemp();
  emit("=", "shiftreg", "null", o2, -1);
  emit("call",string((char*)($1).tempvar) + string((char*)($2).str) + string((char*)($3).str)   ,"","",-1);
  emit("=", o2, "null", "shiftreg", -1);
  emit("=", "popparam", "null", s.c_str(), -1);
  emit("add", "rsp", to_string(8), "", -1);
  strcpy(($$).tempvar, s.c_str());

  if(curr_table->lookup(string((char*)($3).str)).offset == -1 && checkobj(string((char*)($3).str)) == 0){
  if(!isaccess)
    {
      cout<<"Undeclared variable on line "<< yylineno<<"\n";
    }
  }
  isaccess=0;
}
|SUPER DOT Identifier OPENBRACKET ArgumentList CLOSEBRACKET {
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

  if(curr_table->lookup(string((char*)($3).str)).offset == -1 && checkobj(string((char*)($3).str)) == 0){
  if(!isaccess)
    {
      cout<<"Undeclared variable on line "<< yylineno<<"\n";
    }
  }
  isaccess=0;
}
|SUPER DOT Identifier OPENBRACKET CLOSEBRACKET {
  string s = newtemp();
  string o2 = newtemp();
  emit("=", "shiftreg", "null", o2, -1);
  emit("call",string((char*)($1).str) + string((char*)($2).str) + string((char*)($3).str),"","",-1);
  emit("=", o2, "", "shiftreg", -1);
  emit("=", "popparam", "null", s.c_str(), -1);
  emit("add", "rsp", to_string(8), "", -1);
  strcpy(($$).tempvar,s.c_str());

  if(curr_table->lookup(string((char*)($3).str)).offset == -1 && checkobj(string((char*)($3).str)) == 0){
  if(!isaccess)
    {
      cout<<"Undeclared variable on line "<< yylineno<<"\n";
    }
  }
  isaccess=0;
};

ArrayAccess:
Name OPENSQUAREBRACKET Expression CLOSESQUAREBRACKET {
  arrayname=($1).type;
  strcpy(($$).tempvar, newtemp().c_str());
  string tp4;
  string tp5 = curr_table->lookup(string((char*)($1).type)).type;
  for(auto it: tp5){
    if(it != '['){
      tp4.push_back(it);
    }
    else{
      break;
    }
  }

  string array_len = curr_table->lookup(string((char*)(($1).type))).type;
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
    emit("*", to_string(x), string((char*)(($3).tempvar)), tp8, -1);
    // cout<<"YUI"<<y<<" "<<x<<'\n';
    // tp8 = to_string(x);
    arrayaccesscount -- ;
  }
  else{
    // string tv13 = newtemp();
    emit("*",string((char*)($3).tempvar), "8" , tp8 , -1);
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
  if(objtotemp[string((char*)(($$).tempvar))] != ""){
    strcpy(($$).tempvar, objtotemp[string((char*)(($$).tempvar))].c_str());
  }
  if(objtotemp[string((char*)(($1).tempvar))] != ""){
    strcpy(($1).tempvar, objtotemp[string((char*)(($1).tempvar))].c_str());
  }
  emit("=",tp8,"null",tp7,-1);
  string tv14 = newtemp();
  emit("+",string((char*)($1).tempvar), tp7 , tv14 , -1);
  string tp6 = tv14;
  if(objtotemp[tp6] != ""){
    tp6 = objtotemp[tp6];
  }
  emit("=",tp6,"null",string((char*)($$).tempvar),-1);

  if(arrayaccesscount == 0){
    string tv7 = string((char*)(($$).tempvar));
    tv7 = "*" + tv7;
    strcpy(($$).tempvar, tv7.c_str());
  }

  arraccess=1;
  if(curr_table->lookup(string((char*)($1).type)).offset == -1 && checkobj(string((char*)($1).type)) == 0){
    cout<<"Undeclared variable on line "<< yylineno<<"\n";
  }
  else
  {
    arrtype=curr_table->lookup(string((char*)($1).type)).type;
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
    if(strcmp(($3).type,"int"))
    {
      cout<<"Array index not integer and is "<<($3).type<<" on line "<< yylineno<<"\n";
    }
    else
    {
        // cout<<"yooo "<<curr_table->lookup(string((char*)($1).type)).token.c_str()<<'\n';
      if(strcmp(curr_table->lookup(string((char*)($1).type)).token.c_str(),"Array"))
      {
        cout<<"Can not access index of "<<curr_table->lookup(string((char*)($1).type)).token.c_str() <<" on line "<< yylineno<<"\n";
      }
      arrtype=yo;
      if(flag)
      {
        arrtype="null";
      }
      strcpy(($$).type,arrtype.c_str());
      // cout<<"yoo"<<($$).type<<'\n';
    }
  }
  // yo="";
}
|PrimaryNoNewArray OPENSQUAREBRACKET Expression CLOSESQUAREBRACKET {
  strcpy(($$).tempvar, newtemp().c_str());
  string tp4;
  string tp5 = curr_table->lookup(string((char*)($1).type)).type;
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
    emit("*", to_string(x), string((char*)(($3).tempvar)), tp8, -1);
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
    emit("*", to_string(8), string((char*)(($3).tempvar)), tp8, -1);
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
  if(objtotemp[string((char*)(($$).tempvar))] != ""){
    strcpy(($$).tempvar, objtotemp[string((char*)(($$).tempvar))].c_str());
  }
  if(objtotemp[string((char*)(($1).tempvar))] != ""){
    strcpy(($1).tempvar, objtotemp[string((char*)(($1).tempvar))].c_str());
  }
  emit("=",tp8,"null",tp7,-1);
  string tv14 = newtemp();
  emit("+",string((char*)($1).tempvar), tp7 , tv14 , -1);
  string tp6 = tv14;
  if(objtotemp[tp6] != ""){
    tp6 = objtotemp[tp6];
  }
  emit("=",tp6,"null",string((char*)($$).tempvar),-1);

  if(arrayaccesscount == 0){
    string tv7 = string((char*)(($$).tempvar));
    tv7 = "*" + tv7;
    strcpy(($$).tempvar, tv7.c_str());
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
    if(strcmp(($3).type,"int"))
    {
      cout<<"Array index not integer and is "<<($3).type<<" on line "<< yylineno<<"\n";
    }
    else
    {
      arrtype=yo;
      if(flag)
      {
        arrtype="null";
        // cout<<"null\n";
      }
      strcpy(($$).type,arrtype.c_str());
      // cout<<"yoo"<<($$).type<<'\n';
    }
  // }
  yo="";
};

PostfixExpression:
Primary {
  strcpy(($$).tempvar, ($1).tempvar);

  ($$).ndim=($1).ndim;
  strcpy(($$).type,($1).type);
}
|Name {
  strcpy(($$).tempvar, ($1).tempvar);
  
  if(curr_table->lookup(string((char*)($1).type)).offset == -1 && checkobj(string((char*)($1).type)) == 0){
    if(!isaccess)
    {
      cout<<"Undeclared variable on line "<< yylineno<<"\n";
    }
  }
  strcpy(($$).type,($1).type);
}
|PostIncrementExpression {
  strcpy(($$).tempvar, ($1).tempvar);
  
  strcpy(($$).type,($1).type);
}
|PostDecrementExpression {
  strcpy(($$).tempvar, ($1).tempvar);

  strcpy(($$).type,($1).type);
  
};
PostIncrementExpression:
PostfixExpression PLUSPLUS {
  // cout<<($1).type<<'\n';
  string tmp = newtemp();
  emit("=",($1).tempvar,"null",tmp, -1);
  emit("+", tmp, "1", ($1).tempvar, -1);
  strcpy(($$).tempvar, tmp.c_str());
  // cout<<"LHK"<<curr_table->lookup(string((char*)($1).type)).type<<'\n';
  string s;
  if(curr_table->lookup(string((char*)($1).type)).offset!=-1)
  {
    s=curr_table->lookup(string((char*)($1).type)).type;
  }
  else s=($1).type;
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
  else strcpy(($$).type,($1).type);
  yo="";

};
PostDecrementExpression:
PostfixExpression MINUSMINUS {

  string tmp = newtemp();
  emit("=",($1).tempvar,"null",tmp, -1);
  emit("-", tmp, "1", ($1).tempvar, -1);
  strcpy(($$).tempvar, tmp.c_str());

  string s;
  if(curr_table->lookup(string((char*)($1).type)).offset!=-1)
  {
    s=curr_table->lookup(string((char*)($1).type)).type;
  }
  else s=($1).type;
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
  else strcpy(($$).type,($1).type);
  yo="";
  
};
UnaryExpression:
PreIncrementExpression {
  strcpy(($$).tempvar, ($1).tempvar);

  ($$).ndim=($1).ndim;
  strcpy(($$).type,($1).type);
}
|PreDecrementExpression {
  strcpy(($$).tempvar, ($1).tempvar);
  
  strcpy(($$).type,($1).type);
}
|PLUS UnaryExpression {
  strcpy(($$).tempvar, newtemp().c_str());
  emit("plus",($2).tempvar,"null",($$).tempvar, -1); 
  
 cout<<string((char*)($2).type)<<endl;
 if(invalidoperator(string((char*)($2).type),0) || !strcmp(string((char*)($2).type).c_str() ,"boolean" )){
    cout<<"Invalid Operator on line "<< yylineno<<"\n";
  }
  strcpy(($$).type,($2).type);
  
  
}
|MINUS UnaryExpression {
strcpy(($$).tempvar, newtemp().c_str());  
  emit("minus",($2).tempvar,"null",($$).tempvar, -1); 
 if(invalidoperator(string((char*)($2).type),0) || !strcmp(string((char*)($2).type).c_str() ,"boolean" )){
    cout<<"Invalid Operator on line "<< yylineno<<"\n";
  }
  strcpy(($$).type,($2).type);
  
}
|UnaryExpressionNotPlusMinus {
  strcpy(($$).tempvar, ($1).tempvar);

  strcpy(($$).type,($1).type);
  ($$).ndim=($1).ndim;
};

PreIncrementExpression:
PLUSPLUS UnaryExpression {
  string tmp = newtemp();
  emit("+",($2).tempvar,"1",tmp, -1);
  emit("=", tmp, "null", ($2).tempvar, -1);
  strcpy(($$).tempvar, tmp.c_str());
  string s;
  if(curr_table->lookup(string((char*)($2).type)).offset!=-1)
  {
    s=curr_table->lookup(string((char*)($2).type)).type;
  }
  else s=($2).type;
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
  else strcpy(($$).type,($2).type);
  
  
  yo="";
  
};
PreDecrementExpression:
MINUSMINUS UnaryExpression {
  string tmp = newtemp();
  emit("-",($2).tempvar,"1",tmp, -1);
  emit("=", tmp, "null", ($2).tempvar, -1);
  strcpy(($$).tempvar, tmp.c_str());
    string s;
  if(curr_table->lookup(string((char*)($2).type)).offset!=-1)
  {
    s=curr_table->lookup(string((char*)($2).type)).type;
  }
  else s=($2).type;
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
  else strcpy(($$).type,($2).type);
  
};
UnaryExpressionNotPlusMinus:
PostfixExpression {
  strcpy(($$).tempvar, ($1).tempvar);
  strcpy(($$).type,($1).type);
}
|TILDA UnaryExpression {
  
  if(invalidoperator(curr_table->lookup(string((char*)($2).type)).type,1) || !strcmp(curr_table->lookup(string((char*)($2).type)).type.c_str() ,"boolean" )){
    cout<<"Invalid TILDA Operator on line "<< yylineno<<"\n";
  }
  string a=newtemp();
  emit("~",($2).tempvar,"null",a.c_str(), -1);
  strcpy(($$).tempvar, a.c_str());
  strcpy(($$).type,($2).type);
  
  
}
|NOT UnaryExpression {
 
   if(strcmp(curr_table->lookup(string((char*)($2).type)).type.c_str() ,"boolean" )){
    cout<<"Invalid NOT Operator on line "<< yylineno<<"\n";
  }
  string a=newtemp();
  emit("!",($2).tempvar,"null",($$).tempvar, -1);
   strcpy(($$).tempvar, a.c_str());
  strcpy(($$).type,($2).type);
  
  
}
|CastExpression {
  strcpy(($$).tempvar, ($1).tempvar);
  strcpy(($$).type,($1).type);
  
};
CastExpression:
OPENBRACKET PrimitiveType Dims CLOSEBRACKET UnaryExpression {
  string casttp= "cast_to_" + string((char*)($2).tempvar) + string((char*)($3).tempvar);
  strcpy(($$).tempvar, newtemp().c_str());
  emit("=",casttp, ($5).tempvar, ($$).tempvar, -1);
  casttype=($2).type;
  for(int i=0;i<($3).ndim;i++)
  {
    casttype+="[]";
  }
  strcpy(($$).type,casttype.c_str());
  casttype="";
  if(curr_table->lookup(string((char*)($5).type)).offset == -1)
  {
    if(invalidoperator(($5).type,0))
    {
      cout<<"Invalid type cast on line from "<<($5).type<<" on line "<<yylineno<<'\n';
    }
  }
  else
  {
    if(invalidoperator(curr_table->lookup(string((char*)($5).type)).type,0))
    {
      cout<<"Invalid type cast on line from "<<curr_table->lookup(string((char*)($5).type)).type<<" on line "<<yylineno<<'\n';
    }
  }
}
|OPENBRACKET PrimitiveType CLOSEBRACKET UnaryExpression {
  string casttp= "cast_to_" + string((char*)($2).tempvar);
  strcpy(($$).tempvar, newtemp().c_str());
  emit("=",casttp, ($4).tempvar, ($$).tempvar, -1);
  
  if(curr_table->lookup(string((char*)($4).type)).offset == -1)
  {
    if(invalidoperator(($4).type,0))
    {
      cout<<"Invalid type cast on line from "<<($4).type<<" on line "<<yylineno<<'\n';
    }
  }
  else
  {
    if(invalidoperator(curr_table->lookup(string((char*)($4).type)).type,0))
    {
      cout<<"Invalid type cast on line from "<<curr_table->lookup(string((char*)($4).type)).type<<" on line "<<yylineno<<'\n';
    }
  }
  strcpy(($$).type,($2).type);
  
  
}
|OPENBRACKET Expression CLOSEBRACKET UnaryExpressionNotPlusMinus {
  string casttp= "cast_to_" + string((char*)($2).tempvar);
  strcpy(($$).tempvar, newtemp().c_str());
  emit("=",casttp, ($4).tempvar, ($$).tempvar, -1);
  
   if(curr_table->lookup(string((char*)($4).type)).offset == -1)
  {
    if(invalidoperator(($4).type,0))
    {
      cout<<"Invalid type cast on line from "<<($4).type<<" on line "<<yylineno<<'\n';
    }
  }
  else
  {
    if(invalidoperator(curr_table->lookup(string((char*)($4).type)).type,0))
    {
      cout<<"Invalid type cast on line from "<<curr_table->lookup(string((char*)($4).type)).type<<" on line "<<yylineno<<'\n';
    }
  }
  strcpy(($$).type,($2).type);
  
  
}
|OPENBRACKET Name Dims CLOSEBRACKET UnaryExpressionNotPlusMinus {
  string casttp= "cast_to_" + string((char*)($2).tempvar) + string((char*)($3).tempvar);
  strcpy(($$).tempvar, newtemp().c_str());
  emit("=",casttp, ($5).tempvar, ($$).tempvar, -1);
  
  strcpy(($$).type,($2).type);
  if(curr_table->lookup(string((char*)($2).type)).offset == -1 && checkobj(string((char*)($2).type)) == 0){
    cout<<"Undeclared variable on line "<< yylineno<<"\n";
  }
  casttype=($2).type;
  for(int i=0;i<($3).ndim;i++)
  {
    casttype+="[]";
  }
  strcpy(($$).type,casttype.c_str());
  casttype="";
   if(curr_table->lookup(string((char*)($5).type)).offset == -1)
  {
    if(invalidoperator(($5).type,0))
    {
      cout<<"Invalid type cast on line from "<<($5).type<<" on line "<<yylineno<<'\n';
    }
  }
  else
  {
    if(invalidoperator(curr_table->lookup(string((char*)($5).type)).type,0))
    {
      cout<<"Invalid type cast on line from "<<curr_table->lookup(string((char*)($5).type)).type<<" on line "<<yylineno<<'\n';
    }
  }
};
MultiplicativeExpression:
UnaryExpression {
  strcpy(($$).tempvar, ($1).tempvar);
  ($$).ndim=($1).ndim;
  if(curr_table->lookup(string((char*)($1).type)).offset != -1)
  {
    strcpy(($$).type,curr_table->lookup(string((char*)($1).type)).type.c_str());
  }
  else
  {
    strcpy(($$).type,($1).type);
  }
}
|MultiplicativeExpression STAR UnaryExpression {

  // strcpy(($$).tempvar, newtemp().c_str());
  // emit("*",($1).tempvar,($3).tempvar,($$).tempvar, -1);


 if(curr_table->lookup(string((char*)($1).type)).offset == -1&&curr_table->lookup(string((char*)($3).type)).offset == -1)
  {
    strcpy(($$).type,getorder(($1).type,($3).type,1).c_str());
    if(strcmp(($1).type,($3).type))
    {
    if(strcmp(getorder(($1).type,($3).type,1).c_str(),($1).type))//means 3 is bigger
    {
      //cout<<(getorder(($1).type,($3).type,1).c_str())<<" "<<($3).type<<'\n';
      string a=newtemp();
      string b=string("cast_to_")+string(($3).type);
      string c=string("*")+string(($3).type);
      emit("=",b.c_str(),($1).tempvar,a.c_str(), -1);
      strcpy(($$).tempvar, newtemp().c_str());
      emit(c.c_str(),a.c_str(),($3).tempvar,($$).tempvar, -1);
    }
    else
    {
      string a=newtemp();
      string b=string("cast_to_")+string(($1).type);
      string c=string("*")+string(($1).type);
      emit("=",b.c_str(),($3).tempvar,a.c_str(), -1);
      strcpy(($$).tempvar, newtemp().c_str());
      emit(c.c_str(),($1).tempvar,a.c_str(),($$).tempvar, -1);
    }
    }
    else{
      string c=string("*")+string(($1).type);
      strcpy(($$).tempvar, newtemp().c_str());
      emit(c.c_str(),($1).tempvar,($3).tempvar,($$).tempvar, -1);
    }
  }
  else if(curr_table->lookup(string((char*)($1).type)).offset == -1&&curr_table->lookup(string((char*)($3).type)).offset != -1)
  {
    strcpy(($$).type,getorder(($1).type,curr_table->lookup(string((char*)($3).type)).type.c_str(),1).c_str());
    if(strcmp(($1).type,curr_table->lookup(string((char*)($3).type)).type.c_str()))
    {
    if(strcmp(getorder(($1).type,curr_table->lookup(string((char*)($3).type)).type.c_str(),1).c_str(),($1).type))//means 3 is bigger
    {
      //cout<<(getorder(($1).type,($3).type,1).c_str())<<" "<<($3).type<<'\n';
      string a=newtemp();
      string b=string("cast_to_")+string(curr_table->lookup(string((char*)($3).type)).type.c_str());
      // string c=string(curr_table->lookup(string((char*)($3).type)).type.c_str())+string(" ")+string(($3).tempvar);
      string c=string("*")+string(curr_table->lookup(string((char*)($3).type)).type.c_str());
      emit("=",b.c_str(),($1).tempvar,a.c_str(), -1);
      strcpy(($$).tempvar, newtemp().c_str());
      // emit("*",a.c_str(),c.c_str(),($$).tempvar, -1);
      emit(c.c_str(),a.c_str(),($3).tempvar,($$).tempvar, -1);
    }
    else
    {
      string a=newtemp();
      string b=string("cast_to_")+string(($1).type);
      // string c=string(($1).type)+string(" ")+string(($1).tempvar);
      string c=string("*")+string(($1).type);
      emit("=",b.c_str(),($3).tempvar,a.c_str(), -1);
      strcpy(($$).tempvar, newtemp().c_str());
      // emit("*",c.c_str(),a.c_str(),($$).tempvar, -1);
      emit(c.c_str(),($1).tempvar,a.c_str(),($$).tempvar, -1);
    }
    }
    else{
      string c=string("*")+string(($1).type);
      strcpy(($$).tempvar, newtemp().c_str());
      emit(c.c_str(),($1).tempvar,($3).tempvar,($$).tempvar, -1);
    }
  }
  else if(curr_table->lookup(string((char*)($3).type)).offset != -1&&curr_table->lookup(string((char*)($1).type)).offset != -1)
  {
    strcpy(($$).type,getorder(curr_table->lookup(string((char*)($3).type)).type.c_str(),curr_table->lookup(string((char*)($1).type)).type.c_str(),1).c_str());
    if(strcmp(curr_table->lookup(string((char*)($3).type)).type.c_str(),curr_table->lookup(string((char*)($1).type)).type.c_str()))
    {
    if(strcmp(getorder(curr_table->lookup(string((char*)($3).type)).type.c_str(),curr_table->lookup(string((char*)($1).type)).type.c_str(),1).c_str(),curr_table->lookup(string((char*)($1).type)).type.c_str()))//means 3 is bigger
    {
      //cout<<(getorder(($1).type,($3).type,1).c_str())<<" "<<($3).type<<'\n';
      string a=newtemp();
      string b=string("cast_to_")+string(curr_table->lookup(string((char*)($3).type)).type.c_str());
      // string c=string(curr_table->lookup(string((char*)($3).type)).type.c_str())+string(" ")+string(($3).tempvar);
      string c=string("*")+string(curr_table->lookup(string((char*)($3).type)).type.c_str());
      emit("=",b.c_str(),($1).tempvar,a.c_str(), -1);
      strcpy(($$).tempvar, newtemp().c_str());
      // emit("*",a.c_str(),c.c_str(),($$).tempvar, -1);
      emit(c.c_str(),a.c_str(),($3).tempvar,($$).tempvar, -1);
    }
    else
    {
      string a=newtemp();
      string b=string("cast_to_")+string(curr_table->lookup(string((char*)($1).type)).type.c_str());
      // string c=string(curr_table->lookup(string((char*)($1).type)).type.c_str())+string(" ")+string(($1).tempvar);
      string c=string("*")+string(curr_table->lookup(string((char*)($1).type)).type.c_str());
      emit("=",b.c_str(),($3).tempvar,a.c_str(), -1);
      strcpy(($$).tempvar, newtemp().c_str());
      // emit("*",c.c_str(),a.c_str(),($$).tempvar, -1);
      emit(c.c_str(),($1).tempvar,a.c_str(),($$).tempvar, -1);
    }
  }
  else{
      string c=string("*")+string(($1).type);
      strcpy(($$).tempvar, newtemp().c_str());
      emit(c.c_str(),($1).tempvar,($3).tempvar,($$).tempvar, -1);
    }
  }
  else
  {
    strcpy(($$).type,getorder(($3).type,curr_table->lookup(string((char*)($1).type)).type.c_str(),1).c_str());
    if(strcmp(($3).type,curr_table->lookup(string((char*)($1).type)).type.c_str()))
    {
    if(strcmp(getorder(($3).type,curr_table->lookup(string((char*)($1).type)).type.c_str(),1).c_str(),($3).type))//means 3 is bigger
    {
      //cout<<(getorder(($1).type,($3).type,1).c_str())<<" "<<($3).type<<'\n';
      string a=newtemp();
      string b=string("cast_to_")+string(curr_table->lookup(string((char*)($1).type)).type.c_str());
      // string c=string(curr_table->lookup(string((char*)($1).type)).type.c_str())+string(" ")+string(($1).tempvar);
      string c=string("*")+string(curr_table->lookup(string((char*)($1).type)).type.c_str());
      emit("=",b.c_str(),($3).tempvar,a.c_str(), -1);
      strcpy(($$).tempvar, newtemp().c_str());
      // emit("*",c.c_str(),a.c_str(),($$).tempvar, -1);
      emit(c.c_str(),($1).tempvar,a.c_str(),($$).tempvar, -1);
    }
    else
    {
      string a=newtemp();
      string b=string("cast_to_")+string(($3).type);
      // string c=string(($3).type)+string(" ")+string(($3).tempvar);
      string c=string("*")+string(($3).type);
      emit("=",b.c_str(),($1).tempvar,a.c_str(), -1);
      strcpy(($$).tempvar, newtemp().c_str());
      // emit("*",a.c_str(),c.c_str(),($$).tempvar, -1);
      emit(c.c_str(),a.c_str(),($3).tempvar,($$).tempvar, -1);
    }
    }
    else{
      string c=string("*")+string(($1).type);
      strcpy(($$).tempvar, newtemp().c_str());
      emit(c.c_str(),($1).tempvar,($3).tempvar,($$).tempvar, -1);
    }
  }

  
}
|MultiplicativeExpression FORWARDSLASH UnaryExpression {

  // strcpy(($$).tempvar, newtemp().c_str());
  // emit("/",($1).tempvar,($3).tempvar,($$).tempvar, -1);

//  strcpy(($$).type,getorder(($1).type,($3).type,1).c_str());
 if(curr_table->lookup(string((char*)($1).type)).offset == -1&&curr_table->lookup(string((char*)($3).type)).offset == -1)
  {
    strcpy(($$).type,getorder(($1).type,($3).type,1).c_str());
    if(strcmp(($1).type,($3).type))
    {
    if(strcmp(getorder(($1).type,($3).type,1).c_str(),($1).type))//means 3 is bigger
    {
      //cout<<(getorder(($1).type,($3).type,1).c_str())<<" "<<($3).type<<'\n';
      string a=newtemp();
      string b=string("cast_to_")+string(($3).type);
      string c=string("/")+string(($3).type);
      emit("=",b.c_str(),($1).tempvar,a.c_str(), -1);
      strcpy(($$).tempvar, newtemp().c_str());
      emit(c.c_str(),a.c_str(),($3).tempvar,($$).tempvar, -1);
    }
    else
    {
      string a=newtemp();
      string b=string("cast_to_")+string(($1).type);
      string c=string("/")+string(($1).type);
      emit("=",b.c_str(),($3).tempvar,a.c_str(), -1);
      strcpy(($$).tempvar, newtemp().c_str());
      emit(c.c_str(),($1).tempvar,a.c_str(),($$).tempvar, -1);
    }
    }
    else{
      string c=string("/")+string(($1).type);
      strcpy(($$).tempvar, newtemp().c_str());
      emit(c.c_str(),($1).tempvar,($3).tempvar,($$).tempvar, -1);
    }
  }
  else if(curr_table->lookup(string((char*)($1).type)).offset == -1&&curr_table->lookup(string((char*)($3).type)).offset != -1)
  {
    strcpy(($$).type,getorder(($1).type,curr_table->lookup(string((char*)($3).type)).type.c_str(),1).c_str());
    if(strcmp(($1).type,curr_table->lookup(string((char*)($3).type)).type.c_str()))
    {
    if(strcmp(getorder(($1).type,curr_table->lookup(string((char*)($3).type)).type.c_str(),1).c_str(),($1).type))//means 3 is bigger
    {
      //cout<<(getorder(($1).type,($3).type,1).c_str())<<" "<<($3).type<<'\n';
      string a=newtemp();
      string b=string("cast_to_")+string(curr_table->lookup(string((char*)($3).type)).type.c_str());
      // string c=string(curr_table->lookup(string((char*)($3).type)).type.c_str())+string(" ")+string(($3).tempvar);
      string c=string("/")+string(curr_table->lookup(string((char*)($3).type)).type.c_str());
      emit("=",b.c_str(),($1).tempvar,a.c_str(), -1);
      strcpy(($$).tempvar, newtemp().c_str());
      // emit("*",a.c_str(),c.c_str(),($$).tempvar, -1);
      emit(c.c_str(),a.c_str(),($3).tempvar,($$).tempvar, -1);
    }
    else
    {
      string a=newtemp();
      string b=string("cast_to_")+string(($1).type);
      // string c=string(($1).type)+string(" ")+string(($1).tempvar);
      string c=string("/")+string(($1).type);
      emit("=",b.c_str(),($3).tempvar,a.c_str(), -1);
      strcpy(($$).tempvar, newtemp().c_str());
      // emit("*",c.c_str(),a.c_str(),($$).tempvar, -1);
      emit(c.c_str(),($1).tempvar,a.c_str(),($$).tempvar, -1);
    }
    }
    else{
      string c=string("/")+string(($1).type);
      strcpy(($$).tempvar, newtemp().c_str());
      emit(c.c_str(),($1).tempvar,($3).tempvar,($$).tempvar, -1);
    }
  }
  else if(curr_table->lookup(string((char*)($3).type)).offset != -1&&curr_table->lookup(string((char*)($1).type)).offset != -1)
  {
    strcpy(($$).type,getorder(curr_table->lookup(string((char*)($3).type)).type.c_str(),curr_table->lookup(string((char*)($1).type)).type.c_str(),1).c_str());
    if(strcmp(curr_table->lookup(string((char*)($3).type)).type.c_str(),curr_table->lookup(string((char*)($1).type)).type.c_str()))
    {
    if(strcmp(getorder(curr_table->lookup(string((char*)($3).type)).type.c_str(),curr_table->lookup(string((char*)($1).type)).type.c_str(),1).c_str(),curr_table->lookup(string((char*)($1).type)).type.c_str()))//means 3 is bigger
    {
      //cout<<(getorder(($1).type,($3).type,1).c_str())<<" "<<($3).type<<'\n';
      string a=newtemp();
      string b=string("cast_to_")+string(curr_table->lookup(string((char*)($3).type)).type.c_str());
      // string c=string(curr_table->lookup(string((char*)($3).type)).type.c_str())+string(" ")+string(($3).tempvar);
      string c=string("/")+string(curr_table->lookup(string((char*)($3).type)).type.c_str());
      emit("=",b.c_str(),($1).tempvar,a.c_str(), -1);
      strcpy(($$).tempvar, newtemp().c_str());
      // emit("*",a.c_str(),c.c_str(),($$).tempvar, -1);
      emit(c.c_str(),a.c_str(),($3).tempvar,($$).tempvar, -1);
    }
    else
    {
      string a=newtemp();
      string b=string("cast_to_")+string(curr_table->lookup(string((char*)($1).type)).type.c_str());
      // string c=string(curr_table->lookup(string((char*)($1).type)).type.c_str())+string(" ")+string(($1).tempvar);
      string c=string("/")+string(curr_table->lookup(string((char*)($1).type)).type.c_str());
      emit("=",b.c_str(),($3).tempvar,a.c_str(), -1);
      strcpy(($$).tempvar, newtemp().c_str());
      // emit("*",c.c_str(),a.c_str(),($$).tempvar, -1);
      emit(c.c_str(),($1).tempvar,a.c_str(),($$).tempvar, -1);
    }
    }
    else{
      string c=string("/")+string(($1).type);
      strcpy(($$).tempvar, newtemp().c_str());
      emit(c.c_str(),($1).tempvar,($3).tempvar,($$).tempvar, -1);
    }
  }
  else
  {
    strcpy(($$).type,getorder(($3).type,curr_table->lookup(string((char*)($1).type)).type.c_str(),1).c_str());
    if(strcmp(($3).type,curr_table->lookup(string((char*)($1).type)).type.c_str()))
    {
    if(strcmp(getorder(($3).type,curr_table->lookup(string((char*)($1).type)).type.c_str(),1).c_str(),($3).type))//means 3 is bigger
    {
      //cout<<(getorder(($1).type,($3).type,1).c_str())<<" "<<($3).type<<'\n';
      string a=newtemp();
      string b=string("cast_to_")+string(curr_table->lookup(string((char*)($1).type)).type.c_str());
      // string c=string(curr_table->lookup(string((char*)($1).type)).type.c_str())+string(" ")+string(($1).tempvar);
      string c=string("/")+string(curr_table->lookup(string((char*)($1).type)).type.c_str());
      emit("=",b.c_str(),($3).tempvar,a.c_str(), -1);
      strcpy(($$).tempvar, newtemp().c_str());
      // emit("*",c.c_str(),a.c_str(),($$).tempvar, -1);
      emit(c.c_str(),($1).tempvar,a.c_str(),($$).tempvar, -1);
    }
    else
    {
      string a=newtemp();
      string b=string("cast_to_")+string(($3).type);
      // string c=string(($3).type)+string(" ")+string(($3).tempvar);
      string c=string("/")+string(($3).type);
      emit("=",b.c_str(),($1).tempvar,a.c_str(), -1);
      strcpy(($$).tempvar, newtemp().c_str());
      // emit("*",a.c_str(),c.c_str(),($$).tempvar, -1);
      emit(c.c_str(),a.c_str(),($3).tempvar,($$).tempvar, -1);
    }
    }
    else{
      string c=string("/")+string(($1).type);
      strcpy(($$).tempvar, newtemp().c_str());
      emit(c.c_str(),($1).tempvar,($3).tempvar,($$).tempvar, -1);
    }
}
}
|MultiplicativeExpression MODULO UnaryExpression {
//   strcpy(($$).tempvar, newtemp().c_str());
//   emit("%",($1).tempvar,($3).tempvar,($$).tempvar, -1);

//  strcpy(($$).type,getorder(($1).type,($3).type,0).c_str());
if(curr_table->lookup(string((char*)($1).type)).offset == -1&&curr_table->lookup(string((char*)($3).type)).offset == -1)
  {
    strcpy(($$).type,getorder(($1).type,($3).type,1).c_str());
    if(strcmp(($1).type,($3).type))
    {
    if(strcmp(getorder(($1).type,($3).type,1).c_str(),($1).type))//means 3 is bigger
    {
      //cout<<(getorder(($1).type,($3).type,1).c_str())<<" "<<($3).type<<'\n';
      string a=newtemp();
      string b=string("cast_to_")+string(($3).type);
      string c=string("%")+string(($3).type);
      emit("=",b.c_str(),($1).tempvar,a.c_str(), -1);
      strcpy(($$).tempvar, newtemp().c_str());
      emit(c.c_str(),a.c_str(),($3).tempvar,($$).tempvar, -1);
    }
    else
    {
      string a=newtemp();
      string b=string("cast_to_")+string(($1).type);
      string c=string("%")+string(($1).type);
      emit("=",b.c_str(),($3).tempvar,a.c_str(), -1);
      strcpy(($$).tempvar, newtemp().c_str());
      emit(c.c_str(),($1).tempvar,a.c_str(),($$).tempvar, -1);
    }
    }
    else{
      string c=string("%")+string(($1).type);
      strcpy(($$).tempvar, newtemp().c_str());
      emit(c.c_str(),($1).tempvar,($3).tempvar,($$).tempvar, -1);
    }
  }
  else if(curr_table->lookup(string((char*)($1).type)).offset == -1&&curr_table->lookup(string((char*)($3).type)).offset != -1)
  {
    strcpy(($$).type,getorder(($1).type,curr_table->lookup(string((char*)($3).type)).type.c_str(),1).c_str());
    if(strcmp(($1).type,curr_table->lookup(string((char*)($3).type)).type.c_str()))
    {
    if(strcmp(getorder(($1).type,curr_table->lookup(string((char*)($3).type)).type.c_str(),1).c_str(),($1).type))//means 3 is bigger
    {
      //cout<<(getorder(($1).type,($3).type,1).c_str())<<" "<<($3).type<<'\n';
      string a=newtemp();
      string b=string("cast_to_")+string(curr_table->lookup(string((char*)($3).type)).type.c_str());
      // string c=string(curr_table->lookup(string((char*)($3).type)).type.c_str())+string(" ")+string(($3).tempvar);
      string c=string("%")+string(curr_table->lookup(string((char*)($3).type)).type.c_str());
      emit("=",b.c_str(),($1).tempvar,a.c_str(), -1);
      strcpy(($$).tempvar, newtemp().c_str());
      // emit("*",a.c_str(),c.c_str(),($$).tempvar, -1);
      emit(c.c_str(),a.c_str(),($3).tempvar,($$).tempvar, -1);
    }
    else
    {
      string a=newtemp();
      string b=string("cast_to_")+string(($1).type);
      // string c=string(($1).type)+string(" ")+string(($1).tempvar);
      string c=string("%")+string(($1).type);
      emit("=",b.c_str(),($3).tempvar,a.c_str(), -1);
      strcpy(($$).tempvar, newtemp().c_str());
      // emit("*",c.c_str(),a.c_str(),($$).tempvar, -1);
      emit(c.c_str(),($1).tempvar,a.c_str(),($$).tempvar, -1);
    }
    }
    else{
      string c=string("%")+string(($1).type);
      strcpy(($$).tempvar, newtemp().c_str());
      emit(c.c_str(),($1).tempvar,($3).tempvar,($$).tempvar, -1);
    }
  }
  else if(curr_table->lookup(string((char*)($3).type)).offset != -1&&curr_table->lookup(string((char*)($1).type)).offset != -1)
  {
    strcpy(($$).type,getorder(curr_table->lookup(string((char*)($3).type)).type.c_str(),curr_table->lookup(string((char*)($1).type)).type.c_str(),1).c_str());
    if(strcmp(curr_table->lookup(string((char*)($3).type)).type.c_str(),curr_table->lookup(string((char*)($1).type)).type.c_str()))
    {
    if(strcmp(getorder(curr_table->lookup(string((char*)($3).type)).type.c_str(),curr_table->lookup(string((char*)($1).type)).type.c_str(),1).c_str(),curr_table->lookup(string((char*)($1).type)).type.c_str()))//means 3 is bigger
    {
      //cout<<(getorder(($1).type,($3).type,1).c_str())<<" "<<($3).type<<'\n';
      string a=newtemp();
      string b=string("cast_to_")+string(curr_table->lookup(string((char*)($3).type)).type.c_str());
      // string c=string(curr_table->lookup(string((char*)($3).type)).type.c_str())+string(" ")+string(($3).tempvar);
      string c=string("%")+string(curr_table->lookup(string((char*)($3).type)).type.c_str());
      emit("=",b.c_str(),($1).tempvar,a.c_str(), -1);
      strcpy(($$).tempvar, newtemp().c_str());
      // emit("*",a.c_str(),c.c_str(),($$).tempvar, -1);
      emit(c.c_str(),a.c_str(),($3).tempvar,($$).tempvar, -1);
    }
    else
    {
      string a=newtemp();
      string b=string("cast_to_")+string(curr_table->lookup(string((char*)($1).type)).type.c_str());
      // string c=string(curr_table->lookup(string((char*)($1).type)).type.c_str())+string(" ")+string(($1).tempvar);
      string c=string("%")+string(curr_table->lookup(string((char*)($1).type)).type.c_str());
      emit("=",b.c_str(),($3).tempvar,a.c_str(), -1);
      strcpy(($$).tempvar, newtemp().c_str());
      // emit("*",c.c_str(),a.c_str(),($$).tempvar, -1);
      emit(c.c_str(),($1).tempvar,a.c_str(),($$).tempvar, -1);
    }
    }
    else{
      string c=string("%")+string(($1).type);
      strcpy(($$).tempvar, newtemp().c_str());
      emit(c.c_str(),($1).tempvar,($3).tempvar,($$).tempvar, -1);
    }
  }
  else
  {
    strcpy(($$).type,getorder(($3).type,curr_table->lookup(string((char*)($1).type)).type.c_str(),1).c_str());
    if(strcmp(($3).type,curr_table->lookup(string((char*)($1).type)).type.c_str()))
    {
    if(strcmp(getorder(($3).type,curr_table->lookup(string((char*)($1).type)).type.c_str(),1).c_str(),($3).type))//means 3 is bigger
    {
      //cout<<(getorder(($1).type,($3).type,1).c_str())<<" "<<($3).type<<'\n';
      string a=newtemp();
      string b=string("cast_to_")+string(curr_table->lookup(string((char*)($1).type)).type.c_str());
      // string c=string(curr_table->lookup(string((char*)($1).type)).type.c_str())+string(" ")+string(($1).tempvar);
      string c=string("%")+string(curr_table->lookup(string((char*)($1).type)).type.c_str());
      emit("=",b.c_str(),($3).tempvar,a.c_str(), -1);
      strcpy(($$).tempvar, newtemp().c_str());
      // emit("*",c.c_str(),a.c_str(),($$).tempvar, -1);
      emit(c.c_str(),($1).tempvar,a.c_str(),($$).tempvar, -1);
    }
    else
    {
      string a=newtemp();
      string b=string("cast_to_")+string(($3).type);
      // string c=string(($3).type)+string(" ")+string(($3).tempvar);
      string c=string("%")+string(($3).type);
      emit("=",b.c_str(),($1).tempvar,a.c_str(), -1);
      strcpy(($$).tempvar, newtemp().c_str());
      // emit("*",a.c_str(),c.c_str(),($$).tempvar, -1);
      emit(c.c_str(),a.c_str(),($3).tempvar,($$).tempvar, -1);
    }
    }
    else{
      string c=string("%")+string(($1).type);
      strcpy(($$).tempvar, newtemp().c_str());
      emit(c.c_str(),($1).tempvar,($3).tempvar,($$).tempvar, -1);
    }
}
};
AdditiveExpression:
MultiplicativeExpression {
  strcpy(($$).tempvar, ($1).tempvar);

  ($$).ndim=($1).ndim;
  strcpy(($$).type,($1).type);
}
|AdditiveExpression PLUS MultiplicativeExpression {
  // strcpy(($$).tempvar, newtemp().c_str());
  // emit("+",($1).tempvar,($3).tempvar,($$).tempvar, -1);
  

 if(curr_table->lookup(string((char*)($1).type)).offset == -1&&curr_table->lookup(string((char*)($3).type)).offset == -1)
  {
    strcpy(($$).type,getorder(($1).type,($3).type,1).c_str());
    if(strcmp(($1).type,($3).type))
    {
    if(strcmp(getorder(($1).type,($3).type,1).c_str(),($1).type))//means 3 is bigger
    {
      //cout<<(getorder(($1).type,($3).type,1).c_str())<<" "<<($3).type<<'\n';
      string a=newtemp();
      string b=string("cast_to_")+string(($3).type);
      string c=string("+")+string(($3).type);
      emit("=",b.c_str(),($1).tempvar,a.c_str(), -1);
      strcpy(($$).tempvar, newtemp().c_str());
      emit(c.c_str(),a.c_str(),($3).tempvar,($$).tempvar, -1);
    }
    else
    {
      string a=newtemp();
      string b=string("cast_to_")+string(($1).type);
      string c=string("+")+string(($1).type);
      emit("=",b.c_str(),($3).tempvar,a.c_str(), -1);
      strcpy(($$).tempvar, newtemp().c_str());
      emit(c.c_str(),($1).tempvar,a.c_str(),($$).tempvar, -1);
    }
    }
    else{
      string c=string("+")+string(($1).type);
      strcpy(($$).tempvar, newtemp().c_str());
      emit(c.c_str(),($1).tempvar,($3).tempvar,($$).tempvar, -1);
    }
  }
  else if(curr_table->lookup(string((char*)($1).type)).offset == -1&&curr_table->lookup(string((char*)($3).type)).offset != -1)
  {
     
    strcpy(($$).type,getorder(($1).type,curr_table->lookup(string((char*)($3).type)).type.c_str(),1).c_str());
    if(strcmp(($1).type,curr_table->lookup(string((char*)($3).type)).type.c_str()))
    {
    if(strcmp(getorder(($1).type,curr_table->lookup(string((char*)($3).type)).type.c_str(),1).c_str(),($1).type))//means 3 is bigger
    {
      //cout<<(getorder(($1).type,($3).type,1).c_str())<<" "<<($3).type<<'\n';
      string a=newtemp();
      string b=string("cast_to_")+string(curr_table->lookup(string((char*)($3).type)).type.c_str());
      // string c=string(curr_table->lookup(string((char*)($3).type)).type.c_str())+string(" ")+string(($3).tempvar);
      string c=string("+")+string(curr_table->lookup(string((char*)($3).type)).type.c_str());
      emit("=",b.c_str(),($1).tempvar,a.c_str(), -1);
      strcpy(($$).tempvar, newtemp().c_str());
      // emit("*",a.c_str(),c.c_str(),($$).tempvar, -1);
      emit(c.c_str(),a.c_str(),($3).tempvar,($$).tempvar, -1);
    }
    else
    {
      string a=newtemp();
      string b=string("cast_to_")+string(($1).type);
      // string c=string(($1).type)+string(" ")+string(($1).tempvar);
      string c=string("+")+string(($1).type);
      emit("=",b.c_str(),($3).tempvar,a.c_str(), -1);
      strcpy(($$).tempvar, newtemp().c_str());
      // emit("*",c.c_str(),a.c_str(),($$).tempvar, -1);
      emit(c.c_str(),($1).tempvar,a.c_str(),($$).tempvar, -1);
    }
    }
    else{
      string c=string("+")+string(($1).type);
      strcpy(($$).tempvar, newtemp().c_str());
      emit(c.c_str(),($1).tempvar,($3).tempvar,($$).tempvar, -1);
    }
  }
  else if(curr_table->lookup(string((char*)($3).type)).offset != -1&&curr_table->lookup(string((char*)($1).type)).offset != -1)
  {
    
    strcpy(($$).type,getorder(curr_table->lookup(string((char*)($3).type)).type.c_str(),curr_table->lookup(string((char*)($1).type)).type.c_str(),1).c_str());
    if(strcmp(curr_table->lookup(string((char*)($3).type)).type.c_str(),curr_table->lookup(string((char*)($1).type)).type.c_str()))
    {
    if(strcmp(getorder(curr_table->lookup(string((char*)($3).type)).type.c_str(),curr_table->lookup(string((char*)($1).type)).type.c_str(),1).c_str(),curr_table->lookup(string((char*)($1).type)).type.c_str()))//means 3 is bigger
    {
      //cout<<(getorder(($1).type,($3).type,1).c_str())<<" "<<($3).type<<'\n';
      string a=newtemp();
      string b=string("cast_to_")+string(curr_table->lookup(string((char*)($3).type)).type.c_str());
      // string c=string(curr_table->lookup(string((char*)($3).type)).type.c_str())+string(" ")+string(($3).tempvar);
      string c=string("+")+string(curr_table->lookup(string((char*)($3).type)).type.c_str());
      emit("=",b.c_str(),($1).tempvar,a.c_str(), -1);
      strcpy(($$).tempvar, newtemp().c_str());
      // emit("*",a.c_str(),c.c_str(),($$).tempvar, -1);
      emit(c.c_str(),a.c_str(),($3).tempvar,($$).tempvar, -1);
    }
    else
    {
      string a=newtemp();
      string b=string("cast_to_")+string(curr_table->lookup(string((char*)($1).type)).type.c_str());
      // string c=string(curr_table->lookup(string((char*)($1).type)).type.c_str())+string(" ")+string(($1).tempvar);
      string c=string("+")+string(curr_table->lookup(string((char*)($1).type)).type.c_str());
      emit("=",b.c_str(),($3).tempvar,a.c_str(), -1);
      strcpy(($$).tempvar, newtemp().c_str());
      // emit("*",c.c_str(),a.c_str(),($$).tempvar, -1);
      emit(c.c_str(),($1).tempvar,a.c_str(),($$).tempvar, -1);
    }
    }
    else{
      string c=string("+")+string(($1).type);
      strcpy(($$).tempvar, newtemp().c_str());
      emit(c.c_str(),($1).tempvar,($3).tempvar,($$).tempvar, -1);
    }
  }
  else
  {
    strcpy(($$).type,getorder(($3).type,curr_table->lookup(string((char*)($1).type)).type.c_str(),1).c_str());
    if(strcmp(($3).type,curr_table->lookup(string((char*)($1).type)).type.c_str()))
    {
    if(strcmp(getorder(($3).type,curr_table->lookup(string((char*)($1).type)).type.c_str(),1).c_str(),($3).type))//means 3 is bigger
    {
      //cout<<(getorder(($1).type,($3).type,1).c_str())<<" "<<($3).type<<'\n';
      string a=newtemp();
      string b=string("cast_to_")+string(curr_table->lookup(string((char*)($1).type)).type.c_str());
      // string c=string(curr_table->lookup(string((char*)($1).type)).type.c_str())+string(" ")+string(($1).tempvar);
      string c=string("+")+string(curr_table->lookup(string((char*)($1).type)).type.c_str());
      emit("=",b.c_str(),($3).tempvar,a.c_str(), -1);
      strcpy(($$).tempvar, newtemp().c_str());
      // emit("*",c.c_str(),a.c_str(),($$).tempvar, -1);
      emit(c.c_str(),($1).tempvar,a.c_str(),($$).tempvar, -1);
    }
    else
    {
      string a=newtemp();
      string b=string("cast_to_")+string(($3).type);
      // string c=string(($3).type)+string(" ")+string(($3).tempvar);
      string c=string("+")+string(($3).type);
      emit("=",b.c_str(),($1).tempvar,a.c_str(), -1);
      strcpy(($$).tempvar, newtemp().c_str());
      // emit("*",a.c_str(),c.c_str(),($$).tempvar, -1);
      emit(c.c_str(),a.c_str(),($3).tempvar,($$).tempvar, -1);
    }
    }
    else{
      string c=string("+")+string(($1).type);
      strcpy(($$).tempvar, newtemp().c_str());
      emit(c.c_str(),($1).tempvar,($3).tempvar,($$).tempvar, -1);
    }
}
}
|AdditiveExpression MINUS MultiplicativeExpression {

  // strcpy(($$).tempvar, newtemp().c_str());
  // emit("-",($1).tempvar,($3).tempvar,($$).tempvar, -1);
  
if(curr_table->lookup(string((char*)($1).type)).offset == -1&&curr_table->lookup(string((char*)($3).type)).offset == -1)
  {
    strcpy(($$).type,getorder(($1).type,($3).type,1).c_str());
    if(strcmp(($1).type,($3).type))
    {
    if(strcmp(getorder(($1).type,($3).type,1).c_str(),($1).type))//means 3 is bigger
    {
      //cout<<(getorder(($1).type,($3).type,1).c_str())<<" "<<($3).type<<'\n';
      string a=newtemp();
      string b=string("cast_to_")+string(($3).type);
      string c=string("-")+string(($3).type);
      emit("=",b.c_str(),($1).tempvar,a.c_str(), -1);
      strcpy(($$).tempvar, newtemp().c_str());
      emit(c.c_str(),a.c_str(),($3).tempvar,($$).tempvar, -1);
    }
    else
    {
      string a=newtemp();
      string b=string("cast_to_")+string(($1).type);
      string c=string("-")+string(($1).type);
      emit("=",b.c_str(),($3).tempvar,a.c_str(), -1);
      strcpy(($$).tempvar, newtemp().c_str());
      emit(c.c_str(),($1).tempvar,a.c_str(),($$).tempvar, -1);
    }
    }
    else{
      string c=string("-")+string(($1).type);
      strcpy(($$).tempvar, newtemp().c_str());
      emit(c.c_str(),($1).tempvar,($3).tempvar,($$).tempvar, -1);
    }
  }
  else if(curr_table->lookup(string((char*)($1).type)).offset == -1&&curr_table->lookup(string((char*)($3).type)).offset != -1)
  {
    strcpy(($$).type,getorder(($1).type,curr_table->lookup(string((char*)($3).type)).type.c_str(),1).c_str());
    if(strcmp(($1).type,curr_table->lookup(string((char*)($3).type)).type.c_str()))
    {
    if(strcmp(getorder(($1).type,curr_table->lookup(string((char*)($3).type)).type.c_str(),1).c_str(),($1).type))//means 3 is bigger
    {
      //cout<<(getorder(($1).type,($3).type,1).c_str())<<" "<<($3).type<<'\n';
      string a=newtemp();
      string b=string("cast_to_")+string(curr_table->lookup(string((char*)($3).type)).type.c_str());
      // string c=string(curr_table->lookup(string((char*)($3).type)).type.c_str())+string(" ")+string(($3).tempvar);
      string c=string("-")+string(curr_table->lookup(string((char*)($3).type)).type.c_str());
      emit("=",b.c_str(),($1).tempvar,a.c_str(), -1);
      strcpy(($$).tempvar, newtemp().c_str());
      // emit("*",a.c_str(),c.c_str(),($$).tempvar, -1);
      emit(c.c_str(),a.c_str(),($3).tempvar,($$).tempvar, -1);
    }
    else
    {
      string a=newtemp();
      string b=string("cast_to_")+string(($1).type);
      // string c=string(($1).type)+string(" ")+string(($1).tempvar);
      string c=string("-")+string(($1).type);
      emit("=",b.c_str(),($3).tempvar,a.c_str(), -1);
      strcpy(($$).tempvar, newtemp().c_str());
      // emit("*",c.c_str(),a.c_str(),($$).tempvar, -1);
      emit(c.c_str(),($1).tempvar,a.c_str(),($$).tempvar, -1);
    }
    }
    else{
      string c=string("-")+string(($1).type);
      strcpy(($$).tempvar, newtemp().c_str());
      emit(c.c_str(),($1).tempvar,($3).tempvar,($$).tempvar, -1);
    }
  }
  else if(curr_table->lookup(string((char*)($3).type)).offset != -1&&curr_table->lookup(string((char*)($1).type)).offset != -1)
  {
    strcpy(($$).type,getorder(curr_table->lookup(string((char*)($3).type)).type.c_str(),curr_table->lookup(string((char*)($1).type)).type.c_str(),1).c_str());
    if(strcmp(curr_table->lookup(string((char*)($3).type)).type.c_str(),curr_table->lookup(string((char*)($1).type)).type.c_str()))
    {
    if(strcmp(getorder(curr_table->lookup(string((char*)($3).type)).type.c_str(),curr_table->lookup(string((char*)($1).type)).type.c_str(),1).c_str(),curr_table->lookup(string((char*)($1).type)).type.c_str()))//means 3 is bigger
    {
      //cout<<(getorder(($1).type,($3).type,1).c_str())<<" "<<($3).type<<'\n';
      string a=newtemp();
      string b=string("cast_to_")+string(curr_table->lookup(string((char*)($3).type)).type.c_str());
      // string c=string(curr_table->lookup(string((char*)($3).type)).type.c_str())+string(" ")+string(($3).tempvar);
      string c=string("-")+string(curr_table->lookup(string((char*)($3).type)).type.c_str());
      emit("=",b.c_str(),($1).tempvar,a.c_str(), -1);
      strcpy(($$).tempvar, newtemp().c_str());
      // emit("*",a.c_str(),c.c_str(),($$).tempvar, -1);
      emit(c.c_str(),a.c_str(),($3).tempvar,($$).tempvar, -1);
    }
    else
    {
      string a=newtemp();
      string b=string("cast_to_")+string(curr_table->lookup(string((char*)($1).type)).type.c_str());
      // string c=string(curr_table->lookup(string((char*)($1).type)).type.c_str())+string(" ")+string(($1).tempvar);
      string c=string("-")+string(curr_table->lookup(string((char*)($1).type)).type.c_str());
      emit("=",b.c_str(),($3).tempvar,a.c_str(), -1);
      strcpy(($$).tempvar, newtemp().c_str());
      // emit("*",c.c_str(),a.c_str(),($$).tempvar, -1);
      emit(c.c_str(),($1).tempvar,a.c_str(),($$).tempvar, -1);
    }
    }
    else{
      string c=string("-")+string(($1).type);
      strcpy(($$).tempvar, newtemp().c_str());
      emit(c.c_str(),($1).tempvar,($3).tempvar,($$).tempvar, -1);
    }
  }
  else
  {
    strcpy(($$).type,getorder(($3).type,curr_table->lookup(string((char*)($1).type)).type.c_str(),1).c_str());
    if(strcmp(($3).type,curr_table->lookup(string((char*)($1).type)).type.c_str()))
    {
    if(strcmp(getorder(($3).type,curr_table->lookup(string((char*)($1).type)).type.c_str(),1).c_str(),($3).type))//means 3 is bigger
    {
      //cout<<(getorder(($1).type,($3).type,1).c_str())<<" "<<($3).type<<'\n';
      string a=newtemp();
      string b=string("cast_to_")+string(curr_table->lookup(string((char*)($1).type)).type.c_str());
      // string c=string(curr_table->lookup(string((char*)($1).type)).type.c_str())+string(" ")+string(($1).tempvar);
      string c=string("-")+string(curr_table->lookup(string((char*)($1).type)).type.c_str());
      emit("=",b.c_str(),($3).tempvar,a.c_str(), -1);
      strcpy(($$).tempvar, newtemp().c_str());
      // emit("*",c.c_str(),a.c_str(),($$).tempvar, -1);
      emit(c.c_str(),($1).tempvar,a.c_str(),($$).tempvar, -1);
    }
    else
    {
      string a=newtemp();
      string b=string("cast_to_")+string(($3).type);
      // string c=string(($3).type)+string(" ")+string(($3).tempvar);
      string c=string("-")+string(($3).type);
      emit("=",b.c_str(),($1).tempvar,a.c_str(), -1);
      strcpy(($$).tempvar, newtemp().c_str());
      // emit("*",a.c_str(),c.c_str(),($$).tempvar, -1);
      emit(c.c_str(),a.c_str(),($3).tempvar,($$).tempvar, -1);
    }
    }
    else{
      string c=string("-")+string(($1).type);
      strcpy(($$).tempvar, newtemp().c_str());
      emit(c.c_str(),($1).tempvar,($3).tempvar,($$).tempvar, -1);
    }
}
};

ShiftExpression:
AdditiveExpression {
  strcpy(($$).tempvar, ($1).tempvar);

  ($$).ndim=($1).ndim;
  strcpy(($$).type,($1).type);
  
}
|ShiftExpression OPENANGULARBRACKETOPENANGULARBRACKET AdditiveExpression {

  strcpy(($$).tempvar, newtemp().c_str());
  emit("<<",($1).tempvar,($3).tempvar,($$).tempvar, -1);

  if(!invalidoperator(($1).type,0))
  {
    if(!strcmp(($3).type,"int"))
    {
      strcpy(($$).type,($1).type);
    }
    else
    {
      cout<<"Invalid shift operator on line "<< yylineno<<"\n";
    }
  }
  else cout<<"Invalid shift operator on line "<< yylineno<<"\n";
//  strcpy(($$).type,getorder(($1).type,($3).type,1).c_str());
}
|ShiftExpression CLOSEANGULARBRACKETCLOSEANGULARBRACKET AdditiveExpression  {
  strcpy(($$).tempvar, newtemp().c_str());
  emit(">>",($1).tempvar,($3).tempvar,($$).tempvar, -1);
 if(!invalidoperator(($1).type,0))
  {

    if(!strcmp(($3).type,"int"))
    {
      strcpy(($$).type,($1).type);
    }
    else
    {
      cout<<"Invalid shift operator on line "<< yylineno<<"\n";
    }
  }
  else cout<<"Invalid shift operator on line "<< yylineno<<"\n";
  
  
  
  
}
|ShiftExpression CLOSEANGULARBRACKETCLOSEANGULARBRACKETCLOSEANGULARBRACKET AdditiveExpression {
  strcpy(($$).tempvar, newtemp().c_str());
  emit("<<<",($1).tempvar,($3).tempvar,($$).tempvar, -1);
 if(!invalidoperator(($1).type,0))
  {
    if(!strcmp(($3).type,"int"))
    {
      strcpy(($$).type,($1).type);
    }
    else
    {
      cout<<"Invalid shift operator on line "<< yylineno<<"\n";
    }
  }
  else cout<<"Invalid shift operator on line "<< yylineno<<"\n";
  
};
RelationalExpression:
ShiftExpression {
  strcpy(($$).tempvar, ($1).tempvar);

  ($$).ndim=($1).ndim;
  strcpy(($$).type,($1).type);
}
|RelationalExpression OPENANGULARBRACKET ShiftExpression {
  // cout<<strcmp(($1).type,"boolean")<<" "<<($3).type<<"yo"<<(!strcmp(($1).type,"boolean")||!strcmp(($3).type,"boolean"))<<'\n';
  
 if(!strcmp(($1).type,"boolean")||!strcmp(($3).type,"boolean"))
  {
    cout<<"Invalid relation comparision operator on line "<< yylineno<<"\n";
  }
  else 
  {
    if(strcmp(getorder(($1).type,($3).type,1).c_str(),($1).type))//means 1 is bigger
    {
      string a=newtemp();
      string b=string("cast_to_")+string(($3).type);
      emit("=",b.c_str(),($1).tempvar,a.c_str(), -1);
      //cout<<(getorder(($1).type,($3).type,1).c_str())<<" "<<($3).type<<'\n';
    }
    if(strcmp(getorder(($1).type,($3).type,1).c_str(),($3).type))//means 1 is bigger
    {
      string a=newtemp();
      string b=string("cast_to_")+string(($1).type);
      emit("=",b.c_str(),($3).tempvar,a.c_str(), -1);
      //cout<<(getorder(($1).type,($3).type,1).c_str())<<" "<<($3).type<<'\n';
    }
    strcpy(($$).type,"boolean");
  }
  strcpy(($$).tempvar, newtemp().c_str());
  emit("<",($1).tempvar,($3).tempvar,($$).tempvar, -1);
  
}
|RelationalExpression CLOSEANGULARBRACKET ShiftExpression {
  // strcpy(($$).tempvar, newtemp().c_str());
  // emit(">",($1).tempvar,($3).tempvar,($$).tempvar, -1);
  
 if(!strcmp(($1).type,"boolean")||!strcmp(($3).type,"boolean"))
  {
    cout<<"Invalid relation comparision operator on line "<< yylineno<<"\n";
  }
  else 
  {
    if(strcmp(getorder(($1).type,($3).type,1).c_str(),($1).type))//means 1 is bigger
    {
      string a=newtemp();
      string b=string("cast_to_")+string(($3).type);
      emit("=",b.c_str(),($1).tempvar,a.c_str(), -1);
      //cout<<(getorder(($1).type,($3).type,1).c_str())<<" "<<($3).type<<'\n';
    }
    if(strcmp(getorder(($1).type,($3).type,1).c_str(),($3).type))//means 1 is bigger
    {
      string a=newtemp();
      string b=string("cast_to_")+string(($1).type);
      emit("=",b.c_str(),($3).tempvar,a.c_str(), -1);
      //cout<<(getorder(($1).type,($3).type,1).c_str())<<" "<<($3).type<<'\n';
    }
    strcpy(($$).type,"boolean");
  }
  strcpy(($$).tempvar, newtemp().c_str());
  emit(">",($1).tempvar,($3).tempvar,($$).tempvar, -1);
  
}
|RelationalExpression OPENANGULARBRACKETEQUAL ShiftExpression {
  // strcpy(($$).tempvar, newtemp().c_str());
  // emit("<=",($1).tempvar,($3).tempvar,($$).tempvar, -1);

 if(!strcmp(($1).type,"boolean")||!strcmp(($3).type,"boolean"))
  {
    cout<<"Invalid relation comparision operator on line "<< yylineno<<"\n";
  }
  else 
  {
    if(strcmp(getorder(($1).type,($3).type,1).c_str(),($1).type))//means 1 is bigger
    {
      string a=newtemp();
      string b=string("cast_to_")+string(($3).type);
      emit("=",b.c_str(),($1).tempvar,a.c_str(), -1);
      //cout<<(getorder(($1).type,($3).type,1).c_str())<<" "<<($3).type<<'\n';
    }
    if(strcmp(getorder(($1).type,($3).type,1).c_str(),($3).type))//means 1 is bigger
    {
      string a=newtemp();
      string b=string("cast_to_")+string(($1).type);
      emit("=",b.c_str(),($3).tempvar,a.c_str(), -1);
      //cout<<(getorder(($1).type,($3).type,1).c_str())<<" "<<($3).type<<'\n';
    }
    strcpy(($$).type,"boolean");
  }
  strcpy(($$).tempvar, newtemp().c_str());
  emit("<=",($1).tempvar,($3).tempvar,($$).tempvar, -1);
}
|RelationalExpression CLOSEANGULARBRACKETEQUAL ShiftExpression {
  // strcpy(($$).tempvar, newtemp().c_str());
  // emit(">=",($1).tempvar,($3).tempvar,($$).tempvar, -1);
  
 if(!strcmp(($1).type,"boolean")||!strcmp(($3).type,"boolean"))
  {
    cout<<"Invalid relation comparision operator on line "<< yylineno<<"\n";
  }
  else 
  {
    if(strcmp(getorder(($1).type,($3).type,1).c_str(),($1).type))//means 1 is bigger
    {
      string a=newtemp();
      string b=string("cast_to_")+string(($3).type);
      emit("=",b.c_str(),($1).tempvar,a.c_str(), -1);
      //cout<<(getorder(($1).type,($3).type,1).c_str())<<" "<<($3).type<<'\n';
    }
    if(strcmp(getorder(($1).type,($3).type,1).c_str(),($3).type))//means 1 is bigger
    {
      string a=newtemp();
      string b=string("cast_to_")+string(($1).type);
      emit("=",b.c_str(),($3).tempvar,a.c_str(), -1);
      //cout<<(getorder(($1).type,($3).type,1).c_str())<<" "<<($3).type<<'\n';
    }
    strcpy(($$).type,"boolean");
  }
  strcpy(($$).tempvar, newtemp().c_str());
  emit(">=",($1).tempvar,($3).tempvar,($$).tempvar, -1);
  
  
}
|RelationalExpression INSTANCEOF ReferenceType {
  
  
};
EqualityExpression:
RelationalExpression {
  
  strcpy(($$).tempvar, ($1).tempvar);

  ($$).ndim=($1).ndim;
  strcpy(($$).type,($1).type);
}
|EqualityExpression EQUALEQUAL RelationalExpression {
  // strcpy(($$).tempvar, newtemp().c_str());
  // emit("==",($1).tempvar,($3).tempvar,($$).tempvar, -1);
  
  if(!strcmp(($1).type,"boolean")||!strcmp(($3).type,"boolean"))
  {
    cout<<"Invalid equality comparision operator on line "<< yylineno<<"\n";
  }
  else 
  {
    if(strcmp(getorder(($1).type,($3).type,1).c_str(),($1).type))//means 1 is bigger
    {
      string a=newtemp();
      string b=string("cast_to_")+string(($3).type);
      emit("=",b.c_str(),($1).tempvar,a.c_str(), -1);
      //cout<<(getorder(($1).type,($3).type,1).c_str())<<" "<<($3).type<<'\n';
    }
    if(strcmp(getorder(($1).type,($3).type,1).c_str(),($3).type))//means 1 is bigger
    {
      string a=newtemp();
      string b=string("cast_to_")+string(($1).type);
      emit("=",b.c_str(),($3).tempvar,a.c_str(), -1);
      //cout<<(getorder(($1).type,($3).type,1).c_str())<<" "<<($3).type<<'\n';
    }
    strcpy(($$).type,"boolean");
  }
  strcpy(($$).tempvar, newtemp().c_str());
  emit("==",($1).tempvar,($3).tempvar,($$).tempvar, -1);
  
  
}
|EqualityExpression NOTEQUAL RelationalExpression {
  // strcpy(($$).tempvar, newtemp().c_str());
  // emit("!=",($1).tempvar,($3).tempvar,($$).tempvar, -1);
  
 if(!strcmp(($1).type,"boolean")||!strcmp(($3).type,"boolean"))
  {
    cout<<"Invalid equality comparision operator on line "<< yylineno<<"\n";
  }
  else 
  {
    if(strcmp(getorder(($1).type,($3).type,1).c_str(),($1).type))//means 1 is bigger
    {
      string a=newtemp();
      string b=string("cast_to_")+string(($3).type);
      emit("=",b.c_str(),($1).tempvar,a.c_str(), -1);
      //cout<<(getorder(($1).type,($3).type,1).c_str())<<" "<<($3).type<<'\n';
    }
    if(strcmp(getorder(($1).type,($3).type,1).c_str(),($3).type))//means 1 is bigger
    {
      string a=newtemp();
      string b=string("cast_to_")+string(($1).type);
      emit("=",b.c_str(),($3).tempvar,a.c_str(), -1);
      //cout<<(getorder(($1).type,($3).type,1).c_str())<<" "<<($3).type<<'\n';
    }
    strcpy(($$).type,"boolean");
  }
  strcpy(($$).tempvar, newtemp().c_str());
  emit("!=",($1).tempvar,($3).tempvar,($$).tempvar, -1);
  
  
};
AndExpression:
EqualityExpression {
  strcpy(($$).tempvar, ($1).tempvar);

  ($$).ndim=($1).ndim;
  strcpy(($$).type,($1).type);
  
}
|AndExpression AND EqualityExpression {
  strcpy(($$).tempvar, newtemp().c_str());
  emit("&",($1).tempvar,($3).tempvar,($$).tempvar, -1);
  
 strcpy(($$).type,getorder(($1).type,($3).type,0).c_str());
  
};
ExclusiveOrExpression:
AndExpression {
  strcpy(($$).tempvar, ($1).tempvar);

  ($$).ndim=($1).ndim;
  strcpy(($$).type,($1).type);
  
}
|ExclusiveOrExpression XOR AndExpression {
  strcpy(($$).tempvar, newtemp().c_str());
  emit("^",($1).tempvar,($3).tempvar,($$).tempvar, -1);
 strcpy(($$).type,getorder(($1).type,($3).type,0).c_str());
  
  
};
InclusiveOrExpression:
ExclusiveOrExpression {
  strcpy(($$).tempvar, ($1).tempvar);

  ($$).ndim=($1).ndim;
  strcpy(($$).type,($1).type);
}
|InclusiveOrExpression OR ExclusiveOrExpression {
  strcpy(($$).tempvar, newtemp().c_str());
  emit("|",($1).tempvar,($3).tempvar,($$).tempvar, -1);
  
 strcpy(($$).type,getorder(($1).type,($3).type,0).c_str());

};
ConditionalAndExpression:
InclusiveOrExpression {
  strcpy(($$).tempvar, ($1).tempvar);

  ($$).ndim=($1).ndim;
   strcpy(($$).type,($1).type);
}
|ConditionalAndExpression ANDAND InclusiveOrExpression {
  strcpy(($$).tempvar, newtemp().c_str());
  emit("&&",($1).tempvar,($3).tempvar,($$).tempvar, -1);
  
  strcpy(($$).type,"boolean");
  
  
};
ConditionalOrExpression:
ConditionalAndExpression {
  strcpy(($$).tempvar, ($1).tempvar);

  ($$).ndim=($1).ndim;
  strcpy(($$).type,($1).type);
}
|ConditionalOrExpression OROR ConditionalAndExpression {
  strcpy(($$).tempvar, newtemp().c_str());
  emit("||",($1).tempvar,($3).tempvar,($$).tempvar, -1);
  strcpy(($$).type,"boolean");
};
ConditionalExpression:
ConditionalOrExpression {
  strcpy(($$).tempvar, ($1).tempvar);

  ($$).ndim=($1).ndim;
  strcpy(($$).type,($1).type);
}
|ConditionalOrExpression QUESTION Expression COLON ConditionalExpression {
 strcpy(($$).type,getorder(($3).type,($5).type,1).c_str());
};
AssignmentExpression:
ConditionalExpression {
  strcpy(($$).tempvar, ($1).tempvar);

  strcpy(($$).type,($1).type);
  ($$).ndim=($1).ndim;
}
|Assignment {
  strcpy(($$).tempvar, ($1).tempvar);
  strcpy(($$).type, ($1).type);
  ($$).sz = ($1).sz;
};

Assignment:
LeftHandSide AssignmentOperator AssignmentExpression {
  if(!strcmp(($2).tempvar,"="))
  {
    string p = string((char*)($1).tempvar);
    string o = p.substr(0, p.find('.'));
    string p1 = string((char*)($3).tempvar);
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
        int offset1 = curr_table->lookup(string((char*)($3).tempvar)).offset;
        int offset2 = curr_table->lookup(tp3).offset;
        if(offset1 != -1 && offset2 != -1){
          string tv5 = newtemp(), tv6 = newtemp();
          emit("+", tv10, to_string(offset1), tv5, -1);
          emit("+", tv10, to_string(offset2), tv6, -1);
          emit("=",("*(" + tv5 + ")").c_str(),"null",("*(" + tv10 + tv6 + ")").c_str(), -2);
        }
        else{
          storeobj[currtemp] = string((char*)(($1).tempvar));
        emit("=",($3).tempvar,"null",tp3.c_str(), -2);
        }
      }
      strcpy(($$).tempvar, tp3.c_str());
    }
    else{
        string tv11 = string((char*)($3).tempvar), tv12 = string((char*)($1).tempvar);
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
    strcpy(($$).tempvar, newtemp().c_str());
    string a=($2).tempvar;
    a=a.substr(0,a.size()-1);
    emit(a,($1).tempvar,($3).tempvar,($$).tempvar, -1);
    emit("=",($$).tempvar,"null",($1).tempvar, -2);
  }
  // emit("=",($3).tempvar,"null",($$).tempvar, -1);
  // emit(($2).tempvar,($$).tempvar,"null",($1).tempvar, -1);
  string s=curr_table->lookup(string((char*)($1).type)).type;
  string yo="";
  // cout<<"SSS"<<arrtype<<'\n';
  // cout<<"YYY"<<flag<<'\n';
  if(curr_table->lookup(string((char*)($1).type)).offset != -1)
  {
    if(curr_table->lookup(string((char*)($3).type)).offset != -1)
    {
      if(!boolgetorder(curr_table->lookup(string((char*)($1).type)).type.c_str(),curr_table->lookup(string((char*)($3).type)).type.c_str(),1))
      {
        if(strcmp(curr_table->lookup(string((char*)($1).type)).type.c_str(),($3).type)) 
        {
          cout<<"Invalid assignment between "<<curr_table->lookup(string((char*)($1).type)).type.c_str()<<" and "<<($3).type<<" on line "<<yylineno<<'\n';
        }
      }
      else
      {
        strcpy(($$).type,curr_table->lookup(string((char*)($3).type)).type.c_str());
      }
    }
    else
    {
      if(!strcmp(arrtype.c_str(),"null"))
      {
        if(!boolgetorder(curr_table->lookup(string((char*)($1).type)).type.c_str(),($3).type,1))
        {
          if(strcmp(curr_table->lookup(string((char*)($1).type)).type.c_str(),($3).type)) 
          {
            cout<<"Invalid assignment between "<<curr_table->lookup(string((char*)($1).type)).type.c_str()<<" and "<<($3).type<<" on line "<<yylineno<<'\n';
          }
        }
        else
        {
          strcpy(($$).type,($3).type);
        }
      }
      else
      {
        if(!boolgetorder(curr_table->lookup(string((char*)($1).type)).type.c_str(),arrtype,1))
        {
          if(strcmp(curr_table->lookup(string((char*)($1).type)).type.c_str(),arrtype.c_str())) 
          {
            cout<<"Invalid assignment between "<<curr_table->lookup(string((char*)($1).type)).type.c_str()<<" and "<<arrtype<<" on line "<<yylineno<<'\n';
          }
        }
        else
        {
          strcpy(($$).type,arrtype.c_str());
        }
      }
    }
  }
  else
  {
    if(curr_table->lookup(string((char*)($3).type)).offset != -1)
    {
      if(strcmp(($1).type,curr_table->lookup(string((char*)($3).type)).type.c_str()))
      {
        cout<<"Invalid assignment between "<<($1).type<<" and "<<curr_table->lookup(string((char*)($3).type)).type<<" on line "<<yylineno<<'\n';
      }
      else
      {
        strcpy(($$).type,($1).type);
      }
    }
    else
    {
      if(!boolgetorder(($1).type,($3).type,1))
      {
        if(!strcmp(($1).type,"String")&&!strcmp(($3).type,"string"))
        {

        }
        else if(strcmp(($1).type,($3).type))cout<<"Invalid assignment between "<<($1).type<<" and "<<($3).type<<" on line "<<yylineno<<'\n';
      }
      else
      {
        strcpy(($$).type,($1).type);
      }
    }
  }
  arrtype="null";
};
LeftHandSide:
Name {
  // cout<<"shrey"<<($1).type<<'\n';
  if(curr_table->lookup(string((char*)($1).type)).offset == -1 && checkobj(string((char*)($1).type)) == 0){
    if(!isaccess)
    {
      cout<<"Undeclared variable on line "<< yylineno<<"\n";
    }
  }
  strcpy(($$).type, ($1).type);
  strcpy(($$).tempvar, ($1).tempvar);
  ($$).sz = ($1).sz;
  isaccess=0;
}
|FieldAccess {
  strcpy(($$).tempvar, ($1).tempvar);
  strcpy(($$).type, ($1).type);
  // cout<<"shrey"<<($1).type<<'\n';
  ($$).sz = ($1).sz;
  
}
|ArrayAccess {
  strcpy(($$).tempvar, ($1).tempvar);
  // cout<<"shubhan\n";
  // cout<<"SHUBHAN"<<($1).type<<'\n';
  strcpy(($$).type, ($1).type);
  // cout<<"GGG"<< ($1).type<<'\n';
  ($$).sz = ($1).sz;
  arrtype="null";
};

AssignmentOperator:
EQUAL {
  strcpy(($$).tempvar, ($1).str);
  
  
}
|STAREQUAL {
  strcpy(($$).tempvar, ($1).str);
  
}
|FORWARDSLASHEQUAL {
  strcpy(($$).tempvar, ($1).str);
  
}
|PLUSEQUAL {
  strcpy(($$).tempvar, ($1).str);
  
}
|MINUSEQUAL {
  strcpy(($$).tempvar, ($1).str);
  
}
|OPENANGULARBRACKETOPENANGULARBRACKETEQUAL {
  strcpy(($$).tempvar, ($1).str);
  
}
|CLOSEANGULARBRACKETCLOSEANGULARBRACKETEQUAL {
  strcpy(($$).tempvar, ($1).str);
  
}
|CLOSEANGULARBRACKETCLOSEANGULARBRACKETCLOSEANGULARBRACKETEQUAL {
  strcpy(($$).tempvar, ($1).str);
  
}
|ANDEQUAL {
  strcpy(($$).tempvar, ($1).str);
  
}
|XOREQUAL {
  
  strcpy(($$).tempvar, ($1).str);
}
|OREQUAL {
  strcpy(($$).tempvar, ($1).str);
  
};

Expression:
AssignmentExpression {
  strcpy(($$).tempvar, ($1).tempvar);

  ($$).ndim=($1).ndim;
  strcpy(($$).type,($1).type);
  // strcpy(($1).argstring,($1).type);
    // cout<<"YO"<<($1).argstring<<'\n';

  
};
ConstantExpression:
Expression {
  strcpy(($$).tempvar, ($1).tempvar);
  strcpy(($$).type,($1).type);
  
};
%%

// Begin Declarations

string classcode;
string funccode;

typedef struct x86_code{
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

void addtox86(string func, string arg1, string arg2){
        x86_code temp;
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
                  addtox86("movq", addr, "%r9");
                  addtox86("addq", "$" + to_string(it3->second.offset), "%r9");
                  regalloc = (regalloc + 1)%3;
                  return "(%r9)";
                }
                else if(regalloc == 1){
                  addtox86("movq", addr, "%r10");
                  addtox86("addq", "$" + to_string(it3->second.offset), "%r10");
                  regalloc = (regalloc + 1)%3;
                  return "(%r10)";
                }
                else{
                  addtox86("movq", addr, "%r11");
                  addtox86("addq", "$" + to_string(it3->second.offset), "%r11");
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
    addtox86("movq", arg2, "%rax");
    addtox86("movq", arg1, "%rdx");
    addtox86("movq", "%rax", "%rcx");
    addtox86("salq", "%rcx", "%rdx");
    addtox86("movq", "%rdx", "%rax");
    addtox86("movq", "%rax", res);
    return;
  }
  else if( q.op == ">>"){
    addtox86("movq", arg2, "%rax");
    addtox86("movq", arg1, "%rdx");
    addtox86("movq", "%rax", "%rcx");
    addtox86("sarq", "%rcx", "%rdx");
    addtox86("movq", "%rdx", "%rax");
    addtox86("movq", "%rax", res);
  } 


  // Division Expression
  if(q.op[0] == '/'){
    if(arg1[0] == '$' && arg2[0] == '$'){
        string temploc = "-8(%rbp)";
        addtox86("movq", temploc, "%rcx");
        addtox86("movq", arg1, "%rax");
        addtox86("movq", arg2, temploc);
        addtox86("cltd","", "");
        addtox86("idivq", temploc, "");
        addtox86("movq", "%rax", res);
        addtox86("movq", "%rcx", temploc);
    }
    else if(arg1[0] == '$'){
        addtox86("movq", arg1, "%rax");
        addtox86("cltd", "", "");
        addtox86("idivq", arg2, "");
        addtox86("movq", "%rax", res);
    }
    else if(arg2[0] == '$'){
        addtox86("movq", arg1, "%rax");
        addtox86("movq", arg1, "%rcx");
        addtox86("movq", arg2, arg1);
        addtox86("cltd", "", "");
        addtox86("idivq", arg1, "");
        addtox86("movq", "%rax", res);
        addtox86("movq", "%rcx", arg1);
    }
    else{
        addtox86("movq", arg1, "%rax");
        addtox86("cltd", "", "");
        addtox86("idivq", arg2, "");
        addtox86("movq", "%rax", res);
    }
  }

  //Modulo Expression
    if(q.op[0] == '%'){
    if(arg1[0] == '$' && arg2[0] == '$'){
        string temploc = "-8(%rbp)";
        addtox86("movq", temploc, "%rcx");
        addtox86("movq", arg1, "%rax");
        addtox86("movq", arg2, temploc);
        addtox86("cltd","", "");
        addtox86("idivq", temploc, "");
        addtox86("movq", "%rdx", res);
        addtox86("movq", "%rcx", temploc);
    }
    else if(arg1[0] == '$'){
        addtox86("movq", arg1, "%rax");
        addtox86("cltd", "", "");
        addtox86("idivq", arg2, "");
        addtox86("movq", "%rdx", res);
    }
    else if(arg2[0] == '$'){
        addtox86("movq", arg1, "%rax");
        addtox86("movq", arg1, "%rcx");
        addtox86("movq", arg2, arg1);
        addtox86("cltd", "", "");
        addtox86("idivq", arg1, "");
        addtox86("movq", "%rdx", res);
        addtox86("movq", "%rcx", arg1);
    }
    else{
        addtox86("movq", arg1, "%rax");
        addtox86("cltd", "", "");
        addtox86("idivq", arg2, "");
        addtox86("movq", "%rdx", res);
    }
  }
  
  // Comparision Operators

  if(q.op == "=="){
    addtox86("movq", arg1, "%rax");
    addtox86("movq", arg2, "%rcx");
    addtox86("cmp", "%rax", "%rcx");
    addtox86("sete", "%al", "");
    addtox86("movzbq", "%al", "%rbx");
    addtox86("movq", "%rbx", res);
  }
  else if(q.op == "!="){
    addtox86("movq", arg1, "%rax");
    addtox86("movq", arg2, "%rcx");
    addtox86("cmp", "%rax", "%rcx");
    addtox86("setne", "%al", "");
    addtox86("movzbq", "%al", "%rbx");
    addtox86("movq", "%rbx", res);
  }
  else if(q.op == "||"){
    addtox86("movq", arg1, "%rax");
    addtox86("movq", arg2, "%rcx");
    addtox86("cmp", "%rax", "$1");
    addtox86("sete", "%al", "");
    addtox86("cmp", "%rcx", "$1");
    addtox86("sete", "%al", "");
    addtox86("movzbq", "%al", "%rbx");
    addtox86("movq", "%rbx", res);
  }
  else if(q.op == "&&"){
    addtox86("movq", arg1, "%rax");
    addtox86("movq", arg2, "%rcx");
    addtox86("cmp", "%rax", "%rcx");
    addtox86("sete", "%al", "");
    addtox86("movzbq", "%al", "%rbx");
    addtox86("movq", "%rbx", res);
  }
  else if(q.op == ">="){
    addtox86("movq", arg1, "%rax");
    addtox86("movq", arg2, "%rcx");
    addtox86("cmp", "%rax", "%rcx");
    addtox86("setle", "%al", "");
    addtox86("movzbq", "%al", "%rbx");
    addtox86("movq", "%rbx", res);
  }
  else if(q.op == "<="){
    addtox86("movq", arg1, "%rax");
    addtox86("movq", arg2, "%rcx");
    addtox86("cmp", "%rax", "%rcx");
    addtox86("setge", "%al", "");
    addtox86("movzbq", "%al", "%rbx");
    addtox86("movq", "%rbx", res);
  }
  else if(q.op == "<"){
    addtox86("movq", arg1, "%rax");
    addtox86("movq", arg2, "%rcx");
    addtox86("cmp", "%rax", "%rcx");
    addtox86("setg", "%al", "");
    addtox86("movzbq", "%al", "%rbx");
    addtox86("movq", "%rbx", res);
  }
  else if(q.op == ">"){
    addtox86("movq", arg1, "%rax");
    addtox86("movq", arg2, "%rcx");
    addtox86("cmp", "%rax", "%rcx");
    addtox86("setl", "%al", "");
    addtox86("movzbq", "%al", "%rbx");
    addtox86("movq", "%rbx", res);
  }
  else if(q.op == "^"){
    addtox86("movq", arg1, "%rax");
    addtox86("movq", arg2, "%rcx");
    addtox86("xorq", "%rcx", "%rax");
    addtox86("movq", "%rax", res);
  }

  op = optofunc(q.op);

  // Add Mul Sub Expressions
  if(op != ""){
    addtox86("movq", arg1, "%rax");
    addtox86("movq", arg2, "%rdx");
    addtox86(op, "%rax", "%rdx");
    if(op == "subq")
      addtox86("neg", "%rdx", "");
    addtox86("movq", "%rdx", res);
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
    addtox86("movq", arg, next);
    arg = "(%r12)";
    ctr=0;
    }
    else{
      string next = "%r13";
    addtox86("movq", arg, next);
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
    addtox86("movq", arg, next);
    arg = "(%r12)";
    ctr=0;
    }
    else{
      string next = "%r13";
    addtox86("movq", arg, next);
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
      addtox86("movq", "%r14", "%r8");
      addtox86("addq", "$" + s.substr(1), "%r8");
      objreg ++ ;
      objreg %= 3;
      return "(%r8)";
    }
    else if(objreg == 1){
      addtox86("movq", "%r14", "%r10");
      addtox86("addq", "$" + s.substr(1), "%r10");
      objreg ++ ;
      objreg %= 3;
      return "(%r10)";
    }
    else{
      addtox86("movq", "%r14", "%r9");
      addtox86("addq", "$" + s.substr(1), "%r9");
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
      // addtox86("movq", "%r14", "%r8");
      if(s[5] == '#'){
        string temp = s.substr(6, s.size()-1);
        addtox86("addq", "$" + to_string(funcsize["Class" + cln + "_" + fn] +  8*stoi(temp)), "%r8");
      }
      objreg ++ ;
      objreg %= 3;
      return "%r8";
    }
    else if(objreg == 1){
      // addtox86("movq", "%r14", "%r8");
      if(s[5] == '#'){
        string temp = s.substr(6, s.size()-1);
        addtox86("addq", "$" + to_string(funcsize["Class" + cln + "_" + fn] +  8*stoi(temp)), "%r10");
      }
      objreg ++ ;
      objreg %= 3;
      return "%r10";
    }
    else{
    //   // addtox86("movq", "%r14", "%r9");
      if(s[5] == '#'){
        string temp = s.substr(6, s.size()-1);
        addtox86("addq", "$" + to_string(funcsize["Class" + cln + "_" + fn] +  8*stoi(temp)), "%r9");
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
        addtox86("movq", "%r14", next);
        addtox86("addq", "$" + to_string(it.second), next);
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

int ismalloc = 1;

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

  for(auto it: list_of_Symbol_Tables){
    // cout<<"NEW TABLE"<<'\n';
    it->print_table();
    cout<<"Classwidth: "<<it->classwidth<<endl;
    cout<<'\n';
  }

  for(auto it: funcsize){
    cout<<it.first<<" "<<it.second<<'\n';
    string cl = it.first.substr(it.first.find("_") + 1);
    if(cl == "main"){
      mainwidth = it.second;
    }
  }

  for(auto it: vartostack){
    cout<<it.first.first<<" "<<it.first.second<<" "<<it.second<<'\n';
  }

  for(auto it: numfuncargs){
    cout<<it.first<<" "<<it.second<<endl;
  }

  init_constructor();
  for(auto it: classconstructor){
    cout<<it.first<<" "<<it.second<<endl;
  }

  for(auto it: classfield){
    cout<<it.first<<'\n';
    for(auto it1 : it.second){
      cout<<it1.first<<' '<<it1.second<<'\n';
    }
  }

  for(auto it: storeobj){
    cout<<it.first<<"// "<<it.second<<endl;
  }
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

  init_constructor();
  for(auto it: classconstructor){
    cout<<it.first<<" "<<it.second<<endl;
  }

  for(auto it: classfield){
    cout<<it.first<<'\n';
    for(auto it1 : it.second){
      cout<<it1.first<<' '<<it1.second<<'\n';
    }
  }

  for(auto it: storeobj){
    cout<<it.first<<"// "<<it.second<<endl;
  }

  for(auto it: objlist){
    cout<<it<<endl;
  }
map<pair<string,string>,string > store;// this is for class.function
map<string,string > store1;// this is for calls
ofstream fout;
fout.open("TAC.txt");
   for(auto it: code){
    curracces ++ ;
    // fout<<it.op<<' '<<it.arg1<<' '<<it.arg2<<' '<<it.res<<endl;
    if(it.arg1 == "shiftreg"){
      it.res = temptoaddr(it.res, funcsize["Class" + curr_class + "_" + curr_func]);
      addtox86("movq", "%r14", it.res);
      cout<<"\\\\\\\\\\\\\\\\\\\\\n";
      cout<<code[curracces-2].op<<endl;
      if(curracces >= 2 && code[curracces-2].op == "param")
        addtox86("movq", temptoaddr(baseptr(code[curracces-2].arg1), funcsize["Class" + curr_class + "_" + curr_func]), "%r14");
      continue;
    }
    if(it.res == "shiftreg"){
      it.arg1 = temptoaddr(it.arg1, funcsize["Class" + curr_class + "_" + curr_func]);
      addtox86("movq",  it.arg1, "%r14");
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
            addtox86("movq","%r14","%r9");
            addtox86("movq","$"+temp.substr(last,i-last),"%r8");
            addtox86("addq","%r8","%r9");
            addtox86("movq","$"+yo,"(%r9)");
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
        addtox86("movq", it.arg1, "%rax");
        addtox86("leave","", "");
        addtox86("ret","", "");
        isret = 1;
      }
      else if(it.op == "BeginClass"){
        inassign = 1;
        fout<<'\t'<<it.op<<" "<<it.arg1<<'\n';
        curr_class = newblock;
        if(classconstructor[curr_class] == 0){
          addtox86("pushq", "%rbp", "");
          addtox86("movq", "%rsp", "%rbp");
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
                  addtox86("movq","%r14","%r9");
                  addtox86("movq","$"+temp.substr(last,i-last),"%r8");
                  addtox86("addq","%r8","%r9");
                  addtox86("movq","$"+yo,"(%r9)");
                  yo="";
                  last=i+1;
                }
              }
            }
          }
          addtox86("movq", "$0", "%rax");
          addtox86("leave", "", "");
          addtox86("ret", "", "");
        }
        if(classconstructor[curr_class] == 0){
          addtox86("pushq", "%rbp", "");
          addtox86("movq", "%rsp", "%rbp");
          addtox86("movq", "$0", "%rax");
          addtox86("leave", "", "");
          addtox86("ret", "", "");
        }
        store[make_pair("",curr_class)]=curr_class;
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
        store1[curr_func]=a;
        store[make_pair(curr_class,curr_func)]=a;
      }
      else if(it.op=="EndFunc" || it.op=="EndClass" || it.op=="EndCtor")
       {
        if(it.op=="EndFunc" ||it.op=="EndCtor"){
          addtox86("leave","","");
          addtox86("ret","","");
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
          addtox86("movq", "%" + it.arg1, "%" + it.res);
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
                    addtox86("movq","%r14","%r9");
                    addtox86("movq","$"+temp.substr(last,i-last),"%r8");
                    addtox86("addq","%r8","%r9");
                    addtox86("movq","$"+yo,"(%r9)");
                    yo="";
                    last=i+1;
                  }
                }
              }
            }
          }
          if(it.arg1 == "rsp" && it.res == "rbp"){
            for(int i =0; i<numfuncargs["Class" + curr_class + "_" + curr_func]; ++i){
              addtox86("movq", to_string(16 + i*8) + "(%rbp)", "%rdx");
              addtox86("movq", "%rdx", to_string(-8 - i*8) + "(%rbp)");
            }
          }
          if(curr_func == "main"){
            addtox86("movq", "$" + to_string(mainwidth), "%rdi");
            addtox86("call", "malloc@PLT", "");
            addtox86("movq", "%rax", "%r15");
            addtox86("movq", "%rax", "%r14");
          }
          int subesp = funcsize["Class" + curr_class + "_" + curr_func] + 8*counter;
          subesp = nextPowerOf2(subesp);
          addtox86("subq", "$" + to_string(subesp), "%rsp");   // Changes the stack pointer to accomodate the function local variables and parameters
        }
        else if(it.arg1 == "popparam"){
          it.res = baseptr(it.res);
          it.res = temptoaddr(it.res, funcsize["Class" + curr_class + "_" + curr_func]);
          addtox86("movq", "%rax", it.res);
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
            addtox86("movq", it.arg1, it.res);
          }
          else{
            addtox86("movq", it.arg1, "%rax");
            addtox86("movq", "%rax", it.res);
          }
        }
        }
        if(it.idx == -2){
          inassign = 1;
        }
        
      }
      else if(it.op == "push" && it.arg1 == "rbp"){
        fout<<'\t'<<it.op<<" "<<it.arg1<<'\n';
        addtox86("pushq", "%rbp", "");
      }
      else if(it.op == "pop" && it.arg1 == "rbp"){
        fout<<'\t'<<it.op<<" "<<it.arg1<<'\n';
        // addtox86("popq", "%rbp", "");
      }
      else if(it.op == "param"){
        fout<<'\t'<<it.op<<" "<<it.arg1<<'\n';
        it.arg1 = baseptr(it.arg1);
        it.arg1 = temptoaddr(it.arg1, funcsize["Class" + curr_class + "_" + curr_func]);
        if(isliteral(it.arg1)){
          it.arg1 = "$" + it.arg1;
        }
        if(code[curracces+1].arg1 == "allocmem"){
          addtox86("movq", it.arg1, "%rdi");
        }
        else
          addtox86("pushq", it.arg1, "");
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
            addtox86("movq", it.arg2, "%r8");
            addtox86("addq", "$" + to_string(offattr), "%r8");
            it.arg2 = "(%r8)";
          
        }
        else if(isvar(it.arg2)){
          for(auto it1 : classfield["Class" + curr_class]){
            
            if(it1.first == it.arg2){
              addtox86("movq", "%r14", "%rbx");
              addtox86("addq", "$" + to_string(it1.second), "%rbx");
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
          addtox86("movq", it.arg2, "%rax");
          it.arg2 = "(%rax)";
        }
        it.arg2 = baseptr(it.arg2);
        it.arg2 = temptoaddr(it.arg2, funcsize["Class" + curr_class + "_" + curr_func]);
        addtox86("movq", it.arg2, "%rax");
        addtox86("movq", "%rax", "%rsi");
        addtox86("leaq", ".LC0(%rip)", "%rax");
        addtox86("movq", "%rax", "%rdi");
        addtox86("movq", "$0", "%rax");
        addtox86("call", "printf@PLT", "");
      }
      else if(it.op == "call"){
        fout<<'\t'<<it.op<<" "<<it.arg1<<" "<<it.arg2<<'\n';
        
        if(it.arg1 == "allocmem"){
          addtox86("call", "malloc@PLT", "");
          ismalloc = 1;
        }
        else{
        if(store1[it.arg1] != "") it.arg1 = store1[it.arg1];
          if(store1[it.arg2] != "") it.arg2 = store1[it.arg2];
          addtox86("","call", it.arg1, it.arg2);
          // yeh toh bas waha jaha call ho raha hai
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
        addtox86("movq", it.arg1, "%rax");
        addtox86("cmp", "$0", "%rax");
        addtox86("je", it.arg2, "");
      }
      else if(it.op=="Goto")
      {
        fout<<'\t'<<it.op<<" "<<it.arg1<<it.arg2<<it.res<<"\n";
        if(it.arg1 == "")
          addtox86("jmp", it.arg2, "");
        else
           addtox86("jmp", it.arg1, "");
      }
      else if(it.arg1==":")
      {
        // fout<<'\t';
        fout<<it.op<<it.arg1<<"\n";
        addtox86(it.op, it.arg1, "");
        newblock = it.op;
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
            addtox86("jmp", code[curracces].arg2, "");
          else
            addtox86("jmp", code[curracces].arg1, "");
          // addtox86("jmp", code[curracces].arg2, "");
        }
        /* cout<<"GHF "<<code[curracces].op<<code[curracces].arg1<<code[curracces].arg2<<'\n'; */
        fout<<'\t'<<it.op<<" "<<it.arg1<<"\n";
        if(isret == 0)
          addtox86("movq", "$0", "%rax");  // Harcoding the return value
        /* addtox86("leave", "", "");
        addtox86(it.op, "", ""); */
        /* cout<<"SHU "<<it.op<<'\n';
         */
      }
      else if(it.arg1=="cast_to_int"||it.arg1=="cast_to_float"||it.arg1=="cast_to_byte"||it.arg1=="cast_to_boolean"||it.arg1=="cast_to_byte"||it.arg1=="cast_to_short"||it.arg1=="cast_to_long"||it.arg1=="cast_to_double"||it.arg1=="cast_to_string")
      {
        addtox86("movq", it.arg2, "%rax");
        addtox86("movq", "%rax", it.res);
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

    fout.close();
    fout.open("x86code.s");

    fout << "\t.section    .rodata" << '\n';
    fout<<".LC0:" << '\n';
    fout<< "\t.string    \"%ld\\n\""<<'\n';
    fout<<"\t.text"<<'\n';
    fout<<"\t.globl    main"<<'\n';

   for(auto it: asmcode){
      // x86ind ++ ;
      // if(i<length && x86ind == objpushed[i]){
      //   i ++ ;
      //   continue;
      // }
      if(it.arg1 == ":" ){
      if(it.func[0]=='L')
      {
      cout<<it.func<<' '<<it.arg1<<' '<<it.arg2<<'\n';
      fout<<it.func<<' '<<it.arg1<<' '<<it.arg2<<'\n';
      } 
      else if(store[make_pair(it.classn,it.func)]!="")
      {
      cout<<store[make_pair(it.classn,it.func)]<<' '<<it.arg1<<' '<<it.arg2<<'\n';
      fout<<store[make_pair(it.classn,it.func)]<<' '<<it.arg1<<' '<<it.arg2<<'\n';
      }
      else
      {
      cout<<it.func<<' '<<it.arg1<<' '<<it.arg2<<'\n';
      fout<<it.func<<' '<<it.arg1<<' '<<it.arg2<<'\n';
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
    // for(auto i:store)
    // {
    //   cout<<i.first<<" "<<i.second<<'\n';
    // }

  return 0;
}

void yyerror(const char * s)
{
  cout<<"Error in line " << yylineno << " : " << s << endl;
  exit(0);
}