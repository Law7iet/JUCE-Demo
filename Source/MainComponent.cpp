#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent() {
    
    makeListView();
    
    header.addButton.addListener(this);
    header.undoButton.addListener(this);
    header.saveDataButton.addListener(this);
    header.saveDataButton.setEnabled(false);
    
    addAndMakeVisible(header);
    
    setSize(800, 600);
}

MainComponent::~MainComponent() {
    header.addButton.removeListener(this);
    header.undoButton.removeListener(this);
    header.saveDataButton.removeListener(this);

    if(auto body = dynamic_cast<ListComponent*>(currentView.get()))
    {
        body->addOrRemoveListeners(false, this);
    }

}

//==============================================================================
void MainComponent::paint (juce::Graphics& g) {
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));
}

void MainComponent::resized() {
    juce::Rectangle<int> area = getLocalBounds();
    int headerHeight = 40;

    header.setBounds(area.removeFromTop(headerHeight));    
    if(currentView.get() != nullptr)
    {
        currentView.get()->setBounds(area);
        bool isListViewOn = dynamic_cast<ListComponent*>(currentView.get()) != nullptr;
        header.undoButton.setEnabled(!isListViewOn);
    }
        
}

void MainComponent::buttonClicked(juce::Button* button) {
    if(button == &header.addButton) {
        std::cout << "Hai cliccato il tasto aggiungi" << std::endl;
        makeAddView();
    } else if(button == &header.undoButton) {
        std::cout << "Hai cliccato il tasto indietro" << std::endl;
        makeListView();
    } else if(button == &header.saveDataButton) {
        std::cout << "Hai cliccato il tasto salva" << std::endl;
        if(auto tmp = dynamic_cast<AddPersonComponent*>(currentView.get()))
        {
            manager.addPerson(
                              tmp->getName(),
                              tmp->getSurname(),
                              tmp->getGender(),
                              tmp->getdateOfBirth(),
                              tmp->getfiscalCode()
                              );
        }
        makeListView();
    }
    if (currentView.get() != nullptr)
    {
        if (auto body = dynamic_cast<ListComponent*>(currentView.get()))
        {
            for (int i = 0; i < body->buttons.size(); i++)
            {
                auto b = body->buttons.getUnchecked(i);
                if (b == button)
                {
                    makeDeatilsView(manager.getPersonFromIndex(i));
                    return;
                }
            }
        }
    }
}

void MainComponent::makeListView()
{
    if(currentView.get() != nullptr)
    {
        removeChildComponent(currentView.get());
        auto tmp = dynamic_cast<ListComponent*>(currentView.get());
        if(tmp != nullptr)
        {
            tmp->addOrRemoveListeners(false, this);
        }
    }
    currentView.reset(new ListComponent(&manager));
    header.addButton.setButtonText("Aggiungi");
    header.saveDataButton.setEnabled(false);
    addAndMakeVisible(currentView.get());
    auto tmp = dynamic_cast<ListComponent*>(currentView.get());
    if(tmp != nullptr)
    {
        tmp->addOrRemoveListeners(true, this);
    }
    resized();
}

void MainComponent::makeAddView()
{
    if(currentView.get() != nullptr)
    {
        removeChildComponent(currentView.get());
    }
    currentView.reset(new AddPersonComponent());
    header.addButton.setButtonText("Pulisci");
    header.saveDataButton.setEnabled(true);
    addAndMakeVisible(currentView.get());
    resized();
}

void MainComponent::makeDeatilsView(Person* person)
{
    if(currentView.get() != nullptr)
    {
        removeChildComponent(currentView.get());
    }
    currentView.reset(new ViewComponent(person));
    header.saveDataButton.setEnabled(false);
    addAndMakeVisible(currentView.get());
    resized();
}
