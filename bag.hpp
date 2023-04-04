#ifndef BAG_HPP
#define BAG_HPP

#include <vector>
#include "pennant_tree.hpp"

class Bag {
public:
    Bag();
    void insert(int value);
    void union_binary(Bag &other_bag);
    int get_maxim_pos();
    void print();

private:
    std::vector<PennantTree> bag;
};

#endif