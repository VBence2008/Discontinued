@echo off
title ExDOS
:start
cls
echo ExDOS 1.0.0
echo 2021 - Veress Bence Gyula
echo.
echo ExDOS started as %USERNAME%
echo.
goto live
:livecls
cls
goto live
:live
set /p cmd=">"
if %cmd%==clear goto clear else goto error
if %cmd%==color goto color else goto error
if %cmd%==exit exit else goto error
if %cmd%==goto goto gotocd else goto error
if %cmd%==help goto cmd-help else goto error
if %cmd%==ls goto ls else goto error
if %cmd%==lsb goto lsb else goto error
if %cmd%==ls0 goto ls0 else goto error
if %cmd%==lsp goto lsp else goto error
if %cmd%==lspb goto lspb else goto error
if %cmd%==lsp0 goto lsp0 else goto error
if %cmd%==restart goto start else goto error
:error
echo Error
goto live
:clear
cls
goto live
:cmd-help
echo.
echo Commands:
echo.
echo    clear (Clear the screen)
echo    color [0-9, A-F] (Set the display text color)
echo    exit (Close ExDOS)
echo    goto (Change directory)
echo    help (List of commands)
echo    ls (List directory content)
echo    lsb (List directory content with auto pause)
echo    ls0 (Write the list of files and folders to a text file)
echo    lsp (List directory content with full path and all subfolders)
echo    lspb (List directory content with full path and all subfolders with auto pause)
echo    lsp0 (Write the list of files and folders with full path to a text file)
echo    restart (Restart ExDOS)
echo.
goto live
:ls
echo.
echo Files and folders in this directory:
echo.
dir /b
echo.
goto live
:lsb
echo.
echo Files and folders in this directory:
echo.
dir /b /p
echo.
goto live
:ls0
echo.
echo Writing list to file...
dir /b > exdos_ls0-list.txt
echo Completed! exdos_ls0-list.txt can be found in the directory.
echo.
goto live
:lsp
echo.
echo All files and (sub)folders in this directory with full path:
echo.
dir /b /s
echo.
goto live
:lspb
echo.
echo All files and (sub)folders in this directory with full path:
echo.
dir /b /s /p
echo.
goto live
:lsp0
echo.
echo Writing list to file...
dir /b /s > exdos_lsp0-list.txt
echo Completed! exdos_lsp0-list.txt can be found in the directory.
echo.
goto live
:color
echo.
echo Enter a DOS color code!
echo First digit = Background color
echo Second digit = Text color
echo.
echo 0	=	Black	 	8	=	Gray
echo 1	=	Blue	 	9	=	Light Blue
echo 2	=	Green	 	A	=	Light Green
echo 3	=	Aqua	 	B	=	Light Aqua
echo 4	=	Red	 	C	=	Light Red
echo 5	=	Purple	 	D	=	Light Purple
echo 6	=	Yellow	 	E	=	Light Yellow
echo 7	=	White	 	F	=	Bright White
echo.
set /p CC= Color code: 
color %CC%
echo.
goto live
:gotocd
set /p GOTO=Directory name: 
cd %GOTO%
goto live