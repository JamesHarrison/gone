/**
@file
@author James Harrison <james@talkunafraid.co.uk>
*/
#ifndef SGF_HPP
#define SGF_HPP

#include "board.hpp"
namespace gone {
  /**
  @brief The sgf class allows for (simple) decoding of Simple Game Format files storing Go games.
  @warning This SGF class is not particularly robust or designed for parsing more than simple Go files.
  */
  class sgf {
    // Store the board at the start of the game
    board *initial_board;
    string *sgf_contents;
  public:
    /** Opens, reads and parses a SGF file
    @param filename File path to open
    */
    sgf(string filename);
    ~sgf();
    /** 
    @returns The board given by the file as the initial (starting) position.
    */
    board * getInitialBoard();
  private:
    /**
    Does the actual parsing of the content loaded in the constructor
    @returns True if the content could be parsed, false otherwise.
    */
    bool parse();
  };
  
}
#endif