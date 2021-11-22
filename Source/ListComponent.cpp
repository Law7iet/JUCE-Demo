/*
  ==============================================================================

    BodyComponent.cpp
    Created: 16 Nov 2021 3:03:18pm
    Author:  Han Chu

  ==============================================================================
*/

#include "ListComponent.h"

//==============================================================================
ListComponent::ListComponent(PersonManager* manager) {
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

ListComponent::~ListComponent() {}

void ListComponent::paint(juce::Graphics& g) {
    g.fillAll(juce::Colours::lightgrey);
    g.setColour(juce::Colours::black);
    g.drawText("BODY", getLocalBounds(), juce::Justification::centred);
}

void ListComponent::resized() {
    juce::Rectangle<int> area = getLocalBounds();
    area.removeFromTop(margin);
    for(juce::TextButton* btn : buttons){
        btn->setBounds(area
                       .removeFromTop(rowHeight)
                       .reduced(margin, 0));
    }
}

void ListComponent::addOrRemoveListeners(bool shouldAdd, juce::Button::Listener* componentListener)
{
    for(auto b : buttons)
    {
        if(shouldAdd)
        {
            b->addListener(componentListener);
        }
        else
        {
            b->removeListener(componentListener);
        }
    }
}
