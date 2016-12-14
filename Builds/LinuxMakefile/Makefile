# Automatically generated makefile, created by the Projucer
# Don't edit this file! Your changes will be overwritten when you re-save the Projucer project!

# (this disables dependency generation if multiple architectures are set)
DEPFLAGS := $(if $(word 2, $(TARGET_ARCH)), , -MMD)

ifndef STRIP
  STRIP=strip
endif

ifndef AR
  AR=ar
endif

ifndef CONFIG
  CONFIG=Debug
endif

ifeq ($(CONFIG),Debug)
  JUCE_BINDIR := build
  JUCE_LIBDIR := build
  JUCE_OBJDIR := build/intermediate/Debug
  JUCE_OUTDIR := build

  ifeq ($(TARGET_ARCH),)
    TARGET_ARCH := -march=native
  endif

  JUCE_CPPFLAGS := $(DEPFLAGS) -DLINUX=1 -DDEBUG=1 -D_DEBUG=1 -DJUCER_LINUX_MAKE_6D53C8B4=1 -DJUCE_APP_VERSION=1.0.0 -DJUCE_APP_VERSION_HEX=0x10000 $(shell pkg-config --cflags alsa freetype2 libcurl x11 xext xinerama) -pthread -I../../JuceLibraryCode -I../../../../modules
  JUCE_CFLAGS += $(CFLAGS) $(JUCE_CPPFLAGS) $(TARGET_ARCH) -g -ggdb -O0
  JUCE_CXXFLAGS += $(CXXFLAGS) $(JUCE_CFLAGS) -std=c++11
  JUCE_LDFLAGS += $(LDFLAGS) $(TARGET_ARCH) -L$(JUCE_BINDIR) -L$(JUCE_LIBDIR) $(shell pkg-config --libs alsa freetype2 libcurl x11 xext xinerama) -lGL -ldl -lpthread -lrt 

  TARGET := XMMFM
  BLDCMD = $(CXX) -o $(JUCE_OUTDIR)/$(TARGET) $(OBJECTS) $(JUCE_LDFLAGS) $(RESOURCES) $(TARGET_ARCH)
  CLEANCMD = rm -rf $(JUCE_OUTDIR)/$(TARGET) $(JUCE_OBJDIR)
endif

ifeq ($(CONFIG),Release)
  JUCE_BINDIR := build
  JUCE_LIBDIR := build
  JUCE_OBJDIR := build/intermediate/Release
  JUCE_OUTDIR := build

  ifeq ($(TARGET_ARCH),)
    TARGET_ARCH := -march=native
  endif

  JUCE_CPPFLAGS := $(DEPFLAGS) -DLINUX=1 -DNDEBUG=1 -DJUCER_LINUX_MAKE_6D53C8B4=1 -DJUCE_APP_VERSION=1.0.0 -DJUCE_APP_VERSION_HEX=0x10000 $(shell pkg-config --cflags alsa freetype2 libcurl x11 xext xinerama) -pthread -I../../JuceLibraryCode -I../../../../modules
  JUCE_CFLAGS += $(CFLAGS) $(JUCE_CPPFLAGS) $(TARGET_ARCH) -O3
  JUCE_CXXFLAGS += $(CXXFLAGS) $(JUCE_CFLAGS) -std=c++11
  JUCE_LDFLAGS += $(LDFLAGS) $(TARGET_ARCH) -L$(JUCE_BINDIR) -L$(JUCE_LIBDIR) -fvisibility=hidden $(shell pkg-config --libs alsa freetype2 libcurl x11 xext xinerama) -lGL -ldl -lpthread -lrt 

  TARGET := XMMFM
  BLDCMD = $(CXX) -o $(JUCE_OUTDIR)/$(TARGET) $(OBJECTS) $(JUCE_LDFLAGS) $(RESOURCES) $(TARGET_ARCH)
  CLEANCMD = rm -rf $(JUCE_OUTDIR)/$(TARGET) $(JUCE_OBJDIR)
endif

