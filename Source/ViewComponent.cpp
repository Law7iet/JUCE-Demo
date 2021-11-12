/*
  ==============================================================================

    ViewComponent.cpp
    Created: 9 Nov 2021 10:28:56am
    Author:  Han Chu

  ==============================================================================
*/

#include <JuceHeader.h>
#include "ViewComponent.h"

//==============================================================================
ViewComponent::ViewComponent(Person* person) : currentPerson(person) {
    nameLabel.setText("Name: ", juce::dontSendNotification);
    surnameLabel.setText("Surname: ", juce::dontSendNotification);
    genderLabel.setText("Gender: ", juce::dontSendNotification);
    dateOfBirthLabel.setText("Date of birth (age): ", juce::dontSendNotification);
    fiscalCodeLabel.setText("Fiscal code: ", juce::dontSendNotification);
    
    juce::String gender;
    switch(person->getGender()) {
        case Gender::male:
            gender = "male";
            break;
        case Gender::female:
            gender = "female";
            break;
        case Gender::other:
            gender = "other";
            break;
        default:
            gender = "";
    }
    
    nameInput.setText(person->getName(), juce::dontSendNotification);
    surnameInput.setText(person->getSurname(), juce::dontSendNotification);
    genderInput.setText(gender, juce::dontSendNotification);
    dateOfBirthInput.setText(person->getDateOfBirth().toString(true, false) + " (" + juce::String(person->getAge()) + ")", juce::dontSendNotification);
    fiscalCodeInput.setText(person->getFiscalCode(), juce::dontSendNotification);
    
    nameLabel.setColour(juce::Label::textColourId, juce::Colours::white);
    surnameLabel.setColour(juce::Label::textColourId, juce::Colours::white);
    genderLabel.setColour(juce::Label::textColourId, juce::Colours::white);
    dateOfBirthLabel.setColour(juce::Label::textColourId, juce::Colours::white);
    fiscalCodeLabel.setColour(juce::Label::textColourId, juce::Colours::white);
    nameInput.setColour(juce::Label::textColourId, juce::Colours::white);
    surnameInput.setColour(juce::Label::textColourId, juce::Colours::white);
    genderInput.setColour(juce::Label::textColourId, juce::Colours::white);
    dateOfBirthInput.setColour(juce::Label::textColourId, juce::Colours::white);
    fiscalCodeInput.setColour(juce::Label::textColourId, juce::Colours::white);
        
    addAndMakeVisible(nameLabel);
    addAndMakeVisible(surnameLabel);
    addAndMakeVisible(genderLabel);
    addAndMakeVisible(dateOfBirthLabel);
    addAndMakeVisible(fiscalCodeLabel);
    addAndMakeVisible(nameInput);
    addAndMakeVisible(surnameInput);
    addAndMakeVisible(genderInput);
    addAndMakeVisible(dateOfBirthInput);
    addAndMakeVisible(fiscalCodeInput);
}

ViewComponent::~ViewComponent() {}

void ViewComponent::paint (juce::Graphics& g) {
    g.setColour(juce::Colours::darkred);
    g.fillAll();
}

void ViewComponent::resized()
{
    auto valueArea = getLocalBounds();
    int rows = 5;
    int margin = valueArea.getHeight() / 20;
    auto height = juce::jmax((valueArea.getHeight() - margin * 2) / rows, 20);
    auto keyArea = valueArea.removeFromLeft(valueArea.getWidth() / 2);
    
//    auto setLabel = [this, height] (juce::Rectangle<int> workingArea, juce::Label c, int align) {
//        c.setBounds(workingArea.removeFromTop(height));
//        c.setJustificationType(align);
//    };
//
//    setLabel(keyArea, nameLabel, juce::Justification::centred);
//    setLabel(valueArea, nameInput, juce::Justification::left);
    
    keyArea.removeFromTop(margin);
    valueArea.removeFromTop(margin);
    
    nameLabel.setBounds(keyArea.removeFromTop(height));
    nameLabel.setJustificationType(juce::Justification::centred);
    surnameLabel.setBounds(keyArea.removeFromTop(height));
    surnameLabel.setJustificationType(juce::Justification::centred);
    genderLabel.setBounds(keyArea.removeFromTop(height));
    genderLabel.setJustificationType(juce::Justification::centred);
    dateOfBirthLabel.setBounds(keyArea.removeFromTop(height));
    dateOfBirthLabel.setJustificationType(juce::Justification::centred);
    fiscalCodeLabel.setBounds(keyArea.removeFromTop(height));
    fiscalCodeLabel.setJustificationType(juce::Justification::centred);
    
    nameInput.setBounds(valueArea.removeFromTop(height));
    nameInput.setJustificationType(juce::Justification::left);
    surnameInput.setBounds(valueArea.removeFromTop(height));
    surnameInput.setJustificationType(juce::Justification::left);
    genderInput.setBounds(valueArea.removeFromTop(height));
    genderInput.setJustificationType(juce::Justification::left);
    dateOfBirthInput.setBounds(valueArea.removeFromTop(height));
    dateOfBirthInput.setJustificationType(juce::Justification::left);
    fiscalCodeInput.setBounds(valueArea.removeFromTop(height));
    fiscalCodeInput.setJustificationType(juce::Justification::left);
    
    keyArea.removeFromBottom(margin);
    valueArea.removeFromBottom(margin);
    
}
