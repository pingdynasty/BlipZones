#include "ZoneListBox.h"

ZoneListBox::ZoneListBox (Preset* p)
    : ListBox("ZoneListBox", this), preset(p)
{
    setSize (600, 400);
    setRowHeight(60);
//     setRowHeight(ZoneComponent(NULL).getHeight());
}

ZoneListBox::~ZoneListBox()
{
}

int ZoneListBox::getNumRows(){
  std::cout << "getNumRows " << (int)preset->getNumberOfZones() << std::endl;
  return preset->getNumberOfZones();
}

Component *ZoneListBox::refreshComponentForRow(int rowNumber, bool isRowSelected, Component *existingComponentToUpdate){
  std::cout << "refresh " << rowNumber << std::endl;
  Zone* zone = preset->getZone(rowNumber);

  ZoneComponent* comp = dynamic_cast <ZoneComponent*>(existingComponentToUpdate);
  if(comp != NULL && comp->getZone() == zone)
    return comp;

  delete existingComponentToUpdate;
  // todo: iff isRowSelected, return editable component
  std::cout << "zone " << (long)zone << std::endl;
  if(zone == NULL)
    return NULL;
//   ZoneComponent* component = new ZoneComponent(zone);
//   addAndMakeVisible(component);
//   return component;
  return new ZoneComponent(zone);
}

void ZoneListBox::paintListBoxItem(int rowNumber, Graphics &g, int width, int height, bool rowIsSelected){
//   std::cout << "paint " << rowNumber << std::endl;
  // todo - leave empty?
//     if (rowIsSelected)
//         g.fillAll (findColour (TextEditor::highlightColourId));
//     g.setColour (findColour (ListBox::textColourId));
//     Font f (height * 0.7f);
//     f.setHorizontalScale (0.9f);
//     g.setFont (f);
//     String txt;
//     txt << "zone " << rowNumber;
//     g.drawText ("hallo"+txt, 4, 0, width - 6, height,
//                 Justification::centredLeft, true);
}

