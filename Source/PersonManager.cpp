/*
  ==============================================================================

    ManagerPersone.cpp
    Created: 8 Nov 2021 5:56:38pm
    Author:  Han Chu

  ==============================================================================
*/

#include <JuceHeader.h>
#include "PersonManager.h"

//==============================================================================
PersonManager::PersonManager() {
    peopleList = juce::OwnedArray<Person>();
    addPerson("nome1",
              "cognome1",
              Gender::male,
              juce::Time(2000, 1, 1, 1, 1),
              "1");
    addPerson("nome2",
              "cognome2",
              Gender::female,
              juce::Time(2001, 2, 2, 3, 5),
              "2");
    addPerson("nome3",
              "cognome3",
              Gender::other,
              juce::Time(2002, 3, 4, 5, 6),
              "3");
}

void PersonManager::addPerson(juce::String name,
                              juce::String surname,
                              Gender gender,
                              juce::Time dateOfBirth,
                              juce::String fiscalCode) {
    Person* p = new Person(name, surname, gender, dateOfBirth, fiscalCode);
    peopleList.add(p);
    sendChangeMessage();
}

int PersonManager::getNumberOfPeople() {
    return peopleList.size();
}

Person* PersonManager::getPersonFromIndex(int index) {
    if (index + 1 > peopleList.size() || index < 0) {
        return NULL;
    } else {
        Person* pickedPerson = peopleList.getUnchecked(index);
        return pickedPerson;
    }
}

