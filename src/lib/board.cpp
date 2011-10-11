#include "board.hpp"
#include <iostream>
#include <bitset>
namespace gone {
  board::~board() {
    delete occupied;
    delete owner;
  }
  board::board() {
    occupied = new bitset<81>;
    owner = new bitset<81>;
  }
  void board::printBoard() {
    std::cout << "Printing board" << endl;
    for (int y=0;y<9;y++) {
      std::cout << y << ": ";
      for (int x=0;x<9;x++) {
        if ((*occupied).test((y*9)+x) == true) {
          if ((*owner).test((y*9)+x) == true) {
            std::cout << " W ";
          } else {
            std::cout << " B ";
          }
        } else { 
          std::cout << " - ";
        }
      }
      std::cout << endl;
    }
  }
  /*
  * Adds a stone at the specified position (x/y coordinate) with the given owner (false=black, true=white)
  * FIXME: Don't allow illegal stone placement?
  */
  bool board::addStone(int x, int y, bool o, bool check_for_illegal_moves) {
    size_t pos = (y*9)+x;
    //std::cout << "Position: " << pos << " x: " << x << " y: " << y << " owner: " << o << endl;
    if (check_for_illegal_moves) {
      if ((*occupied).test(pos) == true) {
        //std::cout << "Illegal move" << endl;
        return false;
      }
    }
    //std::cout << "Legal move" << endl;
    (*occupied).set(pos, true);
    (*owner).set(pos, o);
    return true;
  }
}