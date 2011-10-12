/**
@file
@author James Harrison <james@talkunafraid.co.uk>
*/
#ifndef BASICPLAYER_HPP
#define BASICPLAYER_HPP
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
      @returns True if the move was successful, false if it could not be made.
      */
      bool makeMove(board *b);
  };
}
#endif