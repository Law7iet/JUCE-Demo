/*
  ==============================================================================

    BodyComponent.cpp
    Created: 16 Nov 2021 3:03:18pm
    Author:  Han Chu

  ==============================================================================
*/

#include "BodyComponent.h"

//==============================================================================
BodyComponent::BodyComponent() {
//    loadData();
//    
//    table.setColour (juce::ListBox::outlineColourId, juce::Colours::grey);      // [2]
//        table.setOutlineThickness (1);
//    
//    if (columnList != nullptr)
//    {
//        for (auto* columnXml : columnList->getChildIterator())
//        {
//            table.getHeader().addColumn (columnXml->getStringAttribute ("name"), // [2]
//                                         columnXml->getIntAttribute ("columnId"),
//                                         columnXml->getIntAttribute ("width"),
//                                         50,
//                                         400,
//                                         juce::TableHeaderComponent::defaultFlags);
//        }
//    }
    setBounds(0, 0, 1000, 1000);
}

BodyComponent::~BodyComponent() {}

void BodyComponent::paint(juce::Graphics& g) {
    g.fillAll(juce::Colours::lightgrey);
    g.setColour(juce::Colours::black);
}

void BodyComponent::resized() {}

void BodyComponent::loadData() {
//    juce::File path = juce::File("/Users/hanchu/Desktop/Tirocinio - AudioModeling/JUCE - Tutorials/Demo/Resources");
//    auto file = path.getChildFile("TableData.xml");
//    if(file.exists()) {
//        auto data = juce::XmlDocument::parse(file);
//
//        auto dataList   = data->getChildByName ("DATA");
//        auto columnList = data->getChildByName ("HEADERS");
//
//        int numRows = dataList->getNumChildElements();
//    }
}
