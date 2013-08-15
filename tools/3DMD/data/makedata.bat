@echo off
REM =================================
REM ======= GENERATE UI FILE ========
REM =================================
%QTDIR%\5.1.0\msvc2012\bin\uic.exe -o "..\src\generated\ui_mainwindow.h" ".\forms\mainwindow.ui"