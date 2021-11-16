#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent() {
    
    addAndMakeVisible(header);
    addAndMakeVisible(body);
    
    undoButton.setButtonText("Indietro");
    addAndMakeVisible(undoButton);
    
    loadDataButton.setButtonText("Carica");
    addAndMakeVisible(loadDataButton);
    
    saveDataButton.setButtonText("Salva");
    addAndMakeVisible(saveDataButton);
    
    setSize(800, 600);
}

MainComponent::~MainComponent() {}

//==============================================================================
void MainComponent::paint (juce::Graphics& g) {
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));
}

void MainComponent::resized() {
    juce::Rectangle<int> area = getLocalBounds();
    int headerHeight = 40;
    int buttonWidth = 100;
    int buttonMargin = 10;

    auto headerArea = area.removeFromTop(headerHeight);
    header.setBounds(headerArea);
    undoButton.setBounds((headerArea.removeFromLeft(buttonWidth)).reduced(buttonMargin));
    loadDataButton.setBounds((headerArea.removeFromRight(buttonWidth)).reduced(buttonMargin));
    saveDataButton.setBounds((headerArea.removeFromRight(buttonWidth)).reduced(buttonMargin));
    
    body.setBounds(area);
}

void MainComponent::buttonClicked(juce::Button* button) {}

