#!/bin/bash

function style-format {
    find . -name '*.h' -or -name '*.c' -or -name '*.cpp' -or -name '*.cc' | xargs clang-format -i -style=Google && echo "Style format ended"
}

function compile {
    clang *.c  -o $1.exe && echo "$1 compiled"
}

function run {
    ./$1.exe
}