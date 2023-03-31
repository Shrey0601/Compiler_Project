%{
    #include<bits/stdc++.h>
    #include <fstream>
    using namespace std;
    void yyerror(const char * s);
    int yylex();
    extern int yylineno;
    extern FILE* yyin;
    #define YYERROR_VERBOSE 1
    int nodes = 0;
    map<int, string> node_names;
    vector<pair<int,string>> parents, child;
    string s;

%}

%define parse.error verbose

%union {
  struct {
    int n;
    char str[1000];
  } lab;
  int cnt;
  char lex[1000];
}

%type<cnt> Goal
%type<cnt> Literal
%type<cnt> Type
%type<cnt> PrimitiveType
%type<cnt> NumericType
%type<cnt> IntegralType
%type<cnt> FloatingPointType
%type<cnt> ReferenceType
%type<cnt> ClassOrInterfaceType
%type<cnt> ClassType
%type<cnt> InterfaceType
%type<cnt> ArrayType
%type<cnt> Name
%type<cnt> SimpleName
%type<cnt> QualifiedName
%type<cnt> CompilationUnit
%type<cnt> ImportDeclarations
%type<cnt> TypeDeclarations
%type<cnt> PackageDeclaration
%type<cnt> ImportDeclaration
%type<cnt> SingleTypeImportDeclaration
%type<cnt> TypeImportOnDemandDeclaration
%type<cnt> TypeDeclaration
%type<cnt> Modifiers
%type<cnt> Modifier
%type<cnt> ClassDeclaration
%type<cnt> Super
%type<cnt> Interfaces
%type<cnt> InterfaceTypeList
%type<cnt> ClassBody
%type<cnt> ClassBodyDeclarations
%type<cnt> ClassBodyDeclaration
%type<cnt> ClassMemberDeclaration
%type<cnt> FieldDeclaration
%type<cnt> VariableDeclarators
%type<cnt> VariableDeclarator
%type<cnt> VariableDeclaratorId
%type<cnt> VariableInitializer
%type<cnt> MethodDeclaration
%type<cnt> MethodHeader
%type<cnt> MethodDeclarator
%type<cnt> FormalParameterList
%type<cnt> FormalParameter
%type<cnt> Throws
%type<cnt> ClassTypeList
%type<cnt> MethodBody
%type<cnt> StaticInitializer
%type<cnt> ConstructorDeclaration
%type<cnt> ConstructorDeclarator
%type<cnt> ConstructorBody
%type<cnt> ExplicitConstructorInvocation
%type<cnt> InterfaceDeclaration
%type<cnt> ExtendsInterfaces
%type<cnt> InterfaceBody
%type<cnt> InterfaceMemberDeclarations
%type<cnt> InterfaceMemberDeclaration
%type<cnt> ConstantDeclaration
%type<cnt> AbstractMethodDeclaration
%type<cnt> ArrayInitializer
%type<cnt> VariableInitializers
%type<cnt> Block
%type<cnt> BlockStatements
%type<cnt> BlockStatement
%type<cnt> LocalVariableDeclarationStatement
%type<cnt> LocalVariableDeclaration
%type<cnt> Statement
%type<cnt> StatementNoShortIf
%type<cnt> StatementWithoutTrailingSubstatement
%type<cnt> EmptyStatement
%type<cnt> LabeledStatement
%type<cnt> LabeledStatementNoShortIf
%type<cnt> ExpressionStatement
%type<cnt> StatementExpression
%type<cnt> IfThenStatement
%type<cnt> IfThenElseStatement
%type<cnt> IfThenElseStatementNoShortIf
%type<cnt> SwitchStatement
%type<cnt> SwitchBlock
%type<cnt> SwitchBlockStatementGroups
%type<cnt> SwitchBlockStatementGroup
%type<cnt> SwitchLabels
%type<cnt> SwitchLabel
%type<cnt> WhileStatement
%type<cnt> WhileStatementNoShortIf
%type<cnt> DoStatement
%type<cnt> ForStatement
%type<cnt> ForStatementNoShortIf
%type<cnt> ForInit
%type<cnt> ForUpdate
%type<cnt> StatementExpressionList
%type<cnt> BreakStatement
%type<cnt> ContinueStatement
%type<cnt> ReturnStatement
%type<cnt> ThrowStatement
%type<cnt> SynchronizedStatement
%type<cnt> TryStatement
%type<cnt> Catches
%type<cnt> CatchClause
%type<cnt> Finally
%type<cnt> Primary
%type<cnt> PrimaryNoNewArray
%type<cnt> ClassInstanceCreationExpression
%type<cnt> ArgumentList
%type<cnt> ArrayCreationExpression
%type<cnt> DimExprs
%type<cnt> DimExpr
%type<cnt> Dims
%type<cnt> FieldAccess
%type<cnt> MethodInvocation
%type<cnt> ArrayAccess
%type<cnt> PostfixExpression
%type<cnt> PostIncrementExpression
%type<cnt> PostDecrementExpression
%type<cnt> UnaryExpression
%type<cnt> PreIncrementExpression
%type<cnt> PreDecrementExpression
%type<cnt> UnaryExpressionNotPlusMinus
%type<cnt> CastExpression
%type<cnt> MultiplicativeExpression
%type<cnt> AdditiveExpression
%type<cnt> ShiftExpression
%type<cnt> RelationalExpression
%type<cnt> EqualityExpression
%type<cnt> AndExpression
%type<cnt> ExclusiveOrExpression
%type<cnt> InclusiveOrExpression
%type<cnt> ConditionalAndExpression
%type<cnt> ConditionalOrExpression
%type<cnt> ConditionalExpression
%type<cnt> AssignmentExpression
%type<cnt> Assignment
%type<cnt> LeftHandSide
%type<cnt> AssignmentOperator
%type<cnt> Expression
%type<cnt> ConstantExpression


%token<lab> BYTE
%token<lab> SHORT 
%token<lab> INT
%token<lab> LONG 
%token<lab> CHAR
%token<lab> ELSE
%token<lab> CATCH
%token<lab> FINALLY
%token<lab> INTERFACE
%token<lab> PLUS
%token<lab> FORWARDSLASH
%token<lab> MODULO
%token<lab> IF 
%token<lab> SWITCH
%token<lab> IntegerLiteral
%token<lab> FloatingPointLiteral
%token<lab> BooleanLiteral
%token<lab> CharacterLiteral
%token<lab> StringLiteral
%token<lab> NullLiteral
%token<lab> FLOAT
%token<lab> DOUBLE
%token<lab> BOOLEAN
%token<lab> CASE
%token<lab> DEFAULT
%token<lab> DO
%token<lab> WHILE
%token<lab> OPENANGULARBRACKET
%token<lab> CLOSEANGULARBRACKET
%token<lab> OPENBRACKET
%token<lab> CLOSEBRACKET
%token<lab> OPENCURLYBRACKET
%token<lab> CLOSECURLYBRACKET
%token<lab> OPENSQUAREBRACKET
%token<lab> CLOSESQUAREBRACKET
%token<lab> EQUAL
%token<lab> STAREQUAL
%token<lab> FORWARDSLASHEQUAL
%token<lab> PLUSEQUAL
%token<lab> MINUSEQUAL
%token<lab> OPENANGULARBRACKETOPENANGULARBRACKETEQUAL
%token<lab> CLOSEANGULARBRACKETCLOSEANGULARBRACKETEQUAL
%token<lab> CLOSEANGULARBRACKETCLOSEANGULARBRACKETCLOSEANGULARBRACKETEQUAL
%token<lab> ANDEQUAL
%token<lab> XOREQUAL
%token<lab> OREQUAL
%token<lab> DOT
%token<lab> COMMA
%token<lab> SEMICOLON
%token<lab> COLON
%token<lab> INSTANCEOF
%token<lab> Identifier
%token<lab> PUBLIC 
%token<lab> PROTECTED 
%token<lab> PRIVATE
%token<lab> STATIC
%token<lab> ABSTRACT 
%token<lab> FINAL 
%token<lab> NATIVE 
%token<lab> SYNCHRONIZED 
%token<lab> TRANSIENT 
%token<lab> VOLATILE
%token<lab> PACKAGE
%token<lab> IMPORT 
%token<lab> STAR
%token<lab> CLASS
%token<lab> EXTENDS
%token<lab> IMPLEMENTS
%token<lab> VOID
%token<lab> THIS 
%token<lab> SUPER
%token<lab> BREAK
%token<lab> RETURN
%token<lab> FOR
%token<lab> TRY
%token<lab> THROWS
%token<lab> THROW
%token<lab> CONTINUE
%token<lab> NEW
%token<lab> PLUSPLUS
%token<lab> MINUSMINUS
%token<lab> TILDA
%token<lab> NOT
%token<lab> AND
%token<lab> OR
%token<lab> OROR
%token<lab> ANDAND
%token<lab> NOTEQUAL
%token<lab> MINUS
%token<lab> OPENANGULARBRACKETOPENANGULARBRACKET
%token<lab> CLOSEANGULARBRACKETCLOSEANGULARBRACKET
%token<lab> CLOSEANGULARBRACKETCLOSEANGULARBRACKETCLOSEANGULARBRACKET
%token<lab> QUESTION
%token<lab> XOR
%token<lab> EQUALEQUAL
%token<lab> OPENANGULARBRACKETEQUAL
%token<lab> CLOSEANGULARBRACKETEQUAL

%%
Goal:
CompilationUnit {
  // $$ = nodes++; node_names[$$] = "Goal";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
};

