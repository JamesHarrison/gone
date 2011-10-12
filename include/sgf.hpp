/**
@file
@author James Harrison <james@talkunafraid.co.uk>
*/
#ifndef SGF_HPP
#define SGF_HPP
#include <iostream>
#include <fstream>
#include "board.hpp"
namespace gone {
  /// The sgf class allows for (simple) decoding of Simple Game Format files storing Go games.
  class sgf {
    // Store the board at the start of the game
    board *initial_board;
  public:
    /** Opens, reads and parses a SGF file
    @param file File path to open
    */
    sgf(char[] file);
    ~sgf();
    /** 
    @returns The board given by the file as the initial (starting) position.
    */
    board getInitialBoard();
  private:
    /**
    Does the actual parsing of an SGF string.
    @param string SGF file contents
    @returns True if the file could be parsed, false otherwise.
    */
    bool parse(char[] string);
  };
  
}
#endif