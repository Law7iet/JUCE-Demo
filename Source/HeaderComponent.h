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
class HeaderComponent  : public juce::Component,
                                juce::FilenameComponentListener
{
public:
    HeaderComponent();
    ~HeaderComponent() override;

    void paint (juce::Graphics& g) override;
    void resized() override;
    void filenameComponentChanged(juce::FilenameComponent* fileComponentThatHasChanged) override;

    // Public attributes ------------------------------------------------------
    
    juce::TextButton addButton;
    juce::TextButton undoButton;
    juce::TextButton saveDataButton;
    std::unique_ptr<juce::FilenameComponent> loadDataComponent;
    
private:
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (HeaderComponent)
};
