#include "game.hpp"

void Game::gameLoop() {
  while (m_state != END) {
    if (m_state == START) {
      updateStart();
      renderStart();
    } else if (m_state == PLAYING) {
      updatePlaying();
      renderPlaying();
    }
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