@echo off
setlocal enabledelayedexpansion

for /F %%a in ('echo prompt $E ^| cmd') do set "ESC=%%a"

gcc main.c -o main.exe
if errorlevel 1 (
    echo !ESC![31m Erro na compilação.!ESC![0m
    exit /b
)

set /a passed=0
set /a failed=0

for /d %%d in (gabaritos\2024f1pj_concurso\*) do (
    echo Pasta: %%~nxd
    for %%f in (%%d\*.in) do (
        set "filename=%%~nf"
        set "input_file=%%f"
        set "expected_output=%%d\!filename!.sol"
        set "output_file=%%d\!filename!.out"

        echo Testando: !filename!.in

        main.exe < "!input_file!" > "!output_file!"
        fc "!output_file!" "!expected_output!" > nul
        if errorlevel 1 (
            echo !ESC![31m Teste !filename! falhou.!ESC![0m
            set /a failed+=1
        ) else (
            echo !ESC![32m Teste !filename! passou.!ESC![0m
            set /a passed+=1
        )
        echo -----------------------------
    )
)

echo !ESC![36mResumo: %passed% passaram, %failed% falharam.!ESC![0m
pause
