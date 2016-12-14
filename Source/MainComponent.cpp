/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#ifndef MAINCOMPONENT_H_INCLUDED
#define MAINCOMPONENT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "GmrWrapper.h"

#define DIMIN 2
#define DIMOUT 7

#define INPORT 9001
#define OUTPORT 7770
#define TARGETIP "127.0.0.1"

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainContentComponent   :
public AudioAppComponent, public Button::Listener, private OSCReceiver,
private OSCReceiver::ListenerWithOSCAddress<OSCReceiver::MessageLoopCallback> {
private:
  //=========================== OSC
  OSCSender sender;
  std::vector<float> oscInputVector;
  std::vector<float> oscOutputVector;
  int oscInPort;
  int oscOutPort;
  String oscOutIP;
  bool oscConnected;
  String gmrLabelString;
  String gmrRecordString;
  String gmrAddPhraseString;
  String gmrClearString;
  String gmrInputString;
  String gmrOutputString;

  //=========================== UI
  GroupComponent *uiGroup;
  ComboBox *labelsComboBox;
  TextButton *recordButton;
  TextButton *addPhraseButton;
  TextButton *clearButton;
  
  //=========================== XMM
  GmrWrapper *gmr;
  
public:
  //==============================================================================
  MainContentComponent() {
    setSize (200, 200);

    // specify the number of input and output channels that we want to open
    setAudioChannels (2, 2);
    
    oscInPort = INPORT;
    oscOutPort = OUTPORT;
    oscOutIP = TARGETIP;
    oscConnected = false;
    gmrLabelString = "/label";
    gmrRecordString = "/record";
    gmrAddPhraseString = "/addphrase";
    gmrClearString = "/clear";
    gmrInputString = "/input";
    gmrOutputString = "/output";
    
    oscConnect();
    
//    addAndMakeVisible(uiGroup = new GroupComponent("main group", "Main"));
//    uiGroup->addAndMakeVisible(recordButton = new TextButton(String("REC")));
//    recordButton->addListener(this);
//    uiGroup->addAndMakeVisible(addPhraseButton = new TextButton(String("ADD")));
//    addPhraseButton->addListener(this);
//    uiGroup->addAndMakeVisible(clearButton = new TextButton(String("CLEAR")));
//    clearButton->addListener(this);
//    recordButton->setBounds(0, 0, 100, 100);
//    uiGroup->setBounds(0, 0, 200, 200);
    
    gmr = new GmrWrapper(DIMIN, DIMOUT);
    oscInputVector.resize(DIMIN + DIMOUT);
    oscOutputVector.resize(DIMOUT);
  }

  ~MainContentComponent() {
    shutdownAudio();
    disconnect();
    sender.disconnect();
    
//    delete recordButton;
//    delete addPhraseButton;
//    delete clearButton;
//    delete uiGroup;
    delete gmr;
  }

  //==============================================================================
  void prepareToPlay (int samplesPerBlockExpected, double sampleRate) override {
    // This function will be called when the audio device is started, or when
    // its settings (i.e. sample rate, block size, etc) are changed.

    // You can use this function to initialise any resources you might need,
    // but be careful - it will be called on the audio thread, not the GUI thread.

    // For more details, see the help for AudioProcessor::prepareToPlay()
  }

  void getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill) override {
    // Your audio-processing code goes here!

    // For more details, see the help for AudioProcessor::getNextAudioBlock()

    // Right now we are not producing any data, in which case we need to clear the buffer
    // (to prevent the output of random noise)
    bufferToFill.clearActiveBufferRegion();
  }

  void releaseResources() override {
    // This will be called when the audio device stops, or when it is being
    // restarted due to a setting change.

    // For more details, see the help for AudioProcessor::releaseResources()
  }

  //==============================================================================
  void paint (Graphics& g) override {
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (Colours::black);

    // You can add your drawing code here!
  }

  void resized() override {
    // This is called when the MainContentComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
  }


private:
  //==============================================================================

  // Your private member variables go here...

  // OSC
  void oscMessageReceived (const OSCMessage& message) override
  {
    if (oscConnected) {
      String inputAddress = message.getAddressPattern().toString();
      
      if (inputAddress == this->gmrInputString) {
        int size = message.size();

        if (size > oscInputVector.size()) {
          size = oscInputVector.size();
        }
        
        for (int i = 0; i < size; ++i) {
          if (message[i].isFloat32()) {
            this->oscInputVector[i] = message[i].getFloat32();
          }
        }
        
        if (size < oscInputVector.size()) {
          for (int i = size; i < oscInputVector.size(); ++i) {
            this->oscInputVector[i] = 0.;
          }
        }
        
        oscOutputVector = this->gmr->setInput(this->oscInputVector);
        if (oscOutputVector.size() > 0) {
          sendOscFrame(this->gmr->setInput(this->oscInputVector));
        }
        
      } else if (inputAddress == this->gmrLabelString) {
        
        if (message.size() > 0 && message[0].isString()) {
          std::cout << "received label : " << message[0].getString() << std::endl;
          this->gmr->setLabel(message[0].getString());
        }
        
      } else if (inputAddress == this->gmrRecordString) {
        
        std::cout << "received record message" << std::endl;
        if (message.size() > 0 && message[0].isInt32()) {
          this->gmr->record(message[0].getInt32() != 0);
        }
        
      } else if (inputAddress == this->gmrAddPhraseString) {
        
        std::cout << "received add message" << std::endl;
        this->gmr->add();

      } else if (inputAddress == this->gmrClearString) {
        
        std::cout << "received clear message" << std::endl;
        this->gmr->clear();
        
      }
    } else {
      std::cout << "not connected ?" << std::endl;
    }
  }
  
  void sendOscFrame(std::vector<float> outFrame) {
    OSCMessage mess(this->gmrOutputString);
    for (int i = 0; i < outFrame.size(); ++i) {
      mess.addFloat32(outFrame[i]);
    }
    
    if (oscConnected) {
      if (!sender.send(mess)) {
        showConnectionErrorMessage("Error: could not send OSC message.");
      }
    }
  }

  void oscConnect() {
    if (!connect(oscInPort)) {
      showConnectionErrorMessage("Error: could not connect to UDP port " + String(oscInPort));
    } else {
      addListener (this, this->gmrLabelString);
      addListener (this, this->gmrRecordString);
      addListener (this, this->gmrAddPhraseString);
      addListener (this, this->gmrClearString);
      addListener (this, this->gmrInputString);
      addListener (this, this->gmrOutputString);
      
      if(!sender.connect(oscOutIP, oscOutPort)) {
        showConnectionErrorMessage("Error: could not connect to UDP port " + String(oscOutPort));
      } else {
        oscConnected = true;
      }
    }
  }
  
  void showConnectionErrorMessage(const String& messageText) {
    AlertWindow::showMessageBoxAsync(AlertWindow::WarningIcon, "OSC Connection error", messageText, "OK");
  }
  
  // UI
  void 	buttonClicked(Button *button)  override {
//    if (button == recordButton) {
//      
//    } else if (button == addPhraseButton) {
//      
//    } else if (button == clearButton) {
//      
//    }
  }
  
  void 	buttonStateChanged(Button *) override {}

  JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};


// (This function is called by the app startup code to create our main component)
Component* createMainContentComponent()     { return new MainContentComponent(); }


#endif  // MAINCOMPONENT_H_INCLUDED
