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
  move *basicPlayer::makeMove(board *b, move *last_move) {
    unsigned char pos = rand() % 81;
    if (b->canAdd(pos,colour)) {
      move *m = new move(last_move, pos);
      return m;
    }
    return NULL;
  }
}