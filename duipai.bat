@echo off

.\MinGW64\bin\g++.exe .\pre\code_1.cpp -o .\pre\code_1.exe
.\MinGW64\bin\g++.exe .\pre\code_2.cpp -o .\pre\code_2.exe

:loop
    if %1 == 0 goto py
    if %1 == 1 goto cpp
    .\pre\code_1 < tmp.in > .\file\code_1.out
    .\pre\code_2 < tmp.in > .\file\code_2.out
:py
    .\Python\python.exe %2 
    REM > %~dp0tmp.in
    REM echo %2  %~dp0tmp.in

:cpp
    %2 > %~dp0tmp.in