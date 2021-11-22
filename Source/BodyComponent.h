/*
  ==============================================================================

    BodyComponent.h
    Created: 16 Nov 2021 3:03:18pm
    Author:  Han Chu

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PersonManager.h"

//==============================================================================
/*
*/
class BodyComponent  : public juce::Component
{
public:
    BodyComponent(PersonManager* manager);
    ~BodyComponent() override;

    void paint (juce::Graphics& g) override;
    void resized() override;

    juce::OwnedArray<juce::TextButton> buttons;
    
private:
    int numOfElements;
    int rowHeight;
    int margin;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (BodyComponent)
};
