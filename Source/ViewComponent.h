/*
  ==============================================================================

    ViewComponent.h
    Created: 9 Nov 2021 10:28:56am
    Author:  Han Chu

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "Person.h"

//==============================================================================
/*
*/
class ViewComponent  : public juce::Component
{
public:
    ViewComponent(Person* person);
    ~ViewComponent() override;

    void paint (juce::Graphics& g) override;
    void resized() override;

private:
    Person* currentPerson;
    
    juce::Label nameLabel;
    juce::Label surnameLabel;
    juce::Label genderLabel;
    juce::Label dateOfBirthLabel;
    juce::Label fiscalCodeLabel;
    
    juce::Label nameInput;
    juce::Label surnameInput;
    juce::Label genderInput;
    juce::Label dateOfBirthInput;
    juce::Label fiscalCodeInput;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ViewComponent)
};
