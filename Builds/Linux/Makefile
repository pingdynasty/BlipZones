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
  CPPFLAGS := $(DEPFLAGS) -D "LINUX=1" -D "DEBUG=1" -D "_DEBUG=1" -D "JUCER_LINUX_MAKE_7346DA2A=1" -I "/usr/include" -I "/usr/include/freetype2" -I "../../Libraries" -I "../../../BlipBox/firmware/simulator" -I "../../../BlipBox/firmware" -I "../../BlipBox/firmware/simulator" -I "../../BlipBox/firmware"
  CFLAGS += $(CPPFLAGS) $(TARGET_ARCH) -g -ggdb -O0
  CXXFLAGS += $(CFLAGS) 
  LDFLAGS += -L$(BINDIR) -L$(LIBDIR) -L"/usr/X11R6/lib/" -L"../../Libraries/juce/bin" -lfreetype -lpthread -lrt -lX11 -lGL -lGLU -lXinerama -lasound 
  LDDEPS :=
  RESFLAGS :=  -D "LINUX=1" -D "DEBUG=1" -D "_DEBUG=1" -D "JUCER_LINUX_MAKE_7346DA2A=1" -I "/usr/include" -I "/usr/include/freetype2" -I "../../Libraries" -I "../../../BlipBox/firmware/simulator" -I "../../../BlipBox/firmware" -I "../../BlipBox/firmware/simulator" -I "../../BlipBox/firmware"
  TARGET := BlipZones
  BLDCMD = $(CXX) -o $(OUTDIR)/$(TARGET) $(OBJECTS) $(LDFLAGS) $(RESOURCES) $(TARGET_ARCH)
endif

ifeq ($(CONFIG),Release)
  BINDIR := build
  LIBDIR := build
  OBJDIR := build/intermediate/Release
  OUTDIR := build
  CPPFLAGS := $(DEPFLAGS) -D "LINUX=1" -D "NDEBUG=1" -D "JUCER_LINUX_MAKE_7346DA2A=1" -I "/usr/include" -I "/usr/include/freetype2" -I "../../Libraries" -I "../../../BlipBox/firmware/simulator" -I "../../../BlipBox/firmware" -I "../../BlipBox/firmware/simulator" -I "../../BlipBox/firmware"
  CFLAGS += $(CPPFLAGS) $(TARGET_ARCH) -Os
  CXXFLAGS += $(CFLAGS) 
  LDFLAGS += -L$(BINDIR) -L$(LIBDIR) -L"/usr/X11R6/lib/" -L"../../Libraries/juce/bin" -lfreetype -lpthread -lrt -lX11 -lGL -lGLU -lXinerama -lasound 
  LDDEPS :=
  RESFLAGS :=  -D "LINUX=1" -D "NDEBUG=1" -D "JUCER_LINUX_MAKE_7346DA2A=1" -I "/usr/include" -I "/usr/include/freetype2" -I "../../Libraries" -I "../../../BlipBox/firmware/simulator" -I "../../../BlipBox/firmware" -I "../../BlipBox/firmware/simulator" -I "../../BlipBox/firmware"
  TARGET := BlipZones
  BLDCMD = $(CXX) -o $(OUTDIR)/$(TARGET) $(OBJECTS) $(LDFLAGS) $(RESOURCES) $(TARGET_ARCH)
endif

OBJECTS := \
  $(OBJDIR)/OscOutboundPacketStream_87ae81a6.o \
  $(OBJDIR)/OscPrintReceivedElements_773a3861.o \
  $(OBJDIR)/OscReceivedElements_990f2ae6.o \
  $(OBJDIR)/OscTypes_5116aa15.o \
  $(OBJDIR)/MidiNRPNComponent_31fe6b3b.o \
  $(OBJDIR)/MidiAftertouchComponent_fdd4a45a.o \
  $(OBJDIR)/MidiChannelPressureComponent_876df3f.o \
  $(OBJDIR)/DeleteZoneButton_48234812.o \
  $(OBJDIR)/OscAction_e33520f6.o \
  $(OBJDIR)/OscServer_7fe8383.o \
  $(OBJDIR)/OscComponent_a9199e47.o \
  $(OBJDIR)/ConfigurationComponent_819f48b0.o \
  $(OBJDIR)/ZoneListBox_dec494e2.o \
  $(OBJDIR)/MidiNoteRangeComponent_83ee53dc.o \
  $(OBJDIR)/ControlVoltageComponent_e8d6d51d.o \
  $(OBJDIR)/SelectPresetComponent_c32e92a3.o \
  $(OBJDIR)/PresetFactory_fe788f0c.o \
  $(OBJDIR)/MidiNoteComponent_ad4c9beb.o \
  $(OBJDIR)/MidiPitchBendComponent_6f08226e.o \
  $(OBJDIR)/ActionComponent_1f273448.o \
  $(OBJDIR)/MidiControllerComponent_633a1841.o \
  $(OBJDIR)/ZoneComponent_e6171992.o \
  $(OBJDIR)/MidiMessageReceiver_a5467196.o \
  $(OBJDIR)/ZoneAreaAnimator_cca8cee9.o \
  $(OBJDIR)/AsioSerial_7a9dfc75.o \
  $(OBJDIR)/Serial_5af037d.o \
  $(OBJDIR)/PresetReader_165d1067.o \
  $(OBJDIR)/MidiMessageReader_cccd780e.o \
  $(OBJDIR)/operators_caa0a374.o \
  $(OBJDIR)/spi_bitbang_66707ed7.o \
  $(OBJDIR)/ControlVoltageAction_1c1da3c.o \
  $(OBJDIR)/Action_8c62b41b.o \
  $(OBJDIR)/Event_a7efa41f.o \
  $(OBJDIR)/Preset_76c39c44.o \
  $(OBJDIR)/Zone_92b07a91.o \
  $(OBJDIR)/eeprom_119b2b22.o \
  $(OBJDIR)/interrupt_7815b74b.o \
  $(OBJDIR)/io_396ac548.o \
  $(OBJDIR)/pgmspace_bd943d52.o \
  $(OBJDIR)/FiveWireTouchController_f675de.o \
  $(OBJDIR)/Animator_34f8d44c.o \
  $(OBJDIR)/BlipBox_5cdbe29f.o \
  $(OBJDIR)/Characters_a59f0e4f.o \
  $(OBJDIR)/Configuration_1163487b.o \
  $(OBJDIR)/DirectCounter_d4bbe6d8.o \
  $(OBJDIR)/DisplayManager_22bc63f0.o \
  $(OBJDIR)/EventHandler_659bf035.o \
  $(OBJDIR)/globals_fb00bd5.o \
  $(OBJDIR)/KeyController_64b2cc60.o \
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
  $(OBJDIR)/PresetComponent_8f0e6a3f.o \
  $(OBJDIR)/SimScreen_99fdf804.o \
  $(OBJDIR)/SimWindow_21e2b188.o \
  $(OBJDIR)/BinaryData_ce4232d4.o \
  $(OBJDIR)/JuceLibraryCode_9800db7c.o \

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

