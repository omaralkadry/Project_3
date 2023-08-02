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

vector<pair<string, string>> Person::Get_data()
{
    return this->data;
}

int Person::Get_zipcode() 
{
    return this->zipcode;
}

void Person::Add_offender(const string &name, const string &address)
{
    this->data.emplace_back(name,address);
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

void Person::remove_person(int index)
{
    auto iter = data.begin() + index;
    data.erase(iter);
}
