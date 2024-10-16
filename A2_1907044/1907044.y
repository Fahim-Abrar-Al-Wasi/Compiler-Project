%{
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
%}

%code requires {
    #ifndef CHECK
    #define CHECK
    struct CHECK datatype {
        int type;
        char *strval;
        int intval;
        double realval;
    };
    #endif
}

%union {
    char text[1000];
    struct datatype value;
}

%start program
%token<text> HEADER_FILE
%token<text> VARIABLE
%token<value> NUMBER
%token<value> STR
%token<text> VARIABLE_ACCESS
%type<value>expression
%type<value>condition
%token HEADER INTEGER FLOAT STRING VOID ALLOCATION RETURN PRINT STRUCT FUNC BREAK
%token FOR WHILE IF ELSE_IF ELSE SWITCH CASE DEFAULT 
%token ADD INC DEC SUB MUL DIV LE_OP GE_OP EQ_OP NE_OP
%token ASIN SIN COS ACOS TAN ATAN LOG10 LOG POW
%left ALLOCATION
%left ADD SUB
%left MUL DIV
%left INC DEC

%%

program         : {printf("\nSuccessfully Executed\n");}
                |include program
                |declare program
                |stmt program
                |struct program
                |function program
                ;

struct          :STRUCT VARIABLE '{' stmt '}' {int temp=addStructToSymTable(&head,&tail,$2,"");
                                                        if(!temp)
                                                        {
                                                            printf("\nError: %s is already declared.\n",$2);
                                                            exit(-1);
                                                        }   
                                                        else{
                                                            printf("struct successfully declared\n");
                                                        }                     

                                                      }
                ;

function        :   type FUNC VARIABLE '(' func_para ')' '{' stmt '}' {char *val;
                                                                                int n=log10(currentType)+1;
                                                                                val=calloc(n+1,sizeof(char));
                                                                                snprintf(val,n,"%ld",currentType);
                                                                                int res=addFuncToSymTable(&head,&tail,$3,val);
                                                                                if(!res){
                                                                                    printf("Compilation error: %s already declared\n",$3);
                                                                                }
                                                                                else{
                                                                                    printf("function successfully declared: %s\n",$3);
                                                                                }
                                                                            } 
                ;

type            : INTEGER { currentType = 1; }
                | FLOAT { currentType = 2; }
                | STRING { currentType = 3; }
                | VOID { currentType = 4; }
                | VARIABLE { setTypeFromVariable($1); }
                ;

func_para       :   
                |type VARIABLE func_para
                |',' type VARIABLE func_para
                ;

stmt            :   
                | if stmt
                | declare stmt
                | assign stmt
                | return stmt
                | expression stmt
                | switch stmt
                | for stmt
                | while stmt
                | display stmt
                ;   

switch          :SWITCH '(' expression ')'  {
                        switchCasedata = $3;
                        printf("\n\nSwitch case \n");
                    } '{' casegrammer '}'
                ;
casegrammer     : CASE  expression ':'  stmt {
                    if(caseflag == 0 && evaluate($2,switchCasedata,"==").intval == 1){
                        caseflag = 1;
                        printf("\nCase executed : %d\n",$2.intval);
                    }
                } casegrammer
                | DEFAULT ':' stmt  {if(caseflag == 0){
                                            printf("\nDefualt executed\n");
                                        }
                                    }
                ;             

if              : IF '(' expression ')' '{' stmt '}' {
                        ifptr++;
                        if(boolvalue($3)){
                            printf("\n\nIF Block executed\n");
                            ifdone[ifptr]=1;
                        }
                    } elsifgrmr {
                        ifptr--;
                    }
                ;

elsifgrmr       :
                | ELSE_IF '(' expression ')' '{' stmt '}' {
                    if(ifdone[ifptr]==0 && boolvalue($3)){
                      ifdone[ifptr]=1;
                      printf("ELSE IF Block executed\n");
                    }
                } elsifgrmr
                | ELSE '{' stmt '}' {
                    if(ifdone[ifptr]==0){
                        printf("ELSE Block executed\n\n");
                    }
                }
                ;

