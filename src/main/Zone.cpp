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

Stock Zone::getOutputCap() {
    return outputCap;
}

void Zone::update(Stock& relief) {
    if(relief.supersetOf(outputCap) && outputMet.supersetOf(outputCap)) {
        relief -= outputCap;
        inputCap *= 2;
        outputCap *= 2;
    }
}

void Zone::supplyInput(Stock supply) {
    inputMet = inputMet + supply;
}

void Zone::takeOutput(Stock consumption) {
    outputMet = outputMet + consumption;
}
