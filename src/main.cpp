#include <print>
#include <windows.h>
#include <winnls.h>


#include "game.hpp"

int main(void) {
  SetConsoleOutputCP(CP_UTF8);

  Game game{};

  game.loop();

  game.~Game();

  return 0;
}