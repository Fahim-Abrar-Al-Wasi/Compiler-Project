
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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

/* "%code requires" blocks.  */

/* Line 1676 of yacc.c  */
#line 515 "1907044.y"

    #ifndef CHECK
    #define CHECK
    struct CHECK datatype {
        int type;
        char *strval;
        int intval;
        double realval;
    };
    #endif



/* Line 1676 of yacc.c  */
#line 54 "1907044.tab.h"

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     HEADER_FILE = 258,
     VARIABLE = 259,
     NUMBER = 260,
     STR = 261,
     VARIABLE_ACCESS = 262,
     HEADER = 263,
     INTEGER = 264,
     FLOAT = 265,
     STRING = 266,
     VOID = 267,
     ALLOCATION = 268,
     RETURN = 269,
     PRINT = 270,
     STRUCT = 271,
     FUNC = 272,
     BREAK = 273,
     FOR = 274,
     WHILE = 275,
     IF = 276,
     ELSE_IF = 277,
     ELSE = 278,
     SWITCH = 279,
     CASE = 280,
     DEFAULT = 281,
     ADD = 282,
     INC = 283,
     DEC = 284,
     SUB = 285,
     MUL = 286,
     DIV = 287,
     LE_OP = 288,
     GE_OP = 289,
     EQ_OP = 290,
     NE_OP = 291,
     ASIN = 292,
     SIN = 293,
     COS = 294,
     ACOS = 295,
     TAN = 296,
     ATAN = 297,
     LOG10 = 298,
     LOG = 299,
     POW = 300
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 527 "1907044.y"

    char text[1000];
    struct datatype value;



/* Line 1676 of yacc.c  */
#line 123 "1907044.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


