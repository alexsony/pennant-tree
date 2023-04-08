#include <iostream>
#include "pennant_tree.hpp"

PennantTree::PennantTree(int root_value) {
    root = std::make_shared<node>();
    root->key_value = root_value;
    root->left = NULL;
    root->right = NULL;

}

PennantTree::PennantTree() {
    root = std::make_shared<node>();
    root->key_value = 0;
    root->left = NULL;
    root->right = NULL;
    insert(0);

}

PennantTree::PennantTree(PennantTree&& new_tree) {
    if (root == NULL) root = std::make_shared<node>();
    root = new_tree.get_root();
    tree = new_tree.get_tree();
}

void PennantTree::insert(int key) {
    if (NULL != root->left) {

        int N = tree.size();
        std::shared_ptr<node> new_node = std::make_shared<node>();
        new_node->key_value = key;
        tree.push_back(new_node);
        //tree[i] has left child tree[2 * i + 1] and tree[2 * i + 2]
        if (N % 2)
            tree[(N - 1) / 2]->left = new_node;
        else
            tree[(N - 1) / 2]->right = new_node;
    }
    else {
        root->left = std::make_shared<node>();
        root->left->key_value = key;
        tree.push_back(root->left);
    }
}

void PennantTree::pennant_union(PennantTree &tree) {
    tree.get_root()->right = std::make_shared<node>();
    tree.get_root()->right = root->left;
    root->left = tree.get_root();
}

void PennantTree::pennant_split(PennantTree &tree) {
    std::shared_ptr<node> new_node = std::make_shared<node>();

    new_node = root->left;
    root->left = new_node->right;
    new_node->right = NULL;

    tree.get_root() = new_node;

}

std::shared_ptr<node> & PennantTree::get_root() {
    return root;
}

std::vector<std::shared_ptr<node>> PennantTree::get_tree() {
    return tree;
}


void PennantTree::operator = (PennantTree &copy_tree) {
    root = std::move(copy_tree.get_root());
    tree = copy_tree.get_tree();
}


void PennantTree::print() {
    print("",root,false);
}

void PennantTree::print(std::string prefix, const std::shared_ptr<node> leaf, bool is_left) {
    if(NULL != leaf) {
        std::cout << prefix;
        std::cout << (is_left ? "├──" : "└──" );

        std::cout << leaf->key_value << std::endl;

        print(prefix + (is_left ? "│   " : "    "), leaf->left, true);
        print(prefix + (is_left ? "│   " : "    "), leaf->right, false);

    }
}