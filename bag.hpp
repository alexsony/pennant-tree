#ifndef BAG_HPP
#define BAG_HPP

#include <vector>
#include "pennant_tree.hpp"

class Bag {
public:
    Bag();
    void insert(int value);
    void union_binary(Bag &other);
    void split(Bag &other);
    int get_maxim_pos();
    std::vector<PennantTree> &get_bag();
    void print();

private:
    void full_adder(PennantTree &one, PennantTree &two, PennantTree &carry);
    std::vector<PennantTree> bag;
};

#endif