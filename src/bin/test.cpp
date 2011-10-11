#include "board.hpp"
#include "game.hpp"
using namespace gone;
#include <google/profiler.h>
int main() {
  ProfilerStart("/tmp/gone_test.prof");
  for (int i=0;i<100000;i++) {
    game g = game();
    (&g)->run();
  }
  ProfilerStop();
  return 0;
}