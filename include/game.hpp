/**
@file
@author James Harrison <james@talkunafraid.co.uk>
*/
#ifndef GAME_HPP
#define GAME_HPP
#include "board.hpp"
#include "basicplayer.hpp"
#include "move.hpp"
namespace gone {
  /// The game class represents a game and two playerss, and contains basic game logic.
  class game {
    board* game_board;
    basicPlayer* black_player;
    basicPlayer* white_player;
    move* first_move;
  public:
    /**
    Create a new game.
    */
    game();
    ~game();
    /**
    Run a simple game.
    @returns The winner of the game- white is true, false is black.
    */
    bool run();
    /**
    Print the game's current board state to standard output.
    */
    void printBoard();
  };
}
#endif