expression      :NUMBER {$$=$1;
                        if($1.type == 2){
                            printf("\nInt value is %d\n",$1.intval);
                        }
                        else if($1.type == 3){
                            printf("\nFloat value is %lf\n",$1.realval);
                        }}
                |STR {$$=$1;
                        if($1.type == 4){
                            printf("\nString value is %s\n",$1.strval);
                        }}
                | VARIABLE_ACCESS {struct identifier* res = isDeclared(&head,$1);
                                        if(res==NULL){
                                            printf("Compilation Error:  Varribale %s is not declared\n",$1);
                                            exit(-1);
                                        }
                                        else if(res->data.type == 1 || res->data.type == 6){
                                            printf("Error: You can't set a value to struct/function");
                                            exit(-1);
                                        }
                                        else {
                                            if(res->data.type==2){
                                                $$ = make_datatype_int(res->data.intval);}
                                            else if(res->data.type==3){
                                                $$ = make_datatype_double(res->data.realval);}
                                            else if(res->data.type==4){
                                                $$ = make_datatype_char(res->data.strval);
                                            }
                                            if($$.type==2){
                                                printf("Int value is %d\n", $$.intval);
                                            }
                                            else if ($$.type==3){
                                                printf("Float value is %lf\n",$$.realval);
                                            }
                                            else if($$.type==4){
                                                printf("String value is %s\n",$$.strval);
                                            }
                                        }
                                    }
                | SIN '(' expression ')' {if($3.type==4){
                                            printf("Compilation Error: Cannot convert a String to Double\n");
                                            exit(-1);
                                            }
                                        double val;
                                        if($3.type==2){
                                            val = $3.intval;
                                        }else if($3.type==3){
                                            val = $3.realval;
                                        }
                                        printf("Value of the expression: %f\n",sin(val));
                                        }
                | ASIN '(' expression ')' {if($3.type==4){
                                            printf("Compilation Error: Cannot convert a String to Double\n");
                                            exit(-1);
                                        }
                                        double val;
                                        if($3.type==2){
                                            val = $3.intval;
                                        }else if($3.type==3){
                                            val = $3.realval;
                                        }
                                        printf("Value of the expression :: %f\n",asin(val));
                                        }
                | ACOS '(' expression ')' {if($3.type==4){
                                            printf("Compilation Error :: Cannot convert a String to Double\n");
                                            exit(-1);
                                        }
                                        double val;
                                        if($3.type==2){
                                            val = $3.intval;
                                        }else if($3.type==3){
                                            val = $3.realval;
                                        }
                                        printf("Value of the expression :: %f\n",acos(val));
                                        }
                | COS '(' expression ')' {if($3.type==4){
                                            printf("Compilation Error :: Cannot convert a String to Double\n");
                                            exit(-1);
                                        }
                                        double val;
                                        if($3.type==2){
                                            val = $3.intval;
                                        }else if($3.type==3){
                                            val = $3.realval;
                                        }
                                        printf("Value of the expression :: %f\n",cos(val));
                                        }
                | TAN '(' expression ')' {if($3.type==4){
                                            printf("Compilation Error :: Cannot convert a String to Double\n");
                                            exit(-1);
                                        }
                                        double val;
                                        if($3.type==2){
                                            val = $3.intval;
                                        }else if($3.type==3){
                                            val = $3.realval;
                                        }
                                        printf("Value of the expression :: %f\n",tan(val));
                                        }
                | ATAN '(' expression ')' {if($3.type==4){
                                            printf("Compilation Error :: Cannot convert a String to Double\n");
                                            exit(-1);
                                        }
                                        double val;
                                        if($3.type==2){
                                            val = $3.intval;
                                        }else if($3.type==3){
                                            val = $3.realval;
                                        }
                                        printf("Value of the expression :: %f\n",atan(val));
                                        }
                | LOG '(' expression ')' {if($3.type==4){
                                            printf("Compilation Error :: Cannot convert a String to Double\n");
                                            exit(-1);
                                        }
                                        double val;
                                        if($3.type==2){
                                            val = $3.intval;
                                        }else if($3.type==3){
                                            val = $3.realval;
                                        }
                                        printf("Value of the expression :: %f\n",log(val));
                                        }
                | LOG10 '(' expression ')' {if($3.type==4){
                                                printf("Compilation Error :: Cannot convert a String to Double\n");
                                                exit(-1);
                                            }
                                            double val;
                                            if($3.type==2){
                                                val = $3.intval;
                                            }else if($3.type==3){
                                                val = $3.realval;
                                            }
                                            printf("Value of the expression :: %f\n",log10(val));
                                            }
                | POW '(' expression ',' expression ')'  {if($3.type==4){
                                                            printf("Compilation Error :: Cannot convert a String to Double\n");
                                                            exit(-1);
                                                        }
                                                        if($5.type==4){
                                                            printf("Compilation Error :: Cannot convert a String to Double\n");
                                                            exit(-1);
                                                        }
                                                        double val,p;
                                                        if($3.type==2){
                                                            val = $3.intval;
                                                        }else if($3.type==3){
                                                            val = $3.realval;
                                                        }
                                                        
                                                        if($5.type==2){
                                                            p = $5.intval;
                                                        }else if($5.type==3){
                                                            p = $5.realval;
                                                        }
                                                        printf("Value of the expression :: %f\n",pow(val,p));
                                                        }
                | expression ADD expression { $$ = evaluate($1,$3,"+");}
                | expression SUB expression { $$ = evaluate($1,$3,"-");}
                | expression DIV expression { $$ = evaluate($1,$3,"/");}
                | expression MUL expression { $$ = evaluate($1,$3,"*");}
                | expression LE_OP expression {$$ = evaluate($1,$3,"<=");}
                | expression GE_OP expression { $$ = evaluate($1,$3,">=");}
                | expression '<' expression { $$ = evaluate($1,$3,"<");}
                | expression '>' expression { $$ = evaluate($1,$3,">");}
                | expression EQ_OP expression { $$ = evaluate($1,$3,"==");}
                | expression NE_OP expression { $$ = evaluate($1,$3,"!=");}
                | '(' expression ')' { $$ = $2;}
                ;

