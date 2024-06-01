#if defined(_WIN32)
#include <windows.h>
#include <winnls.h>
#endif

#include <print>

#include "game.hpp"

int main(void) {
#if defined(_WIN32)
  SetConsoleOutputCP(CP_UTF8);
#endif

  Game game{};

  return 0;
}