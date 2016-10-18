#include "Zone.h"

Zone::Zone(StockPair recipe)
    : recipe(recipe)
    , inputCap(recipe.input)
    , outputCap(recipe.output)
    , inputMet()
    , outputMet()
    , outputProduced()
{
    //
}

Zone::~Zone() {
    //
}

Stock Zone::getUnprovided() {
    return inputCap - inputMet;
}

Stock Zone::getProvided() {
    return inputMet;
}

Stock Zone::getInputCap() {
    return inputCap;
}

Stock Zone::getUntaken() {
    return outputProduced - outputMet;
}

Stock Zone::getTaken() {
    return outputMet;
}

Stock Zone::getOutputCap() {
    return outputCap;
}

void Zone::updateCap(Stock& relief) {
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

void Zone::updateProduction() {
    if(recipe.input == Stock()) {
        outputProduced = recipe.output;
    }
    else{
        int recipesSatisfied = inputMet.timesItContains(recipe.input);
        outputProduced = recipe.output * recipesSatisfied;
    }
}

void Zone::provide(Stock provided) {
    if(!provided.subsetOf(getUnprovided())) {
        throw ResourceException("Too many resources to receive");
    }

    inputMet += provided;
}

void Zone::take(Stock taken) {
    if(!taken.subsetOf(getUntaken())) {
        throw ResourceException("Not enough resources to take");
    }

    outputMet += taken;
}

void Zone::unprovide(Stock cancelSupply) {
    inputMet -= cancelSupply;
}

void Zone::untake(Stock cancelConsumption) {
    outputMet -= cancelConsumption;
}
