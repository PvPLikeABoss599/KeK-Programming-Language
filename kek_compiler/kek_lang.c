#include <stdio.h>
#include <stdlib.h>

#include "../kek_compiler/kek_lang.h"
#include "../kek_compiler/errors.h"
#include "../kek_library/kek_lib.h"

KeKLang Build_iLang(KeKLang *i)
{
    util_zero(i->main_file, 64);
    i->main_function = malloc(sizeof(Function));
    //i->main_imports = NULL;
    
    i->line_check = NULL;//parser not started this is absent so NULL <stddef.h> or <stdio.h>
    i->fnc_check = NULL;//we aint gonna start yet or i will throw you all in the KEK CAN
    i->extfnc = NULL;//this is about the first thing to even initialize on parse... realloc()
    
    i->builtin = malloc(sizeof(Builtins));
    i->err = malloc(sizeof(Errors));
    
    i->operate = &__operate;
}

void __operate(KeKLang *i, char *file) 
{

}
