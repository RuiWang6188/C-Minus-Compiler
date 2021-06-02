#include "error.h"

void print_error(char *name, int line, int error_num) {
    switch (error_num)
    {
    case UNDEFINED_VAR:
        printf("Error at Line %d: Undefined variable \"%s\"\n", line, name);
        break;
    case UNDEFINED_FUN:
        printf("Error at Line %d: Undefined function \"%s\"\n", line, name);
        break;
    case REDEFINED_VAR:
        printf("Error at Line %d: Redefined variable \"%s\"\n", line, name);
        break;
    case REDEFINED_FUN:
        printf("Error at Line %d: Redefined function \"%s\"\n", line, name);
        break;
    case MISMATCHED_TYPE_ASSIGNOP:
        printf("Error at Line %d: Different types on two sides of \"%s\"\n", line, name);
        break;
    case MISMATCHED_TYPE_OP:
        printf("Error at Line %d: Wrong types of \"%s\"\n", line, name);
        break;
    case MISMATCHED_TYPE_PARAMETER:
        printf("Error at Line %d: Wrong types of parameter \"%s\"\n", line, name);
        break;
    case MISMATCHED_TYPE_RETURN:
        printf("Error at Line %d: Wrong types of return \"%s\"\n", line, name);
        break;
    case NONARRAY_VAR_USE_BRACKETS:
        printf("Error at Line %d: Wrong usage of \"[]\" at \"%s\"\n", line, name);
        break;
    case VAR_USE_PARENTHESES:
        printf("Error at Line %d: \"%s\" can't use {} \n", line, name);
        break;
    case NONSTRUCT_VAR_USE_DOT:
        printf("Error at Line %d: \"%s\" can't use . \n", line, name);
        break;
    case ACCESS_UNDEFINED_FIELDS_IN_STRUCT:
        printf("Error at Line %d: \"%s\" is undefined in struct \n", line, name);
        break;
    case REDEFINED_FIELDS_IN_STRUCT:
        printf("Error at Line %d: \"%s\" is redefined in struct \n", line, name);
        break;
    case INIT_FIELDS_IN_STRUCT:
        printf("Error at Line %d: \"%s\" can't be initialized in struct \n", line, name);
        break;
    default:
        break;
    }
}