#include "ERROR.h"
#include <stdio.h>

char* last_erreur=NULL;
void ERROR(char* err)
{
    last_erreur=err;
}

char* ERROR_get()
{
    return last_erreur;
}