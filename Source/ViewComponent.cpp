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
ViewComponent::ViewComponent(Person* person) : currentPerson(person)
{
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
    
    std::function<void(juce::Label*, juce::String)> setText = [] (juce::Label* label, juce::String text) {
        label->setText(text, juce::dontSendNotification);
    };
    setText(&nameLabel, "Name: ");
    setText(&surnameLabel, "Surname: ");
    setText(&genderLabel, "Gender: ");
    setText(&dateOfBirthLabel, "Date of birth (age): ");
    setText(&fiscalCodeLabel, "Fiscal code: ");
    
    setText(&nameInput, person->getName());
    setText(&surnameInput, person->getSurname());
    setText(&genderInput, gender);
    setText(&dateOfBirthInput, person->getDateOfBirth().toString(true, false) + " (" + juce::String(person->getAge()) + ")");
    setText(&fiscalCodeInput, person->getFiscalCode());
    
    std::function<void(juce::Label*)> setWhiteText = [] (juce::Label *l) {
        l->setColour(juce::Label::textColourId, juce::Colours::white);
    };
    
    setWhiteText(&nameLabel);
    setWhiteText(&surnameLabel);
    setWhiteText(&genderLabel);
    setWhiteText(&dateOfBirthLabel);
    setWhiteText(&fiscalCodeLabel);
    setWhiteText(&nameInput);
    setWhiteText(&surnameInput);
    setWhiteText(&genderInput);
    setWhiteText(&dateOfBirthInput);
    setWhiteText(&fiscalCodeInput);
    
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
    
    std::function<void(juce::Rectangle<int>*, juce::Label*, int)> setLabel = [this, height] (juce::Rectangle<int>* workingArea, juce::Label* c, int align) {
        c->setBounds(workingArea->removeFromTop(height));
        c->setJustificationType(align);
    };
    
    keyArea.removeFromTop(margin);
    valueArea.removeFromTop(margin);
    
    setLabel(&keyArea, &nameLabel, juce::Justification::centred);
    setLabel(&keyArea, &surnameLabel, juce::Justification::centred);
    setLabel(&keyArea, &genderLabel, juce::Justification::centred);
    setLabel(&keyArea, &dateOfBirthLabel, juce::Justification::centred);
    setLabel(&keyArea, &fiscalCodeLabel, juce::Justification::centred);
    
    setLabel(&valueArea, &nameInput, juce::Justification::left);
    setLabel(&valueArea, &surnameInput, juce::Justification::left);
    setLabel(&valueArea, &genderInput, juce::Justification::left);
    setLabel(&valueArea, &dateOfBirthInput, juce::Justification::left);
    setLabel(&valueArea, &fiscalCodeInput, juce::Justification::left);

    keyArea.removeFromBottom(margin);
    valueArea.removeFromBottom(margin);
}
