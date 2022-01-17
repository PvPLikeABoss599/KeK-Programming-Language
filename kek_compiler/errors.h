#pragma once

// this file is for

// all kek language errors

// and their processor :)

typedef struct Error_t {// used to print the errors
    char        error_file[64];
    int         error_line;
    char        *error_message;
} Error;

typedef struct Errors_t {// collection of the errors
    Error       **errors;
    void        *(*add_error)(Error *, char *, int, char *);
    void        *(*die)(Error *);
} Errors;

void err_kill_self(Error *);
Errors *Build_Error(Errors *);
void __adderr(Error *, char *, int, char *);
