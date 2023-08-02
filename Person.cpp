//
// Created by omar on 7/29/2023.
//
#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<fstream>
#include"Person.h"
using namespace std;

Person::Person()
{
    this->zipcode = -1;
}

Person::Person(int zipcode)
{
    this->zipcode = zipcode;
}

vector<string> Person::Get_names() 
{
    return this->names;
}

vector<string> Person::Get_addresses() 
{
    return this->addresses;
}

int Person::Get_zipcode() 
{
    return this->zipcode;
}

void Person::Add_offender(const string &name, const string &address)
{
    this->names.push_back(name);
    this->addresses.push_back(address);
}

void Person::Deserialize(istringstream& stream){
    string token;

	getline(stream, this->name, ',');

	getline(stream, this->address, ',');

    getline(stream, this->city, ',');

    getline(stream, this->state, ',');

	getline(stream, token, ',');
	this->zipcode = stoi(token);

    getline(stream, this->county, ',');
}

void Person::PrintInfo(){
    cout << "Name: " << this->name << endl;
	cout << "Address: " << this->address << endl;
	cout << "City: " << this->city << endl;
	cout << "State:" << this->state << endl;
	cout << "Zipcode: " << this->zipcode << endl;
}