OBJECTS := \
  $(JUCE_OBJDIR)/json_reader_39c924c7.o \
  $(JUCE_OBJDIR)/json_value_373b4af7.o \
  $(JUCE_OBJDIR)/json_writer_141f1877.o \
  $(JUCE_OBJDIR)/xmmAttribute_6d960a15.o \
  $(JUCE_OBJDIR)/xmmJson_89ff5659.o \
  $(JUCE_OBJDIR)/xmmGaussianDistribution_41477a44.o \
  $(JUCE_OBJDIR)/xmmModelSharedParameters_b1c304c3.o \
  $(JUCE_OBJDIR)/xmmModelSingleClass_69d76c06.o \
  $(JUCE_OBJDIR)/xmmPhrase_65c6c0f7.o \
  $(JUCE_OBJDIR)/xmmTrainingSet_bdcd4d74.o \
  $(JUCE_OBJDIR)/xmmGmm_df5a0f89.o \
  $(JUCE_OBJDIR)/xmmGmmParameters_c0389f93.o \
  $(JUCE_OBJDIR)/xmmGmmSingleClass_390e0b51.o \
  $(JUCE_OBJDIR)/xmmHierarchicalHmm_5c072ea0.o \
  $(JUCE_OBJDIR)/xmmHmmParameters_ce40c73.o \
  $(JUCE_OBJDIR)/xmmHmmSingleClass_81d03a71.o \
  $(JUCE_OBJDIR)/xmmKMeans_dae35481.o \
  $(JUCE_OBJDIR)/xmmKMeansParameters_a18a0e8b.o \
  $(JUCE_OBJDIR)/MainComponent_a6ffb4a5.o \
  $(JUCE_OBJDIR)/Main_90ebc5c2.o \
  $(JUCE_OBJDIR)/juce_audio_basics_6b797ca1.o \
  $(JUCE_OBJDIR)/juce_audio_devices_a742c38b.o \
  $(JUCE_OBJDIR)/juce_audio_formats_5a29c68a.o \
  $(JUCE_OBJDIR)/juce_audio_processors_dea3173d.o \
  $(JUCE_OBJDIR)/juce_audio_utils_c7eb679f.o \
  $(JUCE_OBJDIR)/juce_core_75b14332.o \
  $(JUCE_OBJDIR)/juce_cryptography_6de2ebff.o \
  $(JUCE_OBJDIR)/juce_data_structures_72d3da2c.o \
  $(JUCE_OBJDIR)/juce_events_d2be882c.o \
  $(JUCE_OBJDIR)/juce_graphics_9c18891e.o \
  $(JUCE_OBJDIR)/juce_gui_basics_8a6da59c.o \
  $(JUCE_OBJDIR)/juce_gui_extra_4a026f23.o \
  $(JUCE_OBJDIR)/juce_opengl_cd70b4c2.o \
  $(JUCE_OBJDIR)/juce_osc_be4cee16.o \
  $(JUCE_OBJDIR)/juce_video_f128c512.o \

.PHONY: clean

$(JUCE_OUTDIR)/$(TARGET): check-pkg-config $(OBJECTS) $(RESOURCES)
	@echo Linking JUCE-XMM-example-GMR-OSC
	-@mkdir -p $(JUCE_BINDIR)
	-@mkdir -p $(JUCE_LIBDIR)
	-@mkdir -p $(JUCE_OUTDIR)
	@$(BLDCMD)

check-pkg-config:
	@command -v pkg-config >/dev/null 2>&1 || { echo >&2 "pkg-config not installed. Please, install it."; exit 1; }
	@pkg-config --print-errors alsa freetype2 libcurl x11 xext xinerama

clean:
	@echo Cleaning JUCE-XMM-example-GMR-OSC
	@$(CLEANCMD)

strip:
	@echo Stripping JUCE-XMM-example-GMR-OSC
	-@$(STRIP) --strip-unneeded $(JUCE_OUTDIR)/$(TARGET)

