/*
  ==============================================================================

    HeaderComponent.cpp
    Created: 10 Nov 2021 5:39:48pm
    Author:  Han Chu

  ==============================================================================
*/

#include <JuceHeader.h>
#include "HeaderComponent.h"

//==============================================================================
HeaderComponent::HeaderComponent() {}

HeaderComponent::~HeaderComponent() {}

void HeaderComponent::paint(juce::Graphics& g) {
    g.fillAll(juce::Colours::darkgrey);
    g.setColour(juce::Colours::white);
}

void HeaderComponent::resized() {}
