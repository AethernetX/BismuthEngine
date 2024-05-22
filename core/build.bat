if not exist bin mkdir bin


cd bin

:: find a way to infer from the .env.cmake file so we know if user wants to use either makefiles, solution files e.t.c
:: in the meantime just do the arguments yourself
cmake -S ../ -B . -G "MinGW Makefiles"

mingw32-make

cd ..

pause
