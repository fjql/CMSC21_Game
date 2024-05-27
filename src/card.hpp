#pragma once

#include <string>

typedef enum {
  CLUBS = 0,
  DIAMONDS = 1,
  HEARTS = 2,
  SPADES = 3
} Suit;

typedef enum {
  ACE,
  JACK,
  KING,
  QUEEN,
  NUMBER
} Face;

class Card {
  int m_value = 0;
  Suit m_suit;
  Face m_face;

  public:

  Card(int val, Suit suit, Face face) : m_value(val), m_suit(suit), m_face(face) { }
  
  int getValue() {
    return m_value;
  }

  std::string getSuit() {
    switch (m_suit) {
      case CLUBS:
        return "Clubs";
      case DIAMONDS:
        return "Diamonds";
      case HEARTS:
        return "Hearts";
      case SPADES:
        return "Spades";
      default:
        return "HUH?!?!";
      }
  }

  std::string getFace() {
    switch (m_face) {
    case ACE:
      return "Ace";
    case JACK:
      return "Jack";
    case KING:
      return "King";
    case QUEEN:
      return "Queen";
    case NUMBER:
      return std::to_string(m_value);
    }
  }
};