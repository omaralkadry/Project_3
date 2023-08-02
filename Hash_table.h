#include <iostream>
#include <string>
#include <vector>
#include "Person.cpp"

using namespace std;

class HashTable {
private:
    vector<Person> table; // vector of Person objects
    int numPeople; // num people in the hash table

    HashTable();
    int Hash(int zipcode); // hash function to map zipcodes to table indices

public:
    // Search for a person by their zipcode
    // Returns the Person object if found
    Person search(int zipcode);

    // Insert a new person into the hash table
    void insert(Person& person);

    void print();
};
