#pragma once

#include <memory>
#include <vector>


#include "card.hpp"

class Player {
  std::vector<std::shared_ptr<Card>> m_hand;
};