#include <conio.h>

#include "game.hpp"
#include "render.hpp"

void Game::loop() {
  render();
  while (m_state != END) {
    char input = _getch();

    if (input == 27) {
      m_state = END;
    }

    update(input);
    render();
  }
}

void Game::shuffleDeck(int times) {
  PlaySound("audio/shuffle.wav", NULL, SND_SYNC | SND_FILENAME);
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

void Game::deal() {
  for (int i = 0; i < 2; i++) {
    m_dealer->addCard(m_deck.back());
    m_deck.pop_back();
    m_deck.shrink_to_fit();
  }

    m_player->addCard(m_deck.back());
    m_deck.pop_back();
    m_deck.shrink_to_fit();
}

void Game::addPlayer() {
  m_player->addCard(m_deck.back());
  m_deck.pop_back();
  m_deck.shrink_to_fit();
}

void Game::update(char input) {
  if (m_state == START) {
    if (input == 49) {
      m_state = PLAYING;
    }

    if (input == 50) {
      m_state = END;
    }
  }

  if (m_state == PLAYING) {
    if (!m_started) {
      generateDeck();

      shuffleDeck(6);

      deal();

      m_started = true;
    }

    if (input == 49) {
      if (m_player->getHand().size() == 4) {
        msg = "No more hits because it will ruin the UI, sorry.\n";
        return;
      }

      m_player->addCard(m_deck.back());
      m_deck.pop_back();
      m_deck.shrink_to_fit();

      if (m_player->getVals() == 21){
        checkWin();
      } else if (m_player->getVals() > 21) {
        // lose
      }
    }
  }
}

void Game::render() {
  std::system("clear");
  if (m_state == START) {
    std::printf("%s\n%s\n%s\n%s\n%s\n", separator.c_str(), start.c_str(),
                separator.c_str(), start_options.c_str(), separator.c_str());
  }

  if (m_state == PLAYING) {
    std::printf("%s\n", separator.c_str());

    std::print("Dealer: \n");

    m_dealer->displayHand();

    std::print("You: \n");

    m_player->displayHand();

    std::printf("%s\n", separator.c_str());

    std::printf(play_options.c_str(), msg.c_str());

    std::printf("%s\n", separator.c_str());
  }

  if (m_state == END) {
    std::printf("Thanks for playing!");
  }
}