rem   *** validation ***
call scripts\run-validator-tests.bat
call scripts\run-checker-tests.bat

rem    *** tests ***
md tests
call scripts\gen-input-via-stdout.bat "files\gen.exe 1000 15" "tests\01" 1
call scripts\gen-input-via-stdout.bat "files\gen.exe 1000 300" "tests\02" 2
call scripts\gen-input-via-stdout.bat "files\gen.exe 999 300" "tests\03" 3
call scripts\gen-input-via-stdout.bat "files\gen.exe 994 3000" "tests\04" 4
call scripts\gen-input-via-stdout.bat "files\gen.exe 995 3000" "tests\05" 5
call scripts\gen-input-via-stdout.bat "files\gen.exe 996 3000" "tests\06" 6
call scripts\gen-input-via-stdout.bat "files\gen.exe 997 3000" "tests\07" 7
call scripts\gen-input-via-stdout.bat "files\gen.exe 998 3000" "tests\08" 8
call scripts\gen-input-via-stdout.bat "files\gen.exe 999 3000" "tests\09" 9
call scripts\gen-input-via-stdout.bat "files\gen.exe 1000 3000" "tests\10" 10
call scripts\gen-answer.bat tests\01 tests\01.a "tests" ""
call scripts\gen-answer.bat tests\02 tests\02.a "tests" ""
call scripts\gen-answer.bat tests\03 tests\03.a "tests" ""
call scripts\gen-answer.bat tests\04 tests\04.a "tests" ""
call scripts\gen-answer.bat tests\05 tests\05.a "tests" ""
call scripts\gen-answer.bat tests\06 tests\06.a "tests" ""
call scripts\gen-answer.bat tests\07 tests\07.a "tests" ""
call scripts\gen-answer.bat tests\08 tests\08.a "tests" ""
call scripts\gen-answer.bat tests\09 tests\09.a "tests" ""
call scripts\gen-answer.bat tests\10 tests\10.a "tests" ""

