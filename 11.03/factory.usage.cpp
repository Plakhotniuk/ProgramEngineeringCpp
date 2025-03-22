#include "factory.hpp"
#include <cassert>

int main() {
    factory::FactoryClient create_factory{};

    auto client0 = create_factory.make(0);
    auto client1 = create_factory.make(1);
    client0->test();
    client1->test();
    delete client0;
    delete client1;

    auto client100 = create_factory.make(100);

    assert(!client100);
    delete client100;
}