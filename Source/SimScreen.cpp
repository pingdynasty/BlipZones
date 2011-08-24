#include "SimScreen.h"

#include <inttypes.h>
#include "globals.h"
#include "BlipBox.h"
#include "LedController.h"

static int row_count = 8;
static int column_count = 10;
static SimScreen *simstance = NULL;

SimScreen::SimScreen ()
{
  std::cout << "SimScreen " << isEnabled() << std::endl;
  setMouseCursor(MouseCursor::CrosshairCursor);
  if(simstance == NULL)
    simstance = this;
}

SimScreen::~SimScreen()
{
  if(simstance == this)
    simstance = NULL;
}

void SimScreen::release(){
  blipbox.keys.setValue(0, 1023);
}

void SimScreen::position(uint16_t x, uint16_t y){
  blipbox.keys.setValue(1, x);
  blipbox.keys.setValue(2, y);
  blipbox.keys.setValue(0, 40);
}

void SimScreen::position(const Point<float> p){
  position(p.getX()/getWidth()*1024, p.getY()/getHeight()*1024);
}

void SimScreen::mouseDown (const MouseEvent& e)
{
  position(getMouseXYRelative().toFloat());
}

void SimScreen::mouseDrag (const MouseEvent& e)
{
  if(contains(e.getPosition()))
    position(getMouseXYRelative().toFloat());
}

void SimScreen::mouseUp (const MouseEvent& e){
  release();
}

void SimScreen::mouseExit (const MouseEvent& e){
//   release();
}

void SimScreen::paint (Graphics& g)
{
  g.fillAll(Colours::black);
  if(blipbox.keys.isPressed()){
    g.setColour(Colours::grey);
    float x = blipbox.keys.pos.x*getWidth()/1024;
    float y = getHeight() - blipbox.keys.pos.y*getHeight()/1024;
    g.drawLine(x, 0, x, getHeight());
    g.drawLine(0, y, getWidth(), y);
  }
  g.setColour(Colours::red);
  float width = std::min((float)getWidth()/column_count, (float)getHeight()/row_count)*0.8;
  float margin = width/2;
  g.setOrigin(margin, margin);
  float dx = (getWidth()-margin) / column_count;
  float dy = (getHeight()-margin) / row_count;
  for(int col=0; col<column_count; ++col){
    for(int row=0; row<row_count; ++row){
      g.setOpacity(0.4);
      g.drawEllipse(col*dx, row*dy, width, width, 4);
      uint8_t value = blipbox.leds.getLed(col, row_count-row-1);
//       g.setOpacity(blipbox.leds.getLed(col, row)/255.0);
//       g.setColour(c.withBrightness(blipbox.leds.getLed(col, row)/255.0));
      g.setOpacity(value/255.0);
      g.fillEllipse(col*dx, row*dy, width, width);
    }
  }
}

void SimScreen::resized()
{  
}

void LedController::init(){
  back_buffer = buf1;
  counter.init();
}

void LedController::flip(){
//   uint8_t* front_buffer = flipped ? buf2 : buf1;
//   back_buffer = flipped ? buf1 : buf2;  
//   // memcpy(to, from, bytes)
//   memcpy(back_buffer, front_buffer, LED_BUFFER_LENGTH);
//   flipped = !flipped;
  if(simstance){
    const MessageManagerLock mmLock;
    simstance->repaint();
  }
}

void LedController::displayCurrentRow(void){
  counter.tick();
}

void LedController::sendBufferData(uint8_t row){
}
