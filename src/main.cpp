#include "LldAdapter.h"
#include "GoldAdapter.h"
#include <iostream>

int main() {
    std::cout << "Starting Heimdall Adapters test...\n";

    // Create GoldAdapter instance
    heimdall::gold::GoldAdapter gold;
    gold.doSomething();

    // Create LldAdapter instance
    heimdall::lld::LldAdapter lld;
    lld.doSomething();

    std::cout << "Heimdall Adapters test finished.\n";
    return 0;
}
