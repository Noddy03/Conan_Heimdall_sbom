#include "LldAdapter.h"
#include "GoldAdapter.h"

int main() {
    heimdall::gold::GoldAdapter gold;
    gold.doSomething();

    heimdall::lld::LldAdapter lld;
    lld.doSomething();

    return 0;
}