return          : RETURN expression {
                    printf("return occured\n");
                    printf("value of the expression: ");
                    variable_type($2);
                }
                | RETURN {
                    printf("void return\n");
                }
                ;

declare         :type variables
                ;

variables       : variable ',' variables
                | variable
                ;

variable        : VARIABLE ALLOCATION expression {char *val;
                    if ($3.type == 2) {
                        $3.type = 4;
                        int n = 0;
                        int tempVal = $3.intval;

                        do {
                            tempVal /= 10;
                            n++;
                        } while (tempVal != 0);

                        if (n == 0) {
                            n = 1;
                        }
                        val = calloc(n + 1, sizeof(char));
                        snprintf(val, n + 1, "%ld", $3.intval);
                    }
                    else if ($3.type == 3) {
                        $3.type = 4;
                        val = calloc(51, sizeof(char));
                        snprintf(val, 50, "%lf", $3.realval);
                    }
                    else{
                        val = $3.strval;
                    }
                    int result = addNewVal(&head,&tail,$1,val);
                    if(!result)
                    {
                        printf("Compilation Error ::  Varribale %s is already declared\n",$1);
                        exit(-1);
                    }
                    else{
                        printf("varriable declared : %s\n",$1);
                    }
                }
                | VARIABLE {int temp = addNewVal(&head,&tail,$1,"");
                    if(!temp)
                    {
                        printf("Compilation Error ::  Varribale %s is already declared\n",$1);
                        exit(-1);
                    }
                }
                ;

assign          : varassign ',' assign
                | varassign 
                ;

