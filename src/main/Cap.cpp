#include "Cap.h"

Cap::Cap(StockPair recipe)
    : recipe(recipe)
{
    //
}

void Cap::update(Stock relief) {
    //
}

Stock Cap::getInput() {
    return recipe.input;
}

Stock Cap::getOutput() {
    return recipe.output;
}
