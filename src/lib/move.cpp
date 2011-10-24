#include "move.hpp"
#include <iostream>
namespace gone {
  move::move(move *parent, unsigned char pos) {
    next = NULL;
    last = parent;
    position = pos;
    if (parent != NULL) {
      depth = (parent->getDepth()+1);
      parent->next = this;
    } else {
      depth = 0;
    }
    //std::cout << "Move created: " << (int)pos << " - depth " << (int)depth << endl;
  }
  move::~move() {
    // We have to tidy up our loose ends- destroy everything after this,
    // or we risk having dangling pointers.
    delete next;
  }
  short int move::getDepth() {
    return depth;
  }
  bool move::getOwnership() {
    if (depth % 2 == 0) {
      return false;
    }
    return true;
  }
  unsigned char move::getPosition() {
    return position;
  }
  board *move::getBoard() {
    board *b = new board();
    move *curr_move = last;
    move *last_move = NULL;
    while(curr_move != last_move) {
      last_move = curr_move;
      if (curr_move->last != NULL) {
        curr_move = curr_move->last;
      }
    }
    curr_move = last_move;
    while(curr_move != NULL) {
      curr_move->getPosition();
      curr_move = curr_move->next;
    }
    return b;
  }
  void move::printMove() {
    std::cout << "Moves resulting in this board-state: " << endl;
    move *curr_move = last;
    move *last_move = NULL;
    while(curr_move != last_move) {
      last_move = curr_move;
      if (curr_move->last != NULL) {
        curr_move = curr_move->last;
      }
    }
    curr_move = last_move;
    while(curr_move != NULL) {
      curr_move->getBoard()->printBoard();
      curr_move = curr_move->next;
    }
  }
}