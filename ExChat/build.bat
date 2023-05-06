del build\*.exe
g++ src\chat.cpp -o build\chat.exe -Wall -O2
g++ src\send.cpp -o build\send.exe -Wall -O2
@echo off
echo.
echo Build complete!
echo.
pause
cls