for             : FOR '(' expression ':' '<' expression ':' expression ')' '{' expression '}' {
                            printf("\n\nfor loop\n\n"); 
                            if($11.type == 2){
                                for(int i = $3.intval;i<$6.intval;i=i+$8.intval)
                                {
                                    printf("For iteration %d OUTPUT: %d\n",i,$11.intval);
                                }
                            }
                            if($11.type == 3){
                                for(int i = $3.intval;i<$6.intval;i=i+$8.intval)
                                {
                                    printf("For iteration %d OUTPUT: %lf\n",i,$11.realval);
                                }
                            }
                            if($11.type == 4){
                                for(int i = $3.intval;i<$6.intval;i=i+$8.intval)
                                {
                                    printf("For iteration %d OUTPUT: %s\n",i,$11.strval);
                                }
                            }    
                        }
                | FOR '(' expression ':' '>' expression ':' expression ')' '{' expression '}' {
                            printf("\n\nfor loop\n\n"); 
                            if($11.type == 2){
                                for(int i = $3.intval;i>$6.intval;i=i+$8.intval)
                                {
                                    printf("For iteration %d OUTPUT: %d\n",i,$11.intval);
                                }
                            }
                            if($11.type == 3){
                                for(int i = $3.intval;i>$6.intval;i=i+$8.intval)
                                {
                                    printf("For iteration %d OUTPUT: %lf\n",i,$11.realval);
                                }
                            }
                            if($11.type == 4){
                                for(int i = $3.intval;i>$6.intval;i=i+$8.intval)
                                {
                                    printf("For iteration %d OUTPUT: %s\n",i,$11.strval);
                                }
                            }    
                        }
                | FOR '(' expression ':' LE_OP expression ':' expression ')' '{' expression '}' {
                            printf("\n\nfor loop\n\n"); 
                            if($11.type == 2){
                                for(int i = $3.intval;i<=$6.intval;i=i+$8.intval)
                                {
                                    printf("For iteration %d OUTPUT: %d\n",i,$11.intval);
                                }
                            }
                            if($11.type == 3){
                                for(int i = $3.intval;i<=$6.intval;i=i+$8.intval)
                                {
                                    printf("For iteration %d OUTPUT: %lf\n",i,$11.realval);
                                }
                            }
                            if($11.type == 4){
                                for(int i = $3.intval;i<=$6.intval;i=i+$8.intval)
                                {
                                    printf("For iteration %d OUTPUT: %s\n",i,$11.strval);
                                }
                            }    
                        }
                | FOR '(' expression ':' GE_OP expression ':' expression ')' '{' expression '}' {
                            printf("\n\nfor loop\n\n"); 
                            if($11.type == 2){
                                for(int i = $3.intval;i>=$6.intval;i=i+$8.intval)
                                {
                                    printf("For iteration %d OUTPUT: %d\n",i,$11.intval);
                                }
                            }
                            if($11.type == 3){
                                for(int i = $3.intval;i>=$6.intval;i=i+$8.intval)
                                {
                                    printf("For iteration %d OUTPUT: %lf\n",i,$11.realval);
                                }
                            }
                            if($11.type == 4){
                                for(int i = $3.intval;i>=$6.intval;i=i+$8.intval)
                                {
                                    printf("For iteration %d OUTPUT: %s\n",i,$11.strval);
                                }
                            }    
                        }
                ;

while           : WHILE '(' expression ')' '{' expression condition '}' {
                        if($3.type == 2){
                            int i = $3.intval-1;
                            while(i){
        	                printf("While Iteration:%d output:%d\n",i,$6.intval);
        	                if(i == $7.intval)
        		                break;
                            if(i<$7.intval)
        	                    i = i + 1;
                            if(i>$7.intval)
                                i = i-1;
                            }}
                        else if($3.type == 3){
                            int i = $3.intval-1;
                            while(i){
        	                printf("While Iteration:%d output:%d\n",i,$6.realval);
        	                if(i == $7.intval)
        		                break;
                            if(i<$7.intval)
        	                    i = i + 1;
                            if(i>$7.intval)
                                i = i-1;
                            }}
                        else if($3.type == 4){
                            int i = $3.intval-1;
                            while(i){
        	                printf("While Iteration:%d output:%d\n",i,$6.strval);
        	                if(i == $7.intval)
        		                break;
                            if(i<$7.intval)
        	                    i = i + 1;
                            if(i>$7.intval)
                                i = i-1;
                            }}
                        else{
                            printf("Invalid type inside conditional loop.");
                        
                        }
                    }
                ;

