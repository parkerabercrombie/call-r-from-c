#!/bin/bash

# Launch script for the call R from C example program.

export R_HOME=/Library/Frameworks/R.framework/Resources
export LD_LIBRARY_PATH=$R_HOME/lib

./r_test
