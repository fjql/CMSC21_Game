#pragma once

#include <vector>
#include <memory>

#include "card.hpp"

class Dealer {
  std::vector<std::shared_ptr<Card>> m_hand;
};