$(JUCE_OBJDIR)/json_reader_39c924c7.o: ../../Dependencies/xmm/dependencies/jsoncpp/src/json_reader.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling json_reader.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/json_value_373b4af7.o: ../../Dependencies/xmm/dependencies/jsoncpp/src/json_value.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling json_value.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/json_writer_141f1877.o: ../../Dependencies/xmm/dependencies/jsoncpp/src/json_writer.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling json_writer.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/xmmAttribute_6d960a15.o: ../../Dependencies/xmm/src/core/common/xmmAttribute.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling xmmAttribute.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/xmmJson_89ff5659.o: ../../Dependencies/xmm/src/core/common/xmmJson.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling xmmJson.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/xmmGaussianDistribution_41477a44.o: ../../Dependencies/xmm/src/core/distributions/xmmGaussianDistribution.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling xmmGaussianDistribution.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/xmmModelSharedParameters_b1c304c3.o: ../../Dependencies/xmm/src/core/model/xmmModelSharedParameters.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling xmmModelSharedParameters.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/xmmModelSingleClass_69d76c06.o: ../../Dependencies/xmm/src/core/model/xmmModelSingleClass.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling xmmModelSingleClass.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/xmmPhrase_65c6c0f7.o: ../../Dependencies/xmm/src/core/trainingset/xmmPhrase.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling xmmPhrase.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/xmmTrainingSet_bdcd4d74.o: ../../Dependencies/xmm/src/core/trainingset/xmmTrainingSet.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling xmmTrainingSet.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/xmmGmm_df5a0f89.o: ../../Dependencies/xmm/src/models/gmm/xmmGmm.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling xmmGmm.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/xmmGmmParameters_c0389f93.o: ../../Dependencies/xmm/src/models/gmm/xmmGmmParameters.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling xmmGmmParameters.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/xmmGmmSingleClass_390e0b51.o: ../../Dependencies/xmm/src/models/gmm/xmmGmmSingleClass.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling xmmGmmSingleClass.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/xmmHierarchicalHmm_5c072ea0.o: ../../Dependencies/xmm/src/models/hmm/xmmHierarchicalHmm.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling xmmHierarchicalHmm.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/xmmHmmParameters_ce40c73.o: ../../Dependencies/xmm/src/models/hmm/xmmHmmParameters.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling xmmHmmParameters.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/xmmHmmSingleClass_81d03a71.o: ../../Dependencies/xmm/src/models/hmm/xmmHmmSingleClass.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling xmmHmmSingleClass.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/xmmKMeans_dae35481.o: ../../Dependencies/xmm/src/models/kmeans/xmmKMeans.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling xmmKMeans.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/xmmKMeansParameters_a18a0e8b.o: ../../Dependencies/xmm/src/models/kmeans/xmmKMeansParameters.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling xmmKMeansParameters.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/MainComponent_a6ffb4a5.o: ../../Source/MainComponent.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling MainComponent.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/Main_90ebc5c2.o: ../../Source/Main.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling Main.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/juce_audio_basics_6b797ca1.o: ../../JuceLibraryCode/juce_audio_basics.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling juce_audio_basics.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/juce_audio_devices_a742c38b.o: ../../JuceLibraryCode/juce_audio_devices.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling juce_audio_devices.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/juce_audio_formats_5a29c68a.o: ../../JuceLibraryCode/juce_audio_formats.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling juce_audio_formats.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/juce_audio_processors_dea3173d.o: ../../JuceLibraryCode/juce_audio_processors.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling juce_audio_processors.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/juce_audio_utils_c7eb679f.o: ../../JuceLibraryCode/juce_audio_utils.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling juce_audio_utils.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/juce_core_75b14332.o: ../../JuceLibraryCode/juce_core.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling juce_core.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/juce_cryptography_6de2ebff.o: ../../JuceLibraryCode/juce_cryptography.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling juce_cryptography.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/juce_data_structures_72d3da2c.o: ../../JuceLibraryCode/juce_data_structures.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling juce_data_structures.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/juce_events_d2be882c.o: ../../JuceLibraryCode/juce_events.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling juce_events.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/juce_graphics_9c18891e.o: ../../JuceLibraryCode/juce_graphics.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling juce_graphics.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/juce_gui_basics_8a6da59c.o: ../../JuceLibraryCode/juce_gui_basics.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling juce_gui_basics.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/juce_gui_extra_4a026f23.o: ../../JuceLibraryCode/juce_gui_extra.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling juce_gui_extra.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/juce_opengl_cd70b4c2.o: ../../JuceLibraryCode/juce_opengl.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling juce_opengl.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/juce_osc_be4cee16.o: ../../JuceLibraryCode/juce_osc.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling juce_osc.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/juce_video_f128c512.o: ../../JuceLibraryCode/juce_video.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling juce_video.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

-include $(OBJECTS:%.o=%.d)
