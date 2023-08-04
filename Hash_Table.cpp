#include <vector>
#include <list>
#include "Hash_Table.h"
using namespace std;

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

const double HashTable::loadfact = 0.7;

int HashTable::hash(int key) const {
    return key % capacity; // might need to change, this does not resolve collision cases when/if zipcode values are duplicate
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

void HashTable::insert(int zipcode, const string& name, const string& address){
    int key = hash(zipcode);
    Person person(zipcode);

    // Check if the person already exists in the table
    for(const auto& data : table[key]){
        if(data.first == zipcode){
            person.Add_offender(name, address); // if the person with the same data exists, update the data (ex. they moved)
            break;
        }
    }

    // Otherwise if the person doesn't exist in the data, add the new data
    person.Add_offender(name, address);
    table[key].push_back(make_pair(zipcode, person));
    size++;

    if(loadFactor() > loadfact){
        rehash();
    }
}

double HashTable::loadFactor() const{
    return static_cast<double>(size) / static_cast<double>(capacity);
}

vector<Person> HashTable::searchByZipcode(int zipcode) const{
    vector<Person> result;
    int key = hash(zipcode);

    for(const auto& data : table[key]){
        if(data.first == zipcode){
            result.push_back(data.second);
        }
    }
    return result;
}
