#pragma once

#include <JuceHeader.h>
#include "HeaderComponent.h"
#include "ListComponent.h"
#include "ViewComponent.h"
#include "PersonManager.h"
#include "AddPersonComponent.h"
#include "MyListener.h"

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent  : public juce::Component,
                              juce::Button::Listener,
                              juce::ChangeListener,
                              MyListener

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
    
    void addListener(MyListener* l);
    void removeListener(MyListener* l);
    void currentViewChanged(juce::String viewName);
    
private:
    //==============================================================================
    PersonManager manager;
    HeaderComponent header;
    
    std::unique_ptr<Component> currentView = nullptr;
    AddPersonComponent addPersonForm;
    
    juce::ListenerList<MyListener> listeners;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
