#ifndef BASICPLAYER_HPP
#define BASICPLAYER_HPP
namespace gone {
  class basicPlayer {
    bool* colour;
    public:
      basicPlayer(bool c);
      ~basicPlayer();
      bool makeMove(board *b);
  };
}
#endif