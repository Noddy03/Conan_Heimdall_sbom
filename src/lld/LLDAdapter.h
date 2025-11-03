#include "LLDAdapter.h"
#include <iostream>

namespace heimdall {
namespace lld {

LLDAdapter::LLDAdapter() {
    std::cout << "LLDAdapter initialized\n";
}

void LLDAdapter::doSomething() {
    std::cout << "LLDAdapter doing something\n";
}

} // namespace lld
} // namespace heimdall
