#ifndef LEVELER_HPP
#define LEVELER_HPP

#include<memory>  // shared_ptr

#include "Needs.h"

class Leveler {
private:
    std::shared_ptr<Needs> needs;
public:
    Leveler(std::shared_ptr<Needs> needs);
    void update();
    int getLevel();
};

#endif
