#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent() {
    
    makeListView();
    
    header.addButton.addListener(this);
    header.undoButton.addListener(this);
    header.saveDataButton.addListener(this);
    header.saveDataButton.setEnabled(false);
    
    manager.addChangeListener(this);
    
    addAndMakeVisible(header);
    
    setSize(800, 600);
}

MainComponent::~MainComponent() {
    header.addButton.removeListener(this);
    header.undoButton.removeListener(this);
    header.saveDataButton.removeListener(this);
    
    
    manager.removeChangeListener(this);
    if(auto body = dynamic_cast<ListComponent*>(currentView.get()))
    {
        body->addOrRemoveListeners(false, this);
    }
}

//==============================================================================
void MainComponent::paint (juce::Graphics& g) 
{
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));
    
}

void MainComponent::resized() {
    juce::Rectangle<int> area = getLocalBounds();
    int headerHeight = 40;

    header.setBounds(area.removeFromTop(headerHeight));    
    if(currentView.get() != nullptr)
    {
        currentView.get()->setBounds(area);
    }  

    if (isParentOf(&addPersonForm))
    {
        addPersonForm.setBounds(area);
    }
}

void MainComponent::buttonClicked(juce::Button* button) {
    if(button == &header.addButton) {
        std::cout << "Hai cliccato il tasto aggiungi" << std::endl;
        showAddPersonForm(true);
    } else if(button == &header.undoButton) {
        std::cout << "Hai cliccato il tasto indietro" << std::endl;
        makeListView();
    } else if(button == &header.saveDataButton) {
        std::cout << "Hai cliccato il tasto salva" << std::endl;
        manager.addPerson(
            addPersonForm.getName(),
            addPersonForm.getSurname(),
            addPersonForm.getGender(),
            addPersonForm.getdateOfBirth(),
            addPersonForm.getfiscalCode()
        );
        showAddPersonForm(false);
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
    header.undoButton.setEnabled(false);
    addAndMakeVisible(currentView.get());
    auto tmp = dynamic_cast<ListComponent*>(currentView.get());
    if(tmp != nullptr)
    {
        tmp->addOrRemoveListeners(true, this);
    }
    
    showAddPersonForm(false);
}

void MainComponent::showAddPersonForm(bool shouldShow)
{
    if (shouldShow)
    {
        addAndMakeVisible(addPersonForm);
        header.addButton.setButtonText("Pulisci");
        header.saveDataButton.setEnabled(true);
        header.undoButton.setEnabled(true);
    }
    else
    {
        removeChildComponent(&addPersonForm);
    }

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
    header.undoButton.setEnabled(true);
    addAndMakeVisible(currentView.get());
    
    showAddPersonForm(false);
}

void MainComponent::changeListenerCallback(juce::ChangeBroadcaster* source)
{
    if (source == &manager)
    {
        auto tmp = dynamic_cast<ListComponent*>(currentView.get());
        if (tmp != nullptr)
        {
            makeListView();
        }
    }
}

void MainComponent::addListener(MyListener* l)
{
    listeners.add(l);
}

void MainComponent::removeListener(MyListener* l)
{
    listeners.remove(l);
}


void MainComponent::currentViewChanged(juce::String viewName)
{
    std::cout << viewName << std::endl;
}
