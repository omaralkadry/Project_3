//
// Created by omar on 7/29/2023.
//
#include "Person.h"

Person::Person()
{
    // Initialize zipcode to a default value of -1, indicating no zipcode provided.
    this->zipcode = -1;
}

Person::Person(int zipcode)
{
    // sets the provided zipcode when creating a new Person object.
    this->zipcode = zipcode;
}

vector<string> Person::Get_names()
{
    // Return the vector of names associated with this Person.
    return this->names;
}

vector<string> Person::Get_addresses()
{
    // Return the vector of addresses associated with this Person.
    return this->addresses;
}

int Person::Get_zipcode()
{
    // Return the zipcode of this Person.
    return this->zipcode;
}

void Person::Add_offender(string& name, string& address)
{
    // appending their name and address to the respective vectors.
    this->names.push_back(name);
    this->addresses.push_back(address);
}

void Person::Deserialize(istringstream& stream)
{
    string token;

    // Read name, address, city, state, zipcode, and county from the stream
    getline(stream, this->name, ',');
    getline(stream, this->address, ',');
    getline(stream, this->city, ',');
    getline(stream, this->state, ',');
    getline(stream, token, ',');
    this->zipcode = stoi(token);
    getline(stream, this->county, ',');
}

void Person::PrintInfo()
{
    // Print the information of this Person
    cout << "Name: " << this->name << endl;
    cout << "Address: " << this->address << endl;
    cout << "City: " << this->city << endl;
    cout << "State:" << this->state << endl;
    cout << "Zipcode: " << this->zipcode << endl;
}
