#include "game.hpp"
#include "render.hpp"

#if defined(_WIN32)
#include <conio.h>
#endif

void Game::loop() {
  render();
  while (m_state != END) {
#if defined(_WIN32)
    char input = _getch();
#endif

    if (input == 27) {
      m_state = END;
    }

    update();
    render();
  }
}

void Game::shuffleDeck(int times) {
  for (int i = 0; i < times; i++) {
    int random = std::rand() % 4;

    if (random == 0)
      shuffleHalf();
    else if (random == 1)
      shuffleRiffle();
    else if (random == 2)
      shuffleOverhand();
    else
      shuffleTheresAnActualShuffleFunctionWow();
  }
}

void Game::update() {}

void Game::render() {
  std::system("clear");
  if (m_state == START) {
    std::printf("%s\n%s\n%s\n", separator.c_str(), start.c_str(), separator.c_str());
  }
}