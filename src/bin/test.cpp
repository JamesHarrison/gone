#include "board.hpp"
#include "game.hpp"
using namespace gone;
#include <google/profiler.h>
int main() {
  ProfilerStart("/tmp/gone_test.prof");
  for (int i=0;i<10;i++) {
    game *g = new game();
    g->run();
    g->printBoard();
    delete g;
  }
  ProfilerStop();
  return 0;
}