if (-not (Test-Path -Path "bin")) {
    New-Item -Path . -Name "bin" -ItemType "directory"
    Write-Output "Created bin folder"
}

$compiler = "clang++"
if ($Args -contains "g++") {
    $compiler = "g++"
}

if ((Get-Command "clang++.exe") -or (Get-Command "g++.exe")) {
    & $compiler ./src/*.cpp -o ./bin/Game.exe -std=c++2b -Wall -Wextra -O1

    if ($Args -contains "run") {
        bin/Game.exe
    }
} else {
    Write-Host "Can't find compiler." -ForegroundColor Red
    Return
}