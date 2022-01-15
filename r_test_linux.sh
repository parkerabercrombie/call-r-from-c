#!/bin/bash

# Launch script for the call R from C example program.

export R_HOME=/usr/lib/R
export LD_LIBRARY_PATH=$R_HOME/lib

./r_test
