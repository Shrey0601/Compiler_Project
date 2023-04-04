%{
    #include<iostream>
    #include<map>
    #include<vector>
    #include<string>
    #include<fstream>
    #include "parser.tab.h"
    int line=1;
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

{BYTE} {strcpy(yylval.lab.str, yytext); return BYTE;}
{SHORT} {strcpy(yylval.lab.str, yytext); return SHORT;}
{INT} {strcpy(yylval.lab.str, yytext); return INT;} 
{LONG} {strcpy(yylval.lab.str, yytext); return LONG;} 
{CHAR} {strcpy(yylval.lab.str, yytext); return CHAR;}
{ELSE} {strcpy(yylval.lab.str, yytext); return ELSE;}
{CATCH} {strcpy(yylval.lab.str, yytext); return CATCH;}
{FINALLY} {strcpy(yylval.lab.str, yytext); return FINALLY;}
{THROWS} {strcpy(yylval.lab.str, yytext); return THROWS;}
{INTERFACE} {strcpy(yylval.lab.str, yytext); return INTERFACE;}
{PLUS} {strcpy(yylval.lab.str, yytext); return PLUS;}
{FORWARDSLASH} {strcpy(yylval.lab.str, yytext); return FORWARDSLASH;}
{MODULO} {strcpy(yylval.lab.str, yytext); return MODULO;}
{IF} {strcpy(yylval.lab.str, yytext); return IF;} 
{SWITCH} {strcpy(yylval.lab.str, yytext); return SWITCH;}
{FLOAT} {strcpy(yylval.lab.str, yytext); return FLOAT;}
{DOUBLE} {strcpy(yylval.lab.str, yytext); return DOUBLE;}
{BOOLEAN} {strcpy(yylval.lab.str, yytext); return BOOLEAN;}
{CASE} {strcpy(yylval.lab.str, yytext); return CASE;}
{DEFAULT} {strcpy(yylval.lab.str, yytext); return DEFAULT;}
{DO} {strcpy(yylval.lab.str, yytext); return DO;}
{WHILE} {strcpy(yylval.lab.str, yytext); return WHILE;}
{OPENANGULARBRACKET} {strcpy(yylval.lab.str, yytext); return OPENANGULARBRACKET;}
{CLOSEANGULARBRACKET} {strcpy(yylval.lab.str, yytext); return CLOSEANGULARBRACKET;}
{OPENBRACKET} {strcpy(yylval.lab.str, yytext); return OPENBRACKET;}
{CLOSEBRACKET}  {strcpy(yylval.lab.str, yytext); return CLOSEBRACKET;}
{OPENCURLYBRACKET} {strcpy(yylval.lab.str, yytext); return OPENCURLYBRACKET;}
{CLOSECURLYBRACKET} {strcpy(yylval.lab.str, yytext); return CLOSECURLYBRACKET;}
{OPENSQUAREBRACKET} {strcpy(yylval.lab.str, yytext); return OPENSQUAREBRACKET;}
{CLOSESQUAREBRACKET} {strcpy(yylval.lab.str, yytext); return CLOSESQUAREBRACKET;}
{EQUAL} {strcpy(yylval.lab.str, yytext); return EQUAL;}
{STAREQUAL} {strcpy(yylval.lab.str, yytext); return STAREQUAL;}
{FORWARDSLASHEQUAL} {strcpy(yylval.lab.str, yytext); return FORWARDSLASHEQUAL;}
{PLUSEQUAL} {strcpy(yylval.lab.str, yytext); return PLUSEQUAL;}
{MINUSEQUAL} {strcpy(yylval.lab.str, yytext); return MINUSEQUAL;}
{OPENANGULARBRACKETOPENANGULARBRACKETEQUAL} {strcpy(yylval.lab.str, yytext); return OPENANGULARBRACKETOPENANGULARBRACKETEQUAL;}
{CLOSEANGULARBRACKETCLOSEANGULARBRACKETEQUAL} {strcpy(yylval.lab.str, yytext); return CLOSEANGULARBRACKETCLOSEANGULARBRACKETEQUAL;}
{CLOSEANGULARBRACKETCLOSEANGULARBRACKETCLOSEANGULARBRACKETEQUAL} {strcpy(yylval.lab.str, yytext); return CLOSEANGULARBRACKETCLOSEANGULARBRACKETCLOSEANGULARBRACKETEQUAL;}
{ANDEQUAL} {strcpy(yylval.lab.str, yytext); return ANDEQUAL;}
{XOREQUAL} {strcpy(yylval.lab.str, yytext); return XOREQUAL;}
{OREQUAL} {strcpy(yylval.lab.str, yytext); return OREQUAL;}
{DOT} {strcpy(yylval.lab.str, yytext); return DOT;}
{COMMA} {strcpy(yylval.lab.str, yytext); return COMMA;}
{SEMICOLON} {strcpy(yylval.lab.str, yytext); return SEMICOLON;}
{COLON}     {strcpy(yylval.lab.str, yytext); return COLON;}
{INSTANCEOF} {strcpy(yylval.lab.str, yytext); return INSTANCEOF;}
{PUBLIC} {strcpy(yylval.lab.str, yytext); return PUBLIC;} 
{PROTECTED} {strcpy(yylval.lab.str, yytext); return PROTECTED;} 
{PRIVATE} {strcpy(yylval.lab.str, yytext); return PRIVATE;}
{STATIC} {strcpy(yylval.lab.str, yytext); return STATIC;}
{ABSTRACT} {strcpy(yylval.lab.str, yytext); return ABSTRACT;} 
{FINAL} {strcpy(yylval.lab.str, yytext); return FINAL;} 
{NATIVE} {strcpy(yylval.lab.str, yytext); return NATIVE;} 
{SYNCHRONIZED} {strcpy(yylval.lab.str, yytext); return SYNCHRONIZED;} 
{TRANSIENT} {strcpy(yylval.lab.str, yytext); return TRANSIENT;} 
{VOLATILE}  {strcpy(yylval.lab.str, yytext); return VOLATILE;}
{PACKAGE} {strcpy(yylval.lab.str, yytext); return PACKAGE;}
{IMPORT} {strcpy(yylval.lab.str, yytext); return IMPORT;} 
{STAR} {strcpy(yylval.lab.str, yytext); return STAR;}
{CLASS} {strcpy(yylval.lab.str, yytext); return CLASS;}
{EXTENDS} {strcpy(yylval.lab.str, yytext); return EXTENDS;}
{IMPLEMENTS} {strcpy(yylval.lab.str, yytext); return IMPLEMENTS;}
{VOID} {strcpy(yylval.lab.str, yytext); return VOID;}
{THIS}  {strcpy(yylval.lab.str, yytext); return THIS;} 
{SUPER} {strcpy(yylval.lab.str, yytext); return SUPER;}
{BREAK}         {strcpy(yylval.lab.str, yytext); return BREAK;}
{RETURN} {strcpy(yylval.lab.str, yytext); return RETURN;}
{FOR} {strcpy(yylval.lab.str, yytext); return FOR;}
{TRY} {strcpy(yylval.lab.str, yytext); return TRY;}
{THROW}     {strcpy(yylval.lab.str, yytext); return THROW;}
{CONTINUE} {strcpy(yylval.lab.str, yytext); return CONTINUE;}
{NEW} {strcpy(yylval.lab.str, yytext); return NEW;}
{PLUSPLUS} {strcpy(yylval.lab.str, yytext); return PLUSPLUS;}
{MINUSMINUS} {strcpy(yylval.lab.str, yytext); return MINUSMINUS;}
{TILDA} {strcpy(yylval.lab.str, yytext); return TILDA;}
{NOT} {strcpy(yylval.lab.str, yytext); return NOT;}
{AND} {strcpy(yylval.lab.str, yytext); return AND;}
{OR} {strcpy(yylval.lab.str, yytext); return OR;}
{OROR} {strcpy(yylval.lab.str, yytext); return OROR;}
{ANDAND} {strcpy(yylval.lab.str, yytext); return ANDAND;}
{NOTEQUAL} {strcpy(yylval.lab.str, yytext); return NOTEQUAL;}
{MINUS} {strcpy(yylval.lab.str, yytext); return MINUS;}
{OPENANGULARBRACKETOPENANGULARBRACKET} {strcpy(yylval.lab.str, yytext); return OPENANGULARBRACKETOPENANGULARBRACKET;}
{CLOSEANGULARBRACKETCLOSEANGULARBRACKET} {strcpy(yylval.lab.str, yytext); return CLOSEANGULARBRACKETCLOSEANGULARBRACKET;}
{CLOSEANGULARBRACKETCLOSEANGULARBRACKETCLOSEANGULARBRACKET}     {strcpy(yylval.lab.str, yytext); return CLOSEANGULARBRACKETCLOSEANGULARBRACKETCLOSEANGULARBRACKET;}
{QUESTION} {strcpy(yylval.lab.str, yytext); return QUESTION;}
{XOR} {strcpy(yylval.lab.str, yytext); return XOR;}
{EQUALEQUAL} {strcpy(yylval.lab.str, yytext); return EQUALEQUAL;}
{OPENANGULARBRACKETEQUAL} {strcpy(yylval.lab.str, yytext); return OPENANGULARBRACKETEQUAL;}
{CLOSEANGULARBRACKETEQUAL} {strcpy(yylval.lab.str, yytext); return CLOSEANGULARBRACKETEQUAL;}
{TextBlock} 
{NullLiteral} {strcpy(yylval.lab.str, yytext); return NullLiteral;}
{IntegerLiteral} {strcpy(yylval.lab.str, yytext); return IntegerLiteral;}
{FloatingPointLiteral} {strcpy(yylval.lab.str, yytext); return FloatingPointLiteral;}
{BooleanLiteral} {strcpy(yylval.lab.str, yytext); return BooleanLiteral;}
{CharacterLiteral} {strcpy(yylval.lab.str, yytext); return CharacterLiteral;}
{StringLiteral} {strcpy(yylval.lab.str, yytext); return StringLiteral;}
{Identifier} {strcpy(yylval.lab.str, yytext); return Identifier;}
{LineTerminator} {}
{WhiteSpace} {}
{Comment} {}
<<EOF>> {yyterminate();}

%%

int yywrap()
{ return 1; }