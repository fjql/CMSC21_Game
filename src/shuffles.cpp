#include "game.hpp"

#include <algorithm>
#include <cstdlib>
#include <memory>
#include <random>
#include <vector>

void Game::shuffleHalf() {
  std::vector<std::shared_ptr<Card>> first(m_deck.begin(), m_deck.begin() + 26);
  std::vector<std::shared_ptr<Card>> second(m_deck.begin() + 26, m_deck.end());

  m_deck.clear();

  m_deck.insert(m_deck.begin(), second.begin(), second.end());
  m_deck.insert(m_deck.end(), first.begin(), first.end());
}

void Game::shuffleOverhand() {
  std::vector<std::shared_ptr<Card>> temp(m_deck.begin(), m_deck.end());

  m_deck.clear();

  int count = 0;
  while (count < 52) {
    int randn = std::rand() % 12;

    if (count + randn >= 52) {
      randn = 52 - count;
    }

    m_deck.reserve(m_deck.size() + randn);
    m_deck.insert(m_deck.begin(), temp.begin() + count,
                  temp.begin() + count + randn);

    count += randn;
  }
}

void Game::shuffleRiffle() {
  std::vector<std::shared_ptr<Card>> first(m_deck.begin(), m_deck.begin() + 26);
  std::vector<std::shared_ptr<Card>> second(m_deck.begin() + 26, m_deck.end());

  m_deck.clear();

  for (int i = 0; i < 26; i++) {
    m_deck.push_back(first[i]);
    m_deck.push_back(second[i]);
  }
}

void Game::shuffleTheresAnActualShuffleFunctionWow() {
  // So it turns out this thing exists, I'm keeping the other stuff anyway
  // because sunk cost fallacy.

  std::default_random_engine rng{};
  std::shuffle(m_deck.begin(), m_deck.end(), rng);
}