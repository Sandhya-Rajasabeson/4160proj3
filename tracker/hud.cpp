#include<sstream>
#include "hud.h"

Hud::Hud(SDL_Renderer* rend) :
  renderer(rend),
  gdata(Gamedata::getInstance()),
  hudFrame( {gdata.getXmlInt("hud/loc/x"),
             gdata.getXmlInt("hud/loc/y"),
             gdata.getXmlInt("hud/width"),
             gdata.getXmlInt("hud/height")}
  ),
  clock( Clock::getInstance() ),
  io( IoMod::getInstance() ),
  tog(false)
{}

void Hud::draw() const {
  if(tog){

      // First set the blend mode so that alpha blending will work;
      // the default blend mode is SDL_BLENDMODE_NONE!
      SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
      // Set the hud background color:
      SDL_SetRenderDrawColor( renderer, 0, 0, 15, 255/2 );

      // Draw the  background
      SDL_RenderFillRect( renderer, &hudFrame );

      // Set the  color for the hud outline:
      SDL_SetRenderDrawColor( renderer, 255, 102, 255, 255 );
      SDL_RenderDrawRect( renderer, &hudFrame );
      std::stringstream strm;
      strm << "fps: " << clock.getFps() << std::ends;
      io.writeText(strm.str(), hudFrame.x+15, hudFrame.y+15);

      io.writeText("A: turn left", hudFrame.x+15, hudFrame.y+45);
      io.writeText("D: turn right", hudFrame.x+15, hudFrame.y+75);
      io.writeText("W: jump!", hudFrame.x+15, hudFrame.y+105);
      io.writeText("spcbr: shoot", hudFrame.x+15, hudFrame.y+135);


  }
}

void Hud::toggle() {
  tog = !tog;
}
