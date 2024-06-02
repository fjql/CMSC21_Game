#pragma once

#include <memory>
#include <vector>

#include "card.hpp"

class Player {
  std::vector<std::shared_ptr<Card>> m_hand;

public:
  Player() { m_hand = {}; }

  std::vector<std::shared_ptr<Card>> getHand() { return m_hand; }

  void addCard(std::shared_ptr<Card> card) { m_hand.push_back(card); }

  void displayHand() {
    int count = 1;
    for (auto card : m_hand) {
      std::printf("%d: %s %s, ", count, card->getFace().c_str(), card->getSuit().c_str());
      count++;
    }
    std::printf("\n");
  }
};