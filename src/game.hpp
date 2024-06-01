#pragma once

#include <cstdlib>
#include <ctime>
#include <memory>
#include <print>
#include <vector>

#include "card.hpp"

typedef enum { START = 0, PLAYING = 1, END = 2 } GameState;

class Game {
  std::vector<std::shared_ptr<Card>> m_deck;
  GameState m_state = START;

  void generateDeck() {
    m_deck = {};

    for (int i = 0; i < 4; i++) {
      m_deck.push_back(std::make_shared<Card>(0, Suit(i), ACE));
      m_deck.push_back(std::make_shared<Card>(10, Suit(i), JACK));
      m_deck.push_back(std::make_shared<Card>(10, Suit(i), KING));
      m_deck.push_back(std::make_shared<Card>(10, Suit(i), QUEEN));

      for (int j = 1; j < 10; j++)
        m_deck.push_back(std::make_shared<Card>(j + 1, Suit(i), NUMBER));
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

    shuffleDeck(6);
  }

  ~Game() {
    for (auto card : m_deck) {
      card->~Card();
    }
    m_deck.clear();
    m_deck.shrink_to_fit();
  }

  GameState getState() { return m_state; }

  void displayDeck() {
    int i = 0;
    for (auto card : m_deck) {
      std::printf("%d\t %s %s (%d)\n", i, card->getSuit().c_str(),
                  card->getFace().c_str(), card->getValue());
      i++;
    }
    std::printf("\n");
  }

  void shuffleDeck(int times);

  void update();
  void render();

  void loop();
};