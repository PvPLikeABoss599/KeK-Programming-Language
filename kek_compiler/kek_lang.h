#pragma once

// what i see here is about wrong... it will work

// try moving to a .c and leaving function definitions here to know that functoin exists in the same .c as .h

#include "../kek_compiler/errors.h"

// a line inside the kek source file
typedef struct Line_Checker_t 
{
    void *idk;// dude what the fuck do i put here
} LinesCheck;
typedef struct  Line_Checker_t CurrentLine;

// a function inside the kek source file
typedef struct FunctionChecker_t 
{
    char        fnc_name[64];       // add this to defines #define ILANG_FUNC_NAME_SIZE_MAX 64
    
    int         fnc_args_count;     // function paramater count
    int         fnc_returns_count;  // function return variables count
    int         fnc_variables_count;// function variable count

    char        **fnc_args;         // argument names
    char        **fnc_returns;      // return names
    char        **fnc_variables;    // variable names
    
    LinesCheck  **fnc_all_lines;    // all the lines that got parsed
    CurrentLine *fnc_check_line;    // current line to parse
} Function;
typedef struct FunctionChecker_t FncChecker;

// list all functions parsed from .ksf (kek source file)
typedef struct ExternalFunctions_t
{
    char        **functions;
    char        **variables;
    char        **classes;
} ExternalFnc;

// single builtin function
struct kek_internal_function_t 
{
    char name[64];
    char **parameters;
    char **returns;
    void *ptr;
};

// all builtin fucks for the language syntax and code
typedef struct BuiltinStuff_t 
{
    struct kek_internal_function_t **functions;     // fucktion pointers to my internal librarys for the stub
    char                           **variables;
    char                           **classes;
} Builtins;

// the entire shits to manage my damn code
typedef struct KeKLang_t 
{
    // for identification of program
    char        main_file[64];      // again add ILANG_MAIN_FILE_NAME_SIZE_MAX 64
    Function    main_function;
    char        **main_imports;     // may not use this and determine the imports on parse
    
    // from parsing the code.. (init fnc_check; run the line_check; add to extfnc)
    FncChecker  *fnc_check;         // function parser
    CurrentLine *line_check;        // current parsed line
    ExternalFnc *extfnc;            // stub functions
    
    // utilited
    Builtins    *builtin;           // builtin functions
    Errors      *err;               // errors.......

    // compile this hoe
    void        *(*operate)(struct KeKLang_t *, char *);
} KeKLang;

// the damn compile and initialize this bitch
void __operate(KeKLang *, char *);    // compile the keks
KeKLang Build_KeKLang(KeKLang *);         // initalize the whole damn shit
