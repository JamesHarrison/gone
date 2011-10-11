#ifndef BOARD_HPP
#define BOARD_HPP
#include <iostream>
#include <bitset>
using namespace std;
namespace gone {
  class board {
    // This bitset stores a bit for each intersection. If it is 1, it is occupied. If it is 0, it is not.
    // The board is stored top left to bottom right row by row- bits 0-9 are row 0, 10-19 are row 2, and so on.
    bitset<81> *occupied;
    // As above, but for ownership of stones. Each bit here corresponds to a bit in the occupied bitset; if it
    // is not set here but is set in the above, it is a black stone. If it is set here and above, it is a white stone.
    bitset<81> *owner;
  public:
    board();
    ~board();
    void printBoard();
    bool addStone(int x, int y, bool o, bool check_for_illegal_moves);
  };
}
#endif