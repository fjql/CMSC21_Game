#pragma once

#include <memory>
#include <vector>
#include <windows.h>

#include "card.hpp"
#include "render.hpp"

class Player {
  std::vector<std::shared_ptr<Card>> m_hand;
  int m_wins = 0;

public:
  Player() { m_hand = {}; }

  std::vector<std::shared_ptr<Card>> getHand() { return m_hand; }

  int getWins() { return m_wins; }

  void addWin() { m_wins++; }
  
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
    int val = 0;
    for (auto card : m_hand) {
      val += card->getValue();
    }
    return val;
  }
};