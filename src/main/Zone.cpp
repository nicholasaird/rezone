#include "Zone.h"

Zone::Zone(StockPair recipe)
    : recipe(recipe)
    , input()
    , output()
    , inputCap(recipe.input)
    , outputCap(recipe.output)
{
    //
}

Zone::~Zone() {
    //
}

Stock Zone::getInputAvailable() {
    return recipe.input;
}

Stock Zone::getInputMet() {
    return Stock();
}

Stock Zone::getInputCap() {
    return inputCap;
}

Stock Zone::getOutputCap() {
    return outputCap;
}

void Zone::update(Stock& relief) {
    if(relief.supersetOf(outputCap) && output.supersetOf(outputCap)) {
        relief -= outputCap;
        inputCap *= 2;
        outputCap *= 2;
    }
}

void Zone::supplyInput(Stock supply) {
    input = input + supply;
}

void Zone::takeOutput(Stock consumption) {
    output = output + consumption;
}
