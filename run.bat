@echo off
:: path
set arg1=%1
cd %arg1%
:: g++로 컴파일
g++ main.cpp -o main

:: .in 확장자를 가진 모든 파일 탐지 및 실행
for %%f in (*.in) do (
    echo res:
    main < %%f
    echo.
    echo ------------------------------------
)
cd ../