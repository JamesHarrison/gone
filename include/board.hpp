/**
@file
@author James Harrison <james@talkunafraid.co.uk>
*/
#ifndef BOARD_HPP
#define BOARD_HPP
#include <bitset>
using namespace std;
namespace gone {
  /// The board class stores a single board in gone. This is done using two bitsets for space efficiency.
  class board {
    // This bitset stores a bit for each intersection. If it is 1, it is occupied. If it is 0, it is not.
    // The board is stored top left to bottom right row by row- bits 0-9 are row 0, 10-19 are row 2, and so on.
    bitset<81> *occupied;
    // As above, but for ownership of stones. Each bit here corresponds to a bit in the occupied bitset; if it
    // is not set here but is set in the above, it is a black stone. If it is set here and above, it is a white stone.
    bitset<81> *owner;
  public:
    /**
    Sets up a new board with no stones on it
    */
    board();
    ~board();
    /**
    Prints a board out to standard output
    */
    void printBoard();
    /**
    Adds a stone to the board at a given position for a given owner, optionally checking for illegal moves.

    @param pos The position on the board to add at
    @param o The owner (white=true, black=false)
    */
    void addStone(unsigned char pos, bool o);
    /**
    @param pos Position on the board to check
    @param owner Owner to check for
    @return True if a stone can be placed in this position
    */
    bool canAdd(unsigned char pos, bool owner);
  };
}
#endif