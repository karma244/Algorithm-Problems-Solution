@echo off
:: path
set arg1=%1
cd %arg1%
:: g++로 컴파일
g++ main.cpp -o main && main