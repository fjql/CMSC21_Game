#pragma once

#include <memory>
#include <vector>

#include "card.hpp"
#include "render.hpp"

class Player {
  std::vector<std::shared_ptr<Card>> m_hand;
  int m_wins = 0;
  bool m_hit = false;

public:
  Player() { m_hand = {}; }

  std::vector<std::shared_ptr<Card>> getHand() { return m_hand; }

  void addCard(std::shared_ptr<Card> card) { m_hand.push_back(card); }

  bool getHit() { return m_hit; }
  void hit() { m_hit = true; }

  void displayHand() {
    if (m_hit) {
      if (m_hand.size() == 3) {
        std::printf(player_hit.c_str(), m_hand[0]->getSuit().c_str(),
                    m_hand[1]->getSuit().c_str(), m_hand[2]->getSuit().c_str(),
                    m_hand[0]->getFace().c_str(), m_hand[1]->getFace().c_str(),
                    m_hand[2]->getFace().c_str(), m_hand[0]->getSuit().c_str(),
                    m_hand[1]->getSuit().c_str(), m_hand[2]->getSuit().c_str());
      } else if (m_hand.size() == 4) {
        std::printf(player_hit2.c_str(), m_hand[0]->getSuit().c_str(),
                    m_hand[1]->getSuit().c_str(), m_hand[2]->getSuit().c_str(),
                    m_hand[3]->getSuit().c_str(), m_hand[0]->getFace().c_str(),
                    m_hand[1]->getFace().c_str(), m_hand[2]->getFace().c_str(),
                    m_hand[3]->getFace().c_str(), m_hand[0]->getSuit().c_str(),
                    m_hand[1]->getSuit().c_str(), m_hand[2]->getSuit().c_str(),
                    m_hand[3]->getSuit().c_str());
      } else {
        std::printf(player_hit3.c_str(), m_hand[0]->getSuit().c_str(),
                    m_hand[1]->getSuit().c_str(), m_hand[2]->getSuit().c_str(),
                    m_hand[3]->getSuit().c_str(), m_hand[4]->getSuit().c_str(),
                    m_hand[0]->getFace().c_str(), m_hand[1]->getFace().c_str(),
                    m_hand[2]->getFace().c_str(), m_hand[3]->getFace().c_str(),
                    m_hand[4]->getFace().c_str(), m_hand[0]->getSuit().c_str(),
                    m_hand[1]->getSuit().c_str(), m_hand[2]->getSuit().c_str(),
                    m_hand[3]->getSuit().c_str(), m_hand[4]->getSuit().c_str());
      }
    } else {
      std::printf(player.c_str(), m_hand[0]->getSuit().c_str(),
                  m_hand[1]->getSuit().c_str(), m_hand[0]->getFace().c_str(),
                  m_hand[1]->getFace().c_str(), m_hand[0]->getSuit().c_str(),
                  m_hand[1]->getSuit().c_str());
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