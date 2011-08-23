# Automatically generated makefile, created by the Jucer
# Don't edit this file! Your changes will be overwritten when you re-save the Jucer project!

ifndef CONFIG
  CONFIG=Debug
endif

ifeq ($(TARGET_ARCH),)
  TARGET_ARCH := -march=native
endif

# (this disables dependency generation if multiple architectures are set)
DEPFLAGS := $(if $(word 2, $(TARGET_ARCH)), , -MMD)

ifeq ($(CONFIG),Debug)
  BINDIR := build
  LIBDIR := build
  OBJDIR := build/intermediate/Debug
  OUTDIR := build
  CPPFLAGS := $(DEPFLAGS) -D "LINUX=1" -D "DEBUG=1" -D "_DEBUG=1" -D "JUCER_LINUX_MAKE_7346DA2A=1" -I "/usr/include" -I "/usr/include/freetype2"
  CFLAGS += $(CPPFLAGS) $(TARGET_ARCH) -g -ggdb -O0
  CXXFLAGS += $(CFLAGS) 
  LDFLAGS += -L$(BINDIR) -L$(LIBDIR) -L"/usr/X11R6/lib/" -L"../../../juce/bin" -lfreetype -lpthread -lrt -lX11 -lGL -lGLU -lXinerama -lasound 
  LDDEPS :=
  RESFLAGS :=  -D "LINUX=1" -D "DEBUG=1" -D "_DEBUG=1" -D "JUCER_LINUX_MAKE_7346DA2A=1" -I "/usr/include" -I "/usr/include/freetype2"
  TARGET := BlipZones
  BLDCMD = $(CXX) -o $(OUTDIR)/$(TARGET) $(OBJECTS) $(LDFLAGS) $(RESOURCES) $(TARGET_ARCH)
endif

ifeq ($(CONFIG),Release)
  BINDIR := build
  LIBDIR := build
  OBJDIR := build/intermediate/Release
  OUTDIR := build
  CPPFLAGS := $(DEPFLAGS) -D "LINUX=1" -D "NDEBUG=1" -D "JUCER_LINUX_MAKE_7346DA2A=1" -I "/usr/include" -I "/usr/include/freetype2"
  CFLAGS += $(CPPFLAGS) $(TARGET_ARCH) -Os
  CXXFLAGS += $(CFLAGS) 
  LDFLAGS += -L$(BINDIR) -L$(LIBDIR) -L"/usr/X11R6/lib/" -L"../../../juce/bin" -lfreetype -lpthread -lrt -lX11 -lGL -lGLU -lXinerama -lasound 
  LDDEPS :=
  RESFLAGS :=  -D "LINUX=1" -D "NDEBUG=1" -D "JUCER_LINUX_MAKE_7346DA2A=1" -I "/usr/include" -I "/usr/include/freetype2"
  TARGET := BlipZones
  BLDCMD = $(CXX) -o $(OUTDIR)/$(TARGET) $(OBJECTS) $(LDFLAGS) $(RESOURCES) $(TARGET_ARCH)
endif

OBJECTS := \
  $(OBJDIR)/eeprom_119b2b22.o \
  $(OBJDIR)/interrupt_7815b74b.o \
  $(OBJDIR)/io_396ac548.o \
  $(OBJDIR)/pgmspace_bd943d52.o \
  $(OBJDIR)/FiveWireTouchController_f675de.o \
  $(OBJDIR)/Animator_34f8d44c.o \
  $(OBJDIR)/BlipBox_5cdbe29f.o \
  $(OBJDIR)/BlipBoxProtocol_313f2f57.o \
  $(OBJDIR)/Characters_a59f0e4f.o \
  $(OBJDIR)/Configuration_1163487b.o \
  $(OBJDIR)/DirectCounter_d4bbe6d8.o \
  $(OBJDIR)/DisplayManager_22bc63f0.o \
  $(OBJDIR)/EventHandler_659bf035.o \
  $(OBJDIR)/globals_fb00bd5.o \
  $(OBJDIR)/KeyController_64b2cc60.o \
  $(OBJDIR)/MessageDispatcher_7190f993.o \
  $(OBJDIR)/MidiZone_b040b8d2.o \
  $(OBJDIR)/MidiZoneEventHandler_bc17ccc2.o \
  $(OBJDIR)/Parameters_d3e365cf.o \
  $(OBJDIR)/PresetChooser_3d3409e1.o \
  $(OBJDIR)/SerialProtocol_a3d59791.o \
  $(OBJDIR)/SerialProtocolReader_18069df4.o \
  $(OBJDIR)/ApplicationConfiguration_4b5ea10f.o \
  $(OBJDIR)/ApplicationSettingsComponent_dd54a033.o \
  $(OBJDIR)/BlipClient_d12f7da5.o \
  $(OBJDIR)/BlipSim_356db187.o \
  $(OBJDIR)/BlipSimComponent_eafa3680.o \
  $(OBJDIR)/MainWindow_499ac812.o \
  $(OBJDIR)/Main_90ebc5c2.o \
  $(OBJDIR)/MidiZoneComponent_5a1e8671.o \
  $(OBJDIR)/MidiZonePreset_30c42135.o \
  $(OBJDIR)/PresetComponent_8f0e6a3f.o \
  $(OBJDIR)/SimScreen_99fdf804.o \
  $(OBJDIR)/SimWindow_21e2b188.o \
  $(OBJDIR)/BinaryData_ce4232d4.o \
  $(OBJDIR)/JuceLibraryCode1_682c927f.o \
  $(OBJDIR)/JuceLibraryCode2_683aaa00.o \
  $(OBJDIR)/JuceLibraryCode3_6848c181.o \
  $(OBJDIR)/JuceLibraryCode4_6856d902.o \

