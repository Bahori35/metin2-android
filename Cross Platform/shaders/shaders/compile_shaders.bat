@echo off
REM ============================================================================
REM Shader Compilation Script for Vulkan SPIR-V
REM ============================================================================

setlocal enabledelayedexpansion

set SCRIPT_DIR=%~dp0
pushd "%SCRIPT_DIR%"

REM Set paths - using bgfx folder structure
set SHADERC=D:\development\bgfx\bgfx\.build\win32_vs2022\bin\shadercRelease.exe
set BGFX_INCLUDE=D:\development\bgfx\bgfx\src
set OUTPUT_DIR=%SCRIPT_DIR%..\bin\shaders

REM Delete old shaders first
if exist "%OUTPUT_DIR%\*.bin" del /Q "%OUTPUT_DIR%\*.bin"

REM Check if shaderc.exe exists
if not exist "%SHADERC%" (
    echo ERROR: shaderc.exe not found at %SHADERC%
    echo.
    echo Please download shaderc.exe from:
    echo https://github.com/bkaradzic/bgfx/releases/latest
    echo.
    echo Extract shaderc.exe and place it at:
    echo %CD%\..\build-external\shaderc.exe
    echo.
    pause
    exit /b 1
)

REM Create output directory if it doesn't exist
if not exist "%OUTPUT_DIR%" mkdir "%OUTPUT_DIR%"

echo ============================================================================
echo Compiling shaders for Vulkan SPIR-V
echo ============================================================================
echo.

REM Shader compilation settings for Vulkan SPIR-V
REM Note: Use 'linux' platform for Vulkan even on Windows
set PLATFORM=linux
set PROFILE=spirv
set SHADER_TYPE_VS=vertex
set SHADER_TYPE_FS=fragment
set VARYING=%SCRIPT_DIR%varying.def.sc

REM Compile vertex shaders
echo [1/8] Compiling vs_pdt.sc...
echo Command: "%SHADERC%" -f vs_pdt.sc -o "%OUTPUT_DIR%\vs_pdt.bin" --type %SHADER_TYPE_VS% --platform %PLATFORM% -p %PROFILE% -i "%BGFX_INCLUDE%" --varyingdef "%VARYING%"
"%SHADERC%" -f vs_pdt.sc -o "%OUTPUT_DIR%\vs_pdt.bin" --type %SHADER_TYPE_VS% --platform %PLATFORM% -p %PROFILE% -i "%BGFX_INCLUDE%" --varyingdef "%VARYING%" --verbose 2>&1
echo Exit code: %ERRORLEVEL%
if errorlevel 1 (
    echo FAILED: vs_pdt.sc
    pause
    exit /b 1
)
if not exist "%OUTPUT_DIR%\vs_pdt.bin" (
    echo ERROR: vs_pdt.bin was not generated!
    pause
    exit /b 1
)

echo [2/8] Compiling fs_pdt.sc...
"%SHADERC%" -f fs_pdt.sc -o "%OUTPUT_DIR%\fs_pdt.bin" --type %SHADER_TYPE_FS% --platform %PLATFORM% -p %PROFILE% -i "%BGFX_INCLUDE%"
if errorlevel 1 (
    echo FAILED: fs_pdt.sc
    pause
    exit /b 1
)
if not exist "%OUTPUT_DIR%\fs_pdt.bin" (
    echo ERROR: fs_pdt.bin was not generated!
    pause
    exit /b 1
)

echo [3/8] Compiling vs_pnt.sc...
"%SHADERC%" -f vs_pnt.sc -o "%OUTPUT_DIR%\vs_pnt.bin" --type %SHADER_TYPE_VS% --platform %PLATFORM% -p %PROFILE% -i "%BGFX_INCLUDE%" --varyingdef "%VARYING%"
if errorlevel 1 (
    echo FAILED: vs_pnt.sc
    pause
    exit /b 1
)
if not exist "%OUTPUT_DIR%\vs_pnt.bin" (
    echo ERROR: vs_pnt.bin was not generated!
    pause
    exit /b 1
)

echo [4/8] Compiling fs_pnt.sc...
"%SHADERC%" -f fs_pnt.sc -o "%OUTPUT_DIR%\fs_pnt.bin" --type %SHADER_TYPE_FS% --platform %PLATFORM% -p %PROFILE% -i "%BGFX_INCLUDE%"
if errorlevel 1 (
    echo FAILED: fs_pnt.sc
    pause
    exit /b 1
)
if not exist "%OUTPUT_DIR%\fs_pnt.bin" (
    echo ERROR: fs_pnt.bin was not generated!
    pause
    exit /b 1
)

