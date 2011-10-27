#include "board.hpp"
#include "game.hpp"
using namespace gone;
#include <google/profiler.h>
int main() {
  ProfilerStart("/tmp/gone_test.prof");
  for (int i=0;i<10000;i++) {
    game *g = new game();
    g->run();
    delete g;
  }
  ProfilerStop();
  return 0;
}