#pragma once

#include <memory>
#include <vector>

#include "card.hpp"
#include "render.hpp"

class Player {
  std::vector<std::shared_ptr<Card>> m_hand;

public:
  Player() { m_hand = {}; }

  std::vector<std::shared_ptr<Card>> getHand() { return m_hand; }

  void addCard(std::shared_ptr<Card> card) { m_hand.push_back(card); }

  void displayHand() {
    std::printf(player.c_str(), m_hand[0]->getSuit().c_str(),
                m_hand[1]->getSuit().c_str(), m_hand[0]->getFace().c_str(),
                m_hand[1]->getFace().c_str(), m_hand[0]->getSuit().c_str(),
                m_hand[1]->getSuit().c_str());
  }
};