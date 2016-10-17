#include "Zone.h"

Zone::Zone(StockPair recipe)
    : recipe(recipe)
    , inputCap(recipe.input)
    , outputCap(recipe.output)
    , inputMet()
    , outputMet()
{
    //
}

Zone::~Zone() {
    //
}

Stock Zone::getInputAvailable() {
    return inputCap - inputMet;
}

Stock Zone::getInputMet() {
    return inputMet;
}

Stock Zone::getInputCap() {
    return inputCap;
}

Stock Zone::getOutputAvailable() {
    return outputCap - outputMet;
}

Stock Zone::getOutputMet() {
    return outputMet;
}

Stock Zone::getOutputCap() {
    return outputCap;
}

void Zone::update(Stock& relief) {
    if(relief.supersetOf(outputCap) && outputMet.supersetOf(outputCap)) {
        relief -= outputCap;
        inputCap *= 2;
        outputCap *= 2;
    }
    else if(!outputMet.supersetOf(outputCap / 2)) {
        relief += outputCap / 2;
        inputCap /= 2;
        outputCap /= 2;
    }
}

void Zone::supplyInput(Stock supply) {
    if(!supply.subsetOf(getInputAvailable())) {
        throw ResourceException("Too many resources to receive");
    }

    inputMet += supply;
}

void Zone::takeOutput(Stock consumption) {
    if(!consumption.subsetOf(getOutputAvailable())) {
        throw ResourceException("Not enough resources to take");
    }

    outputMet += consumption;
}

void Zone::cancelInput(Stock cancelSupply) {
    inputMet -= cancelSupply;
}

void Zone::cancelOutput(Stock cancelConsumption) {
    outputMet -= cancelConsumption;
}
