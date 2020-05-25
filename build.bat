@echo off

pushd debug
gcc -g ../src/com112_main.c ../src/com112_sort.c ../src/com112_file.c -o program.exe
popd