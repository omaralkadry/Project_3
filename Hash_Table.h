#pragma once
#include <vector>
#include <list>
#include "Person.h"
using namespace std;

class HashTable {
private:
    HashTable();
    ~HashTable();
    static const int capacity = 100;
    static const double loadfact;

    vector<list<pair<int, Person>>> table;
    int size;

    int hash(int key) const;
    void rehash();
    double loadFactor() const;

public:
    void insert (Person& person);
    vector<Person> searchByZipcode(int zipcode) const;
};

/*=== CONSTRUCTOR/DESTRUCTOR===*/
HashTable::HashTable(){
    size = 0;
    table.resize(capacity);
}

HashTable::~HashTable(){
    for(auto& bucket : table){
        bucket.clear();
    }
}

int HashTable::hash(int key) const {
    return key % capacity; // this does not resolve collision cases when/if zipcode values are duplicate
}

void HashTable::rehash(){
    // Double the capacity and create a new empty table with the new capacity
    vector<list<pair<int, Person>>> newTable;
    newTable = table;
    table.resize(newTable.size() * 2);

    // Rehash all elements from the old table to the new table
    for (const auto& bucket : table) {
        for (const auto& data : bucket) {
            int key = hash(data.first);
            newTable[key].push_back(data);
        }
    }
}

void HashTable::insert(Person& person){
    int hashVal = hash(person.Get_zipcode());
    table[hashVal].push_back(make_pair(person.Get_zipcode(), person));
    size++;

    if(loadFactor() > loadfact){
        rehash();
    }
}




