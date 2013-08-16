@echo off
REM =================================
REM ======= FOLDER STURCTURE ========
REM =================================
set DATA_FOLDER="..\data"
set SRC_FOLDER="..\src"

REM =================================
REM ====== GENERATE UI HEADER =======
REM =================================
%QTDIR%\5.1.0\msvc2012\bin\uic.exe -o "%SRC_FOLDER%\generated\ui_mainwindow.h" "%DATA_FOLDER%\forms\mainwindow.ui"

REM =================================
REM ===== GENERATE moc_* FILE =======
REM =================================
%QTDIR%\5.1.0\msvc2012\bin\moc.exe "%SRC_FOLDER%\mainwindow.h" -o "%SRC_FOLDER%\generated\moc_mainwindow.cpp"