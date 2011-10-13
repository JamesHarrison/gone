#include "sgf.hpp"
#include <iostream>
#include <fstream>
#include <streambuf>
namespace gone {
  sgf::sgf(string filename) {
    // Initialize things
    initial_board = new board();
    // Crack on with opening the file and reading it.
    // Rather neat method from http://stackoverflow.com/questions/2602013/read-whole-ascii-file-into-c-stdstring/2602060#2602060
    std::ifstream t(filename.c_str());
    // Now we have an ifstream, build a stream buffer iterator from it and initialize the string with the iterator
    sgf_contents = new string((std::istreambuf_iterator<char>(t)),std::istreambuf_iterator<char>());
    std::cout << "Got this string out of it all: " << (*sgf_contents).c_str() << endl;
  }
  sgf::~sgf() {
    delete initial_board;
  }
  bool sgf::parse() {
    return false;
  }
  board * sgf::getInitialBoard() {
    return initial_board;
  }
}