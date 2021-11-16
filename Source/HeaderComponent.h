/*
  ==============================================================================

    HeaderComponent.h
    Created: 10 Nov 2021 5:39:48pm
    Author:  Han Chu

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class HeaderComponent  : public juce::Component
{
public:
    HeaderComponent();
    ~HeaderComponent() override;

    void paint (juce::Graphics& g) override;
    void resized() override;

private:
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (HeaderComponent)
};
