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
    PennantTree(PennantTree &&new_tree);

    void insert(int key);
    void pennant_union(PennantTree &tree);
    void pennant_split(PennantTree &tree);
    std::shared_ptr<node> & get_root();
    std::vector<std::shared_ptr<node>> get_tree();
    void operator = (PennantTree &copy_tree);
    void print();
private:
    void print(std::string prefix, const std::shared_ptr<node> leaf, bool is_left);

    std::shared_ptr<node> root = NULL;
    std::vector<std::shared_ptr<node>> tree;
};

#endif