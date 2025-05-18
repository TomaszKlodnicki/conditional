#include <iostream>
#include <string>
#include "conditional.hpp"

int main(){

    Conditional<std::string, true> store;
    Conditional<std::string, false> dont_store;

    store = "example";
    dont_store = "example";

    std::cout << sizeof(store) << "\n" <<  store.value() << "\n";
    std::cout << sizeof(dont_store) << "\n" <<  dont_store.value() << "\n";

    return 0;
}