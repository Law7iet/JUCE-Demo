#pragma once

#include <JuceHeader.h>
#include "HeaderComponent.h"
#include "ViewComponent.h"
#include "FooterComponent.h"
#include "PersonManager.h"

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent  : public juce::Component,
                              juce::Button::Listener
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
    void buttonClicked(juce::Button* button) override;

private:
    //==============================================================================
    PersonManager manager;
    
    HeaderComponent header;
    std::unique_ptr<ViewComponent> view;
    FooterComponent footer;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
