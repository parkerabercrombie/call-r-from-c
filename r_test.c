/**
 * Example of how to call an R function from C using an embdeed R
 * environment.
 *
 * Author: Parker Abercrombie <parker@pabercrombie.com>
 */

#include <stdio.h>
#include <string.h>

#include <Rinternals.h>
#include <Rembedded.h>

/**
 * Invokes the command source("foo.R").
 */
void source(const char *name)
{
    SEXP e;

    PROTECT(e = lang2(install("source"), mkString(name)));
    R_tryEval(e, R_GlobalEnv, NULL);
    UNPROTECT(1);
}

/**
 * Wrapper for R function add1, defined in func.R.
 */
void R_add1(int alen, int a[])
{
    // Allocate an R vector and copy the C array into it.
    SEXP arg;
    PROTECT(arg = allocVector(INTSXP, alen));
    memcpy(INTEGER(arg), a, alen * sizeof(int));

    // Setup a call to the R function
    SEXP add1_call;
    PROTECT(add1_call = lang2(install("add1"), arg));

    // Execute the function
    int errorOccurred;
    SEXP ret = R_tryEval(add1_call, R_GlobalEnv, &errorOccurred);

    if (!errorOccurred)
    {
        printf("R returned: ");
        double *val = REAL(ret);
        for (int i = 0; i < LENGTH(ret); i++)
            printf("%0.1f, ", val[i]);
        printf("\n");
    }
    else
    {
        printf("Error occurred calling R\n");
    }
    
    UNPROTECT(2);
}

int main(int argc, char *argv[])
{
    // Intialize the R environment.
    int r_argc = 2;
    char *r_argv[] = { "R", "--silent" };
    Rf_initEmbeddedR(r_argc, r_argv);
    
    int arg[] = { 1, 2, 3, 4, 5 };

    // Invoke a function in R
    source("func.R");
    R_add1(5, arg);

    // Release R environment
    Rf_endEmbeddedR(0);
    return(0);
}
