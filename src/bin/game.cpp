#include "board.hpp"
#include "game.hpp"
using namespace gone;
#include <google/profiler.h>
int main() {
  ProfilerStart("/tmp/gone_game.prof");
  game *g = new game;
  bool result = g->run();
  g->printBoard();
  delete g;
  ProfilerStop();
  return 0;
}