%{

    #include <stdio.h>
    #include <conio.h>
    #include <string.h>
    #include "1907044.tab.h"
    #include <stdlib.h>
    void yyerror(char *);

%}

header [a-zA-Z]+[.][h]
variable [a-zA-Z][a-zA-Z0-9]*
digit [0-9]

%%

"take_in" {printf("\n[importing Header]\n");
            return HEADER;}

"numeric" {printf("\n[Integer Type Detected]\n");
            return INTEGER;}

"decimal" {printf("\n[Float Type Detected]\n");
            return FLOAT;}

"none" {printf("\n[Void Type Detected]\n");
            return VOID;}

"string" {printf("\n[String Type Detected]\n");
            return STRING;}

"<-" {return ALLOCATION;}

"<" {return '<';}

">" {return '>';}

"iteration" {printf("\n[For Loop Detected]\n");
            return FOR;}

"conditional_loop" {printf("\n[While Loop Detected]\n");
                    return WHILE;}

"result" {printf("\n[Return Detected]\n");
            return RETURN;}

"break" {return BREAK;}

"display" {printf("\n[Print Detected]\n");
            return PRINT;}

"asin" {return ASIN;}

"sin" {return SIN;}

"cos" {return COS;}

"acos" {return ACOS;}

"tan" {return TAN;}

"atan" {return ATAN;}

"log10" {return LOG10;}

"log" {return LOG;}

"pow" {return POW;}

"check" {printf("\n[IF Detected]\n");return IF;}

"alt_check" {printf("\n[ELSE IF Detected]\n");return ELSE_IF;}

"fallback" {printf("\n[ELSE Detected]\n");return ELSE;}

"record" {printf("\n[Structure Detected]\n");
            return STRUCT;}

"method" {printf("\n[Function Detected]\n");
            return FUNC;}

"select" {printf("\n[Switch Detected]\n");
            return SWITCH;}

"pick" {printf("\n[Case Detected]\n");
        return CASE;}

"default" {printf("\n[Default Detected]\n");
            return DEFAULT;}

"+" {printf("\n[Addition Detected]\n");
        return ADD;}

"inc" {printf("\n[Increment Detected]\n");
        return INC;}

"dec" {printf("\n[Decrement Detected]\n");
        return DEC;}

"-" {printf("\n[Subtraction Detected]\n");
        return SUB;}

"*" {printf("\n[Multiplication Detected]\n");
        return MUL;}

"/" {printf("\n[Division Detected]\n");
        return DIV;}

"<=" {return(LE_OP);}

">=" {return(GE_OP);}

"==" {return(EQ_OP); }

"!=" {return(NE_OP); }

"{"	{return('{');}

"}" {return('}');}

"," {return(','); }

":"	{return(':'); }

"("	{return('('); }

")"	{return(')'); }

{header} {printf("\n[header found]\n");
            strcpy(yylval.text,yytext);
            return HEADER_FILE;}

"&"{variable} {printf("\n[Accessing Variable]\n");
        strcpy(yylval.text,yytext+1);
        return VARIABLE_ACCESS;}

{variable} {printf("\n[Variable Detected]\n");
            strcpy(yylval.text,yytext);
            return VARIABLE;}

{digit}+ {printf("\n[Integer Value Detected]\n");
            yylval.value.intval=atoi(yytext);
            yylval.value.type = 2;
            return NUMBER;}

{digit}+[.]{digit}+ {printf("\n[Floating Value Detected]\n");
                    yylval.value.realval=atof(yytext);
                    yylval.value.type = 3;
                    return NUMBER;}

"\""(.)*"\"" {printf("\n[String Value Detected]\n");
                yylval.value.type = 4;
                yylval.value.strval = calloc(strlen(yytext),sizeof(char));
                strcpy(yylval.value.strval,yytext+1);
                yylval.value.strval[strlen(yylval.value.strval)-1]=0;
                return STR;}
[#].* {printf("\n[Single Line Comment detected]\n");}

[ ]* {}
[\n]* {}
[\t]* {}
. {}

%%
int yywrap(void)
{
    return 1;
}