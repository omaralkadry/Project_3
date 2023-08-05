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

int HashTable::hash(int key) {
    return key % capacity; // might need to change, this does not resolve collision cases when/if zipcode values are duplicate
}

void HashTable::rehash() {
    // Double the capacity and create a new empty table with the new capacity
    int newCapacity = capacity * 2;
    vector<list<pair<int, Person>>> newTable(newCapacity);

    // Rehash all elements from the old table to the new table
    for (auto& bucket : table) {
        for (auto& data : bucket) {
            int key = hash(data.first);
            newTable[key].push_back(data);
        }
    }

    // Update the table with the newTable
    table = move(newTable);
    capacity = newCapacity;
}

void HashTable::insert(int& zipcode, string& name, string& address) {
    int key = hash(zipcode);
    Person person(zipcode);

    // Check if the person already exists in the table
    // for (auto& data : table[key]) {
    //     person = data.second;
    //     if (data.first == zipcode) {
    //         data.second.Add_offender(name,address);
    //         return; // Exit the function after updating the existing entry
    //     }
    //     else{

    //     }
    // }

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
    vector<pair<string, string>> namesAndAddresses;

    cout << "Found data at Zipcode " << zipcode << ":" << endl;
    for (auto& data : table[key]) {
        if (data.first == zipcode) {
            Person person = data.second;
            vector<pair<string, string>> personData = person.Get_data();
            found = true;
            for (int i = 0; i < personData.size(); i++) {
                namesAndAddresses.push_back(personData.at(i));
            }
        }
    }

    if (!found) {
        cout << "There are no offenders at the provided zip code." << endl;
        return;
    }

    //sorts names & addresses
    sort(namesAndAddresses.begin(), namesAndAddresses.end());

    for (const auto& nameAndAddress : namesAndAddresses) {
        cout << "   Name: " << nameAndAddress.first << endl;
        cout << "   Address: " << nameAndAddress.second << endl;
        cout << endl;
    }
}

void HashTable::remove(const string& name, int zipcode) {
    int key = hash(zipcode);
    bool found = false;

    for (auto it = table[key].begin(); it != table[key].end(); ++it) {
        if (it->first == zipcode) {
            Person& person = it->second; // reference to the Person object
            vector<pair<string, string>> personData = person.Get_data();
            for (int i = 0; i < personData.size(); i++) {
                if (personData[i].first == name) {
                    person.remove_person(i);
                    found = true;
                    size--;
                    break;
                }
            }
        }
    }

    if (found) {
        cout << "Successfully deleted the person with name: " << name << " and zipcode: " << zipcode << endl;
    } else {
        cout << "No matching person found with name: " << name << " and zipcode: " << zipcode << endl;
    }
}
