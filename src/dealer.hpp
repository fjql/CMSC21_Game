#pragma once

#include <memory>
#include <vector>

#include "card.hpp"
#include "render.hpp"

class Dealer {
  std::vector<std::shared_ptr<Card>> m_hand;

public:
  Dealer() { m_hand = {}; }

  std::shared_ptr<Card> getCard() { return m_hand[0]; }

  void addCard(std::shared_ptr<Card> card) { m_hand.push_back(card); }

  void displayHand() {
    std::printf(dealer.c_str(), m_hand[0]->getSuit().c_str(),
                m_hand[0]->getFace().c_str(), m_hand[0]->getSuit().c_str());
  }
};