#!/bin/bash
# Define color escape sequences
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
BLUE='\033[0;34m'
NC='\033[0m' # Reset color escape sequence

workDir=.
for dir in "$workDir"/*; do
    if [ -d "$dir" ]; then
        printf "${GREEN}Make in $dir\n${NC}"
        make -C $dir
    fi
done
printf "${GREEN}Compile all done.\n${NC}"
