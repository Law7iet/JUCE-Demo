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
HeaderComponent::HeaderComponent() {
    undoButton.setButtonText("Indietro");
    addAndMakeVisible(undoButton);
    
    addButton.setButtonText("Aggiungi");
    addAndMakeVisible(addButton);
    
    saveDataButton.setButtonText("Salva");
    addAndMakeVisible(saveDataButton);
    
    loadDataComponent.reset(new juce::FilenameComponent ("fileComp",
                                                         {},
                                                         false,
                                                         false,
                                                         false,
                                                         {},
                                                         {},
                                                         {}));
    loadDataComponent->setBrowseButtonText("Carica");
    loadDataComponent->addListener(this);
    addAndMakeVisible(loadDataComponent.get());
}

HeaderComponent::~HeaderComponent() {}

void HeaderComponent::paint(juce::Graphics& g) {
    g.fillAll(juce::Colours::darkgrey);
    g.setColour(juce::Colours::white);
}

void HeaderComponent::resized() {
    juce::Rectangle<int> headerArea = getLocalBounds();
    int buttonWidth = 100;
    int buttonMargin = 10;
    
    undoButton.setBounds((headerArea.removeFromLeft(buttonWidth)).reduced(buttonMargin));
    addButton.setBounds((headerArea.removeFromLeft(buttonWidth)).reduced(buttonMargin));
    saveDataButton.setBounds((headerArea.removeFromLeft(buttonWidth)).reduced(buttonMargin));
    loadDataComponent->setBounds((headerArea.removeFromRight(buttonWidth * 2)).reduced(buttonMargin));
}

void HeaderComponent::filenameComponentChanged(juce::FilenameComponent* fileComponentThatHasChanged) {
    juce::String fileName = fileComponentThatHasChanged->getCurrentFile().getFileName();
    std::cout << "Hai selezionato il file: " << fileName << std::endl;
}
