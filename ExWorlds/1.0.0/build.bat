@echo off
if exist build\ExWorlds.exe (
del build\ExWorlds.exe
)
g++ src\*.cpp -o build\ExWorlds.exe -Wall -O2 -L X:\Dev\ExCpp -L C:\Dev\raylib -L C:\Dev\JsonCpp -lraylib -lopengl32 -lgdi32 -lwinmm -ljsoncpp
IF %ERRORLEVEL% NEQ 0 (
echo Build failed!
pause
) else (
echo Build completed!
pause
)