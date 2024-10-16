
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "1907044.y"

    #include<stdio.h>
    #include<stdlib.h>
    #include<math.h>
    #include<conio.h>
    #include<string.h>
    #include <ctype.h>
    #include <stdbool.h>

    struct identifier_data
{
    int type;
    char *varname;
    int valtype;
    char *strval;
    int intval;
    double realval;
};

struct identifier
{
    struct identifier_data data;
    struct identifier *next;

};

#ifndef CHECK
    #define CHECK
    struct CHECK datatype {
        int type;
        char *strval;
        int intval;
        double realval;
    };
    #endif


    void yyerror(char *);
    int main(void);
    int yylex(void);
    int currentType=-1;
    struct datatype switchCasedata;
    int caseflag;
    int ifdone[1000];
    int ifptr;
    struct identifier *head=NULL,*tail=NULL;

    #define ERROR(msg) do { fprintf(stderr, "Error: %s\n", msg); exit(EXIT_FAILURE); } while (0)


    struct identifier *isDeclared(struct identifier **head, char *varname) {
    struct identifier *now = *head, *ans = NULL;
        while (now != NULL) {
            if (strcmp(now->data.varname, varname) == 0) {
                ans = now;
                break;
            }
            now = now->next;
        }
        return ans;
    }

    struct identifier *getVal(struct identifier **head, char *str) {
        return isDeclared(head, str);
    }
    void setTypeFromVariable(char *varName) {
        struct identifier* temp = getVal(&head, varName);
        if (temp == NULL || temp->data.type != 6) {
            printf("error: can't be defined\n");
            exit(-1);
        }
        currentType = temp->data.intval;
    }

    int max(int a,int b){
        if(a>=b){
            return a;
        }
        return b;
    }

    void variable_type(struct datatype tmp){
        if(tmp.type==2){
            printf("\nType of the variable is Int\n");
            printf("\nValue of the variable %d\n", tmp.intval);
        }
        else if (tmp.type==3){
            printf("\nType of the variable is Float\n");
            printf("\nValue of the variable %lf\n",tmp.realval);
        }
        else if(tmp.type==4){
            printf("\nType of the variable is String\n");
            printf("\nValue of the variable %s\n",tmp.strval);
        }
    }

    

    struct identifier *findStructName(struct identifier **head, int id) {
    struct identifier *now = *head, *ans = NULL;
        while (now != NULL) {
            if (now->data.type == 6 && now->data.intval == id) {
                ans = now;
                break;
            }
            now = now->next;
        }
        return ans;
    }

    char *gettypename(int id, struct identifier** head) {
        switch (id) {
            case 0:
                return "VOID";
            case 1:
                return "INT";
            case 2:
                return "DOUBLE";
            case 3:
                return "STRING";
            default:
                {
                    struct identifier *res = findStructName(head, id);
                    if (res == NULL) {
                        printf("\nError: Struct not found\n");
                        exit(-1);
                    }
                    return res->data.varname;
                }
        }
    }

    void added(struct identifier **head, struct identifier **tail, struct identifier_data newdata) {
        if(newdata.type == 1){
            newdata.strval = strdup(gettypename(newdata.intval,head));
        }
        struct identifier *new_node = (struct identifier *)malloc(sizeof(struct identifier));
        new_node->data = newdata;
        new_node->next = NULL;
        if (*head == NULL) {
            *head = new_node;
        } else {
            (*tail)->next = new_node;
        }
        *(tail) = new_node;
        return;
    }

    

    bool boolvalue(struct datatype x) {
        switch (x.type) {
            case 2:
                return x.intval != 0;
            case 3:
                return x.realval != 0.0;
            case 4:
                return strlen(x.strval) > 0;
            default:
                return false;
        }
    }

    int check_digit(char c){
        return isdigit((unsigned char)c);
    }

    int check_int(char *c){
        int i;
        for(i=0;i<strlen(c);i++){
            if(check_digit(c[i])==0){
                return 0;
            }
        }
        return 1;
    }

    int check_real(char *c){
        int f=0;
        int i;
        for(i=0;i<strlen(c);i++){
            if(c[i]=='.'){
                f=1;
                continue;
            }
            if(check_digit(c[i])==0){
                return 0;
            }
        }
        if(f==1){
            return 1;
        }
        else{
            return 0;
        }
    }

    int determineType(char *val) {
        if (check_int(val)) {
            return 2; // Integer
        } else if (check_real(val)) {
            return 3; // Real number
        } else if (strlen(val) > 0) {
            return 4; // String
        } else {
            return 1; // Default to function
        }
    }

    struct identifier_data construct(int type,char *varname,char *val){
        struct identifier_data data;
        data.type=type;
        data.varname=strdup(varname);
        switch (type) {
            case 1: // function
                data.valtype = 1;
                data.intval = atoi(val);
                break;
            case 6: // struct
                data.valtype = 6;
                data.intval = atoi(val);
                break;

            default:
                if (check_int(val)) {
                    data.valtype = 2;
                    data.intval = atoi(val);
                } else if (check_real(val)) {
                    data.valtype = 3;
                    data.realval = atof(val);
                } else {
                    data.valtype = 4;
                    data.strval = strdup(val);
                }
                break;
        }
        return data;
    }

    int addNewVal(struct identifier **head, struct identifier **tail, char *str, char *val) {
        if (isDeclared(head, str) != NULL) {
            return 0;
        }

        int type = determineType(val);
        struct identifier_data tmp = construct(type, str, val);
        added(head, tail, tmp);
        return 1;
    }

    struct datatype make_datatype_int(int val){
        struct datatype tmp;
        tmp.type=2;
        tmp.intval=val;
        return tmp;
    }

    struct datatype make_datatype_double(double val){
        struct datatype tmp;
        tmp.type=3;
        tmp.realval=val;
        return tmp;
    }

    struct datatype make_datatype_char(char *val){
        struct datatype tmp;
        tmp.type=4;
        tmp.strval= calloc(strlen(val)+1,sizeof(char));
        strcpy(tmp.strval,val);
        return tmp;
    }

    void convert_to_str(struct datatype *a){
        if(a->type==2){
            a->type=4;
            int n= (int)log10(a->intval)+1;
            a->strval= calloc(n+1,sizeof(char));
            snprintf(a->strval,n+1,"%ld",a->intval);
        }
        else if(a->type==3){
            a->type=4;
            int n= 50;
            a->strval= calloc(n+1,sizeof(char));
            snprintf(a->strval,n,"%lf",a->intval);
        }
    }

    void convert_to_double(struct datatype *a){
        if(a->type==2){
            a->type=3;
            a->realval=a->intval*1.0;
        }
    }

    void makesame(struct datatype *a,struct datatype *b){
        if(a->type==b->type){
            return;
        }
        else if (a->type==4 || b->type==4){
            convert_to_str(a);
            convert_to_str(b);
        }
        else if(a->type==3 || b->type==3){
            convert_to_double(a);
            convert_to_double(b);
        }

    }

    struct datatype prepare_for_evaluate(struct datatype *a,struct datatype *b){
        makesame(a,b);
        struct datatype temp;
        if(temp.type==2){
            temp= make_datatype_int(a->intval);
        }
        if(a->type==3){
            temp= make_datatype_double(a->realval);
        }
        if(a->type==4){
            temp= make_datatype_char(a->strval);
        }
        return temp;
    }

    struct datatype evaluate(struct datatype a,struct datatype b,char *sign) {
        struct datatype tmp;
        int type = max(a.type, b.type);
        if (strcmp(sign, "+") == 0) {
            tmp = prepare_for_evaluate(&a, &b);
            if (type == 2) {
                tmp.intval = a.intval + b.intval;
            } else if (type == 3) {
                tmp.realval = a.realval + b.realval;
            } else if (type == 4) {
                realloc(tmp.strval, (strlen(a.strval) + strlen(b.strval) + 1) * sizeof(char));
                strcat(tmp.strval, b.strval);
            }
            variable_type(tmp);
        }
        else if (strcmp(sign, "*") == 0) {
            int str_len;
            if((a.type==2 && b.type==4) || (a.type==4 && b.type==2)){
                str_len=max(a.intval,b.intval);
            }
            tmp = prepare_for_evaluate(&a, &b);
            if (type == 2) {
                tmp.intval = a.intval * b.intval;
            } else if (type == 3) {
                tmp.realval = a.realval * b.realval;
            } 
        }
        else if(strcmp(sign,"/")==0){
            tmp = prepare_for_evaluate(&a, &b);
            if(a.type==2){
                if(b.intval==0){
                    printf("Division by zero error\n");
                    exit(-1);
                }
                tmp.intval=a.intval/b.intval;
            }
            else if(a.type==3){
                if(b.realval==0.0){
                    printf("Division by zero error\n");
                    exit(-1);
                }
                tmp.realval=a.realval/b.realval;
            }
        }
        else if (strcmp(sign,"-")==0){
            tmp = prepare_for_evaluate(&a, &b);
            if(a.type==2){
                tmp.intval=a.intval-b.intval;
            } else if(a.type==3){
                tmp.realval=a.realval-b.realval;
            }
            else{
                printf("compilation error in minus\n");
                exit(-1);
            }
        }
        else if(strcmp(sign,"<")==0){
            prepare_for_evaluate(&a, &b);
            tmp.type=2;
            if(a.type==2 || a.type==3){
                tmp.intval=(a.type==2?a.intval<b.intval:a.realval<b.realval);
            }else{
                tmp.intval=strcmp(a.strval,b.strval)<0;
            }
        }
        else if(strcmp(sign,"<=")==0){
            prepare_for_evaluate(&a, &b);
            tmp.type=2;
            if(a.type==2 || a.type==3){
                tmp.intval=(a.type==2?(a.intval<=b.intval):(a.realval<=b.realval));
            }else{
                tmp.intval=strcmp(a.strval,b.strval)<=0;
            }
        }
        else if(strcmp(sign,">")==0){
            prepare_for_evaluate(&a, &b);
            tmp.type=2;
            if(a.type==2 || a.type==3){
                tmp.intval=(a.type==2?(a.intval>b.intval):(a.realval>b.realval));
            }else{
                tmp.intval=strcmp(a.strval,b.strval)>0;
            }
        }
        else if(strcmp(sign,">=")==0){
            prepare_for_evaluate(&a, &b);
            tmp.type=2;
            if(a.type==2 || a.type==3){
                tmp.intval=(a.type==2?a.intval>=b.intval:a.realval>=b.realval);
            }else{
                tmp.intval=strcmp(a.strval,b.strval)>=0;
            }
        }
        else if(strcmp(sign,"==")==0){
            prepare_for_evaluate(&a, &b);
            tmp.type=2;
            if(a.type==2 || a.type==3){
                tmp.intval=(a.type==2?a.intval==b.intval:a.realval==b.realval);
            }else{
                tmp.intval=strcmp(a.strval,b.strval)==0;
            }   
        }
        else if(strcmp(sign,"!=")==0){
            prepare_for_evaluate(&a, &b);
            tmp.type=2;
            if(a.type==2 || a.type==3){
                tmp.intval=(a.type==2?a.intval!=b.intval:a.realval!=b.realval);
            }else{
                tmp.intval=strcmp(a.strval,b.strval)!=0;
            }
        }
        else if(strcmp(sign,"%")==0){
            if(type==2){
                tmp= prepare_for_evaluate(&a,&b);
                tmp.intval=a.intval%b.intval;
            }
            else{
                printf("compilation error in mod\n");
            }
        }

        else if(strcmp(sign,"^")==0){
            if(type==2){
                tmp= prepare_for_evaluate(&a,&b);
                tmp.intval=a.intval^b.intval;
            }
            else{
                printf("compilation error in XOR\n");
            }
        }
        else if(strcmp(sign,"&")==0){
            if(type==2){
                tmp= prepare_for_evaluate(&a,&b);
                tmp.intval=a.intval&b.intval;
            }
            else{
                printf("compilation error in AND\n");
            }
        }
        else if(strcmp(sign,"|")==0){
            if(type==2){
                tmp= prepare_for_evaluate(&a,&b);
                tmp.intval=a.intval%b.intval;
            }
            else{
                printf("compilation error in mod\n");
            }
        }
        return tmp;
    }

    void setVal(struct identifier **head, struct identifier **tail, char *str, char *val) {
        struct identifier *idx = isDeclared(head, str);
        if (idx == NULL) {
            addNewVal(head, tail, str, val);
        }
        else if(idx->data.type == 1 || idx->data.type == 6){
            printf("Error :: You can't set a value to struct/function");
            exit(-1);
        }
        else {
            int type = 1;
            if (check_int(val))
                type = 2;
            else if (check_real(val))
                type = 3;
            else if (strlen(val) > 0)
                type = 4;
            idx->data = construct(type, str, val);
        }
    }

    int addFuncToSymTable(struct identifier **head, struct identifier **tail, char *str, char *val) {
        if (isDeclared(head, str) != NULL)
            return 0;
        int type = 1;
        struct identifier_data tmp = construct(type, str, val);
        added(head, tail, tmp);
        return 1;
    }

    int addStructToSymTable(struct identifier **head, struct identifier **tail, char *str, char *val) {
        if (isDeclared(head, str) != NULL)
            return 0;
        int type = 6;
        struct identifier_data tmp = construct(type, str, val);
        added(head, tail, tmp);
        return 1;
    }


