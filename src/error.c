#include "error.h"

void print_error(char *name, int line, int error_num) {
    switch (error_num)
    {
    case UNDEFINED_VAR:
        break;
    case UNDEFINED_FUN:
        break;
    case REDEFINED_VAR:
        break;
    case REDEFINED_FUN:
        break;
    case MISMATCHED_TYPE_ASSIGNOP:
        break;
    case MISMATCHED_TYPE_OP:
        break;
    case MISMATCHED_TYPE_PARAMETER:
        break;
    case MISMATCHED_TYPE_RETURN:
        break;
    case NONARRAY_VAR_USE_BRACKETS:
        break;
    case VAR_USE_PARENTHESES:
        break;
    case NONSTRUCT_VAR_USE_DOT:
        break;
    case ACCESS_UNDEFINED_FIELDS_IN_STRUCT:
        break;
    case REDEFINED_FIELDS_IN_STRUCT:
        break;
    case INIT_FIELDS_IN_STRUCT:
        break;
    default:
        break;
    }
}