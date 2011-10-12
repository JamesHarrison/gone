#include <iostream>
#include "board.hpp"
#include "basicplayer.hpp"

#include <stdlib.h>
namespace gone {
  basicPlayer::basicPlayer(bool c) {
    colour = c;
    srand ( time(NULL) );
  }
  basicPlayer::~basicPlayer() {
  }
  bool basicPlayer::makeMove(board *b) {
    // For now: Place randomly on board
    int x = rand() % 9;
    int y = rand() % 9;
    //std::cout << "Making move: " << x << "," << y << " - " << colour << endl;
    //b->printBoard();
    if (b->addStone(x,y,colour,true)) {
      //std::cout << "Move success" << endl;
      return true;
    } else {
      //std::cout << "Move failure" << endl;
      return false;
    }
  }
}