echo [5/8] Compiling vs_pt.sc...
"%SHADERC%" -f vs_pt.sc -o "%OUTPUT_DIR%\vs_pt.bin" --type %SHADER_TYPE_VS% --platform %PLATFORM% -p %PROFILE% -i "%BGFX_INCLUDE%" --varyingdef "%VARYING%"
if errorlevel 1 (
    echo FAILED: vs_pt.sc
    pause
    exit /b 1
)
if not exist "%OUTPUT_DIR%\vs_pt.bin" (
    echo ERROR: vs_pt.bin was not generated!
    pause
    exit /b 1
)

echo [6/8] Compiling fs_pt.sc...
"%SHADERC%" -f fs_pt.sc -o "%OUTPUT_DIR%\fs_pt.bin" --type %SHADER_TYPE_FS% --platform %PLATFORM% -p %PROFILE% -i "%BGFX_INCLUDE%"
if errorlevel 1 (
    echo FAILED: fs_pt.sc
    pause
    exit /b 1
)
if not exist "%OUTPUT_DIR%\fs_pt.bin" (
    echo ERROR: fs_pt.bin was not generated!
    pause
    exit /b 1
)

echo [7/8] Compiling vs_pc.sc...
"%SHADERC%" -f vs_pc.sc -o "%OUTPUT_DIR%\vs_pc.bin" --type %SHADER_TYPE_VS% --platform %PLATFORM% -p %PROFILE% -i "%BGFX_INCLUDE%" --varyingdef "%VARYING%"
if errorlevel 1 (
    echo FAILED: vs_pc.sc
    pause
    exit /b 1
)
if not exist "%OUTPUT_DIR%\vs_pc.bin" (
    echo ERROR: vs_pc.bin was not generated!
    pause
    exit /b 1
)

echo [8/12] Compiling fs_pc.sc...
"%SHADERC%" -f fs_pc.sc -o "%OUTPUT_DIR%\fs_pc.bin" --type %SHADER_TYPE_FS% --platform %PLATFORM% -p %PROFILE% -i "%BGFX_INCLUDE%"
if errorlevel 1 (
    echo FAILED: fs_pc.sc
    pause
    exit /b 1
)
if not exist "%OUTPUT_DIR%\fs_pc.bin" (
    echo ERROR: fs_pc.bin was not generated!
    pause
    exit /b 1
)

echo [9/12] Compiling vs_pt2.sc...
"%SHADERC%" -f vs_pt2.sc -o "%OUTPUT_DIR%\vs_pt2.bin" --type %SHADER_TYPE_VS% --platform %PLATFORM% -p %PROFILE% -i "%BGFX_INCLUDE%" --varyingdef "%VARYING%"
if errorlevel 1 (
    echo FAILED: vs_pt2.sc
    pause
    exit /b 1
)
if not exist "%OUTPUT_DIR%\vs_pt2.bin" (
    echo ERROR: vs_pt2.bin was not generated!
    pause
    exit /b 1
)

echo [10/12] Compiling fs_pt2.sc...
"%SHADERC%" -f fs_pt2.sc -o "%OUTPUT_DIR%\fs_pt2.bin" --type %SHADER_TYPE_FS% --platform %PLATFORM% -p %PROFILE% -i "%BGFX_INCLUDE%"
if errorlevel 1 (
    echo FAILED: fs_pt2.sc
    pause
    exit /b 1
)
if not exist "%OUTPUT_DIR%\fs_pt2.bin" (
    echo ERROR: fs_pt2.bin was not generated!
    pause
    exit /b 1
)

echo [11/12] Compiling vs_terrain.sc...
"%SHADERC%" -f vs_terrain.sc -o "%OUTPUT_DIR%\vs_terrain.bin" --type %SHADER_TYPE_VS% --platform %PLATFORM% -p %PROFILE% -i "%BGFX_INCLUDE%" --varyingdef "%VARYING%"
if errorlevel 1 (
    echo FAILED: vs_terrain.sc
    pause
    exit /b 1
)
if not exist "%OUTPUT_DIR%\vs_terrain.bin" (
    echo ERROR: vs_terrain.bin was not generated!
    pause
    exit /b 1
)

echo [12/12] Compiling fs_terrain.sc...
"%SHADERC%" -f fs_terrain.sc -o "%OUTPUT_DIR%\fs_terrain.bin" --type %SHADER_TYPE_FS% --platform %PLATFORM% -p %PROFILE% -i "%BGFX_INCLUDE%"
if errorlevel 1 (
    echo FAILED: fs_terrain.sc
    pause
    exit /b 1
)
if not exist "%OUTPUT_DIR%\fs_terrain.bin" (
    echo ERROR: fs_terrain.bin was not generated!
    pause
    exit /b 1
)

echo.
echo ============================================================================
echo SUCCESS! All shaders compiled for Vulkan SPIR-V
echo ============================================================================
echo.
echo Output directory: %OUTPUT_DIR%
echo.
echo Compiled shaders:
dir /b "%OUTPUT_DIR%\*.bin"
echo.
popd
pause
