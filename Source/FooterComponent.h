/*
  ==============================================================================

    FooterComponent.h
    Created: 9 Nov 2021 10:26:52am
    Author:  Han Chu

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PersonManager.h"

//==============================================================================
/*
*/
class FooterComponent  : public juce::Component
{
public:
    FooterComponent(PersonManager& personManager);
    ~FooterComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;
//    juce::OwnedArray<juce::TextButton> getButtons();

    juce::OwnedArray<juce::TextButton> buttons;
private:

    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FooterComponent)
};