$(OBJDIR)/OscOutboundPacketStream_87ae81a6.o: ../../Libraries/osc/OscOutboundPacketStream.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling OscOutboundPacketStream.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/OscPrintReceivedElements_773a3861.o: ../../Libraries/osc/OscPrintReceivedElements.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling OscPrintReceivedElements.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/OscReceivedElements_990f2ae6.o: ../../Libraries/osc/OscReceivedElements.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling OscReceivedElements.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/OscTypes_5116aa15.o: ../../Libraries/osc/OscTypes.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling OscTypes.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/MidiNRPNComponent_31fe6b3b.o: ../../Source/MidiNRPNComponent.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling MidiNRPNComponent.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/MidiAftertouchComponent_fdd4a45a.o: ../../Source/MidiAftertouchComponent.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling MidiAftertouchComponent.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/MidiChannelPressureComponent_876df3f.o: ../../Source/MidiChannelPressureComponent.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling MidiChannelPressureComponent.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/DeleteZoneButton_48234812.o: ../../Source/DeleteZoneButton.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling DeleteZoneButton.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/OscAction_e33520f6.o: ../../Source/OscAction.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling OscAction.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/OscServer_7fe8383.o: ../../Source/OscServer.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling OscServer.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/OscComponent_a9199e47.o: ../../Source/OscComponent.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling OscComponent.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/ConfigurationComponent_819f48b0.o: ../../Source/ConfigurationComponent.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling ConfigurationComponent.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/ZoneListBox_dec494e2.o: ../../Source/ZoneListBox.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling ZoneListBox.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/MidiNoteRangeComponent_83ee53dc.o: ../../Source/MidiNoteRangeComponent.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling MidiNoteRangeComponent.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/ControlVoltageComponent_e8d6d51d.o: ../../Source/ControlVoltageComponent.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling ControlVoltageComponent.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/SelectPresetComponent_c32e92a3.o: ../../Source/SelectPresetComponent.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling SelectPresetComponent.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/PresetFactory_fe788f0c.o: ../../Source/PresetFactory.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling PresetFactory.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/MidiNoteComponent_ad4c9beb.o: ../../Source/MidiNoteComponent.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling MidiNoteComponent.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/MidiPitchBendComponent_6f08226e.o: ../../Source/MidiPitchBendComponent.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling MidiPitchBendComponent.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/ActionComponent_1f273448.o: ../../Source/ActionComponent.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling ActionComponent.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/MidiControllerComponent_633a1841.o: ../../Source/MidiControllerComponent.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling MidiControllerComponent.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/ZoneComponent_e6171992.o: ../../Source/ZoneComponent.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling ZoneComponent.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/MidiMessageReceiver_a5467196.o: ../../Source/MidiMessageReceiver.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling MidiMessageReceiver.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/ZoneAreaAnimator_cca8cee9.o: ../../Source/ZoneAreaAnimator.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling ZoneAreaAnimator.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/AsioSerial_7a9dfc75.o: ../../Source/AsioSerial.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling AsioSerial.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/Serial_5af037d.o: ../../Source/Serial.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling Serial.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/PresetReader_165d1067.o: ../../../BlipBox/firmware/PresetReader.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling PresetReader.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/MidiMessageReader_cccd780e.o: ../../../BlipBox/firmware/MidiMessageReader.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling MidiMessageReader.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/operators_caa0a374.o: ../../../BlipBox/firmware/operators.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling operators.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/spi_bitbang_66707ed7.o: ../../../BlipBox/firmware/spi_bitbang.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling spi_bitbang.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/ControlVoltageAction_1c1da3c.o: ../../../BlipBox/firmware/ControlVoltageAction.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling ControlVoltageAction.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/Action_8c62b41b.o: ../../../BlipBox/firmware/Action.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling Action.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/Event_a7efa41f.o: ../../../BlipBox/firmware/Event.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling Event.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/Preset_76c39c44.o: ../../../BlipBox/firmware/Preset.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling Preset.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

$(OBJDIR)/Zone_92b07a91.o: ../../../BlipBox/firmware/Zone.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling Zone.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

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

$(OBJDIR)/JuceLibraryCode_9800db7c.o: ../../JuceLibraryCode/JuceLibraryCode.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling JuceLibraryCode.cpp"
	@$(CXX) $(CXXFLAGS) -o "$@" -c "$<"

-include $(OBJECTS:%.o=%.d)
