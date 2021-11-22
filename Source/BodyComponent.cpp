/*
  ==============================================================================

    BodyComponent.cpp
    Created: 16 Nov 2021 3:03:18pm
    Author:  Han Chu

  ==============================================================================
*/

#include "BodyComponent.h"

//==============================================================================
BodyComponent::BodyComponent(PersonManager* manager) {
    numOfElements = manager->getNumberOfPeople();
    rowHeight = 40;
    margin = 10;
    setBounds(0, 0, juce::jmin(1000, 1000), (margin * 2) + (rowHeight * numOfElements));
    
    for(int index = 0; index < numOfElements; index++) {
        juce::TextButton* btn = new juce::TextButton();
        btn->setButtonText(manager->getPersonFromIndex(index)->getFiscalCode());
        buttons.add(btn);
        addAndMakeVisible(btn);
    }
}

BodyComponent::~BodyComponent() {}

void BodyComponent::paint(juce::Graphics& g) {
    g.fillAll(juce::Colours::lightgrey);
    g.setColour(juce::Colours::black);
    g.drawText("BODY", getLocalBounds(), juce::Justification::centred);
}

void BodyComponent::resized() {
    juce::Rectangle<int> area = getLocalBounds();
    area.removeFromTop(margin);
    for(juce::TextButton* btn : buttons){
        btn->setBounds(area
                       .removeFromTop(rowHeight)
                       .reduced(margin, 0));
    }
}
