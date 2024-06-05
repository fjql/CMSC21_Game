#pragma once

#include <cstdlib>
#include <ctime>
#include <memory>
#include <print>
#include <vector>
#include <windows.h>

#include "card.hpp"
#include "dealer.hpp"
#include "player.hpp"

typedef enum { START = 0, PLAYING = 1, END = 2 } GameState;

class Game {
  std::vector<std::shared_ptr<Card>> m_deck;
  GameState m_state = START;
  std::shared_ptr<Dealer> m_dealer;
  std::shared_ptr<Player> m_player;
  bool m_started = false;

  void generateDeck(int decks) {
    m_deck = {};

    for (int k = 0; k < decks; k++) {
      for (int i = 0; i < 4; i++) {
        m_deck.push_back(std::make_shared<Card>(0, Suit(i), ACE));
        m_deck.push_back(std::make_shared<Card>(10, Suit(i), JACK));
        m_deck.push_back(std::make_shared<Card>(10, Suit(i), KING));
        m_deck.push_back(std::make_shared<Card>(10, Suit(i), QUEEN));

        for (int j = 1; j < 10; j++)
          m_deck.push_back(std::make_shared<Card>(j + 1, Suit(i), NUMBER));
      }
    }
  }

  void shuffleHalf();
  void shuffleOverhand();
  void shuffleRiffle();
  void shuffleTheresAnActualShuffleFunctionWow();

public:
  std::string msg = "";

  Game() {
    std::srand(std::time(nullptr));

    m_dealer = std::make_shared<Dealer>();
    m_player = std::make_shared<Player>();

    PlaySound("audio/extra.wav", NULL, SND_ASYNC | SND_LOOP | SND_FILENAME);
  }

  ~Game() {
    for (auto card : m_deck) {
      card->~Card();
    }
    m_deck.clear();
    m_deck.shrink_to_fit();

    m_dealer->~Dealer();
    m_player->~Player();
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
  void deal();
  void addDealer();
  void addPlayer();

  void checkWin();

  void update(char input);
  void render();

  void loop();
};