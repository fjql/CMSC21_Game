#include <print>

#include "game.hpp"

int main (void) {
    Game game{};

    game.displayDeck();

    game.shuffleDeck(4);
    
    game.displayDeck();

    return 0;
}