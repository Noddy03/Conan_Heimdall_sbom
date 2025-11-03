#include "GoldAdapter.h"
#include <iostream>

namespace heimdall {
namespace gold {

GoldAdapter::GoldAdapter() {
    std::cout << "GoldAdapter initialized\n"; 
}

void GoldAdapter::doSomething() {
    std::cout << "GoldAdapter doing something\n";
}

} // namespace gold
} // namespace heimdall
