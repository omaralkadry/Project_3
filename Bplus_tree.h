#ifndef BPLUSTREE_H
#define BPLUSTREE_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Person.h"

class Node {
public:
    bool is_leaf;
    std::vector<int> zipcodes;
    std::vector<Person> data;
    std::vector<Node*> children;
    explicit Node(bool leaf_bool);
};

class BPlusTree {
public:
    BPlusTree();
    Node* Get_root(); // unused
    void insert(int zipcode, const std::string& name, const std::string& address);
    void search(int zipcode);
    void change_address(int zipcode, string name, string address);

private:
    Node* root;
    const int order = 100; // adjust order value according to the size of total data
};

#endif // BPLUSTREE_H
