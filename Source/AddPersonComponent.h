/*
  ==============================================================================

    AddPersonComponent.h
    Created: 18 Nov 2021 4:02:36pm
    Author:  Han Chu

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "Gender.h"

//==============================================================================
/*
*/
class AddPersonComponent  : public juce::Component
{
public:
    AddPersonComponent();
    ~AddPersonComponent() override;

    void paint (juce::Graphics& g) override;
    void resized() override;
    juce::String getName();
    juce::String getSurname();
    Gender getGender();
    juce::Time getdateOfBirth();
    juce::String getfiscalCode();

private:
    juce::Label nameLabel;
    juce::Label surnameLabel;
    juce::Label genderLabel;
    juce::Label dateOfBirthLabel;
    juce::Label fiscalCodeLabel;
    
    juce::TextEditor nameInput;
    juce::TextEditor surnameInput;
    juce::ComboBox genderInput;
    juce::TextEditor dateOfBirthInput;
    juce::TextEditor fiscalCodeInput;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AddPersonComponent)
};
