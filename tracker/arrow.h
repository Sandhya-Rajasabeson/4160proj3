#ifndef ARROW__H
#define ARROW__H

#include <iostream>
#include "sprite.h"
#include "gameData.h"

class Arrow : public Sprite {
public:
  explicit Arrow(const string& name) :
    Sprite(name),
    distance(0),
    maxDistance(Gamedata::getInstance().getXmlInt(name+"/distance")),
    tooFar(false)
  { }
  virtual void update(Uint32 ticks);
  bool goneTooFar() const { return tooFar; }
  void reset() {
    tooFar = false;
    distance = 0;
  }

private:
  float distance;
  float maxDistance;
  bool tooFar;
};
#endif
