%{
    #include<iostream>
    #include<map>
    #include<vector>
    #include<string>
    #include<fstream>
    #include "parser.tab.h"
    using namespace std;

%}


BYTE                "byte"
SHORT               "short" 
INT                 "int"
LONG                "long" 
CHAR                "char"
ELSE                "else"
CATCH               "catch"
FINALLY            "finally"
INTERFACE           "interface"
PLUS                "+"
FORWARDSLASH        "/"
MODULO              "%"
IF                  "if"
SWITCH              "switch"
FLOAT               "float"
DOUBLE              "double"
BOOLEAN             "boolean"

CASE                "case"
DEFAULT             "default"
DO                  "do"
WHILE               "while"


OPENANGULARBRACKET  "<"
CLOSEANGULARBRACKET ">"
OPENBRACKET         "("
CLOSEBRACKET        ")"
OPENCURLYBRACKET    "{"
CLOSECURLYBRACKET   "}"
OPENSQUAREBRACKET   "["
CLOSESQUAREBRACKET  "]"
EQUAL               "="
STAREQUAL           "*="
FORWARDSLASHEQUAL   "/="
PLUSEQUAL           "+="
MINUSEQUAL          "-="
OPENANGULARBRACKETOPENANGULARBRACKETEQUAL                               "<<="
CLOSEANGULARBRACKETCLOSEANGULARBRACKETEQUAL                             ">>="
CLOSEANGULARBRACKETCLOSEANGULARBRACKETCLOSEANGULARBRACKETEQUAL          ">>>="
ANDEQUAL            "&="
XOREQUAL            "^="
OREQUAL             "|="
DOT                 "."
COMMA               ","
SEMICOLON           ";"
COLON               ":"
INSTANCEOF          "instanceof"
PUBLIC              "public"
PROTECTED           "protected"
PRIVATE             "private"
THROWS              "throws" 
STATIC              "static"
ABSTRACT            "abstract"
FINAL               "final"
NATIVE              "native" 
SYNCHRONIZED        "synchronized" 
TRANSIENT           "transient" 
VOLATILE            "volatile"
PACKAGE             "package"
IMPORT              "import"
STAR                "*"
CLASS               "class"
EXTENDS             "extends"
IMPLEMENTS          "implements"
VOID                "void"
THIS                "this"
SUPER               "super"
BREAK               "break"
RETURN              "return"
FOR                 "for"
TRY                 "try"
THROW               "throw"
CONTINUE            "continue"
NEW                 "new"
PLUSPLUS            "++"
MINUSMINUS          "--"
TILDA               "~"
NOT                 "!"
AND                 "&"
OR                  "|"
OROR                "||"
ANDAND              "&&" 
NOTEQUAL            "!=" 
MINUS               "-"
OPENANGULARBRACKETOPENANGULARBRACKET                            "<<"
CLOSEANGULARBRACKETCLOSEANGULARBRACKET                          ">>"
CLOSEANGULARBRACKETCLOSEANGULARBRACKETCLOSEANGULARBRACKET       ">>>"
QUESTION            "?"
XOR                 "^"
EQUALEQUAL          "=="
OPENANGULARBRACKETEQUAL                                          "<="
CLOSEANGULARBRACKETEQUAL                                         ">="

/* <-------------------------------------------------------------------Java 17  Grammar ---------------------------------------------------------------------------------------------------------------> */



Digit [0-9]
NonZeroDigit [1-9]
DigitOrUnderscore {Digit}|"_"
Underscores "_"+
DigitsAndUnderscores {DigitOrUnderscore}+
Digits {Digit}|{Digit}{DigitsAndUnderscores}?{Digit}
DecimalNumeral 0|{NonZeroDigit}{Digits}?|{NonZeroDigit}{Underscores}{Digits}

HexNumeral "0x"{HexDigits}|"0X"{HexDigits}
HexDigits {HexDigit}|{HexDigit}{HexDigitsAndUnderscores}?{HexDigit}
HexDigit [0-9A-Fa-f]
HexDigitsAndUnderscores {HexDigitOrUnderscore}+
HexDigitOrUnderscore {HexDigit}|"_"

OctalNumeral 0{OctalDigits}|0{Underscores}{OctalDigits}
OctalDigits {OctalDigit}|{OctalDigit}{OctalDigitsAndUnderscores}?{OctalDigit}
OctalDigit [0-7]
OctalDigitsAndUnderscores {OctalDigitOrUnderscore}+
OctalDigitOrUnderscore {OctalDigit}|"_"

