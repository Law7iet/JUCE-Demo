/*
  ==============================================================================

    ManagerPersone.h
    Created: 8 Nov 2021 5:56:38pm
    Author:  Han Chu

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PersonManager.h"
#include "Person.h"

//==============================================================================
/*
*/
class PersonManager: public juce::ChangeBroadcaster {
public:
    PersonManager();
    void addPerson(juce::String name,
                   juce::String surname,
                   Gender gender,
                   juce::Time dateOfBirth,
                   juce::String fiscalCode);
    int getNumberOfPeople();
    Person* getPersonFromIndex(int index);
    
private:
    juce::OwnedArray<Person> peopleList;
};
