#pragma once

#include <print>
#include <vector>
#include <cstdlib>
#include <ctime>

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

  void shuffleHalf();
  void shuffleOverhand();
  void shuffleRiffle();
  void shuffleTheresAnActualShuffleFunctionWow();

  public:

  Game() {
    std::srand(std::time(nullptr));

    generateDeck();
  }

  ~Game() {
    for (Card* card : m_deck) {
      card->~Card();
    }
    m_deck.clear();
    m_deck.shrink_to_fit();
  }

  void displayDeck() {
    int i = 0;
    for (Card* card : m_deck) {
      std::printf("%d\t %s of %s (%d)\n", i, card->getFace().c_str(), card->getSuit().c_str(), card->getValue());
      i++;
    }
    std::printf("\n");
  }

  void shuffleDeck(int times);
};