#include "ApplicationConfiguration.h"
#include "MidiMessageReceiver.h"
#include "BlipSim.h"
#include "SimScreen.h"
#include "BlipClient.h"
#include "Preset.h"
#include "OscServer.h"

void ApplicationConfiguration::initialise(){
  PropertiesFile* properties = ApplicationConfiguration::getApplicationProperties();
  getBlipClient()->setPort(properties->getValue("serialport"));
  getBlipClient()->setSpeed(properties->getValue("serialspeed").getIntValue());
  getMidiMessageReceiver()->setMidiInput(properties->getValue("midiinput"));
  getBlipSim()->setMidiOutput(properties->getValue("midioutput"));
  getOscServer()->setHostname(properties->getValue("oschost"));
  getOscServer()->setPort(properties->getValue("oscport").getIntValue());
}

PropertiesFile* properties = NULL;
PropertiesFile* ApplicationConfiguration::getApplicationProperties(){
  if(properties == NULL){
    PropertiesFile::Options opts;
    opts.osxLibrarySubFolder = "Application Support";
    opts.folderName = "BlipBox";
    opts.applicationName = "BlipZones";
    opts.filenameSuffix = ".properties";
    properties = new PropertiesFile(opts);
    if(!properties->containsKey("serialport"))
      properties->setValue("serialport", "none");
    if(!properties->containsKey("serialspeed"))
      properties->setValue("serialspeed", "57600");
    if(!properties->containsKey("presetdirectory"))
      properties->setValue("presetdirectory", File::getSpecialLocation(File::userDocumentsDirectory).getChildFile("BlipZones").getFullPathName());
    if(!properties->containsKey("midioutput"))
      properties->setValue("midioutput", "none");
    if(!properties->containsKey("midiinput"))
      properties->setValue("midiinput", "none");
    if(!properties->containsKey("oschost"))
      properties->setValue("oschost", "localhost");
    if(!properties->containsKey("oscport"))
      properties->setValue("oscport", "9000");
    if(!properties->isValidFile())
      std::cerr << "Invalid properties file: " << properties->getFile().getFullPathName() << std::endl;
  }
  return properties;
}

BlipSim* blipsim = NULL;
BlipSim* ApplicationConfiguration::getBlipSim(){
  if(blipsim == NULL)
    blipsim = new BlipSim();
  return blipsim;
}

BlipClient* blipclient = NULL;
BlipClient* ApplicationConfiguration::getBlipClient(){
  if(blipclient == NULL)
    blipclient = new BlipClient();
  return blipclient;
}

#define PRESETS 8
Preset presets[PRESETS];
Preset* ApplicationConfiguration::getPreset(int index){
  if(index < PRESETS)
    return &presets[index];
  return NULL;
}

File ApplicationConfiguration::getPresetDirectory(){
  PropertiesFile* properties = getApplicationProperties();
  File dir(properties->getValue("presetdirectory"));
  return dir;
}

MidiMessageReceiver receiver;
MidiMessageReceiver* ApplicationConfiguration::getMidiMessageReceiver(){
  return &receiver;
}

OscServer oscserver;
OscServer* ApplicationConfiguration::getOscServer(){
  return &oscserver;
}

void ApplicationConfiguration::release(){
/*     If you're leaking, it's probably because you're using old-fashioned, non-RAII techniques for */
/*     your object management. Tut, tut. Always, always use ScopedPointers, OwnedArrays, */
/*     ReferenceCountedObjects, etc, and avoid the 'delete' operator at all costs! */
  if(properties != NULL)
    properties->saveIfNeeded();
  deleteAndZero(properties);
  deleteAndZero(blipsim);
  deleteAndZero(blipclient);
}
