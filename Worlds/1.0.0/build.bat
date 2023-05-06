@echo off
if exist build\Worlds.exe (
del build\Worlds.exe
)
g++ src\*.cpp -o build\Worlds.exe -Wall -O2 -L X:\Dev\ExCpp -L C:\Dev\raylib -L C:\Dev\JsonCpp -lraylib -lopengl32 -lgdi32 -lwinmm -ljsoncpp
IF %ERRORLEVEL% NEQ 0 (
echo Build failed!
pause
) else (
echo Build completed!
pause
)