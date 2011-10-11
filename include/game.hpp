#ifndef GAME_HPP
#define GAME_HPP
#include "board.hpp"
#include "basicplayer.hpp"
namespace gone {
  class game {
    board* game_board;
    basicPlayer* black_player;
    basicPlayer* white_player;
  public:
    game();
    ~game();
    bool run();
    void printBoard();
  };
}
#endif