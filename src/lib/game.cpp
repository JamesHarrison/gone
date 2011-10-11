#include "board.hpp"
#include "game.hpp"
#include "basicplayer.hpp"
namespace gone {
  game::game() {
    white_player = new basicPlayer(true);
    black_player = new basicPlayer(false);
    game_board = new board();
  }
  game::~game() {
    delete &white_player;
    delete &black_player;
    delete &game_board;
  }
  void game::printBoard() {
    game_board->printBoard();
  }
  bool game::run() {
    // Black plays first
    bool current_player = false;
    bool last_move_success = true;
    while(last_move_success) {
      //std::cout << "Starting run, white is " << white_player << " black " << black_player << endl;
      if (current_player == true) {
        last_move_success = white_player->makeMove(game_board);
        //std::cout << "White made a move: " << last_move_success << endl;
      } else {
        last_move_success = black_player->makeMove(game_board);
        //std::cout << "Black made a move: " << last_move_success << endl;
      }
      current_player = !current_player;
    }
    return true;
  }

}