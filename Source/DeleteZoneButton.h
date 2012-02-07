#ifndef __DELETE_ZONE_BUTTON_H__
#define __DELETE_ZONE_BUTTON_H__

#include "../JuceLibraryCode/JuceHeader.h"
#include "ZoneListBox.h"

class DeleteZoneButton : public ImageButton, public ButtonListener {
private:
  ZoneListBox* box;
  int index;
  static const char* deleteButton_png;
  static const int deleteButton_pngSize;
public:
 DeleteZoneButton(ZoneListBox* b, int i) : ImageButton(L"delete button"), box(b), index(i) {
    setImages(false, true, true,
	      ImageCache::getFromMemory(deleteButton_png, deleteButton_pngSize), 
	      1.0000f, Colour (0x0),
	      Image(), 1.0000f, Colour (0x0),
	      Image(), 1.0000f, Colour (0x0));
    setBounds (8, 8, 23, 24);
    addListener (this);
  }
  void buttonClicked(Button* buttonThatWasClicked){
    std::cout << "delete " << index << std::endl;
    Preset* preset = box->getPreset();
    // shift later zones up one notch
    int i=index;
    for(; i+1<preset->getNumberOfZones(); ++i)
      preset->setZone(i, preset->getZone(i+1));
    preset->setZone(i, NULL);
    box->updateContent();
  }
};

#endif /* __DELETE_ZONE_BUTTON_H_ */ 
