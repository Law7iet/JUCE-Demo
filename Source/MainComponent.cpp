#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent() {
    
    body = std::make_unique<BodyComponent>(&manager);
    addAndMakeVisible(body.get());
    
    header.addButton.addListener(this);
    header.undoButton.addListener(this);
    header.saveDataButton.addListener(this);
    header.saveDataButton.setEnabled(false);
    
    addAndMakeVisible(header);
    addAndMakeVisible(body.get());
    
    setSize(800, 600);
}

MainComponent::~MainComponent() {
    header.addButton.removeListener(this);
    header.undoButton.removeListener(this);
    header.saveDataButton.removeListener(this);
}

//==============================================================================
void MainComponent::paint (juce::Graphics& g) {
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));
}

void MainComponent::resized() {
    juce::Rectangle<int> area = getLocalBounds();
    int headerHeight = 40;

    header.setBounds(area.removeFromTop(headerHeight));    
    if(body != nullptr) {
        body->setBounds(area);
        header.undoButton.setEnabled(false);
    } else {
        header.undoButton.setEnabled(true);
    }
    if(addView != nullptr) {
        addView->setBounds(area);
    }
        
}

void MainComponent::buttonClicked(juce::Button* button) {
    if(button == &header.addButton) {
        std::cout << "Hai cliccato il tasto aggiungi" << std::endl;

        body.reset();
        header.addButton.setButtonText("Pulisci");
        header.saveDataButton.setEnabled(true);
        addView = std::make_unique<AddPersonComponent>();
        addAndMakeVisible(addView.get());
        
        resized();
        
    } else if(button == &header.undoButton) {
        std::cout << "Hai cliccato il tasto indietro" << std::endl;
        
        addView.reset();
        header.addButton.setButtonText("Aggiungi");
        header.saveDataButton.setEnabled(false);
        body = std::make_unique<BodyComponent>(&manager);
        addAndMakeVisible(body.get());
        resized();
        
    } else if(button == &header.saveDataButton) {
        std::cout << "Hai cliccato il tasto salva" << std::endl;
        
        manager.addPerson(
                          addView->getName(),
                          addView->getSurname(),
                          addView->getGender(),
                          addView->getdateOfBirth(),
                          addView->getfiscalCode()
                          );
        
        addView.reset();
        header.addButton.setButtonText("Aggiungi");
        header.saveDataButton.setEnabled(false);
        body = std::make_unique<BodyComponent>(&manager);
        addAndMakeVisible(body.get());
        resized();
    }
}

