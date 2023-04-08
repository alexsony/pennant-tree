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

void Bag::union_binary(Bag &other) {
    auto maxim_r = [this, &other]() -> int{
        int r1 = this->get_maxim_pos();
        int r2  = other.get_maxim_pos();
        if (r1 > r2) return r1;
        else if (r1 < r2) return r2;
        else return r1 + 1;
    };

    int r = maxim_r();
    PennantTree carry(0);
    carry.get_root() = NULL;
    
    for (int k = 0; k < r; k++) full_adder(bag[k],other.get_bag()[k],carry);
}

void Bag::split(Bag &other) {
    auto maxim_r = [this, &other]() -> int{
        int r1 = this->get_maxim_pos();
        int r2  = other.get_maxim_pos();
        if (r1 > r2) return r1;
        else if (r1 < r2) return r2;
        else return r1 + 1;
    };

    PennantTree y(0);
    y = bag[0];
    bag[0].get_root() = NULL;
    int r = maxim_r();

    for (int i = other.get_bag().size() - 1; i < r - 1; i++) {
        other.get_bag().push_back(PennantTree());
    }

    for (int k = 1; k < r; k++) {
        if (bag[k].get_root() != NULL) {
            bag[k].pennant_split(other.get_bag()[k-1]);
            bag[k - 1] = bag[k];
            bag[k].get_root() = NULL; 
        } else {
            other.get_bag()[k-1].get_root() = NULL;
        }
    }
    if (y.get_root() != NULL) insert(1);
}

void Bag::full_adder(PennantTree &one, PennantTree &two, PennantTree &carry) {
    int x,y,c;
    (one.get_root() == NULL) ? (x = 0) : (x = 1);
    (two.get_root() == NULL) ? (y = 0) : (y = 1);
    (carry.get_root() == NULL) ? (c = 0) : (c = 1);

    if ((x == 0) && (y == 0) && (c == 0)) {   
        one.get_root() = NULL;
        carry.get_root() = NULL;
        return;
    } 
    if ((x == 1) && (y == 0) && (c == 0)) {
        carry.get_root() = NULL;
        return;
    }
    if ((x == 0) && (y == 1) && (c == 0)) {
        one.get_root() = std::move(two.get_root());
        carry.get_root() = NULL;
        return;
    }
    if ((x == 0) && (y == 0) && (c == 1)) {
        one.get_root() = std::move(carry.get_root());
        carry.get_root() = NULL;
        return;
    }
    if ((x == 1) && (y == 1) && (c == 0)) {
        one.pennant_union(two);
        carry.get_root() = std::move(one.get_root());
        one.get_root() = NULL;
        return;
    }
    if ((x == 1) && (y == 0) && (c == 1)) {
        one.pennant_union(carry);
        carry.get_root() = std::move(one.get_root());
        one.get_root() = NULL;
        return;
    }
    if ((x == 0) && (y == 1) && (c == 1)) {
        two.pennant_union(carry);
        carry.get_root() = std::move(two.get_root());
        one.get_root() = NULL;
        return;
    }
    if ((x == 1) && (y == 1) && (c == 1)) {
        two.pennant_union(carry);
        carry.get_root() = std::move(two.get_root());
        return;
    }
    
}


int Bag::get_maxim_pos() {
    int maxim;
    for (int k = 0; k < bag.size(); ++k) {
        if (bag[k].get_root() != NULL) maxim = k;
    }

    return maxim;
}

std::vector<PennantTree> & Bag::get_bag() {
    return bag;
}


void Bag::print() {
    for (int k = 0; k < bag.size(); ++k) {
        bag[k].print();
        std::cout << "K = " << k << std::endl;
        // std::cout << "size = " << pow(2,k) << std::endl;
    }
}