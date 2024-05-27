#include "game.hpp"

#include <vector>
#include <xutility>

void Game::shuffleHalf() {
  std::vector<Card*> first(m_deck.begin(), m_deck.begin() + 26);
  std::vector<Card*> second(m_deck.begin() + 26, m_deck.end());
  
  m_deck.clear();

  m_deck.insert(m_deck.begin(), second.begin(), second.end());
  m_deck.insert(m_deck.end(), first.begin(), first.end());
}

void Game::shuffleRiffle() {
}