/* Line 189 of yacc.c  */
#line 588 "1907044.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

/* "%code requires" blocks.  */

/* Line 209 of yacc.c  */
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



/* Line 209 of yacc.c  */
#line 626 "1907044.tab.c"

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

/* Line 214 of yacc.c  */
#line 527 "1907044.y"

    char text[1000];
    struct datatype value;



/* Line 214 of yacc.c  */
#line 695 "1907044.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 707 "1907044.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  65
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   896

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  85
/* YYNRULES -- Number of states.  */
#define YYNSTATES  241

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   300

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      48,    49,     2,     2,    50,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    51,     2,
      52,     2,    53,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    46,     2,    47,     2,     2,     2,     2,
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
      45
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     7,    10,    13,    16,    19,    25,
      35,    37,    39,    41,    43,    45,    46,    50,    55,    56,
      59,    62,    65,    68,    71,    74,    77,    80,    83,    84,
      93,    94,   101,   105,   106,   116,   117,   118,   128,   133,
     135,   137,   139,   144,   149,   154,   159,   164,   169,   174,
     179,   186,   190,   194,   198,   202,   206,   210,   214,   218,
     222,   226,   230,   233,   235,   238,   242,   244,   248,   250,
     254,   256,   269,   282,   295,   308,   317,   322,   323,   329,
     330,   335,   337,   341,   344,   347
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      55,     0,    -1,    -1,    83,    55,    -1,    71,    55,    -1,
      60,    55,    -1,    56,    55,    -1,    57,    55,    -1,    16,
       4,    46,    60,    47,    -1,    58,    17,     4,    48,    59,
      49,    46,    60,    47,    -1,     9,    -1,    10,    -1,    11,
      -1,    12,    -1,     4,    -1,    -1,    58,     4,    59,    -1,
      50,    58,     4,    59,    -1,    -1,    65,    60,    -1,    71,
      60,    -1,    74,    60,    -1,    70,    60,    -1,    69,    60,
      -1,    61,    60,    -1,    75,    60,    -1,    76,    60,    -1,
      78,    60,    -1,    -1,    24,    48,    69,    49,    62,    46,
      63,    47,    -1,    -1,    25,    69,    51,    60,    64,    63,
      -1,    26,    51,    60,    -1,    -1,    21,    48,    69,    49,
      46,    60,    47,    66,    67,    -1,    -1,    -1,    22,    48,
      69,    49,    46,    60,    47,    68,    67,    -1,    23,    46,
      60,    47,    -1,     5,    -1,     6,    -1,     7,    -1,    38,
      48,    69,    49,    -1,    37,    48,    69,    49,    -1,    40,
      48,    69,    49,    -1,    39,    48,    69,    49,    -1,    41,
      48,    69,    49,    -1,    42,    48,    69,    49,    -1,    44,
      48,    69,    49,    -1,    43,    48,    69,    49,    -1,    45,
      48,    69,    50,    69,    49,    -1,    69,    27,    69,    -1,
      69,    30,    69,    -1,    69,    32,    69,    -1,    69,    31,
      69,    -1,    69,    33,    69,    -1,    69,    34,    69,    -1,
      69,    52,    69,    -1,    69,    53,    69,    -1,    69,    35,
      69,    -1,    69,    36,    69,    -1,    48,    69,    49,    -1,
      14,    69,    -1,    14,    -1,    58,    72,    -1,    73,    50,
      72,    -1,    73,    -1,     4,    13,    69,    -1,     4,    -1,
      82,    50,    74,    -1,    82,    -1,    19,    48,    69,    51,
      52,    69,    51,    69,    49,    46,    69,    47,    -1,    19,
      48,    69,    51,    53,    69,    51,    69,    49,    46,    69,
      47,    -1,    19,    48,    69,    51,    33,    69,    51,    69,
      49,    46,    69,    47,    -1,    19,    48,    69,    51,    34,
      69,    51,    69,    49,    46,    69,    47,    -1,    20,    48,
      69,    49,    46,    69,    77,    47,    -1,    18,    48,    69,
      49,    -1,    -1,    15,    48,    79,    80,    49,    -1,    -1,
      69,    81,    50,    80,    -1,    69,    -1,     7,    13,    69,
      -1,     7,    28,    -1,     7,    29,    -1,     8,    52,     3,
      53,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   551,   551,   552,   553,   554,   555,   556,   559,   572,
     586,   587,   588,   589,   590,   593,   594,   595,   598,   599,
     600,   601,   602,   603,   604,   605,   606,   607,   610,   610,
     615,   615,   621,   627,   627,   638,   639,   639,   645,   652,
     659,   663,   691,   703,   715,   727,   739,   751,   763,   775,
     787,   809,   810,   811,   812,   813,   814,   815,   816,   817,
     818,   819,   822,   827,   832,   835,   836,   839,   874,   883,
     884,   887,   908,   929,   950,   973,  1014,  1022,  1022,  1027,
    1027,  1030,  1034,  1066,  1110,  1156
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "HEADER_FILE", "VARIABLE", "NUMBER",
  "STR", "VARIABLE_ACCESS", "HEADER", "INTEGER", "FLOAT", "STRING", "VOID",
  "ALLOCATION", "RETURN", "PRINT", "STRUCT", "FUNC", "BREAK", "FOR",
  "WHILE", "IF", "ELSE_IF", "ELSE", "SWITCH", "CASE", "DEFAULT", "ADD",
  "INC", "DEC", "SUB", "MUL", "DIV", "LE_OP", "GE_OP", "EQ_OP", "NE_OP",
  "ASIN", "SIN", "COS", "ACOS", "TAN", "ATAN", "LOG10", "LOG", "POW",
  "'{'", "'}'", "'('", "')'", "','", "':'", "'<'", "'>'", "$accept",
  "program", "struct", "function", "type", "func_para", "stmt", "switch",
  "$@1", "casegrammer", "$@2", "if", "$@3", "elsifgrmr", "$@4",
  "expression", "return", "declare", "variables", "variable", "assign",
  "for", "while", "condition", "display", "$@5", "mul_exp", "$@6",
  "varassign", "include", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   123,   125,    40,    41,
      44,    58,    60,    62
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    54,    55,    55,    55,    55,    55,    55,    56,    57,
      58,    58,    58,    58,    58,    59,    59,    59,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    62,    61,
      64,    63,    63,    66,    65,    67,    68,    67,    67,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    70,    70,    71,    72,    72,    73,    73,    74,
      74,    75,    75,    75,    75,    76,    77,    79,    78,    81,
      80,    80,    82,    82,    82,    83
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     2,     2,     2,     2,     5,     9,
       1,     1,     1,     1,     1,     0,     3,     4,     0,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     0,     8,
       0,     6,     3,     0,     9,     0,     0,     9,     4,     1,
       1,     1,     4,     4,     4,     4,     4,     4,     4,     4,
       6,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     1,     2,     3,     1,     3,     1,     3,
       1,    12,    12,    12,    12,     8,     4,     0,     5,     0,
       4,     1,     3,     2,     2,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,    14,    39,    40,    41,     0,    10,    11,    12,    13,
      63,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     2,     2,
       0,     2,    18,    18,    18,    18,     2,    18,    18,    18,
      18,    70,     2,     0,    83,    84,     0,    41,    62,    77,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     1,     6,     7,    68,     0,
      64,    66,     5,     0,    24,    18,    19,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    23,    22,     4,
       2,    21,    25,    26,    27,     0,     3,    82,     0,     0,
      18,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    61,     0,     0,     0,    20,    51,
      52,    54,    53,    55,    56,    59,    60,    57,    58,     0,
      69,    85,    79,     0,     0,     0,     0,     0,    28,    43,
      42,    45,    44,    46,    47,    49,    48,     0,    67,    15,
      65,     0,    78,     8,     0,     0,     0,     0,     0,    18,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    50,     0,    15,     0,    80,     0,     0,
       0,     0,     0,     0,    33,     0,     0,     0,    15,    16,
      18,     0,     0,     0,     0,     0,    75,    35,     0,    18,
      29,    17,     0,     0,     0,     0,     0,     0,     0,     0,
      34,    18,    32,     9,     0,     0,     0,     0,    76,     0,
      18,    30,     0,     0,     0,     0,     0,     0,     0,    73,
      74,    71,    72,     0,    38,    31,    18,     0,    36,    35,
      37
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    72,    28,    29,    73,   164,    31,    32,   160,   187,
     228,    33,   197,   210,   239,    34,    35,    75,    70,    71,
      37,    38,    39,   183,    40,    99,   133,   151,    41,    42
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -95
static const yytype_int16 yypact[] =
{
     281,   -95,   -95,   -95,    49,   -42,   -95,   -95,   -95,   -95,
      91,   -37,     9,   -33,   -16,    -8,     6,    15,    16,    17,
      35,    36,    44,    52,    54,    55,    91,   104,   281,   281,
      -3,   281,   326,   326,   231,   326,   281,   326,   326,   326,
     326,    56,   281,    91,   -95,   -95,   109,   -95,   843,   -95,
      61,    91,    91,    91,    91,    91,    91,    91,    91,    91,
      91,    91,    91,    91,   131,   -95,   -95,   -95,    95,   115,
     -95,    70,   -95,   117,   -95,   326,   -95,    91,    91,    91,
      91,    91,    91,    91,    91,    91,    91,   -95,   -95,   -95,
     281,   -95,   -95,   -95,   -95,   116,   -95,   843,    69,    91,
     326,   324,   351,   361,   385,   395,   419,   429,   453,   463,
     487,   497,   521,   531,   -95,    91,    77,   117,   -95,     3,
       3,   -31,   -31,   843,   843,   843,   843,   843,   843,    49,
     -95,   -95,   555,    78,    79,    27,    92,    94,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,    91,   843,     8,
     -95,    93,   -95,   -95,    91,    91,    91,    91,    91,   326,
      96,   565,   105,   137,   102,    91,   589,   599,   626,   636,
     161,   106,   -19,   -95,   148,     8,   108,   -95,    91,    91,
      91,    91,   111,   110,   -95,    91,   122,   113,     8,   -95,
     326,   663,   673,   697,   707,    91,   -95,   -14,   731,   326,
     -95,   -95,   127,   130,   132,   136,   140,   741,   129,   141,
     -95,   326,   -95,   -95,    91,    91,    91,    91,   -95,    91,
     326,   -95,   765,   775,   799,   809,   833,   142,   -19,   -95,
     -95,   -95,   -95,   152,   -95,   -95,   326,   153,   -95,   -14,
     -95
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -95,    57,   -95,   -95,    59,   -94,    -9,   -95,   -95,   -72,
     -95,   -95,   -95,   -40,   -95,   -10,   -95,    82,    84,   -95,
     120,   -95,   -95,   -95,   -95,   -95,    38,   -95,   -95,   -95
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -82
static const yytype_int16 yytable[] =
{
      48,    68,    81,    82,    83,    84,   185,   186,   208,   209,
      46,    49,     1,    50,    69,    51,    64,     6,     7,     8,
       9,    85,    86,    74,    76,    87,    88,    90,    91,    92,
      93,    94,    52,    97,    79,    80,    81,    82,    83,    84,
      53,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,    54,    85,    86,    27,   162,    30,
     154,   155,    43,    55,    56,    57,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,    44,    45,   156,
     157,   189,    36,    58,    59,    66,    67,    30,    30,   132,
      30,   134,    60,    89,   201,    30,     2,     3,    47,    96,
      61,    30,    62,    63,    65,   148,    95,   100,   115,     1,
      36,    36,    98,    36,     6,     7,     8,     9,    36,   116,
     117,    68,   131,   129,    36,   149,   153,   152,    17,    18,
      19,    20,    21,    22,    23,    24,    25,   161,   158,    26,
     159,   175,   172,   165,   166,   167,   168,   169,   170,    30,
     171,   176,   188,   184,   190,   132,   235,   196,    77,   195,
     200,    78,    79,    80,    81,    82,    83,    84,   191,   192,
     193,   194,    36,   199,   213,   198,   214,   219,   215,   182,
     114,   202,   216,    85,    86,   207,   217,   220,    77,   234,
     212,    78,    79,    80,    81,    82,    83,    84,   236,   240,
     238,   150,   221,   177,   222,   223,   224,   225,   163,   226,
       0,   227,     0,    85,    86,   130,     0,     0,     0,     0,
       0,   174,     0,     0,     0,     0,     0,   237,     0,     0,
       0,     0,     0,     0,   163,     1,     2,     3,     4,     0,
       6,     7,     8,     9,     0,    10,    11,   163,     0,     0,
      13,    14,    15,     0,     0,    16,     0,     0,    77,     0,
       0,    78,    79,    80,    81,    82,    83,    84,    17,    18,
      19,    20,    21,    22,    23,    24,    25,     0,     0,    26,
       0,     0,     0,    85,    86,     1,     2,     3,     4,     5,
       6,     7,     8,     9,     0,    10,    11,    12,     0,     0,
      13,    14,    15,     0,     0,    16,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    17,    18,
      19,    20,    21,    22,    23,    24,    25,     0,     0,    26,
       1,     2,     3,     4,     0,     6,     7,     8,     9,     0,
      10,    11,     0,     0,     0,    13,    14,    15,     0,     0,
      16,    77,     0,     0,    78,    79,    80,    81,    82,    83,
      84,     0,     0,    17,    18,    19,    20,    21,    22,    23,
      24,    25,     0,     0,    26,   135,    85,    86,    77,     0,
       0,    78,    79,    80,    81,    82,    83,    84,    77,     0,
       0,    78,    79,    80,    81,    82,    83,    84,     0,     0,
     136,     0,     0,    85,    86,     0,     0,     0,     0,     0,
     137,     0,    77,    85,    86,    78,    79,    80,    81,    82,
      83,    84,    77,     0,     0,    78,    79,    80,    81,    82,
      83,    84,     0,     0,   138,     0,     0,    85,    86,     0,
       0,     0,     0,     0,   139,     0,    77,    85,    86,    78,
      79,    80,    81,    82,    83,    84,    77,     0,     0,    78,
      79,    80,    81,    82,    83,    84,     0,     0,   140,     0,
       0,    85,    86,     0,     0,     0,     0,     0,   141,     0,
      77,    85,    86,    78,    79,    80,    81,    82,    83,    84,
      77,     0,     0,    78,    79,    80,    81,    82,    83,    84,
       0,     0,   142,     0,     0,    85,    86,     0,     0,     0,
       0,     0,   143,     0,    77,    85,    86,    78,    79,    80,
      81,    82,    83,    84,    77,     0,     0,    78,    79,    80,
      81,    82,    83,    84,     0,     0,   144,     0,     0,    85,
      86,     0,     0,     0,     0,     0,   145,     0,    77,    85,
      86,    78,    79,    80,    81,    82,    83,    84,    77,     0,
       0,    78,    79,    80,    81,    82,    83,    84,     0,     0,
     146,     0,     0,    85,    86,     0,     0,     0,     0,     0,
       0,   147,    77,    85,    86,    78,    79,    80,    81,    82,
      83,    84,    77,     0,     0,    78,    79,    80,    81,    82,
      83,    84,     0,     0,   -81,     0,     0,    85,    86,     0,
       0,     0,     0,     0,   173,     0,    77,    85,    86,    78,
      79,    80,    81,    82,    83,    84,    77,     0,     0,    78,
      79,    80,    81,    82,    83,    84,     0,     0,     0,     0,
     178,    85,    86,     0,     0,     0,     0,     0,     0,     0,
     179,    85,    86,    77,     0,     0,    78,    79,    80,    81,
      82,    83,    84,    77,     0,     0,    78,    79,    80,    81,
      82,    83,    84,     0,     0,     0,     0,   180,    85,    86,
       0,     0,     0,     0,     0,     0,     0,   181,    85,    86,
      77,     0,     0,    78,    79,    80,    81,    82,    83,    84,
      77,     0,     0,    78,    79,    80,    81,    82,    83,    84,
       0,     0,   203,     0,     0,    85,    86,     0,     0,     0,
       0,     0,   204,     0,    77,    85,    86,    78,    79,    80,
      81,    82,    83,    84,    77,     0,     0,    78,    79,    80,
      81,    82,    83,    84,     0,     0,   205,     0,     0,    85,
      86,     0,     0,     0,     0,     0,   206,     0,    77,    85,
      86,    78,    79,    80,    81,    82,    83,    84,    77,     0,
       0,    78,    79,    80,    81,    82,    83,    84,     0,     0,
       0,     0,   211,    85,    86,     0,     0,     0,     0,     0,
     218,     0,    77,    85,    86,    78,    79,    80,    81,    82,
      83,    84,    77,     0,     0,    78,    79,    80,    81,    82,
      83,    84,   229,     0,     0,     0,     0,    85,    86,     0,
       0,     0,   230,     0,     0,     0,    77,    85,    86,    78,
      79,    80,    81,    82,    83,    84,    77,     0,     0,    78,
      79,    80,    81,    82,    83,    84,   231,     0,     0,     0,
       0,    85,    86,     0,     0,     0,   232,     0,     0,     0,
      77,    85,    86,    78,    79,    80,    81,    82,    83,    84,
      77,     0,     0,    78,    79,    80,    81,    82,    83,    84,
       0,     0,   233,     0,     0,    85,    86,     0,     0,     0,
       0,     0,     0,     0,     0,    85,    86
};

static const yytype_int16 yycheck[] =
{
      10,     4,    33,    34,    35,    36,    25,    26,    22,    23,
      52,    48,     4,     4,    17,    48,    26,     9,    10,    11,
      12,    52,    53,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    48,    43,    31,    32,    33,    34,    35,    36,
      48,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    48,    52,    53,     0,    50,     0,
      33,    34,    13,    48,    48,    48,    75,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    28,    29,    52,
      53,   175,     0,    48,    48,    28,    29,    28,    29,    99,
      31,   100,    48,    36,   188,    36,     5,     6,     7,    42,
      48,    42,    48,    48,     0,   115,    50,    46,    13,     4,
      28,    29,     3,    31,     9,    10,    11,    12,    36,     4,
      50,     4,    53,     7,    42,    48,    47,    49,    37,    38,
      39,    40,    41,    42,    43,    44,    45,   147,    46,    48,
      46,     4,    46,    50,   154,   155,   156,   157,   158,    90,
     159,    49,     4,    47,    46,   165,   228,    47,    27,    48,
      47,    30,    31,    32,    33,    34,    35,    36,   178,   179,
     180,   181,    90,    51,    47,   185,    46,    48,    46,    18,
      49,   190,    46,    52,    53,   195,    46,    46,    27,    47,
     199,    30,    31,    32,    33,    34,    35,    36,    46,   239,
      47,   117,   211,   165,   214,   215,   216,   217,   149,   219,
      -1,   220,    -1,    52,    53,    95,    -1,    -1,    -1,    -1,
      -1,   162,    -1,    -1,    -1,    -1,    -1,   236,    -1,    -1,
      -1,    -1,    -1,    -1,   175,     4,     5,     6,     7,    -1,
       9,    10,    11,    12,    -1,    14,    15,   188,    -1,    -1,
      19,    20,    21,    -1,    -1,    24,    -1,    -1,    27,    -1,
      -1,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    -1,    -1,    48,
      -1,    -1,    -1,    52,    53,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    -1,    14,    15,    16,    -1,    -1,
      19,    20,    21,    -1,    -1,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    -1,    -1,    48,
       4,     5,     6,     7,    -1,     9,    10,    11,    12,    -1,
      14,    15,    -1,    -1,    -1,    19,    20,    21,    -1,    -1,
      24,    27,    -1,    -1,    30,    31,    32,    33,    34,    35,
      36,    -1,    -1,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    -1,    -1,    48,    51,    52,    53,    27,    -1,
      -1,    30,    31,    32,    33,    34,    35,    36,    27,    -1,
      -1,    30,    31,    32,    33,    34,    35,    36,    -1,    -1,
      49,    -1,    -1,    52,    53,    -1,    -1,    -1,    -1,    -1,
      49,    -1,    27,    52,    53,    30,    31,    32,    33,    34,
      35,    36,    27,    -1,    -1,    30,    31,    32,    33,    34,
      35,    36,    -1,    -1,    49,    -1,    -1,    52,    53,    -1,
      -1,    -1,    -1,    -1,    49,    -1,    27,    52,    53,    30,
      31,    32,    33,    34,    35,    36,    27,    -1,    -1,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,    49,    -1,
      -1,    52,    53,    -1,    -1,    -1,    -1,    -1,    49,    -1,
      27,    52,    53,    30,    31,    32,    33,    34,    35,    36,
      27,    -1,    -1,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,    49,    -1,    -1,    52,    53,    -1,    -1,    -1,
      -1,    -1,    49,    -1,    27,    52,    53,    30,    31,    32,
      33,    34,    35,    36,    27,    -1,    -1,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    49,    -1,    -1,    52,
      53,    -1,    -1,    -1,    -1,    -1,    49,    -1,    27,    52,
      53,    30,    31,    32,    33,    34,    35,    36,    27,    -1,
      -1,    30,    31,    32,    33,    34,    35,    36,    -1,    -1,
      49,    -1,    -1,    52,    53,    -1,    -1,    -1,    -1,    -1,
      -1,    50,    27,    52,    53,    30,    31,    32,    33,    34,
      35,    36,    27,    -1,    -1,    30,    31,    32,    33,    34,
      35,    36,    -1,    -1,    49,    -1,    -1,    52,    53,    -1,
      -1,    -1,    -1,    -1,    49,    -1,    27,    52,    53,    30,
      31,    32,    33,    34,    35,    36,    27,    -1,    -1,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,
      51,    52,    53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      51,    52,    53,    27,    -1,    -1,    30,    31,    32,    33,
      34,    35,    36,    27,    -1,    -1,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,    -1,    -1,    51,    52,    53,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    52,    53,
      27,    -1,    -1,    30,    31,    32,    33,    34,    35,    36,
      27,    -1,    -1,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,    49,    -1,    -1,    52,    53,    -1,    -1,    -1,
      -1,    -1,    49,    -1,    27,    52,    53,    30,    31,    32,
      33,    34,    35,    36,    27,    -1,    -1,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    49,    -1,    -1,    52,
      53,    -1,    -1,    -1,    -1,    -1,    49,    -1,    27,    52,
      53,    30,    31,    32,    33,    34,    35,    36,    27,    -1,
      -1,    30,    31,    32,    33,    34,    35,    36,    -1,    -1,
      -1,    -1,    51,    52,    53,    -1,    -1,    -1,    -1,    -1,
      49,    -1,    27,    52,    53,    30,    31,    32,    33,    34,
      35,    36,    27,    -1,    -1,    30,    31,    32,    33,    34,
      35,    36,    47,    -1,    -1,    -1,    -1,    52,    53,    -1,
      -1,    -1,    47,    -1,    -1,    -1,    27,    52,    53,    30,
      31,    32,    33,    34,    35,    36,    27,    -1,    -1,    30,
      31,    32,    33,    34,    35,    36,    47,    -1,    -1,    -1,
      -1,    52,    53,    -1,    -1,    -1,    47,    -1,    -1,    -1,
      27,    52,    53,    30,    31,    32,    33,    34,    35,    36,
      27,    -1,    -1,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,    49,    -1,    -1,    52,    53,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    52,    53
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      14,    15,    16,    19,    20,    21,    24,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    48,    55,    56,    57,
      58,    60,    61,    65,    69,    70,    71,    74,    75,    76,
      78,    82,    83,    13,    28,    29,    52,     7,    69,    48,
       4,    48,    48,    48,    48,    48,    48,    48,    48,    48,
      48,    48,    48,    48,    69,     0,    55,    55,     4,    17,
      72,    73,    55,    58,    60,    71,    60,    27,    30,    31,
      32,    33,    34,    35,    36,    52,    53,    60,    60,    55,
      60,    60,    60,    60,    60,    50,    55,    69,     3,    79,
      46,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    49,    13,     4,    50,    60,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,     7,
      74,    53,    69,    80,    60,    51,    49,    49,    49,    49,
      49,    49,    49,    49,    49,    49,    49,    50,    69,    48,
      72,    81,    49,    47,    33,    34,    52,    53,    46,    46,
      62,    69,    50,    58,    59,    50,    69,    69,    69,    69,
      69,    60,    46,    49,    58,     4,    49,    80,    51,    51,
      51,    51,    18,    77,    47,    25,    26,    63,     4,    59,
      46,    69,    69,    69,    69,    48,    47,    66,    69,    51,
      47,    59,    60,    49,    49,    49,    49,    69,    22,    23,
      67,    51,    60,    47,    46,    46,    46,    46,    49,    48,
      46,    60,    69,    69,    69,    69,    69,    60,    64,    47,
      47,    47,    47,    49,    47,    63,    46,    60,    47,    68,
      67
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
	    /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

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

/* Line 1455 of yacc.c  */
#line 551 "1907044.y"
    {printf("\nSuccessfully Executed\n");;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 559 "1907044.y"
    {int temp=addStructToSymTable(&head,&tail,(yyvsp[(2) - (5)].text),"");
                                                        if(!temp)
                                                        {
                                                            printf("\nError: %s is already declared.\n",(yyvsp[(2) - (5)].text));
                                                            exit(-1);
                                                        }   
                                                        else{
                                                            printf("struct successfully declared\n");
                                                        }                     

                                                      ;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 572 "1907044.y"
    {char *val;
                                                                                int n=log10(currentType)+1;
                                                                                val=calloc(n+1,sizeof(char));
                                                                                snprintf(val,n,"%ld",currentType);
                                                                                int res=addFuncToSymTable(&head,&tail,(yyvsp[(3) - (9)].text),val);
                                                                                if(!res){
                                                                                    printf("Compilation error: %s already declared\n",(yyvsp[(3) - (9)].text));
                                                                                }
                                                                                else{
                                                                                    printf("function successfully declared: %s\n",(yyvsp[(3) - (9)].text));
                                                                                }
                                                                            ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 586 "1907044.y"
    { currentType = 1; ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 587 "1907044.y"
    { currentType = 2; ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 588 "1907044.y"
    { currentType = 3; ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 589 "1907044.y"
    { currentType = 4; ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 590 "1907044.y"
    { setTypeFromVariable((yyvsp[(1) - (1)].text)); ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 610 "1907044.y"
    {
                        switchCasedata = (yyvsp[(3) - (4)].value);
                        printf("\n\nSwitch case \n");
                    ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 615 "1907044.y"
    {
                    if(caseflag == 0 && evaluate((yyvsp[(2) - (4)].value),switchCasedata,"==").intval == 1){
                        caseflag = 1;
                        printf("\nCase executed : %d\n",(yyvsp[(2) - (4)].value).intval);
                    }
                ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 621 "1907044.y"
    {if(caseflag == 0){
                                            printf("\nDefualt executed\n");
                                        }
                                    ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 627 "1907044.y"
    {
                        ifptr++;
                        if(boolvalue((yyvsp[(3) - (7)].value))){
                            printf("\n\nIF Block executed\n");
                            ifdone[ifptr]=1;
                        }
                    ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 633 "1907044.y"
    {
                        ifptr--;
                    ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 639 "1907044.y"
    {
                    if(ifdone[ifptr]==0 && boolvalue((yyvsp[(3) - (7)].value))){
                      ifdone[ifptr]=1;
                      printf("ELSE IF Block executed\n");
                    }
                ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 645 "1907044.y"
    {
                    if(ifdone[ifptr]==0){
                        printf("ELSE Block executed\n\n");
                    }
                ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 652 "1907044.y"
    {(yyval.value)=(yyvsp[(1) - (1)].value);
                        if((yyvsp[(1) - (1)].value).type == 2){
                            printf("\nInt value is %d\n",(yyvsp[(1) - (1)].value).intval);
                        }
                        else if((yyvsp[(1) - (1)].value).type == 3){
                            printf("\nFloat value is %lf\n",(yyvsp[(1) - (1)].value).realval);
                        };}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 659 "1907044.y"
    {(yyval.value)=(yyvsp[(1) - (1)].value);
                        if((yyvsp[(1) - (1)].value).type == 4){
                            printf("\nString value is %s\n",(yyvsp[(1) - (1)].value).strval);
                        };}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 663 "1907044.y"
    {struct identifier* res = isDeclared(&head,(yyvsp[(1) - (1)].text));
                                        if(res==NULL){
                                            printf("Compilation Error:  Varribale %s is not declared\n",(yyvsp[(1) - (1)].text));
                                            exit(-1);
                                        }
                                        else if(res->data.type == 1 || res->data.type == 6){
                                            printf("Error: You can't set a value to struct/function");
                                            exit(-1);
                                        }
                                        else {
                                            if(res->data.type==2){
                                                (yyval.value) = make_datatype_int(res->data.intval);}
                                            else if(res->data.type==3){
                                                (yyval.value) = make_datatype_double(res->data.realval);}
                                            else if(res->data.type==4){
                                                (yyval.value) = make_datatype_char(res->data.strval);
                                            }
                                            if((yyval.value).type==2){
                                                printf("Int value is %d\n", (yyval.value).intval);
                                            }
                                            else if ((yyval.value).type==3){
                                                printf("Float value is %lf\n",(yyval.value).realval);
                                            }
                                            else if((yyval.value).type==4){
                                                printf("String value is %s\n",(yyval.value).strval);
                                            }
                                        }
                                    ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 691 "1907044.y"
    {if((yyvsp[(3) - (4)].value).type==4){
                                            printf("Compilation Error: Cannot convert a String to Double\n");
                                            exit(-1);
                                            }
                                        double val;
                                        if((yyvsp[(3) - (4)].value).type==2){
                                            val = (yyvsp[(3) - (4)].value).intval;
                                        }else if((yyvsp[(3) - (4)].value).type==3){
                                            val = (yyvsp[(3) - (4)].value).realval;
                                        }
                                        printf("Value of the expression: %f\n",sin(val));
                                        ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 703 "1907044.y"
    {if((yyvsp[(3) - (4)].value).type==4){
                                            printf("Compilation Error: Cannot convert a String to Double\n");
                                            exit(-1);
                                        }
                                        double val;
                                        if((yyvsp[(3) - (4)].value).type==2){
                                            val = (yyvsp[(3) - (4)].value).intval;
                                        }else if((yyvsp[(3) - (4)].value).type==3){
                                            val = (yyvsp[(3) - (4)].value).realval;
                                        }
                                        printf("Value of the expression :: %f\n",asin(val));
                                        ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 715 "1907044.y"
    {if((yyvsp[(3) - (4)].value).type==4){
                                            printf("Compilation Error :: Cannot convert a String to Double\n");
                                            exit(-1);
                                        }
                                        double val;
                                        if((yyvsp[(3) - (4)].value).type==2){
                                            val = (yyvsp[(3) - (4)].value).intval;
                                        }else if((yyvsp[(3) - (4)].value).type==3){
                                            val = (yyvsp[(3) - (4)].value).realval;
                                        }
                                        printf("Value of the expression :: %f\n",acos(val));
                                        ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 727 "1907044.y"
    {if((yyvsp[(3) - (4)].value).type==4){
                                            printf("Compilation Error :: Cannot convert a String to Double\n");
                                            exit(-1);
                                        }
                                        double val;
                                        if((yyvsp[(3) - (4)].value).type==2){
                                            val = (yyvsp[(3) - (4)].value).intval;
                                        }else if((yyvsp[(3) - (4)].value).type==3){
                                            val = (yyvsp[(3) - (4)].value).realval;
                                        }
                                        printf("Value of the expression :: %f\n",cos(val));
                                        ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 739 "1907044.y"
    {if((yyvsp[(3) - (4)].value).type==4){
                                            printf("Compilation Error :: Cannot convert a String to Double\n");
                                            exit(-1);
                                        }
                                        double val;
                                        if((yyvsp[(3) - (4)].value).type==2){
                                            val = (yyvsp[(3) - (4)].value).intval;
                                        }else if((yyvsp[(3) - (4)].value).type==3){
                                            val = (yyvsp[(3) - (4)].value).realval;
                                        }
                                        printf("Value of the expression :: %f\n",tan(val));
                                        ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 751 "1907044.y"
    {if((yyvsp[(3) - (4)].value).type==4){
                                            printf("Compilation Error :: Cannot convert a String to Double\n");
                                            exit(-1);
                                        }
                                        double val;
                                        if((yyvsp[(3) - (4)].value).type==2){
                                            val = (yyvsp[(3) - (4)].value).intval;
                                        }else if((yyvsp[(3) - (4)].value).type==3){
                                            val = (yyvsp[(3) - (4)].value).realval;
                                        }
                                        printf("Value of the expression :: %f\n",atan(val));
                                        ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 763 "1907044.y"
    {if((yyvsp[(3) - (4)].value).type==4){
                                            printf("Compilation Error :: Cannot convert a String to Double\n");
                                            exit(-1);
                                        }
                                        double val;
                                        if((yyvsp[(3) - (4)].value).type==2){
                                            val = (yyvsp[(3) - (4)].value).intval;
                                        }else if((yyvsp[(3) - (4)].value).type==3){
                                            val = (yyvsp[(3) - (4)].value).realval;
                                        }
                                        printf("Value of the expression :: %f\n",log(val));
                                        ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 775 "1907044.y"
    {if((yyvsp[(3) - (4)].value).type==4){
                                                printf("Compilation Error :: Cannot convert a String to Double\n");
                                                exit(-1);
                                            }
                                            double val;
                                            if((yyvsp[(3) - (4)].value).type==2){
                                                val = (yyvsp[(3) - (4)].value).intval;
                                            }else if((yyvsp[(3) - (4)].value).type==3){
                                                val = (yyvsp[(3) - (4)].value).realval;
                                            }
                                            printf("Value of the expression :: %f\n",log10(val));
                                            ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 787 "1907044.y"
    {if((yyvsp[(3) - (6)].value).type==4){
                                                            printf("Compilation Error :: Cannot convert a String to Double\n");
                                                            exit(-1);
                                                        }
                                                        if((yyvsp[(5) - (6)].value).type==4){
                                                            printf("Compilation Error :: Cannot convert a String to Double\n");
                                                            exit(-1);
                                                        }
                                                        double val,p;
                                                        if((yyvsp[(3) - (6)].value).type==2){
                                                            val = (yyvsp[(3) - (6)].value).intval;
                                                        }else if((yyvsp[(3) - (6)].value).type==3){
                                                            val = (yyvsp[(3) - (6)].value).realval;
                                                        }
                                                        
                                                        if((yyvsp[(5) - (6)].value).type==2){
                                                            p = (yyvsp[(5) - (6)].value).intval;
                                                        }else if((yyvsp[(5) - (6)].value).type==3){
                                                            p = (yyvsp[(5) - (6)].value).realval;
                                                        }
                                                        printf("Value of the expression :: %f\n",pow(val,p));
                                                        ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 809 "1907044.y"
    { (yyval.value) = evaluate((yyvsp[(1) - (3)].value),(yyvsp[(3) - (3)].value),"+");;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 810 "1907044.y"
    { (yyval.value) = evaluate((yyvsp[(1) - (3)].value),(yyvsp[(3) - (3)].value),"-");;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 811 "1907044.y"
    { (yyval.value) = evaluate((yyvsp[(1) - (3)].value),(yyvsp[(3) - (3)].value),"/");;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 812 "1907044.y"
    { (yyval.value) = evaluate((yyvsp[(1) - (3)].value),(yyvsp[(3) - (3)].value),"*");;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 813 "1907044.y"
    {(yyval.value) = evaluate((yyvsp[(1) - (3)].value),(yyvsp[(3) - (3)].value),"<=");;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 814 "1907044.y"
    { (yyval.value) = evaluate((yyvsp[(1) - (3)].value),(yyvsp[(3) - (3)].value),">=");;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 815 "1907044.y"
    { (yyval.value) = evaluate((yyvsp[(1) - (3)].value),(yyvsp[(3) - (3)].value),"<");;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 816 "1907044.y"
    { (yyval.value) = evaluate((yyvsp[(1) - (3)].value),(yyvsp[(3) - (3)].value),">");;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 817 "1907044.y"
    { (yyval.value) = evaluate((yyvsp[(1) - (3)].value),(yyvsp[(3) - (3)].value),"==");;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 818 "1907044.y"
    { (yyval.value) = evaluate((yyvsp[(1) - (3)].value),(yyvsp[(3) - (3)].value),"!=");;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 819 "1907044.y"
    { (yyval.value) = (yyvsp[(2) - (3)].value);;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 822 "1907044.y"
    {
                    printf("return occured\n");
                    printf("value of the expression: ");
                    variable_type((yyvsp[(2) - (2)].value));
                ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 827 "1907044.y"
    {
                    printf("void return\n");
                ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 839 "1907044.y"
    {char *val;
                    if ((yyvsp[(3) - (3)].value).type == 2) {
                        (yyvsp[(3) - (3)].value).type = 4;
                        int n = 0;
                        int tempVal = (yyvsp[(3) - (3)].value).intval;

                        do {
                            tempVal /= 10;
                            n++;
                        } while (tempVal != 0);

                        if (n == 0) {
                            n = 1;
                        }
                        val = calloc(n + 1, sizeof(char));
                        snprintf(val, n + 1, "%ld", (yyvsp[(3) - (3)].value).intval);
                    }
                    else if ((yyvsp[(3) - (3)].value).type == 3) {
                        (yyvsp[(3) - (3)].value).type = 4;
                        val = calloc(51, sizeof(char));
                        snprintf(val, 50, "%lf", (yyvsp[(3) - (3)].value).realval);
                    }
                    else{
                        val = (yyvsp[(3) - (3)].value).strval;
                    }
                    int result = addNewVal(&head,&tail,(yyvsp[(1) - (3)].text),val);
                    if(!result)
                    {
                        printf("Compilation Error ::  Varribale %s is already declared\n",(yyvsp[(1) - (3)].text));
                        exit(-1);
                    }
                    else{
                        printf("varriable declared : %s\n",(yyvsp[(1) - (3)].text));
                    }
                ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 874 "1907044.y"
    {int temp = addNewVal(&head,&tail,(yyvsp[(1) - (1)].text),"");
                    if(!temp)
                    {
                        printf("Compilation Error ::  Varribale %s is already declared\n",(yyvsp[(1) - (1)].text));
                        exit(-1);
                    }
                ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 887 "1907044.y"
    {
                            printf("\n\nfor loop\n\n"); 
                            if((yyvsp[(11) - (12)].value).type == 2){
                                for(int i = (yyvsp[(3) - (12)].value).intval;i<(yyvsp[(6) - (12)].value).intval;i=i+(yyvsp[(8) - (12)].value).intval)
                                {
                                    printf("For iteration %d OUTPUT: %d\n",i,(yyvsp[(11) - (12)].value).intval);
                                }
                            }
                            if((yyvsp[(11) - (12)].value).type == 3){
                                for(int i = (yyvsp[(3) - (12)].value).intval;i<(yyvsp[(6) - (12)].value).intval;i=i+(yyvsp[(8) - (12)].value).intval)
                                {
                                    printf("For iteration %d OUTPUT: %lf\n",i,(yyvsp[(11) - (12)].value).realval);
                                }
                            }
                            if((yyvsp[(11) - (12)].value).type == 4){
                                for(int i = (yyvsp[(3) - (12)].value).intval;i<(yyvsp[(6) - (12)].value).intval;i=i+(yyvsp[(8) - (12)].value).intval)
                                {
                                    printf("For iteration %d OUTPUT: %s\n",i,(yyvsp[(11) - (12)].value).strval);
                                }
                            }    
                        ;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 908 "1907044.y"
    {
                            printf("\n\nfor loop\n\n"); 
                            if((yyvsp[(11) - (12)].value).type == 2){
                                for(int i = (yyvsp[(3) - (12)].value).intval;i>(yyvsp[(6) - (12)].value).intval;i=i+(yyvsp[(8) - (12)].value).intval)
                                {
                                    printf("For iteration %d OUTPUT: %d\n",i,(yyvsp[(11) - (12)].value).intval);
                                }
                            }
                            if((yyvsp[(11) - (12)].value).type == 3){
                                for(int i = (yyvsp[(3) - (12)].value).intval;i>(yyvsp[(6) - (12)].value).intval;i=i+(yyvsp[(8) - (12)].value).intval)
                                {
                                    printf("For iteration %d OUTPUT: %lf\n",i,(yyvsp[(11) - (12)].value).realval);
                                }
                            }
                            if((yyvsp[(11) - (12)].value).type == 4){
                                for(int i = (yyvsp[(3) - (12)].value).intval;i>(yyvsp[(6) - (12)].value).intval;i=i+(yyvsp[(8) - (12)].value).intval)
                                {
                                    printf("For iteration %d OUTPUT: %s\n",i,(yyvsp[(11) - (12)].value).strval);
                                }
                            }    
                        ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 929 "1907044.y"
    {
                            printf("\n\nfor loop\n\n"); 
                            if((yyvsp[(11) - (12)].value).type == 2){
                                for(int i = (yyvsp[(3) - (12)].value).intval;i<=(yyvsp[(6) - (12)].value).intval;i=i+(yyvsp[(8) - (12)].value).intval)
                                {
                                    printf("For iteration %d OUTPUT: %d\n",i,(yyvsp[(11) - (12)].value).intval);
                                }
                            }
                            if((yyvsp[(11) - (12)].value).type == 3){
                                for(int i = (yyvsp[(3) - (12)].value).intval;i<=(yyvsp[(6) - (12)].value).intval;i=i+(yyvsp[(8) - (12)].value).intval)
                                {
                                    printf("For iteration %d OUTPUT: %lf\n",i,(yyvsp[(11) - (12)].value).realval);
                                }
                            }
                            if((yyvsp[(11) - (12)].value).type == 4){
                                for(int i = (yyvsp[(3) - (12)].value).intval;i<=(yyvsp[(6) - (12)].value).intval;i=i+(yyvsp[(8) - (12)].value).intval)
                                {
                                    printf("For iteration %d OUTPUT: %s\n",i,(yyvsp[(11) - (12)].value).strval);
                                }
                            }    
                        ;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 950 "1907044.y"
    {
                            printf("\n\nfor loop\n\n"); 
                            if((yyvsp[(11) - (12)].value).type == 2){
                                for(int i = (yyvsp[(3) - (12)].value).intval;i>=(yyvsp[(6) - (12)].value).intval;i=i+(yyvsp[(8) - (12)].value).intval)
                                {
                                    printf("For iteration %d OUTPUT: %d\n",i,(yyvsp[(11) - (12)].value).intval);
                                }
                            }
                            if((yyvsp[(11) - (12)].value).type == 3){
                                for(int i = (yyvsp[(3) - (12)].value).intval;i>=(yyvsp[(6) - (12)].value).intval;i=i+(yyvsp[(8) - (12)].value).intval)
                                {
                                    printf("For iteration %d OUTPUT: %lf\n",i,(yyvsp[(11) - (12)].value).realval);
                                }
                            }
                            if((yyvsp[(11) - (12)].value).type == 4){
                                for(int i = (yyvsp[(3) - (12)].value).intval;i>=(yyvsp[(6) - (12)].value).intval;i=i+(yyvsp[(8) - (12)].value).intval)
                                {
                                    printf("For iteration %d OUTPUT: %s\n",i,(yyvsp[(11) - (12)].value).strval);
                                }
                            }    
                        ;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 973 "1907044.y"
    {
                        if((yyvsp[(3) - (8)].value).type == 2){
                            int i = (yyvsp[(3) - (8)].value).intval-1;
                            while(i){
        	                printf("While Iteration:%d output:%d\n",i,(yyvsp[(6) - (8)].value).intval);
        	                if(i == (yyvsp[(7) - (8)].value).intval)
        		                break;
                            if(i<(yyvsp[(7) - (8)].value).intval)
        	                    i = i + 1;
                            if(i>(yyvsp[(7) - (8)].value).intval)
                                i = i-1;
                            }}
                        else if((yyvsp[(3) - (8)].value).type == 3){
                            int i = (yyvsp[(3) - (8)].value).intval-1;
                            while(i){
        	                printf("While Iteration:%d output:%d\n",i,(yyvsp[(6) - (8)].value).realval);
        	                if(i == (yyvsp[(7) - (8)].value).intval)
        		                break;
                            if(i<(yyvsp[(7) - (8)].value).intval)
        	                    i = i + 1;
                            if(i>(yyvsp[(7) - (8)].value).intval)
                                i = i-1;
                            }}
                        else if((yyvsp[(3) - (8)].value).type == 4){
                            int i = (yyvsp[(3) - (8)].value).intval-1;
                            while(i){
        	                printf("While Iteration:%d output:%d\n",i,(yyvsp[(6) - (8)].value).strval);
        	                if(i == (yyvsp[(7) - (8)].value).intval)
        		                break;
                            if(i<(yyvsp[(7) - (8)].value).intval)
        	                    i = i + 1;
                            if(i>(yyvsp[(7) - (8)].value).intval)
                                i = i-1;
                            }}
                        else{
                            printf("Invalid type inside conditional loop.");
                        
                        }
                    ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 1014 "1907044.y"
    {
                        if((yyvsp[(3) - (4)].value).type == 2)
                            (yyval.value) = (yyvsp[(3) - (4)].value);
                        else
                            printf("Invalid type inside break.");
                    ;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 1022 "1907044.y"
    {
                    printf("PRINT : ")
                ;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 1027 "1907044.y"
    {
                    variable_type((yyvsp[(1) - (1)].value));
                ;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 1030 "1907044.y"
    {
                    variable_type((yyvsp[(1) - (1)].value));
                ;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 1034 "1907044.y"
    {struct identifier* res = isDeclared(&head,(yyvsp[(1) - (3)].text));
                                                            if(res==NULL)
                                                            {
                                                                printf("Compilation Error ::  Varribale %s is not declared\n",(yyvsp[(1) - (3)].text));
                                                                exit(-1);
                                                            }
                                                            else if(res->data.type == 1 || res->data.type == 6)
                                                            {
                                                                printf("Error :: You can't set a value to struct/function");
                                                                exit(-1);
                                                            }
                                                            else 
                                                            {
                                                                if((yyvsp[(3) - (3)].value).type == 2){
                                                                    int n = log10((yyvsp[(3) - (3)].value).intval) + 1;
                                                                    char *num = calloc(n, sizeof(char));
                                                                    sprintf(num,"%ld",(yyvsp[(3) - (3)].value).intval);
                                                                    setVal(&head,&tail,(yyvsp[(1) - (3)].text),num);
                                                                    printf("Value assigned :: %s = %d\n",(yyvsp[(1) - (3)].text),(yyvsp[(3) - (3)].value).intval);
                                                                }
                                                                else if((yyvsp[(3) - (3)].value).type == 3){
                                                                    char *num = calloc(51,sizeof(char));
                                                                    snprintf(num,50,"%lf",(yyvsp[(3) - (3)].value).realval);
                                                                    setVal(&head,&tail,(yyvsp[(1) - (3)].text),num);
                                                                    printf("Value assigned :: %s = %f\n",(yyvsp[(1) - (3)].text),(yyvsp[(3) - (3)].value).realval);
                                                                }
                                                                else{
                                                                    setVal(&head,&tail,(yyvsp[(1) - (3)].text),(yyvsp[(3) - (3)].value).strval);
                                                                    printf("Value assigned :: %s = %s\n",(yyvsp[(1) - (3)].text),(yyvsp[(3) - (3)].value).strval);
                                                                }
                                                            }
                                                        ;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 1066 "1907044.y"
    {struct identifier* res = isDeclared(&head,(yyvsp[(1) - (2)].text));
                                        if(res==NULL)
                                        {
                                            printf("Compilation Error ::  Varribale %s is not declared\n",(yyvsp[(1) - (2)].text));
                                            exit(-1);
                                        }
                                        else if(res->data.type == 1 || res->data.type == 6)
                                        {
                                            printf("Error :: You can't set a value to struct/function");
                                            exit(-1);
                                        }
                                        struct datatype tmp,tmp1,tmp2;
                                        if(res->data.valtype == 2){
                                            tmp = make_datatype_int(res->data.intval);
                                        } 
                                        else if(res->data.valtype == 3){
                                            tmp = make_datatype_double(res->data.realval);
                                        } 
                                        else if(res->data.valtype == 4){
                                            tmp = make_datatype_char(res->data.strval);
                                        } 
                                        else{
                                            tmp = make_datatype_int(0);
                                        } 
                                        tmp1 = make_datatype_int(1);
                                        tmp2 = evaluate(tmp,tmp1,"+");
                                        if(tmp2.type == 2){
                                            int n = log10(tmp2.intval) + 1;
                                            char *numberArray = calloc(n, sizeof(char));
                                            sprintf(numberArray,"%ld",tmp2.intval);
                                            setVal(&head,&tail,(yyvsp[(1) - (2)].text),numberArray);
                                            printf("Value assigned: %s = %d\n",(yyvsp[(1) - (2)].text),tmp2.intval);
                                        }
                                        else if(tmp2.type == 3){
                                            char *numberArray = calloc(51,sizeof(char));
                                            snprintf(numberArray,50,"%lf",tmp2.realval);
                                            setVal(&head,&tail,(yyvsp[(1) - (2)].text),numberArray);
                                            printf("Value assigned :: %s = %f\n",(yyvsp[(1) - (2)].text),tmp2.realval);
                                        }
                                        else{
                                            setVal(&head,&tail,(yyvsp[(1) - (2)].text),tmp2.strval);
                                            printf("Value assigned :: %s = %s\n",(yyvsp[(1) - (2)].text),tmp2.strval);
                                        }
                                    ;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 1110 "1907044.y"
    {struct identifier* res = isDeclared(&head,(yyvsp[(1) - (2)].text));
                                        if(res==NULL)
                                        {
                                            printf("Compilation Error ::  Varribale %s is not declared\n",(yyvsp[(1) - (2)].text));
                                            exit(-1);
                                        }
                                        else if(res->data.type == 1 || res->data.type == 6)
                                        {
                                            printf("Error :: You can't set a value to struct/function");
                                            exit(-1);
                                        }
                                        struct datatype tmp,tmp1,tmp2;
                                        if(res->data.valtype == 2){
                                            tmp = make_datatype_int(res->data.intval);
                                        } 
                                        else if(res->data.valtype == 3){
                                            tmp = make_datatype_double(res->data.realval);
                                        } 
                                        else if(res->data.valtype == 4){
                                            tmp = make_datatype_char(res->data.strval);
                                        } 
                                        else{
                                            tmp = make_datatype_int(0);
                                        } 
                                        tmp1 = make_datatype_int(1);
                                        tmp2 = evaluate(tmp,tmp1,"-");
                                        if(tmp2.type == 2){
                                            int n = log10(tmp2.intval) + 1;
                                            char *numberArray = calloc(n, sizeof(char));
                                            sprintf(numberArray,"%ld",tmp2.realval);
                                            setVal(&head,&tail,(yyvsp[(1) - (2)].text),numberArray);
                                            printf("Value assigned :: %s = %d\n",(yyvsp[(1) - (2)].text),tmp2.intval);
                                        }
                                        else if(tmp2.type == 3){
                                            char *numberArray = calloc(51,sizeof(char));
                                            snprintf(numberArray,50,"%lf",tmp2.realval);
                                            setVal(&head,&tail,(yyvsp[(1) - (2)].text),numberArray);
                                            printf("Value assigned :: %s = %f\n",(yyvsp[(1) - (2)].text),tmp2.realval);
                                        }
                                        else{
                                            setVal(&head,&tail,(yyvsp[(1) - (2)].text),tmp2.strval);
                                            printf("Value assigned :: %s = %s\n",(yyvsp[(1) - (2)].text),tmp2.strval);
                                        }
                                    ;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 1156 "1907044.y"
    {printf("\nIncluded header file: %s\n",(yyvsp[(3) - (4)].text));;}
    break;



/* Line 1455 of yacc.c  */
#line 3096 "1907044.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 1159 "1907044.y"


void yyerror(char *s)
{
    ERROR(s);
}

int main(void)
{
    freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
    yyparse();
}
