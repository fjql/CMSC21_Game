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
  m_player->resetDeck();
  m_dealer->resetDeck();

  for (int i = 0; i < 2; i++) {
    m_dealer->addCard(m_deck.back());
    m_deck.pop_back();
    m_deck.shrink_to_fit();
    
    if (m_player->isStopped()) {
      m_player->addCard(m_deck.back());
      m_deck.pop_back();
      m_deck.shrink_to_fit();
    }
  }

  if (m_player->isStopped()) {
    return;
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

void Game::checkWin() {
  if (m_player->getVals() == 21) {
    m_player->addWin();
    msg = win;
  }

  if (m_player->getVals() > 21) {
    m_dealer->addWin();
    msg = bust;
    m_player->toggleStop();
  }

  if (m_player->isStopped()) {
    if (m_player->getVals() > m_dealer->getVals() && m_player->getVals() <= 21) {
      m_player->addWin();
      msg = win;
    } else {
      m_dealer->addWin();
      msg = bust;
    }
  }
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
      generateDeck(1);

      shuffleDeck(6);

      deal();

      m_started = true;
    }

    if (input == 49) {
      if (m_player->isStopped()) {
        return;
      }

      if (m_player->getHand().size() == 4) {
        msg = "No more hits because it will ruin the UI, sorry.\n";
        return;
      }

      m_player->addCard(m_deck.back());
      m_deck.pop_back();
      m_deck.shrink_to_fit();

      checkWin();
    }

    if (input == 50) {
      if (m_player->isStopped()) {
        deal();

        m_player->toggleStop();

        msg = "";
      }

      // if there were multiple players, this would skip a turn
      // but since i don't have time for that let's just use this to move
      // forward
    }

    if (input == 51) {
      if (m_player->isStopped()) {
        return;
      }

      m_player->toggleStop();
      checkWin();
    }
  }
}

void Game::render() {
  std::system("cls");
  if (m_state == START) {
    std::printf("%s\n%s\n%s\n%s\n%s\n", separator.c_str(), start.c_str(),
                separator.c_str(), start_options.c_str(), separator.c_str());
  }

  if (m_state == PLAYING) {
    std::printf("%s\n", separator.c_str());

    std::printf("Dealer: %d\n", m_dealer->getWins());

    if (m_player->isStopped()) {
      m_dealer->revealHand();
    } else {
      m_dealer->displayHand();
    }

    std::printf("You: %d\n", m_player->getWins());

    m_player->displayHand();

    std::printf("%s\n", separator.c_str());

    std::printf(play_options.c_str(), msg.c_str());

    std::printf("%s\n", separator.c_str());
  }

  if (m_state == END) {
    std::printf("Thanks for playing!");
  }
}