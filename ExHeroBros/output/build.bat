cd G:\Dev\ExHeroBros\output
del ExHeroBros.exe /q
del ExHeroBros.py
del G:\Dev\ExHeroBros\output\__pycache__\*.* /q
rmdir G:\Dev\ExHeroBros\output\__pycache__ /q
del G:\Dev\ExHeroBros\output\build\ExHeroBros\*.* /q
rmdir G:\Dev\ExHeroBros\output\build\ExHeroBros /q
rmdir G:\Dev\ExHeroBros\output\build /q
del ExHeroBros.spec /q
rmdir G:\Dev\ExHeroBros\output\dist /q
copy G:\Dev\ExHeroBros\code\ExHeroBros.py G:\Dev\ExHeroBros\output
pyinstaller --noconfirm --onefile --console --icon "G:/Dev/ExHeroBros/external/icon.ico" --upx-dir "G:/Dev/ExHeroBros/external/upx-3.96-win64"  "G:/Dev/ExHeroBros/output/ExHeroBros.py"
del ExHeroBros.py
del G:\Dev\ExHeroBros\output\__pycache__\*.* /q
rmdir G:\Dev\ExHeroBros\output\__pycache__ /q
del G:\Dev\ExHeroBros\output\build\ExHeroBros\*.* /q
rmdir G:\Dev\ExHeroBros\output\build\ExHeroBros /q
rmdir G:\Dev\ExHeroBros\output\build /q
del ExHeroBros.spec /q
move G:\Dev\ExHeroBros\output\dist\ExHeroBros.exe G:\Dev\ExHeroBros\output
rmdir G:\Dev\ExHeroBros\output\dist /q
pause