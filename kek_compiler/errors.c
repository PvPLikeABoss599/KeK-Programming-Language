#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "../kek_compiler/errors.h"

void err_kill_self(Error *e)
{
    printf("test");
    printf("%s", msg);
    exit(0);
}

Errors *Build_Error(Errors *e)
{
    e->add_error = __adderr;
    e->die = err_n_die;
}

void __adderr(Error *e, char *err_file, int err_line, char *err_message)
{

}

