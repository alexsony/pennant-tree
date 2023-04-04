#include <iostream>
#include "pennant_tree.hpp"
#include "bag.hpp"

int main() {
    PennantTree pt(5),pt2(200);
    // pt.insert(10);
    // pt.insert(30);
    // pt.insert(50);
    // pt.insert(40);
    // pt.insert(5);
    // pt.insert(40);
    // pt.insert(20);



    // std::cout <<"tree1" <<std::endl;
    // pt.print();

    // pt2.insert(7);
    // pt2.insert(30);
    // pt2.insert(50);
    // pt2.insert(8);
    // pt2.insert(9);
    // pt2.insert(10);

    // std::cout <<"tree2" <<std::endl;
    // pt2.print();

    // pt.pennant_union(pt2);

    // std::cout <<"\n-----UNION-----\n" <<std::endl;
    // std::cout <<"tree1" <<std::endl;
    // pt.print();
    // std::cout <<"tree2" <<std::endl;
    // pt2.print();

    // pt.pennant_split(pt2);

    // std::cout <<"\n-----SPLIT-----\n" <<std::endl;
    // std::cout <<"tree1" <<std::endl;
    // pt.print();
    // std::cout <<"tree2" <<std::endl;
    // pt2.print();
   
    Bag b;
    for (int i = 0; i < 8; ++i) b.insert(i);
    std::cout << "Bag1\n";
    b.print();
    std::cout << std::endl;

    Bag b2;
    for (int i = 0; i < 2; ++i) b2.insert(i);
    std::cout << "Bag2\n";
    b2.print();
    std::cout << std::endl;

    std::cout <<"\n-----UNION-----\n" <<std::endl;
    b.union_binary(b2);

    std::cout << "Bag1\n";
    b.print();
    std::cout << std::endl;

    std::cout << "Bag2\n";
    b2.print();
    std::cout << std::endl;

    std::cout <<"\n-----SPLIT-----\n" <<std::endl;
    b.split(b2);

    std::cout << "Bag1\n";
    b.print();
    std::cout << std::endl;

    std::cout << "Bag2\n";
    b2.print();
    std::cout << std::endl;

}