BinaryNumeral "0b"{BinaryDigits}|"0B"{BinaryDigits}
BinaryDigits {BinaryDigit}|{BinaryDigit}{BinaryDigitsAndUnderscores}?{BinaryDigit}
BinaryDigit [0-1]
BinaryDigitsAndUnderscores {BinaryDigitOrUnderscore}+
BinaryDigitOrUnderscore {BinaryDigit}|"_"

IntegerLiteral {DecimalIntegerLiteral}|{HexIntegerLiteral}|{OctalIntegerLiteral}|{BinaryIntegerLiteral}
IntegerTypeSuffix [lL]
DecimalIntegerLiteral {DecimalNumeral}{IntegerTypeSuffix}?
HexIntegerLiteral {HexNumeral}{IntegerTypeSuffix}?
OctalIntegerLiteral {OctalNumeral}{IntegerTypeSuffix}?
BinaryIntegerLiteral {BinaryNumeral}{IntegerTypeSuffix}?

FloatingPointLiteral {DecimalFloatingPointLiteral}|{HexadecimalFloatingPointLiteral}
DecimalFloatingPointLiteral {Digits}"."{Digits}?{ExponentPart}?{FloatTypeSuffix}?|"."{Digits}{ExponentPart}?{FloatTypeSuffix}?|{Digits}{ExponentPart}{FloatTypeSuffix}?|{Digits}{ExponentPart}?{FloatTypeSuffix}
ExponentPart {ExponentIndicator}{SignedInteger}
ExponentIndicator [eE]
SignedInteger {Sign}?{Digits}
Sign [+-]
FloatTypeSuffix [fFdD]

HexadecimalFloatingPointLiteral {HexSignificand}{BinaryExponent}{FloatTypeSuffix}?
HexSignificand {HexNumeral}(".")?|"0x"{HexDigits}?"."{HexDigits}|"0X"{HexDigits}?"."{HexDigits}
BinaryExponent {BinaryExponentIndicator}{SignedInteger}
BinaryExponentIndicator [pP]

BooleanLiteral "true"|"false"

NullLiteral "null"

InputCharacter [^\n\r]

StringLiteral \"{StringCharacter}*\"
StringCharacter [^"\n\r]|"\\""\""

CharacterLiteral \'[^']\'|\'\\{EscapeLetters}\'|\'{UnicodeEscape}\'

Comment {TraditionalComment}|{EndOfLineComment}
TraditionalComment "/*"([^*]|[\r\n]|([*]+([^*/]|[\r\n])))*[*]*"*/"
EndOfLineComment "//"{InputCharacter}*

