if (-not (Test-Path -Path "bin")) {
    New-Item -Path . -Name "bin" -ItemType "directory"
    Write-Output "Created bin folder"
}

$compiler = "clang++"

if (($Args -contains "g++") -or (-not (Get-Command "clang.exe"))) {
    Write-Host "Can't find clang++." -ForegroundColor Red
    $compiler = "g++"
}

if (-not (Get-Command "g++.exe")) {
    Write-Host "Can't find g++." -ForegroundColor Red
    Return
}

& $compiler ./src/*.cpp -o ./bin/Game.exe -std=c++2b -Wall -Wextra -O1 -lwinmm

if ($Args -contains "run") {
    bin/Game.exe
}