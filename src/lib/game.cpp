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
    delete white_player;
    delete black_player;
    delete game_board;
  }
  void game::printBoard() {
    game_board->printBoard();
  }
  bool game::run() {
    // Black plays first
    move *current_move = NULL;
    current_move = black_player->makeMove(game_board, current_move);
    bool current_player = true;
    // Now we keep on looping till we hit a NULL.
    while(current_move != NULL) {
      // Add the last player's move.
      game_board->addStone(current_move->getPosition(), !current_player);
      // Print the last move.
      current_move->printMove();
      // Make the next move.
      if (current_player == true) {
        current_move = white_player->makeMove(game_board, current_move);
      } else {
        current_move = black_player->makeMove(game_board, current_move);
      }
      // Mark this player as having made their move.
      current_player = !current_player;
    }
    delete current_move;
    return true;
  }

}