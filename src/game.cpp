#include "game.hpp"
#include "screens.hpp"

#include <cstdlib>

void Game::loop() {
  //while (m_state != END) {
    update();
    render();
  //}
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
    //std::fputs(start.c_str(), stdout);
    std::printf("%s\n", start.c_str());
  }
}