#!/bin/bash
# Nama output program
OUT="main"

# Kumpulkan semua file .c di direktori ini
SRC_FILES=$(ls *.c)

# Kompilasi dengan flag ketat
gcc -Wall -Wextra -Wpedantic -Wconversion -Werror -std=c11 -o "$OUT" $SRC_FILES