condition       : BREAK '(' expression ')' {
                        if($3.type == 2)
                            $$ = $3;
                        else
                            printf("Invalid type inside break.");
                    } 
                ;

display         : PRINT '(' {
                    printf("PRINT : ")
                } mul_exp ')'
                ;

mul_exp         : expression {
                    variable_type($1);
                } ',' mul_exp
                | expression {
                    variable_type($1);
                }

varassign       : VARIABLE_ACCESS ALLOCATION expression {struct identifier* res = isDeclared(&head,$1);
                                                            if(res==NULL)
                                                            {
                                                                printf("Compilation Error ::  Varribale %s is not declared\n",$1);
                                                                exit(-1);
                                                            }
                                                            else if(res->data.type == 1 || res->data.type == 6)
                                                            {
                                                                printf("Error :: You can't set a value to struct/function");
                                                                exit(-1);
                                                            }
                                                            else 
                                                            {
                                                                if($3.type == 2){
                                                                    int n = log10($3.intval) + 1;
                                                                    char *num = calloc(n, sizeof(char));
                                                                    sprintf(num,"%ld",$3.intval);
                                                                    setVal(&head,&tail,$1,num);
                                                                    printf("Value assigned :: %s = %d\n",$1,$3.intval);
                                                                }
                                                                else if($3.type == 3){
                                                                    char *num = calloc(51,sizeof(char));
                                                                    snprintf(num,50,"%lf",$3.realval);
                                                                    setVal(&head,&tail,$1,num);
                                                                    printf("Value assigned :: %s = %f\n",$1,$3.realval);
                                                                }
                                                                else{
                                                                    setVal(&head,&tail,$1,$3.strval);
                                                                    printf("Value assigned :: %s = %s\n",$1,$3.strval);
                                                                }
                                                            }
                                                        }
                | VARIABLE_ACCESS INC {struct identifier* res = isDeclared(&head,$1);
                                        if(res==NULL)
                                        {
                                            printf("Compilation Error ::  Varribale %s is not declared\n",$1);
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
                                            setVal(&head,&tail,$1,numberArray);
                                            printf("Value assigned: %s = %d\n",$1,tmp2.intval);
                                        }
                                        else if(tmp2.type == 3){
                                            char *numberArray = calloc(51,sizeof(char));
                                            snprintf(numberArray,50,"%lf",tmp2.realval);
                                            setVal(&head,&tail,$1,numberArray);
                                            printf("Value assigned :: %s = %f\n",$1,tmp2.realval);
                                        }
                                        else{
                                            setVal(&head,&tail,$1,tmp2.strval);
                                            printf("Value assigned :: %s = %s\n",$1,tmp2.strval);
                                        }
                                    }
                | VARIABLE_ACCESS DEC {struct identifier* res = isDeclared(&head,$1);
                                        if(res==NULL)
                                        {
                                            printf("Compilation Error ::  Varribale %s is not declared\n",$1);
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
                                            setVal(&head,&tail,$1,numberArray);
                                            printf("Value assigned :: %s = %d\n",$1,tmp2.intval);
                                        }
                                        else if(tmp2.type == 3){
                                            char *numberArray = calloc(51,sizeof(char));
                                            snprintf(numberArray,50,"%lf",tmp2.realval);
                                            setVal(&head,&tail,$1,numberArray);
                                            printf("Value assigned :: %s = %f\n",$1,tmp2.realval);
                                        }
                                        else{
                                            setVal(&head,&tail,$1,tmp2.strval);
                                            printf("Value assigned :: %s = %s\n",$1,tmp2.strval);
                                        }
                                    }
                ;

include         : HEADER '<' HEADER_FILE '>' {printf("\nIncluded header file: %s\n",$3);}
                ;
        
%%

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