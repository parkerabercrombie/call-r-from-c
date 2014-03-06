#######################################################
# Makefile for embedded R example.
#
# Author: Parker Abercrombie <parker@pabercrombie.com>
#######################################################

R_BASE = /usr/local/IT/R-2.15.3/lib64/R

CC = gcc
CFLAGS = -g -I$(R_BASE)/include
LFLAGS = -L$(R_BASE)/lib -lR -lRblas

r_test: r_test.c
	$(CC) -o $@ $(CFLAGS) $(LFLAGS) $^
