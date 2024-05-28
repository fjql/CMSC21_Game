#include "game.hpp"

#include <cstdlib>
#include <vector>
#include <xutility>

void Game::shuffleHalf() {
  std::vector<Card*> first(m_deck.begin(), m_deck.begin() + 26);
  std::vector<Card*> second(m_deck.begin() + 26, m_deck.end());
  
  m_deck.clear();

  m_deck.insert(m_deck.begin(), second.begin(), second.end());
  m_deck.insert(m_deck.end(), first.begin(), first.end());
}

void Game::shuffleOverhand() {
  std::vector<Card*> temp(m_deck.begin(), m_deck.end());

  m_deck.clear();

  int count = 0;
  while (count < 52) {
    int randn = std::rand() % 12;

    if (count + randn >= 52) {
      randn = 52 - count;
    }

    // lunch time brb
    // take chunks then place

    count += randn;
  }
}

void Game::shuffleRiffle() {
  std::vector<Card*> first(m_deck.begin(), m_deck.begin() + 26);
  std::vector<Card*> second(m_deck.begin() + 26, m_deck.end());

  m_deck.clear();

  for (int i = 0; i < 26; i++) {
    m_deck.push_back(first[i]);
    m_deck.push_back(second[i]);
  }
}