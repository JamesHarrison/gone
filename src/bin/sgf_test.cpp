#include <iostream>
#include "game.hpp"
#include "sgf.hpp"
using namespace gone;
int main() {
  std::cout << "gone SGF parser test - testing test.sgf" << endl;
  sgf *parser = new sgf("test.sgf");
  parser->getInitialBoard()->printBoard();
  delete parser;
  return 0;
}