#pragma once
#include <vector>
#include <list>
#include "Person.h"
using namespace std;

class HashTable {
private:
    static const int capacity = 100;
    static const double loadfact;

    vector<list<pair<int, Person>>> table;
    int size;

    int hash(int key) const;
    void rehash();
    double loadFactor() const;

public:
    HashTable();
    ~HashTable();

    void insert(const Person& person);
    vector<Person> searchByZipcode(int zipcode) const;
};
