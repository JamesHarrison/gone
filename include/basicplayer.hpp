/**
@file
@author James Harrison <james@talkunafraid.co.uk>
*/
#ifndef BASICPLAYER_HPP
#define BASICPLAYER_HPP
#include "move.hpp"
namespace gone {
  /// The basicPlayer class represents a Go solver.
  class basicPlayer {
    bool colour;
    public:
      /**
      Sets up a new player.
      @param c The player's colour
      */
      basicPlayer(bool c);
      ~basicPlayer();
      /**
      Have the player make a move on the given board.
      @param b A pointer to the board to be used.
      @param last_move A pointer to the last move made, used to construct the new move
      @returns A pointer to the move the player wants to make, or NULL.
      */
      move *makeMove(board *b, move *last_move);
  };
}
#endif