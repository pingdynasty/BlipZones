#ifndef __JUCER_HEADER_ZONELISTBOX__
#define __JUCER_HEADER_ZONELISTBOX__

#include "../JuceLibraryCode/JuceHeader.h"
#include "Preset.h"
#include "ZoneComponent.h"

class ZoneListBox  : public TableListBox,
                     public TableListBoxModel
{
public:
    //==============================================================================
    ZoneListBox (Preset* p);
    ~ZoneListBox();

  void setPreset(Preset* p){
    preset = p;
  }
  Preset* getPreset(){
    return preset;
  }

  int getNumRows();
  void listBoxItemClicked(int row, const MouseEvent &e);
  void listBoxItemDoubleClicked(int row, const MouseEvent &e);
  void deleteKeyPressed(int row);
  void returnKeyPressed(int row);

  virtual void paintRowBackground(Graphics &g, int rowNumber, int width, int height, bool rowIsSelected);
  virtual Component* refreshComponentForCell(int rowNumber, int columnId, bool isRowSelected, Component *existingComponentToUpdate);
  virtual void paintCell(Graphics &g, int rowNumber, int columnId, int width, int height, bool rowIsSelected);

//   Component* refreshComponentForRow(int rowNumber, bool isRowSelected, Component *existingComponentToUpdate);
//   void paintListBoxItem(int rowNumber, Graphics &g, int width, int height, bool rowIsSelected);

    juce_UseDebuggingNewOperator

private:
/*     ListBox* listBox; */
    Preset* preset;

    //==============================================================================
    // (prevent copy constructor and operator= being generated..)
    ZoneListBox (const ZoneListBox&);
    const ZoneListBox& operator= (const ZoneListBox&);
};

#endif   // __JUCER_HEADER_ZONELISTBOX__
