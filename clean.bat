@echo off
setlocal enabledelayedexpansion

for /r %%d in (.) do (
    for %%f in ("%%~fd\*.exe") do (
        echo [FOUND] %%~f

        del /f /q "%%~f" >nul 2>&1
        if exist "%%~f" (
            echo [ERROR] Failed to delete: %%~f
        ) else (
            echo [DELETED] %%~f
        )
    )
)

echo [DONE] All .exe files have been processed.
pause
