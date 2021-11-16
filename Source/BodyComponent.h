/*
  ==============================================================================

    BodyComponent.h
    Created: 16 Nov 2021 3:03:18pm
    Author:  Han Chu

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class BodyComponent  : public juce::Component
{
public:
    BodyComponent();
    ~BodyComponent() override;

    void paint (juce::Graphics& g) override;
    void resized() override;
    void loadData();
    
    // Funzioni da implementare quando si vuole usare TableListBox

private:
//    juce::TableListBox table  { {}, this };
//    juce::Font font           { 20.0f };
//    
//    std::unique_ptr<juce::XmlElement> data;
//    juce::XmlElement* columnList = nullptr;
//    juce::XmlElement* dataList = nullptr;
//    
//    int numRows = 0;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (BodyComponent)
};
