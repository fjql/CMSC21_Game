#pragma once

#include <print>
#include <vector>

#include "card.hpp"

class Game {
  std::vector<Card*> m_deck;

  void generateDeck() {
    for (int i = 0; i < 4; i++) {
      m_deck.push_back(new Card(0, Suit(i), ACE));
      m_deck.push_back(new Card(10, Suit(i), JACK));
      m_deck.push_back(new Card(10, Suit(i), KING));
      m_deck.push_back(new Card(10, Suit(i), QUEEN));

      for (int j = 1; j < 10; j++)
        m_deck.push_back(new Card(j + 1, Suit(i), NUMBER));
    }
  }

  public:

  Game() {
    generateDeck();
  }

  ~Game() {
  }
};