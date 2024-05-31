#pragma once

#include <vector>
#include <memory>

#include "card.hpp"

class Player {
  std::vector<std::shared_ptr<Card>> m_hand;
};