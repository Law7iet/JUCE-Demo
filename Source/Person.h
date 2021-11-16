/*
  ==============================================================================

    Person.h
    Created: 8 Nov 2021 5:53:19pm
    Author:  Han Chu

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "Gender.h"

//==============================================================================
/*
*/

class Person {
public:
    Person(juce::String name,
           juce::String surname,
           Gender gender,
           juce::Time dateOfBirth,
           juce::String fiscalCode);

    juce::String getName();
    juce::String getSurname();
    Gender getGender();
    juce::Time getDateOfBirth();
    juce::String getFiscalCode();
    int getAge();
    
protected:
    juce::String name;
    juce::String surname;
    Gender gender;
    juce::Time dateOfBirth;
    juce::String fiscalCode;
};
