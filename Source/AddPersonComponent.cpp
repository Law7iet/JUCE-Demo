/*
  ==============================================================================

    AddPersonComponent.cpp
    Created: 18 Nov 2021 4:02:36pm
    Author:  Han Chu

  ==============================================================================
*/

#include "AddPersonComponent.h"

AddPersonComponent::AddPersonComponent() {
    
    nameLabel.setText("Nome: ", juce::NotificationType::dontSendNotification);
    surnameLabel.setText("Cognome: ", juce::NotificationType::dontSendNotification);
    genderLabel.setText("Genere: ", juce::NotificationType::dontSendNotification);
    dateOfBirthLabel.setText("Data di nascita (GG/MM/AAAA): ", juce::NotificationType::dontSendNotification);
    fiscalCodeLabel.setText("Codice Fiscale: ", juce::NotificationType::dontSendNotification);
   
    addAndMakeVisible(nameLabel);
    addAndMakeVisible(surnameLabel);
    addAndMakeVisible(genderLabel);
    addAndMakeVisible(dateOfBirthLabel);
    addAndMakeVisible(fiscalCodeLabel);
  
    nameInput.setJustification(juce::Justification::verticallyCentred);
    surnameInput.setJustification(juce::Justification::verticallyCentred);
    genderInput.addItem("Male", 1);
    genderInput.addItem("Female", 2);
    genderInput.addItem("Other", 3);
    dateOfBirthInput.setJustification(juce::Justification::verticallyCentred);
    fiscalCodeInput.setJustification(juce::Justification::verticallyCentred);
    
    addAndMakeVisible(nameInput);
    addAndMakeVisible(surnameInput);
    addAndMakeVisible(genderInput);
    addAndMakeVisible(dateOfBirthInput);
    addAndMakeVisible(fiscalCodeInput);
}

AddPersonComponent::~AddPersonComponent() {}

void AddPersonComponent::paint (juce::Graphics& g) {}

void AddPersonComponent::resized() {
    int labelLength = 200;
    int labelHeight = 40;
    float topMargin = juce::jmax(10, (getHeight() - (labelHeight * 5)) / 2);
    float sideMargin = (getWidth() - (labelLength * 2)) / 2;
    juce::Rectangle<int> area;
    
    std::function<void(juce::Component* c, bool isLabel, juce::Rectangle<int>* area)> setComponent =
    [this, labelHeight, labelLength, sideMargin]
    (juce::Component* c, bool isLabel, juce::Rectangle<int>* area)
    {
        if(isLabel) {
            c->setBounds(area
                         ->removeFromTop(labelHeight)
                         .withTrimmedLeft(sideMargin)
                         .removeFromLeft(labelLength)
                         );
        } else {
            c->setBounds(area
                         ->removeFromTop(labelHeight)
                         .withTrimmedLeft(sideMargin + labelLength)
                         .removeFromLeft(labelLength)
                         );
        }
    };
    
    area = getLocalBounds();
    area.removeFromTop(topMargin);
    setComponent(&nameLabel, true, &area);
    setComponent(&surnameLabel, true, &area);
    setComponent(&genderLabel, true, &area);
    setComponent(&dateOfBirthLabel, true, &area);
    setComponent(&fiscalCodeLabel, true, &area);

    area = getLocalBounds();
    area.removeFromTop(topMargin);
    setComponent(&nameInput, false, &area);
    setComponent(&surnameInput, false, &area);
    setComponent(&genderInput, false, &area);
    setComponent(&dateOfBirthInput, false, &area);
    setComponent(&fiscalCodeInput, false, &area);

}

juce::String AddPersonComponent::getName() {
    return nameInput.getText();
}

juce::String AddPersonComponent::getSurname() {
    return surnameInput.getText();
}
Gender AddPersonComponent::getGender() {
    return static_cast<Gender>(genderInput.getSelectedId());
}

juce::Time AddPersonComponent::getdateOfBirth() {
    int day = 0;
    int month = 0;
    int year = 0;
    juce::String input = dateOfBirthInput.getText();
    if(input.length() != 10) {
        return juce::Time().getCurrentTime();
    }
    for(int index = 0; index < 10; index++) {
        if(index == 2 || index == 5) {
            if(input[index] != '/') {
                return juce::Time().getCurrentTime();
            }
        } else {
            if(input[index] < (int)'0' || input[index] > (int)'9') {
                return juce::Time().getCurrentTime();
            }
        }
    }
    day = input.substring(0, 2).getIntValue();
    month = input.substring(3, 5).getIntValue();
    year = input.substring(6, 10).getIntValue();
    
    switch(month) {
        case 1:
            if(day > 31) {
                return juce::Time().getCurrentTime();
            }
            break;
        case 2:
            if(year % 4 != 0 || day > 29) {
                return juce::Time().getCurrentTime();
            }
            break;
        case 3:
            if(day > 31) {
                return juce::Time().getCurrentTime();
            }
            break;
        case 4:
            if(day > 30) {
                return juce::Time().getCurrentTime();
            }
            break;
        case 5:
            if(day > 31) {
                return juce::Time().getCurrentTime();
            }
            break;
        case 6:
            if(day > 30) {
                return juce::Time().getCurrentTime();
            }
            break;
        case 7:
            if(day > 31) {
                return juce::Time().getCurrentTime();
            }
            break;
        case 8:
            if(day > 31) {
                return juce::Time().getCurrentTime();
            }
            break;
        case 9:
            if(day > 30) {
                return juce::Time().getCurrentTime();
            }
            break;
        case 10:
            if(day > 31) {
                return juce::Time().getCurrentTime();
            }
            break;
        case 11:
            if(day > 30) {
                return juce::Time().getCurrentTime();
            }
            break;
        case 12:
            if(day > 31) {
                return juce::Time().getCurrentTime();
            }
            break;
        default:
            return juce::Time().getCurrentTime();
    }
    return juce::Time(year, month, day, 0, 0);
}

juce::String AddPersonComponent::getfiscalCode() {
    return fiscalCodeInput.getText();
}
