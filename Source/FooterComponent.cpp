/*
  ==============================================================================

    FooterComponent.cpp
    Created: 9 Nov 2021 10:26:52am
    Author:  Han Chu

  ==============================================================================
*/

#include <JuceHeader.h>
#include "FooterComponent.h"

//==============================================================================
FooterComponent::FooterComponent(PersonManager& personManager) {
    for(int index = 0; index < personManager.getNumberOfPeople(); index++) {
        juce::TextButton* button = new juce::TextButton();
        button->setButtonText(juce::String(index + 1));
        button->setColour(juce::TextButton::buttonColourId, juce::Colours::red);
        addAndMakeVisible(button);
        
        buttons.add(button);
    }
}

FooterComponent::~FooterComponent() {}

void FooterComponent::paint (juce::Graphics& g) {
    g.setColour(juce::Colours::darkgrey);
    g.fillAll();
}

void FooterComponent::resized() {
    juce::Rectangle<int> area = getLocalBounds();
    int margin = 10;
    int width = area.getWidth() / buttons.size();
    
    for(auto* button : buttons) {
        auto workingArea = area.removeFromLeft(width);
        button->setBounds(workingArea.reduced(margin, margin));
    }
}

//juce::OwnedArray<juce::TextButton> FooterComponent::getButtons() {
//    return buttons;
//}
