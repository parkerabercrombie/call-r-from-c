#######################################################
# Makefile for embedded R example.
#
# Author: Parker Abercrombie <parker@pabercrombie.com>
#######################################################

R_BASE = /Library/Frameworks/R.framework/Resources

CFLAGS = -g -I$(R_BASE)/include
LFLAGS = -L$(R_BASE)/lib -lR -lRblas

r_test: r_test.c
	$(CC) -o $@ $(CFLAGS) $(LFLAGS) $^
