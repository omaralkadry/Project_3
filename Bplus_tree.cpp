//
// Created by omar on 7/29/2023.
//
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Person.h"
using namespace std;

class Node {
public:
    bool is_leaf;
    vector<int> zipcodes;
    vector<Person> data;
    vector<Node*> children;
    explicit Node(bool leaf_bool);

};

Node::Node(bool leaf_bool)
{
    this->is_leaf = leaf_bool;
}

// B+ tree class
class BPlusTree {
public:
    BPlusTree();
    Node* Get_root(); // unused
    void insert(int zipcode, const string& name, const string& address);
    void search(int zipcode);

private:
    Node* root;
    // adjust order value according to size of total data
    const int order = 100;
};

BPlusTree::BPlusTree()
{
    root = nullptr;
}

Node* BPlusTree::Get_root()
{
    return this->root;
}

// Add new vertex into Tree
void BPlusTree::insert(int zipcode, const string& name, const string& address) {

    //add new vertex as root if Tree is empty
    if (root == nullptr) {
        root = new Node(true);
        root->zipcodes.push_back(zipcode);
        Person person(zipcode);
        person.Add_offender(name, address);
        root->data.push_back(person);
        return;
    }

    // Tree traversal to find new vertex location
    Node* vertex = root;
    while (!vertex->is_leaf) {
        int child = vertex->children.size();

        for (int i = 0; i < vertex->zipcodes.size(); i++) {
            if (vertex->zipcodes.at(i) > zipcode) {
                child = i;
                break;
            }
        }
        vertex = vertex->children.at(child);
    }

    // Adds new vertex if zipcode not available. Adds person to vertex
    if (vertex->zipcodes.empty()) {
        vertex->zipcodes.push_back(zipcode);
        Person person(zipcode);
        person.Add_offender(name, address);
        vertex->data.push_back(person);
    }
    else {
        int same_key = -1;
        for (int i = 0; i < vertex->zipcodes.size(); i++) {
            if (vertex->zipcodes.at(i) == zipcode) {
                same_key = i;
                break;
            }
        }
        // zipcode not found
        if (same_key == -1) {
            int i = 0;
            for (; i < vertex->zipcodes.size(); i++) {
                if (vertex->zipcodes.at(i) > zipcode) {
                    break;
                }
            }
            vertex->zipcodes.insert(vertex->zipcodes.begin() + i, zipcode);
            Person person(zipcode);
            person.Add_offender(name, address);
            vertex->data.insert(vertex->data.begin() + i, person);
        }
        // zipcode found
        else {
            vertex->data.at(same_key).Add_offender(name, address);
        }
    }
        // If overflow occurs, splits leaf node into two nodes
        if (vertex->zipcodes.size() > order) {

            // Move data to new node and add new node
            Node* right = new Node(true);
            int median = vertex->zipcodes.size() / 2;
            for (int i = median; i < vertex->zipcodes.size(); i++) {
                right->zipcodes.push_back(vertex->zipcodes.at(i));
            }
            for (int i = median; i < vertex->zipcodes.size(); i++) {
                right->data.push_back(vertex->data.at(i));
            }
            for (int i = median; i < vertex->zipcodes.size();) {
                right->zipcodes.pop_back();
            }
            for (int i = median; i < vertex->zipcodes.size();) {
                right->data.pop_back();
            }
            right->children.push_back(vertex->children.at(vertex->children.size()-1));
            vertex->children.at(vertex->children.size()-1) = right;

            if (vertex == root) {
                root = new Node(false);
                root->zipcodes.push_back(right->zipcodes.at(0));
                root->children.push_back(vertex);
                root->children.push_back(right);
            }

            //splits for leaf node, promotes lower zipcode to the parent
            else {
                Node* parent = vertex->children.at(vertex->children.size()-1);
                int x = 0;
                while (parent->zipcodes.size() > x && parent->zipcodes.at(x) < right->zipcodes.at(0)) {
                    x++;
                }
                parent->zipcodes.insert(parent->zipcodes.begin() + x, right->zipcodes.at(0));
                int y = x + 1;
                while (parent->children.size() > y && parent->children.at(y) < right) {
                    y++;
                }
                parent->children.insert(parent->children.begin() + y, right);
                delete right;
            }
        }
    }

// Traverse the tree for the vertex matching zipcode. If found, print all the people within the vertex
void BPlusTree::search(int zipcode) {

    if (root == nullptr) {
        cout << "No data exists in the program" << endl;
        return;
    }

    Node* vertex = root;
    while (!vertex->is_leaf) {
        int child = 0;
        while (child < vertex->zipcodes.size() && vertex->zipcodes.at(child) <= zipcode) {
            child++;
        }
        vertex = vertex->children.at(child);
    }

    int index = -1;
    for (int i = 0; i < vertex->zipcodes.size(); i++) {
        if (vertex->zipcodes.at(i) == zipcode) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "There are no offenders at the provided zip code." << endl;

    }
    else {
        cout << "Found data at Zipcode " << vertex->zipcodes.at(index) << endl;

        for (int i = 0; i < vertex->data.at(index).Get_names().size(); i++) {
            cout << "   Name: " << vertex->data.at(index).Get_names().at(i) << endl;
            cout << "   Address: " << vertex->data.at(index).Get_addresses().at(i) << endl;
            cout << endl;
        }
    }
}

