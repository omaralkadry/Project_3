#pragma once
#include <vector>
#include <list>
#include "Person.h"
using namespace std;

class HashTable {
private:
    int capacity = 100;
    static const double loadfact;

    vector<list<pair<int, Person>>> table;
    int size;

    int hash(int key) const;
    void rehash();
    double loadFactor() const;

public:
    HashTable();
    ~HashTable();
    void insert (int zipcode, const string& name, const string& address);
    void searchByZipcode(int zipcode) const;
};
