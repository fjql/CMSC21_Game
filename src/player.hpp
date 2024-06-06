#pragma once

#include <memory>
#include <vector>
#include <windows.h>

#include "card.hpp"
#include "render.hpp"

class Player {
  std::vector<std::shared_ptr<Card>> m_hand;
  int m_wins = 0;
  bool m_stop = false;

public:
  Player() { m_hand = {}; }

  std::vector<std::shared_ptr<Card>> getHand() { return m_hand; }

  void resetDeck() { m_hand.clear(); }

  int getWins() { return m_wins; }

  void addWin() { m_wins++; }

  bool isStopped() { return m_stop; }

  void toggleStop() { m_stop = !m_stop; }

  void addCard(std::shared_ptr<Card> card) {
    PlaySound("audio/hit.wav", NULL, SND_ASYNC | SND_FILENAME);
    m_hand.push_back(card);
  }

  void displayHand() {
    if (m_hand.size() == 2) {
      std::printf(player.c_str(), m_hand[0]->getSuit().c_str(),
                  m_hand[1]->getSuit().c_str(), m_hand[0]->getFace().c_str(),
                  m_hand[1]->getFace().c_str(), m_hand[0]->getSuit().c_str(),
                  m_hand[1]->getSuit().c_str());
    } else if (m_hand.size() == 3) {
      std::printf(player_hit.c_str(), m_hand[0]->getSuit().c_str(),
                  m_hand[1]->getSuit().c_str(), m_hand[2]->getSuit().c_str(),
                  m_hand[0]->getFace().c_str(), m_hand[1]->getFace().c_str(),
                  m_hand[2]->getFace().c_str(), m_hand[0]->getSuit().c_str(),
                  m_hand[1]->getSuit().c_str(), m_hand[2]->getSuit().c_str());
    } else {
      std::printf(player_hit2.c_str(), m_hand[0]->getSuit().c_str(),
                  m_hand[1]->getSuit().c_str(), m_hand[2]->getSuit().c_str(),
                  m_hand[3]->getSuit().c_str(), m_hand[0]->getFace().c_str(),
                  m_hand[1]->getFace().c_str(), m_hand[2]->getFace().c_str(),
                  m_hand[3]->getFace().c_str(), m_hand[0]->getSuit().c_str(),
                  m_hand[1]->getSuit().c_str(), m_hand[2]->getSuit().c_str(),
                  m_hand[3]->getSuit().c_str());
    }
  }

  int getVals() {
    // sum the values, if the value is 0 then check if adding 11 exceeds 21 if it does then just add 1

    int val = 0;
    for (auto card : m_hand) {
      if (card->getValue() == 0) {
        continue;
      }
      val += card->getValue();
    }

    for (auto card : m_hand) {
      if (card->getValue() == 0) {
        if (val + 11 > 21) {
          val += 1;
        } else {
          val += 11;
        }
      }
    }

    return val;
  }
};