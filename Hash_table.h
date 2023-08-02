#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Person.cpp"

using namespace std;

class HashTable {
private:
    vector<Person> table; // vector of Person objects
    int numPeople; // num people in the hash table
    int capacity; // capacity of the hash table (total number of slots)
    double loadFactor; // threshold load factor to trigger resizing

    void rehash(); // resize the table and rehash the elements

public:
    HashTable();

    // Search for a person by their zipcode
    // Returns the Person object if found
    Person search(int zipcode);

    // Insert a new person into the hash table
    void insert(Person& person);

    void print();
};
