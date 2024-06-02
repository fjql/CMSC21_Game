#pragma once

#include <memory>
#include <vector>


#include "card.hpp"

class Dealer {
  std::vector<std::shared_ptr<Card>> m_hand;
};