Literal:
IntegerLiteral {
  $$ = nodes++; node_names[$$] = "Literal"; parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Literal("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
}
|FloatingPointLiteral  {
  $$ = nodes++; node_names[$$] = "Literal"; parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Literal("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
}
|BooleanLiteral  {
  $$ = nodes++; node_names[$$] = "Literal"; parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Literal("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
}
|CharacterLiteral  {
  $$ = nodes++; node_names[$$] = "Literal"; parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Literal("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
}
|StringLiteral  {
  $$ = nodes++; node_names[$$] = "Literal"; parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "StringLiteral"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
}
|NullLiteral  {
  $$ = nodes++; node_names[$$] = "Literal"; parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Literal("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
};

Type:
PrimitiveType  {
  $$ = nodes++; node_names[$$] = "Type"; parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
}
|ReferenceType {
  $$ = nodes++; node_names[$$] = "Type"; parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
};

PrimitiveType:
NumericType {
  $$ = nodes++; node_names[$$] = "PrimitiveType"; parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
}
|BOOLEAN {
  $$ = nodes++; node_names[$$] = "PrimitiveType"; parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Keyword("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
};

NumericType:
IntegralType {
  $$ = nodes++; node_names[$$] = "NumericType"; parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
}
|FloatingPointType {
  $$ = nodes++; node_names[$$] = "FloatingType"; parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
};

IntegralType:
BYTE {
  $$ = nodes++; node_names[$$] = "IntegralType"; parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Keyword("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
}
|SHORT  {
  $$ = nodes++; node_names[$$] = "IntegralType"; parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Keyword("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
}
|INT  {
  $$ = nodes++; node_names[$$] = "IntegralType"; parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Keyword("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
}
|LONG {
  $$ = nodes++; node_names[$$] = "IntegralType"; parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Keyword("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
}
|CHAR {
  $$ = nodes++; node_names[$$] = "IntegralType"; parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Keyword("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
};

FloatingPointType: 
FLOAT {
  $$ = nodes++; node_names[$$] = "FloatingPointType"; parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Keyword("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
}
|DOUBLE {
  $$ = nodes++; node_names[$$] = "FloatingPointType"; parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Keyword("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
};

ReferenceType:
ClassOrInterfaceType {
  $$ = nodes++; node_names[$$] = "ReferenceType"; parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
}
|ArrayType {
  $$ = nodes++; node_names[$$] = "ReferenceType"; parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
};

ClassOrInterfaceType:
Name {
  $$ = nodes++; node_names[$$] = "ClassOrInterfaceType"; parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
}

ClassType:
ClassOrInterfaceType {
  $$ = nodes++; node_names[$$] = "ClassType"; parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
};

InterfaceType:
ClassOrInterfaceType {
  $$ = nodes++; node_names[$$] = "InterfaceType"; parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
};

ArrayType:
PrimitiveType OPENSQUAREBRACKET CLOSESQUAREBRACKET {
  $$ = nodes++; node_names[$$] = "ArrayType";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  parents.push_back(make_pair($$, node_names[$$])); ($2).n = nodes++; s = "Separator("+string((char*)($2).str)+")"; node_names[($2).n] = s; child.push_back(make_pair(($2).n, node_names[($2).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($3).n = nodes++; s = "Separator("+string((char*)($3).str)+")"; node_names[($3).n] = s; child.push_back(make_pair(($3).n, node_names[($3).n]));
}
|Name OPENSQUAREBRACKET CLOSESQUAREBRACKET {
  $$ = nodes++; node_names[$$] = "ArrayType";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  parents.push_back(make_pair($$, node_names[$$])); ($2).n = nodes++; s = "Separator("+string((char*)($2).str)+")"; node_names[($2).n] = s; child.push_back(make_pair(($2).n, node_names[($2).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($3).n = nodes++; s = "Separator("+string((char*)($3).str)+")"; node_names[($3).n] = s; child.push_back(make_pair(($3).n, node_names[($3).n]));
}
|ArrayType OPENSQUAREBRACKET CLOSESQUAREBRACKET {
  $$ = nodes++; node_names[$$] = "ArrayType";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  parents.push_back(make_pair($$, node_names[$$])); ($2).n = nodes++; s = "Separator("+string((char*)($2).str)+")"; node_names[($2).n] = s; child.push_back(make_pair(($2).n, node_names[($2).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($3).n = nodes++; s = "Separator("+string((char*)($3).str)+")"; node_names[($3).n] = s; child.push_back(make_pair(($3).n, node_names[($3).n]));
};

Name:
SimpleName {
  $$ = nodes++; node_names[$$] = "Name"; parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
}
|QualifiedName {
  $$ = nodes++; node_names[$$] = "Name"; parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
};

SimpleName:
Identifier {
  $$ = nodes++; node_names[$$] = "SimpleName"; parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Identifier("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
};

QualifiedName:
Name DOT Identifier {
  $$ = nodes++; node_names[$$] = "QualifiedName";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  parents.push_back(make_pair($$, node_names[$$])); ($2).n = nodes++; s = "Separator("+string((char*)($2).str)+")"; node_names[($2).n] = s; child.push_back(make_pair(($2).n, node_names[($2).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($3).n = nodes++; s = "Separator("+string((char*)($3).str)+")"; node_names[($3).n] = s; child.push_back(make_pair(($3).n, node_names[($3).n]));
};



CompilationUnit:
PackageDeclaration ImportDeclarations {
  $$ = nodes++; node_names[$$] = "CompilationUnit";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($2, node_names[$2]));
}
|ImportDeclarations {
  $$ = nodes++; node_names[$$] = "CompilationUnit";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
}
|PackageDeclaration TypeDeclarations {
  $$ = nodes++; node_names[$$] = "CompilationUnit";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($2, node_names[$2]));
}
|TypeDeclarations {
  $$ = nodes++; node_names[$$] = "CompilationUnit";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
}
|PackageDeclaration ImportDeclarations TypeDeclarations {
  $$ = nodes++; node_names[$$] = "CompilationUnit";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($2, node_names[$2]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($3, node_names[$3]));
}
|ImportDeclarations TypeDeclarations {
  $$ = nodes++; node_names[$$] = "CompilationUnit";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($2, node_names[$2]));
}
|PackageDeclaration {
  $$ = nodes++; node_names[$$] = "CompilationUnit";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
}
;

ImportDeclarations:
ImportDeclaration {
  $$ = nodes++; node_names[$$] = "ImportDeclarations";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
}
|ImportDeclarations ImportDeclaration {
  $$ = nodes++; node_names[$$] = "ImportDeclarations";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($2, node_names[$2]));
}
;

TypeDeclarations:
TypeDeclaration {
  $$ = nodes++; node_names[$$] = "TypeDeclarations";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
}
|TypeDeclarations TypeDeclaration {
  $$ = nodes++; node_names[$$] = "TypeDeclarations";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($2, node_names[$2]));
}
;

PackageDeclaration:
PACKAGE Name SEMICOLON {
  $$ = nodes++; node_names[$$] = "PackageDeclaration";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Keyword("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($2, node_names[$2]));
  parents.push_back(make_pair($$, node_names[$$])); ($3).n = nodes++; s = "Separator("+string((char*)($3).str)+")"; node_names[($3).n] = s; child.push_back(make_pair(($3).n, node_names[($3).n]));
};

ImportDeclaration:
SingleTypeImportDeclaration {
  $$ = nodes++; node_names[$$] = "ImportDeclaration";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
}
|TypeImportOnDemandDeclaration {
  $$ = nodes++; node_names[$$] = "ImportDeclaration";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
};

SingleTypeImportDeclaration:
IMPORT Name SEMICOLON {
  $$ = nodes++; node_names[$$] = "SingleTypeImportDeclaration";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Keyword("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($2, node_names[$2]));
  parents.push_back(make_pair($$, node_names[$$])); ($3).n = nodes++; s = "Separator("+string((char*)($3).str)+")"; node_names[($3).n] = s; child.push_back(make_pair(($3).n, node_names[($3).n]));
};

TypeImportOnDemandDeclaration:
IMPORT Name DOT STAR SEMICOLON {
  $$ = nodes++; node_names[$$] = "TypeImportOnDemandDeclaration";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Keyword("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($2, node_names[$2]));
  parents.push_back(make_pair($$, node_names[$$])); ($3).n = nodes++; s = "Separator("+string((char*)($3).str)+")"; node_names[($3).n] = s; child.push_back(make_pair(($3).n, node_names[($3).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($4).n = nodes++; s = "Operator("+string((char*)($4).str)+")"; node_names[($4).n] = s; child.push_back(make_pair(($4).n, node_names[($4).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($5).n = nodes++; s = "Separator("+string((char*)($5).str)+")"; node_names[($5).n] = s; child.push_back(make_pair(($5).n, node_names[($5).n]));
};

TypeDeclaration:
ClassDeclaration {
  $$ = nodes++; node_names[$$] = "TypeDeclaration";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
}
|InterfaceDeclaration {
  $$ = nodes++; node_names[$$] = "TypeDeclaration";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
};
|SEMICOLON {
  $$ = nodes++; node_names[$$] = "TypeDeclaration";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Separator("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
};

Modifiers:
Modifier {
  $$ = nodes++;node_names[$$] = "Modifiers";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
}
|Modifiers Modifier {
  $$ = nodes++; node_names[$$] = "Modifiers";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($2, node_names[$2]));
};
Modifier:
PUBLIC  {
  $$ = nodes++; node_names[$$] = "Modifier";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Keyword("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
}
|PROTECTED {
  $$ = nodes++; node_names[$$] = "Modifier";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Keyword("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
} 
|PRIVATE {
  $$ = nodes++; node_names[$$] = "Modifier";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Keyword("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
}
|STATIC {
  $$ = nodes++; node_names[$$] = "Modifier";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Keyword("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
}
|ABSTRACT {
  $$ = nodes++; node_names[$$] = "Modifier";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Keyword("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
} 
|FINAL  {
  $$ = nodes++; node_names[$$] = "Modifier";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Keyword("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
}
|NATIVE  {
  $$ = nodes++; node_names[$$] = "Modifier";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Keyword("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
}
|SYNCHRONIZED  {
  $$ = nodes++; node_names[$$] = "Modifier";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Keyword("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
}
|TRANSIENT  {
  $$ = nodes++; node_names[$$] = "Modifier";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Keyword("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
}
|VOLATILE {
  $$ = nodes++; node_names[$$] = "Modifier";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Keyword("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
};

ClassDeclaration:
CLASS Identifier Super Interfaces ClassBody {
  $$ = nodes++; node_names[$$] = "ClassDeclaration";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Keyword("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($2).n = nodes++; s = "Identifier("+string((char*)($2).str)+")"; node_names[($2).n] = s; child.push_back(make_pair(($2).n, node_names[($2).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($3, node_names[$3]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($4, node_names[$4]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($5, node_names[$5]));
}
|Modifiers CLASS Identifier Interfaces ClassBody {
  $$ = nodes++; node_names[$$] = "ClassDeclaration";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  parents.push_back(make_pair($$, node_names[$$])); ($2).n = nodes++; s = "Keyword("+string((char*)($2).str)+")"; node_names[($2).n] = s; child.push_back(make_pair(($2).n, node_names[($2).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($3).n = nodes++; s = "Identifier("+string((char*)($3).str)+")"; node_names[($3).n] = s; child.push_back(make_pair(($3).n, node_names[($3).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($4, node_names[$4]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($5, node_names[$5]));
}
|Modifiers CLASS Identifier Super ClassBody {
  $$ = nodes++; node_names[$$] = "ClassDeclaration";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  parents.push_back(make_pair($$, node_names[$$])); ($2).n = nodes++; s = "Keyword("+string((char*)($2).str)+")"; node_names[($2).n] = s; child.push_back(make_pair(($2).n, node_names[($2).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($3).n = nodes++; s = "Identifier("+string((char*)($3).str)+")"; node_names[($3).n] = s; child.push_back(make_pair(($3).n, node_names[($3).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($4, node_names[$4]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($5, node_names[$5]));
}
|CLASS Identifier Interfaces ClassBody {
  $$ = nodes++; node_names[$$] = "ClassDeclaration";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Keyword("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($2).n = nodes++; s = "Identifier("+string((char*)($2).str)+")"; node_names[($2).n] = s; child.push_back(make_pair(($2).n, node_names[($2).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($3, node_names[$3]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($4, node_names[$4]));
}
|CLASS Identifier Super ClassBody {
  $$ = nodes++; node_names[$$] = "ClassDeclaration";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Keyword("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($2).n = nodes++; s = "Identifier("+string((char*)($2).str)+")"; node_names[($2).n] = s; child.push_back(make_pair(($2).n, node_names[($2).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($3, node_names[$3]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($4, node_names[$4]));
}
|Modifiers CLASS Identifier ClassBody {
  $$ = nodes++; node_names[$$] = "ClassDeclaration";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  parents.push_back(make_pair($$, node_names[$$])); ($2).n = nodes++; s = "Keyword("+string((char*)($2).str)+")"; node_names[($2).n] = s; child.push_back(make_pair(($2).n, node_names[($2).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($3).n = nodes++; s = "Identifier("+string((char*)($3).str)+")"; node_names[($3).n] = s; child.push_back(make_pair(($3).n, node_names[($3).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($4, node_names[$4]));
}
|CLASS Identifier ClassBody {
  $$ = nodes++; node_names[$$] = "ClassDeclaration";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Keyword("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($2).n = nodes++; s = "Identifier("+string((char*)($2).str)+")"; node_names[($2).n] = s; child.push_back(make_pair(($2).n, node_names[($2).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($3, node_names[$3]));
}
|Modifiers CLASS Identifier Super Interfaces ClassBody {
  $$ = nodes++; node_names[$$] = "ClassDeclaration";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  parents.push_back(make_pair($$, node_names[$$])); ($2).n = nodes++; s = "Keyword("+string((char*)($2).str)+")"; node_names[($2).n] = s; child.push_back(make_pair(($2).n, node_names[($2).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($3).n = nodes++; s = "Identifier("+string((char*)($3).str)+")"; node_names[($3).n] = s; child.push_back(make_pair(($3).n, node_names[($3).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($4, node_names[$4]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($5, node_names[$5]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($6, node_names[$6]));
};

Super:
EXTENDS ClassType {
  $$ = nodes++; node_names[$$] = "Super";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Keyword("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($2, node_names[$2]));
};

Interfaces:
IMPLEMENTS InterfaceTypeList {
  $$ = nodes++; node_names[$$] = "Interfaces";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Keyword("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($2, node_names[$2]));
};

InterfaceTypeList:
InterfaceType {
  $$ = nodes++; node_names[$$] = "InterfaceTypeList";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
}
|InterfaceTypeList COMMA InterfaceType {
  $$ = nodes++; node_names[$$] = "InterfaceTypeList";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  parents.push_back(make_pair($$, node_names[$$])); ($2).n = nodes++; s = "Separator("+string((char*)($2).str)+")"; node_names[($2).n] = s; child.push_back(make_pair(($2).n, node_names[($2).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($3, node_names[$3]));
};

ClassBody:
OPENCURLYBRACKET ClassBodyDeclarations CLOSECURLYBRACKET {
  $$ = nodes++; node_names[$$] = "ClassBody";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Separator("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($2, node_names[$2]));
  parents.push_back(make_pair($$, node_names[$$])); ($3).n = nodes++; s = "Separator("+string((char*)($3).str)+")"; node_names[($3).n] = s; child.push_back(make_pair(($3).n, node_names[($3).n]));
}
|OPENCURLYBRACKET CLOSECURLYBRACKET {
  $$ = nodes++; node_names[$$] = "ClassBody";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Separator("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($2).n = nodes++; s = "Separator("+string((char*)($2).str)+")"; node_names[($2).n] = s; child.push_back(make_pair(($2).n, node_names[($2).n]));
};

ClassBodyDeclarations:
ClassBodyDeclaration {
  $$ = nodes++; node_names[$$] = "ClassBodyDeclarations";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
}
|ClassBodyDeclarations ClassBodyDeclaration {
  $$ = nodes++; node_names[$$] = "ClassBodyDeclarations";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($2, node_names[$2]));
};

ClassBodyDeclaration:
ClassMemberDeclaration {
  $$ = nodes++; node_names[$$] = "ClassBodyDeclaration";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
}
|StaticInitializer {
  $$ = nodes++; node_names[$$] = "ClassBodyDeclaration";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
}
|ConstructorDeclaration {
  $$ = nodes++; node_names[$$] = "ClassBodyDeclaration";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
};

ClassMemberDeclaration:
FieldDeclaration {
  $$ = nodes++; node_names[$$] = "ClassMemberDeclaration";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
}
|MethodDeclaration {
  $$ = nodes++; node_names[$$] = "ClassMemberDeclaration";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
};

FieldDeclaration:
Modifiers Type VariableDeclarators SEMICOLON {
  $$ = nodes++; node_names[$$] = "FieldDeclaration";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($2, node_names[$2]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($3, node_names[$3]));
  parents.push_back(make_pair($$, node_names[$$])); ($4).n = nodes++; s = "Separator("+string((char*)($4).str)+")"; node_names[($4).n] = s; child.push_back(make_pair(($4).n, node_names[($4).n]));
}
|Type VariableDeclarators SEMICOLON {
  $$ = nodes++; node_names[$$] = "FieldDeclaration";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($2, node_names[$2]));
  parents.push_back(make_pair($$, node_names[$$])); ($3).n = nodes++; s = "Separator("+string((char*)($3).str)+")"; node_names[($3).n] = s; child.push_back(make_pair(($3).n, node_names[($3).n]));
};

VariableDeclarators:
VariableDeclarator {
  $$ = nodes++; node_names[$$] = "VariableDeclarators";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
}
|VariableDeclarators COMMA VariableDeclarator {
  $$ = nodes++; node_names[$$] = "VariableDeclarators";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  parents.push_back(make_pair($$, node_names[$$])); ($2).n = nodes++; s = "Separator("+string((char*)($2).str)+")"; node_names[($2).n] = s; child.push_back(make_pair(($2).n, node_names[($2).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($3, node_names[$3]));
};

VariableDeclarator:
VariableDeclaratorId {
  $$ = nodes++; node_names[$$] = "VariableDeclarator";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
}
|VariableDeclaratorId EQUAL VariableInitializer {
  $$ = nodes++; node_names[$$] = "VariableDeclarator";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  parents.push_back(make_pair($$, node_names[$$])); ($2).n = nodes++; s = "Operator("+string((char*)($2).str)+")"; node_names[($2).n] = s; child.push_back(make_pair(($2).n, node_names[($2).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($3, node_names[$3]));
};

VariableDeclaratorId:
Identifier {
  $$ = nodes++; node_names[$$] = "VariableDeclaratorId";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Identifier("+(string)string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
}
|VariableDeclaratorId OPENSQUAREBRACKET CLOSESQUAREBRACKET {
  $$ = nodes++; node_names[$$] = "VariableDeclaratorId";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  parents.push_back(make_pair($$, node_names[$$])); ($2).n = nodes++; s = "Separator("+string((char*)($2).str)+")"; node_names[($2).n] = s; child.push_back(make_pair(($2).n, node_names[($2).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($3).n = nodes++; s = "Separator("+string((char*)($3).str)+")"; node_names[($3).n] = s; child.push_back(make_pair(($3).n, node_names[($3).n]));
};

VariableInitializer:
Expression {
  $$ = nodes++; node_names[$$] = "VariableInitializer";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
}
|ArrayInitializer {
  $$ = nodes++; node_names[$$] = "VariableInitializer";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
};


MethodDeclaration:
MethodHeader MethodBody {
  $$ = nodes++; node_names[$$] = "MethodDeclaration";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($2, node_names[$2]));
}
|MethodBody {
  $$ = nodes++; node_names[$$] = "MethodDeclaration";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
};

MethodHeader:
Modifiers Type MethodDeclarator Throws {
  $$ = nodes++; node_names[$$] = "MethodHeader";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($2, node_names[$2]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($3, node_names[$3]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($4, node_names[$4]));
}
|Modifiers Type MethodDeclarator  {
  $$ = nodes++; node_names[$$] = "MethodHeader";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($2, node_names[$2]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($3, node_names[$3]));
}
|Type MethodDeclarator Throws {
  $$ = nodes++; node_names[$$] = "MethodHeader";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($2, node_names[$2]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($3, node_names[$3]));
}
|Type MethodDeclarator {
  $$ = nodes++; node_names[$$] = "MethodHeader";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($2, node_names[$2]));
}
|Modifiers VOID MethodDeclarator Throws {
  $$ = nodes++; node_names[$$] = "MethodHeader";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  parents.push_back(make_pair($$, node_names[$$])); ($2).n = nodes++; s = "Keyword("+string((char*)($2).str)+")"; node_names[($2).n] = s; child.push_back(make_pair(($2).n, node_names[($2).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($3, node_names[$3]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($4, node_names[$4]));
}
|VOID MethodDeclarator Throws {
  $$ = nodes++; node_names[$$] = "MethodHeader";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Keyword("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($2, node_names[$2]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($3, node_names[$3]));
}
|Modifiers VOID MethodDeclarator  {
  $$ = nodes++; node_names[$$] = "MethodHeader";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  parents.push_back(make_pair($$, node_names[$$])); ($2).n = nodes++; s = "Keyword("+string((char*)($2).str)+")"; node_names[($2).n] = s; child.push_back(make_pair(($2).n, node_names[($2).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($3, node_names[$3]));
}
|VOID MethodDeclarator {
  $$ = nodes++; node_names[$$] = "MethodHeader";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Keyword("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($2, node_names[$2]));
};

MethodDeclarator:
Identifier OPENBRACKET CLOSEBRACKET {
  $$ = nodes++; node_names[$$] = "MethodDeclarator";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Identifier("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($2).n = nodes++; s = "Separator("+string((char*)($2).str)+")"; node_names[($2).n] = s; child.push_back(make_pair(($2).n, node_names[($2).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($3).n = nodes++; s = "Separator("+string((char*)($3).str)+")"; node_names[($3).n] = s; child.push_back(make_pair(($3).n, node_names[($3).n]));
}
|Identifier OPENBRACKET FormalParameterList CLOSEBRACKET {
  $$ = nodes++; node_names[$$] = "MethodDeclarator";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Identifier("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($2).n = nodes++; s = "Separator("+string((char*)($2).str)+")"; node_names[($2).n] = s; child.push_back(make_pair(($2).n, node_names[($2).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($3, node_names[$3]));
  parents.push_back(make_pair($$, node_names[$$])); ($4).n = nodes++; s = "Separator("+string((char*)($4).str)+")"; node_names[($4).n] = s; child.push_back(make_pair(($4).n, node_names[($4).n]));
}
|MethodDeclarator OPENSQUAREBRACKET CLOSESQUAREBRACKET {
  $$ = nodes++; node_names[$$] = "MethodDeclarator";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  parents.push_back(make_pair($$, node_names[$$])); ($2).n = nodes++; s = "Separator("+string((char*)($2).str)+")"; node_names[($2).n] = s; child.push_back(make_pair(($2).n, node_names[($2).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($3).n = nodes++; s = "Separator("+string((char*)($3).str)+")"; node_names[($3).n] = s; child.push_back(make_pair(($3).n, node_names[($3).n]));
};

FormalParameterList:
FormalParameter {
  $$ = nodes++; node_names[$$] = "FormalParameterList";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
}
|FormalParameterList COMMA FormalParameter {
  $$ = nodes++; node_names[$$] = "FormalParameterList";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  parents.push_back(make_pair($$, node_names[$$])); ($2).n = nodes++; s = "Separator("+string((char*)($2).str)+")"; node_names[($2).n] = s; child.push_back(make_pair(($2).n, node_names[($2).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($3, node_names[$3]));
};

FormalParameter:
Type VariableDeclaratorId {
  $$ = nodes++; node_names[$$] = "FormalParameter";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($2, node_names[$2]));
};

Throws:
THROWS ClassTypeList {
  $$ = nodes++; node_names[$$] = "Throws";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Keyword("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($2, node_names[$2]));
};

ClassTypeList:
ClassType  {
  $$ = nodes++; node_names[$$] = "ClassTypeList";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
}
|ClassTypeList COMMA ClassType {
  $$ = nodes++; node_names[$$] = "ClassTypeList";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  parents.push_back(make_pair($$, node_names[$$])); ($2).n = nodes++; s = "Separator("+string((char*)($2).str)+")"; node_names[($2).n] = s; child.push_back(make_pair(($2).n, node_names[($2).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($3, node_names[$3]));
};

MethodBody:
Block  {
  $$ = nodes++; node_names[$$] = "MethodBody";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
}
|SEMICOLON {
  $$ = nodes++; node_names[$$] = "MethodBody";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Separator("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
};

StaticInitializer:
STATIC Block {
  $$ = nodes++; node_names[$$] = "StaticInitializer";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Keyword("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($2, node_names[$2]));
};



ConstructorDeclaration:
Modifiers ConstructorDeclarator Throws ConstructorBody {
  $$ = nodes++; node_names[$$] = "ConstructorDeclaration";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($2, node_names[$2]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($3, node_names[$3]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($4, node_names[$4]));
}
|Modifiers ConstructorDeclarator ConstructorBody {
  $$ = nodes++; node_names[$$] = "ConstructorDeclaration";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($2, node_names[$2]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($3, node_names[$3]));
}
|ConstructorDeclarator Throws ConstructorBody {
  $$ = nodes++; node_names[$$] = "ConstructorDeclaration";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($2, node_names[$2]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($3, node_names[$3]));
}
|ConstructorDeclarator ConstructorBody {
  $$ = nodes++; node_names[$$] = "ConstructorDeclaration";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($2, node_names[$2]));
}


ConstructorDeclarator:
SimpleName OPENBRACKET FormalParameterList CLOSEBRACKET {
  $$ = nodes++; node_names[$$] = "ConstructorDeclarator";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  parents.push_back(make_pair($$, node_names[$$])); ($2).n = nodes++; s = "Separator("+string((char*)($2).str)+")"; node_names[($2).n] = s; child.push_back(make_pair(($2).n, node_names[($2).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($3, node_names[$3]));
  parents.push_back(make_pair($$, node_names[$$])); ($4).n = nodes++; s = "Separator("+string((char*)($4).str)+")"; node_names[($4).n] = s; child.push_back(make_pair(($4).n, node_names[($4).n]));
}
|SimpleName OPENBRACKET CLOSEBRACKET {
  $$ = nodes++; node_names[$$] = "ConstructorDeclarator";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  parents.push_back(make_pair($$, node_names[$$])); ($2).n = nodes++; s = "Separator("+string((char*)($2).str)+")"; node_names[($2).n] = s; child.push_back(make_pair(($2).n, node_names[($2).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($3).n = nodes++; s = "Separator("+string((char*)($3).str)+")"; node_names[($3).n] = s; child.push_back(make_pair(($3).n, node_names[($3).n]));
};

ConstructorBody:
OPENCURLYBRACKET ExplicitConstructorInvocation BlockStatements CLOSECURLYBRACKET {
  $$ = nodes++; node_names[$$] = "ConstructorBody";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Separator("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($2, node_names[$2]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($3, node_names[$3]));
  parents.push_back(make_pair($$, node_names[$$])); ($4).n = nodes++; s = "Separator("+string((char*)($4).str)+")"; node_names[($4).n] = s; child.push_back(make_pair(($4).n, node_names[($4).n]));
}
|OPENCURLYBRACKET BlockStatements CLOSECURLYBRACKET {
  $$ = nodes++; node_names[$$] = "ConstructorBody";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Separator("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($2, node_names[$2]));
  parents.push_back(make_pair($$, node_names[$$])); ($3).n = nodes++; s = "Separator("+string((char*)($3).str)+")"; node_names[($3).n] = s; child.push_back(make_pair(($3).n, node_names[($3).n]));
}
|OPENCURLYBRACKET ExplicitConstructorInvocation CLOSECURLYBRACKET {
  $$ = nodes++; node_names[$$] = "ConstructorBody";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Separator("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($2, node_names[$2]));
  parents.push_back(make_pair($$, node_names[$$])); ($3).n = nodes++; s = "Separator("+string((char*)($3).str)+")"; node_names[($3).n] = s; child.push_back(make_pair(($3).n, node_names[($3).n]));
}
|OPENCURLYBRACKET CLOSECURLYBRACKET {
  $$ = nodes++; node_names[$$] = "ConstructorBody";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Separator("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($2).n = nodes++; s = "Separator("+string((char*)($2).str)+")"; node_names[($2).n] = s; child.push_back(make_pair(($2).n, node_names[($2).n]));
};

ExplicitConstructorInvocation:
THIS OPENBRACKET ArgumentList CLOSEBRACKET SEMICOLON {
  $$ = nodes++; node_names[$$] = "ExplicitConstructorInvocation";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Keyword("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($2).n = nodes++; s = "Separator("+string((char*)($2).str)+")"; node_names[($2).n] = s; child.push_back(make_pair(($2).n, node_names[($2).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($3, node_names[$3]));
  parents.push_back(make_pair($$, node_names[$$])); ($4).n = nodes++; s = "Separator("+string((char*)($4).str)+")"; node_names[($4).n] = s; child.push_back(make_pair(($4).n, node_names[($4).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($5).n = nodes++; s = "Separator("+string((char*)($5).str)+")"; node_names[($5).n] = s; child.push_back(make_pair(($5).n, node_names[($5).n]));
}
|THIS OPENBRACKET CLOSEBRACKET SEMICOLON {
  $$ = nodes++; node_names[$$] = "ExplicitConstructorInvocation";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Keyword("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($2).n = nodes++; s = "Separator("+string((char*)($2).str)+")"; node_names[($2).n] = s; child.push_back(make_pair(($2).n, node_names[($2).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($3).n = nodes++; s = "Separator("+string((char*)($3).str)+")"; node_names[($3).n] = s; child.push_back(make_pair(($3).n, node_names[($3).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($4).n = nodes++; s = "Separator("+string((char*)($4).str)+")"; node_names[($4).n] = s; child.push_back(make_pair(($4).n, node_names[($4).n]));
}
|SUPER OPENBRACKET ArgumentList CLOSEBRACKET SEMICOLON {
  $$ = nodes++; node_names[$$] = "ExplicitConstructorInvocation";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Keyword("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($2).n = nodes++; s = "Separator("+string((char*)($2).str)+")"; node_names[($2).n] = s; child.push_back(make_pair(($2).n, node_names[($2).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($3, node_names[$3]));
  parents.push_back(make_pair($$, node_names[$$])); ($4).n = nodes++; s = "Separator("+string((char*)($4).str)+")"; node_names[($4).n] = s; child.push_back(make_pair(($4).n, node_names[($4).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($5).n = nodes++; s = "Separator("+string((char*)($5).str)+")"; node_names[($5).n] = s; child.push_back(make_pair(($5).n, node_names[($5).n]));
}
|SUPER OPENBRACKET CLOSEBRACKET SEMICOLON {
  $$ = nodes++; node_names[$$] = "ExplicitConstructorInvocation";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Keyword("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($2).n = nodes++; s = "Separator("+string((char*)($2).str)+")"; node_names[($2).n] = s; child.push_back(make_pair(($2).n, node_names[($2).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($3).n = nodes++; s = "Separator("+string((char*)($3).str)+")"; node_names[($3).n] = s; child.push_back(make_pair(($3).n, node_names[($3).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($4).n = nodes++; s = "Separator("+string((char*)($4).str)+")"; node_names[($4).n] = s; child.push_back(make_pair(($4).n, node_names[($4).n]));
};


InterfaceDeclaration:
Modifiers INTERFACE Identifier ExtendsInterfaces InterfaceBody {
  $$ = nodes++; node_names[$$] = "InterfaceDeclaration";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  parents.push_back(make_pair($$, node_names[$$])); ($2).n = nodes++; s = "Keyword("+string((char*)($2).str)+")"; node_names[($2).n] = s; child.push_back(make_pair(($2).n, node_names[($2).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($3).n = nodes++; s = "Identifier("+string((char*)($3).str)+")"; node_names[($3).n] = s; child.push_back(make_pair(($3).n, node_names[($3).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($4, node_names[$4]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($5, node_names[$5]));
}
|INTERFACE Identifier ExtendsInterfaces InterfaceBody {
  $$ = nodes++; node_names[$$] = "InterfaceDeclaration";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Keyword("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($2).n = nodes++; s = "Identifier("+string((char*)($2).str)+")"; node_names[($2).n] = s; child.push_back(make_pair(($2).n, node_names[($2).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($3, node_names[$3]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($4, node_names[$4]));
}
|Modifiers INTERFACE Identifier InterfaceBody {
  $$ = nodes++; node_names[$$] = "InterfaceDeclaration";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  parents.push_back(make_pair($$, node_names[$$])); ($2).n = nodes++; s = "Keyword("+string((char*)($2).str)+")"; node_names[($2).n] = s; child.push_back(make_pair(($2).n, node_names[($2).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($3).n = nodes++; s = "Identifier("+string((char*)($3).str)+")"; node_names[($3).n] = s; child.push_back(make_pair(($3).n, node_names[($3).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($4, node_names[$4]));
}
|INTERFACE Identifier InterfaceBody {
  $$ = nodes++; node_names[$$] = "InterfaceDeclaration";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Keyword("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($2).n = nodes++; s = "Identifier("+string((char*)($2).str)+")"; node_names[($2).n] = s; child.push_back(make_pair(($2).n, node_names[($2).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($3, node_names[$3]));
};

ExtendsInterfaces:
EXTENDS InterfaceType {
  $$ = nodes++; node_names[$$] = "ExtendsInterfaces";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Keyword("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($2, node_names[$2]));
  }
|ExtendsInterfaces COMMA InterfaceType {
  $$ = nodes++; node_names[$$] = "ExtendsInterfaces";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  parents.push_back(make_pair($$, node_names[$$])); ($2).n = nodes++; s = "Separator("+string((char*)($2).str)+")"; node_names[($2).n] = s; child.push_back(make_pair(($2).n, node_names[($2).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($3, node_names[$3]));
  };

InterfaceBody:
OPENCURLYBRACKET CLOSECURLYBRACKET {
  $$ = nodes++; node_names[$$] = "InterfaceBody";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Separator("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($2).n = nodes++; s = "Separator("+string((char*)($2).str)+")"; node_names[($2).n] = s; child.push_back(make_pair(($2).n, node_names[($2).n]));
  }
|OPENCURLYBRACKET InterfaceMemberDeclarations CLOSECURLYBRACKET {
  $$ = nodes++; node_names[$$] = "InterfaceBody";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Separator("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($2, node_names[$2]));
  parents.push_back(make_pair($$, node_names[$$])); ($3).n = nodes++; s = "Separator("+string((char*)($3).str)+")"; node_names[($3).n] = s; child.push_back(make_pair(($3).n, node_names[($3).n]));
  }

InterfaceMemberDeclarations:
InterfaceMemberDeclaration {
  $$ = nodes++; node_names[$$] = "InterfaceMemberDeclarations";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  }
|InterfaceMemberDeclarations InterfaceMemberDeclaration {
  $$ = nodes++; node_names[$$] = "InterfaceMemberDeclarations";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($2, node_names[$2]));
  };

InterfaceMemberDeclaration:
ConstantDeclaration {
  $$ = nodes++; node_names[$$] = "InterfaceMemberDeclaration";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  }
|AbstractMethodDeclaration {
  $$ = nodes++; node_names[$$] = "InterfaceMemberDeclaration";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  };

ConstantDeclaration:
FieldDeclaration {
  $$ = nodes++; node_names[$$] = "ConstantDeclaration";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  };

AbstractMethodDeclaration:
MethodHeader SEMICOLON {
  $$ = nodes++; node_names[$$] = "AbstractMethodDeclaration";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  parents.push_back(make_pair($$, node_names[$$])); ($2).n = nodes++; s = "Separator("+string((char*)($2).str)+")"; node_names[($2).n] = s; child.push_back(make_pair(($2).n, node_names[($2).n]));
  };

ArrayInitializer:
OPENCURLYBRACKET VariableInitializers COMMA CLOSECURLYBRACKET {
  $$ = nodes++; node_names[$$] = "ArrayInitializer";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Separator("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($2, node_names[$2]));
  parents.push_back(make_pair($$, node_names[$$])); ($3).n = nodes++; s = "Separator("+string((char*)($3).str)+")"; node_names[($3).n] = s; child.push_back(make_pair(($3).n, node_names[($3).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($4).n = nodes++; s = "Separator("+string((char*)($4).str)+")"; node_names[($4).n] = s; child.push_back(make_pair(($4).n, node_names[($4).n]));
  }
|OPENCURLYBRACKET COMMA CLOSECURLYBRACKET {
  $$ = nodes++; node_names[$$] = "ArrayInitializer";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Separator("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($2).n = nodes++; s = "Separator("+string((char*)($2).str)+")"; node_names[($2).n] = s; child.push_back(make_pair(($2).n, node_names[($2).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($3).n = nodes++; s = "Separator("+string((char*)($3).str)+")"; node_names[($3).n] = s; child.push_back(make_pair(($3).n, node_names[($3).n]));
  }
|OPENCURLYBRACKET VariableInitializers CLOSECURLYBRACKET {
  $$ = nodes++; node_names[$$] = "ArrayInitializer";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Separator("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($2, node_names[$2]));
  parents.push_back(make_pair($$, node_names[$$])); ($3).n = nodes++; s = "Separator("+string((char*)($3).str)+")"; node_names[($3).n] = s; child.push_back(make_pair(($3).n, node_names[($3).n]));
  }
|OPENCURLYBRACKET CLOSECURLYBRACKET {
  $$ = nodes++; node_names[$$] = "ArrayInitializer";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Separator("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($2).n = nodes++; s = "Separator("+string((char*)($2).str)+")"; node_names[($2).n] = s; child.push_back(make_pair(($2).n, node_names[($2).n]));
  };

VariableInitializers:
VariableInitializer {
  $$ = nodes++; node_names[$$] = "VariableInitializers";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  }
|VariableInitializers COMMA VariableInitializer {
  $$ = nodes++; node_names[$$] = "VariableInitializers";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  parents.push_back(make_pair($$, node_names[$$])); ($2).n = nodes++; s = "Separator("+string((char*)($2).str)+")"; node_names[($2).n] = s; child.push_back(make_pair(($2).n, node_names[($2).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($3, node_names[$3]));
  };


Block:
OPENCURLYBRACKET BlockStatements CLOSECURLYBRACKET {
  $$ = nodes++; node_names[$$] = "Block";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Separator("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($2, node_names[$2]));
  parents.push_back(make_pair($$, node_names[$$])); ($3).n = nodes++; s = "Separator("+string((char*)($3).str)+")"; node_names[($3).n] = s; child.push_back(make_pair(($3).n, node_names[($3).n]));
  }
|OPENCURLYBRACKET CLOSECURLYBRACKET {
  $$ = nodes++; node_names[$$] = "Block";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Separator("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($2).n = nodes++; s = "Separator("+string((char*)($2).str)+")"; node_names[($2).n] = s; child.push_back(make_pair(($2).n, node_names[($2).n]));
  };

BlockStatements:
BlockStatement {
  $$ = nodes++; node_names[$$] = "BlockStatements";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  }
|BlockStatements BlockStatement {
  $$ = nodes++; node_names[$$] = "BlockStatements";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($2, node_names[$2]));
  };

BlockStatement:
LocalVariableDeclarationStatement {
  $$ = nodes++; node_names[$$] = "BlockStatement";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  }
|Statement {
  $$ = nodes++; node_names[$$] = "BlockStatement";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  };

LocalVariableDeclarationStatement:
LocalVariableDeclaration SEMICOLON {
  $$ = nodes++; node_names[$$] = "LocalVariableDeclarationStatement";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  parents.push_back(make_pair($$, node_names[$$])); ($2).n = nodes++; s = "Separator("+string((char*)($2).str)+")"; node_names[($2).n] = s; child.push_back(make_pair(($2).n, node_names[($2).n]));
  };

LocalVariableDeclaration:
Type VariableDeclarators {
  $$ = nodes++; node_names[$$] = "LocalVariableDeclaration";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($2, node_names[$2]));
  };

Statement:
StatementWithoutTrailingSubstatement {
  $$ = nodes++; node_names[$$] = "Statement";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  }
|LabeledStatement {
  $$ = nodes++; node_names[$$] = "Statement";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  }
|IfThenStatement {
  $$ = nodes++; node_names[$$] = "Statement";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  }
|IfThenElseStatement {
  $$ = nodes++; node_names[$$] = "Statement";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  }
|WhileStatement {
  $$ = nodes++; node_names[$$] = "Statement";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  }
|ForStatement {
  $$ = nodes++; node_names[$$] = "Statement";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  };

StatementNoShortIf:
StatementWithoutTrailingSubstatement {
  $$ = nodes++; node_names[$$] = "StatementNoShortIf";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  }
|LabeledStatementNoShortIf {
  $$ = nodes++; node_names[$$] = "StatementNoShortIf";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  }
|IfThenElseStatementNoShortIf {
  $$ = nodes++; node_names[$$] = "StatementNoShortIf";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  }
|WhileStatementNoShortIf {
  $$ = nodes++; node_names[$$] = "StatementNoShortIf";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  }
|ForStatementNoShortIf {
  $$ = nodes++; node_names[$$] = "StatementNoShortIf";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  };

StatementWithoutTrailingSubstatement:
Block {
  $$ = nodes++; node_names[$$] = "StatementWithoutTrailingSubstatement";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  }
|EmptyStatement {
  $$ = nodes++; node_names[$$] = "StatementWithoutTrailingSubstatement";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  }
|ExpressionStatement {
  $$ = nodes++; node_names[$$] = "StatementWithoutTrailingSubstatement";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  }
|SwitchStatement {
  $$ = nodes++; node_names[$$] = "StatementWithoutTrailingSubstatement";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  }
|DoStatement {
  $$ = nodes++; node_names[$$] = "StatementWithoutTrailingSubstatement";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  }
|BreakStatement {
  $$ = nodes++; node_names[$$] = "StatementWithoutTrailingSubstatement";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  }
|ContinueStatement {
  $$ = nodes++; node_names[$$] = "StatementWithoutTrailingSubstatement";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  }
|ReturnStatement {
  $$ = nodes++; node_names[$$] = "StatementWithoutTrailingSubstatement";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  }
|SynchronizedStatement {
  $$ = nodes++; node_names[$$] = "StatementWithoutTrailingSubstatement";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  }
|ThrowStatement {
  $$ = nodes++; node_names[$$] = "StatementWithoutTrailingSubstatement";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  }
|TryStatement {
  $$ = nodes++; node_names[$$] = "StatementWithoutTrailingSubstatement";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  };

EmptyStatement:
SEMICOLON {
  $$ = nodes++; node_names[$$] = "EmptyStatement";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Separator("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
};

LabeledStatement:
Identifier COLON Statement {
  $$ = nodes++; node_names[$$] = "LabeledStatement";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Identifier("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($2).n = nodes++; s = "Separator("+string((char*)($2).str)+")"; node_names[($2).n] = s; child.push_back(make_pair(($2).n, node_names[($2).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($3, node_names[$3]));
  };

LabeledStatementNoShortIf:
Identifier COLON StatementNoShortIf {
  $$ = nodes++; node_names[$$] = "LabeledStatementNoShortIf";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Identifier("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($2).n = nodes++; s = "Separator("+string((char*)($2).str)+")"; node_names[($2).n] = s; child.push_back(make_pair(($2).n, node_names[($2).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($3, node_names[$3]));
  };

ExpressionStatement:
StatementExpression SEMICOLON {
  $$ = nodes++; node_names[$$] = "ExpressionStatement";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  parents.push_back(make_pair($$, node_names[$$])); ($2).n = nodes++; s = "Separator("+string((char*)($2).str)+")"; node_names[($2).n] = s; child.push_back(make_pair(($2).n, node_names[($2).n]));
  };

StatementExpression:
Assignment {
  $$ = nodes++; node_names[$$] = "StatementExpression";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  }
|PreIncrementExpression {
  $$ = nodes++; node_names[$$] = "StatementExpression";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  }
|PreDecrementExpression {
  $$ = nodes++; node_names[$$] = "StatementExpression";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  }
|PostIncrementExpression {
  $$ = nodes++; node_names[$$] = "StatementExpression";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  }
|PostDecrementExpression {
  $$ = nodes++; node_names[$$] = "StatementExpression";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  }
|MethodInvocation {
  $$ = nodes++; node_names[$$] = "StatementExpression";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  }
|ClassInstanceCreationExpression {
  $$ = nodes++; node_names[$$] = "StatementExpression";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  };

IfThenStatement:
IF OPENBRACKET Expression CLOSEBRACKET Statement {
  $$ = nodes++; node_names[$$] = "IfThenStatement";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Keyword("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($2).n = nodes++; s = "Separator("+string((char*)($2).str)+")"; node_names[($2).n] = s; child.push_back(make_pair(($2).n, node_names[($2).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($3, node_names[$3]));
  parents.push_back(make_pair($$, node_names[$$])); ($4).n = nodes++; s = "Separator("+string((char*)($4).str)+")"; node_names[($4).n] = s; child.push_back(make_pair(($4).n, node_names[($4).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($5, node_names[$5]));
  };

IfThenElseStatement:
IF OPENBRACKET Expression CLOSEBRACKET StatementNoShortIf ELSE Statement {
  $$ = nodes++; node_names[$$] = "IfThenElseStatement";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Keyword("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($2).n = nodes++; s = "Separator("+string((char*)($2).str)+")"; node_names[($2).n] = s; child.push_back(make_pair(($2).n, node_names[($2).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($3, node_names[$3]));
  parents.push_back(make_pair($$, node_names[$$])); ($4).n = nodes++; s = "Separator("+string((char*)($4).str)+")"; node_names[($4).n] = s; child.push_back(make_pair(($4).n, node_names[($4).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($5, node_names[$5]));
  parents.push_back(make_pair($$, node_names[$$])); ($6).n = nodes++; s = "Keyword("+string((char*)($6).str)+")"; node_names[($6).n] = s; child.push_back(make_pair(($6).n, node_names[($6).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($7, node_names[$7]));
  };

IfThenElseStatementNoShortIf:
IF OPENBRACKET Expression CLOSEBRACKET StatementNoShortIf ELSE StatementNoShortIf {
  $$ = nodes++; node_names[$$] = "IfThenElseStatementNoShortIf";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Keyword("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($2).n = nodes++; s = "Separator("+string((char*)($2).str)+")"; node_names[($2).n] = s; child.push_back(make_pair(($2).n, node_names[($2).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($3, node_names[$3]));
  parents.push_back(make_pair($$, node_names[$$])); ($4).n = nodes++; s = "Separator("+string((char*)($4).str)+")"; node_names[($4).n] = s; child.push_back(make_pair(($4).n, node_names[($4).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($5, node_names[$5]));
  parents.push_back(make_pair($$, node_names[$$])); ($6).n = nodes++; s = "Keyword("+string((char*)($1).str)+")"; node_names[($6).n] = s; child.push_back(make_pair(($6).n, node_names[($6).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($7, node_names[$7]));
  };

SwitchStatement:
SWITCH OPENBRACKET Expression CLOSEBRACKET SwitchBlock {
  $$ = nodes++; node_names[$$] = "SwitchStatement";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Keyword("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($2).n = nodes++; s = "Separator("+string((char*)($2).str)+")"; node_names[($2).n] = s; child.push_back(make_pair(($2).n, node_names[($2).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($3, node_names[$3]));
  parents.push_back(make_pair($$, node_names[$$])); ($4).n = nodes++; s = "Separator("+string((char*)($4).str)+")"; node_names[($4).n] = s; child.push_back(make_pair(($4).n, node_names[($4).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($5, node_names[$5]));
  };

SwitchBlock:
OPENCURLYBRACKET SwitchBlockStatementGroups SwitchLabels CLOSECURLYBRACKET {
  $$ = nodes++; node_names[$$] = "SwitchBlock";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++;s = "Separator("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($2, node_names[$2]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($3, node_names[$3]));
  parents.push_back(make_pair($$, node_names[$$])); ($4).n = nodes++; s = "Separator("+string((char*)($4).str)+")"; node_names[($4).n] = s; child.push_back(make_pair(($4).n, node_names[($4).n]));
  }
|OPENCURLYBRACKET SwitchLabels CLOSECURLYBRACKET {
  $$ = nodes++; node_names[$$] = "SwitchBlock";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Separator("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($2, node_names[$2]));
  parents.push_back(make_pair($$, node_names[$$])); ($3).n = nodes++; s = "Separator("+string((char*)($3).str)+")"; node_names[($3).n] = s; child.push_back(make_pair(($3).n, node_names[($3).n]));
  }
|OPENCURLYBRACKET SwitchBlockStatementGroups CLOSECURLYBRACKET {
  $$ = nodes++; node_names[$$] = "SwitchBlock";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Separator("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($2, node_names[$2]));
  parents.push_back(make_pair($$, node_names[$$])); ($3).n = nodes++; s = "Separator("+string((char*)($3).str)+")"; node_names[($3).n] = s; child.push_back(make_pair(($3).n, node_names[($3).n]));
  }
|OPENCURLYBRACKET CLOSECURLYBRACKET {
  $$ = nodes++; node_names[$$] = "SwitchBlock";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Separator("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($2).n = nodes++; s = "Separator("+string((char*)($2).str)+")"; node_names[($2).n] = s; child.push_back(make_pair(($2).n, node_names[($2).n]));
  };

SwitchBlockStatementGroups:
SwitchBlockStatementGroup {
  $$ = nodes++; node_names[$$] = "SwitchBlockStatementGroups";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  }
|SwitchBlockStatementGroups SwitchBlockStatementGroup {
  $$ = nodes++; node_names[$$] = "SwitchBlockStatementGroups";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($2, node_names[$2]));
  }

SwitchBlockStatementGroup:
SwitchLabels BlockStatements {
  $$ = nodes++; node_names[$$] = "SwitchBlockStatementGroup";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($2, node_names[$2]));
  };

SwitchLabels:
SwitchLabel  {
  $$ = nodes++; node_names[$$] = "SwitchLabels";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  }
|SwitchLabels SwitchLabel {
  $$ = nodes++; node_names[$$] = "SwitchLabels";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($2, node_names[$2]));
  };

SwitchLabel:
CASE ConstantExpression COLON {
  $$ = nodes++; node_names[$$] = "SwitchLabel";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Keyword("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($2, node_names[$2]));
  parents.push_back(make_pair($$, node_names[$$])); ($3).n = nodes++; s = "Separator("+string((char*)($3).str)+")"; node_names[($3).n] = s; child.push_back(make_pair(($3).n, node_names[($3).n]));
  }
|DEFAULT COLON {
  $$ = nodes++; node_names[$$] = "SwitchLabel";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Keyword("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($2).n = nodes++; s = "Separator("+string((char*)($2).str)+")"; node_names[($2).n] = s; child.push_back(make_pair(($2).n, node_names[($2).n]));
  };

WhileStatement:
WHILE OPENBRACKET Expression CLOSEBRACKET Statement {
  $$ = nodes++; node_names[$$] = "WhileStatement";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Keyword("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($2).n = nodes++; s = "Separator("+string((char*)($2).str)+")"; node_names[($2).n] = s; child.push_back(make_pair(($2).n, node_names[($2).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($3, node_names[$3]));
  parents.push_back(make_pair($$, node_names[$$])); ($4).n = nodes++; s = "Separator("+string((char*)($4).str)+")"; node_names[($4).n] = s; child.push_back(make_pair(($4).n, node_names[($4).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($5, node_names[$5]));
  };

WhileStatementNoShortIf:
WHILE OPENBRACKET Expression CLOSEBRACKET StatementNoShortIf {
  $$ = nodes++; node_names[$$] = "WhileStatementNoShortIf";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Keyword("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($2).n = nodes++; s = "Separator("+string((char*)($2).str)+")"; node_names[($2).n] = s; child.push_back(make_pair(($2).n, node_names[($2).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($3, node_names[$3]));
  parents.push_back(make_pair($$, node_names[$$])); ($4).n = nodes++; s = "Separator("+string((char*)($4).str)+")"; node_names[($4).n] = s; child.push_back(make_pair(($4).n, node_names[($4).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($5, node_names[$5]));
  };

DoStatement:
DO Statement WHILE OPENBRACKET Expression CLOSEBRACKET SEMICOLON {
  $$ = nodes++; node_names[$$] = "DoStatement";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Keyword("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($2, node_names[$2]));
  parents.push_back(make_pair($$, node_names[$$])); ($3).n = nodes++; s = "Keyword("+string((char*)($3).str)+")"; node_names[($3).n] = s; child.push_back(make_pair(($3).n, node_names[($3).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($4).n = nodes++; s = "Separator("+string((char*)($4).str)+")"; node_names[($4).n] = s; child.push_back(make_pair(($4).n, node_names[($4).n]));
  parents.push_back(make_pair($$, node_names[$$]));  child.push_back(make_pair($5, node_names[$5]));
  parents.push_back(make_pair($$, node_names[$$])); ($6).n = nodes++; s = "Separator("+string((char*)($6).str)+")"; node_names[($6).n] = s; child.push_back(make_pair(($6).n, node_names[($6).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($7).n = nodes++; s = "Separator("+string((char*)($7).str)+")"; node_names[($7).n] = s; child.push_back(make_pair(($7).n, node_names[($7).n]));
  };

ForStatement:
FOR OPENBRACKET SEMICOLON Expression SEMICOLON ForUpdate CLOSEBRACKET Statement {
  $$ = nodes++; node_names[$$] = "ForStatement";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Keyword("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($2).n = nodes++; s = "Separator("+string((char*)($2).str)+")"; node_names[($2).n] = s; child.push_back(make_pair(($2).n, node_names[($2).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($3).n = nodes++; s = "Separator("+string((char*)($3).str)+")"; node_names[($3).n] = s; child.push_back(make_pair(($3).n, node_names[($3).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($4, node_names[$4]));
  parents.push_back(make_pair($$, node_names[$$])); ($5).n = nodes++; s = "Separator("+string((char*)($5).str)+")"; node_names[($5).n] = s; child.push_back(make_pair(($5).n, node_names[($5).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($6, node_names[$6]));
  parents.push_back(make_pair($$, node_names[$$])); ($7).n = nodes++; s = "Separator("+string((char*)($7).str)+")"; node_names[($7).n] = s; child.push_back(make_pair(($7).n, node_names[($7).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($8, node_names[$8]));
  }
|FOR OPENBRACKET ForInit SEMICOLON SEMICOLON ForUpdate CLOSEBRACKET Statement {
  $$ = nodes++; node_names[$$] = "ForStatement";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Keyword("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($2).n = nodes++; s = "Separator("+string((char*)($2).str)+")"; node_names[($2).n] = s; child.push_back(make_pair(($2).n, node_names[($2).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($3, node_names[$3]));
  parents.push_back(make_pair($$, node_names[$$])); ($4).n = nodes++; s = "Separator("+string((char*)($4).str)+")"; node_names[($4).n] = s; child.push_back(make_pair(($4).n, node_names[($4).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($5).n = nodes++; s = "Separator("+string((char*)($5).str)+")"; node_names[($5).n] = s; child.push_back(make_pair(($5).n, node_names[($5).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($6, node_names[$6]));
  parents.push_back(make_pair($$, node_names[$$])); ($7).n = nodes++; s = "Separator("+string((char*)($7).str)+")"; node_names[($7).n] = s; child.push_back(make_pair(($7).n, node_names[($7).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($8, node_names[$8]));
  }
|FOR OPENBRACKET ForInit SEMICOLON Expression SEMICOLON CLOSEBRACKET Statement {
  $$ = nodes++; node_names[$$] = "ForStatement";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Keyword("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($2).n = nodes++; s = "Separator("+string((char*)($2).str)+")"; node_names[($2).n] = s; child.push_back(make_pair(($2).n, node_names[($2).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($3, node_names[$3]));
  parents.push_back(make_pair($$, node_names[$$])); ($4).n = nodes++; s = "Separator("+string((char*)($4).str)+")"; node_names[($4).n] = s; child.push_back(make_pair(($4).n, node_names[($4).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($5, node_names[$5]));
  parents.push_back(make_pair($$, node_names[$$])); ($6).n = nodes++; s = "Separator("+string((char*)($6).str)+")"; node_names[($6).n] = s; child.push_back(make_pair(($6).n, node_names[($6).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($7).n = nodes++; s = "Separator("+string((char*)($7).str)+")"; node_names[($7).n] = s; child.push_back(make_pair(($7).n, node_names[($7).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($8, node_names[$8]));
  }
|FOR OPENBRACKET SEMICOLON SEMICOLON ForUpdate CLOSEBRACKET Statement {
  $$ = nodes++; node_names[$$] = "ForStatement";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Keyword("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($2).n = nodes++; s = "Separator("+string((char*)($2).str)+")"; node_names[($2).n] = s; child.push_back(make_pair(($2).n, node_names[($2).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($3).n = nodes++; s = "Separator("+string((char*)($3).str)+")"; node_names[($3).n] = s; child.push_back(make_pair(($3).n, node_names[($3).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($4).n = nodes++; s = "Separator("+string((char*)($4).str)+")"; node_names[($4).n] = s; child.push_back(make_pair(($4).n, node_names[($4).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($5, node_names[$5]));
  parents.push_back(make_pair($$, node_names[$$])); ($6).n = nodes++; s = "Separator("+string((char*)($6).str)+")"; node_names[($6).n] = s; child.push_back(make_pair(($6).n, node_names[($6).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($7, node_names[$7]));
  }
|FOR OPENBRACKET ForInit SEMICOLON SEMICOLON CLOSEBRACKET Statement {
  $$ = nodes++; node_names[$$] = "ForStatement";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Keyword("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($2).n = nodes++; s = "Separator("+string((char*)($2).str)+")"; node_names[($2).n] = s; child.push_back(make_pair(($2).n, node_names[($2).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($3, node_names[$3]));
  parents.push_back(make_pair($$, node_names[$$])); ($4).n = nodes++; s = "Separator("+string((char*)($4).str)+")"; node_names[($4).n] = s; child.push_back(make_pair(($4).n, node_names[($4).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($5).n = nodes++; s = "Separator("+string((char*)($5).str)+")"; node_names[($5).n] = s; child.push_back(make_pair(($5).n, node_names[($5).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($6).n = nodes++; s = "Separator("+string((char*)($6).str)+")"; node_names[($6).n] = s; child.push_back(make_pair(($6).n, node_names[($6).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($7, node_names[$7]));
  }
|FOR OPENBRACKET SEMICOLON Expression SEMICOLON CLOSEBRACKET Statement {
  $$ = nodes++; node_names[$$] = "ForStatement";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Keyword("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($2).n = nodes++; s = "Separator("+string((char*)($2).str)+")"; node_names[($2).n] = s; child.push_back(make_pair(($2).n, node_names[($2).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($3).n = nodes++; s = "Separator("+string((char*)($3).str)+")"; node_names[($3).n] = s; child.push_back(make_pair(($3).n, node_names[($3).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($4, node_names[$4]));
  parents.push_back(make_pair($$, node_names[$$])); ($5).n = nodes++; s = "Separator("+string((char*)($5).str)+")"; node_names[($5).n] = s; child.push_back(make_pair(($5).n, node_names[($5).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($6).n = nodes++; s = "Separator("+string((char*)($6).str)+")"; node_names[($6).n] = s; child.push_back(make_pair(($6).n, node_names[($6).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($7, node_names[$7]));
  }
|FOR OPENBRACKET SEMICOLON SEMICOLON CLOSEBRACKET Statement {
  $$ = nodes++; node_names[$$] = "ForStatement";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Keyword("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($2).n = nodes++; s = "Separator("+string((char*)($2).str)+")"; node_names[($2).n] = s; child.push_back(make_pair(($2).n, node_names[($2).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($3).n = nodes++; s = "Separator("+string((char*)($3).str)+")"; node_names[($3).n] = s; child.push_back(make_pair(($3).n, node_names[($3).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($4).n = nodes++; s = "Separator("+string((char*)($4).str)+")"; node_names[($4).n] = s; child.push_back(make_pair(($4).n, node_names[($4).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($5).n = nodes++; s = "Separator("+string((char*)($5).str)+")"; node_names[($5).n] = s; child.push_back(make_pair(($5).n, node_names[($5).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($6, node_names[$6]));
  }
|FOR OPENBRACKET ForInit SEMICOLON Expression SEMICOLON ForUpdate CLOSEBRACKET Statement {
  $$ = nodes++; node_names[$$] = "ForStatement";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Keyword("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($2).n = nodes++; s = "Separator("+string((char*)($2).str)+")"; node_names[($2).n] = s; child.push_back(make_pair(($2).n, node_names[($2).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($3, node_names[$3]));
  parents.push_back(make_pair($$, node_names[$$])); ($4).n = nodes++; s = "Separator("+string((char*)($4).str)+")"; node_names[($4).n] = s; child.push_back(make_pair(($4).n, node_names[($4).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($5, node_names[$5]));
  parents.push_back(make_pair($$, node_names[$$])); ($6).n = nodes++; s = "Separator("+string((char*)($6).str)+")"; node_names[($6).n] = s; child.push_back(make_pair(($6).n, node_names[($6).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($7, node_names[$7]));
  parents.push_back(make_pair($$, node_names[$$])); ($8).n = nodes++; s = "Separator("+string((char*)($8).str)+")"; node_names[($8).n] = s; child.push_back(make_pair(($8).n, node_names[($8).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($9, node_names[$9]));
  };

ForStatementNoShortIf:
FOR OPENBRACKET SEMICOLON Expression SEMICOLON ForUpdate CLOSEBRACKET StatementNoShortIf {
  $$ = nodes++; node_names[$$] = "ForStatementNoShortIf";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Keyword("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($2).n = nodes++; s = "Separator("+string((char*)($2).str)+")"; node_names[($2).n] = s; child.push_back(make_pair(($2).n, node_names[($2).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($3).n = nodes++; s = s = "Separator("+string((char*)($3).str)+")"; node_names[($3).n] = s; child.push_back(make_pair(($3).n, node_names[($3).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($4, node_names[$4]));
  parents.push_back(make_pair($$, node_names[$$])); ($5).n = nodes++; s = "Separator("+string((char*)($5).str)+")"; node_names[($5).n] = s; child.push_back(make_pair(($5).n, node_names[($5).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($6, node_names[$6]));
  parents.push_back(make_pair($$, node_names[$$])); ($7).n = nodes++; s = "Separator("+string((char*)($7).str)+")"; node_names[($7).n] = s; child.push_back(make_pair(($7).n, node_names[($7).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($8, node_names[$8]));
  }
|FOR OPENBRACKET ForInit SEMICOLON SEMICOLON ForUpdate CLOSEBRACKET StatementNoShortIf {
  $$ = nodes++; node_names[$$] = "ForStatementNoShortIf";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Keyword("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($2).n = nodes++; s = "Separator("+string((char*)($2).str)+")"; node_names[($2).n] = s; child.push_back(make_pair(($2).n, node_names[($2).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($3, node_names[$3]));
  parents.push_back(make_pair($$, node_names[$$])); ($4).n = nodes++; s = "Separator("+string((char*)($4).str)+")"; node_names[($4).n] = s; child.push_back(make_pair(($4).n, node_names[($4).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($5).n = nodes++; s = "Separator("+string((char*)($5).str)+")"; node_names[($5).n] = s; child.push_back(make_pair(($5).n, node_names[($5).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($6, node_names[$6]));
  parents.push_back(make_pair($$, node_names[$$])); ($7).n = nodes++; s = "Separator("+string((char*)($7).str)+")"; node_names[($7).n] = s; child.push_back(make_pair(($7).n, node_names[($7).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($8, node_names[$8]));
  }
|FOR OPENBRACKET ForInit SEMICOLON Expression SEMICOLON CLOSEBRACKET StatementNoShortIf {
  $$ = nodes++; node_names[$$] = "ForStatementNoShortIf";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Keyword("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($2).n = nodes++; s = "Separator("+string((char*)($2).str)+")"; node_names[($2).n] = s; child.push_back(make_pair(($2).n, node_names[($2).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($3, node_names[$3]));
  parents.push_back(make_pair($$, node_names[$$])); ($4).n = nodes++; s = "Separator("+string((char*)($4).str)+")"; node_names[($4).n] = s; child.push_back(make_pair(($4).n, node_names[($4).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($5, node_names[$5]));
  parents.push_back(make_pair($$, node_names[$$])); ($6).n = nodes++; s = "Separator("+string((char*)($6).str)+")"; node_names[($6).n] = s; child.push_back(make_pair(($6).n, node_names[($6).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($7).n = nodes++; s = "Separator("+string((char*)($7).str)+")"; node_names[($7).n] = s; child.push_back(make_pair(($7).n, node_names[($7).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($8, node_names[$8]));
  }
|FOR OPENBRACKET SEMICOLON SEMICOLON ForUpdate CLOSEBRACKET StatementNoShortIf {
  $$ = nodes++; node_names[$$] = "ForStatementNoShortIf";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Keyword("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($2).n = nodes++; s = "Separator("+string((char*)($2).str)+")"; node_names[($2).n] = s; child.push_back(make_pair(($2).n, node_names[($2).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($3).n = nodes++; s = "Separator("+string((char*)($3).str)+")"; node_names[($3).n] = s; child.push_back(make_pair(($3).n, node_names[($3).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($4).n = nodes++; s = "Separator("+string((char*)($4).str)+")"; node_names[($4).n] = s; child.push_back(make_pair(($4).n, node_names[($4).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($5, node_names[$5]));
  parents.push_back(make_pair($$, node_names[$$])); ($6).n = nodes++; s = "Separator("+string((char*)($6).str)+")"; node_names[($6).n] = s; child.push_back(make_pair(($6).n, node_names[($6).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($7, node_names[$7]));
  }
|FOR OPENBRACKET ForInit SEMICOLON SEMICOLON CLOSEBRACKET StatementNoShortIf {
  $$ = nodes++; node_names[$$] = "ForStatementNoShortIf";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Keyword("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($2).n = nodes++; s = "Separator("+string((char*)($2).str)+")"; node_names[($2).n] = s; child.push_back(make_pair(($2).n, node_names[($2).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($3, node_names[$3]));
  parents.push_back(make_pair($$, node_names[$$])); ($4).n = nodes++; s = "Separator("+string((char*)($4).str)+")"; node_names[($4).n] = s; child.push_back(make_pair(($4).n, node_names[($4).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($5).n = nodes++; s = "Separator("+string((char*)($5).str)+")"; node_names[($5).n] = s; child.push_back(make_pair(($5).n, node_names[($5).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($6).n = nodes++; s = "Separator("+string((char*)($6).str)+")"; node_names[($6).n] = s; child.push_back(make_pair(($6).n, node_names[($6).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($7, node_names[$7]));
  }
|FOR OPENBRACKET SEMICOLON Expression SEMICOLON CLOSEBRACKET StatementNoShortIf {
  $$ = nodes++; node_names[$$] = "ForStatementNoShortIf";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Keyword("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($2).n = nodes++; s = "Separator("+string((char*)($2).str)+")"; node_names[($2).n] = s; child.push_back(make_pair(($2).n, node_names[($2).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($3).n = nodes++; s = "Separator("+string((char*)($3).str)+")"; node_names[($3).n] = s; child.push_back(make_pair(($3).n, node_names[($3).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($4, node_names[$4]));
  parents.push_back(make_pair($$, node_names[$$])); ($5).n = nodes++; s = "Separator("+string((char*)($5).str)+")"; node_names[($5).n] = s; child.push_back(make_pair(($5).n, node_names[($5).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($6).n = nodes++; s = "Separator("+string((char*)($6).str)+")"; node_names[($6).n] = s; child.push_back(make_pair(($6).n, node_names[($6).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($7, node_names[$7]));
  }
|FOR OPENBRACKET SEMICOLON SEMICOLON CLOSEBRACKET StatementNoShortIf {
  $$ = nodes++; node_names[$$] = "ForStatementNoShortIf";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Keyword("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($2).n = nodes++; s = "Separator("+string((char*)($2).str)+")"; node_names[($2).n] = s; child.push_back(make_pair(($2).n, node_names[($2).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($3).n = nodes++; s = "Separator("+string((char*)($3).str)+")"; node_names[($3).n] = s; child.push_back(make_pair(($3).n, node_names[($3).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($4).n = nodes++; s = "Separator("+string((char*)($4).str)+")"; node_names[($4).n] = s; child.push_back(make_pair(($4).n, node_names[($4).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($5).n = nodes++; s = "Separator("+string((char*)($5).str)+")"; node_names[($5).n] = s; child.push_back(make_pair(($5).n, node_names[($5).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($6, node_names[$6]));
  }
|FOR OPENBRACKET ForInit SEMICOLON Expression SEMICOLON ForUpdate CLOSEBRACKET StatementNoShortIf {
  $$ = nodes++; node_names[$$] = "ForStatementNoShortIf";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Keyword("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($2).n = nodes++; s = "Separator("+string((char*)($2).str)+")"; node_names[($2).n] = s; child.push_back(make_pair(($2).n, node_names[($2).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($3, node_names[$3]));
  parents.push_back(make_pair($$, node_names[$$])); ($4).n = nodes++; s = "Separator("+string((char*)($4).str)+")"; node_names[($4).n] = s; child.push_back(make_pair(($4).n, node_names[($4).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($5, node_names[$5]));
  parents.push_back(make_pair($$, node_names[$$])); ($6).n = nodes++; s = "Separator("+string((char*)($6).str)+")"; node_names[($6).n] = s; child.push_back(make_pair(($6).n, node_names[($6).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($7, node_names[$7]));
  parents.push_back(make_pair($$, node_names[$$])); ($8).n = nodes++; s = "Separator("+string((char*)($8).str)+")"; node_names[($8).n] = s; child.push_back(make_pair(($8).n, node_names[($8).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($9, node_names[$9]));
  };

ForInit:
StatementExpressionList {
  $$ = nodes++; node_names[$$] = "ForInit";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
}
|LocalVariableDeclaration {
  $$ = nodes++; node_names[$$] = "ForInit";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
};

ForUpdate:
StatementExpressionList {
  $$ = nodes++; node_names[$$] = "ForUpdate";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
};

StatementExpressionList:
StatementExpression {
  $$ = nodes++; node_names[$$] = "StatementExpressionList";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
}
|StatementExpressionList COMMA StatementExpression {
  $$ = nodes++; node_names[$$] = "StatementExpressionList";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  parents.push_back(make_pair($$, node_names[$$])); ($2).n = nodes++; s = "Separator("+string((char*)($2).str)+")"; node_names[($2).n] = s; child.push_back(make_pair(($2).n, node_names[($2).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($3, node_names[$3]));
};

BreakStatement:
BREAK SEMICOLON {
  $$ = nodes++; node_names[$$] = "BreakStatement";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Keyword("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($2).n = nodes++; s = "Separator("+string((char*)($2).str)+")"; node_names[($2).n] = s; child.push_back(make_pair(($2).n, node_names[($2).n]));
}
|BREAK Identifier SEMICOLON {
  $$ = nodes++; node_names[$$] = "BreakStatement";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Keyword("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($2).n = nodes++; s = "Identifier("+string((char*)($2).str)+")"; node_names[($2).n] = s; child.push_back(make_pair(($2).n, node_names[($2).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($3).n = nodes++; s = "Separator("+string((char*)($3).str)+")"; node_names[($3).n] = s; child.push_back(make_pair(($3).n, node_names[($3).n]));
};

ContinueStatement:
CONTINUE Identifier SEMICOLON {
  $$ = nodes++; node_names[$$] = "ContinueStatement";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Keyword("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($2).n = nodes++; s = "Identifier("+string((char*)($2).str)+")"; node_names[($2).n] = s; child.push_back(make_pair(($2).n, node_names[($2).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($3).n = nodes++; s = "Separator("+string((char*)($3).str)+")"; node_names[($3).n] = s; child.push_back(make_pair(($3).n, node_names[($3).n]));
}
|CONTINUE SEMICOLON {
  $$ = nodes++; node_names[$$] = "ContinueStatement";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Keyword("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($2).n = nodes++; s = "Separator("+string((char*)($2).str)+")"; node_names[($2).n] = s; child.push_back(make_pair(($2).n, node_names[($2).n]));
};

ReturnStatement:
RETURN SEMICOLON {
  $$ = nodes++; node_names[$$] = "ReturnStatement";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Keyword("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($2).n = nodes++; s = "Separator("+string((char*)($2).str)+")"; node_names[($2).n] = s; child.push_back(make_pair(($2).n, node_names[($2).n]));
}
|RETURN Expression SEMICOLON {
  $$ = nodes++; node_names[$$] = "ReturnStatement";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Keyword("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($2, node_names[$2]));
  parents.push_back(make_pair($$, node_names[$$])); ($3).n = nodes++; s = "Separator("+string((char*)($3).str)+")"; node_names[($3).n] = s; child.push_back(make_pair(($3).n, node_names[($3).n]));
};

ThrowStatement:
THROW Expression SEMICOLON {
  $$ = nodes++; node_names[$$] = "ThrowStatement";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Keyword("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($2, node_names[$2]));
  parents.push_back(make_pair($$, node_names[$$])); ($3).n = nodes++; s = "Separator("+string((char*)($3).str)+")"; node_names[($3).n] = s; child.push_back(make_pair(($3).n, node_names[($3).n]));
};

SynchronizedStatement:
SYNCHRONIZED OPENBRACKET Expression CLOSEBRACKET Block {
  $$ = nodes++; node_names[$$] = "SynchronizedStatement";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Keyword("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($2).n = nodes++; s = "Separator("+string((char*)($2).str)+")"; node_names[($2).n] = s; child.push_back(make_pair(($2).n, node_names[($2).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($3, node_names[$3]));
  parents.push_back(make_pair($$, node_names[$$])); ($4).n = nodes++; s = "Separator("+string((char*)($4).str)+")"; node_names[($4).n] = s; child.push_back(make_pair(($4).n, node_names[($4).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($5, node_names[$5]));
};

TryStatement:
TRY Block Catches {
  $$ = nodes++; node_names[$$] = "TryStatement";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Keyword("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($2, node_names[$2]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($3, node_names[$3]));
}
|TRY Block Catches Finally {
  $$ = nodes++; node_names[$$] = "TryStatement";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Keyword("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($2, node_names[$2]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($3, node_names[$3]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($4, node_names[$4]));
}
|TRY Block Finally {
  $$ = nodes++; node_names[$$] = "TryStatement";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Keyword("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($2, node_names[$2]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($3, node_names[$3]));
};

Catches:
CatchClause {
  $$ = nodes++; node_names[$$] = "Catches";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
}
|Catches CatchClause {
  $$ = nodes++; node_names[$$] = "Catches";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($2, node_names[$2]));
};

CatchClause:
CATCH OPENBRACKET FormalParameter CLOSEBRACKET Block {
  $$ = nodes++; node_names[$$] = "CatchClause";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Keyword("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($2).n = nodes++; s = "Separator("+string((char*)($2).str)+")"; node_names[($2).n] = s; child.push_back(make_pair(($2).n, node_names[($2).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($3, node_names[$3]));
  parents.push_back(make_pair($$, node_names[$$])); ($4).n = nodes++; s = "Separator("+string((char*)($4).str)+")"; node_names[($4).n] = s; child.push_back(make_pair(($4).n, node_names[($4).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($5, node_names[$5]));
};

Finally:
FINALLY Block {
  $$ = nodes++; node_names[$$] = "Finally";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Keyword("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($2, node_names[$2]));
};

Primary:
PrimaryNoNewArray {
  $$ = nodes++; node_names[$$] = "Primary";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
}
|ArrayCreationExpression {
  $$ = nodes++; node_names[$$] = "Primary";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
};

PrimaryNoNewArray:
Literal {
  $$ = nodes++; node_names[$$] = "PrimaryNoNewArray";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
}
|THIS {
  $$ = nodes++; node_names[$$] = "PrimaryNoNewArray";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Keyword("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
}
|OPENBRACKET Expression CLOSEBRACKET {
  $$ = nodes++; node_names[$$] = "PrimaryNoNewArray";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Separator("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($2, node_names[$2]));
  parents.push_back(make_pair($$, node_names[$$])); ($3).n = nodes++; s = "Separator("+string((char*)($3).str)+")"; node_names[($3).n] = s; child.push_back(make_pair(($3).n, node_names[($3).n]));
}
|ClassInstanceCreationExpression {
  $$ = nodes++; node_names[$$] = "PrimaryNoNewArray";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
}
|FieldAccess {
  $$ = nodes++; node_names[$$] = "PrimaryNoNewArray";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
}
|MethodInvocation {
  $$ = nodes++; node_names[$$] = "PrimaryNoNewArray";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
}
|ArrayAccess {
  $$ = nodes++; node_names[$$] = "PrimaryNoNewArray";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
};

ClassInstanceCreationExpression:
NEW ClassType OPENBRACKET ArgumentList CLOSEBRACKET {
  $$ = nodes++; node_names[$$] = "ClassInstanceCreationExpression";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Keyword("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($2, node_names[$2]));
  parents.push_back(make_pair($$, node_names[$$])); ($3).n = nodes++; s = "Separator("+string((char*)($3).str)+")"; node_names[($3).n] = s; child.push_back(make_pair(($3).n, node_names[($3).n]));
  parents.push_back(make_pair($$, node_names[$$]));  child.push_back(make_pair($4, node_names[$4]));
  parents.push_back(make_pair($$, node_names[$$])); ($5).n = nodes++; s = "Separator("+string((char*)($5).str)+")"; node_names[($5).n] = s; child.push_back(make_pair(($5).n, node_names[($5).n]));
}
|NEW ClassType OPENBRACKET CLOSEBRACKET {
  $$ = nodes++; node_names[$$] = "ClassInstanceCreationExpression";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Keyword("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($2, node_names[$2]));
  parents.push_back(make_pair($$, node_names[$$])); ($3).n = nodes++; s = "Separator("+string((char*)($3).str)+")"; node_names[($3).n] = s; child.push_back(make_pair(($3).n, node_names[($3).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($4).n = nodes++; s = "Separator("+string((char*)($4).str)+")"; node_names[($4).n] = s; child.push_back(make_pair(($4).n, node_names[($4).n]));
};

ArgumentList:
Expression {
  $$ = nodes++; node_names[$$] = "ArgumentList";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
}
|ArgumentList COMMA Expression {
  $$ = nodes++; node_names[$$] = "ArgumentList";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  parents.push_back(make_pair($$, node_names[$$])); ($2).n = nodes++; s = "Separator("+string((char*)($2).str)+")"; node_names[($2).n] = s; child.push_back(make_pair(($2).n, node_names[($2).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($3, node_names[$3]));
};

ArrayCreationExpression:
NEW PrimitiveType DimExprs Dims {
  $$ = nodes++; node_names[$$] = "ArrayCreationExpression";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Keyword("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($2, node_names[$2]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($3, node_names[$3]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($4, node_names[$4]));
}
|NEW PrimitiveType DimExprs {
  $$ = nodes++; node_names[$$] = "ArrayCreationExpression";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Keyword("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($2, node_names[$2]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($3, node_names[$3]));
}
|NEW ClassOrInterfaceType DimExprs Dims {
  $$ = nodes++; node_names[$$] = "ArrayCreationExpression";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Keyword("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($2, node_names[$2]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($3, node_names[$3]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($4, node_names[$4]));
}
|NEW ClassOrInterfaceType DimExprs {
  $$ = nodes++; node_names[$$] = "ArrayCreationExpression";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Keyword("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($2, node_names[$2]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($3, node_names[$3]));
};

DimExprs:
DimExpr {
  $$ = nodes++; node_names[$$] = "DimExprs";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
}
|DimExprs DimExpr {
  $$ = nodes++; node_names[$$] = "DimExprs";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($2, node_names[$2]));
};

DimExpr:
OPENSQUAREBRACKET Expression CLOSESQUAREBRACKET {
  $$ = nodes++; node_names[$$] = "DimExpr";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Separator("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($2, node_names[$2]));
  parents.push_back(make_pair($$, node_names[$$])); ($3).n = nodes++; s = "Separator("+string((char*)($3).str)+")"; node_names[($3).n] = s; child.push_back(make_pair(($3).n, node_names[($3).n]));
};

Dims:
OPENSQUAREBRACKET CLOSESQUAREBRACKET {
  $$ = nodes++; node_names[$$] = "Dims";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Separator("+string((char*)($1).str)+")"; node_names[($2).n] = s; child.push_back(make_pair(($2).n, node_names[($2).n]));
}
|Dims OPENSQUAREBRACKET CLOSESQUAREBRACKET {
  $$ = nodes++; node_names[$$] = "Dims";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  parents.push_back(make_pair($$, node_names[$$])); ($2).n = nodes++; s = "Separator("+string((char*)($2).str)+")"; node_names[($2).n] = s; child.push_back(make_pair(($2).n, node_names[($2).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($3).n = nodes++; s = "Separator("+string((char*)($3).str)+")"; node_names[($3).n] = s; child.push_back(make_pair(($3).n, node_names[($3).n]));
};

FieldAccess:
Primary DOT Identifier {
  $$ = nodes++; node_names[$$] = "FieldAccess";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  parents.push_back(make_pair($$, node_names[$$])); ($2).n = nodes++; s = "Separator("+string((char*)($2).str)+")"; node_names[($2).n] = s; child.push_back(make_pair(($2).n, node_names[($2).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($3).n = nodes++; s = "Identifier("+string((char*)($3).str)+")"; node_names[($3).n] = s; child.push_back(make_pair(($3).n, node_names[($3).n]));
}
|SUPER DOT Identifier {
  $$ = nodes++; node_names[$$] = "FieldAccess";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Keyword("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($2).n = nodes++; s = "Separator("+string((char*)($2).str)+")"; node_names[($2).n] = s; child.push_back(make_pair(($2).n, node_names[($2).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($3).n = nodes++; s = "Identifier("+string((char*)($3).str)+")"; node_names[($3).n] = s; child.push_back(make_pair(($3).n, node_names[($3).n]));
};

MethodInvocation:
Name OPENBRACKET ArgumentList CLOSEBRACKET {
  $$ = nodes++; node_names[$$] = "MethodInvocation";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  parents.push_back(make_pair($$, node_names[$$])); ($2).n = nodes++; s = "Separator("+string((char*)($2).str)+")"; node_names[($2).n] = s; child.push_back(make_pair(($2).n, node_names[($2).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($3, node_names[$3]));
  parents.push_back(make_pair($$, node_names[$$])); ($4).n = nodes++; s = "Separator("+string((char*)($4).str)+")"; node_names[($4).n] = s; child.push_back(make_pair(($4).n, node_names[($4).n]));
}
|Name OPENBRACKET CLOSEBRACKET {
  $$ = nodes++; node_names[$$] = "MethodInvocation";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  parents.push_back(make_pair($$, node_names[$$])); ($2).n = nodes++; s = "Separator("+string((char*)($2).str)+")"; node_names[($2).n] = s; child.push_back(make_pair(($2).n, node_names[($2).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($3).n = nodes++; s = "Separator("+string((char*)($3).str)+")"; node_names[($3).n] = s; child.push_back(make_pair(($3).n, node_names[($3).n]));
}
|Primary DOT Identifier OPENBRACKET ArgumentList CLOSEBRACKET {
  $$ = nodes++; node_names[$$] = "MethodInvocation";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  parents.push_back(make_pair($$, node_names[$$])); ($2).n = nodes++; s = "Separator("+string((char*)($2).str)+")"; node_names[($2).n] = s; child.push_back(make_pair(($2).n, node_names[($2).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($3).n = nodes++; s = "Identifier("+string((char*)($3).str)+")"; node_names[($3).n] = s; child.push_back(make_pair(($3).n, node_names[($3).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($4).n = nodes++; s = "Separator("+string((char*)($4).str)+")"; node_names[($4).n] = s; child.push_back(make_pair(($4).n, node_names[($4).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($5, node_names[$5]));
  parents.push_back(make_pair($$, node_names[$$])); ($6).n = nodes++; s = "Separator("+string((char*)($6).str)+")"; node_names[($6).n] = s; child.push_back(make_pair(($6).n, node_names[($6).n]));
}
|Primary DOT Identifier OPENBRACKET CLOSEBRACKET {
  $$ = nodes++; node_names[$$] = "MethodInvocation";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  parents.push_back(make_pair($$, node_names[$$])); ($2).n = nodes++; s = "Separator("+string((char*)($2).str)+")"; node_names[($2).n] = s; child.push_back(make_pair(($2).n, node_names[($2).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($3).n = nodes++; s = "Identifier("+string((char*)($3).str)+")"; node_names[($3).n] = s; child.push_back(make_pair(($3).n, node_names[($3).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($4).n = nodes++; s = "Separator("+string((char*)($4).str)+")"; node_names[($4).n] = s; child.push_back(make_pair(($4).n, node_names[($4).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($5).n = nodes++; s = "Separator("+string((char*)($5).str)+")"; node_names[($5).n] = s; child.push_back(make_pair(($5).n, node_names[($5).n]));
}
|SUPER DOT Identifier OPENBRACKET ArgumentList CLOSEBRACKET {
  $$ = nodes++; node_names[$$] = "MethodInvocation";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Keyword("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($2).n = nodes++; s = "Separator("+string((char*)($2).str)+")"; node_names[($2).n] = s; child.push_back(make_pair(($2).n, node_names[($2).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($3).n = nodes++; s = "Identifier("+string((char*)($3).str)+")"; node_names[($3).n] = s; child.push_back(make_pair(($3).n, node_names[($3).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($4).n = nodes++; s = "Separator("+string((char*)($4).str)+")"; node_names[($4).n] = s; child.push_back(make_pair(($4).n, node_names[($4).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($5, node_names[$5]));
  parents.push_back(make_pair($$, node_names[$$])); ($6).n = nodes++; s = "Separator("+string((char*)($6).str)+")"; node_names[($6).n] = s; child.push_back(make_pair(($6).n, node_names[($6).n]));
}
|SUPER DOT Identifier OPENBRACKET CLOSEBRACKET {
  $$ = nodes++; node_names[$$] = "MethodInvocation";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Keyword("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($2).n = nodes++; s = "Separator("+string((char*)($2).str)+")"; node_names[($2).n] = s; child.push_back(make_pair(($2).n, node_names[($2).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($3).n = nodes++; s = "Identifier("+string((char*)($3).str)+")"; node_names[($3).n] = s; child.push_back(make_pair(($3).n, node_names[($3).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($4).n = nodes++; s = "Separator("+string((char*)($4).str)+")"; node_names[($4).n] = s; child.push_back(make_pair(($4).n, node_names[($4).n]));
  parents.push_back(make_pair($$, node_names[$$])); ($5).n = nodes++; s = "Separator("+string((char*)($5).str)+")"; node_names[($5).n] = s; child.push_back(make_pair(($5).n, node_names[($5).n]));
};

ArrayAccess:
Name OPENSQUAREBRACKET Expression CLOSESQUAREBRACKET {
  $$ = nodes++; node_names[$$] = "ArrayAccess";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  parents.push_back(make_pair($$, node_names[$$])); ($2).n = nodes++; s = "Separator("+string((char*)($2).str)+")"; node_names[($2).n] = s; child.push_back(make_pair(($2).n, node_names[($2).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($3, node_names[$3]));
  parents.push_back(make_pair($$, node_names[$$])); ($4).n = nodes++; s = "Separator("+string((char*)($4).str)+")"; node_names[($4).n] = s; child.push_back(make_pair(($4).n, node_names[($4).n]));
}
|PrimaryNoNewArray OPENSQUAREBRACKET Expression CLOSESQUAREBRACKET {
  $$ = nodes++; node_names[$$] = "ArrayAccess";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  parents.push_back(make_pair($$, node_names[$$])); ($2).n = nodes++; s = "Separator("+string((char*)($2).str)+")"; node_names[($2).n] = s; child.push_back(make_pair(($2).n, node_names[($2).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($3, node_names[$3]));
  parents.push_back(make_pair($$, node_names[$$])); ($4).n = nodes++; s = "Separator("+string((char*)($4).str)+")"; node_names[($4).n] = s; child.push_back(make_pair(($4).n, node_names[($4).n]));
};

PostfixExpression:
Primary {
  $$ = nodes++; node_names[$$] = "PostfixExpression";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
}
|Name {
  $$ = nodes++; node_names[$$] = "PostfixExpression";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
}
|PostIncrementExpression {
  $$ = nodes++; node_names[$$] = "PostfixExpression";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
}
|PostDecrementExpression {
  $$ = nodes++; node_names[$$] = "PostfixExpression";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
};

PostIncrementExpression:
PostfixExpression PLUSPLUS {
  $$ = nodes++; node_names[$$] = "PostIncrementExpression";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  parents.push_back(make_pair($$, node_names[$$])); ($2).n = nodes++; s = "Operator("+string((char*)($2).str)+")"; node_names[($2).n] = s; child.push_back(make_pair(($2).n, node_names[($2).n]));
};

PostDecrementExpression:
PostfixExpression MINUSMINUS {
  $$ = nodes++; node_names[$$] = "PostDecrementExpression";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  parents.push_back(make_pair($$, node_names[$$])); ($2).n = nodes++; s = "Operator("+string((char*)($2).str)+")"; node_names[($2).n] = s; child.push_back(make_pair(($2).n, node_names[($2).n]));
};

UnaryExpression:
PreIncrementExpression {
  $$ = nodes++; node_names[$$] = "UnaryExpression";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
}
|PreDecrementExpression {
  $$ = nodes++; node_names[$$] = "UnaryExpression";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
}
|PLUS UnaryExpression {
  $$ = nodes++; node_names[$$] = "UnaryExpression";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Operator("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($2, node_names[$2]));
}
|MINUS UnaryExpression {
  $$ = nodes++; node_names[$$] = "UnaryExpression";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Operator("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($2, node_names[$2]));
}
|UnaryExpressionNotPlusMinus {
  $$ = nodes++; node_names[$$] = "UnaryExpression";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
};

PreIncrementExpression:
PLUSPLUS UnaryExpression {
  $$ = nodes++; node_names[$$] = "PreIncrementExpression";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Operator("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($2, node_names[$2]));
};

PreDecrementExpression:
MINUSMINUS UnaryExpression {
  $$ = nodes++; node_names[$$] = "PreDecrementExpression";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Operator("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($2, node_names[$2]));
};

UnaryExpressionNotPlusMinus:
PostfixExpression {
  $$ = nodes++; node_names[$$] = "UnaryExpressionNotPlusMinus";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
}
|TILDA UnaryExpression {
  $$ = nodes++; node_names[$$] = "UnaryExpressionNotPlusMinus";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Operator("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($2, node_names[$2]));
}
|NOT UnaryExpression {
  $$ = nodes++; node_names[$$] = "UnaryExpressionNotPlusMinus";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Operator("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($2, node_names[$2]));
}
|CastExpression {
  $$ = nodes++; node_names[$$] = "UnaryExpressionNotPlusMinus";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
};

CastExpression:
OPENBRACKET PrimitiveType Dims CLOSEBRACKET UnaryExpression {
  $$ = nodes++; node_names[$$] = "CastExpression";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Separator("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($2, node_names[$2]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($3, node_names[$3]));
  parents.push_back(make_pair($$, node_names[$$])); ($4).n = nodes++; s = "Separator("+string((char*)($4).str)+")"; node_names[($4).n] = s; child.push_back(make_pair(($4).n, node_names[($4).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($5, node_names[$5]));
}
|OPENBRACKET PrimitiveType CLOSEBRACKET UnaryExpression {
  $$ = nodes++; node_names[$$] = "CastExpression";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Separator("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($2, node_names[$2]));
  parents.push_back(make_pair($$, node_names[$$])); ($3).n = nodes++; s = "Separator("+string((char*)($3).str)+")"; node_names[($3).n] = s; child.push_back(make_pair(($3).n, node_names[($3).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($4, node_names[$4]));
}
|OPENBRACKET Expression CLOSEBRACKET UnaryExpressionNotPlusMinus {
  $$ = nodes++; node_names[$$] = "CastExpression";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Separator("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($2, node_names[$2]));
  parents.push_back(make_pair($$, node_names[$$])); ($3).n = nodes++; s = "Separator("+string((char*)($3).str)+")"; node_names[($3).n] = s; child.push_back(make_pair(($3).n, node_names[($3).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($4, node_names[$4]));
}
|OPENBRACKET Name Dims CLOSEBRACKET UnaryExpressionNotPlusMinus {
  $$ = nodes++; node_names[$$] = "CastExpression";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Separator("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($2, node_names[$2]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($3, node_names[$3]));
  parents.push_back(make_pair($$, node_names[$$])); ($4).n = nodes++; s = "Separator("+string((char*)($4).str)+")"; node_names[($4).n] = s; child.push_back(make_pair(($4).n, node_names[($4).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($5, node_names[$5]));
};

MultiplicativeExpression:
UnaryExpression {
  $$ = nodes++; node_names[$$] = "MultiplicativeExpression";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
}
|MultiplicativeExpression STAR UnaryExpression {
  $$ = nodes++; node_names[$$] = "MultiplicativeExpression";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  parents.push_back(make_pair($$, node_names[$$])); ($2).n = nodes++; s = "Operator("+string((char*)($2).str)+")"; node_names[($2).n] = s; child.push_back(make_pair(($2).n, node_names[($2).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($3, node_names[$3]));
}
|MultiplicativeExpression FORWARDSLASH UnaryExpression {
  $$ = nodes++; node_names[$$] = "MultiplicativeExpression";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  parents.push_back(make_pair($$, node_names[$$])); ($2).n = nodes++; s = "Operator("+string((char*)($2).str)+")"; node_names[($2).n] = s; child.push_back(make_pair(($2).n, node_names[($2).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($3, node_names[$3]));
}
|MultiplicativeExpression MODULO UnaryExpression {
  $$ = nodes++; node_names[$$] = "MultiplicativeExpression";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  parents.push_back(make_pair($$, node_names[$$])); ($2).n = nodes++; s = "Operator("+string((char*)($2).str)+")"; node_names[($2).n] = s; child.push_back(make_pair(($2).n, node_names[($2).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($3, node_names[$3]));
};

AdditiveExpression:
MultiplicativeExpression {
  $$ = nodes++; node_names[$$] = "AdditiveExpression";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
}
|AdditiveExpression PLUS MultiplicativeExpression {
  $$ = nodes++; node_names[$$] = "AdditiveExpression";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  parents.push_back(make_pair($$, node_names[$$])); ($2).n = nodes++; s = "Operator("+string((char*)($2).str)+")"; node_names[($2).n] = s; child.push_back(make_pair(($2).n, node_names[($2).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($3, node_names[$3]));
}
|AdditiveExpression MINUS MultiplicativeExpression {
  $$ = nodes++; node_names[$$] = "AdditiveExpression";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  parents.push_back(make_pair($$, node_names[$$])); ($2).n = nodes++; s = "Operator("+string((char*)($2).str)+")"; node_names[($2).n] = s; child.push_back(make_pair(($2).n, node_names[($2).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($3, node_names[$3]));
};

ShiftExpression:
AdditiveExpression {
  $$ = nodes++; node_names[$$] = "ShiftExpression";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
}
|ShiftExpression OPENANGULARBRACKETOPENANGULARBRACKET AdditiveExpression {
  $$ = nodes++; node_names[$$] = "ShiftExpression";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  parents.push_back(make_pair($$, node_names[$$])); ($2).n = nodes++; s = "Operator("+string((char*)($2).str)+")"; node_names[($2).n] = s; child.push_back(make_pair(($2).n, node_names[($2).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($3, node_names[$3]));
}
|ShiftExpression CLOSEANGULARBRACKETCLOSEANGULARBRACKET AdditiveExpression  {
  $$ = nodes++; node_names[$$] = "ShiftExpression";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  parents.push_back(make_pair($$, node_names[$$])); ($2).n = nodes++; s = "Operator("+string((char*)($2).str)+")"; node_names[($2).n] = s; child.push_back(make_pair(($2).n, node_names[($2).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($3, node_names[$3]));
}
|ShiftExpression CLOSEANGULARBRACKETCLOSEANGULARBRACKETCLOSEANGULARBRACKET AdditiveExpression {
  $$ = nodes++; node_names[$$] = "ShiftExpression";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  parents.push_back(make_pair($$, node_names[$$])); ($2).n = nodes++; s = "Operator("+string((char*)($2).str)+")"; node_names[($2).n] = s; child.push_back(make_pair(($2).n, node_names[($2).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($3, node_names[$3]));
};

RelationalExpression:
ShiftExpression {
  $$ = nodes++; node_names[$$] = "RelationalExpression";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
}
|RelationalExpression OPENANGULARBRACKET ShiftExpression {
  $$ = nodes++; node_names[$$] = "RelationalExpression";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  parents.push_back(make_pair($$, node_names[$$])); ($2).n = nodes++; s = "Operator("+string((char*)($2).str)+")"; node_names[($2).n] = s; child.push_back(make_pair(($2).n, node_names[($2).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($3, node_names[$3]));
}
|RelationalExpression CLOSEANGULARBRACKET ShiftExpression {
  $$ = nodes++; node_names[$$] = "RelationalExpression";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  parents.push_back(make_pair($$, node_names[$$])); ($2).n = nodes++; s = "Operator("+string((char*)($2).str)+")"; node_names[($2).n] = s; child.push_back(make_pair(($2).n, node_names[($2).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($3, node_names[$3]));
}
|RelationalExpression OPENANGULARBRACKETEQUAL ShiftExpression {
  $$ = nodes++; node_names[$$] = "RelationalExpression";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  parents.push_back(make_pair($$, node_names[$$])); ($2).n = nodes++; s = "Operator("+string((char*)($2).str)+")"; node_names[($2).n] = s; child.push_back(make_pair(($2).n, node_names[($2).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($3, node_names[$3]));
}
|RelationalExpression CLOSEANGULARBRACKETEQUAL ShiftExpression {
  $$ = nodes++; node_names[$$] = "RelationalExpression";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  parents.push_back(make_pair($$, node_names[$$])); ($2).n = nodes++; s = "Operator("+string((char*)($2).str)+")"; node_names[($2).n] = s; child.push_back(make_pair(($2).n, node_names[($2).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($3, node_names[$3]));
}
|RelationalExpression INSTANCEOF ReferenceType {
  $$ = nodes++; node_names[$$] = "RelationalExpression";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  parents.push_back(make_pair($$, node_names[$$])); ($2).n = nodes++; s = "Keyword("+string((char*)($2).str)+")"; node_names[($2).n] = s; child.push_back(make_pair(($2).n, node_names[($2).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($3, node_names[$3]));
};

EqualityExpression:
RelationalExpression {
  $$ = nodes++; node_names[$$] = "EqualityExpression";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
}
|EqualityExpression EQUALEQUAL RelationalExpression {
  $$ = nodes++; node_names[$$] = "EqualityExpression";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  parents.push_back(make_pair($$, node_names[$$])); ($2).n = nodes++; s = "Operator("+string((char*)($2).str)+")"; node_names[($2).n] = s; child.push_back(make_pair(($2).n, node_names[($2).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($3, node_names[$3]));
}
|EqualityExpression NOTEQUAL RelationalExpression {
  $$ = nodes++; node_names[$$] = "EqualityExpression";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  parents.push_back(make_pair($$, node_names[$$])); ($2).n = nodes++; s = "Operator("+string((char*)($2).str)+")"; node_names[($2).n] = s; child.push_back(make_pair(($2).n, node_names[($2).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($3, node_names[$3]));
};

AndExpression:
EqualityExpression {
  $$ = nodes++; node_names[$$] = "AndExpression";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
}
|AndExpression AND EqualityExpression {
  $$ = nodes++; node_names[$$] = "AndExpression";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  parents.push_back(make_pair($$, node_names[$$])); ($2).n = nodes++; s = "Operator("+string((char*)($2).str)+")"; node_names[($2).n] = s; child.push_back(make_pair(($2).n, node_names[($2).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($3, node_names[$3]));
};

ExclusiveOrExpression:
AndExpression {
  $$ = nodes++; node_names[$$] = "ExclusiveOrExpression";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
}
|ExclusiveOrExpression XOR AndExpression {
  $$ = nodes++; node_names[$$] = "ExclusiveOrExpression";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  parents.push_back(make_pair($$, node_names[$$])); ($2).n = nodes++; s = "Operator("+string((char*)($2).str)+")"; node_names[($2).n] = s; child.push_back(make_pair(($2).n, node_names[($2).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($3, node_names[$3]));
};

InclusiveOrExpression:
ExclusiveOrExpression {
  $$ = nodes++; node_names[$$] = "InclusiveOrExpression";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
}
|InclusiveOrExpression OR ExclusiveOrExpression {
  $$ = nodes++; node_names[$$] = "InclusiveOrExpression";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  parents.push_back(make_pair($$, node_names[$$])); ($2).n = nodes++; s = "Operator("+string((char*)($2).str)+")"; node_names[($2).n] = s; child.push_back(make_pair(($2).n, node_names[($2).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($3, node_names[$3]));
};

ConditionalAndExpression:
InclusiveOrExpression {
  $$ = nodes++; node_names[$$] = "ConditionalAndExpression";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
}
|ConditionalAndExpression ANDAND InclusiveOrExpression {
  $$ = nodes++; node_names[$$] = "ConditionalAndExpression";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  parents.push_back(make_pair($$, node_names[$$])); ($2).n = nodes++; s = "Operator("+string((char*)($2).str)+")"; node_names[($2).n] = s; child.push_back(make_pair(($2).n, node_names[($2).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($3, node_names[$3]));
};

ConditionalOrExpression:
ConditionalAndExpression {
  $$ = nodes++; node_names[$$] = "ConditionalOrExpression";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
}
|ConditionalOrExpression OROR ConditionalAndExpression {
  $$ = nodes++; node_names[$$] = "ConditionalOrExpression";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  parents.push_back(make_pair($$, node_names[$$])); ($2).n = nodes++; s = "Operator("+string((char*)($2).str)+")"; node_names[($2).n] = s; child.push_back(make_pair(($2).n, node_names[($2).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($3, node_names[$3]));
};

ConditionalExpression:
ConditionalOrExpression {
  $$ = nodes++; node_names[$$] = "ConditionalExpression";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
}
|ConditionalOrExpression QUESTION Expression COLON ConditionalExpression {
  $$ = nodes++; node_names[$$] = "ConditionalExpression";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  parents.push_back(make_pair($$, node_names[$$])); ($2).n = nodes++; s = "Operator("+string((char*)($2).str)+")"; node_names[($2).n] = s; child.push_back(make_pair(($2).n, node_names[($2).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($3, node_names[$3]));
  parents.push_back(make_pair($$, node_names[$$])); ($4).n = nodes++; s = "Separator("+string((char*)($4).str)+")"; node_names[($4).n] = s; child.push_back(make_pair(($4).n, node_names[($4).n]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($5, node_names[$5]));
};

AssignmentExpression:
ConditionalExpression {
  $$ = nodes++; node_names[$$] = "AssignmentExpression";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
}
|Assignment {
  $$ = nodes++; node_names[$$] = "AssignmentExpression";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
};

Assignment:
LeftHandSide AssignmentOperator AssignmentExpression {
  $$ = nodes++; node_names[$$] = "Assignment";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($2, node_names[$2]));
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($3, node_names[$3]));
};

LeftHandSide:
Name {
  $$ = nodes++; node_names[$$] = "LeftHandSide";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
}
|FieldAccess {
  $$ = nodes++; node_names[$$] = "LeftHandSide";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
}
|ArrayAccess {
  $$ = nodes++; node_names[$$] = "LeftHandSide";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
};

AssignmentOperator:
EQUAL {
  $$ = nodes++; node_names[$$] = "AssignmentOperator";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Operator("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
}
|STAREQUAL {
  $$ = nodes++; node_names[$$] = "AssignmentOperator";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Operator("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
}
|FORWARDSLASHEQUAL {
  $$ = nodes++; node_names[$$] = "AssignmentOperator";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Operator("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
}
|PLUSEQUAL {
  $$ = nodes++; node_names[$$] = "AssignmentOperator";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Operator("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
}
|MINUSEQUAL {
  $$ = nodes++; node_names[$$] = "AssignmentOperator";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Operator("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
}
|OPENANGULARBRACKETOPENANGULARBRACKETEQUAL {
  $$ = nodes++; node_names[$$] = "AssignmentOperator";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Operator("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
}
|CLOSEANGULARBRACKETCLOSEANGULARBRACKETEQUAL {
  $$ = nodes++; node_names[$$] = "AssignmentOperator";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Operator("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
}
|CLOSEANGULARBRACKETCLOSEANGULARBRACKETCLOSEANGULARBRACKETEQUAL {
  $$ = nodes++; node_names[$$] = "AssignmentOperator";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Operator("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
}
|ANDEQUAL {
  $$ = nodes++; node_names[$$] = "AssignmentOperator";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Operator("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
}
|XOREQUAL {
  $$ = nodes++; node_names[$$] = "AssignmentOperator";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Operator("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
}
|OREQUAL {
  $$ = nodes++; node_names[$$] = "AssignmentOperator";
  parents.push_back(make_pair($$, node_names[$$])); ($1).n = nodes++; s = "Operator("+string((char*)($1).str)+")"; node_names[($1).n] = s; child.push_back(make_pair(($1).n, node_names[($1).n]));
};

Expression:
AssignmentExpression {
  $$ = nodes++; node_names[$$] = "Expression";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
};

ConstantExpression:
Expression {
  $$ = nodes++; node_names[$$] = "ConstantExpression";
  parents.push_back(make_pair($$, node_names[$$])); child.push_back(make_pair($1, node_names[$1]));
};

%%

// int main()
// {
//   yyparse();
//   ofstream fout("AST.dot");
//   fout<<"digraph G {"<<endl;
//   fout<<"node [ordering=out]\n";
//   for(auto it : node_names){
//     if(it.second[0]=='\"'){
//       fout<<it.first<<" [label= \"" ;
//       for(auto j: it.second){
//         if(j=='\"') fout<<"\\\"";
//         else fout<<j;
//       }
//       fout<<"\"]" << endl;
//     }
//     else
//     fout<<it.first<<" [label=\"" << it.second << "\"]" << endl;
//   }
//   for(int i=0; i<nodes-1; ++i){
//     fout<<parents[i].first<<" -> "<<child[i].first<<endl;
//   }
//   fout<<"}"<<endl;
//   return 0;
// }
int main(int argc, char *argv[])
{
  string executible_name(argv[0]);
  argc--, argv++;
  if(argc != 3) {
    cerr << executible_name << ": Error: provide arguments correctly\n";
    exit(1);
  }
  char *input_filename = argv[0], *output_filename = argv[1];
  int verbose = atoi(argv[2]);
  if(verbose) yydebug = 1;
  yyin = fopen(input_filename, "r");
  if(yyin == NULL) {
    cerr << executible_name << ": Error: Input file " << input_filename << " not found.\n";
    exit(1);
  }
  yyparse();
  /* cout<<parents.size()<<child.size(); */
  ofstream fout(output_filename);
  fout<<"digraph G {"<<endl;
  fout<<"node [ordering=out]\n";
  for(auto it : node_names){
    if(it.second[0]=='\"'){
      fout<<it.first<<" [label= \"" ;
      for(auto j: it.second){
        if(j=='\"') fout<<"\\\"";
        else fout<<j;
      }
      fout<<"\"]" << endl;
    }
    else
    fout<<it.first<<" [label=\"" << it.second << "\"]" << endl;
  }
  for(int i=0; i<nodes-1; ++i){
    fout<<parents[i].first<<" -> "<<child[i].first<<endl;
  }
  fout<<"}"<<endl;
  return 0;
}

void yyerror(const char * s)
{
  cout<<"Error in line " << yylineno << " : " << s << endl;
  exit(0);
}
