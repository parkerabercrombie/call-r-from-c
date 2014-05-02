call-r-from-c
=============

Author: Parker Abercrombie

Small example of how to call into R code from C. This example creates
an array in C, calls a function in R that adds one to each element of
the array, and then prints the results from C.

To compile and run the example:
% make
% ./r_test.sh

Note that you may need to adjust the path to the R header and library
files in Makefile and r_test.sh to suit your system.

The R function is defined in func.R, and code to call this function
from C is in r_test.c.
