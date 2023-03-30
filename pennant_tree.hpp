#ifndef PENNANT_TREE_HPP
#define PENNANT_TREE_HPP

#include <string>
#include <memory>
#include <vector>

struct node {
    int key_value;
    std::shared_ptr<node> left;
    std::shared_ptr<node> right;
};

class PennantTree {
public:
    PennantTree(int root_value);

    void insert(int key);
    void pennant_union(PennantTree &tree);
    void pennant_split(PennantTree &tree);
    std::shared_ptr<node> get_root();
    void print();
private:
    void print(std::string prefix, const std::shared_ptr<node> leaf, bool is_left);

    std::shared_ptr<node> root;
    std::vector<std::shared_ptr<node>> tree;
};

#endif