.PHONY: clean

$(OUTDIR)/$(TARGET): $(OBJECTS) $(LDDEPS) $(RESOURCES)
	@echo Linking BlipZones
	-@mkdir -p $(BINDIR)
	-@mkdir -p $(LIBDIR)
	-@mkdir -p $(OUTDIR)
	@$(BLDCMD)

clean:
	@echo Cleaning BlipZones
	-@rm -f $(OUTDIR)/$(TARGET)
	-@rm -rf $(OBJDIR)/*
	-@rm -rf $(OBJDIR)

$(OBJDIR)/eeprom_119b2b22.o: ../../../BlipBox/firmware/simulator/avr/eeprom.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling eeprom.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/interrupt_7815b74b.o: ../../../BlipBox/firmware/simulator/avr/interrupt.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling interrupt.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/io_396ac548.o: ../../../BlipBox/firmware/simulator/avr/io.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling io.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/pgmspace_bd943d52.o: ../../../BlipBox/firmware/simulator/avr/pgmspace.c
	-@mkdir -p $(OBJDIR)
	@echo "Compiling pgmspace.c"
	@$(CC) $(CFLAGS) -o "$@" -c "$<"

$(OBJDIR)/FiveWireTouchController_f675de.o: ../../../BlipBox/firmware/simulator/FiveWireTouchController.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling FiveWireTouchController.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/Animator_34f8d44c.o: ../../../BlipBox/firmware/Animator.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling Animator.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/BlipBox_5cdbe29f.o: ../../../BlipBox/firmware/BlipBox.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling BlipBox.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/BlipBoxProtocol_313f2f57.o: ../../../BlipBox/firmware/BlipBoxProtocol.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling BlipBoxProtocol.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/Characters_a59f0e4f.o: ../../../BlipBox/firmware/Characters.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling Characters.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/Configuration_1163487b.o: ../../../BlipBox/firmware/Configuration.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling Configuration.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/DirectCounter_d4bbe6d8.o: ../../../BlipBox/firmware/DirectCounter.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling DirectCounter.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/DisplayManager_22bc63f0.o: ../../../BlipBox/firmware/DisplayManager.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling DisplayManager.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/EventHandler_659bf035.o: ../../../BlipBox/firmware/EventHandler.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling EventHandler.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/globals_fb00bd5.o: ../../../BlipBox/firmware/globals.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling globals.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/KeyController_64b2cc60.o: ../../../BlipBox/firmware/KeyController.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling KeyController.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/MessageDispatcher_7190f993.o: ../../../BlipBox/firmware/MessageDispatcher.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling MessageDispatcher.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/MidiZone_b040b8d2.o: ../../../BlipBox/firmware/MidiZone.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling MidiZone.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/MidiZoneEventHandler_bc17ccc2.o: ../../../BlipBox/firmware/MidiZoneEventHandler.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling MidiZoneEventHandler.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/Parameters_d3e365cf.o: ../../../BlipBox/firmware/Parameters.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling Parameters.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/PresetChooser_3d3409e1.o: ../../../BlipBox/firmware/PresetChooser.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling PresetChooser.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/SerialProtocol_a3d59791.o: ../../../BlipBox/firmware/SerialProtocol.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling SerialProtocol.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/SerialProtocolReader_18069df4.o: ../../../BlipBox/firmware/SerialProtocolReader.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling SerialProtocolReader.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/ApplicationConfiguration_4b5ea10f.o: ../../Source/ApplicationConfiguration.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling ApplicationConfiguration.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/ApplicationSettingsComponent_dd54a033.o: ../../Source/ApplicationSettingsComponent.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling ApplicationSettingsComponent.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/BlipClient_d12f7da5.o: ../../Source/BlipClient.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling BlipClient.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/BlipSim_356db187.o: ../../Source/BlipSim.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling BlipSim.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/BlipSimComponent_eafa3680.o: ../../Source/BlipSimComponent.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling BlipSimComponent.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/MainWindow_499ac812.o: ../../Source/MainWindow.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling MainWindow.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/Main_90ebc5c2.o: ../../Source/Main.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling Main.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/MidiZoneComponent_5a1e8671.o: ../../Source/MidiZoneComponent.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling MidiZoneComponent.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/MidiZonePreset_30c42135.o: ../../Source/MidiZonePreset.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling MidiZonePreset.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/PresetComponent_8f0e6a3f.o: ../../Source/PresetComponent.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling PresetComponent.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/SimScreen_99fdf804.o: ../../Source/SimScreen.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling SimScreen.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/SimWindow_21e2b188.o: ../../Source/SimWindow.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling SimWindow.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/BinaryData_ce4232d4.o: ../../JuceLibraryCode/BinaryData.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling BinaryData.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/JuceLibraryCode1_682c927f.o: ../../JuceLibraryCode/JuceLibraryCode1.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling JuceLibraryCode1.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/JuceLibraryCode2_683aaa00.o: ../../JuceLibraryCode/JuceLibraryCode2.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling JuceLibraryCode2.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/JuceLibraryCode3_6848c181.o: ../../JuceLibraryCode/JuceLibraryCode3.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling JuceLibraryCode3.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/JuceLibraryCode4_6856d902.o: ../../JuceLibraryCode/JuceLibraryCode4.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling JuceLibraryCode4.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

-include $(OBJECTS:%.o=%.d)
