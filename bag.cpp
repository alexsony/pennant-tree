#include "bag.hpp"
#include <iostream>
#include <cmath>

Bag::Bag() {
    bag.push_back(0);
    bag[0].get_root() = NULL;
}

void Bag::insert(int n) {
    PennantTree new_pennant(n);
    new_pennant.insert(n);

    int k = 0;

    while(bag[k].get_root() != NULL) {
        bag[k].pennant_union(new_pennant);
        new_pennant.get_root() = std::move(bag[k].get_root());
        bag[k++].get_root() = NULL;
        if (k >= bag.size()) break;
    }
    if (k >= bag.size()) bag.push_back(std::move(new_pennant));
    else bag.at(k) = new_pennant;
}

void Bag::union_binary(Bag &other_bag) {
    auto maxim_r = [this, &other_bag]() -> int{
        int r1 = this->get_maxim_pos();
        int r2  = other_bag.get_maxim_pos();
        if (r1 > r2) return r1;
        else if (r1 < r2) return r2;
        else return r1 + 1;
    };

    int r = maxim_r();
}

int Bag::get_maxim_pos() {
    int maxim;
    for (int k = 0; k < bag.size(); ++k) {
        if (bag[k].get_root() != NULL) maxim = k;
    }

    return maxim;
}

void Bag::print() {
    for (int k = 0; k < bag.size(); ++k) {
        bag[k].print();
        std::cout << "K = " << k << std::endl;
        // std::cout << "size = " << pow(2,k) << std::endl;
    }
}