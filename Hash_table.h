#include<iostream>
#include<string>
#include<vector>
#include "Person.cpp"
using namespace std;

class HashTable{
private:
    vector<Person> table;
    int numPeople;
    HashTable();
    int Hash(int zipcode);
public:
    Person search(int zipcode);
    void insert(Person& person);
    void print();
};