TextBlock [\"]{3}(" "|[\t\f])*{LineTerminator}{TextBlockContent}*[\"]{3}
NewChar [^\"]
TextBlockContent "\""{NewChar}|"\"""\""{NewChar}|{NewChar}|"\\""\""

Identifier {JavaLetter}{JavaLetterOrDigit}*
JavaLetter [a-zA-Z$_]
JavaLetterOrDigit [a-zA-Z0-9$_]

UnicodeMarker "u"+
UnicodeEscape "\\"{UnicodeMarker}{HexDigit}{4}
EscapeLetters "b"|"s"|"t"|"n"|"f"|"r"|\"|\'|\\
LineTerminator \r|\n|\r\n
WhiteSpace " "|\t|\f|{LineTerminator}

%option yylineno

%%

{BYTE} {strcpy(yylval.lex.str, yytext); return BYTE;}
{SHORT} {strcpy(yylval.lex.str, yytext); return SHORT;}
{INT} {strcpy(yylval.lex.str, yytext); return INT;} 
{LONG} {strcpy(yylval.lex.str, yytext); return LONG;} 
{CHAR} {strcpy(yylval.lex.str, yytext); return CHAR;}
{ELSE} {strcpy(yylval.lex.str, yytext); return ELSE;}
{CATCH} {strcpy(yylval.lex.str, yytext); return CATCH;}
{FINALLY} {strcpy(yylval.lex.str, yytext); return FINALLY;}
{THROWS} {strcpy(yylval.lex.str, yytext); return THROWS;}
{INTERFACE} {strcpy(yylval.lex.str, yytext); return INTERFACE;}
{PLUS} {strcpy(yylval.lex.str, yytext); return PLUS;}
{FORWARDSLASH} {strcpy(yylval.lex.str, yytext); return FORWARDSLASH;}
{MODULO} {strcpy(yylval.lex.str, yytext); return MODULO;}
{IF} {strcpy(yylval.lex.str, yytext); return IF;} 
{SWITCH} {strcpy(yylval.lex.str, yytext); return SWITCH;}
{FLOAT} {strcpy(yylval.lex.str, yytext); return FLOAT;}
{DOUBLE} {strcpy(yylval.lex.str, yytext); return DOUBLE;}
{BOOLEAN} {strcpy(yylval.lex.str, yytext); return BOOLEAN;}
{CASE} {strcpy(yylval.lex.str, yytext); return CASE;}
{DEFAULT} {strcpy(yylval.lex.str, yytext); return DEFAULT;}
{DO} {strcpy(yylval.lex.str, yytext); return DO;}
{WHILE} {strcpy(yylval.lex.str, yytext); return WHILE;}
{OPENANGULARBRACKET} {strcpy(yylval.lex.str, yytext); return OPENANGULARBRACKET;}
{CLOSEANGULARBRACKET} {strcpy(yylval.lex.str, yytext); return CLOSEANGULARBRACKET;}
{OPENBRACKET} {strcpy(yylval.lex.str, yytext); return OPENBRACKET;}
{CLOSEBRACKET}  {strcpy(yylval.lex.str, yytext); return CLOSEBRACKET;}
{OPENCURLYBRACKET} {strcpy(yylval.lex.str, yytext); return OPENCURLYBRACKET;}
{CLOSECURLYBRACKET} {strcpy(yylval.lex.str, yytext); return CLOSECURLYBRACKET;}
{OPENSQUAREBRACKET} {strcpy(yylval.lex.str, yytext); return OPENSQUAREBRACKET;}
{CLOSESQUAREBRACKET} {strcpy(yylval.lex.str, yytext); return CLOSESQUAREBRACKET;}
{EQUAL} {strcpy(yylval.lex.str, yytext); return EQUAL;}
{STAREQUAL} {strcpy(yylval.lex.str, yytext); return STAREQUAL;}
{FORWARDSLASHEQUAL} {strcpy(yylval.lex.str, yytext); return FORWARDSLASHEQUAL;}
{PLUSEQUAL} {strcpy(yylval.lex.str, yytext); return PLUSEQUAL;}
{MINUSEQUAL} {strcpy(yylval.lex.str, yytext); return MINUSEQUAL;}
{OPENANGULARBRACKETOPENANGULARBRACKETEQUAL} {strcpy(yylval.lex.str, yytext); return OPENANGULARBRACKETOPENANGULARBRACKETEQUAL;}
{CLOSEANGULARBRACKETCLOSEANGULARBRACKETEQUAL} {strcpy(yylval.lex.str, yytext); return CLOSEANGULARBRACKETCLOSEANGULARBRACKETEQUAL;}
{CLOSEANGULARBRACKETCLOSEANGULARBRACKETCLOSEANGULARBRACKETEQUAL} {strcpy(yylval.lex.str, yytext); return CLOSEANGULARBRACKETCLOSEANGULARBRACKETCLOSEANGULARBRACKETEQUAL;}
{ANDEQUAL} {strcpy(yylval.lex.str, yytext); return ANDEQUAL;}
{XOREQUAL} {strcpy(yylval.lex.str, yytext); return XOREQUAL;}
{OREQUAL} {strcpy(yylval.lex.str, yytext); return OREQUAL;}
{DOT} {strcpy(yylval.lex.str, yytext); return DOT;}
{COMMA} {strcpy(yylval.lex.str, yytext); return COMMA;}
{SEMICOLON} {strcpy(yylval.lex.str, yytext); return SEMICOLON;}
{COLON}     {strcpy(yylval.lex.str, yytext); return COLON;}
{INSTANCEOF} {strcpy(yylval.lex.str, yytext); return INSTANCEOF;}
{PUBLIC} {strcpy(yylval.lex.str, yytext); return PUBLIC;} 
{PROTECTED} {strcpy(yylval.lex.str, yytext); return PROTECTED;} 
{PRIVATE} {strcpy(yylval.lex.str, yytext); return PRIVATE;}
{STATIC} {strcpy(yylval.lex.str, yytext); return STATIC;}
{ABSTRACT} {strcpy(yylval.lex.str, yytext); return ABSTRACT;} 
{FINAL} {strcpy(yylval.lex.str, yytext); return FINAL;} 
{NATIVE} {strcpy(yylval.lex.str, yytext); return NATIVE;} 
{SYNCHRONIZED} {strcpy(yylval.lex.str, yytext); return SYNCHRONIZED;} 
{TRANSIENT} {strcpy(yylval.lex.str, yytext); return TRANSIENT;} 
{VOLATILE}  {strcpy(yylval.lex.str, yytext); return VOLATILE;}
{PACKAGE} {strcpy(yylval.lex.str, yytext); return PACKAGE;}
{IMPORT} {strcpy(yylval.lex.str, yytext); return IMPORT;} 
{STAR} {strcpy(yylval.lex.str, yytext); return STAR;}
{CLASS} {strcpy(yylval.lex.str, yytext); return CLASS;}
{EXTENDS} {strcpy(yylval.lex.str, yytext); return EXTENDS;}
{IMPLEMENTS} {strcpy(yylval.lex.str, yytext); return IMPLEMENTS;}
{VOID} {strcpy(yylval.lex.str, yytext); return VOID;}
{THIS}  {strcpy(yylval.lex.str, yytext); return THIS;} 
{SUPER} {strcpy(yylval.lex.str, yytext); return SUPER;}
{BREAK}         {strcpy(yylval.lex.str, yytext); return BREAK;}
{RETURN} {strcpy(yylval.lex.str, yytext); return RETURN;}
{FOR} {strcpy(yylval.lex.str, yytext); return FOR;}
{TRY} {strcpy(yylval.lex.str, yytext); return TRY;}
{THROW}     {strcpy(yylval.lex.str, yytext); return THROW;}
{CONTINUE} {strcpy(yylval.lex.str, yytext); return CONTINUE;}
{NEW} {strcpy(yylval.lex.str, yytext); return NEW;}
{PLUSPLUS} {strcpy(yylval.lex.str, yytext); return PLUSPLUS;}
{MINUSMINUS} {strcpy(yylval.lex.str, yytext); return MINUSMINUS;}
{TILDA} {strcpy(yylval.lex.str, yytext); return TILDA;}
{NOT} {strcpy(yylval.lex.str, yytext); return NOT;}
{AND} {strcpy(yylval.lex.str, yytext); return AND;}
{OR} {strcpy(yylval.lex.str, yytext); return OR;}
{OROR} {strcpy(yylval.lex.str, yytext); return OROR;}
{ANDAND} {strcpy(yylval.lex.str, yytext); return ANDAND;}
{NOTEQUAL} {strcpy(yylval.lex.str, yytext); return NOTEQUAL;}
{MINUS} {strcpy(yylval.lex.str, yytext); return MINUS;}
{OPENANGULARBRACKETOPENANGULARBRACKET} {strcpy(yylval.lex.str, yytext); return OPENANGULARBRACKETOPENANGULARBRACKET;}
{CLOSEANGULARBRACKETCLOSEANGULARBRACKET} {strcpy(yylval.lex.str, yytext); return CLOSEANGULARBRACKETCLOSEANGULARBRACKET;}
{CLOSEANGULARBRACKETCLOSEANGULARBRACKETCLOSEANGULARBRACKET}     {strcpy(yylval.lex.str, yytext); return CLOSEANGULARBRACKETCLOSEANGULARBRACKETCLOSEANGULARBRACKET;}
{QUESTION} {strcpy(yylval.lex.str, yytext); return QUESTION;}
{XOR} {strcpy(yylval.lex.str, yytext); return XOR;}
{EQUALEQUAL} {strcpy(yylval.lex.str, yytext); return EQUALEQUAL;}
{OPENANGULARBRACKETEQUAL} {strcpy(yylval.lex.str, yytext); return OPENANGULARBRACKETEQUAL;}
{CLOSEANGULARBRACKETEQUAL} {strcpy(yylval.lex.str, yytext); return CLOSEANGULARBRACKETEQUAL;}
{TextBlock} 
{NullLiteral} {strcpy(yylval.lex.str, yytext); return NullLiteral;}
{IntegerLiteral} {strcpy(yylval.lex.str, yytext); return IntegerLiteral;}
{FloatingPointLiteral} {strcpy(yylval.lex.str, yytext); return FloatingPointLiteral;}
{BooleanLiteral} {strcpy(yylval.lex.str, yytext); return BooleanLiteral;}
{CharacterLiteral} {strcpy(yylval.lex.str, yytext); return CharacterLiteral;}
{StringLiteral} {strcpy(yylval.lex.str, yytext); return StringLiteral;}
{Identifier} {strcpy(yylval.lex.str, yytext); return Identifier;}
{LineTerminator} {}
{WhiteSpace} {}
{Comment} {}
<<EOF>> {yyterminate();}

%%

int yywrap()
{ return 1; }