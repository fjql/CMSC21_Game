#pragma once

#include <memory>
#include <vector>

#include "card.hpp"
#include "render.hpp"

class Dealer {
  std::vector<std::shared_ptr<Card>> m_hand;
  int m_wins = 0;

public:
  Dealer() { m_hand = {}; }

  void resetDeck() { m_hand.clear(); }

  std::shared_ptr<Card> getCard() { return m_hand[0]; }

  void addCard(std::shared_ptr<Card> card) { m_hand.push_back(card); }

  int getWins() { return m_wins; }

  void addWin() { m_wins++; }

  void displayHand() {
    std::printf(dealer.c_str(), m_hand[0]->getSuit().c_str(),
                m_hand[0]->getFace().c_str(), m_hand[0]->getSuit().c_str());
  }

  void revealHand() {
    std::printf(player.c_str(), m_hand[0]->getSuit().c_str(),
                m_hand[1]->getSuit().c_str(), m_hand[0]->getFace().c_str(),
                m_hand[1]->getFace().c_str(), m_hand[0]->getSuit().c_str(),
                m_hand[1]->getSuit().c_str());
  }

  int getVals() {
    int val = 0;
    for (auto card : m_hand) {
      val += card->getValue();
    }
    return val;
  }
};