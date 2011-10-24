/**
@file
@author James Harrison <james@talkunafraid.co.uk>
*/
#ifndef MOVE_HPP
#define MOVE_HPP
#include "board.hpp"
namespace gone {
  /// The move class represents a move by a player in the list of moves 
  class move {
    // The depth of this move in the tree
    short int depth;
    // Position this move chose
    unsigned char position;
    // Next move in the or NULL if this is the 'current' (ie last played) move
    move* next;
    // The move that came before this one.
    move* last;
  public:
    /**
    Create a new move.
    @param parent The parent of this move, NULL if this is the first move.
    @param pos The position (index in the bitmask, ie (y*9)+x) to add a stone at
    */
    move(move *parent, unsigned char pos);
    ~move();
    /**
    @return The depth of this move, with the first move being zero
    */
    short int getDepth();
    /**
    Returns the owner of this move
    @return True for white, false for black
    */
    bool getOwnership();
    /**
    Returns the position of this move
    @return Position of this move
    */
    unsigned char getPosition();
    /**
    Constructs a board that contains this move and all prior moves
    @return A pointer to a gone::board
    */
    board *getBoard();
    /**
    Prints the set of moves used to get to this move, and this move.
    */
    void printMove();
  };
}
#endif