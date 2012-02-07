#include "ZoneListBox.h"
#include "DeleteZoneButton.h"

ZoneListBox::ZoneListBox (Preset* p)
    : TableListBox("ZoneListBox", this), preset(p)
{
//     setSize(580, 400);
    setRowHeight(72);
//     setHeaderHeight(12);
    setHeaderHeight(0);
//     setRowHeight(ZoneComponent(NULL).getHeight());
//     autoSizeAllColumns();

    // total width 580
    // name, column id, width, min width, max width
//     getHeader().addColumn("zone", 1, 540);
//     getHeader().addColumn("x", 2, 23);
    getHeader().addColumn("", 1, 24);
    getHeader().addColumn("", 2, 512);
    getHeader().addColumn("", 3, 24);
// 				 50, 400,
// 				 TableHeaderComponent::defaultFlags);
//     table.getHeader().setSortColumnId (1, true); // sort forwards by the ID column
//     table.getHeader().setColumnVisible (7, false); // hide the "length" column until the user shows it

//     getHeader().setStretchToFitActive(true);
//     getHeader().resizeAllColumnsToFit(580);

}

ZoneListBox::~ZoneListBox()
{
}

void ZoneListBox::deleteKeyPressed(int row){
  std::cout << "delete " << row << std::endl;
}

void ZoneListBox::returnKeyPressed(int row){
  std::cout << "return " << row << std::endl;
}

void ZoneListBox::listBoxItemClicked(int row, const MouseEvent &e){
  std::cout << "clicked " << row << std::endl;
}

void ZoneListBox::listBoxItemDoubleClicked(int row, const MouseEvent &e){
  std::cout << "double clicked " << row << std::endl;
}

int ZoneListBox::getNumRows(){
  std::cout << "getNumRows " << (int)preset->getNumberOfZones() << std::endl;
  return preset->getNumberOfZones();
}

Component* ZoneListBox::refreshComponentForCell(int row, int column, bool isRowSelected, Component *existingComponentToUpdate){
// Component *ZoneListBox::refreshComponentForRow(int rowNumber, bool isRowSelected, Component *existingComponentToUpdate){
  std::cout << "refresh " << row << ":" << column << std::endl;

  if(column == 2){
    Zone* zone = preset->getZone(row);
    if(zone == NULL)
      return NULL;
    ZoneComponent* comp = dynamic_cast <ZoneComponent*>(existingComponentToUpdate);
    if(comp != NULL && comp->getZone() == zone)
      return comp;
    delete existingComponentToUpdate;
    // todo: iff isRowSelected, return editable component
    std::cout << "zone " << (long)zone << std::endl;
    //   ZoneComponent* component = new ZoneComponent(zone);
    //   addAndMakeVisible(component);
    //   return component;
    return new ZoneComponent(zone);
  }else if(column == 3){
    return new DeleteZoneButton(this, row);
  }
  return NULL;
}

void ZoneListBox::paintRowBackground(Graphics &g, int row, int width, int height, bool rowIsSelected){
  if(rowIsSelected)
    g.fillAll (Colours::lightblue);
}

void ZoneListBox::paintCell(Graphics &g, int row, int column, int width, int height, bool rowIsSelected){
  if(column == 1){
    g.setColour(Colours::black);
//     g.setFont(font);
    String text;
    text += row;
    g.drawText(text, 2, 0, width - 4, height, Justification::centredLeft, true);
  }
}

// void ZoneListBox::paintListBoxItem(int rowNumber, Graphics &g, int width, int height, bool rowIsSelected){
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
// }

