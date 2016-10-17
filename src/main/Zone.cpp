#include "Zone.h"

Zone::Zone(StockPair recipe)
    : recipe(recipe)
{
    //
}

Zone::~Zone() {
    //
}

Stock Zone::getInputMet() {
    return Stock();
}

Stock Zone::getInputCap() {
    return recipe.input;
}

Stock Zone::getOutputCap() {
    return recipe.output;
}
