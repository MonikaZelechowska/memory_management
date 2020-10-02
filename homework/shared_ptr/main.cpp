#include <iostream>

#include "make_shared.hpp"
#include "shared_ptr.hpp"

void customDeleter(int* ptr) {
    std::cout << "Custom deleter\n";
    delete ptr;
}

int main() {
    cs::shared_ptr<int> ptr(new int{5});
    auto ptr2(ptr);
    cs::shared_ptr<int> ptr3(new int{5});
    ptr3 = ptr;
    auto ptr4(std::move(ptr));
    cs::shared_ptr<int> ptr5(new int{5});
    ptr5 = std::move(ptr3);

    cs::shared_ptr<int> ptrDel(new int{5}, customDeleter);

    auto ptr6 = cs::make_shared<int>(5);

    return 0;
}