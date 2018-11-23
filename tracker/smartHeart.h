#ifndef SMARTHEART__H
#define SMARTSPRITE__H
#include <string>
#include "multisprite.h"

class SmartHeart : public MultiSprite {
public:
  SmartHeart(const std::string&, Drawable*);
  SmartHeart(const SmartHeart&);
  virtual ~SmartHeart() { }

  void notify(Vector2f);

  virtual void update(Uint32 ticks);

protected:
  SmartHeart& operator=(const SmartHeart&);

private:
  enum MODE {NORMAL, EVADE};
  Drawable *biker;
  Vector2f bikerPos;
  MODE currentMode;
  float safeDistance;

  void left();
  void right();
  void up();
  void down();
};
#endif
