#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent() : footer(manager) {
    
    view = std::make_unique<ViewComponent>(manager.getPersonFromIndex(0));
    
    for(auto btn : footer.buttons) {
        btn->addListener(this);
    }
    
    addAndMakeVisible(header);
    addAndMakeVisible(*view);
    addAndMakeVisible(footer);
    
    setSize(1000, 700);
}

MainComponent::~MainComponent() {
    for (auto btn : footer.buttons) btn->removeListener(this);
}

//==============================================================================
void MainComponent::paint (juce::Graphics& g) {
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));
}

void MainComponent::resized() {
    juce::Rectangle<int> area = getLocalBounds();
    int headerFooterHeight = 40;

    header.setBounds(area.removeFromTop(headerFooterHeight));
    footer.setBounds(area.removeFromBottom(headerFooterHeight));
    view->setBounds(area);
}

void MainComponent::buttonClicked(juce::Button* button) {
    for (int i = 0; i < footer.buttons.size(); i++) {
        auto btn = footer.buttons.getUnchecked(i);
        if (btn == button) {
            view.reset(new ViewComponent(manager.getPersonFromIndex(i)));
            addAndMakeVisible(*view);
            resized();
            return;
        }
    }
}

