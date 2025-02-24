#include "ScopeGuard.hpp"
#include <iostream>


namespace {

void action_a() {
    std::cout << "Action A" << std::endl;
}

void rollback_a() noexcept {
    std::cout << "Action B rollback" << std::endl;
}

void action_b() {
    std::cout << "Action B" << std::endl;
    throw std::runtime_error("Action B failed");
}

void example_func() {
    action_a();

    scope_guard::ScopeGuard guard(rollback_a);

    action_b();

    guard.dismiss_rollback();
}
}

int main ()
{
    try {
        example_func();
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
}