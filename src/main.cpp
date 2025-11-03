#include "lld/LLDAdapter.h"
#include "gold/GoldAdapter.h"
#include <iostream>

int main() {
    std::cout << "Starting Heimdall Adapters test...\n";

    heimdall::gold::GoldAdapter gold;
    gold.doSomething();

    heimdall::lld::LLDAdapter lld;
    lld.doSomething();

    std::cout << "Heimdall Adapters test finished.\n";
    return 0;
}
