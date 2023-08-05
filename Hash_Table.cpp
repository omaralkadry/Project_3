#include <vector>
#include <list>
#include "Hash_Table.h"
#include <utility>
using namespace std;

/*=== CONSTRUCTOR/DESTRUCTOR===*/
HashTable::HashTable() {
    size = 0;
    table.resize(capacity);
}

HashTable::~HashTable() {
    for (auto& bucket : table) {
        bucket.clear();
    }
}

const double HashTable::loadfact = 0.7;

int HashTable::hash(int key) const {
    return key % capacity; // might need to change, this does not resolve collision cases when/if zipcode values are duplicate
}

void HashTable::rehash() {
    // Double the capacity and create a new empty table with the new capacity
    int newCapacity = capacity * 2;
    vector<list<pair<int, Person>>> newTable(newCapacity);

    // Rehash all elements from the old table to the new table
    for (const auto& bucket : table) {
        for (const auto& data : bucket) {
            int key = hash(data.first);
            newTable[key].push_back(data);
        }
    }

    // Update the table with the newTable
    table = move(newTable);
    capacity = newCapacity;
}

void HashTable::insert(int zipcode, const string& name, const string& address) {
    int key = hash(zipcode);
    Person person(zipcode);

    // Check if the person already exists in the table
    for ( auto& data : table[key]) {
        if (data.first == zipcode) {
            //person.Add_offender(name, address); // if the person with the same data exists, update the data (ex. they moved)
            data.second.Add_offender(name,address);
            return; // Exit the function after updating the existing entry
        }
    }

    // Otherwise if the person doesn't exist in the data, add the new data
    person.Add_offender(name, address);
    table[key].push_back(make_pair(zipcode, person));
    size++;

    if (loadFactor() > loadfact) {
        rehash();
    }
}

double HashTable::loadFactor() const {
    return static_cast<double>(size) / static_cast<double>(capacity);
}

void HashTable::searchByZipcode(int zipcode) {
    int key = hash(zipcode);
    bool found = false;

    cout << "Found data at Zipcode " << zipcode << ":" << endl;
    for (auto& data : table[key]) {
        if (data.first == zipcode) {
            Person person = data.second;
            person.sort_data();
            vector<pair<string, string>> personData = person.Get_data();
            found = true;
            for (int i = 0; i < personData.size(); i++) {
                cout << "   Name: " << personData.at(i).first << endl;
                cout << "   Address: " << personData.at(i).second << endl;
                cout << endl;
            }
        }
    }

    if (!found) {
        cout << "There are no offenders at the provided zip code." << endl;
    }
}
