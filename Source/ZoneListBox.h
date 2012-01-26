#ifndef __JUCER_HEADER_ZONELISTBOX_ZONELISTBOX_A416A31D__
#define __JUCER_HEADER_ZONELISTBOX_ZONELISTBOX_A416A31D__

#include "../JuceLibraryCode/JuceHeader.h"
#include "Preset.h"
#include "ZoneComponent.h"

class ZoneListBox  : public ListBox,
                     public ListBoxModel
{
public:
    //==============================================================================
    ZoneListBox (Preset* p);
    ~ZoneListBox();

  void setPreset(Preset* p){
    preset = p;
  }

  int getNumRows();
//     void listBoxItemClicked(int row, const MouseEvent &e);
//     void listBoxItemDoubleClicked(int row, const MouseEvent &e);

  Component *refreshComponentForRow(int rowNumber, bool isRowSelected, Component *existingComponentToUpdate);

  void paintListBoxItem(int rowNumber, Graphics &g, int width, int height, bool rowIsSelected);

    juce_UseDebuggingNewOperator

private:
/*     ListBox* listBox; */
    Preset* preset;

    //==============================================================================
    // (prevent copy constructor and operator= being generated..)
    ZoneListBox (const ZoneListBox&);
    const ZoneListBox& operator= (const ZoneListBox&);
};

#endif   // __JUCER_HEADER_ZONELISTBOX_ZONELISTBOX_A416A31D__
