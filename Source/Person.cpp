/*
  ==============================================================================

    Person.cpp
    Created: 8 Nov 2021 5:53:19pm
    Author:  Han Chu

  ==============================================================================
*/

#include <JuceHeader.h>
#include "Person.h"

//==============================================================================
Person::Person(juce::String name,
               juce::String surname,
               Gender gender,
               juce::Time dateOfBirth,
               juce::String fiscalCode) {
    this->name = name;
    this->surname = surname;
    this->gender = gender;
    this->dateOfBirth = dateOfBirth;
    this->fiscalCode = fiscalCode;
}

juce::String Person::getName() {
    return this->name;
}

juce::String Person::getSurname() {
    return this->surname;
}

Gender Person::getGender() {
    return this->gender;
}

juce::Time Person::getDateOfBirth() {
    return this->dateOfBirth;
}

juce::String Person::getFiscalCode() {
    return this->fiscalCode;
}

int Person::getAge() {
    return (juce::Time().getCurrentTime() - dateOfBirth).inDays() / 365;
}
