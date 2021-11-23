#pragma once

#include <JuceHeader.h>
#include "HeaderComponent.h"
#include "ListComponent.h"
#include "ViewComponent.h"
#include "PersonManager.h"
#include "AddPersonComponent.h"

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent  : public juce::Component,
                              juce::Button::Listener,
                              juce::ChangeListener
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent() override;

    //==============================================================================
    void paint (juce::Graphics& g) override;
    void resized() override;
    void buttonClicked(juce::Button* button) override;
    void makeListView();
    void showAddPersonForm(bool shouldShow);
    void makeDeatilsView(Person* person);
    void changeListenerCallback(juce::ChangeBroadcaster* source) override;
    
private:
    //==============================================================================
    PersonManager manager;
    HeaderComponent header;
    
    std::unique_ptr<Component> currentView = nullptr;
    AddPersonComponent addPersonForm;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
