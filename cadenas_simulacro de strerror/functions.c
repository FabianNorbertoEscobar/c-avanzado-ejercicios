#include "header.h"
char *str_error(int errnum)
    {
    static char msg_error[40];
    sprintf(msg_error,"%.*s\n",sizeof(msg_error)-2,errnum>=0&&errnum<sys_nerr?sys_errlist[errnum]:"Unknown error");
    return msg_error;
    }

